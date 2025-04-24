#include "bientoancuc.h"
#include "contro.h"
#include "game.h"
#include "mechanic.h"
#include "thangthua.h"



#define chieurongchoi 24
#define chieudaichoi 16

using namespace std;


int main()
{    //Đong code duoi de them nhac nhung vi dung luong nop co han nen em khong dua kem file
    //PlaySound(TEXT("amanojaku.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP);

    //khoi tao list
    ll=khoitaolist();
    manhinhcho();
	taobanchoi();

	while (true)
        {

		if (choilai)
        {
			taobanchoi();
			choilai = false;
		}

		hienthi();

		if (kiemtrathua())
        {
			denXY(35, 16);
			cout<<"Ban da thua! Man choi moi bat dau sau 5 giay";
             choilai=true;Sleep(5000);continue;
		}
		if(kiemtrathang())
		{
		    denXY(35,16);
		    cout<<"Ban da thang! Man choi moi bat dau sau 5 giay";
		    choilai=true;Sleep(5000);continue;
		}

		char phim = _getch();
		if(phim == 'b' || phim == 'B')
        {
            khoiphuctrangthai();
            continue;
        }

luubang();luutrangthai();

if (phim == 'w' || phim == 'W')
{
    len();
}
else if (phim == 's' || phim == 'S')
{
    xuong();
}
else if (phim == 'a' || phim == 'A')
{
    trai();
}
else if (phim == 'd' || phim == 'D')
{
    phai();
}



if (kiemtrabuocdichuyen())
{
    themo();
}

	}
	return 0;
}
