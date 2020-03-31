#ifndef __NODE_H
#define __NODE_H

#include <cstddef>
#include <cstdlib>
#include <cmath>
#include <iostream>

class node {
  //classic BST, with one key and one val
public:  
  node() {
    this->key = 0;
    this->val = 0;
    left = NULL;
    right = NULL;
    parent = NULL;
  }

  node(float k, float v) {
    this->key = k;
    this->val = v;
    left = NULL;
    right = NULL;
    parent = NULL;
  }
  
  void add(float k, float v) {
    if(k == this->key) { return; }

    else if (k < this->key) {
      if(this->left == NULL) {
        this->left = new node(k, v);
        this->left->parent = this;
      }
      else {
        this->left->add(k, v);
      }
    }

    else if (k > this->key) {
      if(this->right == NULL) {
        this->right = new node(k, v);
        this->right->parent = this;
      }
      else {
        this->right->add(k, v);
      }
    }
  }

  float getFactor(float k) {
    //hunt through the BST for the values to the left and right of k
    //then use the keys of the nodes to compute an average and return it
    //uses the deepest possible node and the previous one behind it to 
    //compute an "average"
    //TODO: get previous node, i.e. less-than node if it's a left child and vice versa
    node* current = this; //starts at the root but doesn't go into the tree
    node* previous = NULL;
    node* save = NULL;
    bool isLarger = false;  //if this node is smaller than k or not - this is used to
                            //determine which direction to "climb" the tree 
                            //when looking for the nearest neighbor
    bool edge = false;  //if the data point runs outside of the graph 
    
    while(1 == 1) {
      if(k == current->key) { return(k * (current->val / current->key)); }
      
      else if(k < current->key) {
        if(current->left == NULL) {
          //we've hit the bottom of the tree - compute the factor and return it
          isLarger = false;
          break;
        }
        else {
          current = current->left;
        }
      }
      
      else if(k > current->key) {
        if(current->right == NULL) {
          isLarger = true;
          break;
        }
        else {
          current = current->right;
        }
      }
    }
    
    previous = current;
    save = previous;
    
    
    //current now points to the nearest approximation of the node - find the next one in line
    
    if(isLarger) {
      //the k value was bigger than the node's key - climb the parents until 
      //we find one with a right subchild, then go all the way down the left side of it
      
      save = previous;
      previous = previous->parent;
      while(previous != NULL && previous->left != save) {
        //climb the tree until we come to a unique right subchild
        save = previous;
        previous = previous->parent;
      }
    }
    else {
      //the k value was smaller than the node's key 
      
      save = previous;
      previous = previous->parent;
      while(previous != NULL && previous->right != save) {
        //climb the tree until we come to a unique right subchild
        save = previous;
        previous = previous->parent;
      }
    }
    
    if(previous == NULL) {
      //no child found - revert it to the "current" value and use that
      previous = current->parent;
      edge = true;
    }
    
    
    
    //debugging statement
    /*std::cout << "selecting: \n" 
      << "for key: " << k << std::endl 
      << "edge: " << edge <<std::endl
      << "prev: " << previous->key << " " << previous->val << std::endl 
      << "curr: " << current->key << " " << current->val << "\n\n";*/
      
      
    //calculate the factor with "previous" and "current"
    //apply different weight depending on how close the key is to the two vals
    
    //this will ultimately hold the weighted factor
    float factor = 0;
    if(!edge) {
      //the data is within the tree - return a weighted average
      
      float prevFact, currFact, prevWeight, currWeight = 0;
      
      
      //unweighted previous value
      prevFact = (previous->val / previous->key); 
      //unweighted current value
      currFact = (current->val / current->key);
      
      //difference between the keys - used to calculate the weights
      float diff = fabs(previous->key - current->key);
      prevWeight = fabs((current->key - k) / diff);
      currWeight = fabs((previous->key - k) / diff);

      
      factor = (prevFact * prevWeight + currFact * currWeight);
      factor *= k;
    }
    else {
      //the data "runs off" the end of the tree - return a "slope" instead
      float rise, run, diff = 0;
      rise = current->val - previous->val;
      run = current->key - previous->key;
      diff = k - current->key;
      
      //debugging statement
      /*std::cout << "slope selecting: \n"
        << "rise: " << rise << std::endl
        << "run: " << run << std::endl
        << "diff: " << diff << std::endl
        << "slope: " << rise / run << "\n\n";*/
        
      factor = current->val + (diff * (rise / run));
    }
    
    
    return(factor);
  }
  
  void print() {
    if(this->left != NULL) {
      this->left->print();
    }
    
    std::cout << "key: " << this->key << "  val: " << this->val << std::endl;
    
    if(this->right != NULL) {
      this->right->print();
    }
  }
  
private:
  float key;
  float val;
  node *left;
  node *right;
  node *parent;
};

#endif
