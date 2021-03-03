#pragma once

namespace charptr0
{   
    template <typename data_type>
    class dy_Array
    {
        private:
            size_t size;
            data_type* data_ptr;
            data_type m_min;
            data_type m_max;
            data_type m_sum;
        
        public:

            dy_Array();
            dy_Array(const data_type &inital_data);
            
            void append(const data_type &data);
            void insert(const data_type &data);
            void remove(const data_type &data);

            data_type sum() const;
            data_type average() const;
            data_type min() const;
            data_type max() const;

            data_type* array() const;
            size_t length() const; 

    };
}
