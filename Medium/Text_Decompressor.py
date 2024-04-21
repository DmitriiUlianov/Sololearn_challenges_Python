''' You need to decompress text. The compressed version has a number next to each symbol/letter, representing the amount of time that symbol should appear.  
For example, a2b3 is the compressed version of aabbb 
 
Task:  
Write a program that takes the compressed text as input and outputs the decompressed version. 
 
Input Format:  
A single string with letters/symbols, each followed by a number. 
 
Output Format:  
A string, representing the decompressed text. 
 
Sample Input:  
k2&4b1 
 
Sample Output:  
kk&&&&b

Explanation: The letter k appears 2 times, the symbol & - 4 times and the letter b - 1 time. '''

string = input()
temp = ""
for i in string:
    if not i.isdigit():
        print(i, end = "")
        temp = i 
    else:
        digit = int(i)
        while(digit > 1):
            print(temp, end = "")
            digit -= 1
