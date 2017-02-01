#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_LENGTH(ARR) \
	(sizeof(ARR)/sizeof(ARR[0]))

int greatest_numers_in_array(const int numbers[], long unsigned int max_ele){
	int result=0;
	for(long unsigned int i=0; i < max_ele; i++){
		if(numbers[i] > result){
			result = numbers[i];
		}
	}
	return result;
}

int main(int argc, const char *argv[]){
	int numbers[10]={0x00};
	srand(time(NULL));
	for( int i=0; i< 10; i++){
		for( int j=0; j< 10; j++){
			numbers[j] = rand()%1000;
		}
		printf("Greatest among (%d,%d,%d,%d,%d,%d,%d,%d,%d,%d) is %d\n", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6], numbers[7], numbers[8], numbers[9], greatest_numers_in_array(numbers, ARRAY_LENGTH(numbers)) );
	}

	return 0;
}
