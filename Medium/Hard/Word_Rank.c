/* A word is a sequence of letters A-Z. Rearranging the letters in the word, you can come up with new words, composed of the same letters.  
For example, the letters in the word TESTING can be rearranged to result in SETTING. 
If we sort all the words made up of the same set of letters alphabetically, we can calculate the rank of each word.   
 
Task: 
Given a word (not limited to just "dictionary words"), calculate and output its rank among all the words that can be made from the letters of that word. The word can contain duplicate letters. 
 
Input Format: 
A string, representing a sequence of letters (A-Z). 
 
Output Format: 
An integer, representing the rank of the given word. 
 
Sample Input: 
ABAB 
 
Sample Output: 
2

Explanation: Let's create a list of all the words that can be made up of the letters of the input and sort them alphabetically: 
1. AABB 
2. ABAB 
3. ABBA 
4. BAAB 
5. BABA 
6. BBAA 
The given word is number 2 in the list. */

// Program to print all permutations of a string in sorted order.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Following function is needed for library function qsort(). */

int compare(const void* a, const void* b)
{
    return (*(char*)a - *(char*)b);
}
 
// A utility function two swap two characters a and b
void swap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
 
// This function finds the index of the smallest character
// which is greater than 'first' and is present in str[l..h]
int findCeil(char str[], char first, int l, int h)
{
    // initialize index of ceiling element
    int ceilIndex = l;
    // Now iterate through rest of the elements and find the
    // smallest character greater than 'first'
    for (int i = l + 1; i <= h; i++)
        if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;
    return ceilIndex;
}
 
// Print all permutations of str in sorted order
void sortedPermutations(char str[])
{

    /// my code////
    char my_str[10]={0};
    strcpy(my_str, str);
    
    //////////////
    
    
    // Get size of string
    int size = strlen(str);
    // Sort the string in increasing order
    qsort(str, size, sizeof(str[0]), compare);
    // Print permutations one by one
    bool isFinished = false;
    while (!isFinished) {
        // print this permutation
        static int x = 1;
        //printf("%d  %s \n", x++, str);
        
        /// my code////
        if(strcmp(str, my_str)==0){
            printf("%d", x);
            break;
        }
        x++;
        //////////////
        
        // Find the rightmost character which is smaller
        // than its next character. Let us call it 'first
        // char'
        int i;
        for (i = size - 2; i >= 0; --i)
            if (str[i] < str[i + 1])
                break;
        // If there is no such character, all are sorted in
        // decreasing order, means we just printed the last
        // permutation and we are done.
        if (i == -1)
            isFinished = true;
        else {
            // Find the ceil of 'first char' in right of
            // first character. Ceil of a character is the
            // smallest character greater than it
            int ceilIndex = findCeil(str, str[i], i + 1, size - 1);
            // Swap first and second characters
            swap(&str[i], &str[ceilIndex]);
            // Sort the string on right of 'first char'
            qsort(str + i + 1, size - i - 1, sizeof(str[0]), compare);
        }
    }
}

int main()
{   
    char input[10];
    scanf("%s", input);
    sortedPermutations(input);
    return 0;
}
