#include <stdio.h>

void modified_print(const char *str){
	int i=0;
	while(str[i] != '\0'){
		if(str[i] == 'a'){
			printf("%s", "xay");
		}else{
			printf("%c", str[i]);
		}
		i++;
	}
	printf("\n");
}


int main(int argc, char *argv[]){
	if(argc != 2){
		fprintf(stderr, "USAGE: %s <string>\n", argv[0]);
		return -1;
	}
	modified_print(argv[1]);
	return 0;
}
