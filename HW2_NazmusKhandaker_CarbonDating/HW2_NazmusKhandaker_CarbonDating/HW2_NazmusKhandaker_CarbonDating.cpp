/***********************************************************/
/* In the Name of Allah, Most Gracious, Most Merciful      */
/* Program Name: Carbon Dating                             */
/* Program by: Nazmus Shakib Khandaker                     */
/* Course: ENGR230                                         */
/* Instructor: Steve Portscheller                          */
/* Date: Sep 3, 2013                                       */
/* Purpose: Return age of organic object given their %     */
/*     carbon remaining (supplied by user)                 */
/***********************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{
	const double LAMBDA = 0.00012097;
	double input = 0; double inputProcessed = 0; double time = 0;

	cout << "In the Name of Allah, Most Gracious, Most Merciful\n\n";
	cout << "Hi, and welcome to the Carbon Dating App!\n\nWith this app, you can find the age of a sample by entering the amount of carbon 14 still remaining on the sample.\n\nLet's get started!\n\n";
	cout << "Please enter the precent of carbon 14 remaining on the sample (exclude the % symol) and then press \"Enter\"\n";
	cin >> input;
	cout << "\nStarting calculation...\n";

	/*The input will be processed and stored into inputProcessed according to the following calculation
	Carbon dating equation: Q = Qi * e^(-LAMBDA*t), Q == current carbon, Qi == initial carbon, t = time
	=> Q = Qi / e^(LAMBDA*t)
	=> e^(LAMBDA*t) = Qi/Q
	=> Qi/Q = 1/(input / 100) = inputProcessed */

	inputProcessed = 1 / (input / 100);

	time = log(inputProcessed) / LAMBDA; // t = ln(inputProcessed)/LAMBDA

	cout << "Calculation successful!\nFeeding result...\n\n";
	cout << "Your sample, which contains " << input << "% of the original Carbon 14 amount is " << time << " years old!\n";
	cout << "Thanks for using the Carbon Dating app!\n";

	system("pause");
	return 0;
}