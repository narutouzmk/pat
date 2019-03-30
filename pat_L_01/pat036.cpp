#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAX +0.1
#define MIN -0.1

double opn[3] = {0.0};
double ren[3] = {0.0};
char opr[4] = {'+','-','*','/'};

void input(double, double, double, double, char);
void output(char op);

void add_op(double, double, double, double);
void sub_op(double, double, double, double);
void mulity_op(double, double, double, double);
void divide_op(double, double, double, double);

double c1, c2, d1, d2;

int main(void){
	double a1, b1;
	double a2, b2;

	scanf("%lf %lf %lf %lf", &a1, &b1, &a2, &b2);

	c1 = int(a1 * 100 + 0.5) / 100.0;
	d1 = int(b1 * 100 + 0.5) / 100.0;
	c2 = int(a2 * 100 + 0.5) / 100.0;
	d2 = int(b2 * 100 + 0.5) / 100.0;

	for(int i = 0; i < 4; ++i){
		input(a1, b1, a2, b2, opr[i]);
	}

	return 0;
}

void input(double a1, double b1, double a2, double b2, char c){
	char op = c;
	switch(op){
		case '+':
			add_op(a1, b1, a2, b2);
			output(op);
			break;

		case '-':
			sub_op(a1, b1, a2, b2);
			output(op);
			break;
		
		case '*':
			mulity_op(a1, b1, a2, b2);
			output(op);
			break;
		
		case '/':
			divide_op(a1, b1, a2, b2);
			output(op);
			break;
	}
}

