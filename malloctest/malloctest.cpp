#include <iostream>
#include <math.h>
#include <stdlib.h>

int main(void) {

	int *array;	//hold 4 ints
	array = (int *)malloc(sizeof(int) * 4);

	array[0] = 4;
	array[1] = 4;
	array[2] = 4;
	array[3] = 11;

	std::cout << array[2] << std::endl;

	free(array);

	return 0;
}
