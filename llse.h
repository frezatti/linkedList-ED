#ifndef LLSE_H
#define LLSE_H
#include "No.h"
#include <QString>

namespace adf {
    class LLSE
    {
    public:
        LLSE();
        ~LLSE();
        bool isEmpty()const;

        void insertFirst(int element);
        int accessFirst()const;
        int removeFirst();

        void insertPosition(int element, int posicao);
        int accessPosition(int position)const;
        int removePosition(int position);

        void insertLast(int element);
        int accessLast()const;
        int removeLast();

        int getnumberElements()const;
        QString accessAll()const;
        QString accessAllColored(QString color)const;
    private:
       No *first;
       int numberElements;
    };
}

#endif // LLSE_H
