#include <stdio.h>
#include <string.h>

unsigned int count_char_in_str(char ch, const char *str){
	unsigned int count=0;
	while((str=strchr(str, ch))!=NULL){
		count++;
		str+=1;
	}
	return count;
}
unsigned int count_digit_in_range(unsigned int digit, unsigned int min , unsigned int max){
	char str_number[1024]={0x00};
	unsigned int count = 0;
	for(int i=min; i < max; i++){
		sprintf(str_number, "%02d", i);
		count += count_char_in_str(digit+0x30, str_number);
		memset(str_number, 0x00, sizeof(str_number));
	}
	return count;
}

int main(int argc, char *argv[]){
	int number=0;
	int range_min = 0;
	int range_max = 100;
	printf("%d Times Number %d Coming between %d to %d\n", count_digit_in_range( number, range_min, range_max), number, range_min, range_max);
	return 0;
}
