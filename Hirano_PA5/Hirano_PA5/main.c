/*-------------------------------------------------------------------------------------------------
Name: Lily Hirano
Class: CPT_S 121
Section: 03

Description: Displays menu. Once 1-3 is selected, for 1) rules are displayed, 2) game of Yahtzee is
			 played, or 3) game is exited after a key is pressed. Two player game of Yahtzee.
			 Plays 14 rounds, calculates score, and states a winner.

----------------------------------------------------------------------------------------------------*/

#include "header.h"

int main(void)
{
	int dice[6], dice_count[7], points_used1[14], points_used2[14], dice_reroll[6];
	int start = 0, choice = 0, rolls = 1, reroll_choice = 0, round = 0, score_selection = 0, reroll_dice_choice = 1,
		score_check = 0, points1 = 0, points2 = 0, use_check = 0, points_upper1 = 0, points_upper2 = 0;

	srand((unsigned int)time(NULL));

	while (start == 0)
	{
		start = 1;
		round = 1;									//Resets values if player wants to play consecutive game.
		choice = 0;

		do
		{
			choice = menu_choice();					//Keep displaying menu until a value 1-3 is pressed.

		} while (choice < 1 || choice > 3);


		switch (choice)
		{
		case 1:
			system("cls");
			print_game_rules();					//Displays game rules
			system("pause");
			system("cls");

			break;
		case 2:
			while (round <= 14)					//Plays game for 14 rounds.
			{
				rolls = 1;

				system("cls");

				if (round != 1)
				{
					printf("Time for Player 1! \n\nStarting round %d...", round);	//Displays what round it is after the first round.
					system("pause");
					system("cls");
				}


				//Player 1
				printf("Player 1: Roll your five dice! ");
				system("pause");

				roll_dice(dice, 6);
				rolls += 1;							//Initial roll of the dice.
				print_dice(dice, 6);

				while (rolls <= 3)					//Allows for two rerolls of selected dice.
				{
					reroll_choice = choose_reroll();		

					while (reroll_choice == -1)
					{
						printf("Please enter Y or N only. ");		//If character other than y or n is input reprint reroll choice.
						reroll_choice = choose_reroll();
					}

					if (reroll_choice == 0)							//If yes is selected, the player chooses what dice to reroll.
					{												//The dice are rerolled and the dice are printed once again.
						rolls += 1;
						system("cls");

						print_dice(dice, 6);

						choose_reroll_dice(dice_reroll, 6);
						reroll_multiple_dice(dice, dice_reroll, 6);

						print_dice(dice, 6);

					}
					if (reroll_choice == 1)				//If no, exit the loop.
					{
						rolls += 3;

					}
				}
														
				system("cls");					        //Once the player has done the three rolls or selects no,
														//print menu for score selection.
				print_dice(dice, 6);
				score_selection = score_choice();
				
				score_check = check_score(dice, dice_count, 7, score_selection);	//Check score is valid.
				use_check = score_used(points_used1, 14, score_check);				//Check if score is used.

				while (score_check == -1 || use_check == -1)						//While the input is invalid or used, display the points menu.
				{
					system("cls");
					printf("Invalid. Please use a valid or unused combination.\n");

					print_dice(dice, 6);
					score_selection = score_choice();
					score_check = check_score(dice, dice_count, 7, score_selection);
					use_check = score_used(points_used1, 7, score_check);
				}

				give_points(score_check, &points1, dice, 6, &points_upper1, dice_count, 7, use_check);	//Give points based on selection

				
				system("cls");
				printf("Player 1 now has %d points and %d upper points.\n\n", points1, points_upper1);		//Display points and start player 2.
				printf("\nTime for Player 2! ");
				system("pause");
				

				//Player 2
				system("cls");
				printf("Player 2: Roll your five dice! ");
				system("pause");

				rolls = 1;

				roll_dice(dice, 6);
				rolls += 1;										//Initial roll of the dice.
				print_dice(dice, 6);

				while (rolls <= 3)								//Allows for two rerolls of selected dice.
				{
					reroll_choice = choose_reroll();

					while (reroll_choice == -1)					//If character other than y or n is input reprint reroll choice.
					{
						printf("Please enter Y or N only. ");
						reroll_choice = choose_reroll();
					}

					if (reroll_choice == 0)						//If yes is selected, the player chooses what dice to reroll.
					{											//The dice are rerolled and the dice are printed once again.
						rolls += 1;								
						system("cls");

						print_dice(dice, 6);

						choose_reroll_dice(dice_reroll, 6);
						reroll_multiple_dice(dice, dice_reroll, 6);

						print_dice(dice, 6);

					
					}
					if (reroll_choice == 1)						//If no, exit the loop.
					{
						rolls += 3;

					}
				}
				
				system("cls");					        //Once the player has done the three rolls or selects no,
														//print menu for score selection.
				print_dice(dice, 6);
				score_selection = score_choice();
				

				score_check = check_score(dice, dice_count, 7, score_selection);   //Check if score is valid.
				use_check = score_used(points_used2, 14, score_check);			   //Check if score is used.

				while (score_check == -1 || use_check == -1)					   //While the input is invalid or used, display the points menu.
				{
					system("cls");
					printf("Invalid. Please use a valid or unused combination.\n");

					print_dice(dice, 6);
					score_selection = score_choice();
					score_check = check_score(dice, dice_count, 7, score_selection);
					use_check = score_used(points_used2, 7, score_check);
				}

				give_points(score_check, &points2, dice, 6, &points_upper2, dice_count, 7, use_check); //Give points based on selection

				round += 1;

				system("cls");
				printf("Player 2 now has %d points and %d upper points.\n\n", points2, points_upper2);	//Display points and start player 1 on
				system("pause");																		//next round.

			}


			system("cls");
			printf("Calculating score.....");
			system("pause");
			system("cls");

			calculate_final_score(&points1, &points2, &points_upper1, &points_upper2);	

			print_final_scores(&points1, &points2, &points_upper1, &points_upper2);			//Calculates and prints final scores and prints winner.

			print_final_message(&points1, &points2);



			break;
		case 3:
			system("cls");
			printf("\nGoodbye! Press any key to exit the game. \n");		//Exit message for selecting 3.
		}

		if (choice != 3)
		{
			start = 0;														//Go back to the top if the choice wasn't 3.
		}

		
	}
	return 0;
}
	