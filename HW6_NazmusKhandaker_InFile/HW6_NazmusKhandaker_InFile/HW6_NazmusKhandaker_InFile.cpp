/***********************************************************/
/* In the Name of Allah, Most Gracious, Most Merciful      */
/* Program Name: InFile                                    */
/* Program by: Nazmus Shakib Khandaker                     */
/* Course: ENGR230                                         */
/* Instructor: Steve Portscheller                          */
/* Date: Oct 1, 2013                                       */
/* Purpose: Analalyze a function from an input file        */
/*      and output results in an output file               */
/***********************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

//Function Prototypes
void welcomeMessage(string appName, string appPurpose);
void closingMessage(string appName);
void errorMessage(int errorCode);

int main()
{
	string appName = "InFile";
	string appPurpose = "This app will read data describing a function, y, of x.\n This data is located in the file \"HW6Input.txt\", which should be in the same directory in which this app is located. Let's get started!";
	welcomeMessage(appName, appPurpose);
	system("pause"); cout << endl << endl;

	double x = 0, y = 0, xMax = 0, xMin = 0, yMax = 0, yMin = 0, x_at_yMax = 0, x_at_yMin = 0;

	//Define new instance of oFile stream; open output file.
	ifstream inFile("HW6Input.txt");  //inFile is an arbitrary name, which is given to the new instance of ifstream.
	//Test if file successfully opened
	if (!inFile)
	{
		errorMessage(1);
		inFile.close();
		return 1;
	}
	cout << "Input file successfully opened.\n";
	//Define new instance of oFile stream; open output file.
	ofstream outFile("HW6Output.txt"); //outFile is an arbitrary name, which is given to the new instance of ofstream.
	//Test if file successfully opened.
	if (!outFile)
	{
		errorMessage(3);
		inFile.close(); outFile.close();
		return 1;
	}
	else outFile << "x-value     y-value\n"; //output header
	cout << "Output file successfully created.\n";

	if (inFile.good()) //File is accessable
	{
		cout << "\nWorking, please wait...\n[";
		while (inFile) //loop untile end of file or until file becomes inaccessable
		{
			inFile >> x >> y;

			//Check and / or update max and min
			if (x > xMax)
				xMax = x;
			if (y > yMax)
			{
				yMax = y; x_at_yMax = x;
			}
			if (x < xMin)
				xMin = x;
			if (y < yMin)
			{
				yMin = y; x_at_yMin = x;
			}

			//Reproduce input values on output file.

			if (outFile.good())
			{
				outFile << setw(7) << setiosflags(ios::fixed) << setprecision(2) << x << "    ";
				outFile << setw(8) << setiosflags(ios::fixed) << setprecision(5) << y << endl;
				cout << "0"; //Progress bar
			}
			else
			{
				errorMessage(4);
				inFile.clear(); outFile.clear();
				return 1;
			}
		}
	}
	if (inFile.bad()) //File has become inaccessable
	{
		errorMessage(2);
		inFile.close(); outFile.close();
		return 1;
	}
	if (inFile.eof()) //End of file(eof) reached
	{
		cout << "] 100%\n\n";
		inFile.close();
	}

	outFile << endl << "The function was evaluated from " << xMin << " to " << xMax << ".";
	outFile << endl << "The function has a minimum value of " << yMin << " when x is " << x_at_yMin << ".";
	outFile << endl << "The function has a maximum value of " << yMax << " when x is " << x_at_yMax << ".";

	closingMessage(appName);
	outFile.close();
	system("pause");
	return 0;
}

void welcomeMessage(string appName, string appPurpose)
{
	cout << "In the name of Allah, Most Gracious, Most Merciful\n";
	cout << "**************************";
	cout << endl << appName << "\nBy Nazmus Shakib Khandaker\n";
	cout << "**************************\n\n";

	cout << "Welcome to " << appName << "! " << appPurpose << "\n\n";
	return;
}

void closingMessage(string appName)
{
	cout << appName << " has successfully completed!\nWe placed the results in the output file called \"HW6Output.txt\", which is located in the smae directory as this app. Double-click on the file to see the results\n";
	cout << "Thank you for using " << appName << endl;
	return;
}

void errorMessage(int errorCode)
{
	if (errorCode == 1)
	{
		cout << "\n\nOops!\n\nA file needed to properly run this app is missing or corrupted. This app will now quit.\n\n";
		cout << "Error code 001: \"HW6Input.txt\" cannot be found.\n";
		system("pause");
	}
	else if (errorCode == 2)
	{
		cout << "\n\nOops!\n\nA file needed to properly run this app is no longer available or has become corrupted. This app will now quit.\n\n";
		cout << "Error code 002: \"HW6Input.txt\" no longer accessable\n";
		system("pause");
	}
	else if (errorCode == 3)
	{
		cout << "\n\nOops!\n\nA file needed to properly run this app is missing or corrupted. This app will now quit.\n\n";
		cout << "Error code 003: failed to open \"HW6Output.txt\".\n";
		system("pause");
	}
	else if (errorCode == 4)
	{
		cout << "\n\nOops!\n\nA file needed to properly run this app o longer available or has become corrupted. This app will now quit.\n\n";
		cout << "Error code 004: \"HW6Output.txt\" no longer accessable.\n";
		system("pause");
	}
	return;
}

