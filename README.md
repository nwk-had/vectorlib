# vectorlib
このプログラムでは、3次元ベクトルに対する数種類の演算関数が用意されています。これは以前、ロボットの6自由度Ikを解いたときの副産物です。
簡単なプログラムで需要もなさそうですが、せっかくなので公開します。ご自由にお使いください。
それぞれの関数については、ソースコードに日本語の説明があります。
nwk-had
@RoboSafs01075


This program provides several types of arithmetic functions for three-dimensional vectors. This is a byproduct of solving the robot's six degrees of freedom Ik before.

float* Rot(float x[3], float y[3], short axis/*1:x,2:y,3:z*/, float deg);
Function that returns a vector y rotated by deg around vector x in the direction of the axis.

float* Rot2(float x[3], short axis/*1:x,2:y,3:z*/, float deg);
Another version of the Rot function.
The argument itself is rewritten as a rotated vector.

float* CrossProduct(float x1[3], float x2[3], float y[3]);
Returns the cross product of vectors.

float InnerProduct(float x1[3], float x2[3]);
Returns the inner product of vectors.

float* Normalize(float x[3], float y[3]);
Function to return a vector of size 1 parallel to the argument.

float* Normalize2(float x[3]);
Another version of the Normalize function.
The argument itself is rewritten as a normalized vector.

float AngleOfVecs(float x1[3], float x2[3]);
Calculates the angle between two vectors.

float* SumVect(float y[3], float dy[3],short bairitsu);
Returns a vector that is the sum of two vectors.
y=y+bairitsu*dy

float* SumVect2(float x[3], float dx[3], float y[3],short bairitsu);
Another version of the Normalize function.
y=x+bairitsu*dx

float CalcNorm(float x[3]);
Calculates the magnitude of the vector of arguments.

float* DiscompVect(float v[3], float p[3], float q[3], float s_t_[2]);
For v = s・p + t・q, find s, t when v, p, q are known.
