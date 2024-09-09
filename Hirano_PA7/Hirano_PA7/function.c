/* Authors: Deitel & Deitel - C How to Program
Lily Hirano
Class: Cpt_S 121
Lab Section: 03
Description: Plays game of five draw Poker.
*/



#include "header.h"

/*-----------------------------------------------------------
* Function: menu_choice()
* Description: Displays the menu for the game of Poker
* Input parameters: None
* Returns: Choice made by user.
* Preconditions: Integer 1-3 choice is made.
* Postconditions: The Menu has been printed and the choice
				  has been recorded.
-------------------------------------------------------------*/
int menu_choice()
{
	int choice = 0;

	do
	{
		printf("1. Display Rules\n2. Play Poker\n3. Exit game\n");
		scanf(" %d", &choice);
		system("CLS");
	} while (choice > 3 || choice < 1);

	return choice;

}

/*-----------------------------------------------------------
* Function: display_rules()
* Description: Displays the rules of the game of five draw 
			   poker.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: The rules have been printed.
-------------------------------------------------------------*/
void display_rules()
{
	printf("1. The dealer draws 5 cards and deals you 5 cards.\n2. You and the dealer have the chance to discard and draw up to three cards.\n");
	printf("2. Try to earn one of the following combinations sorted from highest scoring to lowest: \n");
	printf("\t- Four of a kind\n\t- Full House (Three of the same and a pair)\n\t- Flush (Five cards of the same suit)\n\t- Straight\n\t- Three of a Kind\n\t- Two Pair\n\t- One Pair\n");
	printf("4. The program will assess you and the dealer's best scoring combination and announce who won.\n");

}

/* shuffle cards in deck -- Made by Deitel& Deitel*/
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/*------------------------------------------------------------
* Function: deal()
* Description : Deals the player 5 cards from the deck
* Input parameters : Deck, face, and suit array. Player's hand 
					 array of 5, and the current card to be 
					 drawn.
* Returns : The current card.
* Preconditions : Input parameters are met.
* Postconditions : The cards have been dealt to the player.
-------------------------------------------------------------*/
int deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand player[5], int current_card)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

		for (;card < 5 && current_card <= 52; current_card++)
		{
			/* loop through rows of wDeck */
			for (row = 0; row <= 3; row++)
			{
				/* loop through columns of wDeck for current row */
				for (column = 0; column <= 12; column++)
				{
					/* if slot contains current card, deal card */
					if (wDeck[row][column] == current_card)
					{
						player[card].hand->index_face = column;
						player[card].hand->index_suit = row;

						card++;

					}
				}
			}
		}
		//Face column. Suit row

		return current_card;
}

/*------------------------------------------------------------
* Function: print_hand()
* Description : Prints the hand of the desired player.
* Input parameters : Player's hand, face, and suit array.
* Returns : None
* Preconditions : Input parameters are met and the hand stores 
				  5 cards only.
* Postconditions : The player's hand has been printed.
-------------------------------------------------------------*/
void print_hand(Hand player[5], const char* wFace[], const char* wSuit[])
{
	for(int index = 0; index < 5; index++)
	{
		printf("%d. %s of %s\n", index + 1, wFace[player[index].hand->index_face], wSuit[player[index].hand->index_suit]);
	}
	printf("\n\n");

}

/*------------------------------------------------------------
* Function: choose_card_redraw()
* Description : Allows the player to choose which cards to
				redraw.
* Input parameters : Redraw array of 3.
* Returns : None
* Preconditions : Redraw array provided. Up to three integers 
				  are provided by the user.
* Postconditions : The statements have been printed and the
				   choice(s) have been logged into the array.
-------------------------------------------------------------*/
void choose_card_redraw(int redraw[3])
{
	char temp = '\0', choice = '\0';
	
	printf("Would you like to redraw? Y/N? ");

	do{
		scanf("%c", &choice);

	} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

	if(choice == 'Y' || choice == 'y')
	{
		printf("Type up to three cards you would like to redraw separated by spaces: ");

		for (int index = 0; temp != '\n'; ++index)
		{
			scanf(" %d%c", &redraw[index], &temp);		//scan until enter is entered.
		}
	}
}

