//Lily Hirano CptS 121 Battleship
#include "header.h"

/*-----------------------------------------------------------
* Function: print_main_screen()
* Description: Prints the main screen for battleship.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: The main screen has been printed.
-------------------------------------------------------------*/
void print_main_screen()
{
	printf("***** Welcome to Battleship! *****\n\n");
	printf("Rules of the game:\n1. This is a two player game.\n2. Player1 is you and Player2 is the computer.\n");
	printf("3. The first player is chosen randomly.\n4. Place your ships horizontally or vertically in a fashion where the ships do not overlap.\n");
	printf("5. You and the computer take shots at the each other's ships until someone wins!\n\n");
	printf("Press any key to play the game!\n\n");
	system("pause");
	system("cls");
}

/*-----------------------------------------------------------
* Function: print_placement_choice()
* Description: Prompts user to manually place or randomly 
			   place ships. Answer is logged.
* Input parameters: None
* Returns: Choice made by user.
* Preconditions: Placing choice is not a character.
* Postconditions: The statement has been printed and the 
				  choice has been recorded.
-------------------------------------------------------------*/
int print_placement_choice()
{
	int placing_choice = 0;

	do
	{
		printf("Would you like to: [1] manually place your ships or [2] randomly generate them? ");
		scanf("%d", &placing_choice);

	} while (placing_choice > 2 || placing_choice < 1);

	system("cls");

	return placing_choice;

}

/*-----------------------------------------------------------
* Function: initialize_game_board()
* Description: Sets the game board to water, '-'.
* Input parameters: Character board that is 10x10.
* Returns: None
* Preconditions: Character board is 10x10
* Postconditions: The game board has been initialized to 
				  water.
-------------------------------------------------------------*/
void initialize_game_board(char board[10][10])
{
	for (int y = 0; y < 10; y++)
	{
		
		for (int x = 0; x < 10; x++)
		{
			board[y][x] = '-';

		}
	}
}

/*-----------------------------------------------------------
* Function: display_board_1()
* Description: Displays the coordinates, water, and ship 
			   positions for player 1.
* Input parameters: Character board that is 10x10.
* Returns: None
* Preconditions: Char board is 10x10 and has been initialized.
* Postconditions: The board has been successfully printed.
-------------------------------------------------------------*/
void display_board_1(char board[10][10])
{
	printf("Player 1's Board\n");

	for (int y = 0; y < 10; y++)
	{
		if (y == 0)
		{
			printf("  0123456789\n");

		}

		for (int x = 0; x < 10; x++)
		{
			if (x == 0)
			{
				printf("%d ", y);

			}
			printf("%c", board[y][x]);
	
		}
		printf("\n");
	}

}

/*-----------------------------------------------------------
* Function: display_board_2()
* Description: Displays the board for player 2. Omits the 
			   ship placement and replaces it with water.
* Input parameters: Char board that is 10x10
* Returns: None
* Preconditions: Char board is 10x10 and board has been 
				 initialized
* Postconditions: The board has been printed.
-------------------------------------------------------------*/
void display_board_2(char board[10][10])
{
	printf("Player 2's Board\n");

	for (int y = 0; y < 10; y++)
	{
		if (y == 0)
		{
			printf("  0123456789\n");

		}

		for (int x = 0; x < 10; x++)
		{
			if (x == 0)
			{
				printf("%d ", y);

			}
			if (board[y][x] == 'R' || board[y][x] == 'C' || board[y][x] == 'D' || board[y][x] == 'S' || board[y][x] == 'B')
			{
				printf("-");

			}
			else
			{
				printf("%c", board[y][x]);
			}

		}
		printf("\n");

	}

}

