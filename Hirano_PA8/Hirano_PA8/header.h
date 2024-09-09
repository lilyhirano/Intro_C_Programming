/* Lily Hirano
   Cpt_S 121
   PA 8
   4/25/2024 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct occurrences
{
	int num_occurrences;
	double frequency;

} Occurrences;


char* my_str_n_cat(char* source, char* destination, int n);
int binary_search(int* array, int size, int target);
void bubble_sort(char* array_strings[], int num);
int is_palindrome(char string[], int length);
int find_primes(unsigned int num, unsigned int x);
int sum_primes(unsigned int num);
void maximum_occurences(char* string, Occurrences occurences[], int* num_ptr, char* char_ptr);