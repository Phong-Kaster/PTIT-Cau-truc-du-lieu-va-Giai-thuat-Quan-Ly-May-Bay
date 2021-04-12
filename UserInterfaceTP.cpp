#pragma once
#include<iostream>
#include<conio.h>//getch()
#include<stdint.h>
#include<string.h>//char
#include<string>//string
#include<iomanip>// for setw va setfill
#include"GlobalVariableTP.h"// thu vien chua cac hang so
#include"MyLibraryTP.h"// thu vien chua cac ham xu li do hoa
#include"AirplaneTP.h"
#include"ProcessionTP.h"
#include"FlightTP.h"
#include"PassengerTP.h"
//#include"AirplaneTP.h"
using namespace std;
/*Bien toan cuc*/
ListAirplane LA;
FlightList FL;
AVLTree root;
extern int nPassenger;
// co toi da 5 phan tu toi da 50 ki tu
int xKeyDisplay[7] = { 1,20,45,63,83,95, 107 };// toa do X cac diem nut
char TenHocVien[100] = { "HOC VIEN CONG NGHE BUU CHINH VIEN THONG CO SO THANH PHO HO CHI MINH"};
char ThucDon[MaxItem][70] = { 
					   "1.Quan Li Cac May Bay",
					   "2.Quan Li Cac Chuyen Bay",
					   "3.Dang Ky Ve May Bay",
					   "4.Huy Bo Ve May Bay",
					   "5.Xem Danh Sach Hanh Khach Chi Tiet",
					   "6.Xem So Do Cho Ngoi & Danh Sach Ve Con Trong",
					   "7.Xem Chi Tiet So Lan Thuc Hien Chuyen Bay",
					   "8.Xem Cac Chuyen Bay Di Toi Cac Dia Danh",
                       "0.Thoat Chuong Trinh"
};

