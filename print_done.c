#include <stdio.h>


int print_done_without_loop(unsigned int times){
	if(times){
		printf("DONE\n");
		print_done_without_loop(times-1);
	}
}

int print_done_without_loop_and_condition(){
	printf("DONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\n");
	printf("DONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\n");
	printf("DONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\n");
	printf("DONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\n");
	printf("DONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\n");
	printf("DONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\n");
	printf("DONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\n");
	printf("DONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\n");
	printf("DONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\n");
	printf("DONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\nDONE\n");
}
int main(int argc, char *argv[]){
	//print_done_without_loop(100);
	print_done_without_loop_and_condition();
	return 0;
}
