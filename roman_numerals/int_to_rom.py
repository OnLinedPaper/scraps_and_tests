#Nicholas Reed 2018
#program to accept an int and turn it into roman numerals

import sys

inval = 0
try:
    inval = int(raw_input("integer: "))
except ValueError:
    print "invalid integer"
    exit()
outstring = "" #assemble the output string to print out all at once

while(inval > 0):
    #repeatedly subtract the largest amount possible from the input number
    #and add the corresponding numeral(s) to the output
    if(inval - 1000 >= 0):
        outstring += "M"
        inval -= 1000

    elif(inval - 900 >= 0):
        outstring += "CM"
        inval -= 900

    elif(inval - 500 >= 0):
        outstring += "D"
        inval -= 500

    elif(inval - 400 >= 0):
        outstring += "CD"
        inval -= 400

    elif(inval - 100 >= 0):
        outstring += "C"
        inval -= 100

    elif(inval - 90 >= 0):
        outstring += "XC"
        inval -= 90

    elif(inval - 50 >= 0):
        outstring += "L"
        inval -= 50

    elif(inval - 10 >= 0):
        outstring += "X"
        inval -= 10

    elif(inval - 9 >= 0):
        outstring += "IX"
        inval -= 9;

    elif(inval - 5 >= 0):
        outstring += "V"
        inval -= 5

    elif(inval - 4 >= 0):
        outstring += "IV"
        inval -= 4

    elif(inval - 1 >= 0):
        outstring += "I"
        inval -= 1

print "output:", outstring
