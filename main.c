#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) 
{
	FILE *data;
	// Variables to get time from system (in order to register to file)
	time_t rawtime;
	struct tm *timeinfo;
	//
	unsigned short int sarradas = 0;
	char input, details[50], target[20];
	
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
			if((input == 's') || (input == 'S')) // Beeing a sarrada, gets details and target
			{
				printf("\n\tPlease, detail the sarrada: ");
				fflush(stdin);
				gets(details);
				printf("\n\tPlease, register the target: ");
				fflush(stdin);
				gets(target);
				sarradas++;	
			}
					
			printf("\n\tNew input: ");
			scanf(" %c",&input);
		}
	
	// Getting time from system
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	
	// Registering time and sarradas to file
	fprintf(data, "%s", asctime(timeinfo));
	fprintf(data, "Sarrada details: %s", details);
	fprintf(data, "\nTarget: %s", target);
	fprintf(data, "\nSarradas total: %hu", sarradas);
		
	printf("\nThank you! Have a nice day free of sarradas\n");
	
	fclose(data);
	
	return 0;
}
