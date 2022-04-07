#pragma once
#include "classTime.h"
#include "classMovie.h"
#include "classTimeslot.h"
#include <iostream>


int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
std::string getTime(Time time);
std::string getTimeSlot(TimeSlot ts);
std::string getMovie(Movie mv);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 





