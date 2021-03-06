// Copyright 2015 <precisef0x>

#pragma once

#include <iostream>
#include <string>
#include <sstream>

using ::std::string;
using ::std::stringstream;

struct Time {
  int hours;
  int minutes;
};

class Schedule {
 private:
  Time open;
  Time close;

 public:
  Schedule();
  Schedule(const Schedule&);
  Schedule(Time open, Time close);
  Schedule(int openH, int openM, int closeH, int closeM);
  ~Schedule();
  Schedule& operator+(const Schedule&);
  string printOpen();
  string printClose();
  Time getOpenTime() const;
  Time getCloseTime() const;
  void setTime(Time open, Time close);
  void setTime(int openH, int openM, int closeH, int closeM);
};
