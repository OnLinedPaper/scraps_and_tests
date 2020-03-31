#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#include <vector>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "node.h"

class controller {

public:
  controller() {
    //init the controller - read from a file, called data.txt
    //store it in a vector, shuffle it, and insert it into the BSTs
    
    std::vector<std::pair<float, float>> v;
    std::string line, first, second;
    std::pair<float, float> p;
    
    std::ifstream inf;
    inf.open("data.txt");
    if(!inf.is_open()) { std::cerr << "can't open data.txt"; return; }
    
    //read in data: temperature (in K) and voltage (in V)
    while(getline(inf, line)) {
      //std::cout << line << std::endl;
      
      //make the string a stream so we can read from it
      std::stringstream ss(line);
      
      //read the values into the pair: temp is first, voltage is second
      ss >> p.first >> p.second;
      //convert V to mV
      p.second *= 1000;
      
      //std::cout << p.second << std::endl;
      
      //add it to the vector
      v.push_back(p);
    }
    
    //shuffle the vector to ensure (with high probability) a balanced BST
    std::random_shuffle(v.begin(), v.end());
    
    kAsKey = new node(v.front().first, v.front().second);
    mvAsKey = new node(v.front().second, v.front().first);
  
    for(std::vector<std::pair<float, float>>::iterator it = v.begin(); it!= v.end(); it++) {
      kAsKey->add(it->first, it->second);
      mvAsKey->add(it->second, it->first);
    }
  }
  
  
  float convertmVtoK(float mVin) { 
    float f = mvAsKey->getFactor(mVin);
    if(f < 0) {
      std::cout << "Warning: current projections indicate that this input voltage returns a negative Kelvin value.\n";
    }
    return(f);
  }
  float convertKtomV(float kIn) {
    float f =  kAsKey->getFactor(kIn);
    if(f < 0) {
      std::cout << "Warning: current projections indicate that this input temperature returns a negative millivolt value.\n";
    }
    return(f);
  }

  void debug_print(){
    //a debugging function that prints the trees
    kAsKey->print();
    mvAsKey->print();
  }

private:
  node *kAsKey;
  node *mvAsKey;
};

#endif
