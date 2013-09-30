/***********************************************************/
/* In the Name of Allah, Most Gracious, Most Merciful      */
/* Program Name: Armageddon                                */
/* Program by: Nazmus Shakib Khandaker                     */
/* Course: ENGR230                                         */
/* Instructor: Steve Portscheller                          */
/* Date: Sep 10, 2013                                      */
/* Purpose: Determine time it takes to reach final height  */
/*     given initial conditions and final height           */
/***********************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double G = 9.81;

int main()
{
	double h_i = 0, v_i = 0, h = 0, t = 0; // Please refer to comment block below to see what these variables are.
	int restart = 1; // The app will quit once the value of restart is 0, inputed by the user

	cout << "**************************";
	cout << "\nHW3 Armageddon\nBy Nazmus Shakib Khandaker\n";
	cout << "**************************\n\n";

	/* Hight of falling object as function of time is as follows:

	h = h_i - v_i * t - 1/2 * G * t^2
	=> 1/2 * G * t^2 + v_i * t + h - h_i = 0, where h = final height, h_i = initial height,
	v_i = initial velocity, G = gravitational constant, t = time

	We want to solve for t, which can be done using the quadratic formula:

	t = (-v_i + sqrt(v_i * v_i - 2 * G * (h - h_i))) / G    Equation has been selected so that time is positive.
	*/

	cout << "Welcome!\n\nThis app will calculate the time it takes for an object to free fall a certain distance.\n\n";
	cout << "We'll ask you for the inital height of the object, the final velocity of the object, and the final height of the object after it falls a certain distance.\n\n";

	while (restart == 1)
	{
		cout << "Let's get started! Make sure to press enter after you type a value.\n\n";
		cout << "What is the object's initial height (in meters)? >";
		cin >> h_i;
		cout << "\nWhat is the inital velocity of the object (in meters/seconds)? >";
		cin >> v_i;
		cout << "\nWhat is the final height of the object (in meters)? >";
		cin >> h;
		cout << "\n\nOkay, thanks! We're calculating the time.\n\n";

		t = (-v_i + sqrt(v_i * v_i - 2 * G * (h - h_i))) / G;

		cout << "Okay, we're done!\nAn object starting at a height of " << h_i << " meters and a velocity of " << v_i << " m/s will reach a height of " << h << " meters in " << t << " seconds";
		cout << "\n\nThanks for using this app!\nWould you like to try another value?\nPlease type 1 for yes and 0 for no. >";
		cin >> restart;

	}

	return 0;
}