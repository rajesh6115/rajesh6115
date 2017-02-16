#include <stdio.h>
#include <stdlib.h>
int find_in_power_serise(int number, int power){
	do{
		if((number % power) ==0){
			number = number/power;
		}else{
			break;
		}
	}while(number>1);
	if(number == 1){
		return 1;
	}else{
		return 0;
	}
}

int is_nth_bit_set(unsigned int num, int bit){
	return ((num >> bit) & 0x01);
}

int find_in_power_serise_of_2(unsigned int number){
	int count = 0;
	for(int i=0; i < (sizeof(number)*8 ); i++){
		if(is_nth_bit_set(number, i)){
			count ++;
		}
	}
	if(count == 1){
		return 1;
	}else{
		return 0;
	}
}

int count_bit_set(unsigned int number, int count)
{
	if(number){
		if(number&0x01)
			count++;
		return count_bit_set((number >> 1), count);
	}
	return count;
}

int find_in_power_serise_of_2_no_loop(unsigned int number){
	if(count_bit_set(number, 0)==1){
		return 1;
	}else{
		return 0;
	}
}
int main(int argc, char *argv[]){
	if(argc != 2){
		fprintf(stderr, "USAGE:%s <number>\n", argv[0]);
		return -1;
	}
	int num = atoi(argv[1]);
	int power = 2;
	printf("%d is %s Power Serise of %d\n", num, find_in_power_serise(num, power)?"IN":"NOT IN", power);
	printf("%d is %s Power Serise of %d\n", num, find_in_power_serise_of_2(num)?"IN":"NOT IN", 2);
	printf("%d is %s Power Serise of %d\n", num, find_in_power_serise_of_2_no_loop(num)?"IN":"NOT IN", 2);
	return 0;
}