/*------------------------------------------------------------
* Function: chosen_redraw()
* Description : Redraws the player's selected cards.
* Input parameters : Redraw, player's hand, and deck array. 
					 The current card for the deck.
* Returns : The current card after redrawing.
* Preconditions : Input parameters are met
* Postconditions : The cards have been redrawn.
-------------------------------------------------------------*/
int chosen_redraw(int redraw[3], Hand player[5], int current_card, const int wDeck[][13])
{
	for (int index = 0, redrawn_card = 0; index < 3; index++)
	{
			if (redraw[index] != 0)
			{
				redrawn_card = redraw[index] - 1;

					/* loop through rows of wDeck */
					for (int row = 0; row <= 3; row++)
					{
						/* loop through columns of wDeck for current row */
						for (int column = 0; column <= 12; column++)
						{
							/* if slot contains current card, redraw card */
							if (wDeck[row][column] == current_card)
							{
								player[redrawn_card].hand->index_face = column;
								player[redrawn_card].hand->index_suit = row;


							}
						}
					}

				current_card++;
			}

	}

	return current_card;
}

/*------------------------------------------------------------
* Function: dealer_redraw()
* Description : Redraws a card for the dealer.
* Input parameters : Dealer's hand and deck array. Current card 
					 of the deck and desired card to redraw from
					 the hand.
* Returns : The current card after redrawing.
* Preconditions : Input parameters are met.
* Postconditions : The desired card has been redrawn.
-------------------------------------------------------------*/
int dealer_redraw(Hand dealer[5], int current_card, const int wDeck[][13], int card_to_redraw)
{
	for (; current_card <= 52; current_card++)
	{
		/* loop through rows of wDeck */
		for (int row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (int column = 0; column <= 12; column++)
			{
				/* if slot contains current card, redraw desired card */
				if (wDeck[row][column] == current_card)
				{
					dealer[card_to_redraw].hand->index_face = column;
					dealer[card_to_redraw].hand->index_suit = row;
					
					current_card++;

					return current_card;
				}
			}
		}
	}
	
	
}

/*------------------------------------------------------------
* Function: evaluate_dealer()
* Description : Evaluates if the dealer should redraw cards, 
				and if so, what cards should be redrawn.
* Input parameters : Face frequency, dealer's hand, and deck 
					 array. Dealer's current score before redraw, 
					 and the current card of the deck. 
* Returns : Current card of the deck after redrawing.
* Preconditions : Input parameters are met.
* Postconditions : The dealer's cards have been redrawn.
-------------------------------------------------------------*/
int evaluate_dealer(int face_table[13], Hand dealer[5], const int wDeck[][13], int current_card, int score)
{
	if (score >= 4)
	{
		return current_card;			//If score is higher than a four, keep the hand.
	}
	if (score == 0)
	{
		for(int loop = 0; loop < 3; loop++)
		{
			dealer_redraw(dealer, current_card, wDeck, loop);	//if no points, redraw the first three cards.
			current_card++;
		}
	}
	else
	{
		for (int index = 0; index < 13; index++)
		{
			if (face_table[index] == 2 || face_table[index] == 3)		//If there is a pair, redraw the other three cards
			{															//If there's a triple, redraw the other two cards
				for(int index2 = 0; index2 < 5; index2++)
				{
					if (dealer[index2].hand->index_face != index)
					{
						current_card = dealer_redraw(dealer, current_card, wDeck, index2);
					}
				}
			}
			
		}

	}
	return current_card;
}

