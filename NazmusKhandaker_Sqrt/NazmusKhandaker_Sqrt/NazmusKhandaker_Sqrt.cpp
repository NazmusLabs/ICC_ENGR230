/***********************************************************/
/* In the Name of Allah, Most Gracious, Most Merciful      */
/* Program Name: The Square Root (Mid-Term Exam)           */
/* Program by: Nazmus Shakib Khandaker                     */
/* Course: ENGR230                                         */
/* Instructor: Steve Portscheller                          */
/* Date: Oct 8, 2013                                       */
/* Purpose: calculates the square root of any number       */
/*      using Newton's iterative method                    */
/***********************************************************/

#include <iostream>	//used for cin >> and cout <<
#include <cmath>
#include <iomanip>
#include <string>
#include <cctype>	//Used for toupper function
#include <cstdlib>	//used for system("pause");
using namespace std;

//Function Prototypes
void welcomeMessage(string appName, string appPurpose);		//Displays the welcome message to the user
void closingMessage(string appName, string message);		//Displays closing message after the app has fulfilled its purpose
void errorMessage(int errorCode);							//receives error codes and displays the appropriate message
bool askYesNO(string question);								//used for yes/no questions. Returns 1 for yes, and 0 for no.

int main()
{
	string appName = "The Square Root Calculator";
	string appPurpose = "This app calculates the square root of any number using Newton's iterative method. Let's get started!";
	welcomeMessage(appName, appPurpose);
	system("pause"); cout << endl;
	bool restart = 1; //This app will quit once the restart value is 0 or an error occures.

	double x = 2, n = 0, iteration = 0;  //Please see description of these variables below.

	//Explains Newton's iterative method to user if they ask for it.
	if (askYesNO("Before we start, do you want to learn more about Newton's iterative method?") == 1)
	{
		cout << "Newton's iterative method states this:\n\nx2 = x1 + 1/2 * (n/x1 - x1)\n";
		cout << "where n is the value for which we want to find the square root, x1 is our guess from the previous iteration, x2 is a more accurate guess.\n\n";
		cout << "We iterate this equation over and over until we achieve the accuracy we need. For the initial iteraton, x1 can be an arbitrary value.\n\n";
		system("pause");
	}

	while (restart == 1)
	{
		//input user value and store in n
		cout << "Please type a number for which you would like to find the squire root >"; cin >> n;
		cout << "Thanks!\nProcessing...";

		if (n < 0)
		{
			cout << "done!";
			errorMessage(1);
			return 1;
		}
		else cout << "done!\nCalculating...\n\n";

		cout << "Iteration #    Root" << endl;
		cout << setw(11) << 0 << "    " << setw(5) << setiosflags(ios::fixed) << setprecision(3) << 2.000 << endl;

		while (abs(sqrt(n) - x) > 0.0001 && iteration < 25)
		{
			x = (x + 0.5 * (n / x - x)); //find a more accurate guess and store in x2
			iteration = iteration + 1;  //We keep track of iteration because we are limiting maximum iteration to 25
			cout << setw(11) << iteration << "    " << setw(5) << setiosflags(ios::fixed) << setprecision(3) << x << endl;
		}

		restart = askYesNO("Would you like to find the square root of another number?");  //User has the choice to start over or quit
	}

	closingMessage(appName, "has completed the requested operation.");
	system("pause");
	return 0;
}


//Please refer to the function prototypes for descriptive comments for each of the following functions
void welcomeMessage(string appName, string appPurpose)
{
	cout << "In the name of Allah, Most Gracious, Most Merciful\n";
	cout << "**************************";
	cout << endl << appName << "\nBy Nazmus Shakib Khandaker\n";
	cout << "**************************\n\n";

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
		cout << "\n\nOops!\n\nNegative numbers are not allowed. This app will now quit.\n\n";
		cout << "Error code 001: Cannot take square root of negative number.\n";
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