// dong tuy chon
void NormalLine()
{
	SetColor(14);// yellow
	SetBGColor(0);// black
}
// dong dang chon
void HighlightLine()
{
	SetColor(14);// yellow 
	SetBGColor(1);// dark blue        
}
/*============== CENTER MENU =============*/
// menu dung phim moi ten de dieu huong
int RemoveConfirm()
{
	// return 0 la yes - dong y, return 1 la no - tu choi
	ShowCur(false);
	NormalLine();
	
	gotoxy(X_RemoveConfirm,Y_RemoveConfirm );
	cout << " Ban co chac chan muon xoa ??";

	char Option[2][4] = {"Yes" ,"No" };
	for( int i = 0 ; i < 2 ;i++)
	{
		gotoxy(X_RemoveConfirm, Y_RemoveConfirm + i*2 + 2);
		cout << Option[i];
	}
	int pointer = 0;

	gotoxy(X_RemoveConfirm, Y_RemoveConfirm + pointer*2 + 2);
	HighlightLine();
	cout << Option[pointer];
	char signal;

	while(true)
	{
		signal = _getch();
		if( signal == 224)
			signal = _getch();
		switch(signal)
		{
		case KEY_UP:
			if( pointer > 0)
			{
				NormalLine();
				gotoxy(X_RemoveConfirm, Y_RemoveConfirm + pointer*2 + 2);
				cout << Option[pointer];
				pointer--;
				HighlightLine();
				gotoxy(X_RemoveConfirm, Y_RemoveConfirm + pointer*2 + 2);
				cout << Option[pointer];
			}
			break;
		case KEY_DOWN:
			if( pointer < 1 )
			{
				NormalLine();
				gotoxy(X_RemoveConfirm, Y_RemoveConfirm + pointer*2 + 2);
				cout << Option[pointer];
				pointer++;
				HighlightLine();
				gotoxy(X_RemoveConfirm, Y_RemoveConfirm + pointer*2 + 2);
				cout << Option[pointer];
			}
			break;
		case ENTER:
			for (int i = 0; i < 3; i++)
			{
				gotoxy(X_RemoveConfirm, Y_RemoveConfirm+i*2);
				printf("%-30s", " ");
			}
			return pointer;
		}
	}// while(true)
}
void DrawTable()
{
	gotoxy( X_TitlePage - 7 ,Y_TitlePage+1);
	cout << TenHocVien;
	/*      "HOC VIEN CONG NGHE BUU CHINH VIEN THONG CO SO THANH PHO HO CHI MINH"*/
	gotoxy( X_TitlePage - 7 , Y_Display + 19 + 1);
	cout << " >> Nguyen Thanh Phong -------- N18DCCN147 -------- D18CQCN03-N << ";
	//ve thanh ngang ben tren va duoi
	for (int i = xKeyDisplay[3] - 12; i < 122; i++)
	{

		//ve thanh ngang ben tren so 1
		gotoxy(i, Y_Display-2);
		cout << char(176);

		// ve thanh ngang ben tren so 2
		gotoxy(i, Y_Display + 1);
		cout << char(176);
 
		//ve thanh ngang ben duoi
		gotoxy(i, Y_Display + 19);
		cout << char(176);
		
		gotoxy(i ,  Y_Display + 19 + 3);
		cout << char(176);
	}

	for (int j = Y_Display ; j < Y_Display + 25; j++)
	{
		gotoxy(  xKeyDisplay[3] - 12 , j - 2 );
		cout << char(176);

		gotoxy( 122 , j - 2 );
		cout << char(176);
	}
}
int ScrollMenu(char ThucDon[MaxItem][70])
{
	// xuat menu
	ShowCur(false);// an con tro nhap nhay di
	NormalLine();
	system("cls");
	DrawTable();
	for(int i = 0 ; i < MaxItem ; i++)
	{
		
		gotoxy(X_CenterMenu,Y_CenterMenu + i*2);
		cout << ThucDon[i];
	}
	// to mau cho dong duoc chon
	int pointer = 0; // vi tri hien tai cua thanh sang
//	HighlightLine();
	gotoxy(X_CenterMenu,Y_CenterMenu + pointer*2);
	HighlightLine();
	cout << ThucDon[pointer];
	// dieu khien chuc nang
	char signal;
	while(true)
	{
		signal = _getch();// kiem tra xem co nhap gi tu ban phim khong
		if( signal == -32)
		{
			signal = _getch();
		}
			// dieu huong
			switch(signal)
			{
			case KEY_UP:
				if( pointer + 1 > 1)
				{
					// tro ve mau cu
					NormalLine();
					gotoxy(X_CenterMenu,Y_CenterMenu + pointer*2);
					cout << ThucDon[pointer];
					pointer--;// cap nhat lai vi tri 
					// vi tri thanh sang
					HighlightLine();
					gotoxy(X_CenterMenu,Y_CenterMenu + pointer*2);
					cout << ThucDon[pointer];
				}
				break;
			case KEY_DOWN:
				if( pointer + 1 < MaxItem)
				{
					NormalLine();
					gotoxy(X_CenterMenu,Y_CenterMenu + pointer*2);
					cout << ThucDon[pointer];
					pointer++;
					HighlightLine();
					gotoxy(X_CenterMenu,Y_CenterMenu + pointer*2);
					cout << ThucDon[pointer];
				}
				break;
			case ENTER:// lua lai ket qua de thuc hien lenh tuong ung voi CenterMenu
				return pointer + 1;
			}
	}
}
/* ========== END CENTER MENU =========== */

