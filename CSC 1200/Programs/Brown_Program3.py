#GRACE BROWN
#PROGRAM 3
#DUE: 8 December 2025
#LAST MODIFIED: 1 December 2025

def introBanner():                                              #Provides title of program for singular run
    print("························")
    print("Tennessee Tech University")
    print("----STUDENT DATABASE----")
    print("························")

def addStudent(student_dict):                                   #Allows user to add a new dicitonary/student
    print()
    dict = student_dict
    last_key = max(student_dict.keys())                         #Evaluates the largest key integer
    new_Tnum = last_key + 1                                     #Generates new T# one integer larger than the previous key

    
    result = True
    while True:                                                 #Loop to ensure a first and last name are entered
        name = input("New Name (First Last): ").strip()         #.strip() ensures theer is no trailing space to interfere with username                
        if " " in name:                                         #Checks if there is a space to denote two names
            major = input("New Major: ")                        #If space is detected, program proceeds with adding student
            concen = input("New Concentration: ")                
                                    
            user = name.split()                                 #Splits the name up into two strings
            first_name = user[0]                            
            last_name = user[1]

            first_initial = first_name[0]                       
            last_initials = last_name[:4]

            username = (first_initial + last_initials).lower()  #Combined the initials into a new username

            f_name = first_name[0].upper()+ first_name[1:].lower()
            l_name = last_name[0].upper()+ last_name[1:].lower()
            name = f_name + " " + l_name                        #Esures the name is in First, Last format with no random capitalizations or extra spaces

            new_student = {                                     #New dicitonary using input values
                "Name" : name,
                "Username" : username,
                "Major" : major,
                "Concentration" : concen
            }

            dict.update({new_Tnum : new_student})               #Connects the new key to the new value and adds to end of dictionary
            print()
            print(f"{new_student["Name"]} has been added to the Database!")
            print()
            
            result = False
            break                                               #Breaks while loop

        else:                                                   #If only one name is entered, the error message will appear
            print()
            print("Please Enter a First and Last name!")
            print()
            result = True
        print()

def modifyStudent(student_dict):                                #Similar to addStudent()
    dict = student_dict
    print()
    print("Please enter the T# of the student you wish to Modify...")
    num = input("T#")                                          #Converts input to int to match to key
    print()
    if num.isdigit() == True:
        num = int(num)
        result = True 
        if num in dict:                                         #Checks if student is in dictionary
            result = True
            while True:                                         #If student is in dicionary, loop begins
                new_name = input("Updated First and Last Name: ").strip()
                if " " in new_name:                             #Checks if there is a first and last name entered
                    new_major = input("Updated Major: ")
                    new_concentration = input("Updated Concentration: ")
                                                
                    user = new_name.split()                     #Splits first and last name into seperate strings
                    first_name = user[0]
                    last_name = user[1]

                    first_initial = first_name[0]               #First initial first name
                    last_initials = last_name[:4]               #First four initials of last name
                    new_user = (first_initial + last_initials).lower()

                    f_name = first_name[0].upper()+ first_name[1:].lower()
                    l_name = last_name[0].upper()+ last_name[1:].lower()
                    name = f_name + " " + l_name                #Ensures first and last name begin with a capital letter

                    dict.update({num : {
                    "Name": name, 
                    "Username" : new_user, 
                    "Major" : new_major,
                    "Concentration" : new_concentration
                    }
                    })
                    result = False                              #Breaks loop
                    break
                
                else:                                           #Error message if no last name entered
                    print()
                    print("Please enter a First and Last name!")
                    print()
            
        else:                                                   #If student ID not found, error message prints
            print()
            print("Student Not Found")
        print()
    else:
        print("Please only enter Numbers!")

def viewStudent(student_dict):                                  #Prints each dictionary, keys, and values
    dict = student_dict
    for key in dict:                                            #Iterates through dictionary
        print()
        print(f"T{key}")                                        #Automatically adds T
        print("---------------------------------------------------")
        print(f"Name:          {dict[key]["Name"]}")            
        print(f"Username:      {dict[key]["Username"]}")
        print(f"Major:         {dict[key]["Major"]}")
        print(f"Concentration: {dict[key]["Concentration"]}")
        print("---------------------------------------------------")

def removeStudent(student_dict):                                #Deletes whole student dictionary based on Key provided
    dict = student_dict

    print()
    print("Please enter the T# of the Student you wise to delete...")
    num = input("T#")                                           #Allows user to input integer that correclates to student Key
    print()
    if num.isdigit() == True:
        if int(num) in dict:                                    #If student number (converted to int) is found in dictionary, it will be deleted
            print(f"{dict[int(num)]["Name"]} has been Deleted!")
            del dict[int(num)]
        else:                                                   #If Student number is NOT found, error message will appear
            print("This Student does Not Exist!")
    else:
        print("Please Only Enter Numbers!")

    print()


def menu():                                                     #Allows user to choose which selection they want
    result = True

    while result == True:                                       #Loop to either continue program or exit
        print()
        print("Please make a selection...")
        print("""
[1] View All Current Students
[2] Enter New Student Data
[3] Remove Student Data
[4] Modify Student Data
[5] EXIT PROGRAM           
""")
        choice = input("...")
        if choice in ["1", "2", "3", "4"]:                      #List of valid options to check for
            result = True                                       #If choice is in the list, then the program  continues
            break
        elif choice == "5":                                     #If choice is 5, the program exits
            result = False
            break
        else:                                                   #If choice is NOT in the list, the inner loop repeats until valid choice is selected
            print()
            print("Please enter a VALID selection!")
            print()
    return result, choice                                       #Returns two values: one to determine Main Loop and the other to determine which path the program will take
    
def main():
    ############# STARTER DATA ####################

    student_dict = {
        123 : {"Name" : "Hannah Brown", "Username": "hbrow", "Major": "Computer Science", "Concentration" : "Cybersecurity"}, 
        124 : {"Name" : "Hayden Patrick", "Username": "hpatr", "Major": "Engineering", "Concentration": "Civil" },
        125 : {"Name" : "Jeffery Cart", "Username": "jcart", "Major": "Engineering", "Concentration": "N/A"}, 
        126 : {"Name" : "William Smart", "Username" : "wsmar", "Major": "Engineering", "Concentration": "Mechatronics"}
        }

    ############# FUNCTIONS #######################
    introBanner()                                               #Prints Program Title
    result = True
    while result:                                               #Main loop for selection
        result, choice = menu()
        if choice == "1":                                       #Prints all student info
            viewStudent(student_dict)

        elif choice == "2":                                     #Allows user to create new dictionary
            addStudent(student_dict)

        elif choice == "3":                                     #Allows user to remove chosen dictionary 
            removeStudent(student_dict)

        elif choice == "4":                                     #Allows user to modify chosen dictionary
            modifyStudent(student_dict)

        elif choice == "5":                                     #Exits program
            print()
            print("You Have Exited The Program")
            print()

            
        
################# INITIATES MAIN ##################

if __name__ == "__main__":
    main()