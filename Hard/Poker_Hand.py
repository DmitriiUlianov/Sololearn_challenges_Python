''' You are playing poker with your friends and need to evaluate your hand.  
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

Explanation: The hand includes two Jacks and two 2s, resulting in Two Pairs. '''

import sys
myHand = input()

myDict = {
    '2': 1,
    '3': 2,
    '4': 3,
    '5': 4,
    '6': 5,
    '7': 6,
    '8': 7,
    '9': 8,
    '10': 9,
    'J': 10,
    'Q': 11,
    'K': 12,
    'A': 13
}

myHandList = myHand.split()

# checking Flush (if myHandSuite = 5)
if len(myHandList[0]) == 2:
    myHandSuite = myHand.count(myHand[1])
else:
    myHandSuite = myHand.count(myHand[2])

# creating the list of values    
myValueList = []
for i in myHandList:
    if len(i) == 2:
        myValueList.append(i[0:1])
    else:
        myValueList.append(i[0:2])

# sorting myValueList
myValueListSorted = sorted(myValueList, key = lambda item: myDict[item])

# checking Straight (if straightCheck = 5)
straightCheck = 0
i = 0
for j in myValueListSorted:
    if myDict.get(myValueListSorted[i]) == myDict.get(myValueListSorted[i + 1]) - 1:
        straightCheck += 1
        if i < 3:
            i += 1

if myHandSuite == 5:
    if straightCheck == 5 and "A" in myValueList:
        print("Royal Flush")
        sys.exit()
    if straightCheck == 5 and "A" not in myValueList:
        print("Straight Flush")
        sys.exit()
    else: 
        print("Flush")
        sys.exit()
        
if myHandSuite != 5 and straightCheck == 5:
    print("Straight")
    sys.exit()
'''   
num = [myValueListSorted[0].count]
j = 1
while j < 5:
    if myValueListSorted[j] != myValueListSorted[j - 1]
        num.append(myValueListSorted[j].count)
'''    
    
if  myValueListSorted.count(myValueListSorted[0]) == 4 or myValueListSorted.count(myValueListSorted[1]) == 4:
    print("Four of a Kind")
    sys.exit()
    
if  (myValueListSorted.count(myValueListSorted[0]) == 2 and myValueListSorted.count(myValueListSorted[2]) == 3) or (myValueListSorted.count(myValueListSorted[0]) == 3 and myValueListSorted.count(myValueListSorted[3]) == 2):
    print("Full House")
    sys.exit()

if  myValueListSorted.count(myValueListSorted[0]) == 3 or myValueListSorted.count(myValueListSorted[1]) == 3 or myValueListSorted.count(myValueListSorted[2]) == 3:
    print("Three of a Kind")
    sys.exit()        

if  myValueListSorted.count(myValueListSorted[0]) == 2 and myValueListSorted.count(myValueListSorted[2]) == 2:
    print("Two pairs")
    sys.exit()  
if  myValueListSorted.count(myValueListSorted[1]) == 2 and myValueListSorted.count(myValueListSorted[3]) == 2:
    print("Two pairs")
    sys.exit() 
if  myValueListSorted.count(myValueListSorted[0]) == 2 and myValueListSorted.count(myValueListSorted[3]) == 2:
    print("Two pairs")
    sys.exit() 

k = 0
for i in myValueListSorted:
    OnePair = myValueListSorted.count(myValueListSorted[k])
    k += 1
    if OnePair == 2:
        print("One Pair")
        sys.exit() 
        
print("High Card")
