#include <stdio.h>
#include <stdlib.h>

void swap_elements_in_array(int* array){
	
	int temp = array[0];
	array[0] = array[4];
	array[4] = temp;

}

int getRandomInteger(int n){

	int limit;
	int r;

	limit = RAND_MAX - (RAND_MAX % n);

	while((r = rand()) >= limit);

	return r % n;

}

int main(){

	int array[5] = {1, 2, 3, 4, 5};

	swap_elements_in_array(array);

	printf("Pos. 1: %i; Pos. 5: %i", array[0], array[4]);

	for(int i = 0; i < 5; i++){

		int random_number = getRandomInteger(15);

		printf("%i. Random Number = %i\n", i, random_number);

	};

}