/*-----------------------------------------------------------
* Function: manually_place_ships()
* Description: Allows the user to place their own ship by 
			   entering valid coordinates.
* Input parameters: Char board that is 10x10
* Returns: None
* Preconditions: No letter coordinates are input.
* Postconditions: The ships have been placed on the board.
-------------------------------------------------------------*/
void manually_place_ships(char board[10][10])
{
	int x = 0, y = 0, coordinate = 0, check = 0,z = 0;
	char temp = '\0';

	//Carrier------------------------------------------------------------------------
	printf("Enter five cells to place the Carrier across separated by spaces: ");	
	while( temp != '\n')
	{
		scanf(" %d%c", &coordinate, &temp);
		y = coordinate % 10;
		x = (coordinate / 10) % 10;
		z = (coordinate / 100) % 10;
		check += check_placement_valid(board, x, y, z);
		board[y][x] = 'C';
	}
	while (check != 0) //Keep displaying invalid while invalid.
	{
		check = 0;
		temp = '\0';
		for (int a = 0; a < 10; a++)
		{
			for (int b = 0; b < 10; b++)
			{
				if (board[a][b] == 'C') //Reset any carrier markers to water.
				{
					board[a][b] = '-';
				}
			}
		}
		printf("Invalid placement of ship. Please try again: "); //Get user input again.
		while (temp != '\n')
		{
			scanf(" %d%c", &coordinate, &temp);
			y = coordinate % 10;
			x = (coordinate / 10) % 10;
			z = (coordinate / 100) % 10;
			check += check_placement_valid(board, x, y, z);
			board[y][x] = 'C';
		}
	}
		
	//Battleship-------------------------------------------------------------------	
	temp = '\0';
	
	printf("Enter four cells to place the Battleship across separated by spaces: ");

	while (temp != '\n')
	{
		scanf(" %d%c", &coordinate, &temp);
		y = coordinate % 10;
		x = (coordinate / 10) % 10;
		z = (coordinate / 100) % 10;
		check += check_placement_valid(board, x, y, z);
		board[y][x] = 'B';
	}
	
	while (check != 0)
	{
		check = 0;
		temp = '\0';
		for (int a = 0; a < 10; a++)
		{
			for (int b = 0; b < 10; b++)
			{
				if (board[a][b] == 'B')
				{
					board[a][b] = '-';
				}

			}
		}
		printf("Invalid placement of ship. Please try again: ");
		while (temp != '\n')
		{
			scanf(" %d%c", &coordinate, &temp);
			y = coordinate % 10;
			x = (coordinate / 10) % 10;
			z = (coordinate / 100) % 10;
			check += check_placement_valid(board, x, y, z);
			board[y][x] = 'B';
		}

	}

	//Cruiser-------------------------------------------------------------
	temp = '\0';

	printf("Enter three cells to place the Cruiser across separated by spaces: ");

	while (temp != '\n')
	{
		scanf(" %d%c", &coordinate, &temp);
		y = coordinate % 10;
		x = (coordinate / 10) % 10;
		z = (coordinate / 100) % 10;
		check += check_placement_valid(board, x, y, z);
		board[y][x] = 'R';
	}

	while (check != 0)
	{
		check = 0;
		temp = '\0';
		for (int a = 0; a < 10; a++)
		{
			for (int b = 0; b < 10; b++)
			{
				if (board[a][b] == 'R')
				{
					board[a][b] = '-';
				}

			}
		}
		printf("Invalid placement of ship. Please try again: ");
		while (temp != '\n')
		{
			scanf(" %d%c", &coordinate, &temp);
			y = coordinate % 10;
			x = (coordinate / 10) % 10;
			z = (coordinate / 100) % 10;
			check += check_placement_valid(board, x, y, z);
			board[y][x] = 'R';
		}

	}

	//Submarine------------------------------------------------------------------
	temp = '\0';

	printf("Enter three cells to place the Submarine across separated by spaces: ");

	while (temp != '\n')
	{
		scanf(" %d%c", &coordinate, &temp);
		y = coordinate % 10;
		x = (coordinate / 10) % 10;
		z = (coordinate / 100) % 10;
		check += check_placement_valid(board, x, y, z);
		board[y][x] = 'S';
	}

	while (check != 0)
	{
		check = 0;
		temp = '\0';
		for (int a = 0; a < 10; a++)
		{
			for (int b = 0; b < 10; b++)
			{
				if (board[a][b] == 'S')
				{
					board[a][b] = '-';
				}

			}
		}
		printf("Invalid placement of ship. Please try again: ");
		while (temp != '\n')
		{
			scanf(" %d%c", &coordinate, &temp);
			y = coordinate % 10;
			x = (coordinate / 10) % 10;
			z = (coordinate / 100) % 10;
			check += check_placement_valid(board, x, y, z);
			board[y][x] = 'S';
		}

	}
	
	//Destroyer---------------------------------------------------------------------
	temp = '\0';

	printf("Enter two cells to place the Destroyer across separated by spaces: ");

	while (temp != '\n')
	{
		scanf(" %d%c", &coordinate, &temp);
		y = coordinate % 10;
		x = (coordinate / 10) % 10;
		z = (coordinate / 100) % 10;
		check += check_placement_valid(board, x, y, z);
		board[y][x] = 'D';
	}

	while (check != 0)
	{
		check = 0;
		temp = '\0';
		for (int a = 0; a < 10; a++)
		{
			for (int b = 0; b < 10; b++)
			{
				if (board[a][b] == 'D')
				{
					board[a][b] = '-';
				}

			}
		}
		printf("Invalid placement of ship. Please try again: ");
		while (temp != '\n')
		{
			scanf(" %d%c", &coordinate, &temp);
			y = coordinate % 10;
			x = (coordinate / 10) % 10;
			z = (coordinate / 100) % 10;
			check += check_placement_valid(board, x, y, z);
			board[y][x] = 'D';
		}

	}
}

