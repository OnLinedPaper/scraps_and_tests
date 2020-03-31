#include <iostream>

int main(void) {
  int *p;
  int *q;

  int x = 3;
  int y = 4;

  p = &x;
  q = p;
  p = &y;

  std::cout << *p << " " << *q << std::endl;

}
