#include "bag.h"
typedef std::size_t size_type;



bag::bag(size_type _capacity)
{
    capacity = _capacity;
    data = new value_type (_capacity);
    used = 0;
}

void bag::reserve(size_type new_size)
{
    value_type* new_data = new value_type (new_size);
    value_type* w = new_data;
    copy_array (new_data,data,used);
    delete [] data;
    data = new_data;

    // T* new_array = new T [capacity];
    // T* w = new_array;
    // copy_array (new_array, a, size) ;
    // delete []a;
    // return new_array
}
    //copy from the original
    //


//=================================
//Big 3
//Tested
bag::bag(bag& src)
{
    //since this is constructor not allocated yet
    capacity = src.capacity ;
    data = new value_type (capacity);
    used = src.used;
    copy_array(data,src.data,src.used);
}

//tested
bag& bag::operator= (const bag& otherClass)
{
    if(this == &otherClass)
    {
        return *this;
    }
    delete [] data;
    capacity = otherClass.capacity ;
    used = otherClass.used;
    data = new value_type (capacity);
    copy_array(data,otherClass.data,otherClass.used);

    return *this;
}
bag::~bag()
{
    delete[]data;
    data = nullptr;
    std::cout << "Destructor Fired : \n";
}
//=================================
//5.

bool bag::erase(const value_type& target) // tested 
{
    //PRE :: use shift-left function
    //POST :: delete all the target
    value_type* w = data;
    value_type* end = data + used;

    while(w != end)
    {
        if (*w == target)
        {
            shift_left(w);
        }
        else
        {
        w++;
        }
    }
}

bool bag::erase_one(const value_type& target) // tested
{
    value_type* w = data;
    value_type* end = data + used;
    while(w != end)
    {
        if (*w == target)
        {
            shift_left(w);
            return true;
        }
        else
        {
        w++;
        }
    }
}

//================================= //helper =================================

//helper
void bag::copy_array (value_type* dest,const value_type* src,size_type how_many_to_copy)
{
    bool debugging = true ;
    if(debugging)
    {
    value_type* w = dest;
    value_type* endOfArray = dest+how_many_to_copy;
    for (;w < endOfArray; w++)
    {
        *w = *src;
        src++;
    }
    }
}

//precondition : take the address of where you want to shift left
//post         : shift left at that position decre used by one ;

void bag::shift_left (value_type* position)
{

    value_type *w = position;
    value_type *end_w = data + used;
    value_type *w2 = w + 1 ;

    while (w != end_w)
    {
        *w = *w2;
        w++;
        w2++;
    }
    used--;
}

//================================= end =================================


// tested
void bag::insert(const value_type& entry)
{
    value_type* w =  data + used ;

    *w = entry;
    used++;
}

//friend functions
