/* Name: Lily Hirano
   Class: Cpt_S 121   Section: 3
   Date: 1/19/2024

   Description: This program calculates total series resistance, sales tax,
				the volume of a right rectangular pyramid, total parallel resistance,
				character encoding, the distance between two points, and the answer to a general
				equation.*/

#define _CRT_SECURE_NO_WARNINGS 
#define PI 3.14159265358979323846       //Constant macro for pi.
#include <math.h>
#include <stdio.h>

int main(void)
{
	int series_r1 = 0, series_r2 = 0, series_r3 = 0, parallel_r1 = 0, parallel_r2 = 0,
		parallel_r3 = 0, shift = 0, a = 0;
	double sales_tax_rate = 0.0, item_cost = 0.0, length = 0.0, width = 0.0, height = 0.0,
		x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, x = 0, z = 0, y = 0.0, parallel_resistance = 0.0,
		diff_x=0.0, diff_y = 0.0;
	char plaintext_char = '\n';

	// Total Series Resistance
	printf("Input three in series resistance integer values: ");
	scanf("%d%d%d", &series_r1, &series_r2, &series_r3); //Gets resistance values from user.

	printf("The total series resistance is: R1 + R2 + R3 = %d + %d + %d = %d", series_r1, series_r2, 
		series_r3, series_r1 + series_r2 + series_r3); //Calculates in series resistance and prints value.

	printf("\n");

	// Sales Tax
	printf("Input sales tax rate: ");
	scanf("%lf", &sales_tax_rate);
	printf("Input item cost : ");  //Gets sales tax and item cost from user.
	scanf("%lf", &item_cost);

	printf("The sales tax is: %.2lf * %.2lf = %.2lf", sales_tax_rate, item_cost, sales_tax_rate * item_cost);
	                  //Calculates and prints sales tax.
	printf("\n");

	// Volume of a right rectangular pyramid
	printf("Input length, width, and height: ");
	scanf("%lf%lf%lf", &length, &width, &height);    //Gets user input.
	printf("The volume is: (%lf * %lf * %lf) / 3 = %lf", length, width, height, (length * width * height) / 3); //Calculates volume and prints result.

	printf("\n");

	// Total parallel resistance
	printf("Input three parallel integer resistance values in the order of R1, R2, and R3: "); //Gets resistor values from user.
	scanf("%d%d%d", &parallel_r1, &parallel_r2, &parallel_r3);

	parallel_resistance = 1 / ((1 / (double)parallel_r1) + (1 / (double)parallel_r2) + 
		(1 / (double)parallel_r3));          
	printf("The total parallel resistance is: 1 / ((1/%d) + (1/%d) + (1/%d)) = %lf", 
		parallel_r1, parallel_r2, parallel_r3, parallel_resistance);  //Calculates parallel resistance
																		// and prints result.
	printf("\n");

	// Character Encoding
	printf("Enter one character from the keyboard: ");
	scanf(" %c", &plaintext_char);

	printf("Enter one integer shift value: ");    //Gets character and shift value from user and assigns to variable.
	scanf("%d", &shift);

	printf("The encoded character is: (%c - a) + A - %d = %c", plaintext_char, shift, (plaintext_char - 'a') + 'A' - shift);
	printf("\n");  //Prints character result using equation.

	// Distance Between Two Points
	printf("Input the x and y value of coordinate 1: ");
	scanf("%lf%lf", &x1, &y1);
	                                                         // Gets the coordinates fromt the user and
	printf("Input the x and y value of coordinate 2: ");        // assigns to variable.
	scanf("%lf%lf", &x2, &y2);

	diff_x = x1 - x2;
	diff_y = y1 - y2;
	printf("The distance between the two points is: sqrt( (%lf - %lf)^2 + (%lf - %lf)^2 ) = %lf", x1, x2, y1, y2, 
		sqrt( pow((diff_x),2) + pow((diff_y),2)));				//Calculates the distance and prints result.
	printf("\n");

	// General equation solver
	printf("Input a value for x: ");
	scanf("%lf", &x);
	
	printf("Input a value for z: ");     // Gets x, z, y, and a from user.
	scanf("%lf", &z);

	printf("Input a value for y: ");
	scanf("%lf", &y);

	printf("Input an integer value for a: ");
	scanf("%d", &a);

	y = y / ((double)3 / (double)17) - z + x / (a % 2) + PI;
	printf("The answer to the general equation is: %lf", y); // Calculates for y and prints the result.


	return 0;
}
