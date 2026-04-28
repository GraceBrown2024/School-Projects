#GRACE BROWN
#Lab 5
#LAST MODIFIED: 21 Nov 2025

import random, sys, time

def playing():                                                              #Allows player to decide if they want to play the game or not
    result = True 

    while result == True:                                                       #As long as the result is YES, the rest of the game will play 
        print()
        slowPrint("Are you ready to sign into your Reddit Account?")
        print("[YES]  [NO]")
        selection = input(">> ")
        play = selection.upper()
        
        if play == "YES":
            result = True
            break

        elif play == "NO":                                                      #If the answer is NO, the loop breaks and exits the program entirely
            print("Good! Enjoy being a useful member of society!")
            print(" ")
            result = False
            break

        else:                                                                   #If the user selects anything OTHER than yes or no, the selection REPEATS
            print("Please choose a valid answer!")
            print(" ")
    return result    

def calcDamage(character):                                                  #Calculates damage for player/enemy based on stats of the attacker
    return character["AP"]                                                      

def slowPrint(text, delay=0.05):                                            #Prints out each letter at a timed interval
    for c in text:
        sys.stdout.write(c)
        sys.stdout.flush()
        time.sleep(delay)
    print()

def applyDamage(char_one, char_two):                                        #Applies the damage to the victim's HP 
    new_health = char_one["HP"] - char_two["AP"]                            #Uses the dictionary reference to calculate new health
    if new_health <= 0:                                                     #Resets health to 0 if it goes below 
        new_health = 0
    return new_health                                                       #Returns new health to be used for dicitonary updating 


def banner(x):                                                              #Prints out a selected banner based on number parameter provided

    if x == 1:
        print("""                                                                                         
 _______  __   __  __   __  ______          __   __  _______  __    _  _______  __   __  ______    _______ 
|       ||  | |  ||  | |  ||      |        |  | |  ||       ||  |  | ||       ||  | |  ||    _ |  |       |
|       ||  |_|  ||  | |  ||  _    | ____  |  |_|  ||    ___||   |_| ||_     _||  | |  ||   | ||  |    ___|
|       ||       ||  |_|  || | |   ||____| |       ||   |___ |       |  |   |  |  |_|  ||   |_||_ |   |___ 
|      _||       ||       || |_|   |       |       ||    ___||  _    |  |   |  |       ||    __  ||    ___|
|     |_ |   _   ||       ||       |        |     | |   |___ | | |   |  |   |  |       ||   |  | ||   |___ 
|_______||__| |__||_______||______|          |___|  |_______||_|  |__|  |___|  |_______||___|  |_||_______|                                                                                                    
    """)

    elif x == 2:
        print("-"*50)
        print()
        print("""
 _______  _______  __   __  _______    _______  __   __  _______  ______   
|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |  
|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||  
|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ 
|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |
|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |
|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|
                                """)
        print()
        print("-"*50)

    elif x == 3:
        print("-"*50)
        print()
        print("""
__   __  _______  __   __    _     _  ___   __    _ 
|  | |  ||       ||  | |  |  | | _ | ||   | |  |  | |
|  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| |
|       ||  | |  ||  |_|  |  |       ||   | |       |
|_     _||  |_|  ||       |  |       ||   | |  _    |
  |   |  |       ||       |  |   _   ||   | | | |   |
  |___|  |_______||_______|  |__| |__||___| |_|  |__|
              """)
        print()
        print("-"*50)

