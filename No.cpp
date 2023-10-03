#include "No.h"


namespace adf {
    No::No():
        data(0),
        next(0)
    {
    }
    No::No(int element):
        data(element),
        next(0)
    {
    }

    void No::setData(int newData){
        data=newData;
    }
    int No::getData()const{
        return data;
    }

    void No::setNext(No* newNext){
        next=newNext;
    }

    No* No::getNext()const{
        return next;
    }
}

