# lab1 - student
# Grace Brown
# Last Modified 9/15/2025

# Variables for the hero
hero_name = "Pim"
hero_hp = 100
hero_attack = 30

# Variables for the enemy
enemy_name = "Forest Demon"
enemy_hp = 90
enemy_attack = 25

# intro print statements
print("Welcome to Smiling Friends HQ!")
print("------------------------")

# Hero's intro and stats
print("Our hero is", hero_name)
print("-----------------------")
print("STATS")
print("Health:", hero_hp)
print("Attack:", hero_attack)
print("-----------------------")
print("-----------------------")

#Theme setup
print("As" , hero_name, "walks through the forest to collect sticks, a terrifying", enemy_name, "appears!")
print("-----------------------")

# Forest demon Stats
print(enemy_name , "STATS")
print("Health:", enemy_hp)
print("Attack:", enemy_attack)
print("-----------------------")
print("-----------------------")

# calculating damage output
damage = 30

#ATTACKING
enemy_hp = enemy_hp - damage

# Results of Pim Attack
print(hero_name, "kisses the", enemy_name, "for", damage, "damage!")
print(enemy_name, "now has", enemy_hp , "health")
print("-----------------------")

################### CONCEPT: Rolling chance for enemy attack
#  I've only done this once in my freetime so forgive me if its disgusting
import random

chance_attack = random.randint(1, 4) # Forest demon MIGHT hit or he MIGHT hurt himself

if chance_attack == 1:
    hero_hp = hero_hp - 0 #Forest Demon hurts itself
    print(enemy_name, "lunged at", hero_name, "but tripped over a stick and fell!")
    enemy_hp = enemy_hp - 2
    print(hero_name, "is at full health!")
    print(enemy_name , "is at" , enemy_hp , "health.") 

if chance_attack == 2: #Base attack
    hero_hp = hero_hp - enemy_attack
    print(enemy_name, "grabs", hero_name, "and bites his little arm.")
    print(hero_name, "now has", hero_hp, "health.")

if chance_attack == 3: #CHANCE of pim being KOed
    hero_hp = hero_hp - enemy_attack*random.randint(2,4)
    print(enemy_name, "screamed really loud and startled", hero_name)
    print(enemy_name, "'s power is boosted!")
    print(hero_name, "now has" , hero_hp , "health.")

if chance_attack == 4:
    hero_hp = hero_hp - enemy_attack*4 #KOs Pim and triggers end game screen
    print(enemy_name, "straight up ate", hero_name, "and it was so horrid.")
    print(hero_name,  "now has", hero_hp , "health.")

print("-----------------------")

if hero_hp == 0: #If Pim dies 
    print(hero_name, "is dead.")
    print("GAME OVER")

print("-----------------------")