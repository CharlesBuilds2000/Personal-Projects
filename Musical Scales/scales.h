#pragma once
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;

enum Scales
{
    chromatic, major, minor, harmonic_minor, melodic_minor, penatonic, blue
};


class Node //Linked List nodes
{
    public:
    std::string data;
    Node* next;

    Node(std::string data)
    {
        this->data = data;
        next = NULL;
    }
};

int scale;
int key;
std::string input_key;
std::string input_scale;

//These are all the valid keys
vector<std::string>Keys = {"a", "a#", "b", "c", "c#", "d", "d#", "e", "f", "f#", "g", "g#"}; 

//These are all the valid scales
vector<std::string>ScaleTypes = {"chromatic", "major", "minor", "hminor", "mminor", "penatonic", "blue"};

//These are the rules for creating each of the scales 'h' represent a half-step, 'w' represent a whole-step, 
//and 't' represent a 3 half-steps or minor third
vector<char>Chromatic = {'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h', 'h'};
vector<char>Major = {'w', 'w', 'h', 'w', 'w', 'w', 'h'};
vector<char>Minor = {'w','h','w','w','h','w','w'};
vector<char>HMinor = {'w','h','w','w','h','t','h'};
vector<char>MMinor = {'w','h','w','w','w','w','h'};
vector<char>Penatonic = {'w', 'w', 't', 'w', 't'};
vector<char>Blue = {'t', 'w','h', 'h', 't', 'w'};


void print(vector<char>scale, Node* root)
{
    cout << root->data << "\t"; //Print out the root note first
    for(char i : scale) 
    {
        if(i == 'h') //If the chosen scale has 'h', it means to move the ptr once (half step)
        {
            root = root->next;
        }

        else if(i == 'w') //If the chosen scale has 'w', it means to move the ptr twice (whole step)
        {
            root = root->next->next;
        }

        else // Move the ptr 3 times (3 half steps)
        {
            root = root->next->next->next;
        }

        cout << root->data << "\t"; //Print out the note
    }

    cout << "\n";
}

//Check if the user input is valid
bool validKey(std::string inputKey)
{
    for(int i = 0; i < Keys.size(); i++)
    {
        if(inputKey == Keys[i]) 
        {
            key = i;
            return true;
        }
    }

    return false;
}

bool validScale(std::string inputScale)
{
    for(int i = 0; i < ScaleTypes.size(); i++)
    {
        if(inputScale == ScaleTypes[i])
        {
            scale = i;
            return true;
        }
    }

    return false;
}
