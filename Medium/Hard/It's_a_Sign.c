/* You work in a sign factory, and the machine has started printing all of the signs backwards! 
The signs have already been packed into boxes of four signs each. Every letter on every sign is capitalized, 
so if the original sign was of a palindrome (a word or phrase that is the same backwards and forwards) you can still save those signs and not have to reprint them. 
Check each box to see if you should open it up to dig out the sign you can save, or if you need to just throw the whole box in the trash. 
 
Task  
Given the four words that were supposed to be contained in each box, determine if at least one of them is of a palindrome. 
 
Input Format  
Four strings that represent the word or phrase that was supposed to be printed on the signs inside each box. 
 
Output Format  
A string that say 'Open' if at least one of the boxes is a palindrome or 'Trash' if all of the signs are misprinted. 
 
Sample Input 
CAT 
MONDAYS 
RACECAR 
TACOS 
 
Sample Output  
Open

Explanation  
RACECAR is a palindrome and is the same forwards and backwards. You will want to open this box to get that sign out. *\

/*
#include<stdio.h>
#include<string.h>

int rev_cmp(char word[100]){

    int lenght = strlen(word);
    char rev_word[100]={0};
    for (int i=0; i<lenght; ++i){
        rev_word[i]=word[lenght-1-i];
    }  
    int res=strcmp(word, rev_word);
    return res;   
}

int main(){
    char word1[100];
    char word2[100];
    char word3[100];
    char word4[100];

    scanf("%s", &word1);
    scanf("%s", &word2);
    scanf("%s", &word3);
    scanf("%s", &word4);

    int res1 = rev_cmp(word1);
    int res2 = rev_cmp(word2);
    int res3 = rev_cmp(word3);
    int res4 = rev_cmp(word4);

    printf(res1==0||res2==0||res3==0||res4==0 ? "Open":"Trash");
    
    return 0;
}
*/

#include<stdio.h>
#include<string.h>

int isPalindrom(char* word){
    int lenght = strlen(word);
    char* left = word;
    char* right = word + lenght - 1;

    while (left < right) {
        if (*left++ != *right--) {
            return 0;
        }
    }

    return 1;   
}

int main(){
    char word[4][100];

    for (int i = 0; i < 4; ++i) {
        scanf("%s", word[i]);
    }
    
    for (int i = 0; i < 4; ++i) {
        if (isPalindrom(word[i])) {
            printf("Open");
            return 0;
        }
    }

    printf("Trash");
    
    return 0;
}
