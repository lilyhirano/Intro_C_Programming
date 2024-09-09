/* Lily Hirano
   Cpt_S 121
   PA 8
   4/25/2024 */

#include "header.h"

/*-----------------------------------------------------------
* Function: my_str_n_cat()
* Description:  This function to copies at most n characters,
				character by character, from the source character 
				array to the end of the destination character 
				array
* Input parameters: Source and destination strings, num of 
					characters to be copied
* Returns: Pointer to the destination string
* Preconditions: N is not negative
* Postconditions: The destination string has the desired number
				  of source characters added onto the end of it
-------------------------------------------------------------*/
char* my_str_n_cat(char* source, char* destination, int n)
{

	while (*destination != '\0')		//Reach the end of destination to not overwrite
	{
		destination++;

	}

	for (int index = 0; index < n && *source != '\0'; index++)	//Add source onto end of destination char by char
	{
		*destination = *source;
		source++;
		destination++;

	}

	*destination = '\0';	//Add null onto end of string

	return *destination;
 }

/*-----------------------------------------------------------
* Function: binary_search()
* Description: Searches for target value in a sorted list.
* Input parameters: Array, size of the array, and target integer
* Returns: The index of the target integer or -1 for target 
		   not found
* Preconditions: Array is a sorted list
* Postconditions: The target index is returned.
-------------------------------------------------------------*/
int binary_search(int* array, int size, int target)
{
	int found = 0, left_index = 0, right_index = size - 1, target_index = -1, midpoint = 0;

	while (found == 0 && left_index <= right_index)
	{
		midpoint = (left_index + right_index) / 2;

		if (array[midpoint] == target) //Set to found if target is found
		{
			found = 1;
			target_index = midpoint;
		}
		else if (array[midpoint] < target) //If current number is less than the target, move the left 
											//index to the current midpoint shifted left one
		{
			left_index = midpoint + 1;

		}
		else								//If current number is greater than the target, move the right index 
		{									//to the current midpoint shifted to the right one
			right_index = midpoint - 1;

		}
		
	}
	return target_index;
}

/*-----------------------------------------------------------
* Function: bubble_sort()
* Description: Sorts an array of strings.
* Input parameters: Array of pointers to strings and number 
					of strings
* Returns: None
* Preconditions: Number of strings is greater than 0
* Postconditions: The array of strings has been sorted
-------------------------------------------------------------*/
void bubble_sort(char* array_strings[], int num)
{
	int u = num, c = 1;
	char* temp = NULL;

	while (u > 1)
	{
		while (c < u)
		{
			if (strcmp(array_strings[c], array_strings[c - 1]) < 0)  //if right is less than left
			{
				temp = array_strings[c - 1];
				array_strings[c - 1] = array_strings[c];		//swap pointers
				array_strings[c] = temp;
			}
			c++;
		}
		u--;
	}
}

/*-----------------------------------------------------------
* Function: is_palindrome()
* Description: Recursively determines if a string is a 
			   palindrome, ignoring white space.
* Input parameters: String and length of the string
* Returns: 0 if not a palindrome and 1 if a palindrome
* Preconditions: Length of string is greater than 0
* Postconditions: 1 or 0 has been returned
-------------------------------------------------------------*/
int is_palindrome(char string[], int length)
{
	if (length <= 1)	
	{
		return 1;
	}

	while (*string == ' ' || string == '\0')  //Skip blank space from the left
	{
		string++;
		length--;

	}
	while (string[length] == ' ' || string[length] == '\0') //Skip blank space from the right
	{
		length--;

	}
	if (*string == string[length]) //If the first and last characters match, check next characters
	{
		return is_palindrome(string + 1, length - 2);
	}
	else						 //Otherwise, is not a palindrome
	{
		return 0;
	}
}

/*-----------------------------------------------------------
* Function: find_primes()
* Description: Recursively determines if num is a prime.
* Input parameters: Unsigned desired number and unsigned x 
					modulator.
* Returns: 1 if num is a prime and 0 if num is not a prime.
* Preconditions: Num and x are greater than 0
* Postconditions: 1 or 0 has been returned
-------------------------------------------------------------*/
int find_primes(unsigned int num, unsigned int x)
{
	if (x == 1) //if reached where 1 is the modulator, the number is a prime
	{
		return 1;
	}
	else if (num % x == 0) //If not prime return 0
	{
		return 0;
	}
	else
	{
		return find_primes(num, x - 1);
	}
}

/*-----------------------------------------------------------
* Function: sum_primes()
* Description: Recursively finds the sum of the primes from
			   num to 2.
* Input parameters: Unsigned desired number
* Returns: The sum of the primes
* Preconditions: None
* Postconditions: Sum has been returned
-------------------------------------------------------------*/
int sum_primes(unsigned int num)
{
	int sum = 0;

	if (num < 2) //If less than 2, there are no primes
	{
		return 0;
	}

	if (find_primes(num, num / 2))
	{
		sum += num + sum_primes(num - 1); //If num is prime, add it to the sum

	}
	else
	{
		sum += sum_primes(num - 1); //Else, keep looking for a prime
	}

	return sum;
}

/*-----------------------------------------------------------
* Function: maximum_occurences()
* Description: Finds the maximum number of occurences of
			   alphanumeric characters in a string and finds the 
			   frequency of each character
* Input parameters: String, occurences array, integer poiner for 
					the maximum occurences, and a char pointer 
					for the most frequent character
* Returns: None
* Preconditions: String is not empty
* Postconditions: The maximum occurences and most frequent 
				  character has been found
-------------------------------------------------------------*/
void maximum_occurences(char *string, Occurrences occurences[], int *num_ptr, char *char_ptr)
{
	int x = 0, length = strlen(string), maximum = 0;
	char most_frequent = '\0';

	while (*string != '\0')
	{
		x = *string - 32; //white space is now in the 0th index spot

		occurences[x].num_occurrences++; //Add occurance to 

		string++;

	}

	for (int index = 0; index < 95; index++) //Calculate frequency for whole array
	{
		occurences[index].frequency = (double)(occurences[index].num_occurrences / length);

	}

	for (int index = 1; index < 95; index++) //Finds the maximum for the array and determines the character
	{
		if (occurences[index].num_occurrences > maximum)
		{
			maximum = occurences[index].num_occurrences;
			most_frequent = index + 32;
		}

	}

	*num_ptr = maximum;
	*char_ptr = most_frequent;

}