#include <stdio.h>
#include <stdlib.h>

int is_prime_number(unsigned int number){
	if(number <= 1){
		return 0;
	}
	for(unsigned int devisor=2; devisor < number/2; devisor++){
		if(number % devisor == 0){
			return 0;
		}
	}
	return 1;
}


int main(int argc, char *argv[]){
	unsigned int num = 97;
	if( argc > 1){
		num =  atoi(argv[1]);
	}
	printf("%d is %s\n", num, is_prime_number(num) ? "prime number": "non prime numebr");
	return 0;
}
