''' You're given a representation of a 5x5 2D map, and if you can only move left, right, up, or down, 
determine how many moves you would have to make to get between two points on the map. 
 
Task: 
 Determine the total number of moves that are needed between two points on a map.  
 The points that you move between are marked with a P and the spaces in between are marked with X. 
 
Input Format:  
A string that represents the 2D space starting at the top left.  Each level from top to bottom is separated by a comma. 
 
Output Format:  
An integer that represents the total number of moves that you had to make. 
 
Sample Input:  
XPXXX,XXXXX,XXXXX,XXXPX,XXXXX 
 
Sample Output:  
5

Explanation: 
The map looks as: 
XPXXX 
XXXXX 
XXXXX 
XXXPX 
XXXXX 
 
You had to move right 2 spaces, then down 3 spaces for a total of 5 moves. '''

string = input()
strings = string.split(",")
space = 0
pointX1 = 0
pointY1 = 0
pointX2 = 0
pointY2 = 0
index = 0 

while index < 5:
    for j in strings[index]:
        if j == "X":
            space += 1
        if j == "P":
            if pointX1 == 0:
                space += 1
                pointX1 = space
                pointY1 = index + 1
            else:   
                space += 1
                pointX2 = space
                pointY2 = index + 1
                break
                
    if pointX2 != 0:
        break 
    else:
        space = 0
        index += 1

print(pointY2 - pointY1 + abs(pointX2 - pointX1))
