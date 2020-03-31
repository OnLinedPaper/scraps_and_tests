//Nicholas Reed 2018

/*
ABC bank wants a program that allows the user to have a record of the transactions they've done in the day~ You can deposit money, withdraw money, and transfer money to another account~ 
-You can only withdraw 4 times, and no more than 1500$ in total
-You can only transfer money 3 times
-You can only deposit 93 times
-Each deposit gets an interest of 1.25%
-Your account's balance cant be less than 100$
-Use functions (duh) and arrays
*/

#include <stdio.h>
#include <string.h>

int deposit(int *account, int min, int *count, int max ) {

  int amount = 0;
  
  fprintf(stdout, "amount to deposit: $");
  fscanf(stdin, "%i", &amount);
  
  if(amount > 0 && (*account - amount > min) && *count < max) {
    *account += (amount + amount * .0125);
    
    return(amount);
  }
  else { return(0); }
}

int main(void) {

  int balance = 4000;
  int balance_min = 100;
  
  int withdrawals = 0;
  int withdrawal_max = 4;
  
  int transfers = 0;
  int transfer_max = 3;
  
  int deposits = 0;
  int deposit_max = 93;
  
  int num_of_transactions = 0;
  
  int transactions[withdrawal_max + transfer_max + deposit_max];
  int transaction_type[withdrawal_max + transfer_max + deposit_max];
  /*
    deposit is type 1
    withdrawal is type 2
    transfer is type 3
  */
  
  int choice = 0;
  
  do {
    
    fprintf(stdout, "\033[2Jbalance: $%i\n0: quit\n1: deposit\n2: withdraw\n3:transfer\n> ", balance);
    fscanf(stdin, "%i", &choice);
    
    if(choice == 1) {
      int amount = deposit( &balance, balance_min, &deposits, deposit_max );
      if(amount) {
        transactions[withdrawals + transfers + deposits] = amount;
        transaction_type[withdrawals + transfers + deposits] = 1;
        
        deposits++;
      }
    }
    
  } while(choice != 0);

  return(0);
}





