#include <iostream>
#include <ctime>
#include <vector>

int main(void) {

  double secs_in_a_day = 86400;

  //now, more or less
  time_t time0; //your start time here
  time(&time0);

  //20 days later
  time_t time19 = time0 + (20 * secs_in_a_day); //your end time here

  std::vector<struct tm > timevec;

  for(time_t i = time0; i <= time19; i += secs_in_a_day) {
    struct tm t = *(gmtime(&i));
    std::cout << i << "\n";
    timevec.push_back(t);
  }

  char buffer[80];

  for(struct tm tim : timevec) {
    strftime(buffer, 80, "Time: %d / %m / %y\n", &tim);
    puts(buffer);
  }


  return 0;
}
