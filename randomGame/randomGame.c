#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<math.h>

int randomNum(int MIN, int MAX){
    srand(time(0));
    return rand()%(MAX - MIN + 1) + MIN;
}

void randomGame(){
    int MIN, MAX;
    printf("Enter the range you want (MIN, MAX): ");
    scanf("%d %d",&MIN,&MAX);
    int times;
    times = log(MAX-MIN+1)/log(2) + 1;
    printf("You have max %d times to guess. Do you wanna beg (Y/N)? : ",times);
    char choice;
    scanf(" %c",&choice);
    int beg;
    if(choice == 'Y'){
        printf("Enter the number times you have to guess (< %d): ",times);
        scanf("%d",&beg);
    }
    printf("Let's play!\n");
    int a = randomNum(MIN,MAX);
    int count = 1;
    bool win;
    bool again = false;
    while(count <= times){
        int guess;
        printf("Your %d try: ",count);
        scanf("%d",&guess);
        if(guess == a){
            if(choice == 'Y'){
				if(count <= beg) printf("Congrats! You beg successfully!");
				else printf("You're right, but failed beg.");
			}else printf("Congrats! You're number one.");
			win = true;
            break;
        }else{
        	if(choice == 'Y' && again == false){
	        	if(count+1 > beg){
	        		printf("You have failed beg. Do you wanna continue to guess (Y/N)? : ");
	        		scanf(" %c",&choice);
	        		if(choice != 'Y'){
	        			win = false;
	        			break;
					}else again = true;
				}	
			}
			if(guess > a) printf("Your guess is bigger than the result.\n");
            else printf("Your guess is smaller than the result.\n");	
            count++;
        }
    }
    if(win != true) printf("Better luck next time. The answer is: %d",a);
}
    
int main(){
    randomGame();
    return 0;
}
