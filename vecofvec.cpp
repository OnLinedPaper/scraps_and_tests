#include <iostream>
#include <vector>

int main(void) {
  std::vector<int> v;
  std::vector<int> w;

  std::vector<std::vector<int> * > u;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);

  w.push_back(5);
  w.push_back(6);
  w.push_back(7);
  w.push_back(8);

  u.push_back(&v);
  u.push_back(&w);

  (*(u[0]))[1] = 9;
  w[2] = 0;

  for(std::vector<int> *vec : u) {
    for(int i : *vec) {
      std::cout << i << std::endl;
    }
  }

  for(int i : v) {
    std::cout << i << std::endl;
  }

  for(int i : w) {
    std::cout << i << std::endl;
  }
}
