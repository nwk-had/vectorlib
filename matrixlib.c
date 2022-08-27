#include <stdio.h>
#include <math.h>
#include "matrixlib.h"

#define PI 3.14

float* Rot(float x[3], float y[3], short axis/*1:x,2:y,3:z*/, float deg){
	/*
	 *ベクトルxをaxis回りにdegだけ回転したベクトルyを返す関数
	 *
	 * */

	float Rot[3][3] = {};
	float cosdeg=cos(deg/180*PI);
	float sindeg=sin(deg/180*PI);

	////回転行列準備
	if(axis==1){//x軸回りの回転

		Rot[0][0]=1;  Rot[0][1]=0;      Rot[0][2]=0;
		Rot[1][0]=0;  Rot[1][1]=cosdeg; Rot[1][2]=-sindeg;
		Rot[2][0]=0;  Rot[2][1]=sindeg; Rot[2][2]=cosdeg;

	}else if(axis==2){//y軸回りの回転

		Rot[0][0]=cosdeg;  Rot[0][1]=0; Rot[0][2]=sindeg;
		Rot[1][0]=0;  	   Rot[1][1]=1; Rot[1][2]=0;
		Rot[2][0]=-sindeg; Rot[2][1]=0; Rot[2][2]=cosdeg;

	}else if(axis==3){//z軸周りの回転

		Rot[0][0]=cosdeg;  Rot[0][1]=-sindeg; Rot[0][2]=0;
		Rot[1][0]=sindeg;  Rot[1][1]=cosdeg;  Rot[1][2]=0;
		Rot[2][0]=0; 	   Rot[2][1]=0;       Rot[2][2]=1;

	}

	short i;

	for(i=0;i<3;i++){
		//回転後のベクトルを返す
		y[i] = Rot[i][0]*x[0]+Rot[i][1]*x[1]+Rot[i][2]*x[2];
	}

	return y;
}

float* Rot2(float x[3], short axis/*1:x,2:y,3:z*/, float deg){
	/*
	 *ベクトルxをaxis回りにdegだけ回転して返す
	 *引数をそのまま変換するver
	 * */
	float y[3]={};

	float Rot[3][3] = {};
	float cosdeg=cos(deg/180*PI);
	float sindeg=sin(deg/180*PI);

	//回転行列準備
	if(axis==1){//x軸回りの回転

		Rot[0][0]=1;  Rot[0][1]=0;      Rot[0][2]=0;
		Rot[1][0]=0;  Rot[1][1]=cosdeg; Rot[1][2]=-sindeg;
		Rot[2][0]=0;  Rot[2][1]=sindeg; Rot[2][2]=cosdeg;

	}else if(axis==2){//y軸回りの回転

		Rot[0][0]=cosdeg;  Rot[0][1]=0; Rot[0][2]=sindeg;
		Rot[1][0]=0;  	   Rot[1][1]=1; Rot[1][2]=0;
		Rot[2][0]=-sindeg; Rot[2][1]=0; Rot[2][2]=cosdeg;

	}else if(axis==3){//z軸周りの回転

		Rot[0][0]=cosdeg;  Rot[0][1]=-sindeg; Rot[0][2]=0;
		Rot[1][0]=sindeg;  Rot[1][1]=cosdeg;  Rot[1][2]=0;
		Rot[2][0]=0; 	   Rot[2][1]=0;       Rot[2][2]=1;

	}

	short i;

	for(i=0;i<3;i++){
		//回転後のベクトルを返す
		y[i] = Rot[i][0]*x[0]+Rot[i][1]*x[1]+Rot[i][2]*x[2];
	}

	for(i=0;i<3;i++){
		//回転後のベクトルを返す
		x[i] = y[i];
	}

	return x;
}

float* CrossProduct(float x1[3], float x2[3], float y[3]/*出力*/){
	/*
	 * x1,x2の外積yを返す関数
	 * */
	y[0]=x1[1]*x2[2]-x1[2]*x2[1];
	y[1]=x1[2]*x2[0]-x1[0]*x2[2];
	y[2]=x1[0]*x2[1]-x1[1]*x2[0];

	return y;
}
float InnerProduct(float x1[3], float x2[3]){
	/*
	 * x1,x2の内積を返す関数
	 */
	return x1[0]*x2[0]+x1[1]*x2[1]+x1[2]*x2[2];
}

float* Normalize(float x[3], float y[3]/*?o??*/){
	/*
	 * x方向の大きさ1のベクトルyを返す関数
	 * */

	float norm = sqrtf(x[0]*x[0]+x[1]*x[1]+x[2]*x[2]);
	if(norm>0){
		y[0]=x[0]/norm; y[1]=x[1]/norm; y[2]=x[2]/norm;
	}else{
		y[0]=0; y[1]=0; y[2]=0;
	}

	return y;
}
float* Normalize2(float x[3]/*入力兼出力*/){
	/*
	 * ベクトルxの大きさを正規化して返す
	 * */

	float norm = sqrtf(x[0]*x[0]+x[1]*x[1]+x[2]*x[2]);
	if(norm>0){
		x[0]=x[0]/norm; x[1]=x[1]/norm; x[2]=x[2]/norm;
	}else{
		x[0]=0; x[1]=0; x[2]=0;
	}

	return x;
}
float AngleOfVecs(float a[3], float b[3]){
	/*
	 * 二つのベクトルx1, x2のなす角を求める関数
	 * 戻り値はrad
	 * ！！！負の値が出ないので扱いは慎重に！！！
	 */
	float x1[3]={a[0],a[1],a[2]};
	float x2[3]={b[0],b[1],b[2]};

	float rad;
	Normalize2(x1);
	Normalize2(x2);

	rad=acos((x1[0]*x2[0]+x1[1]*x2[1]+x1[2]*x2[2])
			/(sqrtf(x1[0]*x1[0]+x1[1]*x1[1]+x1[2]*x1[2])
			*sqrtf(x2[0]*x2[0]+x2[1]*x2[1]+x2[2]*x2[2])));

	return rad;

}
float* SumVect(float y[3], float dy[3],short bairitsu){
	/*
	 * ベクトルyにdyのbairitsu倍を足して返す関数
	 */
		y[0]=y[0]+bairitsu * dy[0];
		y[1]=y[1]+bairitsu * dy[1];
		y[2]=y[2]+bairitsu * dy[2];

	return y;
}
float* SumVect2(float x[3], float dx[3], float y[3],short bairitsu){
	/*
	 * ベクトルxにdxを足したyを返す関数
	 */
	y[0]=x[0]+bairitsu * dx[0];
	y[1]=x[1]+bairitsu * dx[1];
	y[2]=x[2]+bairitsu * dx[2];

	return y;
}

float CalcNorm(float x[3]){
	/*
	 * ベクトルのノルムを計算
	 */
	float norm=x[0]*x[0]+x[1]*x[1]+x[2]*x[2];

	return norm;

}

float* DiscompVect(float v[3], float p[3], float q[3], float s_t_[2]){
	/*
	 * v = s・p + t・qに対し, v, p, qが既知の時にs, tを求める
	 */

	s_t_[0]=InnerProduct(p, v);//CalcNorm(CrossProduct(cp_v_with_p));
	s_t_[1]=InnerProduct(q, v);//CalcNorm(CrossProduct(cp_v_with_q));

	return s_t_;
}
