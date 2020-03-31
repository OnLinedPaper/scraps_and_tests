#Nicholas Reed 2018
#program to accept roman numerals and turn them into an int

import sys

chars = ""
chars = raw_input("numerals: ") #read the input string
chars = chars.upper() #convert to uppercase for ease of processing

val = 0; #running total
tempval = 0; #current value
lastval = 0; #last value

for letter in chars:
    if letter == "I":
        tempval = 1
    elif letter == "V":
        tempval = 5
    elif letter == "X":
        tempval = 10
    elif letter == "L":
        tempval = 50
    elif letter == "C":
        tempval = 100
    elif letter == "D":
        tempval = 500
    elif letter == "M":
        tempval = 1000
    else:
        print"character", letter, "not recognized!"
        exit()

    if(lastval < tempval): #the last value was smaller than this one -
                           #do the roman numeral subtraction
        val += (tempval - (lastval*2))
    else: #the last value was not smaller - just add this to the total
        val += tempval
    lastval = tempval   #store the value read this time
    tempval = 0         #reset the tempval

print "value:", val #print the final val
