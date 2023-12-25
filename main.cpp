// Program:	TicTacToe with loops
// Date:	??
// Author:  Yours Truly

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> 
#include "main.h"

using namespace std;

int main(void)
{
	int decision = 0, points[MAX_PLAYERS], wins[MAX_PLAYERS], ties[MAX_PLAYERS], losses[MAX_PLAYERS], count = 0, indicator = -1, adder = 0,scorecount = 0,p1 = -2, p2 = -2;
	bool gameOver = false, running = true;		      // game loop control flag
	char posLocation;				  // user input variable for position choice
	char playAgain = 'A';			  // program exit control flag
	char playerSymbol = 'X';		  // current player symbol
	string pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9;  // board display variables
	string playername[MAX_PLAYERS];

	DisplayIntro();
	while (running)
	{
		//loadstats(playername, points, wins, ties, losses, count);
		displaymenu(decision);
		if (decision == 1)
		{
			while (adder != 2)
			{
				names(playername, count, adder, playAgain,points,wins,ties,losses,p1,p2);
				indicator++;
			}


			while (playAgain == 'A')
			{
				InitializeGame(gameOver, playerSymbol, pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9);   // Initializes the game board
				DisplayGameBoard(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9);                         // Displays the game board

				while (!gameOver)			                                                                        //  Loop until a winner is determined or all squars have been used
				{
					posLocation = GetValidUserInput(playerSymbol, pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, playername, indicator);    // Get vaild user inpur
					SetGameBoardPosition(posLocation, playerSymbol, pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9);  // Set the appropriate board position
					DisplayGameBoard(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9);                                 // Display the game board
					gameOver = CheckForGameOver(playerSymbol, pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9,count, adder, indicator,playername,points,wins,ties,losses,p1,p2);        // Check for end of game condition and change the player symbol
				}
				playAgain = RequestAdditionalGame();   // Determine whether to play the game again
			}

		}
		else if (decision == 2)
		{
			displaystats(playername, points, wins, ties, losses, count);
			system("pause");
		}
		else if (decision == 3)
		{
			writedata(count,playername,points,wins,ties,losses);
		}
		else if (decision == 4)
		{
			running = false;
		}
	}


	DisplayCredits();                         // Display the credit screen
	return 0;
}
//---------------------------------------------------------------------------------------
char RequestAdditionalGame(void)
{
	char userEntry;

	cout << "Enter \"A\" to play again, any other key to exit: " << endl << endl;		// getting user input for whether the player wants to play again
	cin >> userEntry;
	userEntry = toupper(userEntry);
	cout << endl << endl;

	return(userEntry);
}

//---------------------------------------------------------------------------------------
void UpdatePlayer(char& playerSymbol, int& indicator)
{
	if (playerSymbol == 'O')			// alternating between the X and O player
	{
		indicator = indicator - 1;
		playerSymbol = 'X';
	}

	else
	{
		indicator = indicator + 1;
		playerSymbol = 'O';
	}

}

//---------------------------------------------------------------------------------------
bool CheckForGameOver(char& playerSymbol, string pos1, string pos2, string pos3, string pos4, string pos5, string pos6, string pos7, string pos8, string pos9,int count, int& adder, int& indicator,string player[], int points[], int wins[], int ties[], int losses[],int p1,int p2)
{
	if ((pos1 == pos2 && pos1 == pos3) || (pos4 == pos5 && pos4 == pos6) || (pos7 == pos8 && pos7 == pos9) ||  // checking game victory conditions
		(pos1 == pos4 && pos1 == pos7) || (pos2 == pos5 && pos2 == pos8) || (pos3 == pos6 && pos3 == pos9) ||
		(pos1 == pos5 && pos1 == pos9) || (pos3 == pos5 && pos3 == pos7))
	{
		cout << endl << "Player " << player[indicator] << " wins!!  Whoohooo!!" << endl << endl << endl;
		adder = 0;
		if (indicator = p1)
		{
			wins[p1]++;
			losses[p1 - 1] + 1;
			cout << losses[p1 - 1] << " " << p1 << " " << p2 << " ";
			points[p1] = wins[p1] * 2 + ties[p1];
		}
		else if (indicator = p1 - 1)
		{
			wins[p2]++;
			losses[p1]++;
			points[p2] = wins[p2] * 2 + ties[p2];
		}
		return true;
	}
	else if (pos1 != "1" && pos2 != "2" && pos3 != "3" && pos4 != "4" && pos5 != "5" && pos6 != "6" && pos7 != "7" && pos8 != "8" && pos9 != "9")
	{
		cout << endl << "It's a draw!! Get'em next time." << endl << endl << endl;
		ties[p1] + 1;
		ties[p2] + 1;
		adder = 0;
		return true;
	}
	else
	{
		UpdatePlayer(playerSymbol, indicator);
		return false;
	}
}

