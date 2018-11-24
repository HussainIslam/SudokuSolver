#include <iostream>
#include <iomanip>
#include "Sudoku.h"
using namespace std;

namespace hussain{
  Sudoku::Sudoku(){
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        cells[i][j] = 0;
        permanent[i][j] = false;
        for(int k = 0; k < 9; k++){
          possibilities[i][j][k] = k+1;
        }
      }
    }

  }
  
  Sudoku::~Sudoku() {}

  std::istream& Sudoku::input(std::istream& is){
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        is >> cells[i][j];
        if(cells[i][j] != 0){
          permanent[i][j] = true;
          for(int k = 0; k < 9; k++){
            possibilities[i][j][k] =0;
          }
        }
      }
    }
    return is;
  }

  std::ostream& Sudoku::display(std::ostream& os) const {
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++){
        os << setw(3);
        os << cells[i][j];
      }
      os << endl;
    }
    return os;
  }

  bool Sudoku::checkHorizontal() {

  }

  bool Sudoku::checkVertical(){
    
  }

  bool Sudoku::checkInBox() {

  }

  bool Sudoku::onlyPossibility() {

  }

  bool Sudoku::validity(int number, int hPosition, int vPosition) {

  }

  std::istream& operator>>(std::istream& is, Sudoku& sudoku) {
    sudoku.input(is);
    return is;
  }

  std::ostream& operator<<(std::ostream& os, const Sudoku& sudoku) {
    sudoku.display(os);
    return os;
  }

}
