#include <stdio.h>
#include <string.h>

void flush_stdin(void)
{
	char ch;
	do{
		ch = getchar();
	}while( ch != EOF && ch != '\n');
}

int accept_number_form_user(void)
{
	int num=0;
	char buffer[256]={0x00};
	do{
		printf("Enter a Number between 1 to 9 : ");
		scanf(" %[^\n]s", buffer);
		if(strlen(buffer) == 1){
			sscanf(buffer," %d", &num);
		}
		if(num<1 || num >9){
			printf("Please Try Again...\n");
		}
		flush_stdin();
		memset(buffer, 0x00, sizeof(buffer));
	}while(num<1 || num >9);
	return num;
}
int main(int argc, char *argv[]){
	printf("You Entered: %d\n", accept_number_form_user());
	char buffer[256]={0x00};
	return 0;
}
