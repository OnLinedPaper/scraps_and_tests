import random

#seed the RNG with system time
random.seed(None)

#all the characters we'll be using
lowers = 'qwertyuiopasdfghjklzxcvbnm'
uppers = 'QWERTYUIOPASDFGHJKLZXCVBNM'
number = '0123456789'

#how long the generated string will be - change this as you wish
length = 12

#repeat until CTRL-C
while True:
  #get a random position for the uppercase letter
  uprspot = random.randint(0, length-1)
  numspot = uprspot

  while uprspot == numspot:
    #get a random position for the number that ISN'T the upper letter's space
    numspot = random.randint(0, length-1)

  strgen = ""

  #generate the string
  for i in range (0, length):
    #check if it's time to print the uppercase letter
    if i == uprspot:
      strgen += random.choice(uppers)

    #check if it's time to print the number
    elif i == numspot:
      strgen += random.choice(number)

    #neither - print a lowercase letter
    else:
      strgen += random.choice(lowers)

  #prints to STDOUT - feel free to redirect this to a file
  print(strgen)

