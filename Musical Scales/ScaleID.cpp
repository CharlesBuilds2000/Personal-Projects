#include <iostream>
#include <vector>
#include <string>
#include "scales.h"

using std::cout;
using std::cin;
using std::endl;

//Create the Linked List
Node* Initialize()
{
    Node* head = NULL;
    Node* tail = NULL;

    for(int i = 0; i < Keys.size(); i++)
    {
        Node* temp = new Node(Keys[i]);

        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    tail->next = head; //Make the last elements points back to the start of the list

    return head;
}

int UserInput()
{
    cout << "Enter a Key: ";
    cin >> input_key;
    for(int i = 0; i < input_key.size(); i++) {input_key[i] = tolower(input_key[i]);} //Make the input lowercase
    if(!validKey(input_key)) return 1; //If the input key is not equal to a valid key, it will terminate the function

    cout << "Enter a Scale: ";
    cin >> input_scale;
    for(int i = 0; i < input_scale.size(); i++) {input_scale[i] = tolower(input_scale[i]);} //Make the input lowercase
    if(!validScale(input_scale)) return 1; //If the input key is not equal to a valid scale, it will terminate the function

    //If everything is valid, it will terminate the function
    return 0;

}

void printScale(int key, int scale, Node* head)
{
    Node* temp = head;

    while(temp->data != Keys[key]) temp = temp->next; //Set the head ptr to point to the root note

    switch (scale) //Based on the scale chosen by the user, it will print out that scale
    {
        case chromatic:
            print(Chromatic, temp);
            break;
        
        case major:
            print(Major, temp);
            break;
        
        case minor:
            print(Minor, temp);
            break;

        case harmonic_minor:
            print(HMinor, temp);
            break;
        
        case melodic_minor:
            print(MMinor, temp);
            break;

        case penatonic:
            print(Penatonic, temp);
            break;

        case blue:
            print(Blue, temp);
            break;
        
        default:
            break;
    }
}

int main()
{
    Node* Start = Initialize(); //Save the linked list into a variable

    while(true)
    {
        if(UserInput() != 1) //If the function return any input other than 1, it represent all inputs are valid
        {
            printScale(key, scale, Start); //Print the scale
        }

        else //Otherwise, the input are not valid
        {
            cout << "Invalid Key or scale\n";
            cout << "Here are the list of acceptable keys: ";
            for(std::string i : Keys) cout << "{" << i << "} "; //Print out all the acceptable keys
            cout << "\nHere are the list of acceptable scales: ";
            for(std::string i : ScaleTypes) //Print out all the acceptable scales
            {
                if(i == "minor") cout << "{" << i << " (Natural Minor)} ";
                else if(i == "hminor") cout << "{" << i << " (Harmonic Minor)} ";
                else if(i == "mminor") cout << "{" << i << " (Melodic Minor)} ";
                else cout << "{" << i << "} ";
            }

            cout << endl;
        }
    } 
}
