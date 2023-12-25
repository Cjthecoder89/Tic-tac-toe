#include <string>

using namespace std;

// Function Prototypes
void DisplayIntro(void);
void InitializeGame(bool& gameOver, char& playerSymbol, string& pos1, string& pos2, string& pos3, string& pos4, string& pos5, string& pos6, string& pos7, string& pos8, string& pos9);
void DisplayGameBoard(string pos1, string pos2, string pos3, string pos4, string pos5, string pos6, string pos7, string pos8, string pos9);
char GetValidUserInput(char playerSymbol, string pos1, string pos2, string pos3, string pos4, string pos5, string pos6, string pos7, string pos8, string pos9, string playername[], int indicator);
void SetGameBoardPosition(int posLocation, char playerSymbol, string& pos1, string& pos2, string& pos3, string& pos4, string& pos5, string& pos6, string& pos7, string& pos8, string& pos9);
bool CheckForGameOver(char& playerSymbol, string pos1, string pos2, string pos3, string pos4, string pos5, string pos6, string pos7, string pos8, string pos9,int count, int& adder, int& indicator, string player[], int points[], int wins[], int ties[], int losses[],int p1, int p2);
void UpdatePlayer(char& playerSymbol, int& indicator);
char RequestAdditionalGame(void);
void DisplayCredits(void);


//---------------------------------------------------------------------------------------
//Added prototypes
//---------------------------------------------------------------------------------------
void displaymenu(int& selection);
void displaystats(string playername[], int points[], int wins[], int ties[], int losses[], int count);
void names(string playername[], int& count, int& adder, char& playagain, int points[], int wins[], int ties[], int losses[],int& p1,int& p2);
void loadstats(string playername[], int points[], int wins[], int ties[], int losses[], int& count);
void writedata(int count, string playername[], int points[], int wins[], int ties[], int losses[]);
//---------------------------------------------------------------------------------------
//constants
//---------------------------------------------------------------------------------------
const int MAX_PLAYERS = 10;