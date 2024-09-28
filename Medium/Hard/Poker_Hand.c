/* You are playing poker with your friends and need to evaluate your hand.  
A hand consists of five cards and is ranked, from lowest to highest, in the following way: 
High Card: Highest value card (from 2 to Ace). 
One Pair: Two cards of the same value. 
Two Pairs: Two different pairs. 
Three of a Kind: Three cards of the same value. 
Straight: All cards are consecutive values. 
Flush: All cards of the same suit. 
Full House: Three of a kind and a pair. 
Four of a Kind: Four cards of the same value. 
Straight Flush: All cards are consecutive values of same suit. 
Royal Flush: 10, Jack, Queen, King, Ace, in same suit.  
 
Task: 
Output the rank of the give poker hand.  
 
Input Format:  
A string, representing five cards, each indicating the value and suite of the card, separated by spaces.  
Possible card values are: 2 3 4 5 6 7 8 9 10 J Q K A 
Suites:  H (Hearts), D (Diamonds), C (Clubs), S (Spades) 
For example, JD indicates Jack of Diamonds.  
 
Output Format: 
A string, indicating the rank of the hand (in the format of the above description).  
 
Sample Input: 
JS 2H JC AC 2D 
 
Sample Output:  
Two Pairs

Explanation: The hand includes two Jacks and two 2s, resulting in Two Pairs. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    
    char input[100];  
    fgets(input,100,stdin);
    int length = strlen(input);
    char *values[]={"2","3","4","5",           
                    "6","7","8","9",
              "10","J","Q","K","A"};
    int count[13]={0};
//////////////////////// finding suit    
    char rev_input[100]={0};
    for(int i=0; i<length; ++i){
        rev_input[i]= input[length-1-i];
    }
    int count_suit=1;                    
    for(int i=1; i<length; ++i){
       if(rev_input[0]==rev_input[i])   
          ++count_suit; 
         //should be 5 for Flush
    }
///////////////////// counting cards   
    for(int i=0; i<length; ++i){
        for(int j=0; j<13;++j){
            if(input[i]==*values[j]){
                ++count[j];
            } 
        }
    }
//////////////////// finding straight 
    int count_straight = 1;
    for(int i=0; i<13;++i){
        if (count[i]==1){
            while(count[++i] == 1){
                 ++count_straight; 
       //should be 5 for Straight
            }
            break;
        }        
    }   
/////////////////////////////////////
    if (count_straight==5 && count[12]==1 && count_suit==5){
        printf("Royal Flush");
        return 0;        
    }
    if (count_straight==5 && count_suit==5){
        printf("Straight Flush");
        return 0;        
    }
    if (count_straight==5){
        printf("Straight");
        return 0;        
    }
    if (count_suit==5){
        printf("Flush");
        return 0;        
    }
/////////////////////////  finding 4    
    for(int i=0; i<13; ++i){
        if (count[i]==4){
            printf("Four of a Kind");
            return 0;
        }
/////////////////  finding 3 + 2 or 3
        if (count[i]==3){
           int m=i;
           while (++m<=12){
             if (count[m]==2){
                printf("Full House");
                return 0;
                }
           }
           printf("Three of a Kind");
           return 0;
        }
////////  finding 2 + 3 or 2 + 2 or 2
        if (count[i]==2){
            int n=i;
            while (++n<=12){
              if (count[n]==3){
                printf("Full House");
                return 0;
              }
            }
            while (++n<=12){
              if (count[n]==2){
                printf("Two Pairs");
                return 0;
              }
            }
            printf("One Pair");
            return 0;   
        }
    }
    printf("High Card");
    return 0;
}
