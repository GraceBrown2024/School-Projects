#Grace Brown
#Last Modified: 23 September 2025

import random

############# FUNCTIONS ##########################################################


def welcome():                                     #Prints welcome and sets up scene                  
    print("Welcome to Vought Tower!")
    print("As you and the rest of the Seven sit around the table, you see your CEO, Asheley, approach.")
    print("...")
    print("'Homelander... sir I am so sorry... There's-'")
    print("You cut her off.")
    print("...")
    print("'Ashley, what did I tell you about interrupting my meetings?'")
    print("'Yes sir, but sir... we have a problem...'")
    print("...")
    print("Ashley leads you to the control room.")
    print("On the wall of screens, you see your least favorite person...")
    print("Billy Butcher.") 
    print("Alone.")
    print("Standing right outside the underground entrance.")
    print("He has nothing with him except a smirk and an intent to kill.")
    print("...")
    print("...")
    print("Outwardly calm, internally fuming, you walk away from Ashley and enter the elevator to the bottom floor.")
    print("Seconds feel like hours. You aren't nervous, just annoyed. You are ready to kill this scum and go back to your meeting.")
    print("...")
    print("The elevator door opens. Butcher waits exactly twelve feet away.")
    print("You, Homelander, God of all Supes, sigh and prepare to end this quickly.")
    print("-----------------------")


def hero_Intro(hero, hero_hp, hero_ap):                 #Prints Homelanders Stats
    print(f"You are {hero}")
    print("...")
    print("STATS")
    print(f"Health: {hero_hp}")
    print(f"Attack Power: {hero_ap}")
    print("     ")
    print("-----------------------")
    print("    ")

def enemy_Intro(enemy_1, enemy_1_hp, enemy_1_ap):           #Prints Billy Butcher stats
    print(f"{enemy_1} stands before you.")
    print("...")
    print("STATS")
    print(f"Health: {enemy_1_hp}")
    print(f"Attack Power: {enemy_1_ap}")
    print("     ")
    print("-----------------------")


def calcDamage(ap):                                       # calculates damage done                   
    return ap - random.randint(1, 5)

# applies damage to health
def attack(health, damage):
    return health - damage


def printOutcome(attacker, defender, damage, health):               # Prints from 3 possible attack outcomes
    print("    ")
    number = random.randint(1,3)
    if number == 1:
        print(f"{attacker} strikes at {defender} for {damage} damage!")
        if damage >= 30:                                                    # If the attack is outside "normal" range, I considered it a crit hit
            print("CRITICAL HIT!")
        print(f"{defender} now has {health} health!")
        print("-----------------------")

    if number == 2:
        print(f"{attacker} punches {defender} for {damage} damage!")
        if damage >= 30:
            print("CRITICAL HIT!")
        print(f"{defender} now has {health} health!")
        print("-----------------------")

    if number == 3:
        print(f"{attacker} knocks over {defender} for {damage} damage!")
        if damage >= 30:
            print("CRITICAL HIT!")
        print(f"{defender} now has {health} health!")
        print("-----------------------")


def endScreen(hero, hero_hp, enemy_1, enemy_hp):                    # Prints endscreen for when either character dies
    if hero_hp <= 0:
        print("-----------------------")
        print(f"{enemy_1} has finally done it...")
        print(f"{hero} clutches his heart, godly yet still human, and falls.")
        print(f"{hero} is no more. {enemy_1} wins.")
        print("-----------------------")
        print("GAME OVER. YOU LOSE.")

    if enemy_hp <= 0:
        print("-----------------------")
        print(f"Just as he expected, {enemy_1} has died at the hands of {hero}.")
        print(f"{hero} wipes the blood from his costume and kicks {enemy_1}'s body.")
        print(f'"Eugh. Gross."')
        print("-----------------------")
        print("CONGRATULATIONS! YOU WIN!")
   
####### MAIN #############################################################
def main():
    # print welcome message
    welcome()
    print("       ")
    print("       ")
    
    # hero information
    hero = "Homelander"
    hero_hp = 100
    hero_ap = 30

    # enemy information
    enemy_1 = "Billy Butcher"
    enemy_1_hp = 100
    enemy_1_ap = 25


    hero_Intro(hero, hero_hp, hero_ap)                           # prints hero intro

    enemy_Intro(enemy_1, enemy_1_hp, enemy_1_ap)                 # prints enemy intro
    
    # set the number of turns for the battle
    turns = 5                                                    # I chose 5 turns so the battle WILL end with someone winning eventually

    # for loop to simulate the battle
    for i in range(turns):

        print("-----------------------")
        print(f"Turn {i+1}")
        print("...")
        
        ## hero attacks enemy
        if random.randint(1,5) == 2:                            # Chance of Critical Hit
            damage = calcDamage(hero_ap*random.randint(2,3))       # I gave him a lower chance of crit hit beacause every time I tested the code, he would disproportionately win and I wanted to see him lose.
        
        else:              
            damage = calcDamage(hero_ap)

        enemy_1_hp = attack(enemy_1_hp, damage)
        printOutcome(hero, enemy_1, damage, enemy_1_hp)

        if enemy_1_hp <= 0:                                     # Triggers end screen if Billy dies 
            endScreen(hero, hero_hp, enemy_1, enemy_1_hp)
            break                                               # ends loop         


        ## enemy attacks hero
        if random.randint(1,4) == 2:                            # Chance of Critical Hit
            damage = calcDamage(enemy_1_ap*random.randint(2,5))
    
        else:                                                   
            damage = calcDamage(enemy_1_ap)
        hero_hp = attack(hero_hp, damage)
        printOutcome(enemy_1, hero, damage, hero_hp)
        
        if hero_hp <= 0:                                        #Triggers end screen if Homelander dies
            endScreen(hero, hero_hp, enemy_1, enemy_1_hp)
            break                                               # ends loop

    print("-----------------------")
    



##################### initiate main
# initiate main this way, as was explained in class
if __name__ == "__main__":
    main()