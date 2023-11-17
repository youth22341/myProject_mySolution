#include<stdio.h>
#include<math.h>

double roundOnePrecision (double n){
    double res = n - (int)n; //Take the decimal of float number. 
                             //Ex: 3.453 -> res = 0.453
    if(10*res - (int)(10*res) == 0) return n; //Check that res is 1 number (after '.') or not. 
                                              //If res is one number, such as 0.2, then 10*res is integer
    else{ //res is more than 1 number (afer '.')
        int k = (int)n; //Take the integer of float number n. Ex: 3.453 -> k = 3
        int ans = (int)(100*res); //Multiple 100 times the res to take 2 number after '.'
                                 //Ex: res = 0.453 -> ans = 45
        if(ans % 10 >= 5) { //Condition to round number n. Ex: ans % 10 = 5 >= 5 
            return k + 0.1*((ans + 10)/10); //Keep 2 number after '.' - Rounding. 
                                            //Ex: ans = 45 -> (ans + 10)/10 = 5 -> 0.1*5 = 0.5 => return 3 + 0.5 = 3.5
        }
        else return k + 0.1*(ans/10); //Keep 1 number after '.'
                                      //Ex: res = 0.445 -> ans = 44 -> ans % 10 = 4 < 5
                                      //-> ans/10 = 4 -> 0.1*4 = 0.4 => return 3 + 0.4 = 3.4
    }
}

int main(){
    printf("%lf",roundOnePrecision(5.568));
    return 0;
}



