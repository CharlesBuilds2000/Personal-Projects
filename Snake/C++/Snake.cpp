#include <iostream>
#include <vector>
#include <conio.h>
#include "GameManager.h"

using std::cout;
using std::endl;

void Display() //To display the border, the player, and the fruit
{
    system("CLS");

    for (int i = 1; i <= Row; i++)
    {
        if (i > 1 && i < Row) { cout << "*"; } //If i does not represent the top border or the bottom border, it will start 
                                              //the new row with a "*"

        for (int j = 1; j <= Column; j++)
        {   
            bool createWhiteSpace = true; //if this is true, the program will create a " "

            if (i == 1 || i == Row) //Draw the border that is on the top and the bottom
            {
                cout << "*";

                if (j == Column) cout << endl;
            }

            else if (player.getPosX() == j && player.getPosY() == i) //if the player location is located at a specific i and j, it will print out "O" to represent the snake's head
            //after printing "O", we want to set the boolean to false to make sure we do not print out a unnecessary " "
            { 
                cout << "O"; 
                createWhiteSpace = false;

            }

            else if (fruit.getPosX() == j && fruit.getPosY() == i) { cout << "F"; createWhiteSpace = false; }
            //Same concept as the player

            for (int k = 1; k <= player.getBodyCount(); k++) //If the snake has a body, it will show it here
            {
                //Grab the previous location from the vector x and y
                playerBody.setPosX(playerLocationX[playerLocationX.size() - k]); 
                playerBody.setPosY(playerLocationY[playerLocationY.size() - k]);

                if (j == playerBody.getPosX() && i == playerBody.getPosY()) //If i and j match the coords, it will print the body
                {
                    cout << "o";
                    createWhiteSpace = false;
                }

                if (player.getPosX() == playerBody.getPosX() && player.getPosY() == playerBody.getPosY()) //If the player ran into their own body
                {
                    gameOver = true;
                }

            }

            if (createWhiteSpace && i > 1 && i < Row && j >= 1 && j <= Column - 1) //create a space if the boolean is true and we are not at a border
            {
                cout << " "; 
                if (j == Column - 1) { cout << "*" << endl; }
            }


        }
    }

    cout << endl << "Score: " << player.getScore() << endl; //Display the score at the bottom of the screen
}

void Movement()
{
    //Every movement is tracked using vectors, we can use these vectors to create a path for the bodies to follow
    playerLocationX.push_back(player.getPosX());
    playerLocationY.push_back(player.getPosY());

    switch (player.getMove())
    {
        case UP:
            player.setPosY(player.getPosY() - 1); //By subtracting 1, we are technically "moving up" the spaces in the terminal
            break;
        case DOWN:
            player.setPosY(player.getPosY() + 1);
            break;
        case LEFT:
            player.setPosX(player.getPosX() - 1);
            break;
        case RIGHT:
            player.setPosX(player.getPosX() + 1);
            break;
        default:
            break;
    }

    while (_kbhit()) //If it register a key press
    {
        switch (_getch())//If a key is pressed, it will grab the character
        {
        case 'w':
            player.setMove(UP);
            break;
        case 's':
            player.setMove(DOWN);
            break;
        case 'a':
            player.setMove(LEFT);
            break;
        case 'd':
            player.setMove(RIGHT);
            break;
        default:
            break;
        }
    }
}

void Interaction() //How the game will react if there is any interaction/collision between the objects
{
    if (player.getPosX() == Column || player.getPosY() == Row || player.getPosX() == 0 || player.getPosY() == 0) //If the player collide with the border
    {
        cout << endl << "Game Over" << endl;
        gameOver = true; //End the main loop

    }

    if (player.getPosX() == fruit.getPosX() && player.getPosY() == fruit.getPosY()) //If the player collect the fruit
    {
        player.setScore(player.getScore() + 10); //Add 10 to the score
        player.setBodyCount(player.getBodyCount() + 1); //Add 1 snake body to the player

        //The Fruit will generate at a random location
        fruit.setRandomLocationX(); 
        fruit.setRandomLocationY();
    }
}


int main()
{
    while (!gameOver)
    {
        Display();
        Movement();
        Interaction();
    }

    system("Pause");
    

}


