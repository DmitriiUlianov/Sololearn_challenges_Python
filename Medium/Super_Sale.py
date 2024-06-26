''' Your favorite store is having a sale! You pay full price for the most expensive item that you get, 
but then you get 30% off of everything else in your purchase! How much are you going to save?  
Sales tax is 7%.  
Also, you leave anything below a dollar in your saving as a tip to the seller. If your saving is a round amount, you don't leave any tips. 
 
Task:  
Given the prices of items you want to purchase, determine how much you will save during your shopping!  
 
Input Format:  
An string of numbers separated by commas that represent the prices for all of the items that you want to purchase (without tax). 
 
Output Format:  
An integer number that represents the total savings that you got for shopping during the sale. 
 
Sample Input:  
100.25,80.99,40.00 
 
Sample Output:  
38

Explanation:  
With the sale, you would get 30% off of the second two items. The amount you save is $36.297, and $38.83779 when you consider the 7% tax. 
After leaving the 0.83779 as a tip, your final saving is $38. '''

string = input()
list_prices = string.split(",")
float_list_prices = list(map(float, list_prices))
max_price = max(float_list_prices)

sum_without_discount = sum(float_list_prices)
'''
sum_with_discount = 0
for i in float_list_prices:
    if i != max_price:
        sum_with_discount += 0.7*i
    else:
        sum_with_discount += i
print(int(1.07*(sum_without_discount - sum_with_discount)))
'''
print(int(1.07*(0.3*(sum_without_discount - max_price))))
