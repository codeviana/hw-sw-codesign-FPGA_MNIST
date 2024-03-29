/*
 * CNN_recognition.h
 *
 *  Created on: 2018��7��14��
 *      Author: Song Jiahao
 */

#ifndef CNN_RECOGNITION_H_
#define CNN_RECOGNITION_H_

#define IMAGE_DIM 28
#define CONV_CORE_DIM 3 //3
#define CONV_RANGE 1
#define CONV_MID 1
#define CONV1_OUT_DIM 8
#define CONV2_OUT_DIM 4
#define FC1_OUT_DIM 32
#define FC2_OUT_DIM 10

#include <math.h>

#define RELU(x) (((x)>0)?(x):(0))

float Input_Image[IMAGE_DIM][IMAGE_DIM];

float Conv1_W[CONV_CORE_DIM][CONV_CORE_DIM][1][CONV1_OUT_DIM];
float Conv1_B[CONV1_OUT_DIM] = {
	0.037722453475, 0.002797347261, 0.305463284254, 0.201481848955, 0.119835518301, 0.125280037522, 0.108334325254, 0.034626591951,
};
float Conv1_Image[IMAGE_DIM][IMAGE_DIM][CONV1_OUT_DIM];
float Pool1_Image[IMAGE_DIM / 2][IMAGE_DIM / 2][CONV1_OUT_DIM];

float Conv2_W[CONV_CORE_DIM][CONV_CORE_DIM][CONV1_OUT_DIM][CONV2_OUT_DIM];
float Conv2_B[CONV2_OUT_DIM] = {
	0.099538996816, 0.045513521880, 0.186764270067, 0.073189675808
};
float Conv2_Image[IMAGE_DIM / 2][IMAGE_DIM / 2][CONV2_OUT_DIM];
float Pool2_Image[IMAGE_DIM / 4][IMAGE_DIM / 4][CONV2_OUT_DIM];

float Flat_Image[(IMAGE_DIM / 4)*(IMAGE_DIM / 4)*CONV2_OUT_DIM];

float Fc1_W[(IMAGE_DIM / 4)*(IMAGE_DIM / 4)*CONV2_OUT_DIM][FC1_OUT_DIM];
float Fc1_B[FC1_OUT_DIM] = {
	0.085268668830, 0.104823432863, 0.094293154776, 0.116845712066, 0.092972017825, 0.093681968749, 0.069857798517, 0.101836457849, 0.075211443007, 0.109067849815, 0.112637236714, 0.094236835837, 0.128623679280, 0.058109421283, 0.103581912816, 0.096784077585, 0.093983590603, 0.126963421702, 0.100000001490, 0.187534689903, 0.076948776841, 0.161091834307, 0.110916681588, 0.131336808205, 0.117547012866, 0.072507366538, 0.048740513623, 0.067004226148, 0.079193867743, 0.147164106369, 0.094332851470, 0.131599575281
};
float FC1_Image[FC1_OUT_DIM];

float Fc2_W[FC1_OUT_DIM][FC2_OUT_DIM];
float Fc2_B[FC2_OUT_DIM] = {
	-0.036088421941, 0.312147021294, -0.109268501401, -0.145344331861, 0.349955409765, 0.041141033173, 0.159300595522, -0.013305801898, 0.197449177504, 0.236681833863
};
float FC2_Image[FC2_OUT_DIM];
float Softmax[FC2_OUT_DIM];
int ans=0, subop;

#include "para_conv1.h"
#include "para_conv2.h"
#include "para_fc1.h"
#include "para_fc2.h"
#include "data.h"

// Load all parameters and data
void Load_All();
// Convolution Layer 1 with relu
void Conv1();
// Max-pooling Layer 1
void MaxPool1();
// Convolution Layer 2 with relu
void Conv2();
// Max-pooling Layer 2
void MaxPool2();
// Flatten the image
void Flatten();
// FC Layer 1 with relu
void Fc1();
// FC Layer 2
void Fc2();
// Softmax and get the result
void Get_Answer();

int CNN_MNIST_recognition() {
	//LCD_Clear();
	Load_All();
	//*(pSEG) = 0xff00ffff + (9 << 20) + (6 << 16);  // 96%
	Conv1();
	MaxPool1();
	//*(pSEG) = 0xff00ffff + (9 << 20) + (7 << 16);  // 97%
	Conv2();
	MaxPool2();
	Flatten();
	//*(pSEG) = 0xff00ffff + (9 << 20) + (8 << 16);  // 98%
	Fc1();
	//*(pSEG) = 0xff00ffff + (9 << 20) + (9 << 16);  // 99%
	Fc2();
	Get_Answer();
	return ans;
}

void Load_All() {
	Format_Conv1_W();
	Format_Conv2_W();
	Format_Fc1_W();
	Format_Fc2_W();
	//Format_InputImage();
}

void Conv1() {
	int i, j, k;
	int i2, j2;
	float tmp_ans;
	for (i = 0; i < IMAGE_DIM; i++)
		for (j = 0; j < IMAGE_DIM; j++)
			for (k = 0; k < CONV1_OUT_DIM; k++) {
				tmp_ans = 0.0;
				for (i2 = -CONV_RANGE; i2 <= CONV_RANGE; i2++)
					for (j2 = -CONV_RANGE; j2 <= CONV_RANGE; j2++)
						if (i + i2 >= 0 && j + j2 >= 0 && i + i2 < IMAGE_DIM && j + j2 < IMAGE_DIM)
							tmp_ans += Conv1_W[CONV_MID + i2][CONV_MID + j2][0][k] * Input_Image[i + i2][j + j2];
				tmp_ans += Conv1_B[k];
				tmp_ans = RELU(tmp_ans);
				Conv1_Image[i][j][k] = tmp_ans;
			}
}

