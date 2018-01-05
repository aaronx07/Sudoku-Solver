#include <iostream>
#include <fstream>
#include <string>
#include "sudoku.hpp"
class OutOfBounds{};
using namespace std;

/**Constructs with input file based off string*/
Sudoku::Sudoku(string& s)
{
  col=9;
  row=9;
  int num;
  char hold;
  ifstream input;

  input.open(s);
  if(input.is_open())
    {
      for(int i=0;i<row;i++)
      {

        for(int t=0;t<col;t++)
        {
          input>>hold;
          num=convertn(hold); //Calls for ASCII to Int conversions
          puzzle[i][t]=num;
        }
      }
    }

input.close(); //Closes file
}


/**Converts ASCII to int*/
int Sudoku::convertn(char h)
{
  int num_check=0;
  num_check=int(h);

  /**Switch Statement for conversions*/
    switch (num_check)
    {
      case 42 :
      num_check=0;
      break;

      case 49 :
      num_check=1;
      break;

      case 50 :
      num_check=2;
      break;

      case 51 :
      num_check=3;
      break;

      case 52 :
      num_check=4;
      break;

      case 53 :
      num_check=5;
      break;

      case 54 :
      num_check=6;
      break;

      case 55 :
      num_check=7;
      break;

      case 56 :
      num_check=8;
      break;

      case 57 :
      num_check=9;
      break;
    }

return num_check; //Returns int
}


//Saves to output file
void Sudoku::Save(string& s)
{
   ofstream output;
   output.open(s);
      if(output.is_open())
      {
        for(int i=0;i<row;i++)
        {
          for(int t=0;t<col;t++)
          {
            if(puzzle[i][t]==0)
            {
              output<<'*';
            }
            else
            {
              output<<puzzle[i][t];
            }

          }
          output<<endl;

        }

    output.close();
  }
}

//Overloaded output
ostream &operator<<(ostream &out, const Sudoku& a)
{
  for(int i=0;i<a.row;i++)
    {
      for(int t=0;t<a.col;t++)
        {
          //determines when to output asterisk
          if(a.puzzle[i][t]==0)
            {
              out<<'*';
            }

          else
            {
            out<<a.puzzle[i][t];
            }
        }

        out<<endl;
    }

        return out;
  }



/**Accesses Grid Values at specific index*/
int Sudoku::operator()(const int& x, const int& y)
{
  try
  {
    if(x>0 && x<10 && y>0 && y<10)
    {
      int temp=0;
      temp=puzzle[x-1][y-1];
      return temp;
    }

    else
    {
      throw OutOfBounds();
    }
  }

  catch (OutOfBounds)
  {
    cout << "OutOfBounds";
    return 0;
  }
}

/**Calls fill puzzle with appropriate member data.*/
void Sudoku::Solve()
{
fill_puzzle(puzzle, 0, 0);
}

/**Fills puzzle and checks for issues.*/
bool Sudoku::fill_puzzle(int puzzle[][9], int row, int col)
{
    //Finds next row
    int next_row = (col == 9 - 1) ? row + 1 : row;

    // Finds next Col
    int next_col = (col + 1) % (9);

    // Returns true if solved
    if(row == 9)
        return true;

    //Checks if we can change the current number
    if(puzzle[row][col] != NONE)
        return fill_puzzle(puzzle, next_row, next_col);

    // Finds value that can fit
    for(int value = 1; value <= 9; value++)
    {
        puzzle[row][col] = value;


        if(is_legal(puzzle, row, col, value) && fill_puzzle(puzzle, next_row, next_col))
            return true;

        puzzle[row][col] = NONE;
    }

    // None of the values solved the sudoku.
    return false;
}

//Checks if value is legal for specific index.
bool Sudoku::is_legal(const int puzzle[][9], int row, int col, int val)
{
    return (check_row(puzzle[row], col, val) &&
            check_column(puzzle, row, col, val) &&
            check_sqr(puzzle, row, col, val));
}

//Checks column and returns true if number can be placed.
bool Sudoku::check_column(const int puzzle[][9], int row, int col, int val)
{
  for(int i = 0; i < 9; i++)
      if(i != row && puzzle[i][col] == val)
      return false;

      return true;
}
//Checks row and returns true if number can be placed.
bool Sudoku::check_row(const int row[], int col, int val)
{
    for(int i = 0; i < 9; i++)
      if(i != col && row[i] == val)
        return false;  // if it finds the same value

        return true;
}



//Makes sure number is okay for 3x3 square
bool Sudoku::check_sqr(const int puzzle[][9], int row, int col, int val)
{
    int row_corner = (row / 3) * 3;

    int col_corner = (col / 3) * 3;

    for(int i = row_corner; i < (row_corner + 3); i++)
    for(int j = col_corner; j < (col_corner + 3); j++)

    //Returns false for same value
        if((i != row || j != col) && puzzle[i][j] == val)
          return false;

    return true;
}