/*------------------------------------------------------------
* Function: evaluate_frequency()
* Description : Evaluates the frequency of each suit and face 
				from the player's hand. Resets the frequency 
				tables each time
* Input parameters : Player's hand, suit frequency, face 
					 frequency, face, and suit array
* Returns : None
* Preconditions : The input parameters are met.
* Postconditions : The face and suit frequency tables have 
				   been correctly filled in.
-------------------------------------------------------------*/
void evaluate_frequency(Hand player[5], int suit_table[4], int face_table[13], const char* wFace[], const char* wSuit[])
{
	for (int index = 0; index < 5; index++)
	{
		suit_table[index] = 0;
	}												//resets frequency tables to 0 each time function is used.
	for (int index = 0; index < 13; index++)
	{
		face_table[index] = 0;
	}
	


	for (int index = 0; index < 5; index++)
	{
		for(int suit_type = 0; suit_type < 4; suit_type++)
		{
			if (player[index].hand->index_suit == suit_type)		//Add 1 to the corresponding suit type for each type of suit in the player's hand
			{
				suit_table[suit_type]++;

			}
		}
	}

	for (int index = 0; index < 5; index++)
	{
		for (int face_type = 0; face_type < 13; face_type++)		//Add 1 to the corresponding face type for each face type in the player's hand
		{
			if (player[index].hand->index_face == face_type)
			{
				face_table[face_type]++;

			}
		}
	}

}

/*------------------------------------------------------------
* Function: find_pair()
* Description : Finds a pair in the player's hand
* Input parameters : Face frequency table.
* Returns : 1 if there is a pair, and 0 if there is not.
* Preconditions : The input parameters have been met and the	
				  frequency of the faces in the player's hand 
				  has been evaluated.
* Postconditions : The correct scoring has been returned.
-------------------------------------------------------------*/
int find_pair(int face_table[13])
{

	for (int index = 0; index < 13; index++)
	{
		if (face_table[index] == 2)
		{
			return 1;
		}

	}
	return 0;
}

/*------------------------------------------------------------
* Function: find_twopair()
* Description : Finds two pairs in the player's hand
* Input parameters : Face frequency table.
* Returns : 2 if there are two pairs, and 0 if there is not.
* Preconditions : The input parameters have been met and the
				  frequency of the faces in the player's hand
				  has been evaluated.
* Postconditions : The correct scoring has been returned.
-------------------------------------------------------------*/
int find_twopairs(int face_table[13])
{
	int count = 0;

	for (int index = 0; index < 13; index++)
	{
		if (face_table[index] == 2)
		{
			count++;
		}

	}

	if (count == 2)
	{
		return 2;
	}
	else
	{

		return 0;
	}

}

/*------------------------------------------------------------
* Function: find_threeofkind()
* Description : Finds a three of a kind in the player's hand
* Input parameters : Face frequency table.
* Returns : 3 if there is a three of a kind, and 0 if there is 
		    not.
* Preconditions : The input parameters have been met and the
				  frequency of the faces in the player's hand
				  has been evaluated.
* Postconditions : The correct scoring has been returned.
-------------------------------------------------------------*/
int find_threeofkind(int face_table[13])
{

	for (int index = 0; index < 13; index++)
	{
		if (face_table[index] == 3)
		{
			return 3;
		}

	}
	
	return 0;

}

/*------------------------------------------------------------
* Function: find_fourofkind()
* Description : Finds a four of a kind in the player's hand
* Input parameters : Face frequency table.
* Returns : 7 if there is a four of a kind, and 0 if there is not.
* Preconditions : The input parameters have been met and the
				  frequency of the faces in the player's hand
				  has been evaluated.
* Postconditions : The correct scoring has been returned.
-------------------------------------------------------------*/
int find_fourofkind(int face_table[13])
{

	for (int index = 0; index < 13; index++)
	{
		if (face_table[index] == 4)
		{
			return 7;
		}

	}
	
	return 0;

}

/*------------------------------------------------------------
* Function: find_fullhouse()
* Description : Finds a full house in the player's hand
* Input parameters : Face frequency table.
* Returns : 6 if there is a full house, and 0 if there is not.
* Preconditions : The input parameters have been met and the
				  frequency of the faces in the player's hand
				  has been evaluated.
* Postconditions : The correct scoring has been returned.
-------------------------------------------------------------*/
int find_fullhouse(int face_table[13])
{

	for (int index = 0; index < 13; index++) //search the face table
	{
		if (face_table[index] == 3) //if found a three, search for a 2
		{
			for (int index2 = 0; index2 < 13; index2++)
			{
				if (face_table[index2] == 2)
				{
					return 6;

				}

			}

		}
		if (face_table[index] == 2) //if found a two search for a three
		{
			for (int index2 = 0; index2 < 13; index2++)
			{
				if (face_table[index2] == 3)
				{
					return 6;

				}

			}

		}

	}

	return 0;
}

