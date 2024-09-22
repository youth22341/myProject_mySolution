#include<stdio.h>

int getPow(int a,int b); // get a^b
double roundAnyPrecision(double n, int m); // round number n with m precision, m is integer

int getPow (int a, int b){
	int i;
	int result = 1;
	for(i = 1; i <= b; i++)
		result *= a;
	return result;
}

double roundAnyPrecision (double n, int m){
    double res = n - (int)n; 
    int coeff_1 = getPow(10,m);
    if(coeff_1*res - (int)(coeff_1*res) == 0) return n; 
    else{ 
        int k = (int)n; 
        int coeff_2 = 10*coeff_1;
        int ans_1 = (int)(coeff_1*res);
		int ans_2 = (int)(coeff_2*res); 
        if(ans_2 % 10 >= 5) { 
            return k + (ans_1 + 1)/(1.0*coeff_1);
        }
        else return k + ans_1/(1.0*coeff_1);
    }
}

int main(){
    printf("%lf",roundAnyPrecision(5.468,0));
    return 0;
}
