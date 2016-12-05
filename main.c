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
	unsigned short int sarradas = 0, level, memesTotal = 0,memeType, meme1 = 0, meme2 = 0;
	char input, details[DETAILS_FIELD], target[TARGET_FIELD];

	// If there's an existing file, opens it. Otherwise, creates it
	if((data = fopen("sarradas.txt","r+")) == 0)
	{
		if((data = fopen("sarradas.txt","w+")) == 0)
		{
			printf("It was not possible to open the sarradas' file");
			exit(1);
		}
	}

	printf("\n\tWelcome to the Unesp Bright River BCC 2016 Sarrada Counter\n");
	printf("\tType 's' to increase the number of sarradas\n");
	printf("\tType 'q' to quit\n");
	printf("\tType 'm' to increase the number of memes\n");
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
                fprintf(data, "\n%s", asctime(timeinfo));
				fprintf(data, "\nSarrada details: %s", details);
				fprintf(data, "\nTarget: %s\n\n", target);
				/***********************************************************************************/
			}
			else if((input == 'm') || (input == 'M')) // Beeing a meme, gets details
            {
                printf("\n\tPlease, select the meme:");
                printf("\n\t1 - WOWOWOWOWOWOWOOOWOOOOOWOWOOOW");
                printf("\n\t2 - BIzarro");
                printf("\n\tYour option: ");
                scanf("%hu",&memeType);

                // Getting time from system
                time(&rawtime);
                timeinfo = localtime(&rawtime);

                switch(memeType)
                {
                    case 1:
                        meme1++;

                        // Registering time and meme type to file
                        fprintf(data, "\n%s", asctime(timeinfo));
                        fprintf(data, "\nWOWOWOWOWOWOWOOOWOOOOOWOWOOOW: %hu\n", meme1);

                        break;

                    case 2:
                        meme2++;

                        // Registering time and meme type to file
                        fprintf(data, "%s", asctime(timeinfo));
                        fprintf(data, "\nBIzarro: %hu\n", meme2);

                        break;
                }

                memesTotal++;
            }
			else
				printf("\n\tInput not accepted. Please, enter a valid input (s for sarrada | m for meme | q to quit)");

			printf("\n\tNew input: ");
			scanf(" %c",&input);
		}

	// Registering the total of sarradas and memes to the file
	fprintf(data, "\nSarradas total: %hu", sarradas);
	fprintf(data, "\nMemes total: %hu", memesTotal);

	printf("\nThank you! Have a nice day free of sarradas\n");

	fclose(data);

	return 0;
}
