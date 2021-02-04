#include <iostream>
using namespace std;
#include "List.cpp"

//直接插入排序
void insertSort(SqList<int> &S)
{
    int i,j,temp;
    for (i = 1; i < S.getLength(); i++)
    {
        if (S[i]<S[i-1])
        {
            temp=S[i];
            for (j = i-1; j >= 0&&temp<S[j]; j--)
            {
                S[j+1]=S[j]; 
            }
            S[j+1]=temp;
        }          
    }   
}

//折半插入排序
void binaryInsertSort(SqList<int> &S)
{
    int low,high,mid,temp;
    for (int i = 1; i < S.getLength(); i++)
    {
        temp=S[i];
        low=0;
        high=i-1;
        while (low<=high)
        {
            mid=(low+high)/2;
            if (temp<S[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }   
        }
        for (int j = i-1; j > high; j--)
        {
            S[j+1]=S[j];
        }
        S[high+1]=temp;
    } 
}

//希尔排序
void shellInsertSort(SqList<int> &S,int n)
{
    int i,j,temp;
    for (i = n; i < S.getLength(); i+=n)
    {
        if (S[i]<S[i-n])
        {
            temp=S[i];
            for (j = i-n; j >= 0&&temp<S[j]; j-=n)
            {
                S[j+n]=S[j]; 
            }
            S[j+n]=temp;
        }          
    }
}

//冒泡排序
void bubbleSort(SqList<int> &S)
{
    int temp;
    for (int i = 0; i < S.getLength()-1; i++)
    {
        for (int j = 0; j < S.getLength()-i-1; j++)
        {
            if (S[j]>S[j+1])
            {
                temp=S[j];
                S[j]=S[j+1];
                S[j+1]=temp;
            }    
        }    
    }    
}

//快速排序
int partition(SqList<int> &S,int low,int high)
{
    int temp=S[low];
    while (low<high)
    {
        while (low<high&&S[high]>temp)
        {
            high--;
        }
        S[low]=S[high];
        while (low<high&&S[low]<temp)
        {
            low++;
        }
        S[high]=S[low];
    }
    S[low]=temp;
    return low;   
}
void quickSort(SqList<int> &S,int low,int high)
{
    if (low<high)
    {
        int n=partition(S,low,high);
        quickSort(S,low,n-1);
        quickSort(S,n+1,high);
    }
}

//选择排序
void selectSort(SqList<int> &S)
{
    int min,temp;
    for (int i = 0; i < S.getLength(); i++)
    {
        min=i;
        for (int j = i+1; j < S.getLength(); j++)
        {
            if (S[j]<S[min])
            {
                min=j;
            }    
        }
        if (min!=i)
        {
            temp=S[i];
            S[i]=S[min];
            S[min]=temp;
        }      
    }   
}

//堆排序
void heapAdjust(SqList<int> &S,int a,int b)
{
    int temp=S[a];
    for (int i = 2*a+1; i < b; i=2*i+1)
    {
        if (i<b-1&&S[i]<S[i+1])
        {
            i++;
        }
        if (temp>=S[i])
        {
            break;
        }
        S[a]=S[i];
        a=i;
    }
    S[a]=temp;   
}
void heapSort(SqList<int> &S)
{
    int temp;
    for (int i = (S.getLength()-1)/2; i >= 0; i--)
    {
        heapAdjust(S,i,S.getLength());
    }
    for (int j = S.getLength()-1; j > 0; j--)
    {
        temp=S[0];
        S[0]=S[j];
        S[j]=temp;
        heapAdjust(S,0,j);
    }       
}