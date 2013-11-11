/************************************************************/
/* In the Name of Allah, Most Gracious, Most Merciful		*/
/* Program Name: NazmusLabs ENGR230 Core Software			*/
/* Program by: Nazmus Shakib Khandaker						*/
/* Course: ENGR230											*/
/* Instructor: Steve Portscheller							*/
/* Date: Oct 8, 2013										*/
/* Purpose: provides foundation and general featureset		*/
/*          for all ENGR 230 applications					*/
/************************************************************/

#include <iostream>	//used for cin >> and cout <<
#include <cmath>	//provides extra math functions like square roots and power
#include <iomanip>
#include <fstream>	//used for minipulating files
#include <string>	//enables the use of string variable type
#include <cctype>	//used for toupper function
using namespace std;

//Global constants
const double SPRING_CONST = 1.25*pow(10, 9), COEFFICIENT = 1.40*pow(10, 7), DEPT = 8 * 0.0254, MASS = 4000 * 453.5924;

//NazmusLabs Software Core Function Prototypes
void welcomeMessage(string appName, string appPurpose);		//Displays the welcome message to the user
void closingMessage(string appName, string message);		//Displays closing message after the app has fulfilled its purpose
void errorMessage(int errorCode);							//receives error codes and displays the appropriate message
bool askYesNO(string question);								//used for yes/no questions. Returns 1 for yes, and 0 for no.
void aboutApp();											//Gives a detailed description of what the program does.
void pauseApp();											//Pauses the app and wait for a keystoke.
void ignore_line(std::istream& in);							//Clears unwanted input stream;

//Application Specefic Function Prototypes
bool bisect(double& left, double& right);					//Evaulates the boundaries and closes the gap between them if root is found between them. Returns 1 if no root found.
double fcn(double t);										//This function evaluates the equation using the value of t (which is passed to it)
void getBounds(double& left, double& right);				//This function gets the values of left and right bounds from the user.


int main()
{
	//startup sequence
	string appName = "Bisect";
	string appPurpose = "This app will use the bisection method to find the root of the given equation.";
	welcomeMessage(appName, appPurpose);
	bool restart = 1; //This app will quit once the restart value is 0 or an error occures.
	//end of startup sequence

	double left = 0;		//lower bound of our guess
	double right = 0;		//upper bound of our guess
	bool IsNoRoot = 0;		//will become 0 if roots are found

	//Gives first-time users an option to learn about what this program does.
	if (askYesNO("Before we start, do you want to learn more about what this program does?"))
	{
		aboutApp();		//The aboutApp function describes the program in detail.
	}

	cout << "This app will find the root of the following function:\n\n";
	cout << "x = exp(-n*t) * (x0 * cos(s*t) + x0 * (n/s) * sin(s*t))";
	cout << "\n\nwhere:\nt = dependent variable\nx = independent variable\nx0 = " << DEPT << "\nn = c/2m\ns = sqrt(k/m - c^2/(4m^2))\nm = " << MASS << "\nk = " << SPRING_CONST << "\nc = " << COEFFICIENT << endl << endl;
	cout << "We will now ask you to give us the values for the upper and lower boundary for t; we will use those to guess the root." << endl << endl;

	//Should the user choose to restart the app, the app will restart from this point.
	while (restart == 1)
	{
		getBounds(left, right);

		int iteration = 1;	//iteration of the following while loop.

		//Define new instance of oFile stream; open output file.
		ofstream outFile("HW7Output.txt"); //outFile is an arbitrary name, which is given to the new instance of ofstream.
		//Test if file successfully created and opened.
		if (!outFile)
		{
			errorMessage(105);
			outFile.close();
			return 1;
		}
		else
		{
			outFile << "This file stores data from the latest run of the Bisect app.\n\n";
			outFile << "iter     time (left)     time (right)     position(left)     position(right)\n"; //output file header
		}

		while (abs(left - right) > 0.000001)	//The loop stops after certain accuracy or if there is no root.
		{
			//int outputError = 0;	//Will become one if Output file becomes inaccessable

			IsNoRoot = bisect(left, right);		//Adjects the boundaries if there is a root and returns 0.
			if (IsNoRoot == 1)
			{
				cout << "There are no roots found.\n\n";
				break;
			}

			if (iteration > 100)			//This is designed to prevent a potential infinite loop.
			{
				cout << "Error: More than one roots found!";
			}

			if (outFile.good())				//Will output the iteration and the values for t and the function at each boundary for that iteration to the ouput file
			{
				outFile << setw(4) << setiosflags(ios::fixed) << iteration << "     ";
				outFile << setw(11) << setiosflags(ios::fixed) << setprecision(6) << left << "     ";
				outFile << setw(12) << setiosflags(ios::fixed) << setprecision(6) << right << "     ";
				outFile << setw(14) << setiosflags(ios::fixed) << setprecision(6) << fcn(left) << "     ";
				outFile << setw(15) << setiosflags(ios::fixed) << setprecision(6) << fcn(right) << endl;
			}
			else							//Fallback if the output file becomes inaccessable
			{
				errorMessage(106);
				outFile.close();
				return 1;
			}

			iteration = iteration + 1;
		}

		if (IsNoRoot == 0)						//Outputs value of fuctions, x, if root exists.
		{
			cout << "The root of the function occures when t = " << fcn(right) << "." << endl << endl;
			cout << "We have placed an ouput file on the directory where this app is located. The file contains detailed information about the values of t and the function at each iteration.\n\n";
		}

		outFile.close();
		restart = askYesNO("Would you like to restart? If you restart, the ouput file's existing data will be overwritten with new data."); //you may want to change the message to be more specefic.
	}

	closingMessage(appName, "has completed the requested operation.");  //you may want to change the message to be more specefic.
	cout << endl << endl; pauseApp();
	return 0;
}


