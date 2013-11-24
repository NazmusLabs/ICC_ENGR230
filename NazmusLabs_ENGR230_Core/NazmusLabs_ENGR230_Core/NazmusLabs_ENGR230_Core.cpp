/************************************************************/
/* In the Name of Allah, Most Gracious, Most Merciful		*/
/* Program Name: NazmusLabs ENGR230 Core Software			*/
/* Program by: Nazmus Shakib Khandaker						*/
/* Course: ENGR230											*/
/* Instructor: Steve Portscheller							*/
/* Date: Nov 23, 2013										*/
/* Purpose: provides foundation and general featureset		*/
/*          for all ENGR 230 applications					*/
/************************************************************/

#include <iostream>	//used for cin >> and cout <<
#include <cmath>	//provides extra math functions like square roots and power
#include <iomanip>
#include <fstream>	//used for minipulating files
#include <string>	//enables the use of string variable type
#include <limits>	//enables numeric_limit for std::cin.ignore( std::numeric_limits< std::streamsize >::max(), '\n'); More Info: http://uk.answers.yahoo.com/question/index?qid=20110314060202AAVLQLI
#include <cctype>	//used for toupper function
using namespace std;

//Global Constants
const double PI = acos(-1);

//NazmusLabs Software Core Function Prototypes
void welcomeMessage(string appName, string appCodeName, string appVersion, string appPurpose);		//Displays the welcome message to the user
void closingMessage(string appName, string message);		//Displays closing message after the app has fulfilled its purpose
void errorMessage(int errorCode);							//receives error codes and displays the appropriate message
bool askYesNO(string question);								//used for yes/no questions. Returns 1 for yes, and 0 for no.
void aboutApp();											//Gives a detailed description of what the program does.
void pauseApp();											//Pauses the app and wait for a keystoke.
void ignore_line(std::istream& in);							//Clears input stream upon call; Useful when input stream has unwanted values.

//Application Specefic Function Prototypes

int main()
{
	//startup sequence
	string appName = "NazmusLabs ENGR230 Core Software";
	string appPurpose = "The core software provides foundations for all of ENGR230 applications. The core features available to those applications depend on the version of the core software used.";
	string appCodeName = "CORE";
	string appVersion = "8.1.10";
	string outputFileName = appCodeName + "Output.txt";	//File name for the output file this program generates
	welcomeMessage(appName, appCodeName, appVersion, appPurpose);
	cout << endl;
	bool restart = 1; //This app will quit once the restart value is 0 or an error occures.
	//Gives first-time users an option to learn more about what this program does.
	if (askYesNO("Before we start, do you want to learn more about what this app does?"))
	{
		aboutApp();		//The aboutApp function describes the program in detail.
	}
	//end of startup sequence

	//Other housekeeping stuff goes here
	cout << "Application performs any pre-operation as required at this point\n\n";

	//Should the user choose to restart the app, the app will restart from this point.
	while (restart == 1)
	{
		int iteration = 0;		//counter for loops

		//insert primary operational code here
		cout << "Application begins primary operation at this point\n\n";

		//Define new instance of oFile stream; open output file.
		ofstream outFile(outputFileName); //outFile is an arbitrary name, which is given to the new instance of ofstream.
		//Test if file successfully created and opened.
		if (!outFile)
		{
			errorMessage(105);
			outFile.close();
			return 1;
		}
		else
		{
			outFile << "This file stores data from the latest run of " << appName << ".\n\n";
			outFile << "iter     value 1     value 2     value 3     value 4\n"; //output file header
		}
		while (iteration < 10)	//The loop runs for 10 iterations by default
		{
			//The following file opeartion will output values to the output file created earlier. By default, it ouputs iteration, and PI four times, under their corresponding output file header created earlier.

			if (outFile.good())				//Will output the iteration and the values for t and the function at each boundary for that iteration to the ouput file
			{
				outFile << setw(4) << setiosflags(ios::fixed) << iteration << "     ";
				outFile << setw(7) << setiosflags(ios::fixed) << setprecision(5) << PI << "     ";		//setw(#): if the number of characters in a value outputted < #, then appropriate number of WS (white space) is added in front of the value to total #. Search online for more info on setw() function
				outFile << setw(7) << setiosflags(ios::fixed) << setprecision(5) << PI << "     ";		//setprecision() and setiosflags() sets accuracy of all following values to the output stream. Search online for more on these
				outFile << setw(7) << setiosflags(ios::fixed) << setprecision(5) << PI << "     ";
				outFile << setw(7) << setiosflags(ios::fixed) << setprecision(5) << PI << endl;
			}
			else							//Fallback if the output file becomes inaccessable
			{
				errorMessage(106);
				outFile.close();
				return 1;
			}

			iteration = iteration + 1;
		}

		cout << "\n\nA file named " << outputFileName << " has been placed on the folder in which this app is located. It contains output data from the latest run.\n\n";

		restart = askYesNO("Would you like to restart? If you choose yes, data from the output file will be replaced with new data."); //you may want to change the message to be more specefic.
	}

	closingMessage(appName, "has completed the requested operation.");  //you may want to change the message to be more specefic.
	pauseApp();
	return 0;
}


