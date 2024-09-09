/* Authors: Deitel& Deitel - C How to Program
Lily Hirano
Class: Cpt_S 121 
Lab Section: 03
Description: Plays game of Poker.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card
{
	int index_face;
	int index_suit;

}Card;

typedef struct hand
{
	Card hand[5];

}Hand;

int menu_choice();
void display_rules();

void print_hand(Hand player[5], const char* wFace[], const char* wSuit[]);

void shuffle(int wDeck[][13]);
int deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand player[5], int current_card);

void choose_card_redraw(int redraw[3]);
int chosen_redraw(int redraw[3], Hand player[5], int current_card, const int wDeck[][13]);

void evaluate_frequency(Hand player[5], int suit_table[4], int face_table[13], const char* wFace[], const char* wSuit[]);

int find_pair(int face_table[13]);	//1 pt
int find_twopairs(int face_table[13]); //2 pts
int find_threeofkind(int face_table[13]); //3 pts
int find_fourofkind(int face_table[13]); //7 pts
int find_fullhouse(int face_table[13]); //6 pts
int find_flush(int suit_table[4]); //5 pts
int find_straight(int face_table[13]); //4 pts

int evaluate_score(int face_table[13], int suit_table[4], int score_table[7]);

int dealer_redraw(Hand dealer[5], int current_card, const int wDeck[][13], int card_to_redraw);
int evaluate_dealer(int face_table[13], Hand dealer[5], const int wDeck[][13], int current_card, int score);


void print_score(int score);
void print_score_dealer(int score);

void print_winner(int score_p1, int score_dealer);

int play_poker();

