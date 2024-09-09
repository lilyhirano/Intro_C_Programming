/*-------------------------------------------------------------------------------------------------
Name: Lily Hirano
Class: CPT_S 121
Section: 03

Description: Displays menu. Once 1-3 is selected, for 1) rules are displayed, 2) game of craps is
			 played, or 3) game is exited after enter is pressed. Plays several rounds
			 until the player wins or loses. Player places bets on each round. A running total of
			 the player's bank balance is kept and returned at the end of the game.

----------------------------------------------------------------------------------------------------*/

#include "header.h"

int main(void)
{
	int choice = 0, start = 0, check_wager = 0, dice1 = 0, dice2 = 0, dice_sum = 0, game_check1 = 0, goal_point = 0,
		point_check = -1, round = 0;
	double balance = 0.0, wager = 0.0;
	
	srand((unsigned int)time(NULL));

	while (start == 0) 
	{
		start = 1;
		point_check = -1;							//Resets values after game is finished if player chooses to play another
		round = 0;									//game consecutively.

		do
		{
			choice = menu_choice();					//Keep displaying menu until a value 1-3 is pressed.

		} while (choice < 1 || choice > 3);

		switch (choice)
		{
		case 1: print_game_rules();					//If 1 is pressed, show rules. If 2 is pressed, play game.  
			break;									// If 3 is pressed, display exit message.
		case 2: printf("Playing game!\n\n");
			balance = get_bank_balance();

			wager = get_wager_amount();

			check_wager = check_wager_amount(wager, balance);		//Get bank balance, wager. Displays messages if wager falls 
			wager_chatter(wager, balance);							 //in certain range.

			while (check_wager == 0)
			{
				printf("Please enter wager smaller than or equal to bank balance.\n");		//Gets new wager if wager is larger 
				wager = get_wager_amount();													//than bank balance.
				check_wager = check_wager_amount(wager, balance);
			}
			if (check_wager == 1)
			{
				printf("\n\nThe game has now begun! Rolling dice....\n\n");				
				dice1 = roll_die(1);
				dice2 = roll_die(2);											//Rolls die for first round, displays sum, and checks
				dice_sum = calculate_sum_dice(dice1, dice2);					//if the game is continued for next rounds.

				game_check1 = is_win_loss_or_point(dice_sum);

				if (game_check1 == 1)											//Display for win. Ends game.
				{
					printf("\n\nYou win this round! Congratulations! Your new bank balance is $%.2lf\n\n", balance + wager); 
				}
				else if (game_check1 == 0)										//Display for loss. Ends game.
				{
					printf("\n\nHouse wins this round! Sorry :,( Your new bank balance is $%.2lf\n\n", balance - wager);
				}
				else															//Continues game otherwise and sets new goal point
				{																// for future rolls.
					goal_point = dice_sum;

					printf("\n\nYou live to play another round!\n");
					printf("Goal point is now: %d\n\n", goal_point);

					while (point_check == -1)
					{

						dice1 = roll_die(1);								//Rolls die for consecutive rounds and displays sum.
						dice2 = roll_die(2);
						dice_sum = calculate_sum_dice(dice1, dice2);

						point_check = is_point_loss_or_neither(dice_sum, goal_point);	//Checks if goal point is met.
						balance = adjust_bank_balance(balance, wager, point_check);		//Adjusts bank balance accordingly.
						round += 1;														//Increases round number by 1 each round.
						
						chatter_messages(round, point_check, balance);					//Displays messages depending on round number
																						// or win/loss.
						
						if (point_check == -1)											//If neither win or loss, get wager amount 
						{																// for next round.
							wager = get_wager_amount();
							wager_chatter(wager, balance);

							while (wager > balance)		//Gets new wager if wager is larger than bank balance.
							{
								printf("Please enter wager smaller than or equal to bank balance.\n");
								wager = get_wager_amount();
							}
						}
					}
				}
			}
			break;
		case 3: printf("\nPress any key to exit game. \n");
		}

		if (choice != 3)		//If choice was originally 1 or 2, display the menu again.
		{
			start = 0;
		}
	}
	return 0;
}

