#include <stdio.h>
#include <string.h>

int find_count_of_words(const char *str){
        int words=0, i=0;
	// skip initial white space characters
	while(str[i] != '\0'){
		if( str[i] == ' ' || str[i] == '\n' || str[i]== '\r' || str[i] == '\t'){
			i++;
		}else{
			break;
		}
	}
        for(; str[i] != '\0'; i++){
                if( str[i] == ' ' || str[i] == '\n' || str[i]== '\r' || str[i] == '\t' ){
                        words+=1;
			// skip consucative white space
                        while(str[i]==' ' || str[i] == '\n' || str[i]== '\r' || str[i] == '\t'){
                                i++;
                        }
                }
        }
        return words;
}

int txt_file_number_of_words(FILE *fp){
        int  words=0;
        char buffer[1024]={0x00};
        size_t bytes=0;
        fseek(fp, 0L, SEEK_SET);
        do{
                memset(buffer, 0x00, sizeof(buffer));
                bytes = fread(buffer, sizeof(char), sizeof(buffer)-1, fp);
                if(bytes > 0){
                	words += find_count_of_words(buffer) ;
                }
        }while(bytes>0);
        return words;
}


int main(int argc, char *argv[]){
        FILE *fp = NULL;
        int number_of_words = 0;
        if(argc != 2){
                fprintf(stderr, "USAGE: %s \n", argv[0]);
                return -1;
        }
        fp = fopen(argv[1], "r");
        number_of_words = txt_file_number_of_words(fp);
        printf("%s having %d Words\n", argv[1], number_of_words);
        fclose(fp);
        return 0;
}
