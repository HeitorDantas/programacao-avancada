#include "Screen.h"

Screen::Screen(int nlin, int ncol);

void Screen::setPixel(int x, int y);

void Screen::clear();

void Screen::setBrush(char brush){
  this->brush = brush;
}

friend ostream& operator<<(ostream &os, Screen &t);
