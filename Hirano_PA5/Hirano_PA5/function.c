/*-------------------------------------------------------------------------------------------------
Name: Lily Hirano
Class: CPT_S 121
Section: 03

Description: Displays menu. Once 1-3 is selected, for 1) rules are displayed, 2) game of Yahtzee is
			 played, or 3) game is exited after a key is pressed. Two player game of Yahtzee.
			 Plays 14 rounds, calculates score, and states a winner.

----------------------------------------------------------------------------------------------------*/

#include "header.h"

/*-----------------------------------------------------------
* Function: menu_choice()
* Date Created: 3/11/2024
* Date Last Modified: 3/11/2024
* Description: Displays the menu for the game of Yahtzee
* Input parameters: None
* Returns: Choice made by user.
* Preconditions: Integer 1-3 choice is made.
* Postconditions: The Menu has been printed and the choice 
                  has been recorded.
-------------------------------------------------------------*/
int menu_choice()
{
	int choice = 0;
	
	printf("1. Display Rules\n2. Play Yahtzee\n3. Exit game\n");
	scanf(" %d", &choice);

	return choice;

}

/*-----------------------------------------------------------
* Function: print_game_rules()
* Date Created: 3/11/2024
* Date Last Modified: 3/11/2024
* Description: Prints the rules of the game of Yahtzee
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: The game rules have been printed.
-------------------------------------------------------------*/
void print_game_rules()
{
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and\n");
	printf("lower section.A total of thirteen boxes or thirteen scoring combinations are divided\n");
	printf("amongst the sections.The upper section consists of boxes that are scored by summing\n");
	printf("the value of the dice matching the faces of the box.If a player rolls four 3's, then the\n");
	printf("score placed in the 3's box is the sum of the dice which is 12. Once a player has\n");
	printf("chosen to score a box, it may not be changed and the combination is no longer in play\n");
	printf("for future rounds. If the sum of the scores in the upper section is greater than or\n");
	printf("equal to 63, then 35 more points are added to the players overall score as a bonus.\n\n");
	printf("Three-of-a-kind: Three dice with the same face.| Score: Sum of all face values on the 5 dice\n");
	printf("Four-of-a-kind: Four dice with the same face.  | Score: Sum of all face values on the 5 dice\n");
	printf("Full house:     One pair and a three-of-a-kind.| Score: 25\n");
	printf("Small straight: A sequence of four dice.       | Score: 30\n");
	printf("Large straight: A sequence of five dice.       | Score: 40\n");
	printf("Yahtzee:        Five dice with the same face   | Score: 50\n");
	printf("Chance:   May be used for any sequence of dice.| Score: Sum of all face values on the 5 dice\n\n");

}

/*-----------------------------------------------------------
* Function: roll_dice()
* Date Created: 3/12/2024
* Date Last Modified: 3/12/2024
* Description: Rolls a dice for the size of the dice array.
* Input parameters: Integer dice array, and size of the array.
* Returns: None.
* Preconditions: Size of the array is given correctly.
* Postconditions: The dice have been randomly generated.
-------------------------------------------------------------*/
void roll_dice(int* dice, int size)
{
	dice[0] = 0;

	for (int index = 1; index < size; ++index)
	{
		dice[index] = rand() % 6 + 1;
	}
}

/*-----------------------------------------------------------
* Function: print_dice()
* Date Created: 3/12/2024
* Date Last Modified: 3/12/2024
* Description: Prints dice array.
* Input parameters: Integer dice array and size of the array.
* Returns: None
* Preconditions: Size of the array is given correctly.
* Postconditions: The dice have been printed on the screen.
-------------------------------------------------------------*/
void print_dice(int* dice, int size)
{
	printf("\nThe dice you rolled are: ");

	for (int index = 1; index < size ; ++index)
	{
		printf("%d ", dice[index]);
	}

	printf("\n");
}

