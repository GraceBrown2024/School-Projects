/*
	Title: CSVHelper.h
	Author: April R. Crockett
	Date: 10/25/2026
	Purpose: This header file contains helper functions that you will use
	to aid in parsing through a csv file
*/
#ifndef CSVHELPER_H
#define CSVHELPER_H

#include <string>
#include <vector>
using namespace std;
/*
	Function: parseCSVLine()
	Purpose: Splits one CSV row into fields.
			 Commas inside quotation marks are part of the field.
			 Two quotation marks in a quoted field represent one quotation mark.
			 Returns false if the quotation marks are not properly closed.
			 Returns true otherwise.
			 fields vector is passed by reference so that vector is filled within this function.
*/
bool parseCSVLine(string line, vector<string>& fields) {
	string current = "";
	bool inQuotes = false;
	char ch;
	
	//remove everything from vector to clear it out
    fields.clear();
    
	//start parsing line one character at a time.
    for (int i = 0; i < (int)line.length(); i++) {
        ch = line[i];

		//if the current character is a dobule quote
        if (ch == '"') {
            if (inQuotes && i + 1 < (int)line.length() && line[i + 1] == '"') {
                current += '"'; //add the double quotes to the current string
                i++;
            } 
			else
                inQuotes = !inQuotes;
        } 
		//if the current character is a single quote
		else if (ch == ',' && !inQuotes) {
            fields.push_back(current); //add current field to vector
            current = ""; //clear out the current string to get ready for next part of line
        } 
		else //add this character tothe current string.
            current += ch;
    }

    if (inQuotes) 
		return false;

    // Remove carriage return when reading a Windows CSV on some systems.
    if (!current.empty() && current[current.length() - 1] == '\r') {
        current.erase(current.length() - 1);
    }

    fields.push_back(current);
    return true;
}

/*
	Function: readNonnegativeNumber()
	Purpose: Converts a string of digits to a nonnegative long long.
			 Returns false if the text is empty, contains nondigits, or is too large.
			 Returns true otherwise
			 nonnegative long long is passed by reference to capture value
*/
bool readNonnegativeNumber(string text, long long& number) 
{
    //variable definitions
	long long result = 0;
    long long maximum = 9223372036854775807LL; // Largest value for a signed 64-bit long long.
	int digit;
	
	//if text is empty, return false
	if (text.empty()) 
		return false;

    for (int i = 0; i < (int)text.length(); i++) {
		//if the character is not a digit, return false
        if (text[i] < '0' || text[i] > '9') 
			return false;

		//if the character would overflow maximum allowed amount after multiplication, return false
        digit = text[i] - '0';
        if (result > (maximum - digit) / 10) 
			return false;
		
		//convert to non-negative long long
        result = result * 10 + digit;
    }

    number = result;
    return true;
}

#endif
