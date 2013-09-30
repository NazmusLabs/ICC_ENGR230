/***********************************************************/
/* In the Name of Allah, Most Gracious, Most Merciful      */
/* Program Name: Armageddon                                */
/* Program by: Nazmus Shakib Khandaker                     */
/* Course: ENGR230                                         */
/* Instructor: Steve Portscheller                          */
/* Date: Sep 10, 2013                                      */
/* Purpose: Determine exit angle of refraction             */
/*    given the entrance angle, and indexes of refraction  */
/***********************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = acos(-1);

int main()
{
	int restart = 1; // The app will quit once the value of restart is 0, inputed by the user
	double entrance = 0.5, exit = 0.5, index1 = 0.5, index2 = 0.5;    //initializing values with 0.5 to prevent unintentional errors such as divide by zero or arcsin of a number greater than 1
	double entrance_deg = 0; // will record the degree value of entrance so a recalculation (and potential loss of precision) is not necessary
	bool IsProcessed = 0;  //this value will be 1 if all inputs are deemed such that there won't be mathematical errors, such as divide by zero or arcsin of a number greater than 1

	cout << "Starting up with the name of Allah, Most Gracious, Most Merciful\n";

	cout << "**************************";
	cout << "\nHW3 Snell's Law\nBy Nazmus Shakib Khandaker\n";
	cout << "**************************\n\n";

	cout << "Welcome!\n\nThis app will calculate the deflection of of light after passing from one material to another.\nThe calculations will be done based on Snell's Law.\n\n";
	cout << "We'll ask you for the the following:\n1) The angle at which light enters the second material from the first material (entrance angle)\n2) The index of refraction of the first material\n3)The index of refraction of the second material..\n\n";
	cout << "You can search the internet for the index of refraction of the materials you are using.\n\n";


	while (restart == 1)
	{
		cout << "Please enter the entrance angle in degrees \\>";
		cin >> entrance;
		entrance_deg = entrance; //See comment after the variable def.
		cout << "\n\nPlease enter the index of refraction for the first material \\>";
		cin >> index1;
		cout << "\n\nPlease enter the index of refraction for the second material  \\>";
		cin >> index2;
		cout << "\n\nThat's all we need. Thanks!\n\n";

		/* Let n1 = index1, n2 = index2, theta1 = entrance, and theta2 = exit
		then, n1 * sin(theta1) = n2 * sin(theta2)
		=> sin(theta2) = n1/n2 * sin(theta2)
		=> theta2 = exit = arcsin(n1/n2 * sin(theta2))

		We want to output the value of exit to the user. */

		cout << "Processing the values you have provided...\n";
		entrance = entrance * PI / 180;  //Converting degrees to radians
		if (index2 == 0)
		{
			cout << "done\n\nThere is no exit angle because all light is reflected, according to the value you have given us.\nThe light is unable to penetrate the interface and instead reflects as from a mirror: all light is reflected (at the same angle with which it approaches) and none is transmitted through the interface.\n\n";
		}
		else if (index1 / index2 * sin(entrance) > 1)
		{
			cout << "done\n\nThere is no exit angle because all light is reflected, according to the value you have given us.\nThe light is unable to penetrate the interface and instead reflects as from a mirror: all light is reflected (at the same angle with which it approaches) and none is transmitted through the interface\n\n.";
		}
		else
		{
			IsProcessed = 1;  //If this occures, we can continue with calculating the value of exit.
			cout << "done\n\n";
		}

		if (IsProcessed == 1)
		{
			cout << "Starting calculation...\n";
			exit = asin(index1 / index2 * sin(entrance));
			exit = exit * 180 / PI;  //Converting rad to deg

			cout << "done\n\n";
			cout << "Light entering the material interface from the first material to the second material with an entrance angle of " << entrance_deg << " degrees will exit with an angle of " << exit << " degrees.";
		}

		IsProcessed = 0; //reset IsProcessed value
		cout << "\n\nThanks for using this app! :) \n\nWould you like to start over?\nPlease type 1 for yes and 0 for no. \>";
		cin >> restart;
		cout << endl << endl;
	}

	return 0;
}