/*-----------------------------------------------------------
* Function: choose_reroll()
* Date Created: 3/13/2024
* Date Last Modified: 3/13/2024
* Description: Asks user if they want to reroll dice, and 
               records response.
* Input parameters: None.
* Returns: 0 if yes, 1 if no, and -1 if y or n isn't entered.
* Preconditions: None.
* Postconditions: The question is displayed and 0, 1, or -1
                  has been returned.
-------------------------------------------------------------*/
int choose_reroll()
{
	char choice = '\0';

	printf("Would you like to reroll?\nY/N?\n");
	scanf(" %c", &choice);

	if (choice == 'y' || choice == 'Y')
	{
		return 0;

	}
	if (choice == 'n' || choice == 'N')
	{
		return 1;

	}
	else
	{
		return -1;
	}
}

/*-----------------------------------------------------------
* Function: score_choice()
* Date Created: 3/13/2024
* Date Last Modified: 3/13/2024
* Description: Displays the choices the player can make for 
               points and logs the choice made.
* Input parameters: None.
* Returns: Choice made by user.
* Preconditions: Choice is an integer.
* Postconditions: The manu has been displayed and the choice 
                  is logged.
-------------------------------------------------------------*/
int score_choice()
{
	int choice = 0;

	printf("\n\nWhat combination would you like to use?:\n");
	printf("1. Three-of-a-kind: Three dice with the same face.| Score: Sum of all face values on the 5 dice\n");
	printf("2. Four-of-a-kind: Four dice with the same face.  | Score: Sum of all face values on the 5 dice\n");
	printf("3. Full house:     One pair and a three-of-a-kind.| Score: 25\n");
	printf("4. Small straight: A sequence of four dice.       | Score: 30\n");
	printf("5. Large straight: A sequence of five dice.       | Score: 40\n");
	printf("6. Yahtzee:        Five dice with the same face   | Score: 50\n");
	printf("7. Chance:   May be used for any sequence of dice.| Score: Sum of all face values on the 5 dice\n");
	printf("8. Sum of 1's.                                    |\n");
	printf("9. Sum of 2's.                                    |\n");
	printf("10.Sum of 3's.                                    |\n");
	printf("11.Sum of 4's.                                    |\n");
	printf("12.Sum of 5's.                                    |\n");
	printf("13.Sum of 6's.                                    |\n");
	printf("0. None.                                          | Score: 0\n\n");

	printf("Enter 0-13: ");
	scanf(" %d", &choice);


	return choice;
}

/*-----------------------------------------------------------
* Function: choose_reroll_dice()
* Date Created: 3/16/2024
* Date Last Modified: 3/16/2024
* Description: Asks the user how many dice they would like 
               to reroll, and logs the response into an array.
			   Dice_reroll[] is set to 0s once run.
* Input parameters: Integer array for dice_reroll and size 
					of the array
* Returns: None.
* Preconditions: Size of the array is correct for number of 
				 dice rolled.
* Postconditions: Dice_reroll[] has been set to all 0s, the 
                  message has been displayed, and the response
				  is logged in the array.
-------------------------------------------------------------*/
void choose_reroll_dice( int* dice_reroll, int size)
{
	char temp = 0;

	for (int index = 0; index < size; ++index)
	{
		dice_reroll[index] = 0;
	}

	printf("Type the dice you would like to reroll separated by spaces: ");

	for (int index = 1; temp != '\n'; ++index)
	{
		scanf(" %d%c", &dice_reroll[index], &temp);
	}
}

