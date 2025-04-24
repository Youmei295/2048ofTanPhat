#pragma once
#include "game.h"
//buoc di chuyen di len
void len()
{
	// Di len

	for (int j = 0; j < 4; j++)
        {
		int t = 0;
		for (int i = 0; i < 4; i++)
        {
			if (bangchoi[i][j] != 0)
			{
				bangchoi[t][j] = bangchoi[i][j];
				t++;
			}
		}
		for (int i = t; i < 4; i++)
         {
		     bangchoi[i][j] = 0;
         }
	}


	// Gop hai o cung gia tri thanh mot

	for (int j = 0; j < 4; j++)
        {
		int t = 0;
		for (int i = 0; i < 4; i++)
		{
			if (bangchoi != 0)
			{
				if (bangchoi[i][j] == bangchoi[i + 1][j])
				{
					bangchoi[t][j] = 2 * bangchoi[i][j];
					diem += bangchoi[t][j];
					t++;
					i++;
				}
				else
				{
					bangchoi[t][j] = bangchoi[i][j];
					t++;
				}
			}
		}
		for (int i = t; i < 4; i++)
		{
		     bangchoi[i][j] = 0;
        }
	}

}
//buoc di chuyen di xuong
void xuong()
{
	// Di xuong

	for (int j = 0; j < 4; j++)
        {
		int t = 3;
		for (int i = 3; i >= 0; i--)
		{
			if (bangchoi[i][j] != 0)
			 {
				bangchoi[t][j] = bangchoi[i][j];
				t--;
			 }
		}
		for (int i = t; i >= 0; i--)
		{
		    bangchoi[i][j] = 0;
        }
}

	// Gop hai o cung gia tri thanh mot

	for (int j = 0; j < 4; j++) {
		int t = 3;
		for (int i = 3; i >= 0; i--) {
			if (bangchoi != 0) {
				if (bangchoi[i][j] == bangchoi[i - 1][j]) {
					bangchoi[t][j] = 2 * bangchoi[i][j];
					diem += bangchoi[t][j];
					t--;
					i--;
				}
				else {
					bangchoi[t][j] = bangchoi[i][j];
					t--;
				}
			}
		}
		for (int i = t; i >= 0; i--) {bangchoi[i][j] = 0;}
	}

}
//buoc di chuyen sang trai
void trai()
{
	// Qua trai

	for (int i = 0; i < 4; i++)
    {
		int t = 0;
		for (int j = 0; j < 4; j++)
    {
			if (bangchoi[i][j] != 0)
			 {
				bangchoi[i][t] = bangchoi[i][j];
				t++;
			 }
    }
		for (int j = t; j < 4; j++)
		{
		    bangchoi[i][j] = 0;
        }
	}

	// Gop hai o cung gia tri thanh mot

	for (int i = 0; i < 4; i++)
        {
		int t = 0;
		for (int j = 0; j < 4; j++)
		{
			if (bangchoi[i][j] != 0)
			{
				if (bangchoi[i][j] == bangchoi[i][j + 1])
				{
					bangchoi[i][t] = 2 * bangchoi[i][j];
					diem += bangchoi[i][t];
					j++;
					t++;
				}
				else
				{
					bangchoi[i][t] = bangchoi[i][j];
					t++;
				}
			}
		}
		for (int j = t; j < 4; j++)
		{
		    bangchoi[i][j] = 0;}
        }

}
//buoc di chuyen sang phai
void phai()
{
	// Qua phai

	for (int i = 0; i < 4; i++)
    {
		int t = 3;
		for (int j = 3; j >= 0; j--)
		{
			if (bangchoi[i][j] != 0)
			{
				bangchoi[i][t] = bangchoi[i][j];
				t--;
			}
		}
		for (int j = t; j >= 0; j--)
		{
		    bangchoi[i][j] = 0;
		}
	}

	// Gop hai o cung gia tri thanh mot

	for (int i = 0; i < 4; i++)
    {
		int t = 3;
		for (int j = 3; j >= 0; j--)
		{
			if (bangchoi[i][j] != 0)
			{
				if (bangchoi[i][j] == bangchoi[i][j - 1])
				{
					bangchoi[i][t] = 2 * bangchoi[i][j];
					diem += bangchoi[i][t];
					j--;
					t--;
				}
				else
				{
					bangchoi[i][t] = bangchoi[i][j];
					t--;
				}
			}
		}
		for (int j = t; j >= 0; j--)
		{
		    bangchoi[i][j] = 0;
		}
	}
}

//kiem tra thu con o trong khong
bool conotrong()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (bangchoi[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}

// Them gia tri cho o trong ngau nhien

void themo()
{
	if (conotrong() == false) return;

	// Tao gia tri cho vi tri trong, 2 hoac 4 voi ti le 8:2
	int x, y;
	srand(time(NULL));

	do {
		x = rand() % 4;
		y = rand() % 4;
	} while (bangchoi[x][y] != 0);

	int s = rand() % 100;
	if (s >=80) bangchoi[x][y] = 4;
	else bangchoi[x][y] = 2;
}