/* ========== Bang them thong tin ========*/
// length = do dai cua toan bo o nhap
// content = tieu de cua o nhap
void FloatingEffectWord(char Content[], int x, int y,int Color)
{
	SetColor(Color);
	SetBGColor(ColorCode_Black);
	ShowCur(false);

	char c[40];
	int length = (int)strlen(Content);// Lay do dai cua chuoi chu
	int signal;
	
	for (int i = 0; i < length; i++) 
	{
		/*Sao chep chuoi tu 40 ki tu "Content + i" toi mang C*/
		strncpy(c, Content + i, 40);
		c[39] = '\0';
		Sleep(100);
		gotoxy(x, y);
		cout << "                                       ";
		gotoxy(x, y); // vi tri de in dong chu chay
		cout << c;
		if (i == length - 1)
		{
			i = 0;  // Chay vinh cuu
		}
		
		if( _kbhit() )
		{
			break;
		}
	}
	cin.ignore();
	return;
}
// tao 1 hang
void CreateRow(int x, int y, string content, int length)
{
	gotoxy(x - 2, y - 1);
	cout << char(176) << setw(length) << setfill(char(176)) << char(176) << char(176);

	gotoxy(x - 2, y);
	cout << char(176) << content << setw(length - content.length() + 1) << setfill(' ') << char(176);
}
// tao 1 bang nhap thong tin
void CreateForm(string content[],int StartIndex,int nContent,int length)
{
	int yAdd = Y_Add;
	for (int i = StartIndex; i < nContent; i++)
	{
		CreateRow(X_Add, yAdd,content[i],length);
		yAdd += 3;
	}
}
/*the hien 1 o ve trong danh sach ve cua may bay*/
void TicketStack(int x, int y, int  text, int status)
{
	SetColor(14);// yellow
	SetBGColor(0);// black
	/*Ve duong ve ben tren*/
	gotoxy(x, y - 1);
	cout << char(176) << setw(3) << setfill(char(176)) << char(176) << char(176);
	/*So thu tu cua cai ve do*/
	gotoxy(x, y);
	
	cout << char(176) << setw(3) << setfill('0')<<text<<char(176);
	//printf("%-5d",text);
	/*ve duong ke ben duoi cua cai ve*/
	gotoxy(x,y+1);
	if (status == 1) {
		SetBGColor(ColorCode_Red);
	}
	cout << char(176) << setw(3) << setfill(char(176)) << char(176) << char(176);

}

/*Xoa bang nhap thong tin sau khi nhap xong*/
void RemoveForm()
{
	system("color 0E");
	for (int i = 0; i < 6; i++)
	{
		gotoxy(127, i*3+4);
		printf("%-20s", " ");
	}
}

void RemoveFormForFlight()
{
	system("color 0E");
	for(int i = 0;i < 3; i++)
	{
		gotoxy(X_Add + 2 , i*3+4);
		printf("%-20s", " ");
	}
}
// xoa toan bo bang nhap thong tin
void RemoveFormComplete()
{
	system("color 0E");
	for( int i = 0 ; i < 20 ; i++)
	{
		gotoxy(X_Add - 2 , Y_Add - 1 + i );
		printf("%-32s", " ");
	}
	//ShowCur(false);
}
// nContent - so luong thanh phan co trong bang do
void RemoveExceedMember(int count,int nContent)
{
	if (count < NumberPerPage)
	{
		for (int i = count; i < NumberPerPage; i++)
		{
			for (int y = 0; y < nContent; y++)
			{
				gotoxy(xKeyDisplay[y] + 3, Y_Display + 3 + i * 3);
				printf("%-18s"," ");
			}
		}
	}
}
/* ========== End Bang Them Thong tin ===============*/

/* ========== Tao bang xuat thong tin ===============*/

/*Noi dung hien thi trong bang liet ke*/
string ContentAirplane[3] = { "So Hieu", "HangMayBay", "SoChoNgoi" };
string ContentFlight[6] = { "MaChuyenBay","SanBayDen","SoHieuMayBay","ThoiGianDi","TongSoVe","TrangThai"};
string ContentTicket[2] = {"Ten Ve","TrangThai"};
string ContentPassenger[5] ={"STT","CMND","Ho","Ten","GioiTinh"};

void Display(string content[], int nContent)// ve bang 
{
	system("color 0E");
	SetColor(14);
	SetBGColor(0);
	//show key - the hien ra noi dung cua cac cot
	for (int i = 0; i < nContent; i++)
	{// Y_Display 4
		gotoxy(xKeyDisplay[i] + 3, Y_Display+1);
		cout << content[i];
	}

	//ve cac duong thang de phan chia cac cot - kich thuoc toi da la 24 ve chieu dai
	for (int j = Y_Display ; j <= Y_Display + 20; j++)
	{
		for (int i = 0; i < nContent+1; i++)
		{
			gotoxy(xKeyDisplay[i], j);
			cout << char(176);
		}
	}
	//ve thanh ngang ben tren va duoi
	for (int i = xKeyDisplay[0]; i <= xKeyDisplay[nContent]; i++)
	{
		//ve thanh ngang ben tren so 1
		gotoxy(i, Y_Display);
		cout << char(176);

		// ve thanh ngang ben tren so 2
		gotoxy(i, Y_Display + 2);
		cout << char(176);

		//ve thanh ngang ben duoi
		gotoxy(i, Y_Display + 21);
		cout << char(176);
	}

	cout << endl;
	gotoxy(X_Tutorial,Y_Tutorial);
	cout << " Huong dan " ;
	gotoxy(X_Tutorial,Y_Tutorial + 2);
	cout << " Page Up:Len || Page Down:Xuong ";
	gotoxy(X_Tutorial,Y_Tutorial + 3);
	cout << " Insert:Them || Del:Xoa ";
	gotoxy(X_Tutorial,Y_Tutorial + 4);
	cout << " Home:Chinh Sua || ESC : thoat" ;
	gotoxy(X_Notification,Y_Notification);
	cout << " Thong Bao ";
}