/*-----------------------------------------------------------
* Function: reroll_multiple_dice()
* Date Created: 3/16/2024
* Date Last Modified: 3/16/2024
* Description: Rerolls the previously selected dice by user.
* Input parameters: Dice array, dice reroll array, and size 
					of the dice array.
* Returns: None.
* Preconditions: Size of dice array is input correctly.
* Postconditions: The dice selected by the user has a new 
				  number generated.
-------------------------------------------------------------*/
void reroll_multiple_dice(int *dice, int *dice_reroll, int size_dice)
{

	for (int index = 1; index <= size_dice; ++index )
	{
		if (dice_reroll[index] != 0)
		{
			switch (dice_reroll[index])
			{
			case 1: dice[1] = rand() % 6 + 1;
				break;
			case 2: dice[2] = rand() % 6 + 1;
				break;
			case 3: dice[3] = rand() % 6 + 1;
				break;
			case 4: dice[4] = rand() % 6 + 1;
				break;
			case 5: dice[5] = rand() % 6 + 1;
			}
		}
	}
}

/*-----------------------------------------------------------
* Function: dice_count()
* Date Created: 3/13/2024
* Date Last Modified: 3/14/2024
* Description: Counts the number of dice that represent each 
			   number. For example: if there are three ones 
			   present. Counts are recorded into an array that 
			   is reset at the beginning of the function.
* Input parameters: Dice array, dice_count array, and size 
				    of dice array.
* Returns: None.
* Preconditions: Dice array and dice_count array are the same 
				 size.
* Postconditions: The dice have been counted and recorded in
                  the dice_count array.
-------------------------------------------------------------*/
void count_dice(int *dice, int *dice_count, int size)
{
	int found = 0;

	for (int index = 0; index < size; ++index)
	{
		dice_count[index] = 0;
	}

	for (int y = 1; y <= size; ++y)
	{
		found = 0;

		for (int x = 1; x < size; ++x)
		{

			if (dice[x] == y)
			{
				found += 1;

			}

		}
		dice_count[y] = found;
	}

}


/*-----------------------------------------------------------
* Function: check_score()
* Date Created: 3/13/2024
* Date Last Modified: 3/18/2024
* Description: Based on the choice by the user, this function
               checks if the choice is valid or not.
* Input parameters: Dice array, dice_count array, 
					size of dice array, and the selection made 
					by the user.
* Returns: 0-13 if the choice is valid, otherwise, returns -1 
		   check value if invalid.
* Preconditions: Input parameters are correct.
* Postconditions: -1 - 13 is returned.
-------------------------------------------------------------*/
int check_score(int *dice, int *dice_count, int size, int selection)
{
	int check = -1;

	count_dice(dice, dice_count, size); 

	if (selection == 0)
	{
		return 0;
	}

	if (selection == 1)
	{

		for (int index = 1; index <= size; index++)
		{
			if (dice_count[index] == 3)
			{
				return 1;
			}
			else
			{
				check = -1;
			}
		}
		
	}
	
	if (selection == 2)
	{
		
		for (int index = 1; index <= size; index++)
		{
			if (dice_count[index] == 4)
			{
				return 2;
			}
			else
			{
				check = -1;
			}
		}

	}

	if (selection == 3)
	{

		for (int index = 1; index <= size; index++)
		{
			if (dice_count[index] == 3)
			{
				for (int index2 = 1; index2 <= size; index2++)
				{
					if (dice_count[index2] == 2)
					{
						return 3;
					}
					else
					{
						check = -1;
					}

				}
			}
			if (dice_count[index] == 2)
			{
				for (int index2 = 1; index2 <= size; index2++)
				{
					if (dice_count[index2] == 3)
					{
						return 3;
					}
					else
					{
						check = -1;
					}

				}

			}
			else
			{
				check = -1;
			}
		}

	}

	if (selection == 4)
	{
		for (int index = 0; index <= size; index ++)
		{
			if (dice_count[index] == 1 || dice_count[index] == 2)
			{
				index += 1;
				if (dice_count[index] == 1 || dice_count[index] == 2)
				{
					index += 1;
					if (dice_count[index] == 1 || dice_count[index] == 2)
					{
						index += 1;
						if (dice_count[index] == 1 || dice_count[index] == 2)
						{
							return 4;
						}

					}
				}

			}

		}


	}

	if (selection == 5)
	{
		for (int index = 0; index <= size; index++)
		{
			if (dice_count[index] == 1)
			{
				index += 1;
				if (dice_count[index] == 1)
				{
					index += 1;
					if (dice_count[index] == 1)
					{
						index += 1;
						if (dice_count[index] == 1)
						{
							index += 1;
							if (dice_count[index] == 1)
							{
								return 5;
							}

						}

					}
				}

			}

		}

	
	}

	if (selection == 6)
	{
		for (int index = 1; index <= size; index++)
		{
			if (dice_count[index] == 5)
			{
				return 6;
			}
		}
	}

	if (selection == 7)
	{
		return 7;
		
	}

	if (selection == 8)
	{
		if (dice_count[1] >= 1)
		{
			return 8;
		}
		else
		{
			return -1;
		}

	}

	if (selection == 9)
	{
		if (dice_count[2] >= 1)
		{
			return 9;
		}
		else
		{
			return -1;
		}

	}

	if (selection == 10)
	{
		if (dice_count[3] >= 1)
		{
			return 10;
		}
		else
		{
			return -1;
		}

	}

	if (selection == 11)
	{
		if (dice_count[4] >= 1)
		{
			return 11;
		}
		else
		{
			return -1;
		}

	}

	if (selection == 12)
	{
		if (dice_count[5] >= 1)
		{
			return 12;
		}
		else
		{
			return -1;
		}

	}

	if (selection == 13)
	{
		if (dice_count[6] >= 1)
		{
			return 13;
		}
		else
		{
			return -1;
		}

	}
	
	return check;
}

