#include <iostream>
#include "time.h"
#include "classTime.h"
#include "classMovie.h"
#include "classTimeslot.h"

int minutesSinceMidnight(Time time)
{
    
    int hour = time.h * 60;
    int min = time.m;
    int total = hour + min;
    return total;


}

int minutesUntil(Time earlier, Time later)
{
    int total = minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
    return total;
    
}

Time addMinutes(Time time0, int min)
{
    int hour = min / 60;
    int min1 = min % 60;
    int new_hour = time0.h + hour;
    int new_min = time0.m + min1;
    if(new_min >=60)
    {
        new_hour+= new_min / 60;
        // if(new_min % 60 < 10)
        // {
        //     return
        // }
        return {new_hour, new_min % 60};
    }
    else
    {
    return {new_hour,new_min};
    }
    
   


}

std::string getTime(Time time)
{

	return std::to_string(time.h) + ":" + (time.m < 10 && time.m > 0 ? "0" : "") + std::to_string(time.m) + (time.m == 60 || time.m == 0 ? "0" : "");
}

std::string getMovie(Movie mv)
{
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    return mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
}

std::string getTimeSlot(TimeSlot ts)
{
    std::string result = getMovie(ts.movie);
    result += " [starts at " + getTime(ts.startTime) + ", ends by " + getTime(addMinutes(ts.startTime, ts.movie.duration));
    return result + "]";
}
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    Movie film = ts.movie;
    Time new_start = addMinutes(ts.startTime, film.duration);
    return {nextMovie, new_start};
    
}
bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
	Time first = ts1.startTime, second = ts2.startTime;
	int firstDuration = ts1.movie.duration, secondDuration = ts2.movie.duration, minutes = minutesUntil(first, second);
	if (minutes > 0)
	{
		if (minutes < firstDuration)
        {
			return true;
        }
	}
	else if (abs(minutes) < secondDuration)
    {
		return true;
    }
	return false;
}






