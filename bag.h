#ifndef __DESKTOP_CS_8_LAB_4_BAG_H_
#define __DESKTOP_CS_8_LAB_4_BAG_H_


#include <iostream>

class bag {
public:
typedef int value_type;
typedef std::size_t size_type;

bag(size_type capacity);


//=================================
//big3
bag(bag& src); // copy constructor
bag& operator= (const bag& otherClass); // assignment operator]
~bag();
//=================================

// 4. setters/getters

size_type getCapacity(){return capacity;}
size_type getSize(){return used;}
value_type* getData(){return data;}

//=================================

// 5. two 'erase' member functions


bool erase(const value_type& target); // remove all 'target' from the bag //need shift left function
bool erase_one(const value_type& target); // remove one 'target' from the bag
// 6. 'insert' member function
void insert(const value_type& entry); // insert entry into the bag - done



/* 7. If there is no space to store a new entry,
you must double the capacity using the reserve
function before storing the new entry.*/
void reserve(size_type new_size);
// 8. squeeze function
// 9. sort function
// 10. operator=
// 11. operator<<

friend std::ostream& operator<< (std::ostream& os,const bag& yourBag)
{
    value_type* w = yourBag.data;
    for (int i = 0; i < yourBag.used; i++ )
    {
        os << *w << " " ;
        w++;
    }
    return os;
}
/*------ 4 friend functions -------*/
// 12. bag operator +(const bag& b1, const bag& b2);
// 13. bag operator -(const bag& b1, const bag& b2);
// 14. bag operator &(const bag& b1, const bag& b2);
// 15. bag operator ^(const bag& b1, const bag& b2);
// You may add more member functions, if needed.

void copy_array (value_type* dest,const value_type* src,size_type size) ;
void shift_left (value_type* my_array);
private:
value_type* data; // The array to store items
size_type used; // How much of array is used
size_type capacity; // The size of 'data'
};

#endif // __DESKTOP_CS_8_LAB_4_BAG_H_


