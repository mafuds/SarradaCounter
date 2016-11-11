#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) 
{
	FILE *data;
	time_t rawtime;
	struct tm *timeinfo;
	unsigned short int sarradas = 0;
	char input;
	
	// If there's an existing file, opens it. Otherwise, creates it
	if((data = fopen("sarradas.txt","r+")) == 0)
	{
		if((data = fopen("sarradas.txt","w+")) == 0)
		{
			printf("Nao foi possivel abrir o arquivo de sarradas");
			exit(1);	
		}
	}
	
	printf("\n\tWelcome to the Unesp Bright River BCC 2016 Sarrada Counter\n");
	printf("\tType 's' to increase the number of sarradas\n");
	printf("\tType 'q' to quit\n");
	scanf(" %c",&input);
	
		// Loop that controls the program. While the user types a sarrada command 's', it counts. If the command is 'q', the program will end
		while((input != 'q') && (input != 'Q'))
		{
			if((input == 's') || (input == 'S'))
				sarradas++;
					
			printf("\tSarradas total: %hu\n", sarradas);
			scanf(" %c",&input);
		}
	
	// Getting time from system
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	
	// Registering time and sarradas to file
	fprintf(data, "%s", asctime(timeinfo));
	fprintf(data, "Sarradas total: %hu", sarradas);
		
	printf("\nThank you! Have a nice day free of sarradas\n");
	
	fclose(data);
	
	return 0;
}
