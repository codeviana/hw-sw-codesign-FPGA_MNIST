#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#include "CNN_recognition.h"
#include "altera_avalon_pio_regs.h"
#include "altera_up_avalon_character_lcd.h"


char str_ans[] = "Result: 0";
char str_pro[] = "0:000% 0:000%";
unsigned char capturedImage[64][64];
float sum_value[28][28], sum_n[28][28];
unsigned char recognize_flag;
unsigned int *pChar162 = LCD_0_BASE;


void Recognition() {

	int i, j;
	int tmp_i, tmp_j;



	for(i = 0; i < 28; i++){
		for(j = 0; j < 28; j++) {
			sum_value[i][j] = 0.0;
			sum_n[i][j] = 0.0;
		}
	}
	// Resize the digit from 64*64 to 28*28 for the CNN
	for(i = 0; i < 64; i++) {
		for(j = 0; j < 64; j++) {
			tmp_i = (int)((float)i * 28.0 / 64.0);
			tmp_j = (int)((float)j * 28.0 / 64.0);
			sum_value[tmp_i][tmp_j] += (capturedImage[i][j]);
			sum_n[tmp_i][tmp_j] += 1;

			//printf("sum_value[%d] = %d.%d | CI = %d\n", tmp_i, (int)(sum_value[tmp_i][tmp_j] * 1.0), ((int)(sum_value[tmp_i][tmp_j] * 1000.0) % 10), (int)capturedImage[i][j]);
		}
		//printf(";\n");
	}

	for(i = 0; i < 28; i++){
		for(j = 0; j < 28; j++){
			Input_Image[i][j] = 1.0 - sum_value[i][j] / (float)sum_n[i][j] / 255.0;
			//Input_Image[i][j] = sum_value[i][j] / (float)sum_n[i][j] / 255;
			//printf("%d.%d,", (int)(Input_Image[i][j] * 1.0), ((int)(Input_Image[i][j] * 1000.0) % 10));
		}
		//printf(";\n");
	}
	for(j = 0; j < 28; j++)
		Input_Image[0][j] = 0.0;

	// Start calculating
	CNN_MNIST_recognition();





	// Display the reliability of the two most possible numbers using the result of softmax
	int tmp2;
	tmp2 = (int)(Softmax[ans] * 100.0);
	str_pro[0] = 48 + ans;
	str_pro[2] = 48 + (tmp2 / 100);
	str_pro[3] = 48 + (tmp2 / 10 % 10);
	str_pro[4] = 48 + (tmp2 % 10);

	tmp2 = (int)(Softmax[subop] * 100.0);
	str_pro[7] = 48 + subop;
	str_pro[9] = 48 + (tmp2 / 100);
	str_pro[10] = 48 + (tmp2 / 10 % 10);
	str_pro[11] = 48 + (tmp2 % 10);
	//LCD_Disp(2, 0, str_pro, 13);

	// hahaha
	if((int)(Softmax[ans] * 100) < 65) {
		//LCD_Disp(1, 0, "Do not xjb Draw", 15);
		//LCD_Disp(2, 0, "Duo Lao A      ", 15);
		//*(pUser_SEG8) = 0xffff0000;
	}

	// When recognizing work is just finished, only 'clear screen' button is enabled.
	recognize_flag = 1;
}

int main() {
	printf("Welcome to MNIST classification. Turn on SW[2] to start\n(Leave ON to repeat // Turn OFF otherwise)\n");
	int i, j, sw, count=0;
	unsigned char pixel;

	FILE *fp;
	char s[] = "Hello\nWorld!";
	alt_up_character_lcd_dev * char_lcd_dev;
	char_lcd_dev = alt_up_character_lcd_open_dev ("/dev/lcd_0");


	while(1) {

		sw = IORD_ALTERA_AVALON_PIO_DATA(SWITCH_BASE);

		if (sw==4){
			fp = fopen(LCD_0_NAME, "w");
			for(i =0; i < 64; i++)
			  {
				  for(j=0; j < 64; j++)
				  {
					  IOWR_ALTERA_AVALON_PIO_DATA(READ_ADDRESS_BASE, count & 0xFFFFFFFFFFFF);

					  pixel = IORD_ALTERA_AVALON_PIO_DATA(PIXEL_BASE);

					  capturedImage[i][j]= pixel;

					  count++;
				  }
			  }
			printf("\nStarting Recognition: Please standby...\n");
			Recognition();

			if(fp){
				//fwrite("", strlen(""), 1, fp);
				str_ans[8] = 48 + ans;
				fwrite(str_ans, strlen(str_ans), 1, fp);
				fclose(fp);
				alt_up_character_lcd_set_cursor_pos(char_lcd_dev, 0, 0);
			}
			else
				printf("File could not be open\n");
			printf("Answer = %d\n", ans);
		  }

	}
	return 0;
}


