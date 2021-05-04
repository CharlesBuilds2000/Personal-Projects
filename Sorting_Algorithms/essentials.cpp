/*
    This file provides important functions for the Sorting_Algorithms folder
    This is here to avoid writing dup code and #includes

*/

#pragma once

#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <ctime>
#include <chrono>

using std::cin;
using std::cout;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int* generateNums(int amount = 10, int max_bound = 100)
{
    srand(time(NULL));

    int* nums = new int[amount];

    for(int i = 0; i < amount; i++)
    {
        nums[i] = rand() % (max_bound + 1);
    }

    return nums;
}

int askUserForSize()
{
    int size;

    cout << "Please enter the size of the array: ";
    cin >> size;

    assert(size > 0);

    return size;
}

int askUserForMaxBound()
{
    int max_bound;

    cout << "Please enter the max bound: ";
    cin >> max_bound;

    assert(max_bound >= 0);

    return max_bound;
}


void printArray(const int* nums, const int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << nums[i] << "\t";
    }   

    cout << "\n";
}

/*
    Main function template code

    int size = askUserForSize();
    int max_bound = askUserForMaxBound();
    int* nums = generateNums(size, max_bound);

    //print the array before any sorting is done
    cout << "Before sorting:\n";
    printArray(nums, size);

    //start the timer
    auto time_begin = std::chrono::steady_clock::now();

    //sort using bubblesort
    bubblesort(nums, size);

    //stop the timer
    auto time_end = std::chrono::steady_clock::now();
    
    //print the array after sorting
    cout << "After sorting:\n";
    printArray(nums, size);

    //displaying the elasped time
    if(std::chrono::duration_cast<std::chrono::milliseconds> (time_end - time_begin).count() == 0)
    {
        cout << "It took " <<  std::chrono::duration_cast<std::chrono::nanoseconds> (time_end - time_begin).count() << " ns to complete this sorting algorithm\n";
    }

    else {cout << "It took " <<  std::chrono::duration_cast<std::chrono::milliseconds> (time_end - time_begin).count() << " ms to complete this sorting algorithm\n";}
*/