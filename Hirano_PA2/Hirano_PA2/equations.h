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


#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979323846
#include <math.h>
#include <stdio.h>

//Series Resistance
int calculate_series_resistance(int series1, int series2, int series3);
//Sales Tax
double calculate_total_sales_tax(double item_cost, double sales_tax_rate);
//Volume of a right rectangular pyramid
double calculate_volume_pyramid(double length, double width, double height);
//Parallel Resistance
double calculate_total_parallel(int parallel_r1, int parallel_r2, int parallel_r3);
//Character Encoding
char calculate_shift(char plaintext_char, int shift);
// Distance Between Two Points
double calculate_distance(double x_1, double x_2, double y_1, double y_2);
//General Equation Solver
double calculate_equation(double y, double z, double x, int a);





