#Last modifier: GRACE BROWN
#Last date modified: 3 OCTOBER 2025

import random

def characterSelection():                      #Prints welcome screen
    print("+","-"*8,"+")

    print("Welcome to VOUGHT!")

    print("+","-"*8,"+")

    print("Choose your character:")     #Allows you to choose your character
    print("1. Homelander")
    print("2. The DEEP")
    print("3. Black Noir")
    print(" ")

def attack(health, damage):                       #Calculates initial attack points
    return health - damage
    

def calcDamage(ap):                   #Calculates damage 
    return ap

        
def heroIntro(ap, hp, character):                    #Prints hero intro
    print("+","-"*8,"+")
    print(f"{character} STATS")
    print("ATTACK:", ap)
    print("HEALTH:", hp)



def enemyIntro(enemy_hp, enemy_ap, enemy):                   #Prints enemy intro
    print(" ")
    print("+","-"*8,"+")
    print(f"{enemy} stands in your way!")
    print("+","-"*8,"+")
    print(f"{enemy} STATS:")
    print(f"ATTACK: {enemy_ap}")
    print(f"HEALTH: {enemy_hp}")
    print(" ")


def printOutcome(attacker, defender, damage, health):                 #Prints final decision, damage, and attack
    num = random.randint(1,3)

    if num == 1:
        if health <= 0:
            pass
        else:
            print("   ")
            print("+","-"*8,"+")
            print(f"{defender} was punched in the nose by {attacker}!")
            print(f"{defender} suffered {damage} hits.")
            print(f"{defender} now has {health} health!")
    if num == 2:
        if health <= 0:
            pass
        else:
            print("   ")
            print("+","-"*8,"+")
            print(f"{attacker} hid behind a suspiciously human-shaped object and and surprised {defender}.")
            print(f"{defender} was stunned and hit for {damage} points!")
            print(f"{defender} now has {health} health.")
    if num == 3:
        if health <= 0:
            pass
        else:
            print("   ")
            print("+","-"*8,"+")
            print(f"{defender} blew a kiss at {attacker} which enraged him!")
            print(f"{attacker} started biting and clawing at {defender} like a rabid animal.")
            print(f"{defender} now has {health} health!")        

def endScreen(character, enemy, char_hp, enemy_hp):                    #Prints one of three end screens IF HP <= 0
    num = random.randint(1,3)

    if char_hp <= 0:
        if num == 1:
            print(f"{character} has been slain by {enemy}! Oh the horror!")

        elif num == 2:
            print(f"{enemy} lunged at you and pierced through your skull with his crowbar! {character} has been defeated!")
        elif num == 3:
            print(f"{character} tried to dodge {enemy}'s attack, but tripped over his own ankle. {character} died at the hands of {enemy} at last!")
        print("-------------------------") 
        print("GAME OVER!!!")
        print("-------------------------") 
    
    if enemy_hp <= 0:
        if num == 1:
            print(" ")
            print(f"{enemy} has been punched through the heart by {character}! {enemy} has finally fallen.")
        elif num == 2:
            print(" ")
            print(f"{character} jumped into the air and body-slammed {enemy}! {enemy} is nothing but a pile of bones and gore.")
        elif num == 3:
            print(" ")
            print(f"{enemy} swung his crowbar at {character} and missed! He fell over and impaled himself... somehow... {enemy} is no more!")
        print("-------------------------") 
        print("YOU WIN!!!")
        print("-------------------------") 
        
################### MAIN #############################
def main():                            
    char_hp = 100
    char_ap = 15

    enemy_hp = 90
    enemy_ap = 15
    enemy = "Billy Butcher"

    characterSelection()
    char_choice = input("...")      #Allows character selection ... I attempted to cast as an integer but would continously get an error message on the *first* run
                                    
    char_one = "Homelander"          #Character variables
    char_two = "The DEEP"
    char_three = "Black Noir"

    if char_choice == "1":
        character = char_one
        print(" ")
        print(f"You are {char_one}!")
        print(" ")

    elif char_choice == "2":
        print(" ")
        character = char_two
        print(f"You are {char_two}!!!!")
        print(" ")

    elif char_choice == "3":
        print(" ")
        character = char_three
        print(f"You are {char_three}!")
        print(" ")
    else:
        print("Please select a valid option!")
    
    heroIntro(char_ap, char_hp, character)              #Introduces your chosen character

    enemyIntro(enemy_hp, enemy_ap, enemy)               #Introduces Billy Butcher   

 ##### END OF INTRO STATEMENTS ##################################################################

    turns = 50                                          #Beginning of loop
    for i in range(turns):                               
        print("-------------------------")     
        print(f"Turn {i+1}") 
        print("...")   

        print(" ")
        print(f"{character}'s TURN!")
        print("What would you like to do?")
        print("1. Attack")
        print("2. Rummage")
        print("-------------------------") 
        
        choice = input("...")
                                    
        if choice == "1":                                                 #HERO ATTACKS
           damage = calcDamage(char_ap)
           enemy_hp = attack(enemy_hp, damage)
           printOutcome(character, enemy, damage, enemy_hp)             

        elif choice == "2":                                               #HOW TO APPLY ATTACK BONUS???
            rummage = random.choice(["heal", "attack_bonus", "nothing"])
            
            if rummage == "heal":
                heal_amount = random.randint(20,50)
                char_hp = heal_amount + char_hp 
                print(f"{character} found a bandaid and somehow healed himself...")
                print(f"{character} now has {char_hp} health!")
            elif rummage == "attack_bonus":
                bonus = random.randint(20, 30)
                char_ap = bonus + char_ap
                print(f"{character} found injected some compound V into his veins!")
                print(f"Attack rose to {char_ap} points!")
            else:
                print(f"{character} looked around and found nothing!")

        else:
            print("Please select a valid option!")
        
        if enemy_hp <= 0:
            endScreen(character, enemy, char_hp, enemy_hp)
            break

        print("-------------------------") 
        print(" ")                                                      #ENEMY ATTACKS

        print(f"{enemy}'s TURN!")
        damage = calcDamage(enemy_ap)
        char_hp = attack(char_hp, damage)

        if char_hp <= 0:
            endScreen(character, enemy, char_hp, enemy_hp)
            break
        printOutcome(enemy, character, enemy_hp, char_hp)

                                             
# initiates main
if __name__ == "__main__":
    main()
