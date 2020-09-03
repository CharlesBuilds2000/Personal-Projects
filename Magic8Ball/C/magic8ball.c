#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 200 

int RandomNum() //This function will generate a random number from 0-16
{
    int randomNumber = rand()%17;
    return randomNumber;
}

void EightBallAnswers(int randNum) //It takes a random number generated above and correspond it to an answer
								   //All answers were taken from https://en.wikipedia.org/wiki/Magic_8-Ball
{
    printf("The Eight Ball Said: ");

    switch (randNum)
    {
		case 1:
			printf("It is certain");
			break;
		case 2:
			printf("As I see it, yes");
			break;
		case 3:
			printf("Don't count on it");
			break;
		case 4:
			printf("It is decidedly so");
			break;
		case 5:
			printf("Most likely");
			break;
		case 6:
			printf("My reply is no");
			break;
		case 7:
			printf("Without a doubt");
			break;
		case 8:
			printf("My sources say no");
			break;
		case 9:
			printf("Yes – definite)y");
			break;
		case 10:
			printf("Yes");
			break;
		case 11:
			printf("Outlook not so good");
			break;
		case 12:
			printf("You May rely on it");
			break;
		case 13:
			printf("Signs point to yes");
			break;
		case 14:
			printf("Very doubtful");
			break;
		default:
			printf("Concentrate and ask again");
			break;       
    }
}

char* MainMenu() //This function will grab the user's input
{
    char* string = (char*)malloc(MAXSIZE * sizeof(char)); //Allocated a dynamic array for storing 200 characters.
														  //Hopefully this is large enough to store the input
    int c; //This variable will help us grab the user input
    printf("-------------------------\nAsk Magic 8 Ball\n-------------------------\n");
    printf("Please state your problem: ");
    
    for(int i = 0; (c = getchar()) != '\n'; i++)
    {
        string[i] = c; //Store each character into the dynamic array
    }

    return string; //return the pointer
}


int main()
{
    while(true)
    {
        char* userInput = MainMenu(); //Store the user input into a char pointer

        if(*(userInput) == '.' && *(userInput + 1) == 'q') break; //if the first two characters were '.' and 'q', it will terminate the program

        int randomNumber = RandomNum(); //Grab a random number from the random number generator

        EightBallAnswers(randomNumber); //Based on the number, it will print out a response

        printf("\n");
        free(userInput);

    }
    
}