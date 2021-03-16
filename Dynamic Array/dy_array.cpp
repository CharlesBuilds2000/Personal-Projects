#include <iostream> //cout
#include "dy_array.h"

namespace charptr0
{
    template <typename data_type>
    dy_Array<data_type>::dy_Array() {this->size = 0;} //if no arguments are given, set up an empty array 

    template <typename data_type>
    dy_Array<data_type>::dy_Array(const data_type &inital_data) //set the inital_data to be the first element of the array
    {
        this->data_ptr = new data_type[1];
        data_ptr[0] = inital_data;
        this->size = 1; //set the size to 1
    }

    template <typename data_type>
    void dy_Array<data_type>::append(const data_type &data) //append an element 
    {
        if(this->size == 0) //if the array is empty, set the data to be the first element
        {
            this->data_ptr = new data_type[1];
            this->data_ptr[0] = data;
            this->size = 1;
            return;
        }

        this->size++; //increment size by 1

        data_type* modified_data = new data_type[size]; //create a new temp array with the new size

        for(size_t i = 0; i < size-1; i++) {modified_data[i] = data_ptr[i];} //copy the values over to the temp array

        modified_data[size-1] = data; //append the data to the end of the temp array

        delete[] this->data_ptr;

        this->data_ptr = new data_type[size]; //allocate the main array with the correct size

        for(size_t i = 0; i < this->size; i++) {this->data_ptr[i] = modified_data[i];} //copy back the values including the new element

        delete modified_data; //free the memory and delete the temp array
    }

    template <typename data_type>
    void dy_Array<data_type>::insert(const data_type &data, const size_t &index)
    {
        if(this->size == 0) {append(data); return;}

        bool passedTheIndex = false;
        this->size++; //increase the size
        data_type* modified_data = new data_type[size]; //create a new temp array with the new size

        for(size_t i = 0; i < this->size; i++) //copy all the values that came before the index
        {
            if(i == index) {modified_data[i] = data; passedTheIndex = true;} //once we reached the index, insert the new element
            else if(passedTheIndex) {modified_data[i] = this->data_ptr[i - 1];} //once the new element has been inserted, start to insert the rest of the element
            else {modified_data[i] = this->data_ptr[i];} //copy all values before the index

        } 

        delete[] this->data_ptr;

        this->data_ptr = new data_type[size]; //allocate the main array with the correct size

        for(size_t i = 0; i < this->size; i++) {this->data_ptr[i] = modified_data[i];} //copy back the values including the new element

        delete modified_data; //free the memory and delete the temp array        
    }

    template <typename data_type>
    int dy_Array<data_type>::search(const data_type &element) 
    {
        int index = -1;

        for(size_t i = 0; i < this->size; i++)
        {
            if(this->data_ptr[i] == element) {index = i; break;}
        }

        return index;
    }

    template <typename data_type>
    void dy_Array<data_type>::remove(const data_type &element)
    {
        if(this->size == 0) {return;}

        int index = -1; 

        for(size_t i = 0; i < size; i++) //find the element
        {
            if(this->data_ptr[i] == element) 
            {
                index = i; 
                break;
            }
        } 

        if(index == -1) {return;} //if no element was found

        for(size_t i = index; i < size-1; i++)
        {
            this->data_ptr[i] = data_ptr[i + 1];
        }

        this->size--; //decrement size by 1
    }

    template<typename data_type>
    void dy_Array<data_type>::change(const size_t &index, const data_type data) {this->data_ptr[index] = data;}

    template<typename data_type>
    void dy_Array<data_type>::replace(const data_type &old_data, const data_type &new_data)
    {
        for(size_t i = 0; i < this->size; i++)
        {
            if(this->data_ptr[i] == old_data) {this->data_ptr[i] = new_data;}
        }
    }

    template <typename data_type>
    data_type* dy_Array<data_type>::array() const {return this->data_ptr;}

    template <typename data_type>
    size_t dy_Array<data_type>::length() const {return this->size;}

}