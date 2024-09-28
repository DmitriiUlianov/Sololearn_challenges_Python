/* You're given a representation of a 5x5 2D map, and if you can only move left, right, up, or down, 
determine how many moves you would have to make to get between two points on the map. 
 
Task: 
 Determine the total number of moves that are needed between two points on a map.  
 The points that you move between are marked with a P and the spaces in between are marked with X. 
 
Input Format:  
A string that represents the 2D space starting at the top left.  Each level from top to bottom is separated by a comma. 
 
Output Format:  
An integer that represents the total number of moves that you had to make. 
 
Sample Input:  
XPXXX,XXXXX,XXXXX,XXXPX,XXXXX 
 
Sample Output:  
5

Explanation: 
The map looks as: 
XPXXX 
XXXXX 
XXXXX 
XXXPX 
XXXXX 
 
You had to move right 2 spaces, then down 3 spaces for a total of 5 moves. */

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int func(char token[5]){
    int res=0;
    int i;
    int j;
    for(i=0; i<5; ++i){
        if(token[i]=='P'){
            res=i+1;
            if(i==4)
                return res; 
        }
    }
    for(j=i+1; j<5; ++j){
        if(token[j]=='P'){
            res=(j+1)-res;
        }
    } 
    return res; 
}
    
int main(){
    
    char input[100];
    fgets(input, 100, stdin);
    
    int num_token=1;
    int res=0;
    int arr[4]={0};
    int i=0;
    for(char* token=strtok(input,",\n"); token!=NULL; token=strtok(NULL,",\n")){
        res=func(token);
        if(res!=0){
            arr[i++]=num_token;
            arr[i++]=res;
        }
        ++num_token;
    }
    printf("%d", (arr[2]-arr[0])+abs(arr[3]-arr[1]));
    
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100]; 
    char *ptr = input - 1;// чтобы в while сделать *++ptr сразу и начать с первого элемента строки(чтобы не тратить лишнюю строку и не ставить    *++ptr в конце while)
    fgets(input, 100, stdin);
    int x = -1, y = -1;// чтобы не путать с индексом массива 0..4

    while (*++ptr) {
        if (*ptr == 'P') {
            if (x == -1) { //считаем значение первого Р
                x = (ptr - input) % 6;
                y = (ptr - input) / 6;
            } else { // считаем значение второго Р, вычисляем разницу и выводим на печать
                printf("%d", abs((int)(ptr - input) % 6 - x) + abs((int)(ptr - input) / 6 - y));
            }
        }
    }

    return 0;
}