//---------------------------------------------------------------------------------------
void SetGameBoardPosition(int posLocation, char playerSymbol, string& pos1, string& pos2, string& pos3, string& pos4, string& pos5, string& pos6, string& pos7, string& pos8, string& pos9)
{
	if (posLocation == '1')			// setting game variable based on the user input value
		pos1 = playerSymbol;
	else if (posLocation == '2')
		pos2 = playerSymbol;
	else if (posLocation == '3')
		pos3 = playerSymbol;
	else if (posLocation == '4')
		pos4 = playerSymbol;
	else if (posLocation == '5')
		pos5 = playerSymbol;
	else if (posLocation == '6')
		pos6 = playerSymbol;
	else if (posLocation == '7')
		pos7 = playerSymbol;
	else if (posLocation == '8')
		pos8 = playerSymbol;
	else if (posLocation == '9')
		pos9 = playerSymbol;
}

//---------------------------------------------------------------------------------------
char GetValidUserInput(char playerSymbol, string pos1, string pos2, string pos3, string pos4, string pos5, string pos6, string pos7, string pos8, string pos9, string playername[], int indicator)
{
	bool validInput = false;
	char entry;

	while (!validInput)
	{
		cout << playername[indicator] << " Enter the location number where you want to place an \"" << playerSymbol << "\": ";
		cin >> entry;		// getting user input for the board position
		if (entry >= '1' && entry <= '9')
		{

			if ((entry == '1' && pos1 == "1") || (entry == '2' && pos2 == "2") || (entry == '3' && pos3 == "3") ||
				(entry == '4' && pos4 == "4") || (entry == '5' && pos5 == "5") || (entry == '6' && pos6 == "6") ||
				(entry == '7' && pos7 == "7") || (entry == '8' && pos8 == "8") || (entry == '9' && pos9 == "9"))
			{
				validInput = true;
			}
			else
			{
				cout << playername[indicator] << " You have entered a position that has already been used. ";
				validInput = false;
			}
		}
		else
		{
			cout << playername[indicator] << " You have entered an incorrect value.  Please enter a number from 1 to 9. ";
		}
		cout << endl << endl;
	}
	return entry;
}

//---------------------------------------------------------------------------------------
void InitializeGame(bool& gameOver, char& playerSymbol, string& pos1, string& pos2, string& pos3, string& pos4, string& pos5, string& pos6, string& pos7, string& pos8, string& pos9)
{
	gameOver = false;			// initializing game variables
	playerSymbol = 'O';
	pos1 = "1";
	pos2 = "2";
	pos3 = "3";
	pos4 = "4";
	pos5 = "5";
	pos6 = "6";
	pos7 = "7";
	pos8 = "8";
	pos9 = "9";
}

//---------------------------------------------------------------------------------------
void DisplayIntro(void)
{
	cout << "**************************************************" << endl;
	cout << "                   Welcome to                    *" << endl;
	cout << "               Awesome Tic Tac Toe               *" << endl;
	cout << "               Finally Woot Woot!!               *" << endl;
	cout << "**************************************************" << endl;
	cout << endl << endl;
	system("pause");
	cout << endl << endl;
}

//---------------------------------------------------------------------------------------
void DisplayGameBoard(string pos1, string pos2, string pos3, string pos4, string pos5, string pos6, string pos7, string pos8, string pos9)
{
	system("cls");

	cout << " " << pos1 << " | " << pos2 << " | " << pos3 << endl;		// displaying the initial game board
	cout << "----------" << endl;
	cout << " " << pos4 << " | " << pos5 << " | " << pos6 << endl;
	cout << "----------" << endl;
	cout << " " << pos7 << " | " << pos8 << " | " << pos9 << endl;
	cout << endl;
}

