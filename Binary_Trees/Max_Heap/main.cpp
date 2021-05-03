#include <ctime>
#include <assert.h>
#include "tree.cpp"

using namespace std;

//random number generator
int* generateNums(size_t amount = 10)
{
    assert(amount > 0);

    int* nums = new int[amount];

    srand(time(NULL)); //start the clock

    for(int i = 0; i < amount; i++)
    {
        nums[i] = rand() % (101); //generate random nums from 0-100
    }
    
    return nums;
}

size_t askUserForSizeOfArray()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    return size;    
}

int main()
{
    while(true)
    {
        size_t size = askUserForSizeOfArray(); //determine the size of the array 
        int* nums = generateNums(size); //generate the array w. random nums from 0-100
        int depth = findMaxDepth(nums, size);

        cout << "Before\n";

        drawTree(nums, size, depth); //draw the tree before building max heap

        for(int i = (size/2)-1; i >= 0; i--)
        {
            heapifiy(nums, size, i);
        }

        cout << "\nAfter\n";

        drawTree(nums, size, depth); //draw the tree after building max heap

        delete[] nums;
    }
}