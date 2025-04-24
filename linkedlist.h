#pragma once
#include <iostream>
struct trangthai
{
    int bang[4][4];
    int diemso;
    trangthai* prev,*next;
};

struct linkedlist
{
    trangthai* head,*tail;
};

linkedlist* khoitaolist()
{
    linkedlist* t=new linkedlist();
    t->head=NULL;t->tail=NULL;
    return t;
}

trangthai* taotrangthai(int a[4][4],const int& sodiem)
{
    trangthai* moi=new trangthai();
    for (int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            moi->bang[i][j]=a[i][j];
        }
    }
    moi->diemso=sodiem;
    moi->prev=NULL;
    moi->next=NULL;
    return moi;
}
//them vao cuoi danh sach
void addtail(linkedlist* danhsach,int a[4][4],const int& sodiem)
{   trangthai* moi=taotrangthai(a,sodiem);
    if(danhsach->head==NULL){danhsach->head=moi;danhsach->tail=moi;return;}
    danhsach->tail->next=moi;moi->prev=danhsach->tail;danhsach->tail=moi;
}

