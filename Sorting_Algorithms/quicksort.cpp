#include "essentials.cpp"

int partition(int* &nums, int low, int high)
{
    //assuming the last element is our pivot
    
    int i = low; //low ptr
    int j = low; //high ptr

    while(j < high)
    {
        //if the value is higher than the pivot, swap the value with the low ptr
        if(nums[j] < nums[high])
        {
            swap(nums[i], nums[j]);
            i++; //increment the low ptr
        }

        j++; //increment the high ptr
    }

    swap(nums[i], nums[high]); //put the pivot into the right index

    return i; //the pivot is sorted, return the index
}

void quickSort(int* &nums, int low, int high)
{
    if(low < high)
    {
        int pivot = partition(nums, low, high);
        quickSort(nums, low, pivot-1);
        quickSort(nums, pivot+1, high);
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

    //sort using quicksort
    quickSort(nums, 0, size-1);

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