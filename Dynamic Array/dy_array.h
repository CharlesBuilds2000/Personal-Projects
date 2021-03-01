#pragma once
#include <string>
#include <typeinfo>
#include <vector>

namespace charptr0
{
    class dy_Array
    {
        private:
            size_t size;
            double* data_ptr;
        
        public:
            dy_Array();
            size_t length() const;

    };
}
