#include <stdio.h>
#include <string.h>
/*
 * serise variable:  used to return fibonacci numbers, provide enough
 * 		     space so that index out of bound should not come.
 * */
int fibonacci_serise(int max, int serise[]){
	int i = 0;
	serise[0] = 1;
	serise[1] = 1;
	for(i=2; i< max; i++){
		serise[i] = serise[i-1] + serise[i-2];
	}
	return i;
}

int fibonacci_serise_upto(int max_value, int serise[]){
	int i = 0;
	serise[0] = 1;
	serise[1] = 1;
	for(i=2; ; i++){
		if((serise[i-1] + serise[i-2]) <= max_value){
			serise[i] = serise[i-1] + serise[i-2];
		}else{
			break;
		}
	}
	return i;
}

int main(int argc, char *argv[]){
	int serise[100] = {0x00};
	int max_term = fibonacci_serise(15, serise);
	for(int i=0; i< max_term; i++){
		if ( (max_term-1) == i){
			printf("%d\n", serise[i]);
		}else{
			printf("%d,",serise[i]);
		}
	}
	memset(serise, 0x00, sizeof(serise));
	max_term = fibonacci_serise_upto(100, serise);
	for(int i=0; i< max_term; i++){
		if ( (max_term-1) == i){
			printf("%d\n", serise[i]);
		}else{
			printf("%d,",serise[i]);
		}
	}
	return 0;
}