/*-----------------------------------------------------------
* Function: sum_faces()
* Date Created: 3/14/2024
* Date Last Modified: 3/14/2024
* Description: Sums the faces of the dice.
* Input parameters: Dice array and the size of the array
* Returns: Calculated sum.
* Preconditions: Int dice array and size is correctly input.
* Postconditions: Sum has been calculated and returned.
-------------------------------------------------------------*/
int sum_faces(int *dice, int size)
{
	int sum = 0;

	for (int index = 0; index < size; ++index)
	{
		sum += dice[index];
	}

	return sum;
}

/*-----------------------------------------------------------
* Function: sum_upper()
* Date Created: 3/14/2024
* Date Last Modified: 3/15/2024
* Description: Based on the checked score choice, sums the 
			   desired dice.
* Input parameters: Int score_check, dice_count array, count 
					array size, dice array, and dice array size.
* Returns: Sum of the desired face.
* Preconditions: All input arrays and variable are correct.
* Postconditions: The sum has been correctly calculated and 
				  returned.
-------------------------------------------------------------*/
int sum_upper(int score_check, int *dice_count, int count_size, int *dice, int size)
{
	int sum = 0;

	count_dice(dice, dice_count, size); 

	switch (score_check)
	{
	case 8: 
		sum = dice_count[1] * 1;
		break;
	case 9: 
		sum = dice_count[2] * 2;
		break;
	case 10:
		sum = dice_count[3] * 3;
		break;
	case 11: 
		sum = dice_count[4] * 4;
		break;
	case 12:
		sum = dice_count[5] * 5;
		break;
	case 13:
		sum = dice_count[6] * 6;
	}
	
	return sum;

}

/*-----------------------------------------------------------
* Function: give_points()
* Date Created: 3/15/2024
* Date Last Modified: 3/16/2024
* Description: Gives the player points based on validated choice.
* Input parameters: Checked score int, points pointer, dice array, 
					size of dice array, upper points pointer, dice
					count array, size of counted dice array, and 
					int to check if the points have been used 
					already.
* Returns: -1 if invalid.
* Preconditions: Input parameters are correct, and pointers are used.
* Postconditions: The points have been given based on the 
				  validated choice.
-------------------------------------------------------------*/
int give_points(int score_check, int *points, int *dice, int size, int *points_upper, int *dice_count, int count_size, int use_check)
{
	int sum = 0, upper_sum = 0;

	sum = sum_faces(dice, size);
	upper_sum = sum_upper(score_check, dice_count, count_size, dice, size);

	switch (score_check)
	{
	case -1: return -1;
		break;
	case 1: *points += sum;
		break;
	case 2: *points += sum;
		break;
	case 3: *points += 25;
		break;
	case 4: *points += 30;
		break;
	case 5: *points += 40;
		break;
	case 6: 
		if (use_check == 2)
		{
		*points += 100;
		}

		else 
		{
		*points += 50;
		}	
		break;
	case 7: *points += sum;
		break;
	case 0: *points += 0;
		break;
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13: *points_upper += upper_sum;

	}
}

