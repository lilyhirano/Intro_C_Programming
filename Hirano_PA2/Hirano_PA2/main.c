/*-------------------------------------------------------------------------------------------------
Name: Lily Hirano
Class: CPT_S 121
Section: 03

Description:    This program calculates total series resistance, sales tax,
				the volume of a right rectangular pyramid, total parallel resistance,
				character encoding, the distance between two points, and the answer to a general
				equation.
Relavant Formulas:
					Series Resistance = R1 + R2 + R3
					Sales Tax = sales tax rate * item cost
					Volume of a Right Pyramid = (L * W * H)/ 3
					Parallel Resistance = 1/ ((1/R1) + (1/R2) + (1/R3))
					Encoded character = (character - a) + A - shift value
					Distance Between Two Points = sqrt((x1-x2_^2)+(y1-y2)^2)
					General Equation = y = y / (3/17) - z + x / (a%2) + PI
----------------------------------------------------------------------------------------------------*/

#include "equations.h"

int main(void)
{
	int series_1 = 0, series_2 = 0, series_3 = 0, total_series = 0, parallel_1 = 0, parallel_2 = 0, parallel_3 = 0,
		shift = 0, a = 0;
	double tax = 0.0, total_sales_tax = 0.0, item_cost = 0.0, height = 0.0, length = 0.0, width = 0.0, 
		volume_pyramid = 0.0, total_parallel_r = 0.0, x_1 = 0.0, x_2 = 0.0, y_1 = 0.0, y_2 = 0.0, distance = 0.0,
		x = 0.0, y = 0.0, z = 0.0;
	char plaintext_char = '\0', encoded_char = '\n';


	//Total Series Resistance
	printf("Input three in series resistance integer values: ");
	scanf("%d%d%d", &series_1, &series_2, &series_3);                         //Gets resistance values from user.

	total_series = calculate_series_resistance(series_1, series_2, series_3); //Calculates total series resistance and
	printf("The in series resistance is: %d + %d + %d = %d\n", series_1, series_2, series_3, total_series); //prints value.

	//Sales Tax
	printf("Input sales tax rate: ");
	scanf("%lf", &tax);

	printf("Input item cost : ");									//Gets sales tax and item cost from user.
	scanf("%lf", &item_cost);

	total_sales_tax = calculate_total_sales_tax(item_cost, tax); //Calculates the sales tax, and prints it.
	printf("The sales tax is : %.2lf * %.2lf = %.3lf \n", item_cost, tax, total_sales_tax);

	//Right Rectangular Pyramid Volume 
	printf("Input length: ");
	scanf("%lf", &length);

	printf("Input width: ");			
	scanf("%lf", &width);											//Gets length, width, and height

	printf("Input height: ");				
	scanf("%lf", &height);

	volume_pyramid = calculate_volume_pyramid(length, width, height);  //Calculates volume and prints value
	printf("The volume is: (%lf * %lf * %lf) / 3 = %.3lf\n", length, width, height, volume_pyramid);

	//Parallel Resistcane
	printf("Input three parallel integer resistance values in the order of R1, R2, and R3: "); //Gets resistor values
	scanf("%d%d%d", &parallel_1, &parallel_2, &parallel_3);										//from user

	total_parallel_r = calculate_total_parallel(parallel_1, parallel_2, parallel_3); 
	printf("The total parallel resistance is: %.3lf\n", total_parallel_r); //Calculates parallel resistance and 
																			//prints value
	//Character Encoding
	printf("Enter one character from the keyboard: ");
	scanf(" %c", &plaintext_char);

	printf("Enter one integer shift value: ");      //Gets character and shift value from user and assigns to variable.
	scanf("%d", &shift);

	encoded_char = calculate_shift(plaintext_char, shift); //Calculates encoded character and prints result
	printf("The encoded character is: (%c - a) + A - %d = %c\n", plaintext_char, shift, encoded_char);

	// Distance Between Two Points
	printf("Input a value for x1: ");
	scanf("%lf", &x_1);
	printf("Input a value for y1 ");
	scanf("%lf", &y_1);
														//Gets (x1,y1) and (x2, y2) from user
	printf("Input a value for x2: ");
	scanf("%lf", &x_2);						
	printf("Input a value for y2 ");
	scanf("%lf", &y_2);

	distance = calculate_distance(x_1, x_2, y_1, y_2); //Calcualates distance and prints value
	printf("The distance between the two points is: sqrt( (%lf - %lf)^2 + (%lf - %lf)^2 ) = %.3lf \n", x_1, x_2, y_1, 
		y_2, distance);

	//General Equation Solver
	printf("Input a value for x: ");
	scanf("%lf", &x);

	printf("Input a value for z: ");					// Gets x, z, y, and a from user.
	scanf("%lf", &z);

	printf("Input a value for y: ");
	scanf("%lf", &y);

	printf("Input an integer value for a: ");
	scanf("%d", &a);

	y = calculate_equation(y, z, x, a);
	printf("The answer to the general equation is: %.3lf", y);	// Solves for y and prints the result.

	return 0;
}

