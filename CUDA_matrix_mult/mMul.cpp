//code inspired by https://www.programiz.com/cpp-programming/examples/matrix-multiplication

#include <iostream>
#include <cstdlib>

void multiply(float *a, float *b, float *c, int aRow, int aCol, 
  int bCol) {
    for(int i = 0; i < aRow; i++)
        for(int j = 0; j < bCol; j++)
            for(int k = 0; k < aCol; k++)
              c[i*bCol + j] += a[i*aCol + k] * b[j + k*bCol];  
  return;
}


int main(int argc, char *argv[])
{

    if(argc != 5) {
      std::cerr << "usage: ./run aRows aCols bRows bCols\n";
      return(-1);
    }

    if(atoi(argv[2]) != atoi(argv[3])) {
      std::cerr << "error! aCols must match bRows. " << 
        argv[2] << ", " << argv[3] << std::endl;
      return(-1);
    }

    srand(4); //so creative

    //accept 4 args: row, col, for a and b
    int aRow = atoi(argv[1]);
    int aCol = atoi(argv[2]);
    int bRow = atoi(argv[3]);
    int bCol = atoi(argv[4]);
    int cRow = aRow;
    int cCol = bCol;

    float *a = (float *)malloc(aRow * aCol * sizeof(float));
    float *b = (float *)malloc(bRow * bCol * sizeof(float));
    float *c = (float *)malloc(cRow * cCol * sizeof(float));


    //initialize them to randoms
    for(int i = 0; i < aRow*aCol; i++) {
        a[i] = i;
    }
    for(int i = 0; i < bRow*bCol; i++) {
            b[i] = i;
    }
    for(int i = 0; i < aRow*bCol; i++) {
        c[i] = 0;
    }

    multiply(a, b, c, aRow, aCol, bCol);



//printout
    for(int i=0; i<aRow * bCol; i++)
      std::cout << c[i] << " ";
    std::cout << std::endl; 


    free(a);
    free(b);
    free(c);

    return 0;
}