def scene(hero, enemy):                                                     #A billion print statements to set up the story 
    enemy_name = enemy["Name"]                                              #Carries the enemy name over from the parameter's dictionary
    hero_name = hero                                                        #Carries hero name over from dictionary-converted-list in parameter

    slowPrint(f"Welcome to Reddit, {hero_name}!")

    print()         
    space_bar = input("[Press ENTER to continue]")
    print()                        

    slowPrint("As you were mindlessly scrolling on r/dankmemes")
    slowPrint("you get a notification")
    print()
    slowPrint("...", delay=0.09)
    print()
    slowPrint(f"{enemy_name} commented on one of your posts")

    print()
    space_bar = input("[Press ENTER to continue]")
    print()

    slowPrint("...", delay=0.09)
    print()
    slowPrint(f"{hero_name}: Oh! A new comment...")
    print()
    slowPrint("...", delay=0.09)
    print()
    slowPrint("You read the comment...")
    print()
    slowPrint(f"{enemy_name}: Ah yes, a classic cope from a chudcel like you. Enjoy youre downvote.") 

    print()
    space_bar = input("[Press ENTER to continue]")      
    print()

    slowPrint("...", delay=0.09)
    print()
    slowPrint("Anger rises in your lonely soul.")
    slowPrint("You begin typing a reply.")
    print()
    slowPrint(f"{hero_name}: I think you will find it's spelled 'your'")
    print()
    slowPrint("...", delay=0.09)
    print()
    slowPrint("And so your ChudVenture begins.")
    print()
    slowPrint("...", delay=0.09)

def stats(char):                                                            #General function to call all stats using dictionary values
    print()
    print(".........................")
    slowPrint(f"{char["Name"]}'s Account")
    print("-------------------------")
    print(f"Karma: {char["HP"]}")                                           #Begins listing the HP and AP based on values from the dictionary
    print(f"Clout: {char["AP"]}")
    print("-------------------------")
    print()



def enemyRandomizer():                                                      #Uses list to connect an item to a potential Key in quest()         
   enemy_choices = ["chud_dict", "destiny_dict", "hefty_dict", "elon_dict"]

   enemy = random.choice(enemy_choices)               

   return enemy                                                             #Returns list item name to use

def conversation(enemy):                                                    #A million If Statements to use for choice 2 in quest()
    num = random.randint(1,4)
    choice = random.choice(["kind", "mean"])                                  #50/50 chance to get a positive result or negative

    if num == 1:
        slowPrint(f"You try to be kind and reason with {enemy}.")
        slowPrint(f"...")
        if choice == "kind":
            print()
            slowPrint(f"{enemy} understands your point of view and apologizes!")
            slowPrint("Your Clout increased!")
            result = "CIncrease"                                            #Variable used to Increase player clout

        elif choice == "mean":
            print()
            slowPrint(f"{enemy} got angrier and doxxed you!")
            slowPrint("Your Karma decreased by half!")
            result = "doxxed"                                               #Variable used to Divide Karma by half

    elif num == 2:
        slowPrint(f"You attempt to bond with {enemy} by bringing up one of their interests!")
        slowPrint("...")
        if choice == "kind":
            print()
            slowPrint(f"{enemy} excitedly tells you about their interests!")
            slowPrint("Your Karma Increased!")
            print()
            result = "KIncrease"                                            #Variable used to Increase Player Karma

        elif choice == "mean":
            print()
            slowPrint(f"{enemy} gets embarrassed and attacks you!")
            slowPrint(f"The Reddit Hivemind finds this hilarious!")
            slowPrint("You lost Clout!")
            print()
            result = "CDecrease"                                            #Varible used to Decrease Player Clout

    elif num == 3:
        slowPrint(f"You try to change the subject...")
        slowPrint("...")
        if choice == "kind":
            print()
            slowPrint(f"{enemy} sees that you are uncomfortable.")
            slowPrint("They will be a bit nicer from now on!")
            slowPrint(f"{enemy} Lost Clout!")
            print()
            result = "ECDecrease"                                           #Variable used to decrease ENEMY clout

        elif choice == "mean":
            print()
            slowPrint(f"{enemy} chuckled behind their screen at your obvious discomfort")
            slowPrint("The Reddit Hivemind caught on to the power imbalance!")
            slowPrint("You lost Clout!")
            print()
            result = "CDecrease"                                            #Variable used to decrease player clout

    elif num ==4:
        slowPrint(f"You use facts and logic to support your argument!")
        slowPrint("...")
        if choice == "kind":
            print()
            slowPrint(f"{enemy} clicks all your links and understands your side more!")
            slowPrint("Uncommon Reddit W")
            slowPrint("You Gained Karma!")
            print()
            result = "KIncrease"                                            #Varible used to Increase Player Clout

        elif choice == "mean":
            print()
            slowPrint(f"{enemy} said he 'aint reading allat'")
            slowPrint("The Reddit Hivemind hates facts and logic!")
            slowPrint("You got Doxxed!")
            slowPrint("You lost half your Karma!")
            print()
            result = "doxxed"                                               #Variable used to divide player karma in half

    return result 

