#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>


template<typename T,typename Alloc>
class vector
{
    public:
    typedef T value_type;
    typedef Alloc alloc_type;
    typedef value_type & reference;
    typedef value_type * pointer;
    typedef const value_type & const_reference;
    typedef const value_type * const_pointer;
    typedef value_type * iterator;
    typedef const value_type * const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::size_t size_type;
    typedef ptrdiff_t difference_type;
    
    vector()
    {
        
    }
    explicit vector(const alloc_type &)
    {
        
    }
    explicit vector(size_type,const alloc_type & = alloc_type() )
    {
        
    }
    vector(size_type,const value_type v,const alloc_type &=alloc_type() )
    {
        
    }
    template <typename InputIter>
    vector(InputIter begin,InputIter end,const alloc_type & = alloc_type() )
    {
        
    }
    template<typename U>
    vector(std::initialize_list<U>,const alloc_type & = alloc_type() )
    {
        
    }
    vector(const vector &)
    {
        
    }
    vector(const vector &,const alloc_type &)
    {
        
    }
    vector(vector &&)
    {
        
    }
    vector(vector &&,const alloc_type &)
    {
        
    }
    ~vector()
    {
        
    }
    
    iterator begin()
    {
        
    }
    const_iterator begin()const
    {
        
    }
    iterator end()
    {
        
    }
    const_iterator end()const
    {
        
    }
    reverse_iterator rbegin()
    {
        
    }
    const_reverse_iterator rbegin()const
    {
        
    }
    reverse_iterator rend()
    {
        
    }
    const_reverse_iterator rend()const
    {
        
    }
    
    const_iterator cbegin()const
    {
        
    }
    const_iterator cend()const
    {
        
    }
    const_reverse_iterator crbegin()const
    {
        
    }
    const_reverse_iterator crend()const
    {
        
    }
    reference front()
    {
        
    }
    const_reference front()const
    {
        
    }
    
    reference back()
    {
        
    }
    
    const_reference back()const
    {
        
    }
    
    pointer data()
    {
        
    }
    
    const_pointer data()const
    {
        
    }
    
    reference operator[](size_type ) const
    {
        
    }
    
    const_reference operator[](size_type ) const
    {
        
    }
    
    reference at(size_type )
    {
        
    }  
    
    const_reference at(size_type )const
    {
        
    }
    void swap(vector &)noexcept
    {
    }
    
};
    
