/***********************************************************/
/* In the Name of Allah, Most Gracious, Most Merciful      */
/* Program Name: NazmusLabs ENGR230 Core Software          */
/* Program by: Nazmus Shakib Khandaker                     */
/* Course: ENGR230                                         */
/* Instructor: Steve Portscheller                          */
/* Date: Oct 8, 2013                                       */
/* Purpose: provides foundation and general featureset     */
/*          for all ENGR 230 applications                  */
/***********************************************************/

#include <iostream>	//used for cin >> and cout <<
#include <cmath>	//provides extra math functions like square roots and power
#include <iomanip>
#include <fstream>	//used for minipulating files
#include <string>	//enables the use of string variable type
#include <cctype>	//used for toupper function
#include <cstdlib>	//used for system("pause");
using namespace std;

//Function Prototypes
void welcomeMessage(string appName, string appPurpose);		//Displays the welcome message to the user
void closingMessage(string appName, string message);		//Displays closing message after the app has fulfilled its purpose
void errorMessage(int errorCode);							//receives error codes and displays the appropriate message
bool askYesNO(string question);								//used for yes/no questions. Returns 1 for yes, and 0 for no.

int main()
{
	//startup sequence
	string appName = "NazmusLabs ENGR230 Core Software";
	string appPurpose = "The core software provides foundations for all of ENGR230 applications. The core features available to those applications depend on the version of the core software used.";
	welcomeMessage(appName, appPurpose);
	system("pause"); cout << endl;
	bool restart = 1; //This app will quit once the restart value is 0 or an error occures.
	//end of startup sequence

	//Other housekeeping stuff goes here
	cout << "Application performs any pre-operation as required at this point\n\n";

	//If the user chooses to restart the app, the app will restart from this point.
	while (restart == 1)
	{
		//insert primary operational code here
		cout << "Application performs primary operation at this point\n\n";

		restart = askYesNO("Would you like to restart?"); //you may want to change the message to be more specefic.
	}

	closingMessage(appName, "has completed the requested operation.");  //you may want to change the message to be more specefic.
	system("pause");
	return 0;
}


//Please refer to the function prototypes for descriptive comments for each of the following functions
void welcomeMessage(string appName, string appPurpose)
{
	cout << "In the name of Allah, Most Gracious, Most Merciful\n";
	cout << "********************************";
	cout << endl << appName << "\nBy Nazmus Shakib Khandaker";
	cout << endl << "Core software version: 7.1.8\n";
	cout << "********************************\n\n";

	cout << "Welcome to " << appName << "! " << appPurpose << "\n\n";
	return;
}

void closingMessage(string appName, string message)
{
	cout << endl << endl << appName << " " << message << endl << endl;
	cout << "Thank you for using " << appName << "!" << endl;
	return;
}

void errorMessage(int errorCode)
{
	if (errorCode == 1)
	{
		cout << "\n\nOops!\n\nInsert user-friendly error message. This app will now quit.\n\n";
		cout << "Error code 001: insert technical information\n";
		system("pause");
	}
	else if (errorCode == 2)
	{
		cout << "\n\nOops!\n\nInsert user-friendly error message. This app will now quit.\n\n";
		cout << "Error code 002: insert technical information\n";
		system("pause");
	}
	else if (errorCode == 3)
	{
		cout << "\n\nOops!\n\nInsert user-friendly error message. This app will now quit.\n\n";
		cout << "Error code 003: insert technical information\n";
		system("pause");
	}
	else if (errorCode == 4)
	{
		cout << "\n\nOops!\n\nInsert user-friendly error message. This app will now quit.\n\n";
		cout << "Error code 004: insert technical information\n";
		system("pause");
	}
	return;
}

bool askYesNO(string question)
{
	bool output;  //if input is yes, output is 1. If input is no, output is 0.
	char input;
	bool invalidInput = 1; //becomes one if user types anything other than yes or no.

	cout << question << " Please type yes or no (you can also type y or n) >";

	while (invalidInput == 1)
	{
		cin >> input; cout << endl << endl;
		if (toupper(input) == 'Y')
		{
			output = 1;
			invalidInput = 0;
		}
		else if (toupper(input) == 'N')
		{
			output = 0;
			invalidInput = 0;
		}
		else
		{
			invalidInput = 1;
			cout << "Oopse!\n\nWe couldn't understand your response. Please type yes or no. >";
		}
	}

	return output;  //MUST be either a 0 or 1
}