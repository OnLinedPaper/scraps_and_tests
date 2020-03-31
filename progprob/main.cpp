#include "controller.h"

int main(void) {
  controller* c = new controller();
  
  int choice = -1;
  float number = -1;
  
  std::cout << "convert in which direction?\nmVtoK: 0\nKtomV: 1\n: ";
  std::cin >> choice;
  
  std::cout << "number to convert: ";
  std::cin >> number;

  std::cout << std::endl;

  if(choice == 0) {
    std::cout << c->convertmVtoK(number) << std::endl;
  } 
  else if(choice == 1) {
    std::cout << c->convertKtomV(number) << std::endl;
  }
   
  
  delete c;
  return 0;
}