void DisplayForWatchOnly(string content[], int nContent,int count)// ve bang 
{
	system("color 0E");
	SetColor(14);
	SetBGColor(0);
	//show key - the hien ra noi dung cua cac cot
	for (int i = 0; i < nContent; i++)
	{// Y_Display 4
		gotoxy(xKeyDisplay[i] + 3, Y_Display+1);
		cout << content[i];
	}

	//ve cac duong thang de phan chia cac cot - kich thuoc toi da la 20+count ve chieu dai
	for (int j = Y_Display ; j <= count*3 + 5; j++)
	{
		for (int i = 0; i < nContent+1; i++)
		{
			gotoxy(xKeyDisplay[i], j);
			cout << char(176);
		}
	}
	//ve thanh ngang ben tren va duoi
	for (int i = xKeyDisplay[0]; i <= xKeyDisplay[nContent]; i++)
	{
		//ve thanh ngang ben tren so 1
		gotoxy(i, Y_Display);
		cout << char(176);

		// ve thanh ngang ben tren so 2
		gotoxy(i, Y_Display + 2);
		cout << char(176);

		gotoxy(i, count*3 + 5);
		cout << char(176);
	}
}


/* ========== End Tao bang xuat thong tin ===========*/
/* ======= Xoa cac noi dung sau khi da xuat man hinh ===== */
void RemoveOldData(int nContent, int locate)
{
	for (int i = 0; i < nContent; i++)
	{
		gotoxy(xKeyDisplay[i] + 3, Y_Display + 3 + locate);
		cout << setw(xKeyDisplay[i + 1] - xKeyDisplay[i]-2) << setfill(' ') <<" ";		
	}
}

void RemoveNotification()
{
	for( int i = 1 ; i < 7 ;i++)
	{
		gotoxy(X_Notification-10,Y_Notification+i);
		printf("%-45s", " ");
	}
}

void CenterMenu()
{
	InitListAirplane(LA);
	ReadAirplaneFile(LA);
	
	InitFlightList(FL);
	ReadFlightFileFromFile(FL,LA);
	

	CreateAVLTree(root);
	ReadPassengerFromFile(root);

	Introduction();
	/*FloatingEffectWord(TenHocVien,X_TitlePage,Y_TitlePage,ColorCode_White);
	return;*/
	system("cls");
	int pointer;

	bool Exit = false;// false nghia la chua thoat, van dang dung
	
	while(Exit == false)
	{  
		pointer =  ScrollMenu(ThucDon);
		
		switch(pointer)
		{
		case 1:
			system("color 0E");
			MenuManageAirplane(LA);
			break;
		case 2:
			system("color 0E");
			MenuManageFlightLisht(FL);
			break;
		case 3:
			system("color 0E");
			BookTicket(root);
			break;
		case 4:
			system("color 0E");
			CancelFlightTicket(root);
			break;
		case 5:
			system("color 0E");
			SeePassengerList(root);
			break;
		case 6:
			system("color 0E");
			WatchUnbookedTicket();
			break;
		case 7:
			system("color 0E");
			WatchHowManyTimeFlightTookOff();
			break;
		case 8:
			system("color 0E");
			WatchFlightsWithDateTimeAndDestination();
			break;
		case MaxItem:
			WriteFlightToFile(FL);
			SavePassengerToFile(root);
			system("color 0E");
			Exit = true;// xac nhan thoat
			system("cls");
			ThankYouAndGoodBye();
			break;
		}
	}
}