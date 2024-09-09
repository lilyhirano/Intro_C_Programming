/*-------------------------------------------------------------------------------------------------
Name: Lily Hirano
Class: CPT_S 121
Section: 03

Description: Displays menu. Once 1-3 is selected, for 1) rules are displayed, 2) game of craps is
			 played, or 3) game is exited after any key is pressed. Plays several rounds
			 until the player wins or loses. Player places bets on each round. A running total of
			 the player's bank balance is kept and returned at the end of the game.

----------------------------------------------------------------------------------------------------*/

#include "header.h"

/*-----------------------------------------------------------
* Function: menu_choice()
* Date Created: 2/17/2024
* Date Last Modified: 2/17/2024
* Description: Displays the menu for the game of craps
* Input parameters: None
* Returns: Choice made by player
* Preconditions: Non character value has ben input
* Postconditions: The rules have been printed and chocie is 
*				  returned
-------------------------------------------------------------*/
int menu_choice(void)
{
	int choice = 0;

	printf("1. Display Rules\n2. Play Craps\n3. Exit game\n");
	scanf("%d", &choice);

	return choice;
}

/*-----------------------------------------------------------
* Function: print_game_rules()
* Date Created: 2/17/2024
* Date Last Modified: 2/17/2024
* Description: Prints the rules of the game of Craps
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: The game rules have been printed.
-------------------------------------------------------------*/
void print_game_rules(void)
{
	printf("Rules:\n");
	printf("A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.\n");
	printf("After the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n");
	printf("If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw\n");
	printf("(called \"craps\"), the player loses(i.e.the \"house\" wins). If the sum is 4, 5, 6, 8, 9, or 10 on the\n");
	printf("first throw, then the sum becomes the player's \"point.\" To win, you must continue rolling the dice until\n");
	printf("you \"make your point.\" The player loses by rolling a 7 before making the point.\n\n");
}

/*-----------------------------------------------------------
* Function: get_bank_balance()
* Date Created: 2/17/2024
* Date Last Modified: 2/17/2024
* Description: Gets the bank balance from the player
* Input parameters: None
* Returns: Balance of the bank
* Preconditions: No characters are input
* Postconditions: The prompts have been printed and the 
*                 balance has been returned.
-------------------------------------------------------------*/
double get_bank_balance(void)
{
	double balance = 0.0;

	printf("Input initial bank balance: $");
	scanf("%lf", &balance);
	printf("Bank balance is now $%.2lf\n", balance);

	return balance;

}

/*-----------------------------------------------------------
* Function: get_wager_amount()
* Date Created: 2/17/2024
* Date Last Modified: 2/17/2024
* Description: Gets the wager from the player
* Input parameters: None
* Returns: Wager amount
* Preconditions: No characters are input
* Postconditions: The prompts have been printed and the wager
*                 is returned.
-------------------------------------------------------------*/
double get_wager_amount(void)
{
	double wager = 0.0;

	printf("Enter a wager for the roll: $");
	scanf("%lf", &wager);

	return wager;
}

/*-----------------------------------------------------------
* Function: check_wager_amount()
* Date Created: 2/17/2024
* Date Last Modified: 2/17/2024
* Description: Checks if the wager is valid, ie less than the
			   bank balance.
* Input parameters: Double number for the wager and double 
				    number for the  bank balance.
* Returns: 0 if the wager is invalid or 1 if the bank balance 
           is valid
* Preconditions: Double numbers are input for the wager and 
			     balance.
* Postconditions: 0 or 1 has been returned.
-------------------------------------------------------------*/
int check_wager_amount(double wager, double balance)
{
	if (wager > balance)
	{
		return 0;
	}
	else
	{

		return 1;
	}

}

/*-----------------------------------------------------------
* Function: roll_dice()
* Date Created: 2/17/2024
* Date Last Modified: 2/17/2024
* Description: Rolls the dice once, generating a random number 
			   1-6. Prints statement showing what die is being 
			   rolled.
* Input parameters: Integer number to denote which dice is being 
					rolled.
* Returns: Dice value for one roll
* Preconditions: Int number is input
* Postconditions: The rolled statement is printed and returned.
-------------------------------------------------------------*/
int roll_die(number)
{
	int die_value = 0;


	die_value = rand() % 6 + 1;

	printf("Dice Number %d's value is: %d\n", number,  die_value);

	return die_value;
}

/*-----------------------------------------------------------
* Function: calculate_sum_dice()
* Date Created: 2/18/2024
* Date Last Modified: 2/18/2024
* Description: Calculates the sum of two dice and prints it
* Input parameters: Two int values for the two dice rolls
* Returns: Sum of the dice
* Preconditions: Two int values have been input
* Postconditions: The statement has been printed and the sum
				  of the die have been returned.
-------------------------------------------------------------*/
int calculate_sum_dice(int die1_value, int die2_value)
{
	int sum_dice = 0.0;

	sum_dice = die1_value + die2_value;

	printf("Dice sum is: %d\n", sum_dice);

	return sum_dice;

}

