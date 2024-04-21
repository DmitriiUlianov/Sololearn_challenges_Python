''' You receive a date and need to know what day of the week it is.  
  
Task:  
Create a program that takes in a string containing a date, and outputs the day of the week. 
 
Input Format:  
A string containing a date in either "MM/DD/YYYY" format or "Month Day, Year" format. 
 
Output Format:  
A string containing the day of the week from the provided date. 
 
Sample Input:  
11/19/2019 
 
Sample Output:  
Tuesday

Explanation:  
19 November 2019 is a Tuesday. '''

from datetime import datetime
import re
days = ["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"]
months = {
    "January" : 1,
    "February" : 2,
    "March" : 3,
    "April" : 4,
    "May" : 5,
    "June" : 6,
    "July" : 7,
    "August" : 8,
    "September" : 9,
    "October" : 10,
    "November" : 11,
    "December" : 12
    }
string = input()
mylist = re.split(r'/| |, ', string)
if mylist[0].isdigit():
    mydate = datetime(int(mylist[2]),int(mylist[0]),int(mylist[1]))
    print(days[mydate.weekday()])
else:
    mydate = datetime(int(mylist[2]),months[mylist[0]],int(mylist[1]))
    print(days[mydate.weekday()])