void output(char c){
	char op = c;
	switch(op){
		
		case '+':
			if(d1 < MIN && d2 < MIN){
				d1 *= -1;
				d2 *= -1;
				printf("(%.1lf-%.1lfi) + (%.1lf-%.1fi) = ", c1, d1, c2, d2);
			}else if(d1 < MIN && d2 > MAX){
				d1 += -1;
				printf("(%.1lf-%.1lfi) + (%.1lf+%.1fi) = ", c1, d1, c2, d2);
			}else if(d1 > MAX && d2 < MIN){
				d2 += -1;
				printf("(%.1lf+%.1lfi) + (%.1lf-%.1fi) = ", c1, d1, c2, d2);
			}else{
				printf("(%.1lf+%.1lfi) + (%.1lf+%.1fi) = ", c1, d1, c2, d2);
			}

			if((ren[1] > MIN && ren[1] < MAX)&&(ren[2] < MAX && ren[2] > MIN)){
				printf("0.0");
			}else if(ren[1] > MIN && ren[1] < MAX && (ren[2] > MAX || ren[2] < MIN)){
				int sign = ren[2] > MAX ? 1 : -1;
				ren[2] *= ren[2] > MAX ? 1 : -1;

				if(sign == -1){
					printf("-%.1lfi", ren[2]);
				}else{
					printf("%.1lfi", ren[2]);
				}
			}else if(ren[2] > MIN && ren[2] < MAX && (ren[1] > MAX || ren[1] < MIN)){
				int sign = ren[1] > MAX ? 1 : -1;
				ren[1] *= ren[1] > MAX ? 1 : -1;

				if(sign == -1){
					printf("-%.1lfi", ren[1]);
				}else{
					printf("%.1lfi", ren[1]);
				}
			}else{
				int sign2 = ren[2] > MAX ? 1 : -1;
				ren[2] *= sign2 == 1 ? 1 : -1;
				printf("%.1lf ", ren[1]);

				if(sign2 == 1){
					printf("+ ");
				}else{
					printf("- ");
				}

				printf("%.1lfi", ren[2]);
			}
			printf("\n");
			break;

		case '-':
			if(d1 < MIN && d2 < MIN){
				d1 *= -1;
				d2 *= -1;
				printf("(%.1lf-%.1lfi) - (%.1lf-%.1fi) = ", c1, d1, c2, d2);
			}else if(d1 < MIN && d2 > MAX){
				d1 *= -1;
				printf("(%.1lf-%.1lfi) - (%.1lf+%.1fi) = ", c1, d1, c2, d2);
			}else if(d1 > MAX && d2 < MIN){
				d2 *= -1;
				printf("(%.1lf+%.1lfi) - (%.1lf-%.1fi) = ", c1, d1, c2, d2);
			}else{
				printf("(%.1lf+%.1lfi) - (%.1lf+%.1fi) = ", c1, d1, c2, d2);
			}

			if((ren[1] > MIN && ren[1] < MAX)&&(ren[2] < MAX && ren[2] > MIN)){
				printf("0.0");
			}else if(ren[1] > MIN && ren[1] < MAX && (ren[2] > MAX || ren[2] < MIN)){
				int sign = ren[2] > MAX ? 1 : -1;
				ren[2] *= ren[2] > MAX ? 1 : -1;

				if(sign == -1){
					printf("-%.1lfi", ren[2]);
				}else{
					printf("%.1lfi", ren[2]);
				}
			}else if(ren[2] > MIN && ren[2] < MAX && (ren[1] > MAX || ren[1] < MIN)){
				int sign = ren[1] > MAX ? 1 : -1;
				ren[1] *= ren[1] > MAX ? 1 : -1;

				if(sign == -1){
					printf("-%.1lfi", ren[1]);
				}else{
					printf("%.1lfi", ren[1]);
				}
			}else{
				int sign2 = ren[2] > MAX ? 1 : -1;
				ren[2] *= sign2 == 1 ? 1 : -1;
				printf("%.1lf ", ren[1]);

				if(sign2 == 1){
					printf("+ ");
				}else{
					printf("- ");
				}

				printf("%.1lfi", ren[2]);
			}
			printf("\n");
		break;

		case '*':
			if(d1 < MIN && d2 < MIN){
				d1 *= -1;
				d2 *= -1;
				printf("(%.1lf-%.1lfi) * (%.1lf-%.1fi) = ", c1, d1, c2, d2);
			}else if(d1 < MIN && d2 > MAX){
				d1 *= -1;
				printf("(%.1lf-%.1lfi) * (%.1lf+%.1fi) = ", c1, d1, c2, d2);
			}else if(d1 > MAX && d2 < MIN){
				d2 *= -1;
				printf("(%.1lf+%.1lfi) * (%.1lf-%.1fi) = ", c1, d1, c2, d2);
			}else{
				printf("(%.1lf+%.1lfi) * (%.1lf+%.1fi) = ", c1, d1, c2, d2);
			}

			if((ren[1] > MIN && ren[1] < MAX)&&(ren[2] < MAX && ren[2] > MIN)){
				printf("0.0");
			}else if(ren[1] > MIN && ren[1] < MAX && (ren[2] > MAX || ren[2] < MIN)){
				int sign = ren[2] > MAX ? 1 : -1;
				ren[2] *= ren[2] > MAX ? 1 : -1;

				if(sign == -1){
					printf("-%.1lfi", ren[2]);
				}else{
					printf("%.1lfi", ren[2]);
				}
			}else if(ren[2] > MIN && ren[2] < MAX && (ren[1] > MAX || ren[1] < MIN)){
				int sign = ren[1] > MAX ? 1 : -1;
				ren[1] *= ren[1] > MAX ? 1 : -1;

				if(sign == -1){
					printf("-%.1lfi", ren[1]);
				}else{
					printf("%.1lfi", ren[1]);
				}
			}else{
				int sign2 = ren[2] > MAX ? 1 : -1;
				ren[2] *= sign2 == 1 ? 1 : -1;
				printf("%.1lf ", ren[1]);

				if(sign2 == 1){
					printf("+ ");
				}else{
					printf("- ");
				}

				printf("%.1lfi", ren[2]);
			}
			printf("\n");
			break;

		case '/':
			if(d1 < MIN && d2 < MIN){
				d1 *= -1;
				d2 *= -1;
				printf("(%.1lf-%.1lfi) / (%.1lf-%.1fi) = ", c1, d1, c2, d2);
			}else if(d1 < MIN && d2 > MAX){
				d1 *= -1;
				printf("(%.1lf-%.1lfi) / (%.1lf+%.1fi) = ", c1, d1, c2, d2);
			}else if(d1 > MAX && d2 < MIN){
				d2 *= -1;
				printf("(%.1lf+%.1lfi) / (%.1lf-%.1fi) = ", c1, d1, c2, d2);
			}else{
				printf("(%.1lf+%.1lfi) / (%.1lf+%.1fi) = ", c1, d1, c2, d2);
			}
			
			if((ren[1] > MIN && ren[1] < MAX)&&(ren[2] < MAX && ren[2] > MIN)){
				printf("0.0");
			}else if(ren[1] > MIN && ren[1] < MAX && (ren[2] > MAX || ren[2] < MIN)){
				int sign = ren[2] > MAX ? 1 : -1;
				ren[2] *= ren[2] > MAX ? 1 : -1;

				if(sign == -1){
					printf("-%.1lfi", ren[2]);
				}else{
					printf("%.1lfi", ren[2]);
				}
			}else if(ren[2] > MIN && ren[2] < MAX && (ren[1] > MAX || ren[1] < MIN)){
				int sign = ren[1] > MAX ? 1 : -1;
				ren[1] *= ren[1] > MAX ? 1 : -1;

				if(sign == -1){
					printf("-%.1lfi", ren[1]);
				}else{
					printf("%.1lfi", ren[1]);
				}
			}else{
				int sign2 = ren[2] > MAX ? 1 : -1;
				ren[2] *= sign2 == 1 ? 1 : -1;
				printf("%.1lf ", ren[1]);

				if(sign2 == 1){
					printf("+ ");
				}else{
					printf("- ");
				}

				printf("%.1lfi", ren[2]);
			}
			printf("\n");
			break;
	}
}

void add_op(double a1, double b1, double a2, double b2){
	ren[1] = a1 + a2;
	ren[2] = b1 + b2;
	ren[1] = int(ren[1] * 100 + 0.5) /100.0;
	ren[2] = int(ren[2] * 100 + 0.5) /100.0;
}

void sub_op(double a1, double b1, double a2, double b2){
	ren[1] = a1 - a2;
	ren[2] = b1 - b2;
	ren[1] = int(ren[1] * 100 + 0.5) /100.0;
	ren[2] = int(ren[2] * 100 + 0.5) /100.0;
}


void mulity_op(double a1, double b1, double a2, double b2){
	ren[1] = a1 * a2 - b1 * b2;
	ren[2] = a1 * b2 + b1 * a2;
	ren[1] = int(ren[1] * 100 + 0.5) /100.0;
	ren[2] = int(ren[2] * 100 + 0.5) /100.0;
}

void divide_op(double a1, double b1, double a2, double b2){
	ren[1] = (a1 * a2 + b1 * b2)/(a2 * a2 + b2 * b2);
	ren[2] = (a2 * b1 - a1 * b2)/(a2 * a2 + b2 * b2);
	ren[1] = int(ren[1] * 100 + 0.5) /100.0;
	ren[2] = int(ren[2] * 100 + 0.5) /100.0;
}
