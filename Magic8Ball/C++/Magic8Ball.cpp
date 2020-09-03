#include <iostream>
#include <ctime>
#include <string>

using std::cout;
using std::cin;

int GenerateRandNum() //This function will generate a random number from 0-16
{
	int luckyNumber = rand() % 17; //Although the 8 balls supports up to 20 answers, 5 of those answers were asking the user to try again, which is no fun
	return luckyNumber;
}

std::string EightBallAnswers(int randNum) //This function will take a random number generated from above and correspond it to a possible answer
										  //All 8 ball answers are from https://en.wikipedia.org/wiki/Magic_8-Ball
{
	std::string answer;
	switch (randNum)
	{
		case 1:
			answer = "It is certain";
			break;
		case 2:
			answer = "As I see it, yes";
			break;
		case 3:
			answer = "Don't count on it";
			break;
		case 4:
			answer = "It is decidedly so";
			break;
		case 5:
			answer = "Most likely";
			break;
		case 6:
			answer = "My reply is no";
			break;
		case 7:
			answer = "Without a doubt";
			break;
		case 8:
			answer = "My sources say no";
			break;
		case 9:
			answer = "Yes – definitely";
			break;
		case 10:
			answer = "Yes";
			break;
		case 11:
			answer = "Outlook not so good";
			break;
		case 12:
			answer = "You May rely on it";
			break;
		case 13:
			answer = "Signs point to yes";
			break;
		case 14:
			answer = "Very doubtful";
			break;
		default:
			answer = "Concentrate and ask again";
			break;

	}

	return answer;
}

std::string MainMenu() 
{
	std::string UserInputString;
	cout << "-------------------------" << std::endl;
	cout << "Ask Magic 8 Ball" << std::endl << "-------------------------" << std::endl << "Please state your problem: ";
	std::getline(cin, UserInputString);

	return UserInputString;
	
}

int main()
{
	while (true)
	{
		std::string Userdecision = MainMenu();

		if (Userdecision == ".quit" || Userdecision == ".Quit") break; //if the user inputs either .quit or .Quit, it will terminate the program

		int luckyNumber = GenerateRandNum(); //store the random number into this integer

		std::string AnswerFromEightBall = EightBallAnswers(luckyNumber); //store the return string into this string variable

		cout << "Eight Ball Said: " << AnswerFromEightBall << std::endl; //print out the response from the 8 ball

		//the loop will repeat itself until the user force closed the program or type .quit/.Quit into the terminal

	}
	
}

