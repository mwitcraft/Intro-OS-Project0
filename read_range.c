#include <stdio.h>
#include <string.h>

char low;
char high;
int data[126];

int main(int argv, char* argc[]){

	/* Simple ideas */
	/* create an array of size 125 to store all data */
	/* index will correspond to the character it represents (ascii decimal number) */
	/* value at that index will be number of time the character appears */
	/* or of size 125-32 and just add 32 to index when printing so correct character gets printed */
	/* maybe add a high and low number corresponding to ascii # of high and low */

	/* Process: */
	/* 1. read file in */
	/* 2. initialize data array */
	/* 3. step through each line */
	/* 4. step through each character in line */
	/* 5. determine if character is in range */
	/* 6. if it is, add to data array */
	/* 7. print */
	
	/* char low; */
	/* char high; */

	/* int data[125]; */
	for(int i = 0; i < 126; ++i)
		data[i] = 0;

/* 	Will include all characters from space to '}' (close curly bracket)	 */
/*	space = 32 | '}' = 125 	 */
	if(argv == 1){
		low = ' ';
		high = '}';
		/* printf("Low = %c (%d)\n", low, low); */
		/* printf("High = %c (%d)\n", high, high); */
	}
/*	Will range from first character to '}'  */
	if(argv == 2){
		low = argc[1][0];
		high = '}';
		/* printf("Low = %c (%d)\n", low, low); */
		/* printf("High = %c (%d)\n", high, high); */
	}
/*	Will range from first character to second character  */
	if(argv == 3){
		low = argc[1][0];
		high = argc[2][0];
		/* printf("Low = %c (%d)\n", low, low); */
		/* printf("High = %c (%d)\n", high, high); */
	}

	FILE *file = stdin;
	char line[99999];

	char c;

	/* for(int i = 0; i < 125; ++i){ */
	/* 	printf("Index: %i \t Count: %i\n", i, data[i]); */
	/* } */
        /*  */
	/* printf("Index: 125 \t Count: %i\n", data[125]); */
        /*  */

	while(!feof(file)){
		c = fgetc(file);
		/* if(c == '}') */
		/* 	printf("Close Bracket"); */
		int charNum = (int)c;
		if(c >= low && c <= high){
			data[charNum] = ++data[charNum];
		}
	}
	
	printData();
	writeData();
	
	/* c = fgetc(file); */
	/* while(c != EOF){ */
	/* 	printf("%c", c); */
	/* 	c = fgetc(file); */
	/* } */

	/* while(fgets(line, sizeof(line), file)){ */
	/* 	for(int i = 0; i < strlen(line); ++i){ */
	/* 		char c = line[i]; */
	/* 		int charNum = (int)c; */
	/* 		if(c >= low && c <= high){ */
	/* 			printf("ASCII value of %c = %d", c, c); */
	/* 			printf("\t %i\n", charNum); */
	/* 			data[charNum] = ++data[charNum]; */
	/* 		} */
	/* 	} */
	/* } */

	/* for(int i = (int)low; i <= (int)high; ++i){ */
	/* 	#<{(| char indexChar = (char)i; |)}># */
	/* 	printf("%c - %i\n", i, data[i]); */
	/* } */

	/* printData(); */
}

void printData(){
	printf("Range: %c-%c", low, high);
	for(int i = (int)low; i <= (int)high; ++i){
		/* the %4 puts 4 empty placeholder spaces that are filled if the number of */
		/* occurences goes up a magnitude of 10 */
		printf("\n%c: %4i ", i, data[i]);
		for(int j = 0; j < data[i]; ++j){
			printf("#");
		}
	}
	printf("\n");
}

void writeData(){
	FILE *outFile = fopen("DataOut", "w");
	
	fprintf(outFile, "Range: %c-%c", low, high);
	for(int i = (int)low; i <= (int)high; ++i){
		fprintf(outFile, "\n%c: %4i ", i, data[i]);
		for(int j = 0; j < data[i]; ++j){
			fprintf(outFile, "#");
		}
	}
	fprintf(outFile, "\n");
}
