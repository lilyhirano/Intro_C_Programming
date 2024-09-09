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


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double read_double(FILE* infile);
int read_integer(FILE* infile);
double calculate_sum(double number1, double number2, double number3, double number4, double number5);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculcate_variance(double deviation1, double deviation2, double deviation3,double deviation4, 
	double deviation5, int number);
double calculate_standard_deviation(double variance);
void print_double(stream, variable);
double find_minimum(double number1, double number2, double number3, double number4, double number5);
double find_maximum(double number1, double number2, double number3, double number4, double number5);


