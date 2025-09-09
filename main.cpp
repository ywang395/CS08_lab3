#include "bag.cpp"
#include <iostream>

int main()
{
    bool testing_big3 = true;
    bool testing_insert_and_constructor = false ;
    bool testing_shift_left = false ;


    if(testing_insert_and_constructor)
    {
    bag myBag(30);
    myBag.insert(40);
    myBag.insert(30);
    std::cout << myBag;
    return 0;
    }

    if(testing_big3)
    {
        bag myBag(3);
        bag yourBag(30);
        int* w = myBag.getData();
        int i = 0 ;
        for(;i<3;i++)
        {
            myBag.insert(i*10);
            yourBag.insert(2*i);
        }
        bag copied_bag(myBag);
        // myBag = yourBag;


        std::cout << "My Bag     :" << myBag << std::endl;
        std::cout << "Your Bag   :" << yourBag << std::endl;
        std::cout << "Copied Bag :" << copied_bag << std::endl;

        myBag.erase(20);
        yourBag.erase_one(4);
        std::cout << "My Bag     :" << myBag <<  "Used : " << myBag.getSize()  << std::endl ;
        std::cout << "UR Bag     :" << yourBag <<  "Used : " << yourBag.getSize()  << std::endl ;


    }

}

