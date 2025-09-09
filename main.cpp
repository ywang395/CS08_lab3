#include "bag.cpp"
#include <iostream>

int main()
{
    bool testing_big3 = true;
    bool testing_insert_and_constructor = false ;


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
        bag myBag(30);
        bag yourBag(30);
        int i = 0 ;
        for(;i<3;i++)
        {
            myBag.insert(i*10);
            yourBag.insert(i*4);
        }
        bag copied_bag(myBag);
        myBag = yourBag;


        std::cout << "My Bag     :" << myBag << std::endl;
        std::cout << "Your Bag   :" << yourBag << std::endl;
        std::cout << "Copied Bag :" << copied_bag << std::endl;
        `
    }

}

