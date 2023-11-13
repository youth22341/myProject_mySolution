#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//Calculate all combinations
unsigned long combination(int a, int b) {
    int i;
    unsigned long result1 = 1;
    unsigned long result2 = 1;
    for(i = 1; i <= a; i++)
        result1 *= i;
    for(i = 1; i <= a-b; i++) {
        if(a == b) {
            result2 = 1;
            break;
        }
        else result2 *= i;
    }
    return result1/result2;
}

int main() {
    char S[13] = "UMESO";  //All suggest characters from the game, the order of element in string is depend on you
    char S2[13] = "Mxxxx"; //Type of words are missing
    char S1[13];
    char S3[13];
    int i,j,p,r;
    int length_S;
    int length_S2;
    int rand_pos;
    int count_character = 0;
    unsigned long combine;
    srand(time(NULL));
    printf("Input: \n===========\n");
    printf("Title: %s\n",S);
    printf("Type of word want to find: %s\n",S2);
    length_S = strlen(S);
    length_S2 = strlen(S2);
    
    //Create string S3 = S2
    for(i = 0; i < length_S2; i++)
        S3[i] = S2[i];
        
    //Count the number of characters which is already exist, then create a string contain all characters can be filled in
    for(i = 0; i < length_S2; i++) {
        for(j = 0; j < length_S; j++) {
            if(S[j] == S3[i]) {
                count_character++;
                for(r = j; r < length_S; r++)
                    S[r] = S[r+1];
                break;
            }
        }
    }
    
    //Create string S1 = S
    for(i = 0; i < length_S; i++)
        S1[i] = S[i];
    combine = combination(length_S - count_character,length_S2 - count_character);
    printf("\n===========\nOutput:\n") ;
    printf("Characters that can be filled in: %s\n",S);
    printf("Combinations: %u\n",combine);
    for(p = 1; p <= combine; p++) {
        for(i = 0; i < strlen(S2); i++) {
            rand_pos = rand() % (length_S - count_character);
            if(S3[i] == 'x' && S1[rand_pos] != 'x') {
                S3[i] = S1[rand_pos];
                S1[rand_pos] = 'x';
            }
            else if(S3[i] == 'x' && S1[rand_pos] == 'x') i--;
            else continue;
        }
        S3[i] = '\0';
        printf("%s ",S3);
        
        //Recreate string S1 and S3
        for(r = 0; r < length_S2; r++)
            S3[r] = S2[r];
        for(r = 0; r < length_S; r++)
            S1[r] = S[r];
    }
    return 0;
}
