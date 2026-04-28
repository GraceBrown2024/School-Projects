#LAB 4
#GRACE BROWN
#Last modified: 31 OCTOBER 2025

import random 

def playing():                                                                  #Begins the playing loop
    result = True 

    while result == True:                                                       #As long as the result is YES, the rest of the game will play 
        print("Do you accept the job offer as a SMILING FRIEND?")
        print("[YES]  [NO]")
        selection = input(">> ")
        play = selection.upper()
        
        if play == "YES":
            result = True
            break

        elif play == "NO":                                                      #If the answer is NO, the loop breaks and exits the program entirely
            print("Alright! Damned be ye! Be gone!")
            print(" ")
            result = False
            break

        else:                                                                   #If the user selects anything OTHER than yes or no, the selection REPEATS
            print("Please choose a valid answer!")
            print(" ")
    return result                                                               #returns the user input that determines continuation of playthrough

def quest():                                                                    #holds variables and helper functions for main playthrough
    ############## VARIABLES ##############
    num = random.randint(1,3)                                                   #Depending on the number, the name of the Client changes
    if num == 1:
        client = "Mr Frog"
    elif num == 2:
        client = "Chris Chan"
    elif num == 3:
        client = "Desmond"
    
    client_hp = 100                                                             #General variables for characters`
    client_ap = 15
    friend_hp = 100
    friend_ap = 17

    turn = 0                                                                    #Begins initial "turns" for each play loop

    ############## INTRODUCTIONS ###############
    intro(client)
    print(" ")
    print("Oh! I'm sorry... I forgot your name!")
    print("Could you tell me real quick?")
    name = input("Enter Name: ")                                                #Allows the user to choose their own name instead of selecting a character
    friend = name.upper()                                                       #Makes the name all uppercase to make it easier to read
    print(" ")
    scene(friend, client)                                                       #Begins intro scene 
    print(" ")
    print("Would you like to see the STATS for this encounter?")                #Allows you to choose if you want to see the variables
    print("[YES]   [NO]")
    answer = input(">> ")
    stats = answer.upper()
    if stats == "YES":
        print(" ")
        friendStats(friend, friend_ap, friend_hp)
        clientStats(client, client_ap, client_hp)
    
    input("[Press Enter To Continue]")                                          #These are added periodically to keep the program from printing all at once


    ############## LOOPS #######################
    while True:                                                                 #Begins main gameplay loop
        turn += 1
        print(".・。.・゜✭・.・✫・゜・。.")
        print(f"TURN {turn}✧.*")
        print(" ")
        ################## HERO TURN #####################
        while True:
            print("What will you do?")
            print("[1. CHEER] [2. RUMMAGE ROOM]")
            choice = int(input(">> "))                                          #Allows user input for each choice
            if choice == 1:                                                     #CHEER is the attack
                friend_ap = calcDamage(friend_ap)
                client_hp = applyDamage(client_hp, friend_ap)
                printOutcomeFriend(friend, client, friend_ap, client_hp)        #Displays the attack returns 
                print(".・。.・゜✭・.・✫・゜・。.")
                print(" ")
                break
            elif choice == 2:                                                   #Randomly decides if the user gets a powerboost or hp boost
                search = random.randint(1,3)
                if search == 1:                                                 #Gives +10 attack boost
                    friend_ap = calcDamage(friend_ap)+10
                    print(".・。.・゜✭・.・✫・゜・。.")
                    print(" ")
                    print(f"{friend} remembered a new cheer tactic!")
                    print(f"{friend}'s Cheer rose 10 Points!")
                    print(f"{friend} now has {friend_ap} Cheer")
                    print(".・。.・゜✭・.・✫・゜・。.")
                elif search == 2:                                               #Adds 30 health points to the character
                    friend_hp = friend_hp + 30
                    print(" .・。.・゜✭・.・✫・゜・。.")
                    print(" ")
                    print(f"{friend} found a picture of {client}'s friends...")
                    print(f"{friend} remembers why he does this job...")
                    print(f"{friend}'s Motivation rose 30 points!")
                    print(f"{friend} now has {friend_hp} Motivation!")
                    print(" ")
                    print(".・。.・゜✭・.・✫・゜・。.")
                elif search == 3:                                               #Does nothing
                    print(".・。.・゜✭・.・✫・゜・。. ")
                    print(" ")
                    print("There was nothing helpful in the room!")
                    print(" ")
                    print(".・。.・゜✭・.・✫・゜・。.")

                print(" ")
                break
            else:                                                               #REPEATS loop if other choice is selected
                print("Please select a valid option!")
                print(' ')
        
        if client_hp <= 0:                                                      #Prints end screen when client loses all HP
            print(" ")
            print("▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄")
            print(" ")
            print(f"Despite all odds, {client} cracks a smile!")
            print("YOU WIN!!! YOU WIN YOU WIN YAYAYAY!!!! YA YOU WIN!!!! HE SMILED YAY!!!!")
            print(" ")
            print("▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄")
            print(" ")
            break

        print(" ")                                                             #Prevents the program from printing all at once
        input("[Press Enter To Continue]")
        print(" ")

        ################### CLIENT TURN ####################
        while True:                                                             #Prints out the client's turn for attack
            print(f"»»-----------►{client}'S TURN")
            client_ap = calcDamage(client_ap)
            friend_hp = applyDamage(friend_hp, client_ap)
            printOutcomeClient(client, friend, client_ap, friend_hp)
            break
        if friend_hp <= 0:                                                      #Prints end screen if friend loses all hp
            print(" ")
            print("▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄")
            print(" ")
            print(f"{client} sighs...")
            print(f"'You tried. Thats all that matters I guess. You can go now...")
            print(f"You failed to make {client} smile... : ( ")
            print(" ")
            print("ੈ✩‧₊˚ GAME OVER ੈ✩‧₊˚")
            print(" ")
            print("▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄")
            print(" ")
            break

        print(" ")                                                              #prevents program from printing all at once
        input("[Press Enter To Continue]")
        print(" ")


               