def quest():                                                                #Main gameplay function

    award_dict = {                                                          #Award dictionary for the chance to increase Karma and clout for enemy
    "Reddit Gold": 100, 
    "a Wholesome Award": 30, 
    "a Helpful Award": 20, 
    "a Hugz Award": 15, 
    "Reddit Silver": 50
    }      

    enemy_dict = {                                                          #Dictionary that holds the possible dictionaries for enemy stats
    "chud_dict" : {"Name": "u/ChudMaster69", "HP": 300, "AP" : 45},
    "destiny_dict" : {"Name": "u/Destiny2007", "HP": 450, "AP" : 45},      
    "hefty_dict" : {"Name": "u/Hefty_Alternative413", "HP": 250, "AP" : 60},
    "elon_dict" : {"Name": "u/ElonMuskOffical420", "HP": 350, "AP" : 55}
    }

    enemy = enemy_dict[enemyRandomizer()]                                   #Calls the enemy randomizer to select a key for the above dictionary

    print()
    slowPrint("What is your Screen Name?")                                  #Allows player to choose screen name
    user = input("... ")                                            

    print()

    hero_dict = {"Name" : "u/"+user, "HP" : 400, "AP" : 40}                 #Dictionary for Hero values. Added u/ for the name to give the Reddit vibes

    hero = hero_dict
    name = hero_dict["Name"]                                                #Takes value from the hero dictionary's key "name"
    enemy_name = enemy["Name"]

    scene(name, enemy)                                                      #Plays scene to kickoff the Chud Simulator 
    print()
    space_bar = input("[Press ENTER to continue]")
    print()
    slowPrint(f"You look at {enemy_name}'s account")
    stats(enemy)                                                            #Prints the enemy's stats (HP is Karma... Clout is AP)
    print() 
    space_bar = input("[Press ENTER to continue]")
    print()
    slowPrint("Luckily, your account is just as (un)impressive.")
    stats(hero)

    ######## GAMEPLAY LOOP########################
    turn = 0
    while True:                                                             #As long as either character stays above 0 Karma/Clout, the loop will continue        
        turn += 1
        print()
        space_bar = input("[Press ENTER to continue]")                      
        print()
        print("-"*30)
        print(f"TURN {turn}")
        print("-"*30)

        ################## HERO TURN #############
        while True:                                                         #Begins player choice loop that will continue unless one of 3 options is chosen
            print()
            slowPrint("What will you do?")
            print()
            print("[1. INSULT]  [2. ATTEMPT CONVERSATION]  [3. ACCEPT DEFEAT]")
            choice = int(input("Enter Number Here ... "))
            print()
            print("...")
            print()
            if choice == 1:                                                 #General attack option
                calcDamage(hero)
                enemy["HP"] = applyDamage(enemy, hero)                      #Takes dictionary value and uses applyDamage() to calculate new enemy HP
                slowPrint(f"You insulted {enemy_name}'s intellect!")
                slowPrint(f"The Reddit hivemind takes your side and downvotes {enemy_name}!")
                print()
                slowPrint(f"{enemy_name} now has {enemy["HP"]} Karma!")
                print()
                break
                

            elif choice == 2:                                               #Takes result from conversation() and depending on the result, dicitonary values will change
                rand_result = conversation(enemy_name)

                if rand_result == "doxxed":
                    hero_dict["HP"] = int(hero_dict["HP"]/2)                #Halves HP and rounds to nearest integer

                elif rand_result == "CIncrease":
                    hero_dict["AP"] = hero_dict["AP"]+20                    #Adds 20 attack points to player

                elif rand_result == "CDecrease":
                    hero_dict["AP"] = hero_dict["AP"]-5                     #Removes 20 attack points from player

                elif rand_result == "KIncrease":
                    hero_dict["HP"] = hero_dict["HP"]+30                    #adds 30 Karma to player
                
                elif rand_result == "ECDecrease":
                    enemy["AP"] = enemy["AP"]-10                            #Removes 10 attack points from enemy
                break

            elif choice == 3:                                               #This reduces the player's karma to 0 and ends the game
                slowPrint(f"You stopped replying to {enemy_name}")
                slowPrint("The other Redditors think you are a weak chud")
                slowPrint("You lost ALL your Karma!")                        
                hero_dict.update({"HP": 0})
                break
                                                        
            else:                                                           #loop repeats if valid option is not selected
                print("Please enter a valid option!")
            
        
        print()
        space_bar = input("[Press ENTER to continue]")
        print()

        stats(hero)
        print()                                                             #Prints updates stats for viewer enjoyment (or demise)
        stats(enemy)

        if enemy["HP"] <= 0 or enemy["AP"] <= 0:                            #If enemy loses all karma or clout, end screen plays and you win                      
            banner(3)
            print()
            slowPrint("You have logged out of your Reddit account!")
            break        

        print()
        space_bar = input("[Press ENTER to continue]")
        print()

        ################## ENEMY TURN ############
        while True:
            slowPrint(f"{enemy_name} replied to your comment!")             #Begins enemy loop turn  
            print()

            num = random.randint(1,4)
            award_name = random.choice(list(award_dict.keys()))             #Chooses random award name            
            award = award_dict[award_name]                                  #Takes value from award name

            if num == 1:                                                    #Updates enemy dictionary to add Karma and Clout based on award value
                slowPrint(f"{enemy_name}'s comment really touched the heart of the Reddit Hivemind!")
                slowPrint(f"A kind stranger gave {enemy_name} {award_name}")
                slowPrint(f"{enemy_name} has gained {award} Karma!")
                enemy["HP"] = enemy["HP"] + award

            elif num == 2 or num == 4:                                      #General attack based on dicitonary AP value
                slowPrint(f"{enemy_name} attacked one of your interests!")
                slowPrint("They called you an incel!")
                slowPrint("Your retorts are being downvoted!")
                slowPrint(f"You lost {enemy["AP"]} Karma!")
                hero_dict.update({"HP": applyDamage(hero, enemy)})
                print()
                

            elif num == 3:                                                  #Chance to lose up to 30 Karma
                self_damage = random.randint(1,3) * 10

                slowPrint(f"{enemy_name}'s comment was just a bit TOO controversial!")
                slowPrint(f"The Reddit Hivemind did NOT like that!")
                slowPrint(f"{enemy_name} LOST {self_damage} Karma! ")
                enemy["HP"] = enemy["HP"]-self_damage                       #Updates the enemy HP value to reflect the random loss of Karma

            print()
            space_bar = input("[Press ENTER to continue]")
            print()

            stats(hero)
            print()                                                         #Prints stats for player enjoyment
            stats(enemy)

            break

        if hero_dict["HP"] <= 0 or hero_dict["AP"] <= 0:                    #if hero karma or clout goes below zero, end screen plays and you lose
            banner(2)
            print()
            slowPrint("You have logged out of your Reddit account!")
            break


############ MAIN FUNCTION #######################

def main():                                                                 
    banner(1)
    while playing():
        quest()

############ INITIATES MAIN ######################

if __name__ == "__main__":
    main()