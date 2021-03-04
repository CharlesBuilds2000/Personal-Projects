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
            dy_Array();
            dy_Array(const data_type &inital_data);
            
            void append(const data_type &data);
            void insert(const data_type &data, const size_t &index);
            void remove(const data_type &element);
            int search(const data_type &element);
            void change(const size_t &index, const data_type data);
            void replace(const data_type &old_data, const data_type &new_data);

            data_type* array() const;
            size_t length() const; 

    };
}
