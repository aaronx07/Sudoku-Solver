#include <string>
class Sudoku{

  public:

    Sudoku(std::string&);
    int convertn(char h);
    void Save(std::string&);
    friend std::ostream &operator<<(std::ostream &os, const Sudoku&);
    int operator()(const int&, const int&);

    //Solves Puzzle
    void Solve();

    //Boolean that fills out puzzles
    bool fill_puzzle(int sud[][9], int row, int col);
    //Checks for possibilities
    bool check_sqr(const int sud[][9], int row, int col, int val);
    bool check_row(const int row[], int col, int val);
    bool check_column(const int sud[][9], int row, int col, int val);
    bool is_legal(const int sud[][9], int row, int col, int val);



  private:
    int puzzle[9][9];
    const int NONE = 0;
    int row;
    int col;
    int box;
};
