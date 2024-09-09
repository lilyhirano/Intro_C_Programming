/*-------------------------------------------------------------------------------------------------
Name: Lily Hirano
Class: CPT_S 121
Section: 03

Description: Displays menu. Once 1-3 is selected, for 1) rules are displayed, 2) game of craps is 
			 played, or 3) game is exited after enter is pressed. Plays several rounds 
			 until the player wins or loses. Player places bets on each round. A running total of 
			 the player's bank balance is kept and returned at the end of the game. 
					
----------------------------------------------------------------------------------------------------*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu_choice(void);
void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);
int roll_die(number);
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double
	wager_amount, int add_or_subtract);
void chatter_messages(int number_rolls, int win_loss_neither, double current_bank_balance);
void wager_chatter(int wager_amount, int current_bank_balance);