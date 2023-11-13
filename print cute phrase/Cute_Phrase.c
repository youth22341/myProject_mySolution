#include<stdio.h>

void Cute_Phrase(int h){
	int i,j;
	for(i = 1; i <= h; i++){
		for(j = 1; j <= (h+27)/2; j++){
			if(i == 1){
				if(j <= 3 || j == (h+13)/2 || j == (h+15)/2 || j == (h+21)/2 || j == (h+27)/2) printf("*");
				else printf(" ");
			}
			if(i == 2 || i == h-1){
				if(j == 2 || j == (h+7)/2 || j == (h+11)/2 || j == (h+17)/2 || j == (h+21)/2 || j == (h+27)/2) printf("*");
				else printf(" ");
			}
			if(i >= 3 && i <= (h-1)/2){
				if(j == 2 || j == (-2*i+h+11)/2 || j == (h+17)/2 || j == (h+21)/2 || j == (h+27)/2) printf("*");
				else printf(" ");
			}
			if(i == (h+1)/2){
				if(j == 2 || j == 5 || j == (h+13)/2 || j == (h+15)/2 || j == (h+21)/2 || j == (h+27)/2) printf("*");
				else printf(" ");
			}
			if(i >= (h+3)/2 && i <= h-2){
				if(j == 2 || j == (2*i-h+9)/2 || j == (h+17)/2 || j == (h+21)/2 || j == (h+27)/2) printf("*");
				else printf(" ");
			}
			if(i == h){
				if(j <= 3 || j == (h+13)/2 || j == (h+15)/2 || j == (h+23)/2 || j == (h+25)/2) printf("*");
				else printf(" ");
			}
		}
		if(i < h) printf("\n");
	}
}

int main(){
	Cute_Phrase(9);
	return 0;
}
