#include <stdio.h>
#include <string.h>

#define MAX_SAMPLE 3
int get_temprature(int &high_temp, int &low_temp){
	scanf ("%d", high_temp);
	scanf ("%d", low_temp);
	if( *high_temp > *low_temp){
		return 0;
	}else{
		return -1;
	}
}

int main(int argc, char *argv[]){
	int high[MAX_SAMPLE] = {0x00};
	int low[MAX_SAMPLE] = {0x00};
	int i=0;
	while(i < MAX_SAMPLE){
		printf ("Enter the Temprature for day 1: ");
		if(get_temprature(&high[i], &low[i]) != -1){
			i++;
		}else{
			printf("Try again");
		}
	}

	return 0;
}