/*-----------------------------------------------------------
* Function: check_placement_valid()
* Description: Checks if the user's unput coordinates are valid.
* Input parameters: Char board, x coordinate, y coordinate, 
					and possible z if input coordinate is too big.
* Returns: 1 if the coordinate is invalid and 0 if the coordinates 
		   are valid.
* Preconditions: None.
* Postconditions: 1 or 0 is returned.
-------------------------------------------------------------*/
int check_placement_valid(char board[10][10], int x, int y, int z)
{
	if (board[y][x] != '-' || z != 0) //if invalid
	{
		return 1;

	}
	else //if valid
	{
		return 0;
	}

}

/*-----------------------------------------------------------
* Function: randomly_place_ships()
* Description: Randomly places ships by determining the 
			   direction, randomly generating a start point, 
			   and checking if a ship would overlap.
* Input parameters: Char board of one player.
* Returns: None.
* Preconditions: None. 
* Postconditions: The ships have been randomly placed on the 
				  player's board.
-------------------------------------------------------------*/
void randomly_place_ships(char board[10][10])
{
	int axis = 0, x = 0, y = 0;

	//Carrier
	axis = rand() % 2;	//0 if horizontal and 1 if vertical
	

	if (axis == 0)
	{
		x = rand() % 6; //generate x position 0-5
		y = rand() % 10; //generate y position 0-9

		for (int loop = 0; loop < 5; loop++, x++)
		{
			board[y][x] = 'C';

		}
	}
	else
	{
		x = rand() % 10; //generate x position 0-9
		y = rand() % 6; //generate y position 0-5

		for (int loop = 0; loop < 5; loop++, y++)
		{
			board[y][x] = 'C';

		}

	}

	//Battleship
	axis = rand() % 2;	//0 if horizontal and 1 if vertical

	if (axis == 0) 
	{
		for(int found = 1; found > 0; ) //If a ship found, loop
		{
			found = 0; 

			do
			{
				x = rand() % 7;			//Keep generating new start point until on water.
				y = rand() % 10;

			} while (board[y][x] != '-');

			for (int index = 0; index < 4; index++)		//Search for any ships
			{
				if (board[y][x + index] != '-')
				{
					found += 1;
				}
			}

			if (found == 0)			//If no ships found, place new ship
			{
				for (int loop = 0; loop < 4; loop++, x++)
				{
					board[y][x] = 'B';
				}
			}
		}


	}
	else
	{
		for (int found = 1; found > 0; )
		{
			found = 0;

			do
			{
				x = rand() % 10;
				y = rand() % 7;

			} while (board[y][x] != '-');

			for (int index = 0; index < 4; index++)
			{
				if (board[y + index][x] != '-')
				{
					found += 1;
				}
			}

			if (found == 0)
			{
				for (int loop = 0; loop < 4; loop++, y++)
				{
					board[y][x] = 'B';
				}
			}
		}
	}

	//Cruiser
	axis = rand() % 2;	//0 if horizontal and 1 if vertical

	if (axis == 0)
	{
		for (int found = 1; found > 0; ) //If a ship found, loop
		{
			found = 0;

			do
			{
				x = rand() % 8;			//Keep generating new start point until on water.
				y = rand() % 10;

			} while (board[y][x] != '-');

			for (int index = 0; index < 3; index++)		//Search for any ships
			{
				if (board[y][x + index] != '-')
				{
					found += 1;
				}
			}

			if (found == 0)			//If no ships found, place new ship
			{
				for (int loop = 0; loop < 3; loop++, x++)
				{
					board[y][x] = 'R';
				}
			}
		}


	}
	else								//Same as above but for vertical ship
	{
		for (int found = 1; found > 0; )
		{
			found = 0;

			do
			{
				x = rand() % 10;
				y = rand() % 8;

			} while (board[y][x] != '-');

			for (int index = 0; index < 3; index++)
			{
				if (board[y + index][x] != '-')
				{
					found += 1;
				}
			}

			if (found == 0)
			{
				for (int loop = 0; loop < 3; loop++, y++)
				{
					board[y][x] = 'R';
				}
			}
		}
	}

	//Submarine

	axis = rand() % 2;	//0 if horizontal and 1 if vertical

	if (axis == 0)
	{
		for (int found = 1; found > 0; ) //If a ship found, loop
		{
			found = 0;

			do
			{
				x = rand() % 8;			//Keep generating new start point until on water.
				y = rand() % 10;

			} while (board[y][x] != '-');

			for (int index = 0; index < 3; index++)		//Search for any ships
			{
				if (board[y][x + index] != '-')
				{
					found += 1;
				}
			}

			if (found == 0)			//If no ships found, place new ship
			{
				for (int loop = 0; loop < 3; loop++, x++)
				{
					board[y][x] = 'S';
				}
			}
		}


	}
	else
	{
		for (int found = 1; found > 0; )
		{
			found = 0;

			do
			{
				x = rand() % 10;
				y = rand() % 8;

			} while (board[y][x] != '-');

			for (int index = 0; index < 3; index++)
			{
				if (board[y + index][x] != '-')
				{
					found += 1;
				}
			}

			if (found == 0)
			{
				for (int loop = 0; loop < 3; loop++, y++)
				{
					board[y][x] = 'S';
				}
			}
		}
	}

	//Destroyer
	axis = rand() % 2;	//0 if horizontal and 1 if vertical

	if (axis == 0)
	{
		for (int found = 1; found > 0; ) //If a ship found, loop
		{
			found = 0;

			do
			{
				x = rand() % 9;			//Keep generating new start point until on water.
				y = rand() % 10;

			} while (board[y][x] != '-');

			for (int index = 0; index < 2; index++)		//Search for any ships
			{
				if (board[y][x + index] != '-')
				{
					found += 1;
				}
			}

			if (found == 0)			//If no ships found, place new ship
			{
				for (int loop = 0; loop < 2; loop++, x++)
				{
					board[y][x] = 'D';
				}
			}
		}


	}
	else
	{
		for (int found = 1; found > 0; )
		{
			found = 0;

			do
			{
				x = rand() % 10;
				y = rand() % 9;

			} while (board[y][x] != '-');

			for (int index = 0; index < 2; index++)
			{
				if (board[y + index][x] != '-')
				{
					found += 1;
				}
			}

			if (found == 0)
			{
				for (int loop = 0; loop < 2; loop++, y++)
				{
					board[y][x] = 'D';
				}
			}
		}
	}

}

