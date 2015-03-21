#ifndef __AYAP_2_Console__Schedule__
#define __AYAP_2_Console__Schedule__

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Time
{
    int hours;
    int minutes;
};

class Schedule
{
private:
    Time open;
    Time close;
public:
    Schedule();
    Schedule(Time open, Time close);
    Schedule(int openH,int openM,int closeH,int closeM);
    ~Schedule();
    string printOpen();
    string printClose();
};

#endif /* defined(__AYAP_2_Console__Schedule__) */
