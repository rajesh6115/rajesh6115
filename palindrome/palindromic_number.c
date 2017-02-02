#include <stdio.h>
#include <string.h>

int is_palindrome_string(const char string[]){
	int left = 0, right = 0;
	int result = 1;
	right = strlen(string)-1;
	for(;left < right; left++, right--){
		if(string[left] != string[right]){
			result = 0;
			break;
		}
	}

	return result;
}

int is_palindrome_number(unsigned int number){
	char buffer[256]={0x00};
	char pale_buffer[256]={0x00};
	int len =0;
	len = snprintf(buffer, sizeof(buffer)-1, "%d", number);
	return is_palindrome_string(buffer);
}


int main(int argc, char *argv[]){
	char pale[] = "madam";
	int num = 13431;
	if(is_palindrome_number(num)){
		printf("%d is Palindrome\n", num);
	}else{
		printf("%d is Not Palindrome\n", num);
	}
	if(is_palindrome_string(pale)){
		printf("%s is Palindrome\n", pale);
	}else{
		printf("%s is Not Palindrome\n", pale);
	}
	return 0;
}