/*-----------------------------------------------------------
* Function: player_order()
* Description: Randomly generates 1 or 2 to determine player
			   order.
* Input parameters: None.
* Returns: Integer player order.
* Preconditions: None.
* Postconditions: 1 or 2 has been generated and the starting 
				  player has been printed.
-------------------------------------------------------------*/
int player_order()
{
	int order = 0;

	order = rand() % 2 + 1;

	if (order == 1)
	{
		printf("Player 1 goes first. \n");

	}
	if (order == 2)
	{
		printf("Player 2 goes first. \n");

	}

	return order;
}

/*-----------------------------------------------------------
* Function: choose_coordinate()
* Description: Allows player to choose what coordinate to shoot 
			   at.
* Input parameters: Pointers for x and y, and players char 
					board.
* Returns: None
* Preconditions: Input parameters are met and coordinate is 
				 input with a char between x and y. I.e. x,y.
* Postconditions: The statement has been printed and the 
				  coordinate has been logged.
-------------------------------------------------------------*/
void choose_coordinate(int* x, int* y, char board[10][10])
{
	char temp = '\n';
	do {
		printf("Enter what coordinate ((x,y)) you would like to shoot at: ");

		scanf("%d%c%d", x, &temp, y);

	} while (*x > 9 || *x < 0 || *y > 9 || *y < 0 || board[*y][*x] == '*' || board[*y][*x] == 'm'); //Display again if invalid shot.

}

