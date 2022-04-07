#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "classTime.h"
#include "time.h"
#include "classTimeslot.h"
#include "classMovie.h"

Movie movie1 = {"Dumb and Dumber", COMEDY, 107};
Movie movie2 = {"Casablanca", DRAMA, 102};
Movie movie3 = {"Seven Samurais", DRAMA, 207};
Movie movie4 = {"Blade Runner", THRILLER, 117};
Movie movie5  = {"Back to the Future", COMEDY, 120};
Movie movie6  = {"The Dark Knight", DRAMA, 150};
Movie movie7  = {"Halloween", THRILLER, 100};
Movie movie8  = {"Terminator", ACTION, 95};
Movie movie9  = {"The Big Lebowski", COMEDY, 116};
Movie movie10  = {"Black Widow", ACTION, 134};


TimeSlot t = {movie5, {1, 20}};
TimeSlot t1 = {movie6, {0, 48}};
TimeSlot t2 = {movie7, {3, 20}};
TimeSlot t3 = {movie8, {7, 00}};
TimeSlot morning = {movie9, {9, 15}};
TimeSlot morning1 = {movie9, {4, 4}};
TimeSlot second_morning = {movie10, {10, 30}};
TimeSlot second_morning1 = {movie10, {6, 0}};




TEST_CASE("task 1a")
{
	CHECK(minutesSinceMidnight({0, 10}) == 10);
	CHECK(minutesSinceMidnight({5, 43}) == 343);
	CHECK(minutesSinceMidnight({12, 0}) == 720);
	CHECK(minutesSinceMidnight({23, 59}) == 1439);

}
TEST_CASE("task 1b")
{

	CHECK(minutesUntil({0, 0}, {1, 0}) == 60);
	CHECK(minutesUntil({0, 1}, {12, 0}) == 719);
	CHECK(minutesUntil({0, 0}, {1, 0}) == 60);
	CHECK(minutesUntil({10, 1}, {10, 60}) == 59);
}
TEST_CASE("task 2")
{
	
	CHECK(getTime(addMinutes({8, 10}, 75)) == "9:25");
	CHECK(getTime(addMinutes({10, 2}, 40)) == "10:42");
	CHECK(getTime(addMinutes({20, 40}, 19)) == "20:59");
	CHECK(getTime(addMinutes({12, 12}, 0)) == "12:12");

	
}
TEST_CASE("getMovie()")
{

	
	CHECK(getMovie(movie1) == "Dumb and Dumber COMEDY (107 min)");
	CHECK(getMovie(movie2) == "Casablanca DRAMA (102 min)");
	CHECK(getMovie(movie3) == "Seven Samurais DRAMA (207 min)");
	CHECK(getMovie(movie4) == "Blade Runner THRILLER (117 min)");
}
TEST_CASE("task c")
{
	
	CHECK(getTimeSlot(t) == "Back to the Future COMEDY (120 min) [starts at 1:20, ends by 3:20]");
	CHECK(getTimeSlot(t1) == "The Dark Knight DRAMA (150 min) [starts at 0:48, ends by 3:18]");
	CHECK(getTimeSlot(t2)== "Halloween THRILLER (100 min) [starts at 3:20, ends by 5:00]");
	CHECK(getTimeSlot(t3) == "Terminator ACTION (95 min) [starts at 7:00, ends by 8:35]");
}
TEST_CASE("task d")
{

	CHECK(getTimeSlot(scheduleAfter(morning, movie10)) == "Black Widow ACTION (134 min) [starts at 11:11, ends by 13:25]");
	CHECK(getTimeSlot(scheduleAfter(second_morning, movie9)) == "The Big Lebowski COMEDY (116 min) [starts at 12:44, ends by 14:40]");
	CHECK(getTimeSlot(scheduleAfter(morning, movie9)) == "The Big Lebowski COMEDY (116 min) [starts at 11:11, ends by 13:07]");
}

TEST_CASE("task e")
{
	  
	  CHECK(timeOverlap(morning, second_morning));
	  
	  CHECK(!timeOverlap(morning1, second_morning));
	  
	  CHECK(!timeOverlap(morning, second_morning1));
}