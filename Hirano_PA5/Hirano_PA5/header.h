/*-------------------------------------------------------------------------------------------------
Name: Lily Hirano
Class: CPT_S 121
Section: 03

Description: Displays menu. Once 1-3 is selected, for 1) rules are displayed, 2) game of Yahtzee is
			 played, or 3) game is exited after a key is pressed. Two player game of Yahtzee. 
			 Plays 14 rounds, calculates score, and states a winner.

----------------------------------------------------------------------------------------------------*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Menu
int menu_choice();
void print_game_rules();

//Yahtzee Game
void roll_dice(int* dice, int size); 
void print_dice(int* dice, int size);
int choose_reroll();
int score_choice();
void choose_reroll_dice(int* dice_reroll, int size);
void reroll_multiple_dice(int* dice, int* dice_reroll, int size_dice);
void count_dice(int* dice, int *dice_count, int size);
int check_score(int* dice, int *dice_count, int size, int selection);
int sum_faces(int* dice, int size);
int give_points(int score_check, int* points, int* dice, int size, int* points_upper, int *dice_count, int count_size, int use_check);
int score_used(int* points_used, int size_used, int score_check);
int sum_upper(int score_check, int *dice_count, int count_size, int *dice, int size);

//Final Scores
void calculate_final_score(int* points1, int* points2, int* points_upper1, int* points_upper2);
void print_final_scores(int* points1, int* points2, int* points_upper1, int* points_upper2);
void print_final_message(int* points1, int* points2);



