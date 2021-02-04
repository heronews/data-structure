#include <iostream>
using namespace std;
#include "Stack.cpp"
#include "Queue.cpp"

class BiNode
{
public:
    int value;
    BiNode *lchild,*rchild;
};
class BiTree
{
public:
    BiNode *root;
    BiTree();
    void preOrderTraverse();//先序遍历
    void inOrderTraverse();//中序遍历
    void postOrderTraverse();//后序遍历
    void levelOrder();//层次遍历
    int depth();//计算深度
    int nodeCount();//计算节点个数
    int leadCount();//计算叶子节点个数
    ~BiTree();
};

BiTree::BiTree()
{
    root=NULL;
}

void BiTree::preOrderTraverse()
{
    BiNode *p,*q;
    p=this->root;
    LinkStack<BiNode*> L;
    while (p||!L.isEmpty())
    {
        if (p)
        {
            cout << p->value << endl;
            L.push(p);
            p=p->lchild;
        }
        else
        {
            q=L.pop();
            p=q->rchild;
        }                
    }    
}
void BiTree::inOrderTraverse()
{
    BiNode *p,*q;
    p=this->root;
    LinkStack<BiNode*> L;
    while (p||!L.isEmpty())
    {
        if (p)
        {
            L.push(p);
            p=p->lchild;
        }
        else
        {
            q=L.pop();
            cout << q->value << endl;
            p=q->rchild;
        }                
    }
}

void BiTree::postOrderTraverse()
{
    BiNode *p,*q,*tag;
    p=this->root;
    LinkStack<BiNode*> L;
    while (p||!L.isEmpty())
    {
        if (p)
        {
            L.push(p);
            p=p->lchild;
        }
        else
        {
            q=L.pop();
            if (!q->rchild||q->rchild==tag)
            {
                tag=q;
                cout << q->value << endl;
            }
            else
            {
                L.push(q);
                p=q->rchild;
            }
        }                
    }
}

void BiTree::levelOrder()
{
    LinkQueue<BiNode*> L;
    BiNode *p;
    L.enQueue(this->root);
    while (!L.isEmpty())
    {
        p=L.deQueue();
        cout << p->value << endl;
        if (p->lchild)
        {
            L.enQueue(p->lchild);
        }
        if (p->rchild)
        {
            L.enQueue(p->rchild);
        }        
    }    
}

int BiTree::depth()
{
    BiNode *p,*q,*tag;
    int depth=0;
    p=this->root;
    LinkStack<BiNode*> L;
    while (p||!L.isEmpty())
    {
        if (p)
        {
            L.push(p);
            p=p->lchild;
        }
        else
        {
            q=L.getTop();
            if (!q->rchild||q->rchild==tag)
            {
                tag=q;
                depth=depth>L.getLength()?depth:L.getLength();
                L.pop();
            }
            else
            {
                p=q->rchild;
            }
        }                
    }
    return depth;
}

int BiTree::nodeCount()
{
    LinkStack<BiNode*> L;
    BiNode *p=this->root,*q;
    int count=0;
    while (p||!L.isEmpty())
    {
        if (p)
        {
            L.push(p);
            p=p->lchild;
        }
        else
        {
            q=L.pop();
            count++;
            p=q->rchild;
        }       
    }
    return count;   
}

int BiTree::leadCount()
{
    BiNode *p,*q,*tag;
    int count=0;
    p=this->root;
    LinkStack<BiNode*> L;
    while (p||!L.isEmpty())
    {
        if (p)
        {
            L.push(p);
            p=p->lchild;
        }
        else
        {
            q=L.getTop();
            if (!q->rchild||q->rchild==tag)
            {
                if (!q->rchild)
                {
                    count++;
                }
                tag=q;
                L.pop();
            }
            else
            {
                p=q->rchild;
            }
        }                
    }
    return count;
}

BiTree::~BiTree()
{
    BiNode *p,*q,*tag;
    p=this->root;
    LinkStack<BiNode*> L;
    while (p||!L.isEmpty())
    {
        if (p)
        {
            L.push(p);
            p=p->lchild;
        }
        else
        {
            q=L.pop();
            if (!q->rchild||q->rchild==tag)
            {
                tag=q;
                delete q;
            }
            else
            {
                L.push(q);
                p=q->rchild;
            }
        }                
    }
}

//创建二叉树
BiNode* createBiTree()
{
    int value;
    BiNode *p;
    cin >> value;
    if (value==0)
    {
        p=NULL;
    }
    else
    {
        p=new BiNode();
        p->value=value;
        p->lchild=createBiTree();
        p->rchild=createBiTree();
    }
    return p;    
}

//复制二叉树
void copy(BiNode* &B1,BiNode* &B2)
{
    if (!B1)
    {
        B2=NULL;
    }
    else
    {
        B2=new BiNode();
        B2->value=B1->value;
        copy(B1->lchild,B2->lchild);
        copy(B1->rchild,B2->rchild);
    }   
}