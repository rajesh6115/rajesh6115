#include <stdio.h>
#include <string.h>

int find_colindrome(const char *str){
	size_t len = strlen(str);
	if( (len % 6) != 0){
		return 0;
	}
	for(int itr1=0; itr1<len; itr1+=6){
		for( int itr2=0; itr2 < 3 ; itr2++){
			if(str[itr1+itr2] != str[itr1+5-itr2]){
			//	printf("%d:%d-%c:%c\n", itr1+itr2, itr1-itr2+5, str[itr2+itr1], str[itr1-itr2+5]);
				return 0;
			}
		}
	}
	return 1;
}


int main(int argc, char *argv[]){
	printf("%s is %s\n", argv[1], find_colindrome(argv[1])? "Colindrome": "Not a Colindrome");
	return 0;
}
