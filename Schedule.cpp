#include "Schedule.h"

Schedule::Schedule()
{
    this->open.hours = 0;
    this->open.minutes = 0;
    this->close.hours = 23;
    this->close.minutes = 59;
}

Schedule::Schedule(int openH,int openM,int closeH,int closeM)
{
    this->open.hours = openH;
    this->open.minutes = openM;
    this->close.hours = closeH;
    this->close.minutes = closeM;
}

Schedule::Schedule(Time open, Time close)
{
    this->open = open;
    this->close = close;
}

Schedule::~Schedule()
{
    
}

string Schedule::printOpen()
{
    stringstream buffer;
    buffer << ((open.hours>9) ? "" : "0") << open.hours << ':' << ((open.minutes>9) ? "" : "0") << open.minutes;
    return buffer.str();
}

string Schedule::printClose()
{
    stringstream buffer;
    buffer << ((close.hours>9) ? "" : "0") << close.hours << ':' << ((close.minutes>9) ? "" : "0") << close.minutes;
    return buffer.str();
}