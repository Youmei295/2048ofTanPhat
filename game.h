#pragma once
#include "bientoancuc.h"
#include "contro.h"
//hien thi man hinh cho
using namespace std;
//tao man hinh cho
void manhinhcho()
{
	mauchu(11);
	cout<<endl;
	cout<<"   pppppppppppppppp         hhhhhhhhh            aaaaaaaaa       ttttttttt     "<<endl;
	cout<<"  p:::::::::::::::pp     hh:::::::::hh         a::::::::a     tt:::::::::tt   "<<endl;
	cout<<"  p::::::pppppp:::::p  hh:::::::::::::hh      a:::::::::a   tt:::::::::::::tt "<<endl;
	cout<<"  ppppppp     p:::::p h:::::::hhh:::::::h    a::::aa::::a  t::::::ttttt::::::t"<<endl;
	cout<<"              p:::::p h::::::h   h::::::h   a::::a a::::a  t:::::t     t:::::t"<<endl;
	cout<<"              p:::::p h:::::h     h:::::h  a::::a  a::::a  t:::::t     t:::::t"<<endl;
	cout<<"           pppp::::p  h:::::h     h:::::h a::::a   a::::a   t:::::ttttt:::::t "<<endl;
	cout<<"      ppppp::::::pp   h:::::h hhh h:::::ha::::aaaaaa::::aaa  t:::::::::::::t  "<<endl;
	cout<<"    pp::::::::ppp     h:::::h hhh h:::::ha::::::::::::::::a t:::::ttttt:::::t "<<endl;
	cout<<"   p:::::pppp         h:::::h     h:::::haaaaaaaaaa:::::aaat:::::t     t:::::t"<<endl;
	cout<<"  p:::::p             h:::::h     h:::::h          a::::a  t:::::t     t:::::t"<<endl;
	cout<<"  p:::::p             h::::::h   h::::::h          a::::a  t:::::t     t:::::t"<<endl;
	cout<<"  p:::::p       pppppph:::::::hhh:::::::h          a::::a  t::::::ttttt::::::t"<<endl;
	cout<<"  p::::::ppppppp:::::p hh:::::::::::::hh         aa::::::aa tt:::::::::::::tt "<<endl;
	cout<<"  p::::::::::::::::::p   hh:::::::::hh           a::::::::a   tt:::::::::tt   "<<endl;
	cout<<"  ppppppppppppppppppp     hhhhhhhhhh             aaaaaaaaaa     ttttttttt     "<<endl;
	cout<<endl;
	cout<<endl;
	mauchu(14);
	denXY(50, 24);
	denXY(2, 22);
	mauchu(13);
	cout<<("Nhan bat ky phim nao de bat dau choi ");

	_getch();
}
//tao bo khung cho tro 2048
void taokhung()
{
	for (int i = 0; i <= chieurongchoi; i++)
        {
		for (int j = 0; j <= chieudaichoi; j++)
		{
			if (j % 4 == 0)
            {
				denXY(i + 1, j + 1);
				mauchu(6);
				cout<<char(219);
			}

			else if (i % 6 == 0)
            {
				denXY(i + 1, j + 1);
				mauchu(6);
                cout<<char(219);

			}

			else
            {
				mauchu(3);
				denXY(i + 1, j + 1);
				cout<<char(219);
			}
		}
	}
}

//gan 0 cho tat ca cac o roi sau do gan gia tri cho 2 o ngau nhien
void taobanchoi()
{
	xoamh();
	taokhung();

	diem = 0;
	for (int i = 0; i < 4; i++)
    {
		for (int j = 0; j < 4; j++)
		{
			bangchoi[i][j] = 0;
		}
	}
    //de co cac seed random khac nhau, moi lan reset se khong bi trung
	srand(time(NULL));
	int hangovuong1=rand()%4,cotovuong1=rand()%4;
	int hangovuong2, cotovuong2;
	do
    {
        hangovuong2=rand()%4;
        cotovuong2=rand()%4;
    }
    while(hangovuong1==hangovuong2&&cotovuong1==cotovuong2);

	bangchoi[hangovuong1][cotovuong1] = 2;
	bangchoi[hangovuong2][cotovuong2] = 2;
}

// Luu lai diem cao nhat vao file
void luudiemcaonhat(int diem)
{
	fstream fildediem;
	fildediem.open("diem.txt", ios::out);
	fildediem << diem;
	fildediem.close();
}

// tra ve diem cao
int kyluc()
{
	int diem=0;
	fstream fildediem;
	fildediem.open("diem.txt", ios::in);
	fildediem >> diem;
	fildediem.close();
	return diem;
}

// Hien thi tro choi

void hienthi()
{ //diem, ky luc va huong dan choi
	if (diem > kyluc())
    {
		luudiemcaonhat(diem);
	}
	denXY(35, 5);
	mauchu(11);
	cout<<"Ky luc: "<< kyluc();
	denXY(35, 7);
	mauchu(15);
	cout<<("Huong dan choi: ");
	denXY(35, 8);
	mauchu(10);
	cout<<("A: sang trai");
	denXY(35, 9);
	mauchu(9);
	cout<<("S: di xuong");
	denXY(35, 10);
	mauchu(14);
	cout<<("D: sang phai");
	denXY(35, 11);
	mauchu(13);
	cout<<("W: di len");

	denXY(35, 13);
	mauchu(15);
	cout<<("Nhan 'R' de choi lai,'B' de lui lai mot buoc, 'X' de thoat");
// ve bang va to mau cho bang
	for (int i = 3; i <= 21; i += 6)
    {
		for (int j = 3; j <= 15; j += 4)
		{
			mauchu(51);
			denXY(i, j); cout<<string(4,char(219));
			setColor(bangchoi[(j - 3) / 4][(i - 3) / 6]);
			if (bangchoi[(j - 3) / 4][(i - 3) / 6] == 0)
			{
				mauchu(51);
				denXY(i, j); cout<<string(4,char(219));
			}
			else if (bangchoi[(j - 3) / 4][(i - 3) / 6] < 100)
			{
				denXY(i + 1, j);
				cout<<bangchoi[(j - 3) / 4][(i - 3) / 6];
			}
			else
			{
				denXY(i, j);
				cout<<bangchoi[(j - 3) / 4][(i - 3) / 6];
			}

		}
	}
	// hien thi diem
	denXY(35, 3);
	mauchu(12);
	cout<<"Diem: ";
	mauchu(10);
	cout<<diem;
	//hien thi nguon nhac (neuco)
	denXY(35,17);
	cout<<"Nhac: Ama no Jaku";
}
