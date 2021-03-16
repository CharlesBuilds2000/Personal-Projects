#pragma once

namespace charptr0
{   
    template <typename data_type>
    class dy_Array
    {
        private:
            size_t size;
            data_type* data_ptr;
        
        public:
            //default constructor, if no initial data is given, set up an empty array
            dy_Array(); 
            //if a initial data is given, set the data to be the first element
            dy_Array(const data_type &inital_data);
            
            //append an element to the back of the array
            void append(const data_type &data);

            //insert an element to an specific index
            void insert(const data_type &data, const size_t &index);

            //remove an element
            void remove(const data_type &element);

            //search an element, return its index, if not no element is found, return -1
            int search(const data_type &element);

            //change an element given a specific index
            void change(const size_t &index, const data_type data);

            //replace all element with the new element
            void replace(const data_type &old_data, const data_type &new_data);

            //return the dynamic array
            data_type* array() const;

            //return the size
            size_t length() const; 

    };
}