#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	FILE *data;
	unsigned short int sarradas = 0;
	char input;
	
	printf("\n\tWelcome to the Unesp Bright River BCC 2016 Sarrada Counter\n");
	printf("\tType 's' to increase the number of sarradas\n");
	printf("\tType 'q' to quit\n");
	scanf(" %c",&input);
	
		while((input != 'q') || (input != 'Q'))
		{
			if((input == 's') || (input == 'S'))
				sarradas++;
					
			printf("\tSarradas total: %hu\n",sarradas);
			scanf(" %c",&input);		
		}
		
	printf("Thank you! Have a nice day free of sarradas\n");
		
	return 0;
}
