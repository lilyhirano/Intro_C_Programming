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


/*-----------------------------------------------------------
* Function: read_double()
* Date Created: 2/5/2024
* Date Last Modified: 2/5/2024
* Description: Reads an open file and assigns a the first double
			   to a variable.
* Input parameters: Open file stream.
* Returns: One floating point value from the file
* Preconditions: The file must be open and in reading status.
* Postconditions: The floating point value from the file has
				  been retrieved.
-------------------------------------------------------------*/
double read_double(FILE *infile)
{
	double fp_variable = 0.0;

	fscanf(infile, "%lf", &fp_variable);
	return fp_variable;
}

/*-----------------------------------------------------------
* Function: read_integer()
* Date Created: 2/5/2024
* Date Last Modified: 2/5/2024
* Description: Reads an open file and assigns a the first 
			   intger to a variable.
* Input parameters: Open file stream with an integer present.
* Returns: One integer from the file.
* Preconditions:The file must be open and in reading status.
* Postconditions: The integer value from the file has
				  been retrieved.
-------------------------------------------------------------*/
int read_integer(FILE *infile)
{
	int int_variable = 0.0;

	fscanf(infile, "%d", &int_variable);
	return int_variable;
}

/*-----------------------------------------------------------
* Function: calculate_sum()
* Date Created: 2/6/2024
* Date Last Modified: 2/6/2024
* Description: Calculates the sum of 5 double values 
* Input parameters: 5 values of double data tpye.
* Returns: The sum of the 5 values
* Preconditions: All values are doubles.
* Postconditions: The sum of the 5 values has been calculated.
-------------------------------------------------------------*/
double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
	double sum = 0.0;

	sum = number1 + number2 + number3 + number4 + number5;

	return sum;
}

/*-----------------------------------------------------------
* Function: calculate_mean()
* Date Created: 2/6/2024
* Date Last Modified: 2/6/2024
* Description: Calculates the mean given the number of values 
			   and a sum.
* Input parameters: One double value sum and an integer value 
					of the number of inputs summed. Returns -1.0
					if a negative ineger is input.
* Returns: The mean.
* Preconditions: The number integer is not negative.
* Postconditions: The mean using the sum has been calculated.
-------------------------------------------------------------*/
double calculate_mean(double sum, int number)
{
	double mean = 0.0;

	if (number == 0)
	{
		mean = -1.0;
	}

	else
	{
		mean = sum / number;
	}
	return mean;
}

/*-----------------------------------------------------------
* Function: calculate_deviation()
* Date Created: 2/6/2024
* Date Last Modified: 2/6/2024
* Description: Calculates the deviation using the value
*			   and the mean of the collective values.
* Input parameters: Double input value and double mean.
* Returns: The deviation of the value from the mean.
* Preconditions: Both the number and the mean are input.
* Postconditions: The deviation has been calculated.
-------------------------------------------------------------*/
double calculate_deviation(double number, double mean)
{
	double deviation = 0.0;

	deviation = number - mean;
	
	return deviation;
}

/*-----------------------------------------------------------
* Function: calculate_variance()
* Date Created: 2/6/2024
* Date Last Modified: 2/6/2024
* Description: Calculates the variance of a sample.
* Input parameters: Double values of 5 deviations, and the integer 
					number of deviations
* Returns: The variance of the sample.
* Preconditions: Only double deviations and integers have been 
			     input.
* Postconditions: The variance has been calculated.
-------------------------------------------------------------*/
double calculcate_variance(double deviation1, double deviation2, double deviation3, 
	double deviation4, double deviation5, int number)
{
	double variance = 0.0;

	variance = (pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) +
		pow(deviation5, 2)) / number;

	return variance;
}

/*-----------------------------------------------------------
* Function: calculate_standard_deviation()
* Date Created: 2/6/2024
* Date Last Modified: 2/6/2024
* Description: Calculates the standard deviation of a sample
*			   given the variance.
* Input parameters: Double value of the variance.
* Returns: The standard deviation for a sample.
* Preconditions: Only a positive double variance is input.
* Postconditions: The standard deviation has been calculated.
-------------------------------------------------------------*/
double calculate_standard_deviation(double variance)
{
	double st_dev = 0.0;

	st_dev = sqrt(variance);

	return st_dev;
}
/*-----------------------------------------------------------
* Function: print_double()
* Date Created: 2/7/2024
* Date Last Modified: 2/7/2024
* Description: Prints a double value given from a variable to 
*			   a specified file to the hundredths place.
* Input parameters: Stream name and double variable for desired 
*					printed value.
* Returns: Nothing.
* Preconditions: The correct stream name and variable type has 
				 been input.
* Postconditions: The double value has been printed onto the 
			      desired file.
-------------------------------------------------------------*/
void print_double(FILE *stream, double variable)
{

	fprintf(stream, "%.2lf\n", variable);
	return 0;
}


/*-----------------------------------------------------------
* Function: find_maximum()
* Date Created: 2/7/2024
* Date Last Modified: 2/7/2024
* Description: Finds the minimum of 5 values.
* Input parameters: 5 double values
* Returns: The minimum value.
* Preconditions: Only double values have been input.
* Postconditions: The minimum value has been found.
-------------------------------------------------------------*/
double find_minimum(double number1, double number2, double number3, double number4, double number5)
{
	double minimum = number1;

	if (number1 > number2)
	{
		minimum = number2;
	}
	if(number1 > number3)
	{
		minimum = number3;
	}
	if (number1 > number4)
	{
		minimum = number4;
	}
	if (number1 > number5)
	{
		minimum = number5;
	}
	
	return minimum;
}

/*-----------------------------------------------------------
* Function: find_minimum()
* Date Created: 2/7/2024
* Date Last Modified: 2/7/2024
* Description: Finds the maximum of 5 values.
* Input parameters: 5 double values.
* Returns: The maximum value.
* Preconditions: Only double values have been input.
* Postconditions: The maximum value has been found.
-------------------------------------------------------------*/
double find_maximum(double number1, double number2, double number3, double number4, double number5)
{
	double maximum = number1;

	if (number1 < number2)
	{
		maximum = number2;
	}
	if (number1 < number3)
	{
		maximum = number3;
	}
	if (number1 < number4)
	{
		maximum = number4;
	}
	if (number1 < number5)
	{
		maximum = number5;
	}
	return maximum;
}