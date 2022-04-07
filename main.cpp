#include <iostream>
#include "classTime.h"
#include "time.h"
#include "classMovie.h"
#include "classTimeslot.h"


int main()
{
// information
Time val_1 = {10,30};
Time val_2 = {13,40};
Time val_3  = {8,10};
Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};
TimeSlot morning = {movie1, {9, 15}};  
TimeSlot second_morning = {movie1, {10, 30}};  
TimeSlot daytime = {movie2, {12, 15}}; 
TimeSlot evening = {movie2, {16, 45}}; 
   

// Task A
    std::cout << "____________________________" << std::endl;
    std::cout << "time from midnight to 10:30: " << minutesSinceMidnight(val_1) << std::endl;
    std::cout << "time from midnight to 1:40: " << minutesSinceMidnight(val_2) << std::endl;

    std::cout << "time between 10:30 and 1:30: " <<  minutesUntil(val_1, val_2) << std::endl;

// Task B 
    std::cout << "____________________________" << std::endl;   
    std::cout << "75 mins after 8:10 is: " << getTime((addMinutes(val_3, 75))) << std::endl;
    std::cout << getTime(addMinutes({9,15}, 116)) << std::endl;

// Task C
    std::cout << "____________________________" << std::endl;   
    std::cout << getTimeSlot(morning) << std::endl;

// Task D
    std::cout << "____________________________" << std::endl; 
    std::cout << getTimeSlot(scheduleAfter(morning,movie1)) << std::endl;
// Task E
    std::cout << "____________________________" << std::endl;   
    std::cout << "TimeSlots " << getTimeSlot(morning) << " and " << getTimeSlot(second_morning) << " do " << (timeOverlap(morning, second_morning) ? "overlap" : "not overlap") << std::endl;
    
    morning.startTime = {4, 4};
    std::cout << "TimeSlots " << getTimeSlot(morning) << " and " << getTimeSlot(second_morning) << " do " << (timeOverlap(morning, second_morning) ? "overlap" : "not overlap") << std::endl;
   







    return 0;
}