#include <stdio.h>

void recursivePrint(int a) {
  if(a == 0) { return; }
  recursivePrint(a/2);

  fprintf(stdout, "%d", a%2);

}

int main(void) {
  int num = 0;
  
  fprintf(stdout, "decimal number: ");
  fscanf(stdin, "%d", &num);

  recursivePrint(num);

  fprintf(stdout, "\n");

  return 0;
}
