/***********************************************************/
/* In the Name of Allah, Most Gracious, Most Merciful      */
/* Program Name: Bullet-Proof                              */
/* Program by: Nazmus Shakib Khandaker                     */
/* Course: ENGR230                                         */
/* Instructor: Steve Portscheller                          */
/* Date: Sep 24, 2013                                      */
/* Purpose: Evaluate y(x) = ln(1/(1-x))                    */
/*      where value of x is inputed by user                */
/***********************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double x; //This is the input value & independent function variable
	double y; //Output val & dependent function variable
	int restart = 1; // The app will quit once the value of restart is 1, inputed by the user

	//Startup Message
	cout << "Starting up with the name of Allah, Most Gracious, Most Merciful\n";
	cout << "**************************";
	cout << "\nHW5 Bulletproof\nBy Nazmus Shakib Khandaker\n";
	cout << "**************************\n\n";


	cout << "Hey! This is a simple calculator app that calulates the following function:\n\n";
	cout << "y(x) = ln(1/(1-x),\n\nWhere y(x) is a function of x, and x is an independent variable.\n\n";
	cout << "We'll need you to give us a value for x, and we will give you back the value of the function y(x).\n\n";

	while (restart == 1)
	{
		//Take the input value of x
		cout << "Please type in a value for x >";
		cin >> x;

		//Process imput
		cout << "\nThanks!\n\nProcessing the value you gave us...\n";

		//Check for divide by zero
		if (1 - x == 0)
		{
			cout << "Done!\n\nOops! Divide by zero error: the value you have provided causes a division by zero.";
		}
		//Check for domain error
		else if (1 / (1 - x) <= 0)
		{
			cout << "Done!\n\nOops! Domain error: the value you have provided is outside the domain of the function.";
		}
		//If no errors found, we porceed with the calculation!
		else
		{
			cout << "Done!\n\nStarting Calculation...\n";
			y = log(1 / (1 - x));
			cout << "Done!\n\ny(" << x << ") = " << y << endl;
		}

		cout << "\n\nThanks for using this app! :) \n\nWould you like to try another value?\nPlease type 1 for yes and 0 for no. >";
		cin >> restart;
		cout << endl << endl;
	}

	return 0;
}