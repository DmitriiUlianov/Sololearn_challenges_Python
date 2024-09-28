/* You are in charge of security at a casino, and there is a thief who is trying to steal the casino's money!  Look over the security diagrams to make sure that you always have a guard between the thief and the money! 
There is one money location, one thief, and any number of guards on each floor of the casino. 
 
Task:  
Evaluate a given floor of the casino to determine if there is a guard between the money and the thief, if there is not, you will sound an alarm. 
 
Input Format: 
A string of characters that includes $ (money), T (thief), and G (guard), that represents the layout of the casino floor.   
Space on the casino floor that is not occupied by either money, the thief, or a guard is represented by the character x. 
 
Output Format:  
A string that says 'ALARM' if the money is in danger or 'quiet' if the money is safe. 
 
Sample Input:  
xxxxxGxx$xxxT 
 
Sample Output: 
 ALARM

Explanation:  
This input should set off the alarm because there is no guard between the money and the thief! */

/*
#include<stdio.h>
#include<string.h>

int main(){

    char input[100];
    scanf("%s", input);
    int length = strlen(input);
    int money_location;
    int thief_location;

    for(int i=0; i<length; ++i){
        if(input[i]=='$')
            money_location = i;
        if(input[i]=='T')
            thief_location = i;
    }
    if (money_location < thief_location){
        for (int i=money_location+1; i<thief_location; ++i){
            if (input[i]=='G'){
                printf("quiet");
                return 0;
            }
        }
    }
    if (thief_location < money_location){
        for (int i=thief_location+1; i<money_location; ++i){
            if (input[i]=='G'){
                printf("quiet");
                return 0;
            }
        }
    }
    printf("ALARM");
    return 0;
}
*/

/*
#include <stdio.h>

int main(){
    char input[100];
    scanf("%s", input);
    char* it = input;
    int thief_founded = 0;
    int money_founded = 0;
    char* message = 0;

    while (*it) {
        switch(*it++) {
            case '$':
                money_founded = 1;
                if (thief_founded) {
                    message = "ALARM";
                }
                break;
            case 'T':
                thief_founded = 1;
                if (money_founded) {
                    message = "ALARM";
                }
                break;
            case 'G':
                if (thief_founded || money_founded) {
                    message = "quiet";
                }                
                break;
        }
        if (message) {
            break;
        }
    }

    printf("%s", message);

    return 0;
}

*/
/*
#include <stdio.h>

int main(){
    char input[100];
    scanf("%s", input);
    char* it = input;
    int someone_founded = 0;

    while (*it) {
        switch(*it++) {
            case '$':
            case 'T':
                if (someone_founded) {
                    printf("ALARM");
                    return 0;
                }
                someone_founded = 1;
                break;
            case 'G':
                if (someone_founded) {
                    printf("quiet");
                    return 0;                    
                }
                break;
        }
    }

    return 0;
}
*/
#include <stdio.h>

int main(){
    char input[100];
    scanf("%s", input);
    char* it = input;

    while (*it != '$' && *it != 'T')
        ++it;

    while (*++it) {
        switch(*it) {
            case '$':
            case 'T':
                printf("ALARM");
                return 0;
            case 'G':
                printf("quiet");
                return 0;
        }
    }
    
    return 0;
}
