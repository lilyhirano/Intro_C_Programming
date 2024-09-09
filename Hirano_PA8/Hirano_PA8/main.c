/* Lily Hirano
   Cpt_S 121
   PA 8
   4/25/2024 */

#include "header.h"

int main(void)
{
	//1
	char source[] = "Hello there", destination[100] = "Why ";
	int num = 6;
	//2
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int target = 8;
	//3
	char* array_strings[5] = { "lychee", "apple", "strawberry", "mango", "orange" };
	//4
	char palindrome[] = { "r ace car" };
	int length = strlen(palindrome);
	//5
	unsigned int num2 = 10;
	int sum = 0;
	//6
	char* string = { "test string" }, char_ptr = '\0';
	Occurrences occurences[95] = { 0 };
	int num_ptr = 0;



	//1
	my_str_n_cat(source, destination, num);
	printf("1. %s\n\n", destination);

	//2
	printf("2. Target index: %d\n\n", binary_search(array, 10, target));

	//3
	bubble_sort(array_strings, 5);
	printf("3. ");
	for (int index = 0; index < 5; index++)
	{
		printf("%s ", array_strings[index]);
	}
	printf("\n\n");
	
	//4
	printf("4. Palindrome? %d\n\n", is_palindrome(palindrome, length));

	//5
	sum = sum_primes(num2);
	printf("5. Sum of primes: %d\n\n", sum);

	//6
	maximum_occurences(string, occurences, &num_ptr, &char_ptr);
	printf("6. The string \"%s\" has the most frequent character %c show up %d times\n", string, char_ptr, num_ptr);
	

	return 0;

}