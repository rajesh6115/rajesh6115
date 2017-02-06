#include <stdio.h>
int own_strcmp(const char *str1, const char *str2) __attribute__((nonnull(1), nonnull(2)));
int own_strcmp(const char *str1, const char *str2)
{
	int i=0;
	while(str1[i] && str2[i]){
		if( str1[i] != str2[i]){
			break;
		}
		i++;
	}
	return str1[i]-str2[i];
}



int main(int argc, char *argv[]){
	printf("%s and %s is %d\n", argv[1], argv[2], own_strcmp(argv[1], argv[2]));
	return 0;
}
