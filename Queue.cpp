#include <iostream>
using namespace std;

//顺序队
template<class T>
class SqQueue
{
private:
    T *elem;
    int front;
    int rear;
    int size;
public:
    SqQueue(int size);
    bool isEmpty();//是否为空
    int getLength();//获取元素个数
    void enQueue(T value);//入队
    T deQueue();//出队
    T getHead();//显示队头元素
    ~SqQueue();
};

template<class T>
SqQueue<T>::SqQueue(int size)
{
    this->elem=new T[size+1];
    this->front=this->rear=0;
    this->size=size+1;
}

template<class T>
bool SqQueue<T>::isEmpty()
{
    return this->rear==this->front?true:false;
}

template<class T>
int SqQueue<T>::getLength()
{
    return (this->rear-this->front+this->size)%this->size;
}

template<class T>
void SqQueue<T>::enQueue(T value)
{
    if ((this->rear+1)%this->size==this->front)
    {
        throw "error";
    }
    this->elem[this->rear]=value;
    this->rear=(this->rear+1)%this->size;
}

template<class T>
T SqQueue<T>::deQueue()
{
    if (this->rear==this->front)
    {
        throw "error";
    }
    T value=this->elem[this->front];
    this->front=(this->front+1)%this->size;
    return value;
}

template<class T>
T SqQueue<T>::getHead()
{
    if (this->rear==this->front)
    {
        throw "error";
    }
    return this->elem[this->front];  
}

template<class T>
SqQueue<T>::~SqQueue()
{
    if (this->elem!=NULL)
    {
        delete this->elem;
        this->elem=NULL;
        this->front=this->rear=0;
        this->size=0;
    }    
}

//链队
template<class T>
class Qnode
{
public:
    T value;
    Qnode *next;
};
template<class T>
class LinkQueue
{
private:
    Qnode<T> *front;
    Qnode<T> *rear;
public:
    LinkQueue();
    bool isEmpty();//是否为空
    int getLength();//获取元素个数
    void enQueue(T value);//入队
    T deQueue();//出队
    T getHead();//显示队头元素
    ~LinkQueue();
};

template<class T>
LinkQueue<T>::LinkQueue()
{
    front=rear=new Qnode<T>();
    front->next=NULL;
}

template<class T>
bool LinkQueue<T>::isEmpty()
{
    return rear==front?true:false;
}

template<class T>
int LinkQueue<T>::getLength()
{
    Qnode<T> *p;
    p=front->next;
    int length=0;
    while (p)
    {
        length++;
        p=p->next;
    }
    return length;   
}

template<class T>
void LinkQueue<T>::enQueue(T value)
{
    Qnode<T> *p=new Qnode<T>();
    p->value=value;
    p->next=NULL;
    rear->next=p;
    rear=p;
}

template<class T>
T LinkQueue<T>::deQueue()
{   
    if (rear==front)
    {
        throw "error";
    }
    Qnode<T> *p=front->next;
    front->next=p->next;
    T value=p->value;
    if (p==rear)
    {
        rear=front;
    }    
    delete p;
    return value;
}

template<class T>
T LinkQueue<T>::getHead()
{
    if (rear==front)
    {
        throw "error";
    }   
    return front->next->value;
}

template<class T>
LinkQueue<T>::~LinkQueue()
{
    Qnode<T> *p;
    while (front)
    {
        p=front;
        front=front->next;
        delete p;
    }
    front=rear=NULL;
}