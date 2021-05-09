#include "essentials.cpp"

void heapifiy(int* &nums, int size, int parent_index)
{
    int largest_index = parent_index;
    int left_child_index = 2*parent_index+1;
    int right_child_index = 2*parent_index+2;

    if(left_child_index < size && nums[left_child_index] > nums[largest_index])
    {
        largest_index = left_child_index;
    }

    if(right_child_index < size && nums[right_child_index] > nums[largest_index])
    {
        largest_index = right_child_index;
    }

    if(largest_index != parent_index)
    {
        swap(nums[parent_index], nums[largest_index]);
        heapifiy(nums, size, largest_index);
    }
}

void heapSort(int* &nums, int size)
{
    //build max heap
    for(int i = (size/2)-1; i >= 0; i--)
    {
        heapifiy(nums, size, i);
    }

    //sort and del largest num
    for(int i = size-1; i > 0; i--)
    {
        swap(nums[0], nums[i]);
        heapifiy(nums, i, 0);
    }
}

int main()
{
    int size = askUserForSize();
    int max_bound = askUserForMaxBound();
    int* nums = generateNums(size, max_bound);

    //print the array before any sorting is done
    cout << "Before sorting:\n";
    printArray(nums, size);

    //start the timer
    auto time_begin = std::chrono::steady_clock::now();

    //sort using heapsort
    heapSort(nums, size);

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
}