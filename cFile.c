//Danica Marie Suizo
//Karl Andrei Ordinario
#include <stdio.h>
#include <stdlib.h>

extern int imgCvtInttoFloat();

int main()
{ 
	//asks user the height n weight
	int height, width;		
	printf("\a");
	printf("Input height: ");
	scanf("%d", &height);
	printf("Input width: ");
	scanf("%d", &width);
	
	//loop to get user'
	int h[height], w[width], total;
	total=6*width;
	printf("total = %d", total);
	char inputs[total];

	scanf("%*[^\n]");scanf("%*c");
	int i;
	for (i=0; i<height; i++)
	{
		printf("Row %d: ", i+1);
    	fgets(inputs,sizeof(inputs),stdin);
    	printf("You entered: %s\n", inputs);
		
	}
	
	imgCvtInttoFloat();
	return 0;
}
