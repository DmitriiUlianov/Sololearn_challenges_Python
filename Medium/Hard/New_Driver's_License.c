/* You have to get a new driver's license and you show up at the office at the same time as 4 other people. 
The office says that they will see everyone in alphabetical order and it takes 20 minutes for them to process each new license. 
All of the agents are available now, and they can each see one customer at a time. How long will it take for you to walk out of the office with your new license? 
 
Task  
Given everyone's name that showed up at the same time, determine how long it will take to get your new license. 
 
Input Format  
Your input will be a string of your name, then an integer of the number of available agents, and lastly a string of the other four names separated by spaces. 
 
Output Format  
You will output an integer of the number of minutes that it will take to get your license. 
 
Sample Input 
'Eric' 
2 
'Adam Caroline Rebecca Frank' 
 
Sample Output  
40

Explanation  
It will take 40 minutes to get your license because you are in the second group of two to be seen by one of the two available agents.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
   
   char my_name[100];
   scanf("%s", my_name);
   int agents;
   scanf("%d%*c", &agents);
   char names[100];
   fgets(names,100,stdin);
   char *people[4];
   int queue;
   int minutes;
   int i=0;
   double count=1;
   
   for(char *token=strtok(names," "); token != NULL;token=strtok(NULL," ")){
        people[i++]=token;
    }
    for(int i=0; i<4; ++i){
       if(strcmp(my_name,people[i])>0)
            ++count;
    }
    
    queue = ceil(count/agents);
    minutes = queue*20;
    printf("%d", minutes);
    
    return 0;
}