/*-----------------------------------------------------------
* Function: random_shot()
* Description: Takes a random shot at a position that has not 
			   already been shot at.
* Input parameters: X and y pointers, and player's board.
* Returns: None
* Preconditions: None.
* Postconditions: The statement has been printed and a shot 
				  has been taken at the other player's board.
-------------------------------------------------------------*/
void random_shot(int* x, int* y, char board[10][10])
{
	do
	{
		*x = rand() % 10;
		*y = rand() % 10;
	} while (board[*y][*x] == '*' || board[*y][*x] == 'm');

	printf("Player 2 is taking a shot at %d,%d...\n", *x, *y);
	system("pause");
}

/*-----------------------------------------------------------
* Function: check_if_hit()
* Description: Checks if player has hit a ship, checks if the 
			   ship is sunk, and prints messages on the screen 
			   and outfile.
* Input parameters: Player's char board, x and y pointers, 
					order of the players (current player),
					and the outstream.
* Returns: 1 if a ship has been hit and 0 if it is a miss.
* Preconditions: Input parameters are met.
* Postconditions: Messages have been appropriately printed and 
				  1 or 0 is returned.
-------------------------------------------------------------*/
int check_if_hit(char board[10][10],int* x, int* y, int player_order, FILE *outstream)
{
	char ship = '\0';
	int found = 0;

	if (board[*y][*x] != '-')
	{
		
		system("cls");
		printf("Hit!\n\n");
		fprintf(outstream, "Player %d: Hit at %d,%d! ", player_order, *x, *y);  //Prints to battleship.log


		ship = board[*y][*x];		//Store ship type

		board[*y][*x] = '*';		//Board now shows a hit


		for (int a = 0; a < 10; a++)	//Search for other instances of the ship.
		{
			for (int b = 0; b < 10; b++)
			{
				if (board[a][b] == ship)
				{
					found++;
				}
			}

		}

		if (found == 0)	//If the whole ship is sunk, print statement.
		{
			if (ship == 'C')
			{
				printf("Carrier has been sunk!\n\n");
				fprintf(outstream, "Carrier has been sunk! \n");

			}
			if (ship == 'B')
			{
				printf("Battleship has been sunk!\n\n");
				fprintf(outstream, "Battleship has been sunk! \n");
			}
			if (ship == 'R')
			{
				printf("Cruiser has been sunk!\n\n");
				fprintf(outstream, "Cruiser has been sunk! \n");
			}
			if (ship == 'S')
			{
				printf("Submarine has been sunk!\n\n");
				fprintf(outstream, "Submarine has been sunk! \n");
			}
			if (ship == 'D')
			{
				printf("Destroyer has been sunk!\n\n");
				fprintf(outstream, "Destroyer has been sunk! \n");

			}

		}

		if (player_order == 1)		//If player 1 display player 2's board
		{
			display_board_2(board);
			system("pause");
			system("cls");
		}
		if (player_order == 2)		//If player 1 display player 1's board
		{
			display_board_1(board);
			system("pause");
			system("cls");
		}

		return 1;	//Hit

	}
	else
	{
		system("cls");
		printf("Miss!\n\n");
		fprintf(outstream, "Player %d: Missed at %d,%d. ", player_order, *x, *y);

		board[*y][*x] = 'm';		//Board now shows a miss

		if (player_order == 1)
		{
			display_board_2(board);
			system("pause");
			system("cls");
		}
		if (player_order == 2)
		{
			display_board_1(board);
			system("pause");
			system("cls");
		}

		return 0;		//Miss
	}

}

