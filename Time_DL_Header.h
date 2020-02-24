// Copyright 2020 <Diana Lukashuk>
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void p_t(int a) {
  if (a < 10) { cout << "0" << a;
  } else {
    cout << a;
  }
}
int getRandomNumber(int min, int max) {
  static double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
  return static_cast <int>(rand() * fraction * (max - min + 1) + min);
}

class Time {
 public:
Time();
Time(int s);
Time(int h, int m, int s);
friend ostream& operator << (ostream& stream, const Time& a);
friend istream& operator >> (istream& stream, Time& a);

bool operator==(const Time& t);
bool operator!=(const Time& t);
bool operator>(const Time& t);
bool operator<(const Time& t);
bool operator>=(const Time& t);
bool operator<=(const Time& t);
Time rand();
Time& operator=(const Time& t);
Time operator+(const Time& c);
Time operator-(const Time& c);
 private:
int hou, min, sec;
};

Time::Time() {
  hou = 0;
  min = 0;
  sec = 0;
}

Time::Time(int s) {
  hou = 0;
  min = 0;
  sec = s;
  while (sec > 59) {
    sec = sec - 60;
    min++;
  }
  while (min > 59) {
    min = min - 60;
    hou++;
  }
  while (hou > 23) {
    hou = hou - 24;
  }
}

Time::Time(int h, int m, int s) {
  hou = h;
  min = m;
  sec = s;
}

ostream& operator << (ostream& stream, const Time& a) {
p_t(a.hou);
cout << ":";
p_t(a.min);
cout << ":";
p_t(a.sec);
return stream;
}

istream& operator >> (istream& stream, Time& t) {
  string S;
  cin >> S;
  int  i = 0, dop = 0;
  while (S[i] != ':') {
    dop = dop * 10 + (unsigned char) S[i] - (unsigned char)'0';
    i++;
  }
  if (dop > 23) {
  cout << "ERROR(hour)(will input 00)" << endl;
  t.hou = 0;
  } else {
    t.hou = dop;
  }
  dop = 0;
  i++;
  // hour
  while (S[i] != ':') {
    dop = dop * 10 + (unsigned char)S[i] - (unsigned char)'0';
    i++;
  }
  if (dop > 59) {
    cout << "ERROR(minutes)(will input 00)" << endl;
    t.min = 0;
  } else {
    t.min = dop;
  }
  dop = 0;
  i++;
  // sec
  while (i <= S.size() - 1) {
    dop = dop * 10 + (unsigned char)S[i] - (unsigned char)'0';
    i++;
  }
  if (dop > 59) {
  cout << "ERROR(seconds)(will input 00)" << endl;
  t.sec = 0;
  } else {
    t.sec = dop;
  }
  dop = 0;
  return stream;
}

Time Time::operator+(const Time& t) {
  Time res;
  res.sec = sec + t.sec;
  while (res.sec > 59) {
    res.sec = res.sec - 60;
    res.min++;
  }
  res.min = min + t.min+ res.min;
  while (res.min > 59) {
    res.min = res.min - 60;
    res.hou++;
  }
  res.hou = hou + t.hou+ res.hou;
  while (res.hou > 23) {
    res.hou = res.hou - 24;
  }
  return res;
}

Time Time::operator-(const Time& t) {
  Time res;
  res.sec = sec - t.sec;
    while (res.sec < 0) {
      res.sec = res.sec + 60;
      res.min--;
    }
    res.min = min - t.min+ res.min;
    while (res.min < 0) {
      res.min = res.min + 60;
      res.hou--;
    }
    res.hou = hou - t.hou+ res.hou;
    while (res.hou < 0) {
      res.hou = 24 + res.hou;
    }
  return res;
}

bool Time::operator==(const Time& t) {
  bool res = 0;
  if ((min == t.min) && (hou == t.hou) && (sec == t.sec)) res = 1;
  return res;
}

bool Time::operator!=(const Time& t) {
  bool res = 1;
  if ((min == t.min) && (hou == t.hou) && (sec == t.sec)) res = 0;
  return res;
}

bool Time::operator>(const Time& t) {
  if (hou > t.hou) return 1;
  if (hou < t.hou) return 0;
  if (min > t.min) return 1;
  if (min < t.min) return 0;
  if (sec > t.sec) return 1;
  if (sec < t.sec) return 0;
  return 0;
}

bool Time::operator>=(const Time& t) {
  if (hou > t.hou) return 1;
  if (hou < t.hou) return 0;
  if (min > t.min) return 1;
  if (min < t.min) return 0;
  if (sec > t.sec) return 1;
  if (sec < t.sec) return 0;
  return 1;
}

bool Time::operator<(const Time& t) {
  if (hou > t.hou) return 0;
  if (hou < t.hou) return 1;
  if (min > t.min) return 0;
  if (min < t.min) return 1;
  if (sec > t.sec) return 0;
  if (sec < t.sec) return 1;
  return 0;
}

bool Time::operator<=(const Time& t) {
  if (hou > t.hou) return 0;
  if (hou < t.hou) return 1;
  if (min > t.min) return 0;
  if (min < t.min) return 1;
  if (sec > t.sec) return 0;
  if (sec < t.sec) return 1;
  return 1;
}

Time& Time::operator=(const Time& t) {
  hou = t.hou;
  min = t.min;
  sec = t.sec;
  return *this;
}

Time Time::rand() {
  srand(static_cast<unsigned int>(time(0)));
  hou = getRandomNumber(0, 23);
  min = getRandomNumber(0, 59);
  sec = getRandomNumber(0, 59);
  return (*this);
}
