''' You aren't paying attention and you accidentally type a bunch of random letters on your keyboard. 
  You want to know if you ever typed the same letter twice, or if they are all unique letters. 
 
Task:  
If you are given a string of random letters, your task is to evaluate whether any letter is repeated in the string or if you only hit unique keys while you typing. 
 
Input Format:  
A string of random letter characters (no numbers or other buttons were pressed). 
 
Output Format:  
A string that says 'Deja Vu' if any letter is repeated in the input string, or a string that says 'Unique' if there are no repeats. 
 
Sample Input:  
aaaaaaaghhhhjkll 
 
Sample Output:  
Deja Vu

Explanation:  
Your program should output 'Deja Vu' because there are many repetitions in 'aaaaaaaghhhhjkll'. '''

'''
import sys
string = input()
lenght = len(string)
i = 0
j = 1
while i < lenght:
    while j < lenght:
        if string[i] == string[j]:
            print("Deja Vu")
            sys.exit()
        j += 1
    i += 1
    j = i + 1
print("Unique")
'''

import sys
string = input()
lenght = len(string)
i = 0
while i < lenght:
    if string[i] in string[i+1:]:
        print("Deja Vu")
        sys.exit()
    i += 1
print("Unique")