/*------------------------------------------------------------
* Function: find_flush()
* Description : Finds a flush in the player's hand
* Input parameters : Suit frequency table.
* Returns : 5 if there is a flush, and 0 if there is not.
* Preconditions : The input parameters have been met and the
				  frequency of the faces in the player's hand
				  has been evaluated.
* Postconditions : The correct scoring has been returned.
-------------------------------------------------------------*/
int find_flush(int suit_table[4])
{

	for (int index = 0; index < 4; index++)
	{
		if (suit_table[index] == 5)
		{
			return 5;
		}

	}
	
	return 0;

}

/*------------------------------------------------------------
* Function: find_straight()
* Description : Finds a straight in the player's hand
* Input parameters : Face frequency table.
* Returns : 4 if there is a straight, and 0 if there is not.
* Preconditions : The input parameters have been met and the
				  frequency of the faces in the player's hand
				  has been evaluated.
* Postconditions : The correct scoring has been returned.
-------------------------------------------------------------*/
int find_straight(int face_table[13])
{
	for (int index = 0; index < 8; index++)
	{
		if (face_table[index] == 1) //if 5 1s in a row, there is a straight.
		{
			if (face_table[index + 1] == 1)
			{
				if (face_table[index + 2] == 1)
				{
					if (face_table[index + 3] == 1)
					{
						if (face_table[index + 4] == 1)
						{
							return 4;


						}


					}


				}


			}


		}

	}


	return 0;

}

/*------------------------------------------------------------
* Function: evaluate_score()
* Description : Evaluates the highest score in the player's 
			    hand.
* Input parameters : Face frequency, suit frequency, and score 
					 array.
* Returns : Highest possible score from the hand.
* Preconditions : Input parameters are met.
* Postconditions : The highest possible score has been returned.
-------------------------------------------------------------*/
int evaluate_score(int face_table[13], int suit_table[4], int score_table[7])
{
	int largest_score = 0;

	for (int index = 0; index < 7; index++)		//Resets score table each time function is used.
	{
		score_table[index] = 0;
	}

	score_table[0] = find_pair(face_table);
	score_table[1] = find_twopairs(face_table);
	score_table[2] = find_threeofkind(face_table);
	score_table[3] = find_straight(face_table);
	score_table[4] = find_flush(suit_table);
	score_table[5] = find_fullhouse(face_table);
	score_table[6] = find_fourofkind(face_table);

	for (int index = 0; index < 7; index++)		//Find the highest possible score from the score array
	{
		if (largest_score < score_table[index])
		{
			largest_score = score_table[index];
		}
	}

	return largest_score;
}

/*------------------------------------------------------------
* Function: print_score()
* Description : Prints the score for the player
* Input parameters : The highest possible score from the hand.
* Returns : None.
* Preconditions : None.
* Postconditions : The correct statement has been printed.
-------------------------------------------------------------*/
void print_score(int score)
{
	switch (score)
	{
	case 0: printf("You have no points. :(\n");
		break;
	case 1: printf("Your highest scoring combo is a pair.\n");
		break;
	case 2: printf("Your highest scoring combo is two pairs.\n");
		break;
	case 3: printf("Your highest scoring combo is three of a kind.\n");
		break;
	case 4: printf("Your highest scoring combo is a straight.\n");
		break;
	case 5: printf("Your highest scoring combo is a flush!\n");
		break;
	case 6: printf("Your highest scoring combo is a full house!\n");
		break;
	case 7: printf("your highest scoring combo is a four of a kind!!\n");
		break;
	}

}

