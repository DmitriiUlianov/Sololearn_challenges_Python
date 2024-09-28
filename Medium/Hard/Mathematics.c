/* Find which math expression matches the answer that you are given, if you have an integer answer, and a list of math expressions. 
 
Task:  
Test each math expression to find the first one that matches the answer that you are given. 
 
Input Format:  
Two inputs: an integer and a space separated string of math expressions. 
The following operations need to be supported: addition +, subtraction -, multiplication *, division /.  
An expression can include multiple operations. 
 
Output Format:  
A string that tells the index of the first math expression that matches. If there are no matches, output 'none'. 
 
Sample Input:  
15 
(2+100) (5*3) (14+1) 
 
Sample Output:  
index 1

Explanation:  
Index counting starts at 0, so '(5*3)' is at index 1 and matches your answer of 15. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int func(char *ptr){

  // ptr настроен на строку (token)

  //  char* ptr=str;//объявление переменной ptr типа char*, присвоение значения: адрес массива str (первого элемента) - не относится к этому коду
    
    int sum[10]={0};//массив чисел
    int* sum_ptr=sum;
    
    *sum_ptr = atoi(ptr);//в 1-ый элемент массива sum записываем 1-ое число из строки token на которое указывает ptr
    
    int result=0;
    
    while(*ptr != '\0'){
        
        switch(*ptr){
            case '+':
    // sum_ptr все еще настроен на 1-ый элемент массива sum
                ++sum_ptr;
    // настраиваем sum_ptr на 2-ой элемент массива sum, который пока еще равен 0, так как в массив записали нули
                ++ptr;
   // настраиваем ptr на цифру после знака'+' в строке token
                *sum_ptr = atoi(ptr); 
   // меняем значение 2-ого элемента массива sum с 0 на число, на которое указывает теперь ptr 
   // (ptr указывает на первую цифру числа, но atoi считывает все цифры числа до символа неявляющегося цифрой)
                break;
            case '-':
                ++sum_ptr;
                ++ptr;
                *sum_ptr = -atoi(ptr);
                break;
            case '*':
                ++ptr;
                *sum_ptr *= atoi(ptr);
                break;
            case '/':
                ++ptr;
                *sum_ptr /= atoi(ptr);
                break;
        }
        ptr++;
    }
    for(int i=0; i<10; ++i){
        result += sum[i];
    }
    
    return result;

}

int main(){

    int res;
    scanf("%d%*c", &res);
    
    char input[100];
    fgets(input,100,stdin);
    
    int i=0;
    
    for(char *token=strtok(input, " ()"); token!=NULL; token=strtok (NULL, " ()")){
        if(func(token)==res){
            printf("index %d", i);
            return 0;
        }
        ++i;
    }
    printf("none");
    
    return 0;
}
