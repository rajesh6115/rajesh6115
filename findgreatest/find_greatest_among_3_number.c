#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int greatest_among_three(const int num1, const int num2, const int num3){
	int result=0;
	if( num1 > num2){
		if( num1 > num3){
			result = num1;
		}else{
			result = num3;
		}
	}else if(num2 > num3){
		result = num2;
	}else{
		result = num3;
	}
	return result;
}

int main(int argc, const char *argv[]){
	int num1=0, num2=0, num3=0;
	srand(time(NULL));
	for( int i=0; i< 10; i++){
		num1 = rand()%1000;
		num2 = rand()%1000;
		num3 = rand()%1000;
		printf("Greatest among (%d,%d,%d) is %d\n", num1, num2, num3, greatest_among_three(num1, num2, num3));
	}
	return 0;
}