/*------------------------------------------------------------
* Function: print_score_dealer()
* Description : Prints the highest possible score for the dealer.
* Input parameters : Score for the dealer
* Returns : None
* Preconditions : None
* Postconditions : The correct statement has been printed.
-------------------------------------------------------------*/
void print_score_dealer(int score)
{
	switch (score)
	{
	case 0: printf("Dealer has no points.\n");
		break;
	case 1: printf("The Dealer's highest scoring combo is a pair.\n");
		break;
	case 2: printf("The Dealer's scoring combo is two pairs.\n");
		break;
	case 3: printf("The Dealer's scoring combo is three of a kind.\n");
		break;
	case 4: printf("The Dealer's scoring combo is a straight.\n");
		break;
	case 5: printf("The Dealer's scoring combo is a flush!\n");
		break;
	case 6: printf("The Dealer's scoring combo is a full house!\n");
		break;
	case 7: printf("The Dealer's scoring combo is a four of a kind!!\n");
		break;
	}

}

/*------------------------------------------------------------
* Function: print_winner()
* Description : Compares the two scores and prints the appropriate
				winning statement.
* Input parameters : Score of player 1 and the score of the 
					 dealer.
* Returns : None
* Preconditions : None
* Postconditions : The appropriate winning statement has been
				   printed.
-------------------------------------------------------------*/
void print_winner(int score_p1, int score_dealer)
{
	if (score_p1 > score_dealer)
	{
		printf("Congrats you have won!!");
	}
	if (score_p1 < score_dealer)
	{

		printf("Sorry! You have lost and the dealer won the game. :(");
	}
	if (score_p1 == score_dealer)
	{
		printf("You and the dealer have tied!");

	}

	printf("\n\nPlay Again?\n");

}

/*------------------------------------------------------------
* Function: play_poker()
* Description : Runs the game of 5 draw poker
* Input parameters : None
* Returns : 0 after done executing.
* Preconditions : None
* Postconditions : The game of poker runs successfully. 
-------------------------------------------------------------*/
int play_poker()
{
	int start = 0;


	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initialize deck array */


	Hand player1[5], dealer[5];

	int suit_table[5] = { 0 }, face_table[13] = { 0 }, score_table[7] = { 0 };

	srand((unsigned)time(NULL)); /* seed random-number generator */

	while (start == 0)
	{
		start = 1;

		int deck[4][13] = { 0 };
		int redraw[3] = { 0 };
		int score_p1 = 0, score_dealer = 0, choice = 0, current_card = 1;

		choice = menu_choice();

		switch (choice)
		{
		case 1: display_rules();
			system("pause");
			system("cls");
			break;
		case 2:
			shuffle(deck);

			current_card = deal(deck, face, suit, player1, current_card);
			current_card = deal(deck, face, suit, dealer, current_card);

			print_hand(player1, face, suit);
			choose_card_redraw(redraw);
			current_card = chosen_redraw(redraw, player1, current_card, deck);
			system("cls");
			printf("Your final hand is:\n");
			print_hand(player1, face, suit);
			system("pause");
			system("cls");
			evaluate_frequency(player1, suit_table, face_table, face, suit);
			score_p1 = evaluate_score(face_table, suit_table, score_table);


			printf("Dealer is evaluating deck and redrawing...");
			system("pause");

			evaluate_frequency(dealer, suit_table, face_table, face, suit);
			score_dealer = evaluate_score(face_table, suit_table, score_table);
			current_card = evaluate_dealer(face_table, dealer, deck, current_card, score_dealer);

			system("cls");
			printf("Evaluating deck...");
			system("pause");
			system("cls");
			print_score(score_p1);
			printf("\n");
			print_score_dealer(score_dealer);
			printf("\n\n");
			system("pause");
			system("cls");
			print_winner(score_p1, score_dealer);


			break;
		case 3: printf("Press any key to exit the game.\n\n");
			system("pause");
			return 0;
		}

		if (choice != 3)		//If choice was originally 1 or 2, display the menu again.
		{
			start = 0;
		}
	}

	return 0;

}