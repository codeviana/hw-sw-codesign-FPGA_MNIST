#ifndef PARA_FC2
#define PARA_FC2

//#include "global_variables.h"

float Fc2_W_raw[FC1_OUT_DIM * FC2_OUT_DIM] = {
	-0.234396725893, -0.402224034071, -0.077828988433, -0.044855944812, -0.309480696917, 0.218093603849, -0.082400687039, 0.168606460094, -0.167492434382, -0.145766437054,
	-0.066975258291, -0.324415832758, -0.165363520384, -0.073629945517, 0.190918534994, 0.204443246126, 0.206288814545, -0.097281306982, 0.127540320158, -0.190584823489,
	-0.064917854965, 0.026846196502, -0.065266042948, 0.027040949091, -0.150148525834, 0.108824647963, 0.072679162025, -0.052277255803, 0.109033599496, -0.002918982180,
	0.149908572435, -0.127827093005, 0.147847458720, -0.053055845201, -0.067939467728, -0.025279784575, 0.166621565819, -0.315995693207, -0.121500372887, -0.131274074316,
	-0.375077992678, 0.143114998937, -0.250818341970, 0.077628180385, 0.079347923398, -0.050646543503, -0.064350731671, -0.281367242336, 0.078163340688, 0.085667021573,
	0.123259879649, 0.125755146146, 0.043969377875, 0.018584121019, 0.106516525149, -0.007720518857, 0.110907919705, -0.102757595479, -0.019169071689, 0.080808699131,
	0.086867511272, -0.163941949606, 0.120582923293, 0.095870696008, -0.347584843636, -0.202117696404, -0.374375104904, 0.098085202277, 0.072781734169, -0.231802329421,
	0.045702453703, -0.296119779348, 0.001578903291, 0.079519942403, 0.101057030261, -0.048383146524, -0.385028868914, -0.351048767567, 0.089142754674, 0.069202952087,
	0.119175530970, -0.161063224077, -0.044156350195, 0.113872773945, -0.604228973389, 0.122705735266, -0.175830677152, -0.187412902713, 0.079171165824, -0.079391539097,
	0.135449633002, -0.263054132462, 0.062116645277, 0.114265024662, -0.235326185822, -0.071113586426, -0.326632887125, 0.152299046516, -0.016896646470, 0.107343278825,
	0.124991171062, -0.314633101225, -0.183202669024, -0.236147418618, -0.346913188696, 0.111161731184, 0.062925159931, 0.053854092956, 0.093921229243, 0.000865222653,
	0.139964133501, -0.060467161238, -0.193262696266, -0.005084386095, -0.047787405550, 0.110752932727, 0.031125046313, -0.000617206562, -0.100621260703, 0.011798051186,
	0.156409263611, -0.401501238346, 0.011153656058, -0.096691347659, -0.075607977808, 0.136413082480, -0.230596154928, 0.179155647755, 0.075301095843, 0.170723035932,
	-0.274501234293, -0.182234138250, 0.056270986795, 0.155339613557, -0.060807611793, -0.005041137338, -0.292158544064, -0.095103949308, -0.083977900445, -0.024870753288,
	-0.419674724340, 0.149466171861, 0.117589622736, -0.001491371426, 0.031722694635, -0.014816957526, -0.437015414238, -0.020020095631, -0.175024643540, 0.121933147311,
	-0.046635624021, 0.145397379994, 0.149943470955, 0.012132273987, -0.354454368353, -0.275952488184, 0.067014783621, 0.093486413360, 0.096525393426, -0.258316516876,
	-0.182290211320, -0.183872818947, 0.021095685661, 0.132126167417, 0.176740467548, -0.202575311065, -0.367482006550, 0.175805330276, -0.196672052145, 0.168106257915,
	-0.153254553676, -0.341181218624, 0.094703495502, -0.044580858201, 0.105639941990, -0.261130899191, 0.098126932979, 0.130864769220, -0.243015542626, 0.116312652826,
	-0.028554279357, -0.103280320764, 0.046788778156, -0.152840852737, 0.049918703735, -0.155825421214, 0.131217807531, 0.044608470052, 0.088620916009, 0.093500852585,
	0.242917552590, 0.231295391917, -0.158258661628, -0.189113810658, -0.192322596908, -0.056383404881, 0.247233316302, -0.313946187496, 0.067815124989, -0.213605672121,
	-0.336901456118, 0.103180542588, 0.112081296742, 0.122143544257, 0.085391715169, -0.014611103572, -0.423320621252, 0.142349570990, 0.113384686410, 0.130566880107,
	-0.375474572182, 0.187077179551, -0.157709583640, -0.017465084791, 0.185405537486, -0.033274296671, -0.277890294790, 0.187823504210, -0.056051462889, 0.162339225411,
	0.109132952988, 0.154612019658, -0.134784504771, 0.112727783620, -0.320397704840, 0.123657077551, 0.111209534109, -0.273532897234, -0.102362908423, -0.069881707430,
	0.075969547033, -0.238528385758, -0.272886842489, 0.018711671233, 0.150211304426, 0.110807798803, -0.087101288140, 0.033227931708, -0.259015351534, -0.053139343858,
	0.197847157717, -0.145931527019, 0.179385229945, -0.140652805567, -0.077974438667, -0.201255917549, 0.174813494086, -0.252626389265, -0.173078522086, -0.077238678932,
	-0.175925001502, 0.139676913619, 0.167457997799, 0.106788627803, -0.331854104996, -0.060465369374, -0.326729238033, 0.020917823538, 0.158683300018, -0.320934474468,
	0.148427188396, -0.034363903105, 0.197345182300, 0.191355943680, -0.362586975098, 0.190391659737, 0.022295260802, -0.087472490966, 0.037939161062, -0.196176528931,
	-0.293028742075, 0.114380747080, 0.112284176052, 0.103980526328, -0.257874816656, 0.070895969868, 0.093465335667, -0.061906870455, -0.063852943480, -0.396770596504,
	-0.373433232307, 0.081096954644, -0.205149114132, 0.045561823994, -0.171737968922, 0.089244134724, -0.270743876696, 0.076791033149, 0.069049775600, 0.066854335368,
	0.171521484852, -0.501652836800, -0.042966634035, -0.198097750545, 0.174215391278, -0.043280988932, 0.188503652811, -0.131451472640, 0.115259565413, 0.150849923491,
	-0.125158265233, -0.145960763097, 0.034650668502, -0.235801413655, 0.205909237266, 0.094551570714, 0.187727853656, -0.226710900664, 0.164939746261, 0.164889454842,
	-0.162963539362, 0.157234698534, 0.003025386482, -0.356876045465, 0.141815289855, 0.067782752216, 0.157360702753, -0.312196701765, 0.119925968349, -0.183696389198,
};

void Format_Fc2_W() {
	int i, j;
	for (i = 0; i < FC1_OUT_DIM; i++)
		for (j = 0; j < FC2_OUT_DIM; j++)
			Fc2_W[i][j] = Fc2_W_raw[i*FC2_OUT_DIM + j];
}

#endif
