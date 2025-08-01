//Danica Marie Suizo
//Karl Andrei Ordinario
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_HEIGHT 1000
#define MAX_WIDTH 1000

int h[MAX_HEIGHT][MAX_WIDTH];
float f[MAX_HEIGHT][MAX_WIDTH];

extern void imgCvtInttoFloat(int height, int width, int* input, float* output);

int main()
{ 
	//asks user the height n weight 
	int height, width, c;		
	do{
		printf("Input height: ");
		scanf("%d", &height);
		
		if(height < 1){
			printf("Cannot be less than 1\n");
		}else if (height > MAX_HEIGHT){
			printf("Cannot be more than %d\n", MAX_HEIGHT);
		}
	}while(height < 1 || height > MAX_HEIGHT);
	
	do{
		printf("Input width: ");
		scanf("%d", &width);

		if(width < 1){
			printf("Cannot be less than 1\n");
		}else if (width > MAX_WIDTH){
			printf("Cannot be more than %d\n", MAX_WIDTH);
		}
	}while(width < 1 || width > MAX_WIDTH);

	
	int h[height][width];
	char inputs[width * 6 +2];
	
	//loop to get user's inputs
	while ((c = getchar()) != '\n' && c != EOF);
	printf("\nPlease enter %d numbers per row (0-255), separated by commas\n", width);
    printf("Example: 10, 25, 150\n\n");
    
    //Parses inputs and error handling
	int i, j;
	for (i=0; i<height; i++)
	{
		printf("Row %d: ", i+1);
    	fgets(inputs,sizeof(inputs),stdin);  //string format ksi yun yung nsa specs lol
    	inputs[strcspn(inputs, "\n")] = 0;
    	
		//turn string into int
		char *ptr = inputs; //pointer to input string
		int errorFound = 0; //error flag
		
		for(j=0; j<width; j++) {
			int value;
			int charsRead=0;
			
			//counts the chars read
			if (sscanf(ptr, "%d%n", &value, &charsRead) != 1) {
                printf("Error: Invalid format or not enough numbers. Please re-enter the row\n");
                errorFound = 1;
                break; 
            }
            
            if (value < 0 || value > 255) {
                printf("Error: The number %d is out of the valid range (0-255). Please re-enter the row\n", value);
                errorFound = 1;
                break; 
            }
            
            h[i][j] = value;
            ptr += charsRead;  //moves pointer past the chars read
            
            while (*ptr == ' ' || *ptr == '\t') {  //just to be sure if there are spaces in between
                ptr++;
            }
            
            if (j < width - 1) {
                if (*ptr == ',') {
                    ptr++;   //when comma, next number
                } else {
                    
                    printf("Error: Missing a comma after the number %d. Please re-enter the row\n", value);
                    errorFound = 1;
                    break;
                }
            }
		}
		
		if (!errorFound) {
            while (*ptr == ' ' || *ptr == '\t') {
                ptr++;
            }
            if (*ptr != '\0') {
                printf("Error: Too many numbers or extra characters found at the end. Please re-enter the row\n");
                errorFound = 1;
            }
        }
        
        if (errorFound) {
            i--;
        }
    	
    }
	
	//DA FUNCTION
	imgCvtInttoFloat(height, width, &h[0][0], &f[0][0]);

	float* flatF = &f[0][0];

	printf("\nConverted Float Image:\n");
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			printf("%0.2f ", flatF[i * width + j]);
		}
		printf("\n");
	}
	return 0;
}
