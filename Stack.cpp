#include <iostream>
using namespace std;

//顺序栈
template<class T>
class SqStack
{
private:
    T *base;
    T *top;
    int size;
public:
    SqStack();
    SqStack(int size);
    bool isEmpty();//是否为空
    int getLength();//获取元素个数
    void clearStack();//清空栈
    void push(T value);//入栈
    T pop();//出栈
    T getTop();//显示栈顶元素
    ~SqStack();
};

template<class T>
SqStack<T>::SqStack(int size)
{
    this->base=new T[size];
    this->top=this->base;
    this->size=size;
}

template<class T>
bool SqStack<T>::isEmpty()
{
    return this->top==this->base?true:false;
}

template<class T>
int SqStack<T>::getLength()
{
    return this->top-this->base;
}

template<class T>
void SqStack<T>::clearStack()
{
    this->top=this->base;
}

template<class T>
void SqStack<T>::push(T value)
{
    if (this->top-this->base==this->size)
    {
        throw "error";
    }   
    *this->top=value;
    this->top++;  
}

template<class T>
T SqStack<T>::pop()
{
    if (this->top==this->base)
    {
        throw "error";
    }   
    this->top--;
    return *this->top;
}

template<class T>
T SqStack<T>::getTop()
{
    if (this->top==this->base)
    {
        throw "error";
    }   
    T *p=this->top;
    p--;
    return *p;
}

template<class T>
SqStack<T>::~SqStack()
{
    if (this->base!=NULL)
    {
        delete this->base;
        this->top=this->base=NULL;
        this->size=0;
    }    
}

//链栈
template<class T>
class Snode
{
public:
    T value;
    Snode *next;
};
template<class T>
class LinkStack
{
private:
    Snode<T> *head;
public:
    LinkStack();
    bool isEmpty();//是否为空
    int getLength();//获取元素个数
    void clearStack();//清空栈
    void push(T value);//入栈
    T pop();//出栈
    T getTop();//显示栈顶元素
    ~LinkStack();
};

template<class T>
LinkStack<T>::LinkStack()
{
    head=NULL;
}

template<class T>
bool LinkStack<T>::isEmpty()
{
    return head==NULL?true:false;
}

template<class T>
int LinkStack<T>::getLength()
{
    Snode<T> *p;
    p=head;
    int length=0;
    while (p)
    {
        length++;
        p=p->next;
    }
    return length;
}

template<class T>
void LinkStack<T>::clearStack()
{
    Snode<T> *p;
    while (head)
    {
        p=head;
        head=head->next;
        delete p;
    }         
}

template<class T>
void LinkStack<T>::push(T value)
{
    Snode<T> *p=new Snode<T>();
    p->value=value;
    p->next=head;
    head=p;
}

template<class T>
T LinkStack<T>::pop()
{
    if (head==NULL)
    {
        throw "error";
    }
    Snode<T> *p;
    p=head;
    T value=p->value;
    head=head->next;
    delete p;
    return value;    
}

template<class T>
T LinkStack<T>::getTop()
{
    if (head==NULL)
    {
        throw "error";
    }    
    return head->value;
}

template<class T>
LinkStack<T>::~LinkStack()
{
    Snode<T> *p;
    while (head)
    {
        p=head;
        head=head->next;
        delete p;
    }        
}