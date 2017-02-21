#include <stdio.h>

int my_itoa(int number, unsigned short base, char *output, size_t max_len){
	int length = 0;
	if(output == NULL || base > 36){
		return -1;
	}
	for( length=0; length < max_len; length++){
		char digit = number%base;
		if(digit<10){
			digit += '0';
		}else{
			digit += ('A'-9);
		}
		output[length] = digit;
		number = number/base;
		if(number==0){
			break;
		}
	}
	/*
	if(length < max_len){
		strrev(output);
	}*/
	return length;
}


int main(int argc, char *argv[]){
	char buffer[256]={0x00};
	int number, base;
	number = 10;
	base = 2;
	my_itoa(number, base, buffer, 256);
	printf("%d in Base %d =%s", number, base, buffer );
	return 0;
}
