#include <iostream>
using namespace std;

//顺序存储
template <class T>
class SqList
{
private:    
    T *elem;
    int length;
    int size;
public:
    SqList(int size);
    SqList(const SqList<T> &L);//拷贝构造函数
    void clearList();//清空列表
    int getLength();//获取元素个数
    bool isEmpty();//是否为空
    void add(T value);//尾插
    T getElem(int index);//获取某一下标元素
    void insertElem(int index,T value);//定点插入
    void deleteElem(int index);//定点删除
    T& operator[](int index);
    ~SqList();
};

template<class T>
SqList<T>::SqList(int size)
{
    this->elem=new T[size];
    this->length=0;
    this->size=size;
}

template<class T>
SqList<T>::SqList(const SqList<T> &L)
{
    if (this->elem!=NULL)
    {
        delete this->elem;
        this->elem=NULL;
        this->length=0;
        this->size=0;
    }
    this->elem=new T[L.size];
    for (int i = 0; i < L.length; i++)
    {
        this->elem[i]=L.elem[i];
    }
    this->length=L.length;
    this->size=L.size;
}

template<class T>
void SqList<T>::clearList()
{
    this->length=0;
}

template<class T>
int SqList<T>::getLength()
{
    return this->length;
}

template<class T>
bool SqList<T>::isEmpty()
{
    return this->length==0?true:false;
}

template<class T>
void SqList<T>::add(T value)
{
    if (this->length==this->size)
    {
        throw "error";
    }   
    this->elem[this->length]=value;
    this->length++;
}

template<class T>
T SqList<T>::getElem(int index)
{
    if (index<0||index>this->length-1)
    {
        throw "error";
    }    
    return this->elem[index];
}

template<class T>
void SqList<T>::insertElem(int index,T value)
{
    if (index<0||index>this->length||this->length==this->size)
    {
        throw "error";
    }   
    for (int i = this->length-1; i >= index; i--)
    {
        this->elem[i+1]=this->elem[i];
    }
    this->elem[index]=value;
    this->length++;
}

template<class T>
void SqList<T>::deleteElem(int index)
{
    if (index<0||index>this->length-1||this->length==0)
    {
        throw "error";
    }
    for (int i = index; i < this->length; i++)
    {
        this->elem[i]=this->elem[i+1];
    }
    this->length--;
}

template<class T>
T& SqList<T>::operator[](int index)
{
    return this->elem[index];
}

template<class T>
SqList<T>::~SqList()
{
    if (this->elem!=NULL)
    {
        delete this->elem;
        this->elem=NULL;
        this->length=0;
        this->size=0;
    }   
}

//二分查找
int binarySearch(SqList<int> &S,int value)
{
    int low=0;
    int high=S.getLength()-1;
    int mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (value==S[mid])
        {
            return mid;
        }
        else if (value<S[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }  
    return -1;  
}

//合并有序序列
SqList<int> mergeList(SqList<int> &La,SqList<int> &Lb)
{
    SqList<int> Lc(La.getLength()+Lb.getLength());
    int a=0,b=0;
    while (a<La.getLength()&&b<Lb.getLength())
    {
        if (La[a]<Lb[b])
        {
            Lc.add(La[a++]);
        }
        else
        {
            Lc.add(Lb[b++]);
        }        
    }
    while (a<La.getLength())
    {
        Lc.add(La[a++]);
    }
    while (b<Lb.getLength())
    {
        Lc.add(Lb[b++]);
    }
    return Lc;        
}

//链式存储
template<class T>
class Lnode
{
public:
    T value;
    Lnode *next;
};
template<class T>
class LinkList
{
    friend void mergeList(LinkList<int> &La,LinkList<int> &Lb);
private:
    Lnode<T> *head;
public:
    LinkList();
    bool isEmpty();//是否为空
    void clearList();//清空列表
    int getLength();//获取元素个数
    T getElem(int index);//获取某一下标的元素
    void insertElem(int index,T value);//定点插入
    void deleteElem(int index);//定点删除
    void insertHead(T value);//头插法
    void insertRear(T value);//尾插法
    void for_each();//遍历
    ~LinkList();
};

template<class T>
LinkList<T>::LinkList()
{
    head=new Lnode<T>();
    head->next=NULL;
}

template<class T>
bool LinkList<T>::isEmpty()
{
    return head->next==NULL?true:false;
}

template<class T>
void LinkList<T>::clearList()
{
    Lnode<T> *p,*q;
    p=head->next;
    while (p)
    {
        q=p;
        p=p->next;
        delete q;
    }
    head->next=NULL;    
}

template<class T>
int LinkList<T>::getLength()
{
    Lnode<T> *p;
    p=head->next;
    int length=0;
    while (p)
    {
        length++;
        p=p->next;
    }
    return length;   
}

template<class T>
T LinkList<T>::getElem(int index)
{
    Lnode<T> *p;
    p=head->next;
    int step=1;
    while (p&&step<index)
    {
        p=p->next;
        step++;
    }
    if (!p||step>index)
    {
        throw "not found";
    }
    return p->value;
}

template<class T>
void LinkList<T>::insertElem(int index,T value)
{
    Lnode<T> *p;
    p=head;
    int step=0;
    while (p&&step<index-1)
    {
        p=p->next;
        step++;
    }
    if (!p||step>index-1)
    {
        throw "error";
    }
    Lnode<T> *L=new Lnode<T>();
    L->value=value;
    L->next=p->next;
    p->next=L;
}

template<class T>
void LinkList<T>::deleteElem(int index)
{
    Lnode<T> *p,*q;
    p=head;
    int step=0;
    while (p&&step<index-1)
    {
        p=p->next;
        step++;
    }
    if (!p||step>index-1)
    {
        throw "error";
    }
    q=p->next;
    p->next=p->next->next;
    delete q;
}

template<class T>
void LinkList<T>::insertHead(T value)
{
    Lnode<T> *L=new Lnode<T>();
    L->value=value;
    L->next=head->next;
    head->next=L;   
}

template<class T>
void LinkList<T>::insertRear(T value)
{
    Lnode<T> *p,*rear;
    p=head->next;
    rear=head;
    while (p)
    {
        rear=p;
        p=p->next;
    }    
    Lnode<T> *L=new Lnode<T>();
    L->value=value;
    L->next=NULL;
    rear->next=L;
}

template<class T>
void LinkList<T>::for_each()
{
    Lnode<T> *p;
    p=head->next;
    while (p)
    {
        cout << p->value << endl;
        p=p->next;
    }   
}

template<class T>
LinkList<T>::~LinkList()
{
    Lnode<T> *p;
    while (head)
    {
        p=head;
        head=head->next;
        delete p;
    }   
}

//合并有序序列
void mergeList(LinkList<int> &La,LinkList<int> &Lb)
{
    Lnode<int> *pa,*pb,*pc;
    pa=La.head->next;
    pb=Lb.head->next;
    pc=La.head;
    while (pa&&pb)
    {
        if (pa->value<pb->value)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }       
    }
    pc->next=pa?pa:pb;
    delete Lb.head;
    Lb.head=NULL;
}