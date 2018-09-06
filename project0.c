#include <stdio.h>

/* Character representing the lowest character to count in this program */
char low;
/* Character representing the highest character to count in this program */
char high;
/* Int array of size 256 with each index being the int representation of an ASCII character */
int data[256];

/* Prints out the contents of the data array */
/* First line is shows the range that was provided in the format "Range: {a}-{b}" with 'a' being the low end of the range and 'b' being the high end of the range */
/* Following lines, starting with the low end of range and ending with high end of range are in the format: */
/* EX: */
/* J:   5 ##### */
/* Character being counted, followed by a colon, then number of times character appears in given file, right-aligned with 4 spaces initially between it and a colon,  */
/* followed by x many hashes where x is how many times the character appears */
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
	printf("Final number: %i", data[255]);
}

/* Exactly the same as printData(), but instead writes to a file */
/* Used for testing with given examples */
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

/* Reads command line arguments to determine range and reads in the provided file to be processed */
/* Performs necessary action on the data array to allow it to be printed and written out */
int main(int argv, char* argc[]){
	
	/* Initializes array with 0s at every index (because numbers represent number of characters in file) */
	for(int i = 0; i < 256; ++i)
		data[i] = 0;

	/* Will include all characters from space to '}' (close curly bracket)	 */
	/* space = 32 | '}' = 125 	 */
	if(argv == 1){
		low = ' ';
		high = '}';
	}

	/* Will range from first character provided from command line argument to '}'  */
	if(argv == 2){
		low = argc[1][0];
		high = '}';
	}

	/* Will range from first character to second character both supplied by command line arguments  */
	if(argv == 3){
		low = argc[1][0];
		high = argc[2][0];
	}

	/* Assigns file provided to a variable */
	FILE *file = stdin;
	char c;

	/* Steps through each character in the file provided and increments location in array corresponding  */
	/* to the character (by index) 	 */
	while(!feof(file)){
		c = fgetc(file);
		int charNum = (int)c; /* Gets int representation of char currently on */
		/* Only increments data in array if the char is in the range specified */
		if(c >= low && c <= high){
			data[charNum] = ++data[charNum];
		}
	}

	/* Prints data out to command line  */
	printData();
	/* Writes the data out to a file (used to test output with examples)  */
	/* writeData(); */

	return 0;
}