/*-----------------------------------------------------------
* Function: is_win_loss_or_point()
* Date Created: 2/18/2024
* Date Last Modified: 2/18/2024
* Description: Determines if the game has been won, lost, or 
			   continues.
* Input parameters: Int sum of the dice
* Returns: 1 for a win, 0 for a loss, and -1 to continue game.
* Preconditions: Int sun of dice has been input
* Postconditions: 1, 0, or -1 has been returned.
-------------------------------------------------------------*/
int is_win_loss_or_point(int sum_dice)
{
	if (sum_dice == 7 || sum_dice == 11)
	{
		return 1;
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

/*-----------------------------------------------------------
* Function: is_point_loss_or_neither()
* Date Created: 2/18/2024
* Date Last Modified: 2/18/2024
* Description: Finds if the sum of the dice is equal to the 
			   desired point (denoting a win), if the sum is 
			   equal to 7 (denoting a loss), or if the game 
			   continues.
* Input parameters: Integer sum of the dice and integer 
				    value of the desired point.
* Returns: 1 for a win, 0 for a loss, or -1 to continue game.
* Preconditions: Int values for sum and point value have been 
				 input.
* Postconditions: 1, 0, or -1 has been returned
-------------------------------------------------------------*/
int is_point_loss_or_neither(int sum_dice, int point_value)
{
	if (sum_dice == point_value)
	{
		return 1;
	}
	if (sum_dice == 7)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

/*-----------------------------------------------------------
* Function: adjust_bank_balance()
* Date Created: 2/18/2024
* Date Last Modified: 2/19/2024
* Description: Determines if bank balance should be added or 
			   subtracted to depending on win, loss, or neither.
* Input parameters: Double value for bank balance and wager 
					amount. Integer value for if the game was a 
					win, loss, or neither.
* Returns: New bank balance after changes have been made.
* Preconditions: Required values have been input.
* Postconditions: New bank balance has been calculated.
-------------------------------------------------------------*/
double adjust_bank_balance(double bank_balance, double
	wager_amount, int add_or_subtract)
{
	double new_bank_balance = 0.0;

	if (add_or_subtract == 1)
	{
		new_bank_balance = wager_amount + bank_balance;

		return new_bank_balance;
	}
	if (add_or_subtract == 0)
	{
		new_bank_balance = bank_balance - wager_amount;
		return new_bank_balance;
	}
	else
	{
		new_bank_balance = bank_balance;
		return new_bank_balance;
	}

}

/*-----------------------------------------------------------
* Function: chatter_messages()
* Date Created: 2/18/2024
* Date Last Modified: 2/24/2024
* Description: Prints messages throughout the game depeding 
			   on win status or number of rolls.
* Input parameters: Integer number of rolls and win status, 
					and double value for the current bank balance.
* Returns: None
* Preconditions: Required integers and double has been input.
* Postconditions: Printed messages have been displayed.
-------------------------------------------------------------*/
void chatter_messages(int number_rolls, int win_loss_neither, double current_bank_balance)
{
	if (number_rolls == 5)
	{
		printf("\n(((((Wow you're unlucky!!)))))\n");
	}
	if (number_rolls == 10)
	{
		printf("\n(((((Come on, win already!!)))))\n");
	}
	if (win_loss_neither == 1)
	{
		printf("\n\nCongrats!! You have won the game! Your current bank balance is now $%.2lf. \n\nPlay again?\n", current_bank_balance);
	}
	if (win_loss_neither == 0)
	{
		printf("\n\nOOF!! You lose!! You rolled a total of 7. Your current bank balance is now $%.2lf\n\nPlay again?\n", current_bank_balance);
	}
	if (win_loss_neither == -1)
	{
		printf("\n\nTry again! \n\nStarting round %d........\n", number_rolls + 1);
	}
}

/*-----------------------------------------------------------
* Function: wager_chatter()
* Date Created: 2/19/2024
* Date Last Modified: 2/24/2024
* Description: Prints messages depending on how much player \
			   bets in comparison to their ban balance.
* Input parameters: Integer wager amount and bank balance
* Returns: None
* Preconditions: Integers have been input
* Postconditions: The statments have been printed.
-------------------------------------------------------------*/
void wager_chatter(int wager_amount, int current_bank_balance)
{
	if (wager_amount == current_bank_balance)
	{
		printf("(((((Going for broke, huh?)))))\n\n");
	}
	if (wager_amount + 50 < current_bank_balance)
	{
		printf("(((((Come on! Take a chance!!)))))\n\n");
	}
}