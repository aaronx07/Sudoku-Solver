#include <iostream>
#include <string>
#include <fstream>
#include "sudoku.hpp"
using namespace std;

int main()
{
string infile; //Input string.

//Sets input to sample
cout << "Enter puzzle name \n";
cin >> infile;

Sudoku test(infile);
cout << "Unsolved Puzzle: \n";
cout << test;
//Solves Sudoku
test.Solve();
//Saves Solved Sudoku Puzzle
string save;
save = "save.txt";
test.Save(save);
//Outputs with overloaded << operator
cout << "Solved Puzzle \n";
cout << test;
}
