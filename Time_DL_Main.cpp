// Copyright 2020 <Diana Lukashuk>
#include <iostream>
#include <fstream>
#include <clocale>
#include "complex.h"
#include "Time_DL_Header.h"
using namespace std;

int main() {
  clock_t start, stop;
  int i = 0;
  cout << "Class time" << endl;
  Time a(1, 7, 0);
  Time b(1, 2, 0), c;

  start = clock();
  while (i != 4) {
    switch (i) {
    case 0:
      cout << " ________________ " << endl;
      cout << "| Make a choice  |" << endl;
      cout << "|1- Manual entery|" << endl;
      cout << "|2- Random input |" << endl;
      cout << "|3- Guick check  |" << endl;
      cout << "|4- Exit         |" << endl;
      cout << "|________________|" << endl;
      cin >> i;
      break;
    case 1:
      cout << "Enter ferst time: ";
      cin >> a;
      cout << "Enter second time: ";
      cin >> b;
      cout << "Entered time: " << a << ", " << b <<endl;
      i = 5;
      break;
    case 2:
      a.rand();
      i = 5;
      b.rand();
      cout << "Random time: " << a << ", " << b << endl;
      break;
    case 3:
      cout << "Time A " << a << ", Time B " << b << endl;
      cout << "Time A + B = " << a + b << endl;
      cout << "Time A - B = " << a - b << endl;
      cout << "A < B = " << (a < b);
      cout << "   A <= B = " << (a <= b) << endl;
      cout << "A > B = " << (a > b);
      cout << "   A >= B = " << (a >= b) << endl;
      cout << "(A == B) = " << (a == b);
      cout << "   (A != B) = " << (a != b) << endl;
      i = 0;
      break;
    case 5:
      cout << " ________________ " << endl;
      cout << "| Make a choice  |" << endl;
      cout << "|1- Compare      |" << endl;
      cout << "|2- A + B        |" << endl;
      cout << "|3- A - B        |" << endl;
      cout << "|4- Exit         |" << endl;
      cout << "|5- Step back    |" << endl;
      cout << "|________________|" << endl;
      cin >> i;
      if (i == 5) i = 0;
      if (i == 3) {
        cout << "Time A - B = " << a - b << endl;
        i = 5;
      }
      if (i == 2) {
        cout << "Time A + B = " << a + b << endl;
        i = 5;
      }
      if (i == 1) {
      if (a == b) cout << "A == B";
      if (a != b) cout << "A != B";
      cout << endl;
      if (a > b) cout << "A > B   ";
      if (a < b) cout << "A < B   ";
      if (a >= b) cout << "A >= B   ";
      if (a <= b) cout << "A <= B   ";
      cout << endl;
      i = 5;
      }
      break;
    }
  }
  stop = clock();
  int q = (stop-start)/ CLK_TCK;
  Time Q(q);
  cout << "Time spent in the program: " << Q << endl;
  cout << "Don't waste your time." << endl;
  system("pause");
}
