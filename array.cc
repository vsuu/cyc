
#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <type_traits>

template<typename T,size_t N>
    struct array_trait
    {
        typedef T type[N];
        
        static T *_S_Ptr( const type &_t) noexcept
        {
            return const_cast<T *>(_t);
        }
        static T & _S_Ref_at(const type &_t,size_t n) noexcept
        {
            return const_cast<T &>(_t[n]);
        }
    };
    
    template<typename T>
    struct array_trait<T,0>
    {
        struct type {};
        static T *_S_Ptr( const type &_t) noexcept
        {
            return nullptr;
        }
        static T & _S_Ref_at(const type &_t,size_t n) noexcept
        {
            return *static_cast<T*>(nullptr);
        }
        
    };

template<typename T,size_t N>
    class array
{
    public:
        typedef T value_type;
        typedef T & reference;
        typedef const T & const_reference;
        typedef T * pointer;
        typedef const T * const_pointer;
        typedef pointer iterator;
        typedef const_pointer const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
        
        iterator begin() noexcept
        {
            return iterator(data());
        }
        iterator end() noexcept
        {
            return iterator(data()+N);
        }      
        const_iterator begin()const noexcept
        {
            return const_iterator(data());
        }
        const_iterator end()const noexcept
        {
            return const_iterator(data()+N);
        }
        const_iterator cbegin()const noexcept
        {
            return const_iterator(data());
        }
        const_iterator cend()const noexcept
        {
            return const_iterator(data()+N);
        }
        reverse_iterator rbegin() noexcept
        {
            return reverse_iterator(end());
        }
        reverse_iterator rend() noexcept
        {
            return reverse_iterator(begin());
        }
        const_reverse_iterator rbegin()const noexcept
        {
            return const_reverse_iterator(end());
        }
        const_reverse_iterator rend()const noexcept
        {
            return const_reverse_iterator(begin());
        }
        const_reverse_iterator crbegin()const noexcept
        {
            return const_reverse_iterator(end());
        }
        const_reverse_iterator crend()const noexcept
        {
            return const_reverse_iterator(begin());
        }
        constexpr size_t size()const noexcept
        {
            return N;
        }
        constexpr size_t max_size()const noexcept
        {
            return N;
        }
        constexpr bool empty()const  noexcept
        {
            return N==0;
        }
        reference front() noexcept
        {
            return *begin();
        }
        constexpr const_reference front() const noexcept
        {
            return *begin();
        }
        reference back() noexcept
        {
            return N?*(end()-1):*end();
        }
        constexpr const_reference back() noexcept
        {
            return N?*(end()-1):*end();
        }
        pointer data() noexcept
        {
            return array_trait<T,N>::_S_Ptr(Mem);
        }
        const_pointer data()const noexcept
        {
            return array_trait<T,N>::_S_Ptr(Mem);
        }
        reference operator[] (size_t index)
        {
            return array_trait<T,N>::_S_Ref_at(Mem,index);
        }
        const_reference operator[](size_t index)const
        {
            return array_trait<T,N>::_S_Ref_at(Mem,index);
        }
        reference at(size_t index)
        {
            return index<N?array_trait<T,N>::_S_Ref_at(Mem,index):(throw std::out_of_range("1"),array_trait<T,N>::_S_Ref_at(Mem,index));
        }
        const_reference at(size_t index)const
        {
            return index<N?array_trait<T,N>::_S_Ref_at(Mem,index):
                (throw std::out_of_range("2"),array_trait<T,N>::_S_Ref_at(Mem,0) );
        }
        
        void swap(array &o)
        {
            std::swap_ranges(begin(),end(),o.begin());
        }
        void fill(const value_type & v)
        {
            std::fill_n(begin(),size(),v);
        }
        
        typename array_trait<T,N>::type Mem;
};

template<size_t M,typename T,size_t N>
    inline constexpr T & get(array<T,N>& arr) noexcept
    {
        static_assert(M<N,"out_of_range");
        return array_trait<T,N>::_S_Ref_at(arr.Mem,M);
    }
    
template<size_t M,typename T,size_t N>
    inline constexpr const T &get(const array<T,N> & arr) noexcept
    {
        static_assert(M<N,"out_of_range");
        return array_trait<T,N>::_S_Ref_at(arr.Mem,M);
    }
 
 template<size_t M,typename T,size_t N>
    inline constexpr T && get(array<T,N> && arr) noexcept
    {
        static_assert(M<N,"out_of_range");
        return std::move(get<M>(arr));
    }
    
 template<typename T,size_t N>
    inline void swap(array<T,N> &a,array<T,N> &b) noexcept(noexcept(a.swap(b)))
    {
        a.swap(b);
    }
    
    template<typename T>
        class tuple_size;
        
  template<typename T,size_t N>
     struct tuple_size<array<T,N>> : public std::integral_constant<size_t,N>
     {};
  
  template<size_t N,typename T>
    class tuple_element;
    
  template<size_t N,typename T,size_t M>
    struct tuple_element<N,array<T,M>>
    {
        static_assert(N<M,"out_of_range");
        typedef T type;
    };


using std::cout;
using std::endl;

int main()
{
    array<int,5> arr{1,2,3,4,5};
    array<int,5> brr{2,3};
    arr.swap(brr);
    
    for(int i=0;i<arr.size();++i)
    {
        cout<<arr.at(i)<<',';
    }
    cout<<"\b "<<endl;
    cout<< arr.front()<<endl;
    cout<< arr.back()<<endl;
    cout<< get<2>(brr)<<endl;
    return 0;
}