#include "llse.h"
#include <new>
namespace adf {

LLSE::LLSE():
    first(0),
    numberElements(0)
{
}
//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
bool LLSE::isEmpty()const{
    return (!numberElements);
}
//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
void LLSE::insertFirst(int element){
    try {
        numberElements++;
         No* aux=new No(element);
         aux->setNext(first);
         first=aux;
    } catch (std::bad_alloc &erro) {
        throw QString("No nao foi criado");
    }

}
//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
int LLSE::accessFirst()const{
    if(isEmpty()) throw QString("Lista esta vazia (accessfirst)");
    return first->getData();
}
//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
int LLSE::removeFirst(){
    if(isEmpty())throw QString("Lista esta vazia (removefirst())");
    numberElements--;
    No*aux=first;
    first=aux->getNext();
    int valor=aux->getData();
    delete aux;
    return valor;
}
//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
QString LLSE::accessAll()const{
    if(isEmpty())throw QString("Lista esta vazia (accessAll)");
    QString exit="";
    No* aux=first;
    for(int i=1;i<numberElements;i++){
        exit+='|'+QString::number(aux->getData())+'|'+"-> ";
        aux=aux->getNext();
    }
    exit+='|'+QString::number(aux->getData())+'|';
    return exit;
}
QString LLSE::accessAllColored(QString color)const{
    if(isEmpty())throw QString("Lista esta vazia (accessAll)");
    QString exit="";
    No* aux=first;
    int i;
    for(i=1;i<numberElements;i++){
        if(i%2==0){
            exit+='|'+QString::number(aux->getData())+'|'+"-> ";
        }else{
            exit+="|""<font color=\"" + color + "\">"  + QString::number(aux->getData()) + "</font>"+"|-> ";
        }
        aux=aux->getNext();
    }
    if(i%2==0){
        exit+='|'+QString::number(aux->getData())+'|';
    }else{
        exit+="|""<font color=\""+color+"\">" + QString::number(aux->getData()) + "</font>"+'|';
    }


    return exit;
}
//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
void LLSE::insertLast(int element){
    try {
        if(numberElements==0){
            first=new No(element);
            numberElements++;
            return;
        }
        No* aux=first;
        No* value=new No(element);
        for(int i=1;i<numberElements;i++){
            aux=aux->getNext();
        }
        numberElements++;
        aux->setNext(value);

    } catch (std::bad_alloc &erro) {
        throw QString("bad Alloc");
    }

}
//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
int LLSE::accessLast()const{
    if(isEmpty()){throw QString("List esta vazia (accessall())");}
    No* aux=first;
    int value;
    for(int i=1;i<numberElements;i++){
        aux=aux->getNext();
    }
    value=aux->getData();
    return value;
}
//_-_-_-_-_-_-_-_-_-_-
int LLSE::removeLast(){
    if(isEmpty()){throw QString("List esta vazia(removeLast())");}
    No* aux=first;
    int value;
    for(int i=1;i<numberElements;i++){
        aux=aux->getNext();
    }
    numberElements--;
    value=aux->getData();
    delete aux;
    return value;
}
int LLSE::accessPosition(int position)const{
    if(isEmpty())throw QString("Lista esta vazia");
    if(position<0|| position>numberElements)throw QString("posicao selecionada fora da lista");
    if(position==0){return accessFirst();}
    if(position==numberElements){return accessLast();}
    No *aux=first;
    for(int i=1;i<position;i++){
        aux=aux->getNext();
    }
    return aux->getData();
}

int LLSE::removePosition(int position){
    if(isEmpty())throw QString("Lista esta vazia");
    if(position<0|| position>numberElements)throw QString("posicao selecionada fora da lista");
    if(position==0){return removeFirst();}
    if(position==numberElements){return removeLast();}
    No *aux=first;
    for(int i=1;i<position-1;i++){
        aux=aux->getNext();
    }
    No* aux2=aux;
    aux=aux->getNext();
    aux2->setNext(aux->getNext());
    int value=aux->getData();
    delete aux;
    numberElements--;
    return value;
}

void LLSE::insertPosition(int element, int position){
    if(position<0|| position>numberElements)throw QString("posicao selecionada fora da lista");
    if(position==0){return insertFirst(element);}
    if(position==numberElements){return insertLast(element);}
    No *aux=first;
    No *newNo=new No(element);
    No* aux2=0;
    for(int i=1;i<position-1;i++){
        aux=aux->getNext();
    }
    aux2=aux;
    aux=aux->getNext();
    aux2->setNext(newNo);
    newNo->setNext(aux);
    numberElements++;
    return;
}
int LLSE::getnumberElements()const{
    return numberElements;
}
//_-_-_-_-_-_-_-_-_-
    LLSE::~LLSE(){
    delete first;
}

}