//Please refer to the function prototypes for descriptive comments for each of the following functions.

//Application Specefic Functions

void getBounds(double& left, double& right)
{
	int invalidInput = 1;		//Will become 0 when right > left and abs(right - right) < 0.1

	cout << "NOTE: The difference between the upper and lower bound must be no more than 0.1.\n";

	while (invalidInput == 1)
	{
		cout << endl << "Please enter in the value of the left bound. >"; cin >> left; cout << endl;
		cout << "Please type in the value of the right bound. >"; cin >> right; cout << endl << endl;

		if (abs(right - left) < 0.000001)
		{
			cout << "The upper and lower bounds must not be equal! Please try again.\n\n";
			invalidInput = 1;
		}
		else if (right < left)
		{
			cout << "The lower bound must be smaller than the upper bound! Please try again.\n\n";
			invalidInput = 1;
		}
		else if (abs(right - left) > 0.1)
		{
			cout << "The difference between the upper and lower boundaries is too large! It must not be greater than 0.1. Please try again\n\n";
			invalidInput = 1;
		}
		else invalidInput = 0;
	}
	return;
}

double fcn(double t)
{
	double x, c = COEFFICIENT, m = MASS, k = SPRING_CONST, x0 = DEPT;
	double n = c / (2 * m), s = sqrt(k / m - pow(c, 2) / (4 * pow(m, 2)));

	x = exp(-n * t) * (x0 * cos(s * t) + x0 * n / s * sin(s * t));
	return x;
}

bool bisect(double& left, double& right)
{
	if (fcn(left)*fcn(right) > 0) return 1;
	double mid = (left + right) / 2;
	if (fcn(left)*fcn(mid) < 0) right = mid;
	else left = mid;
	return 0;
}

//NazmusLabs Software Core Functions
void welcomeMessage(string appName, string appPurpose)
{
	cout << "In the name of Allah, Most Gracious, Most Merciful\n";
	cout << "********************************";
	cout << endl << appName << "\nBy Nazmus Shakib Khandaker";
	cout << endl << "Core software version: 8.0.9\n";
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
	cout << "This ap uses the bisection method. It is a method for finding the root of a function. ";
	cout << "The root of a function is the value of the independent variable for which the dependent variable is zero.\n\n";
	cout << "The bisection method uses iterative guessing to find an accurate value of the function root. ";
	cout << "We start by picking an upper and lower boundaries for the value of the dependent variable for which the root exists. ";
	cout << "We then evaulate the values of each boundaries. If the value of the function at one boundary has the opposite sign as the on at the other boundary, there is a root. ";
	cout << "If there is a root between the boundaries, we reduce the gap between the boundaries and evaulate the difference between the values of the functiaon at each boundary. ";
	cout << "We keep reducing the gap and evaluating until this difference is small enough to consider our guess accurate. At that point, we will output our guess on the screen.\n\n";

	cout << "For more information on the bisection method, along with graphs that help explain it, please search for \"bisection method\" in Wikipedia.\n\n";

	pauseApp(); cout << "\n\n\n";
	return;
}

void pauseApp()
{
	cout << "Press Enter to continue . . .";
	cin.get();
}

void ignore_line(std::istream& in)
{
	char ch;

	while (in.get(ch) && ch != '\n')
		;

	return;
}
