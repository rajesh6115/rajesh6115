#include <stdio.h>
#include <string.h>

/*Finding Number of new line characters in a buffer*/
int find_count_of_lines(const char *str){
        int liness=0, i=0;
        for(i=0; str[i] != '\0'; i++){
                if( str[i] == '\n' ){
                        liness+=1;
                }
        }
        return liness;
}
/* Read a File chunk by chunk and sum number of new line character in individual chunks*/
int txt_file_number_of_lines(FILE *fp){
        int lines=0;
        char buffer[1024]={0x00};
        size_t bytes=0;
        fseek(fp, 0L, SEEK_SET);
        do{
                memset(buffer, 0x00, sizeof(buffer));
                bytes = fread(buffer, sizeof(char), sizeof(buffer)-1, fp);
                if(bytes > 0){
                        lines += find_count_of_lines(buffer);
                }
        }while(bytes>0);
        return lines;
}

int main(int argc, char *argv[]){
	FILE *fp = NULL;
	int number_of_lines = 0;
	if(argc != 2){
		fprintf(stderr, "USAGE: %s <filename>\n", argv[0]);
		return -1;
	}
        fp = fopen(argv[1], "r");
        number_of_lines= txt_file_number_of_lines(fp);
	printf("%s having %d Lines\n", argv[1], number_of_lines);
	fclose(fp);
	return 0;
}