def calcDamage(ap):                                                             #Returns the attack for a character 
    return ap

def applyDamage(health, damage):                                                #Calculates the health after an attack
    new_health = health - damage
    if new_health <= 0:                                                         #Resets health to 0 if it goes below 
        new_health = 0
    return new_health

def printOutcomeFriend(friend, client, friend_ap, client_hp):                   #Randomly generates an outcome for the FRIEND'S attack      
   num = random.randint(1,3)
   print(" ")
   print(".・。.・゜✭・.・✫・゜・。.")
   print(" ")
   if num == 1:
       print(f"{friend} pulls out a rubber chicken and squeaks it in {client}'s face!")
       print(f"{client} blinked in sudden amusement.")
       print(" ")
   elif num == 2:
       print(f"{friend} had a deep conversation with {client}... {client} feels seen")
       print(" ")
   elif num == 3:
       print(f"{friend} brought {client} out on a date with a real girl!")
       print(f"{client} is beginning to feel less alone!")
       print(" ")
   print(f"{client} has lost {friend_ap} Sadness Points and is left with {client_hp}!")
   print(" ")
   

def printOutcomeClient(client, friend, client_ap, friend_hp):                  #Randomly generates an outcopme for the CLIENT'S attack
    num = random.randint(1,3)
    print(" ")
    print(".・。.・゜✭・.・✫・゜・。.")
    print(" ")
    if num == 1:
       print(f"{client} brushes off {friend}'s attempts at corny jokes.")
       print(f"{friend} is beginning to feel discouraged!")
    elif num == 2:
       print(f"{client} begins to tear up at nothing!")
       print(f"is {client} thinking about something sad? Or is {friend} just THIS bad at their job??")
    elif num == 3:
       print(f"{client} began to laugh at {friend}'s joke, but choked on his own spit.")
       print(f"{client} stopped laughing!")
    print(f"{friend} has lost {client_ap} Motivation Points. They are left with {friend_hp}!")


def intro(client):                                                              #Prints introduction to ease into the game
    print(".・。.・゜✭・.・✫・゜・。.")
    print("ੈ✩‧₊˚ Welcome to the Smiling Friends! *ੈ✩‧₊˚")
    print(".・。.・゜✭・.・✫・゜・。.")
    print(" ")
    print("Its your first day as a Smiling Friend (◕ᴥ◕ʋ)")
    print("I hope you're excited to make someone smile!")
    print(" ")
    print(".・。.・゜✭・.・✫・゜・。.")
    print(" ")
    print(f"╰┈➤Your first client is {client}!")
    print(" ")
    print(".・。.・゜✭・.・✫・゜・。.")

def scene(friend, client):                                                      #After name is chosen, the rest of the scene plays
    print(" ")
    print(f"Ah! {friend}! How could I forget.")
    print(f"Well, {friend}, go out there and make {client} smile!")
    print(" ")
    input("[Press Enter To Continue]")
    print(" ")
    print(".・。.・゜✭・.・✫・゜・。.")
    print(f"╰┈➤ You enter {client}'s home and see him sitting alone")
    print(f"╰┈➤ {client} looks at you without a hint of joy")
    print("╰┈➤ You take a deep breath and prepare to confront him!")
    print(" ")
    input("[Press Enter To Continue]")                                          #Prevents program from printing all at once
    print(" ")
    print(".・。.・゜✭・.・✫・゜・。.")
    print(" ")

def friendStats(name, ap, hp):                                                  #Generates stats for the FRIEND (the attack and health are named differently)
    print(".・。.・゜✭・.・✫・゜・。.")   
    print(f"════ ⋆★⋆ ════ {name}'s STATS ════ ⋆★⋆ ════")
    print(" ")
    print(f"MOTIVATION (health): {hp}")
    print(f"CHEER (attack): {ap}")
    print(".・。.・゜✭・.・✫・゜・。.")
    print(" ")

def clientStats(name, ap, hp):                                                  #Generates stats for the CLIENT
    print(".・。.・゜✭・.・✫・゜・。.")
    print(f"════ ⋆★⋆ ════ {name}'s STATS ════ ⋆★⋆ ════")
    print(" ")
    print(f"SADNESS (health): {hp}")
    print(f"DISCOURAGMENT (attack): {ap}")
    print(".・。.・゜✭・.・✫・゜・。.")
    print(" ")

def main():                                                                    #Main function holds only the main two functions (quest and playing)
    while playing():
        quest()


############## INITIATES MAIN ##################

if __name__ == "__main__":
    main()

