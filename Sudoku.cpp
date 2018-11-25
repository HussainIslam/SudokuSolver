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
    bool valid;
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        do{
          cout << "Please enter number for " << i+1 <<"th row and " << j+1 << "th column: ";
          is >> cells[i][j];
          cout << !validity(cells[i][j], i, j); 
        }while(validity(cells[i][j], i, j));
        if(cells[i][j] != 0){
          permanent[i][j] = true;
          for(int k = 0; k < 9; k++){
            possibilities[i][j][k] = 0;
          }
        }
      }
    }
    return is;
  }

  std::ostream& Sudoku::display(std::ostream& os) const {
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++){
        os << setw(4);
        os << cells[i][j];
      }
      os << endl;
    }
    return os;
  }

  bool Sudoku::checkHorizontal(int number, int vPosition) {
    bool valid = true;
    for(int hPos = 0; hPos < 9; hPos++){
      if(cells[vPosition][hPos] == number){
        valid = false;
      }
    }
    return valid;
  }

  bool Sudoku::checkVertical(int number, int hPosition){
    bool valid = true;
    for(int vPos = 0; vPos < 9; vPos++){
      if(cells[vPos][hPosition] == number){
        valid = false;
      }
    }
    return valid;
  }

  bool Sudoku::checkInBox(int number, int hPosition, int vPosition) {
    int minHPos;
    int maxHPos;
    int minVPos;
    int maxVPos;
    bool valid = true;

    minHPos = hPosition - (hPosition % 3);
    minVPos = vPosition - (vPosition % 3);
    maxHPos = minHPos + 3;
    maxVPos = minVPos + 3;

    for(int i = minHPos; i < maxHPos; i++){
      for(int j = minVPos; j < maxVPos; j++){
        if(cells[i][j] == number){
          valid = false;
        }
      }
    }
    return valid;
  }

  bool Sudoku::onlyPossibility() {

  }

  bool Sudoku::validity(int number, int hPosition, int vPosition) {
    bool horizontal = checkHorizontal(number, vPosition);
    bool vertical = checkVertical(number, hPosition);
    bool box = checkInBox(number, hPosition, vPosition);
    return horizontal * vertical * box;
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
