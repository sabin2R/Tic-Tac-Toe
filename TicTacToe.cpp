#include <iostream>
#include <limits>
using namespace std;

void displayWelcomeScreen()
{
  cout << "\033[2J\033[1;1H"; // Clear console screen
  cout << "***********************************************" << endl;
  cout << "              Welcome to Tic Tac Toe             " << endl;
  cout << "***********************************************" << endl
       << endl;
  cout << "Press any key to continue..." << endl;
  cin.get();
}

void displayInstructions()
{
  cout << "\033[2J\033[1;1H"; // Clear console screen
  cout << "***********************************************" << endl;
  cout << "                 Instructions                    " << endl;
  cout << "***********************************************" << endl
       << endl;
  cout << "Tic Tac Toe is a game for two players, X and O, who take turns marking the spaces in a 3x3 grid." << endl;
  cout << "The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row wins the game." << endl
       << endl;
  cout << "Players take turns to mark a cell in the grid by entering its row and column numbers." << endl;
  cout << "The rows and columns are numbered from 1 to 3." << endl
       << endl;
  cout << "Press any key to start the game..." << endl;
  cin.get();
}

void displayBoard(char board[][3])
{
  cout << "\033[2J\033[1;1H"; // Clear console screen
  cout << "   1   2   3" << endl;
  cout << "1  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << endl;
  cout << "  ---+---+---" << endl;
  cout << "2  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << endl;
  cout << "  ---+---+---" << endl;
  cout << "3  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << endl;
}

void displayReward(char player)
{
  cout << "Congratulations, Player " << player << "! You have won the game" << endl;
}

bool checkWin(char board[][3], char player)
{
  // Check rows
  for (int i = 0; i < 3; i++)
  {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
    {
      return true;
    }
  }

  // Check columns
  for (int j = 0; j < 3; j++)
  {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
    {
      return true;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
  {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
  {
    return true;
  }

  // No win found
  return false;
}

bool checkDraw(char board[][3])
{
  // Check if any empty cells remain
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] == ' ')
      {
        return false;
      }
    }
  }

  // All cells are filled
  return true;
}

int main()
{
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  char currentPlayer = 'X';

  displayWelcomeScreen();
  displayInstructions();

  while (true)
  {
    displayBoard(board);

    // Get player's move
    int row, col;
    cout << "Player " << currentPlayer << ", enter row and column numbers (e.g. 1 2): ";
    cin >> row >> col;

    // Validate move
    if (row < 1 || row > 3 || col < 1 || col > 3)
    {
      cout << "Invalid input. Row and column numbers must be between 1 and 3. Try again." << endl;
      if (!(cin >> row >> col))
      { // Check if input is valid
        cout << "Invalid input. Please enter numbers only." << endl;
        cin.clear();                                         // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        continue;
      }
    }
    // validate move
    if (row < 1 || row > 3 || col < 1 || col > 3)
    {
      cout << "Invalid input. Row and column numbers must be between 1 and 3. Try again." << endl;
      continue;
    }
    if (board[row - 1][col - 1] != ' ')
    {
      cout << "Cell is already occupied. Try again." << endl;
      continue;
    }

    // Mark cell with player's symbol
    board[row - 1][col - 1] = currentPlayer;

    // Check for win or draw
    if (checkWin(board, currentPlayer))
    {
      displayBoard(board);

      break;
    }
    if (checkDraw(board))
    {
      displayBoard(board);
      cout << "Draw!" << endl;
      break;
    }

    // Switch to the other player
    if (currentPlayer == 'X')
    {
      currentPlayer = 'O';
    }
    else
    {
      currentPlayer = 'X';
    }
  }
  if (checkWin(board, currentPlayer))
  {
    displayBoard(board);
    displayReward(currentPlayer); // Call the displayReward function
  }
  return 0;
}
