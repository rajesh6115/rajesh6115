#include <stdio.h>
#include <stdlib.h>

int multiplication_table(unsigned int num, unsigned int table[] , size_t size){
	int i=0;
	for( i=0; i< 10; i++){
		table[i] = num* (i+1);
	}
	return i;
}

int print_multiplication_table(unsigned int num, unsigned int table[], size_t size){
	int i=0;
	for( i=0; i< size; i++){
		printf("%d\tX\t%d\t=\t%d\n", num, i+1, table[i]);
	}
	return i;
}

int main(int argc, char *argv[]){
	if(argc != 2){
		fprintf(stderr, "USAGE: %s <number>\n", argv[0]);
		return -1;
	}
	int number=0;
	number = atoi(argv[1]);
	if(number < 1){
		fprintf(stderr, "Please Enter a Positive Number\n");
		return -1;
	}
	unsigned int table[10]={0x00};
	multiplication_table(number, table, 10);
	print_multiplication_table(number, table, 10);
	return 0;
}
