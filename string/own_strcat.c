#include <stdio.h>
#include <string.h>
int my_strlen(const char *str){
	int len=0;
	if(str){
		while(str[len] != '\0'){
			len++;
		}
	}

	return len;
}
char * my_strcat(char *dest, const char *src)
{
	int dest_len = my_strlen(dest);
	if( dest == NULL || src == NULL){
		return dest;
	}
	int src_itr=0;
	while(src[src_itr] != '\0'){
		dest[dest_len] = src[src_itr];
		dest_len++;
		src_itr++;
	}
	dest[dest_len] = '\0';
	return dest;
}
int main(int argc, char *argv[]){
	char str1[256]="helllo ";
	my_strcat(str1, "world!!!");
	printf("%s\n", str1);
	return 0;
}
