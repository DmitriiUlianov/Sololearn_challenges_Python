''' You need to calculate exactly how many days have passed between two dates. 
 
Task:   
Calculate how many days have passed between two input dates, and output the result.  
 
Input Format:  
Two strings that represent the dates, first date should be the older date.  
Date format: Month DD, YYYY 
 
Output Format:  
A number representing the number of days between the two dates. 
 
Sample Input:  
August 15, 1979 
June 15, 2018 
 
Sample Output:  
14184

Explanation:  
14184 days have passed between the two input days. '''

from datetime import date
import re
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
string1 = input()
string2 = input()
firstdate = re.split(r'/| |, ', string1)
seconddate = re.split(r'/| |, ', string2)
f_date = date(int(firstdate[2]), int(months[firstdate[0]]), int(firstdate[1]))
s_date = date(int(seconddate[2]), int(months[seconddate[0]]), int(seconddate[1]))
print((s_date - f_date).days)
