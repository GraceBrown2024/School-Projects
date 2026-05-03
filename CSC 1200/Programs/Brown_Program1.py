# GRACE BROWN
# Last mod: 20 OCTOBER 2025
# PROGRAM ONE: ASKII SQUARE

####### FUNCTIONS ######################

def print2byN(n):                                   #The width of this square is hardcoded to 2
    if n <= 0:                                      #Prevents the top of the square from being printed in case user input is 0
        print("2byN...THERE IS NO SQUARE WITH NO LENGTH!")
    else:                             
        printTop(2)
        for i in range(n):                          #The lenggth is determined by N
            printSide(2)
            printTop(2)

    
    

def print4byN(n):                                   #The width of this square is hardcoded to 4
    if n <= 0:                                      #Prevents top of square from printing in case user input is 0
        print("4byN...THERE IS NO SQUARE WITH NO LENGTH")
    else:
        printTop(4)
        for i in range(n):                          #The length is determined by N
            printSide(4)
            printTop(4)


def printMbyN(m,n):                                 #Calls the PrintTop and PrintSide helper functions
    if n <= 0:
        print("Custom Square...YOU CANNOT HAVE A SQUARE WITH A NO VALUE!")   
    elif m <= 0:                                                            #Ensures there are no 0 or negative values
        print("Custom Square...YOU CANNOT HAVE A SQUARE WITH NO VALUE!")
    else:                             
        printTop(m)                                 #The width is determined by M 
        for i in range(n):                          #the length begins with this loop and is determined by N
            printSide(m)
            printTop(m)


def printTop(n):                                    #Function used for **both** the top and bottom of the squares
    print('+', end=' ')
    for i in range(n):                              #Repeats the horizontal print of the squares to add more rows
        print("- - - - +", end= " ")
    print()                                         #Print statement to break off the final [end=" "]

def printSide(n):                                   #Function used for the Sides 
   print("|", end= " ")
   for i in range(n):
        print("        |", end= " ")                
   print()                                          #Each repeating block of print/loop/print is to repeat the horizontal print FOUR times exactly vertically
   print("|", end= " ")
   for i in range(n):
        print("        |", end= " ")
   print()                                          #Empty print allows a line break after the horizontal print finishes
   print("|", end= " ")
   for i in range(n):
        print("        |", end= " ")
   print()
   print("|", end= " ")
   for i in range(n):
        print("        |", end= " ")
   print()



############ MAIN FUNCTION #############

def main():
    print("--- Welcome to Ascii Heaven---")                                         #This begins the "intro" and user inputs for the modular inputs
    first_length = int(input("How long would you like your 2byN square? > "))       #This determines the N in the 2byN function
    second_length = int(input("How long would you like your 4byN square? > "))      #This determines the N in the 4byN function

    print("----------------------------")
    third_width = int(input("How WIDE would you like your custom square? > "))      #This dermines the M in the MbyN function
    third_length = int(input("How LONG would you like your custom square? > "))     #This determines the N in the MbyN function
    print("----------------------------")

    print2byN(first_length)                                                         #Begins printing each of the squares with given lengths
    print4byN(second_length)
    printMbyN(third_width, third_length)

    print(" ")           
    print("")                              
print("Thank you for playing with my Squares!")                                     #Outro


########### CALLING MAIN ###############
if __name__ == "__main__":
    main()