//Please refer to the function prototypes for descriptive comments for each of the following functions

//NazmusLabs Software Core Functions
void welcomeMessage(string appName, string appCodeName, string appVersion, string appPurpose)
{
	cout << "In the name of Allah, Most Gracious, Most Merciful\n";
	cout << "***************************************";
	cout << endl << appCodeName << " " << appName << "\nBy Nazmus Shakib Khandaker";
	cout << endl << "Core software version: " << appVersion << "\n";
	cout << "***************************************\n\n";

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
	cout << "\n\nOops!\n\n";
	//This is a sample message;
	if (errorCode == 0)
	{
		cout << "Insert user-friendly error message. This app will now quit.\n\n";
		cout << "Error code 000: insert technical information\n";
		pauseApp();
	}
	//error code sequence starts at the arbitrary value of 102
	else if (errorCode == 102)
	{
		cout << "Error code 102: We couldn't understand your response. Please type y or n. >";
	}
	else if (errorCode == 103)
	{
		cout << "A file needed to properly run this app is missing or corrupted. This app will now quit.\n\n";
		cout << "Error code 003: Input file \"<inputFileName>.txt\" no longer accessable\n";
		pauseApp();
	}
	else if (errorCode == 104)
	{
		cout << "A file needed to properly run this app is no longer available or has become corrupted. This app will now quit.";
		cout << "Error code 004: Input file \"<inputFileName>\" no longer accessable\n";
		pauseApp();
	}
	else if (errorCode == 105)
	{
		cout << "We are unable to save a file in the directory where this app is located. The directory may be read only. This app will now quit.\n\n";
		cout << "Error code 000: failed to create output file \"<outputFileName>.txt\".\n";
		pauseApp();
	}
	else if (errorCode == 106)
	{
		cout << "A file needed to properly run this app o longer available or has become corrupted. This app will now quit.\n\n";
		cout << "Error code 000: output file \"<outputFileName>.txt\" no longer accessable.\n";
		pauseApp();
	}
	else if (errorCode == 107)
	{
		cout << "Insert user-friendly error message. This app will now quit.\n\n";
		cout << "Error code 000: insert technical information\n";
		pauseApp();
	}
	else
	{
		cout << "Something went wrong! This app will now quit.\n\n";
		cout << "Error code 101: unspecified error\n";
		pauseApp();
	}
	return;
}

bool askYesNO(string question)
{
	bool output;  //if input is yes, output is 1. If input is no, output is 0.
	char input;
	bool invalidInput = 1; //becomes one if user types anything other than yes or no.

	cout << question << " Please type y or n. >";

	while (invalidInput == 1)
	{
		cin >> input; cout << endl << endl;
		if (toupper(input) == 'Y')
		{
			output = 1;
			invalidInput = 0;
			ignore_line(cin);
		}
		else if (toupper(input) == 'N')
		{
			output = 0;
			invalidInput = 0;
			ignore_line(cin);
		}
		else
		{
			invalidInput = 1;
			errorMessage(102);
			ignore_line(cin);
		}
	}

	return output;  //MUST be either a 0 or 1
}

void aboutApp()
{
	cout << "\n\nInsert app description here.\n\n";

	pauseApp(); cout << "\n\n\n";
	return;
}

void pauseApp()
{
	cout << "Press Enter to continue . . .";
	std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');		//clears input stream if user types anythign else before pressing enter.

}

void ignore_line(std::istream& in)
{
	char ch;

	while (in.get(ch) && ch != '\n')
		;

	return;
}
