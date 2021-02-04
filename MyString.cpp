#include <iostream>
using namespace std;
#include "List.cpp"

int BF(SqList<char> &S,SqList<char> &T)
{
    int i=0,j=0;
    while (i<S.getLength()&&j<T.getLength())
    {
        if (S[i]==T[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }       
    } 
    if (j>=T.getLength())
    {
        return i-T.getLength();
    }
    else
    {
        return -1;
    }        
}

void getIndex(SqList<char> &T,int *next)
{
    next[0]=-1;
    int i=-1,j=0;
    while (j<T.getLength())
    {
        if (i==-1||T[i]==T[j])
        {
            i++;
            j++;
            next[j]=i;
        }
        else
        {
            i=next[i];
        }       
    }    
}

int KMP(SqList<char> &S,SqList<char> &T)
{
    int next[T.getLength()];
    getIndex(T,next);
    int i=0,j=0;
    while (i<S.getLength()&&j<T.getLength())
    {
        if (j==-1||S[i]==T[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }       
    } 
    if (j>=T.getLength())
    {
        return i-T.getLength();
    }
    else
    {
        return -1;
    }
}