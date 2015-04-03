#include "Schedule.h"

Schedule::Schedule()
{
    open.hours = 0;
    open.minutes = 0;
    close.hours = 23;
    close.minutes = 59;
}

Schedule::Schedule(const Schedule & input)
{
    open.hours = input.open.hours;
    open.minutes = input.open.minutes;
    close.hours = input.close.hours;
    close.minutes = input.close.minutes;
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

Schedule& Schedule::operator+(const Schedule &input)
{
    Time newOpen, newClose;
    if(open.hours*60 + open.minutes >= input.open.hours*60 + input.open.minutes) newOpen = input.open;
    else newOpen = open;
    if(close.hours*60 + close.minutes <= input.close.hours*60 + input.close.minutes) newClose = input.close;
    else newClose = close;
    Schedule *newSchedule = new Schedule(newOpen, newClose);
    return *newSchedule;
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

Time Schedule::getOpenTime() const
{
    return open;
}

Time Schedule::getCloseTime() const
{
    return close;
}

void Schedule::setTime(Time open, Time close)
{
    this->open = open;
    this->close = close;
}

void Schedule::setTime(int openH,int openM,int closeH,int closeM)
{
    this->open.hours = openH;
    this->open.minutes = openM;
    this->close.hours = closeH;
    this->close.minutes = closeM;
}