/*-----------------------------------------------------------
* Function: score_used()
* Date Created: 3/15/2024
* Date Last Modified: 3/16/2024
* Description: Checks if the score has already been used previously.
* Input parameters: Points used array, size of array, and the
					checked score selected.
* Returns: Returns -1 if the score has been used, 2 if the
		   score is 7 and has been used, and 0 if the score 
		   is unused.
* Preconditions: Int points used array and checked score has 
				 been input
* Postconditions: -1, 0, or 2 has been returned.
-------------------------------------------------------------*/
int score_used(int *points_used, int size_used, int score_check)
{
	if (points_used[score_check] == 1)
	{
		return -1;

	}
	if (points_used[7] == 1)
	{
		return 2;
	}
	else
	{
		points_used[score_check] = 1;
		return 0;
	}

}

/*-----------------------------------------------------------
* Function: calculate_final_score()
* Date Created: 3/15/2024
* Date Last Modified: 3/15/2024
* Description: Calculates the final score based on the upper 
			   score board points the player has.
* Input parameters: Points and upper points for player 1 
					and 2, all pointers.
* Returns: None.
* Preconditions: Pointers have been used.
* Postconditions: The final score has been calculated.
-------------------------------------------------------------*/
void calculate_final_score(int* points1, int* points2, int *points_upper1, int *points_upper2)
{
	if (*points_upper1 >= 63)
	{
		*points1 += 63;
	}
	if (*points_upper2 >= 63)
	{
		*points2 += 63;
	}

}

/*-----------------------------------------------------------
* Function: print_final_scores()
* Date Created: 3/16/2024
* Date Last Modified: 3/16/2024
* Description: Prints the final scores for the game of Yahtzee.
* Input parameters: Points and upper points for player 1 
					and 2, all pointers.
* Returns: None.
* Preconditions: Pointers have been inuput.
* Postconditions: The final scores have been printed.
-------------------------------------------------------------*/
void print_final_scores(int* points1, int* points2, int* points_upper1, int* points_upper2)
{
	printf("\n\nPlayer 1 has %d upper points and a final score of: %d\n", *points_upper1, *points1);
	printf("Player 2 has %d upper points and a final score of: %d\n", *points_upper2, *points2);
	system("pause");
	system("cls");

}

/*-----------------------------------------------------------
* Function: print_final_message()
* Date Created: 3/16/2024
* Date Last Modified: 3/16/2024
* Description: Prints the final message that determines the 
			   winner of the game.
* Input parameters: Pointer for points for both player one
					and two.
* Returns: None.
* Preconditions: Pointers have been inuput.
* Postconditions: The winning message has been displayed.
-------------------------------------------------------------*/
void print_final_message(int *points1, int *points2)
{

	if (*points1 > *points2)
	{
		printf("\n\n\nCongrats Player 1, you have won the game of Yahtzee!!!!\n\n\n");
		printf("Play again?\n");
	}
	if (*points1 < *points2)
	{
		printf("\n\n\nCongrats Player 2, you have won the game of Yahtzee!!!!\n\n\n");
		printf("Play again?\n");
	}

	if (*points1 == *points2)
	{
		printf("\n\n\nYou tied!!! Better luck next time!\n\n\n");
		printf("Play again?\n");
	}
}