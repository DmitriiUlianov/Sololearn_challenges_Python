''' You are given a word and want to split it into even parts based on a number that is provided, each half being the size of the number. 
 
Task:  
Write a program that takes in a string, and a number as input.  
Split the string into even parts sized by the number, and output the parts separated by hyphens.  
The last part of the output will be any leftover, as the input string might not split into the provided parts evenly. 
 
Input Format:  
Two inputs: a string and an integer. 
 
Output Format:  
A string, representing the hyphen-separated parts. 
 
Sample Input:  
hello 
2 
 
Sample Output:  
he-ll-o

Explanation: 
We split the word "hello" into 2-sized parts. The last letter o was leftover, resulting in the output he-ll-o. '''

'''
string = input()
num = int(input())
number = num
new_string = ""
count = 0
for i in string:
    new_string += i
    count += 1
    if count == number:
        new_string += "-"
        number += num
        
length = len(new_string)
if new_string[length-1] == '-':      
    print(new_string[:-1])
else:
    print(new_string)
'''
import sys
string = input()
num = int(input())
number = num
length = len(string)
count = 0

for i in string:
    print(i, end ="")
    count += 1
    if count == length:
        sys.exit()
    if count == number:
        print("-", end = "")
        number += num
