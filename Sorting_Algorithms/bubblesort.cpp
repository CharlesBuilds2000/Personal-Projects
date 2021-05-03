#include "essentials.cpp"

void bubblesort(int* &nums, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size-(i+1); j++)
        {
            if(nums[j] > nums[j+1]) {swap(nums[j], nums[j+1]);}
        }
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

}