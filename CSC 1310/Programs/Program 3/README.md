# Food Tracker 1310 
Developer: Grace Brown <br>
Purpose  : *Health tracking and management* ... Log what you eat in a day!<br>
---
## How to Compile and Run
1. Install and Update Makefile Package (per your OS)
2. Open Command Prompt / Terminal
3. Navigate to PROGRAM 3 Directory, then CODE Directory
4. In CODE directory, type "make" 
5. After successful compilation, type "make run"
**NOTE: This is a TERMINAL-BASED PROGRAM! No GUIs have been implemented!**
---
## Data Structures Used
### 2D Array <br>
Used to store user information based on profile. The information will be stored in the following format:
| Date | Current Weight | Calorie Limit  | Calorie Intake | Exceeded Limit |
| -----------| ----------- | ----------- | ----------- | ----------- |
| 112026 | 180 | 1500 | 1450 | 1 |
| 112126 | 1798 | 1500 | 1510 | 0 | 
<br>

**NOTE: The last column is stored as an integer, but will be converted to a boolean for display!** <br>
**NOTE: The weight will have to be converted to an int by x10 and then divided by 10.0 for display!**

### Hash Table <br>
Used to sort through the foods CVS file quickly with each Food item being assigned an ID. Once selected by the user, the name of the food will be matched with an ID and the information from that bucket will be given to the user's food tracking array to calculate their daily intake of macros and calories. The use of a bucket is quick as there is less iterating through each element and instead can jump straight to a key. 
---
## Source of CSV dataset

Gemini Prompt -> *Create me a CSV list of 1000 different foods with the datapoints of FoodID,FoodName,Calories,Fiber,Protein,Carb,Sugar,Fats,Category (category being something along the lines of "fruit" or "vegetable" or "grain") and FoodID starting at 1* <br>
---
## Known Issues
- Hash table not loaded correctly
- custom CSV not implemented
- password is currently redundant
- Userinfo is not permanently stored yet
- Calculations and Profiles not put into arrays completely
---

## TO DO

[x] Correct directories for MAKEFILE **IMPORTANT**
[] Complete userInfo Class functions **ALMOST COMPLETE**
[] Complete Hash table ordering
[] Allow user input custom foods
[] Dynamically Allocate 2D array for daily log
[] Link files and folders to specific users 
[x] Create parsing functions for CSV files
[] User verification for password and username
[x] FIX FORMATTING ON MENUS
[x] Create function in UserInfo to break apart username string and eliminate spaces
[x] Load Profiles onto vector from Users.txt

