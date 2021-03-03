#include "dy_array.h"
namespace charptr0
{
    template <typename data_type>
    dy_Array<data_type>::dy_Array() {this->size = 0;}

    template <typename data_type>
    dy_Array<data_type>::dy_Array(const data_type &inital_data)
    {
        this->data_ptr = new data_type[1];
        data_ptr[0] = inital_data;
        this->size = 1;
    }

    template <typename data_type>
    void dy_Array<data_type>::append(const data_type &data)
    {

    }

    template <typename data_type>
    data_type* dy_Array<data_type>::array() const
    {
        return this->data_ptr;
    }



}