//---------------------------------------------------------------------------------------
void DisplayCredits(void)
{
	system("cls");

	cout << endl << endl;
	cout << "*************  CREDITS  *************" << endl;			// displaying the game credits
	cout << "    Designer: Me                    *" << endl;
	cout << "    Programmer: Me                  *" << endl;
	cout << "    Art Production: Me              *" << endl;
	cout << "    Everything Else: All Me         *" << endl;
	cout << "*************************************" << endl;
	cout << endl << endl;
	system("pause");
}

//---------------------------------------------------------------------------------------
//Added Functions
//---------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------
//Displays the menu of the game of course
//---------------------------------------------------------------------------------------
void displaymenu(int& selection)
{
	system("cls");
	cout << "------------- Main Menu -------------" << endl;
	cout << "1: Enter 1 to play TicTacToe (2 player)." << endl;
	cout << "2: Enter 2 to display all player stats." << endl;
	cout << "3: Enter 3 to write all player records to a file." << endl;
	cout << "4: Enter 4 to exit." << endl;

	cout << "Selection: ";
	cin >> selection;
	if (selection > 4 || selection < 1)
	{
		cout << "Incorrect input, please try again. (Use 1-4)" << endl;
		cout << "Selection: ";
		cin >> selection;
	}
}

//---------------------------------------------------------------------------------------
//Displays the player stats
//---------------------------------------------------------------------------------------
void displaystats(string playername[], int points[], int wins[], int ties[], int losses[], int count)
{
	system("cls");
	if (count > 0)
	{
		cout << " ------------------------------------------- Player Stats ------------------------------------------- " << endl;
		cout << "Player";
		cout << "	|";
		cout << "		Points";
		cout << "	|";
		cout << "		Wins";
		cout << "	|";
		cout << "		losses";
		cout << "	|";
		cout << "		ties" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		loadstats(playername, points, wins, ties, losses, count);
		for (int i = 0; i < count; i++)
		{
			cout << setw(1) << playername[i];  
			cout << setw(20) << points[i];
			cout << setw(20) << wins[i]; 
			cout << setw(29) << ties[i]; 
			cout << setw(35) << losses[i] << endl; 

		}
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	}
	else
	{
		system("cls");
		cout << " ------------------------------------------- Player Stats ------------------------------------------- " << endl;
		cout << "Player";
		cout << "	|";
		cout << "		Points";
		cout << "	|";
		cout << "		Wins";
		cout << "	|";
		cout << "		losses";
		cout << "	|";
		cout << "		ties" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	}
}


void loadstats(string playername[], int points[], int wins[], int ties[], int losses[], int& count)
{
	ifstream inFile;    				// Step 2 - declare your stream type variable

	inFile.open("stats.txt");  		// Step 3 - open the desired file
	if (inFile.is_open())				// check if the file opened
	{
		while (!inFile.eof() && count < MAX_PLAYERS)	// loop until the end of file or we max out on our array size
		{
			inFile >> setw(1) >> playername[count];
			inFile >> setw(20) >> points[count];
			inFile >> setw(20) >> wins[count];
			inFile >> setw(29) >> ties[count];
			inFile >> setw(35) >> losses[count];	// Step 4 - read line into a variable
			count = count + 1;					// increase the counter variable
		}
	}
	inFile.close();
}
//---------------------------------------------------------------------------------------
//Asks the user for their call sign (aka name)
//---------------------------------------------------------------------------------------
void names(string playername[], int& count, int& adder, char& playagain, int points[], int wins[], int ties[], int losses[],int& p1,int& p2)
{

	if (count < MAX_PLAYERS - 1)
	{
		cout << "Please enter a call sign: ";
		cin >> playername[count];
		p1++;
		p2 = p1 + 1;
		cout << p1 << " " << p2;
		losses[count] = 0;
		wins[count] = 0;
		ties[count] = 0;
		points[count] = 0;
		adder++;
		count++;
		playagain = 'A';
	}
	else
	{
		cout << "Maximum players reached." << endl;
	}


}

void writedata(int count, string playername[], int points[], int wins[], int ties[], int losses[])
{
	ofstream outFile;				// file output stream variable

	outFile.open("stats.txt");  // open the file
	if (outFile.is_open())			// if the attempt to open the file was successful start processing the contents
	{
		for (int i = 0; i < count; i++)
		{
			outFile << playername[i] << " " << points[i] << " " << wins[i] << " " << losses[i] << " " << ties[i] << endl;
		}
	}

	cout << "Data succesfully written." << endl;
	outFile.close();                   // close the opened file
	system("pause");
}