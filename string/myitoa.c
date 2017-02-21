#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strrev(char *string){
	if(string == NULL){
		return 0;
	}
	int string_len = strlen(string);
	for(int left=0, right=string_len-1; left < right; left++, right--){
		char temp_ch = string[left];
		string[left] = string[right];
		string[right] = temp_ch;
	}
}

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
			digit += ('A'-10);
		}
		output[length] = digit;
		number = number/base;
		if(number==0){
			break;
		}
	}

	if(length < max_len){
		my_strrev(output);
	}else{
		return -1;
	}
	return length;
}


int main(int argc, char *argv[]){
	char buffer[256]={0x00};
	int number, base;
	for(int i=0; i < 10; i++){
		number = (rand()%1000)+1;
		base = (rand()%35)+1;
		memset(buffer, 0x00, sizeof(buffer));
		my_itoa(number, base, buffer, 256);
		printf("%d in Base %d =%s\n", number, base, buffer );
	}
	return 0;
}
