#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define MIN 10
#define MAX 100

void nhap (int *a, int *n) {
    while (*n < MIN || *n > MAX){
        printf("Give me the number of elements of an array (at least %d elements and maximum %d elements): ",MIN,MAX);
        scanf("%d",n) ;
    }
    int i;
    for (i = 0; i < *n; i++){
        printf("a[%d] = ",i) ;
        scanf("%d",&a[i]);
    }
}

void sapxep_mang_a (int *a, int *n) {
    int i, j;
    for (i = 0; i < *n; i++){
        for (j = i + 1; j < *n  ; j++){
            if (a[j] < a[i]){
                int tg = a[j];
                a[j] = a[i];
                a[i] = tg;
            }
		}
    }
}

void xoatrung_mang_a(int *a, int *n){
	int i,j; int q = 0;
    for (i = 0;i < *n-1;i++){
    	j=i+1;
    	while (j< *n)
	    	if (a[i] == a[j]){
	        	for (q = j; q< *n-1;q++) 
					a[q] = a[q+1];
	    	*n=(*n)-1;
	    	}
	    else j++;
	}
}

void sapxep_mang_b (int *b, int *n) {
    int i, j;
    for (i = 0; i < *n; i++){
        for (j = i + 1; j < *n  ; j++){
            if (b[j] < b[i]){
                int tg = b[j];
                b[j] = b[i];
                b[i] = tg;
            }
        }
    }
}

void xoatrung_mang_b(int *b, int *n){
	int i,j; int q = 0;
	for (i = 0;i <*n-1;i++){
    	j=i+1;
    	while (j< *n)
	    	if (b[i] == b[j]){
	        	for (q = j;q <*n-1;q++) 
					b[q] = b[q+1];
	    	*n=(*n)-1;
	    	}
	    else j++;
	}
}

void xoa_mang_a (int *a,  int n,  int k,  int l) {
    int i; 
    if (l == 0) {
    	for (i = 0; i < n; i++){
    		a[i] = a[i+1];
    	}
	}
    else {
    	int b = 1;
    	for (i = 0; i < n ; i++){
        	a[i] = a[k+l+b];
        	b++;
        }
    }
}

void xoa_mang_b (int *b,  int n,  int k,  int l) {
    int i; 
    if (l == 0) {
    	for (i = 0; i < n; i++){
    		b[i] = b[i+1];
    	}
	}
    else {
    	int c = 1;
    	for (i = 0; i < n ; i++){
        	b[i] = b[k+l+c];
        	c++;
        }
    }
}

int main(){
    int l, i; int m ;
    int n; int choice; int a[100]; int *b;
	do{
		system("cls");
		do{
			system("color A1");
			printf("\t\t\tYou only have these choices: \n");
			printf("1. Type the number of elements of an array (MIN = 10, MAX = 100) and elements (don't need to be difference, but should be natural number) by yourself.\n");
			printf("2. The program will random both the number of elements of an array and elements automatically.\n");
			printf("3. Exit.\n");
			printf("\t\t\tYour choice is: ");
			scanf("%d",&choice);
		}while (choice != 1 && choice != 2 && choice != 3);
	    
	    switch (choice){
	    	case 1: 
				nhap(a,&n); 
				printf("\nArray which is given: \n");
	    		for(i = 0; i < n; i++)
	    			printf("%5d",a[i]);
	    		xoatrung_mang_a(a,&n);
	    		sapxep_mang_a(a,&n) ; 
	    		printf("\nArray which is ascending sorted (and remove all similer):\n");
				for (i = 0; i < n; i++)
				printf("%5d", a[i]);
				m = 0;
    			for (i=0; i < n ; i++){
				l = 0;
				    if (a[i+1] - a[i] == 1){
					    while (i < n && a[i+1] - a[i] == 1){
					        l++;
					        printf("\n%d\n",a[i]);
					        i++;
					    }
					    printf("\n%d\n",a[i]);
					    m++;
					    printf("\nBlock %d\n",m) ;
					    printf("============\n");
					    int k = i - 1 - l; 
					    n -= (l+1); 
					    xoa_mang_a(a,n,k,l);  i = 0;
				    }
				    else {
				    	int k = i ; int l = 0;
				    	n-=1;
				        xoa_mang_a(a,n,k,l); i = 0;
					}         
				}
				if (m != 0)
				    printf("Array which is given contains %d bolock of order natural number\n",m) ;
				else
				    printf("Array which is given does not contain any block of order natural number\n");
				printf("Press Enter to continue choosing.");
				getch();            
    			break;
	    	case 2: 
				srand(time(NULL)); 
				n = rand()%91 + 10;
				printf("The number of elements: n = %d\n\n",n);
				b = (int *)malloc(n * sizeof(int));
				for (i = 0; i < n; i++){
					b[i] = rand()%(n+10);
					printf("a[%d] = %d\n",i,b[i]);
				}
				printf("\nArray which is given: \n");
				for (i = 0; i < n; i++)
			        printf("%5d",b[i]);
			    xoatrung_mang_b(b,&n);
			    sapxep_mang_b(b,&n) ;
			    printf("\nArray which is ascending sorted (and remove all similer):\n");
				for (i = 0; i < n; i++)
					printf("%5d", b[i]);
			    m = 0;
			    for (i=0; i < n ; i++){
				l = 0;
				    if (b[i+1] - b[i] == 1){
					    while (i < n && b[i+1] - b[i] == 1){
					        l++;
					        printf("\n%d\n",b[i]);
					        i++;
					    }
					    printf("\n%d\n",b[i]);
					    m++;
						printf("\nBlock %d\n",m) ;
					    printf("============\n");
					    int k = i - 1 - l; 
					    n -= (l+1); 
					    xoa_mang_b(b,n,k,l);  i = 0;
				    }
				    else {
				    	int k = i ; int l = 0;
				    	n-=1;
				        xoa_mang_b(b,n,k,l); i = 0;
					}         
				}
				if (m != 0)
				    printf("\nArray which is given contains %d bolock of order natural number\n",m) ;
				else
				    printf("\nArray which is given does not contain any block of order natural number\n");
				free(b);
				printf("Press Enter to continue choosing.");
				getch();            
			    break;
		    case 3: printf("\n\tThanks for joining. See you again!"); break;
		    default: break;
		}		
	} while(choice == 1 || choice == 2);
	
	return 0;
}

