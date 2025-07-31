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
	//!!!ADD ERROR HANDLING HERE PENDING
	int height, width, c;		
	printf("\a");
	printf("Input height: ");
	scanf("%d", &height);
	printf("Input width: ");
	scanf("%d", &width);

	
	int h[height][width];
	char inputs[width * 6 +2];
	
	//loop to get user's inputs
	while ((c = getchar()) != '\n' && c != EOF);
	printf("\nPlease enter %d numbers per row (0-255), separated by commas\n", width);
    printf("Example: 10, 25, 150\n\n");
    
    //ALL OF THIS WORKS, DO NOT CHANGE
	int i, j;
	for (i=0; i<height; i++)
	{
		printf("Row %d: ", i+1);
    	fgets(inputs,sizeof(inputs),stdin);  //string format ksi yun yung nsa specs lol
    	inputs[strcspn(inputs, "\n")] = 0;
    	
		//turn string into int
		char *ptr = inputs;
		int errorFound = 0;
		
		for(j=0; j<width; j++) {
			int value;
			int charsRead=0;
			
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
            ptr += charsRead;
            
            while (*ptr == ' ' || *ptr == '\t') {
                ptr++;
            }
            
            if (j < width - 1) {
                if (*ptr == ',') {
                    ptr++;
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
    	//printf("You entered: %s\n", inputs);	
    }
	
	
	//THIS ONE MAKIKITA MO KUNG PAANO SILA NAKA STORE
	/*
	h[0][0]  h[0][1]  h[0][2]
	h[1][0]  h[1][1]  h[1][2]
	h[2][0]  h[2][1]  h[2][2] etc.
	*/
	printf("\nYAY!\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%-5d", h[i][j]); 
        }
        printf("\n");
    }
	
	//DA FUNCTION
	imgCvtInttoFloat(height, width, &h[0][0], &f[0][0]);

	printf("\nConverted Float Image:\n");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%0.2f ", f[i][j]);
		}
		printf("\n");
	}
	return 0;
}
