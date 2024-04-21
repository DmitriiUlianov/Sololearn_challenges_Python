''' You are given a list of whole numbers in ascending order. You need to find which numbers are missing in the sequence. 
 
Task:  
Create a program that takes in a list of numbers and outputs the missing numbers in the sequence separated by spaces. 
 
Input Format:  
The first input denotes the length of the list (N). The next N lines contain the list elements as integers.  
 
Output Format:  
A string containing a space-separated list of the missing numbers. 
 
Sample Input:  
5 
2 
4 
5 
7 
8 
 
Sample Output:  
3 6

Explanation:  
The input list is missing the numbers 3 and 6. '''

length = int(input())
mylist = []
while length > 0:
    mylist.append(int(input()))
    length -= 1
temp = mylist[0]
for i in mylist:
    while i > temp + 1:
        print(temp + 1, end = " ")
        temp += 1
    temp = i
