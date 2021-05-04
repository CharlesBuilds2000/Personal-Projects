#include "essentials.cpp"

void merge(int* &nums, int left, int mid, int right)
{
    int* temp = new int[(right+1)-left]; //allocate mem to for sorted array

    int i = left; //left ptr
    int j = mid+1; //right ptr
    int k = 0; //ptr for temp array

    //compare
    while(i < mid+1 && j < right+1)
    {
        if(nums[i] < nums[j])
        {
            temp[k] = nums[i];
            i++;
        }

        else
        {
            temp[k] = nums[j];
            j++;
        }

        k++;
    }

    while(i < mid+1)
    {
        temp[k] = nums[i];
        i++;
        k++;
    }

    while(j < right+1)
    {
        temp[k] = nums[j];
        j++;
        k++;
    }

    //copy the sorted array back
    for(int i = left; i < right+1; i++)
    {
        nums[i] = temp[i-left];
    }

    delete[] temp;
}

void mergeSort(int* &nums, int left, int right)
{
    if(left < right)
    {
        int mid = (left+right)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
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

    //sort using mergesort
    mergeSort(nums, 0, size-1);

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