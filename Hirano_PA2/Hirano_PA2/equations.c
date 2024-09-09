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

/*-----------------------------------------------------------
* Function: calculate_series_resistance()                                      
* Date Created:                                    
* Date Last Modified: 2/2/24   
* Description: This function calculates the in series resistance 
				given three integer resistance values.
* Input parameters: The three in series resistance integer 
					values.                                    
* Returns: The total series resistance.                                     
* Preconditions: The three integer series resistance values
				 have been acquired. 
* Postconditions: The total in series resistance.   
-------------------------------------------------------------*/
int calculate_series_resistance(int series_1, int series_2, int series_3) 
{																		  
	int total_series = 0;
															//Calculates the total in series resistance 
	total_series = series_1 + series_2 + series_3;

	return total_series;
}

/*-----------------------------------------------------------
* Function: calculate_total_sales_tax()
* Date Created:
* Date Last Modified: 2/2/24
* Description: This function calculates the sales tax given the
*				item cost and sales tax rate.
* Input parameters: Item cost and sales tax rate.
* Returns: The sales tax for an item.
* Preconditions: The sales tax and item cost have been given
*				 by the user.
* Postconditions: The sales tax for an item is returned.
-------------------------------------------------------------*/
double calculate_total_sales_tax(double item_cost, double sales_tax_rate)
{
	double sales_tax = 0.0;

	sales_tax = item_cost * sales_tax_rate;					//Calculates sales tax
	return sales_tax;
}

/*-----------------------------------------------------------
* Function: calculate_volume_pyramid()
* Date Created:
* Date Last Modified: 2/2/24
* Description: This function calculates the volume of a right 
*				rectangular pyramid.
* Input parameters: Length, width, and height of the pyramid.
* Returns: The volume for the pyramid.
* Preconditions: The length, width, and height have been 
*				 given by the user.
* Postconditions: The volume for the right rectangular pyramid
*				  has been calculated.
-------------------------------------------------------------*/
double calculate_volume_pyramid(double length, double width, double height)
{
	double volume = 0.0;

	volume = (length * width * height) / 3;
												           //Calculates volume
	return volume;
}

/*-----------------------------------------------------------
* Function: calculate_total_parallel()
* Date Created:
* Date Last Modified: 2/2/24
* Description: This function calculates the parallel resistance
*				of three parallel resistors.
* Input parameters: Three parallel resistor values.
* Returns: Total parallel resistance.
* Preconditions: The resistor values have been given
*				 by the user.
* Postconditions: The total parallel resistance for an item is 
				  calculated.
-------------------------------------------------------------*/
double calculate_total_parallel(int parallel_r1, int parallel_r2, int parallel_r3)
{
	double total_parallel_r = 0.0;
											              //Calculates total parallel resistance
	total_parallel_r = 1 / ((1 / (double)parallel_r1) + (1 / (double)parallel_r2) + 
		(1 / (double)parallel_r3));

	return total_parallel_r;
}

/*-----------------------------------------------------------
* Function: calculate_shift()
* Date Created:
* Date Last Modified: 2/4/24
* Description: This function calculates the shift of a character
*				given a character and a integer shift value.
* Input parameters: Character from keyboard and integer shift
*					value.
* Returns: Encoded character after shift.
* Preconditions: The sales tax and item cost have been given
*				 by the user.
* Postconditions: The encoded is returned.
-------------------------------------------------------------*/
char calculate_shift(char plaintext_char, int shift)
{
	char encoded_char = '\0';

	encoded_char = (plaintext_char - 'a') + 'A' - shift;	//Finds encoded character
	
	return encoded_char;
}

/*-----------------------------------------------------------
* Function: calculate_distance()
* Date Created:
* Date Last Modified:2/2/24
* Description: This function calculates the distance between 
*			    two points given the x and y values of two 
*				coordinates.
* Input parameters: (x1,y1) and (x2,y2).
* Returns: The distance between the two points.
* Preconditions: (x1,y1) and (x2,y2) have been given by the
				 user.
* Postconditions: The distance between the points has been 
*				  calculated.
-------------------------------------------------------------*/
double calculate_distance(double x_1, double x_2, double y_1, double y_2)
{
	double diff_x = 0.0, diff_y = 0.0, distance = 0.0;

	diff_x = x_1 - x_2;
	diff_y = y_1 - y_2;											//Calculates distance between (x1,y1) and (x2,y2)
	distance = sqrt(pow((diff_x), 2) + pow((diff_y), 2));
	

	return distance;
}

/*-----------------------------------------------------------
* Function: calculate_equation()
* Date Created:
* Date Last Modified:2/2/24
* Description: This function calculates the solution to the 
				equation: y = y / (3/17) - z + x / (a%2) + PI
* Input parameters: A value for y, z, and x has been given and
*					an integer value for a has been given.
* Returns: The value for y
* Preconditions: Values for y, z, x, and a have been given.
* Postconditions: The value for y has been calculated.
-------------------------------------------------------------*/
double calculate_equation(double y, double z, double x, int a)
{
	y = y / ((double)3 / (double)17) - z + x / (a % 2) + PI;     //Calculates for y using general equation

	return y;
}