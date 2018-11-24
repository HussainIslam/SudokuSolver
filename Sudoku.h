#ifndef _HUSSAIN_SUDOKU_H_
#define _HUSSAIN_SUDOKU_H_

namespace hussain{
  class Sudoku {
    int cells [9] [9];
    bool permanent [9][9];
    int possibilities [9][9][9];

    public:
    Sudoku();
    ~Sudoku();
    std::istream& input(std::istream& is);
    std::ostream& display(std::ostream& os) const ;
    bool checkHorizontal();
    bool checkVertical();
    bool checkInBox();
    bool onlyPossibility();
    bool validity();

  };

  std::istream& operator>>(std::istream& is, Sudoku& sudoku);
  std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku);

}

#endif