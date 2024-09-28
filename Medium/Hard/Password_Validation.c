/* You're interviewing to join a security team. They want to see you build a password evaluator for your technical interview to validate the input. 
 
Task:  
Write a program that takes in a string as input and evaluates it as a valid password. The password is valid if it has at a minimum 2 numbers, 
2 of the following special characters ('!', '@', '#', '$', '%', '&', '*'), and a length of at least 7 characters. 
If the password passes the check, output 'Strong', else output 'Weak'. 
 
Input Format: 
A string representing the password to evaluate. 
 
Output Format: 
A string that says 'Strong' if the input meets the requirements, or 'Weak', if not. 
 
Sample Input:  
Hello@$World19 
 
Sample Output:  
Strong

Explanation: 
The password has 2 numbers, 2 of the defined special characters, and its length is 14, making it valid. */

/*
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    
    char string[256];
    fgets(string, 256, stdin);
    int count_digits = 0;
    int count_symbols = 0;
    char symbols[]={'!','@','#','$', '%','&','*'};

    int length = strlen(string);
    if (length < 7){
            printf("Weak");
            return 0;
    }
    for (int i=0; i<=length; ++i ){
        if (isdigit(string[i]))
            ++count_digits;
    }       
    for (int i=0; i<=length; ++i ){
        for(int j=0; j<7; ++j){
            if (string[i]==symbols[j])
                ++count_symbols; 
        }
    }        
    if (count_digits>=2 && count_symbols>=2)
        printf("Strong");
    else 
        printf("Weak");
    
    return 0;
}
*/
/*
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char string[256];
    fgets(string, 256, stdin);
    int count_digits = 0;
    int count_symbols = 0;
    int length = strlen(string);
    if (length >= 7){
        char* it = string;
        while (*it) {
            switch(*it) {
                case '!': case '@': case '#': case '$':case '%': case '&': case '*':
                    ++count_symbols;
                    break;
                default:
                   if (isdigit(*it)) {
                       ++count_digits;
                    }
                    break;
            }
            ++it;
        }
        if (count_digits >= 2 && count_symbols >= 2) {
            printf("Strong");
            return 0;
        }
    }

    printf("Weak");
    return 0;
}
*/
#include<stdio.h>
#include<ctype.h>

int main(){
    char string[256],*it = string - 1;
    fgets(string, 256, stdin);
    int counters[3] = { 0 };

    while (*++it)
        ++counters[(isdigit(*it) != 0) + (*it <= '@')];
    
    printf(counters[0] + counters[1] + counters[2] >= 7 
        && counters[1] >= 2 
        && counters[2] >= 2 ? "Strong" : "Weak");

    return 0;
}
