#pragma once
#include "mechanic.h"


//luu mot bang tam de sau do so sanh xem la nuoc di co dung hay khong

void luubang()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			banghientai[i][j] = bangchoi[i][j];
		}
	}
}
//them trang thai hien tai vao list
void luutrangthai()
{

    addtail(ll,bangchoi,diem);
}

//khoi phuc bangchoi ve lai trang thai truoc do
void khoiphuctrangthai()
{
    if(!ll->head){return;}
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            bangchoi[i][j]=ll->tail->bang[i][j];
        }
    }
    diem=ll->tail->diemso;
    trangthai*temp=ll->tail; ll->tail=ll->tail->prev;ll->tail->next=NULL;
    delete temp;
}


//kiem tra xem buoc di chuyen co hop le hay khong
bool kiemtrabuocdichuyen()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (banghientai[i][j] != bangchoi[i][j]) {return true;}
		}
	}
	return false;
}
//ham kiem tra thu da thua chua
bool kiemtrathua() {
    if (!conotrong())
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if ((j < 3 && bangchoi[i][j] == bangchoi[i][j + 1]) ||(i < 3 && bangchoi[i][j] == bangchoi[i + 1][j]))
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
//ham kiem tra xem da thang chua
bool kiemtrathang()
{   bool kiemtra=false;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(bangchoi[i][j]==2048){kiemtra=true;return kiemtra;}
        }
    }
    return kiemtra;
}