float max(float x1, float x2, float x3, float x4) {
	float ans = x1;
	ans = (x2 > ans) ? x2 : ans;
	ans = (x3 > ans) ? x3 : ans;
	ans = (x4 > ans) ? x4 : ans;
	return ans;
}

void MaxPool1() {
	int i, j, k;
	for (i = 0; i < IMAGE_DIM / 2; i++)
		for (j = 0; j < IMAGE_DIM / 2; j++)
			for (k = 0; k < CONV1_OUT_DIM; k++)
				Pool1_Image[i][j][k] = max(Conv1_Image[i * 2][j * 2][k],
					Conv1_Image[i * 2 + 1][j * 2][k],
					Conv1_Image[i * 2][j * 2 + 1][k],
					Conv1_Image[i * 2 + 1][j * 2 + 1][k]);
}

void Conv2() {
	int i, j, k;
	int i2, j2, k2;
	float tmp_ans;
	for (i = 0; i < IMAGE_DIM / 2; i++)
		for (j = 0; j < IMAGE_DIM / 2; j++)
			for (k = 0; k < CONV2_OUT_DIM; k++) {
				tmp_ans = 0.0;
				for (i2 = -CONV_RANGE; i2 <= CONV_RANGE; i2++)
					for (j2 = -CONV_RANGE; j2 <= CONV_RANGE; j2++)
						for (k2 = -CONV_RANGE; k2 < CONV1_OUT_DIM; k2++)
							if (i + i2 >= 0 && j + j2 >= 0 && i + i2 < IMAGE_DIM / 2 && j + j2 < IMAGE_DIM / 2)
								tmp_ans += Conv2_W[CONV_MID + i2][CONV_MID + j2][k2][k] * Pool1_Image[i + i2][j + j2][k2];
				tmp_ans += Conv2_B[k];
				tmp_ans = RELU(tmp_ans);
				Conv2_Image[i][j][k] = tmp_ans;
			}
}

void MaxPool2() {
	int i, j, k;
	for (i = 0; i < IMAGE_DIM / 4; i++)
		for (j = 0; j < IMAGE_DIM / 4; j++)
			for (k = 0; k < CONV2_OUT_DIM; k++)
				Pool2_Image[i][j][k] = max(Conv2_Image[i * 2][j * 2][k],
					Conv2_Image[i * 2 + 1][j * 2][k],
					Conv2_Image[i * 2][j * 2 + 1][k],
					Conv2_Image[i * 2 + 1][j * 2 + 1][k]);
}

void Flatten() {
	int i, j, k;
	for (i = 0; i < IMAGE_DIM / 4; i++)
		for (j = 0; j < IMAGE_DIM / 4; j++)
			for (k = 0; k < CONV2_OUT_DIM; k++)
				Flat_Image[i*(IMAGE_DIM / 4)*CONV2_OUT_DIM + j * CONV2_OUT_DIM + k] = Pool2_Image[i][j][k];
}

void Fc1() {
	int i, j;
	float tmp_ans;
	for (i = 0; i < FC1_OUT_DIM; i++) {
		tmp_ans = 0.0;
		for (j = 0; j < (IMAGE_DIM / 4)*(IMAGE_DIM / 4)*CONV2_OUT_DIM; j++)
			tmp_ans += Flat_Image[j] * Fc1_W[j][i];
		tmp_ans += Fc1_B[i];
		tmp_ans = RELU(tmp_ans);
		FC1_Image[i] = tmp_ans;
	}
}

void Fc2() {
	int i, j;
	float tmp_ans;
	for (i = 0; i < FC2_OUT_DIM; i++) {
		tmp_ans = 0.0;
		for (j = 0; j < FC1_OUT_DIM; j++)
			tmp_ans += FC1_Image[j] * Fc2_W[j][i];
		tmp_ans += Fc2_B[i];
		FC2_Image[i] = tmp_ans;
	}
}

void Get_Answer() {
	float max = FC2_Image[0];
	int max_point = 0;
	int i;
	for (i = 1; i < FC2_OUT_DIM; i++)
		if (FC2_Image[i] > max) {
			max = FC2_Image[i];
			max_point = i;
		}
	float sum = 0.0;
	for(i = 0; i < FC2_OUT_DIM; i++) {
		Softmax[i] = exp(FC2_Image[i]);
		sum += Softmax[i];
	}
	for(i = 0; i < FC2_OUT_DIM; i++) {
		Softmax[i] /= sum;
	}
	ans = max_point;

	max = -1;
	max_point = -1;
	for(i = 0; i < FC2_OUT_DIM; i++)
		if(Softmax[i] > max && i != ans) {
			max_point = i;
			max = Softmax[i];
		}
	subop = max_point;

	printf("\nHere are the results:\n");

	for(i = 0; i < FC2_OUT_DIM; i++)
		printf("Softmax[%d] = %d.%d\n", i, (int)(Softmax[i] * 100.0), ((int)(Softmax[i] * 1000.0) % 10));
}

#endif /* CNN_RECOGNITION_H_ */
