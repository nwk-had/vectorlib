/*
 * matrixlib.h
 *
 *  Created on: 2022/08/27
 *      Author: nwk-had @RoboSafs01075
 */

#ifndef MATLIXLIB_H_
#define MATLIXLIB_H_



#endif /* MATLIXLIB_H_ */


float* Rot(float x[3], float y[3], short axis/*1:x,2:y,3:z*/, float deg);
float* Rot2(float x[3], short axis/*1:x,2:y,3:z*/, float deg);
float* CrossProduct(float x1[3], float x2[3], float y[3]);
float InnerProduct(float x1[3], float x2[3]);
float* Normalize(float x[3], float y[3]);
float* Normalize2(float x[3]);
float AngleOfVecs(float x1[3], float x2[3]);
float* SumVect(float y[3], float dy[3],short bairitsu);
float* SumVect2(float x[3], float dx[3], float y[3],short bairitsu);
float CalcNorm(float x[3]);
float* DiscompVect(float v[3], float p[3], float q[3], float s_t_[2]);
