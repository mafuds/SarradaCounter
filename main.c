#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DETAILS_FIELD 50
#define TARGET_FIELD  20

int main(int argc, char *argv[])
{
	FILE *data;
	// Variables to get time from system (in order to register to the file)
	time_t rawtime;
	struct tm *timeinfo;
	//
	unsigned short int sarradas = 0, level;
	char input, details[DETAILS_FIELD], target[TARGET_FIELD];

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
				printf("\n\tPlease, detail the level of the sarrada (from 1 - Normal to 10 - HE COMPLETELY F*CKED UP): "); // because there are different levels, so we need to count differently
				scanf("%hu",&level);

					while((level < 1) || (level > 10))
					{
						printf("\n\tLevel not accepted. Please, enter a valid level (from 1 to 10)");
						printf("\n\tLevel: ");
						scanf("%hu",&level);
					}

				printf("\n\tPlease, register the target: ");
				fflush(stdin);
				gets(target);

				sarradas += level;

				/****************Registers the latest sarrada to the file***************************/

                // Getting time from system
                time(&rawtime);
                timeinfo = localtime(&rawtime);

                // Registering time and latest sarrada to file
                fprintf(data, "%s", asctime(timeinfo));
				fprintf(data, "\nSarrada details: %s", details);
				fprintf(data, "\nTarget: %s\n\n", target);
				/***********************************************************************************/
			}
			else
				printf("\n\tInput not accepted. Please, enter a valid input (s for sarrada | q to quit)");

			printf("\n\tNew input: ");
			scanf(" %c",&input);
		}

	// Registering the total of sarradas to the file
	fprintf(data, "\nSarradas total: %hu", sarradas);

	printf("\nThank you! Have a nice day free of sarradas\n");

	fclose(data);

	return 0;
}
