#include <iostream>
#include <cmath>

using std::cout;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//print the array
void printArray(int* nums, size_t size)
{
    for(int i = 0; i < size; i++) {std::cout << nums[i] << "\t";}
    std::cout << "\n";
}

//find the depth of the tree
int findMaxDepth(int* nums, size_t size, int depth = 0)
{
    if(size == 0) {return depth-1;}

    else {findMaxDepth(nums, size/2, ++depth);} //get the parent
}

//display all the element inside of the tree
void drawTree(int* nums, const size_t size, const int maxDepth, int currentDepth = 0)
{
    //determine how many element are in the current depth
    int numbers_of_element = pow(2, currentDepth);

    //determine where to start the index
    int index = pow(2, currentDepth)-1;

    cout << "Depth " << currentDepth << "\n";

    //print the values
    for(int i = 0; i < numbers_of_element; i++)
    {
        cout << nums[index] << " ";
        index++;
        
        if(index >= size) {cout << "\n"; return;} //return if it has reached the last element
    }

    cout << "\n\n";

    drawTree(nums, size, maxDepth, ++currentDepth); //use recursion to move to the next depth
}

//build max heap
void heapifiy(int* &nums, int size, int parent)
{
    int largest = parent;

    int left_child_index = 2*parent+1;
    int right_child_index = 2*parent+2;

    if(left_child_index < size && nums[left_child_index] > nums[largest]) 
    {
        largest = left_child_index;
    }

    if(right_child_index < size && nums[right_child_index] > nums[largest]) 
    {
        largest = right_child_index;
    }

    if(largest != parent)
    {
        swap(nums[parent], nums[largest]);
        heapifiy(nums, size, largest);
    }
}