/*-----------------------------------------------------------
* Function: update_stats()
* Description: Keeps stats for each player with the number of 
			   hits, misses, and total shots taken.
* Input parameters: Stats stats pointer and status of hit or 
					miss.
* Returns: None
* Preconditions: Input parameters are met
* Postconditions: Number of hits, misses, and total shots 
				  appropriately increase.
-------------------------------------------------------------*/
void update_stats(Stats *stats_ptr, int status)
{
	if (status == 1) //hit
	{
		
		stats_ptr->number_hits++;

	}
	else //miss
	{

		stats_ptr->num_misses++;

	}

	stats_ptr->total_shots++;

}

/*-----------------------------------------------------------
* Function: check_if_win()
* Description: Checks if a player has won the game by counting 
*			   the number of *'s on the board.
* Input parameters: Player's board.
* Returns: 0 if game ends and a player has won, or -1 if
*		   the game continues,
* Preconditions: None.
* Postconditions: -1 or 0 has been returned once 17 stars are 
*				  present.
-------------------------------------------------------------*/
int check_if_win(char board[10][10])
{
	int found = 0;

	for (int a = 0; a < 10; a++)	//Search for instances of a hit
	{
		for (int b = 0; b < 10; b++)
		{
			if (board[a][b] == '*')
			{
				found++;
			}
		}

	}
	if (found == 17)	//If all ships are hit, initiate win.
	{
		return 0;
	}
	else				//Otherwise, continue game.
	{
		return -1;
	}

}

/*-----------------------------------------------------------
* Function: final_statement()
* Description: Prints final winning statement.
* Input parameters: Int player who won.
* Returns: None.
* Preconditions: None.
* Postconditions: The winning statement has been printed.
-------------------------------------------------------------*/
void final_statement(int winner)
{
	system("cls");
	printf("Congrats Player %d! You won!\n\n", winner);

}

