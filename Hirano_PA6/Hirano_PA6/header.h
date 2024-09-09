//Lily Hirano CptS 121 Battleship


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>




typedef struct stats
{
	int number_hits, num_misses, total_shots;
	double hits_misses_ratio;

}Stats;

void print_main_screen();
int print_placement_choice();
void initialize_game_board(char board[10][10]);

int player_order();

void manually_place_ships(char board[10][10]);
int check_placement_valid(char board[10][10], int x, int y, int z);
void randomly_place_ships(char board[10][10]);


void display_board_1(char board[10][10]);
void display_board_2(char board[10][10]);


void choose_coordinate(int* x, int* y, char board[10][10]);
void random_shot(int* x, int* y, char board[10][10]);
int check_if_hit(char board[10][10], int* x, int* y, int player_order, FILE* outstream);
void update_stats(Stats* stats_ptr, int status);
int check_if_win(char board[10][10]);

void print_stats(Stats* stats_ptr1, Stats* stats_ptr2, FILE* outfile, int winner);
void final_statement(int winner);

void play_battleship();


