''' The CMYK color model is the standard in the printing industry and refers to the primary colors of pigment: Cyan, Magenta, Yellow, and Black.  
K stands for 'Key' since in 4-color printing the Cyan, Magenta and Yellow printing plates are carefully keyed or aligned with the key of the Black key plate. 
RGB (Red, Green and Blue) is the color space for digital images.

The combination of RGB light creates white, while the combination of CMYK inks creates black.

A CMYK color can be converted to RGB using the following equations: 
R = 255 × (1-C) × (1-K) 
G = 255 × (1-M) × (1-K) 
B = 255 × (1-Y) × (1-K)

Remember, each component of a RGB color is in the range of [0, 255], so the resulting decimal numbers should be rounded to the nearest integers.

Task:  
Given a color in CMYK format, output the corresponding RGB color.  
 
Input Format: 
4 decimal numbers in the range of [0, 1], representing Cyan, Magenta, Yellow and Black.  
 
Output Format: 
A string, representing the corresponding RGB color, each component separated by commas. 
 
Sample Input: 
0.4 
0.49 
0.552 
0.36 
 
Sample Output:  
98,83,73

Explanation: cmyk(0.4, 0.49, 0.552, 0.36) corresponds to rgb(98, 83, 73). '''

cyan = float(input())
magenta = float(input())
yellow = float(input())
key = float(input())

R = round(255*(1 - cyan)*(1-key))
G = round(255*(1 - magenta)*(1-key))
B = round(255*(1 - yellow)*(1-key))

print(R, end = ",")
print(G, end = ",")
print(B)
