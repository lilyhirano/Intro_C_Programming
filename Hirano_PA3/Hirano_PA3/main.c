/*-------------------------------------------------------------------------------------------------
Name: Lily Hirano
Class: CPT_S 121
Section: 03

Description: This program calculates the GPA mean, class standing mean, age mean, GPA standard
			 deviation, GPA minimum, and GPA maximum, given input data of five records on input.dat.
			 The results are printed onto output.dat.
Relevant Formulas:
					standard deviation = sqrt((sum(x-mean)^2)/population size)
----------------------------------------------------------------------------------------------------*/


#include "header.h"


int main(void)
{
	FILE* input_stream = NULL, * output_stream = NULL;
	int class_standing1 = 0, class_standing2 = 0, class_standing3 = 0, class_standing4 = 0, class_standing5 = 0;
	double gpa_1 = 0.0, gpa_2 = 0.0, gpa_3 = 0.0, gpa_4 = 0.0, gpa_5 = 0.0, age_1 = 0.0, age_2 = 0.0, age_3 = 0.0, 
		age_4 = 0.0, age_5 = 0.0, gpa_sum = 0.0, gpa_mean = 0.0, standing_mean = 0.0, standing_sum = 0.0, age_sum = 0.0,
		age_mean = 0.0, deviation1 = 0.0, deviation2 = 0.0, deviation3 = 0.0, deviation4 = 0.0, deviation5 = 0.0,
		variance_gpa = 0.0, stdev_gpa = 0.0, minimum_gpa = 0.0, maximum_gpa = 0.0;

	input_stream = fopen("input.dat", "r");

	read_integer(input_stream);
	gpa_1 = read_double(input_stream); 
	class_standing1 = read_integer(input_stream);		//Gathers data for record 1
	age_1 = read_double(input_stream);
	
	read_integer(input_stream);
	gpa_2 = read_double(input_stream);
	class_standing2 = read_integer(input_stream);		//Gathers data for record 2
	age_2 = read_double(input_stream);

	read_integer(input_stream);
	gpa_3 = read_double(input_stream);
	class_standing3 = read_integer(input_stream);		//Gathers data for record 3
	age_3 = read_double(input_stream);

	read_integer(input_stream);
	gpa_4 = read_double(input_stream);
	class_standing4 = read_integer(input_stream);		//Gathers data for record 4
	age_4 = read_double(input_stream);

	read_integer(input_stream);
	gpa_5 = read_double(input_stream);
	class_standing5 = read_integer(input_stream);		//Gathers data for record 5
	age_5 = read_double(input_stream);

	fclose(input_stream);
	output_stream = fopen("output.dat", "w");

	
	gpa_sum = calculate_sum(gpa_1, gpa_2, gpa_3, gpa_4, gpa_5);
	gpa_mean = calculate_mean(gpa_sum, 5);							//Calculates mean GPA and prints to output.
	print_double(output_stream, gpa_mean);


	standing_sum = calculate_sum(class_standing1, class_standing2, class_standing3, 
		class_standing4, class_standing5);									//Calculates mean standing and prints to 
	standing_mean = calculate_mean(standing_sum, 5);						// output.
	print_double(output_stream, standing_mean);

	age_sum = calculate_sum(age_1, age_2, age_3, age_4, age_5);
	age_mean = calculate_mean(age_sum, 5);						//Calculates mean age and prints to output.
	print_double(output_stream, age_mean);


	deviation1 = calculate_deviation(gpa_1, gpa_mean);
	deviation2 = calculate_deviation(gpa_2, gpa_mean);			//Finds the deviation of each gpa, variance, standard
	deviation3 = calculate_deviation(gpa_3, gpa_mean);			// deviation, then prints result on ouput.dat
	deviation4 = calculate_deviation(gpa_4, gpa_mean);
	deviation5 = calculate_deviation(gpa_5, gpa_mean);
	variance_gpa = calculcate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, 5);
	stdev_gpa = calculate_standard_deviation(variance_gpa);
	print_double(output_stream, stdev_gpa);
	
	minimum_gpa = find_minimum(gpa_1, gpa_2, gpa_3, gpa_4, gpa_5);		//Finds minimum GPA and prints result to 
	print_double(output_stream, minimum_gpa);							//output file.

	maximum_gpa = find_maximum(gpa_1, gpa_2, gpa_3, gpa_4, gpa_5);		//Finds maximum GPA and prints result to 
	print_double(output_stream, maximum_gpa);							// output file.

	fclose(output_stream);

	return 0;
}