#pragma once

#include<iterator>
namespace CppSwift{
namespace Internal {

struct null_output_iterator : 
    std::iterator< std::output_iterator_tag,
                   null_output_iterator > {
    /* no-op assignment */
    template<typename T>
    void operator=(T const&) { }

    null_output_iterator & operator++() { 
        return *this; 
    }

    null_output_iterator operator++(int) { 
        return *this;
    }

    null_output_iterator & operator*() { return *this; }
};

}
}