/*-----------------------------------------------------------
* Function: print_stats()
* Description: Calculates the hits to miss ratio and prints 
			   the final stats for the game onto outfile.
* Input parameters: Stats pointer for player 1 and 2, outfile, 
					and number of winning player.
* Returns: None.
* Preconditions: Input parameters have been met.
* Postconditions: Stats have been correctly calculated and 
				  are printed onto the outfile.
-------------------------------------------------------------*/
void print_stats(Stats* stats_ptr1, Stats* stats_ptr2, FILE *outfile, int winner)
{
	stats_ptr1->hits_misses_ratio = ((double)stats_ptr1->number_hits / (double)stats_ptr1->total_shots) * 100;
	stats_ptr2->hits_misses_ratio = ((double)stats_ptr2->number_hits / (double)stats_ptr2->total_shots) * 100;


	fprintf(outfile, "\n\nStats for the final game:\n\n");

	fprintf(outfile, "Player %d won!\n\n", winner);

	fprintf(outfile, "Player 1: %d shots, %d hits, %d misses.\n", stats_ptr1->total_shots, stats_ptr1->number_hits, stats_ptr1->num_misses);
	fprintf(outfile, "Hit to miss ratio: %.2lf percent\n\n", stats_ptr1->hits_misses_ratio);

	fprintf(outfile, "Player 2: %d shots, %d hits, %d misses.\n", stats_ptr2->total_shots, stats_ptr2->number_hits, stats_ptr2->num_misses);
	fprintf(outfile, "Hit to miss ratio: %.2lf percent", stats_ptr2->hits_misses_ratio);

	printf("Final statistics printed to battleship.log successfully.");

}

/*-----------------------------------------------------------
* Function: play_battleship()
* Description: Runs the game battleship.
* Input parameters: None
* Returns: None
* Preconditions: Other required functions are present and
				 functioning.
* Postconditions: The game of battleship is played, stats are 
				  logged, and a winner is announced.
-------------------------------------------------------------*/

void play_battleship()
{
	char board_p1[10][10], board_p2[10][10];
	Stats stats_p1 = { 0 , 0 , 0 , 0.0 }, stats_p2 = { 0 , 0 , 0 , 0.0 };
	int order_player = 0, x_shot = 0, y_shot = 0, placing_choice = 0, status = 0, win_status = 0, winner = 0;
	FILE* outstream = fopen("battleship.log", "w");

	srand((unsigned int)time(NULL));


	print_main_screen();

	initialize_game_board(board_p1);
	initialize_game_board(board_p2);


	placing_choice = print_placement_choice(); //User chooses if they would like to randomly place ships or place them themselves.

	if (placing_choice == 1)
	{
		manually_place_ships(board_p1);

	}
	if (placing_choice == 2)
	{
		randomly_place_ships(board_p1);

	}

	randomly_place_ships(board_p2);		//Randomly places the ships for player 2
	display_board_1(board_p1);			//Shows player 1 their board
	system("pause");
	system("cls");

	order_player = player_order();		//Chooses who goes first

	while (winner == 0)			//While there is no winner, continue game.
	{

		if (order_player == 1)
		{
			display_board_2(board_p2);
			choose_coordinate(&x_shot, &y_shot, board_p2);			
			status = check_if_hit(board_p2, &x_shot, &y_shot, order_player, outstream);	//Player chooses coords, checks if hit/miss,
			update_stats(&stats_p1, status);											//updates stats, and checks if win.
			win_status = check_if_win(board_p2);

			if (win_status == 0)		//If no ships left, the winner is now player 1.
			{
				winner = 1;
			}

			if (winner == 0)		//If no winner, go to player 2
			{
				order_player = 2;
			}
		}
		if (order_player == 2)
		{
			random_shot(&x_shot, &y_shot, board_p1);		
			status = check_if_hit(board_p1, &x_shot, &y_shot, order_player, outstream);		//Random shot is made by player 2, checks if hit/miss,
			update_stats(&stats_p2, status);												//updates stats, and checks if win.
			win_status = check_if_win(board_p1);

			if (win_status == 0)			//If no ships left, winner is player 2
			{
				winner = 2;
			}
			if (winner == 0)				//If no winner, go to player 1.
			{
				order_player = 1;
			}
		}
	}

	final_statement(winner);
	print_stats(&stats_p1, &stats_p2, outstream, winner);	//Prints final statement and stats to the log.

	fclose(outstream);
}