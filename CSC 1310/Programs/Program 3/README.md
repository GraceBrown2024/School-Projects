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
| 112126 | 179.8 | 1500 | 1510 | 0 | 
<br>

**NOTE: The last column is stored as an integer, but will be converted to a boolean for display!**

### Hash Table <br>
---
## Source of CSV dataset

Gemini Prompt -> *Create me a CSV list of 1000 different foods with the datapoints of FoodID,FoodName,Calories,Fiber,Protein,Carb,Sugar,Fats,Category (category being something along the lines of "fruit" or "vegetable" or "grain") and FoodID starting at 1* <br>
---
## Known Issues
>WORK IN PROGRESS
---

## TO DO
- Correct directories for MAKEFILE **IMPORTANT**
- Complete userInfo Class functions
- Dynamically Allocate 2D array for profiles
- Link files and folders to specific users 
- Create parsing functions for CSV files
- User verification for password and username
- FIX FORMATTING ON MENUS

