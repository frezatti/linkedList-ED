#ifndef NO_H
#define NO_H

namespace adf {

    class No
    {
    public:
        No();
        No(int elemento);

        int getData() const;
        void setData(int newData);

        No* getNext() const;
        void setNext(No *newNext);

    private:
        int data;
        No *next;
    };
}
#endif // NO_H
