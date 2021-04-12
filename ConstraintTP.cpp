#pragma once
/*Noi nay quy dinh nhung 
rang buoc cua phan nhap lieu noi dung chu viet*/
#include<iostream>
#include<string>
#include<string.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<cmath>// for funtion log10
#include<ctime>// danh cho thoi gian thuc
#include"MyLibraryTP.h"
#include<math.h>
#include"GlobalVariableTP.h"
using namespace std;


/* vua chu cai vua co chu so*/
/*ordinal = so thu tu - the hien vi tri cua cai rang buoc ma ta dang su dung o vi tri
thu bao nhieu de thao tac trong ham nhap thong tin */
/*distance the hien khoang cach thut dau dong voi tieu de cua dong do*/
void ConstraintForLetterAndNumber(string &result,bool &MoveOrNot,int &ordinal,bool &SaveOrNot,int distance)
{
	int lenght = (int)result.length();
	gotoxy(X_Add + distance,ordinal * 3 + Y_Add);
	cout << result;
	int count = lenght;

	while(true)
	{
		while( _kbhit() )
		{
			int signal = _getch();
			if( signal != 224 && signal != BACKSPACE && signal != 0)
			{
				/*	--------tu A den Z -----				------Tu a den z -------				-----Tu 0 den 9 -----*/
				if( ( 65 <= signal && signal <= 90 ) || ( 97 <= signal && signal <= 122 ) || ( 48 <= signal && signal <= 57 ) )
				{
					/*Limit_ID_Length la do dai gioi han cua no-*/
					if( count < Limit_ID_Length )
					{
						count++;// cap nhat bien count 
						cout << (char)signal;// hien thi no tren man hinh nhap thong tin
						result += (char)signal;// cap nhat ket qua vao RESULT
					}
				}
				else if( signal == ENTER)
				{
					MoveOrNot = true;// Enter cung tuong duong voi xuong dong 
					return;
				}
				
				else if(signal == ESC){
					SaveOrNot = false;
					return;
				}
			}
			else if( signal == BACKSPACE && count > 0)
			{
				/* xoa ki tu khoang trang - \b dai dien cho 
				khoang trang dung tren ban phim - xoa khoang trang vua nhap*/
				cout << "\b" << " " << "\b";
				/* xoa di 1 ki tu o vi tri cuoi cung - cap nhat lai 1 vi tri*/
				result.erase(result.length() - 1 , 1);
				/* vi day la BACKSPACE nen khong tinh gia tri nay vao bien count*/
				count--;
			}
		}// while(_kbhit())
	}// while(true)
}
/*ham nay se chi nhap ten nguoi hoac ten so hieu may bay*/
/* va cac danh tu chi co 1 tu duy nhat VD Phong,Thanh,Nguyen*/
void ConstraintForOnlyLetter(string &result,bool &MoveOrNot,int &ordinal,bool &SaveOrNot,int distance)
{
	int lenght = (int)result.length();
	int count = lenght;
	gotoxy(X_Add + distance,ordinal*3 + Y_Add);
	cout << result;
	

	while(true)
	{
		while( _kbhit() )
		{
			int signal = _getch();
			if ( signal != 224 && signal != BACKSPACE && signal != 0)
			{
				/*   --- tu A den Z ---						---- tu a den z ---*/ 
				if( ( 65 <= signal && signal <= 90 ) || ( 97 <= signal && signal <= 122 ) )
				{
					// do dai cua 1 chu toi da chi co 7 chu cai
					if( count < Litmit_Word_Length )
					{
						count ++;
						cout << (char)signal;
						result += (char)signal;
					}
				}
				else if( signal == ENTER)
				{
					return;
				}
				
				else if(signal == ESC){
					SaveOrNot = false;
					return;
				}
			}// if( signal != 224 && signal != BACKSPACE )
			else if( signal == BACKSPACE && count > 0)
			{
				/* xoa ki tu khoang trang - \b dai dien cho 
				khoang trang dung tren ban phim - xoa khoang trang vua nhap*/
				cout << "\b" << " " << "\b";
				/* xoa di 1 ki tu o vi tri cuoi cung - cap nhat lai 1 vi tri*/
				result.erase(result.length() - 1 , 1);
				/* vi day la BACKSPACE nen khong tinh gia tri nay vao bien count*/
				count--;
			}
		}// while( _khbit() )
	}// while(true)
}
/*Cho phep nhap danh tu co ki tu khoang trang o giua
VD Thanh Phong*/
void ConstraintsForLetterAndSpace(string &result,bool &MoveOrNot,int &ordinal,bool &SaveOrNot,int distance)
{
	int count = result.length();
	gotoxy(X_Add + distance,ordinal*3 + Y_Add);
	cout << result;
	bool Spaced = false; // false nghia la chua space
	int signal;
	while( true )
	{
		while( _kbhit() )
		{
			signal = _getch();
			if( signal != 224 && signal != 0 )
			{
				if ((65 <= signal && signal <= 90) || (97 <= signal && signal <= 122) || signal == SPACE )
				{
					/*gioi han do dai chuoi la 20*/
					if( count <= 20)
					{
						count++;
						/*Lam chac dieu kien de khong SPACE sai phim*/
						if( Spaced == true && signal == SPACE )
						{
							cout <<(char)signal;
							result += (char)signal;
							Spaced = true;
						}
						else
						{
							Spaced = false;
							cout <<(char)signal;
							result += (char)signal;
						}
					}
				}
				else if ( signal == ENTER)
				{
					SaveOrNot = true;
					return;
				}
				else if (signal == BACKSPACE && count >0)
				{
					cout << "\b" << " " << "\b";
					result.erase(result.length() - 1, 1);
					count--;
				}
				else if( signal == ESC)
				{
					SaveOrNot = false;
					return;
				}
			}// end if ( signal = ..... )
		}//end while( kbhit() )
	}// end while(true)

}

void ConstraintForOnlyNumber(int &result,bool &MoveOrNot,int &ordinal,bool &SaveOrNot,int distance,int LimitNumber)
{
	gotoxy(X_Add + distance,ordinal*3 + Y_Add);
	if( result != 0)
	{
		cout << result;
	}
	int count = 0;// mac dinh 

	int num = result;
	/*Lay di dai cua day so dang nhap vao*/
	do
	{
		count++;
		num /= 10;
	} while (num != 0);
	while( true )
	{
		while( _kbhit() )
		{
			int signal = _getch();
			if( signal != 224 && signal != SPACE && signal != 0 )
			{
				/*  ---tu 0 den 9--- va count nho hon 3*/
				if( 48 <= signal && signal <= 57)
				{
					/* signal = 56 -> numb = 56 - 48 = 8 -> ung dung voi so 8*/
					int Numb = signal - 48;
					if( signal == 48 && count == 0 )
					{
						continue;
					}
					/* vi du LimitNumber = 100 co nghia may bay chi cho 
					nhap toi da 100 cho ngoi */
					else if( (result*10 + Numb) <= LimitNumber) 
					{
						cout << Numb;
						result = result*10 + Numb;
						count ++;
					}
				}
				else if (signal == ESC)
				{
					SaveOrNot = false;
					return;
				}
				 
				else if( signal == 8 && count > 0 )
				{
					cout << (char)BACKSPACE<<" "<<(char)BACKSPACE;
					count--;
					result /= 10;
				}

				else if( signal == ENTER)
				{
					if (result > LimitNumber)
						continue;
					return;
				}
			}// ( signal != 224 && signal != BACKSPACE && signal != 0)
			
		}// while( _kbhit() )
	}// while(true)
}

/*space la khoang thut dau dong
Limit Reach la gia tri gioi han cua no*/
void ConstraintForDateAndTime( int &result,int &DTordinal,bool &SaveOrCancel,int space , int LimitReach)
{

	int count = 0;
	gotoxy(X_Add + space + DTordinal * 3,  9 + Y_Add);
	if( result != 0 )
		cout << result;

	int num = result;
	/*Lay do dai day so dang nhap*/
	do
	{
		count++;
		num /= 10;
	} while (num != 0);

	int signal ;
	while(true)
	{
		while( _kbhit() )
		{
			signal = _getch();

			/*thao tac nhap so*/
			if( signal != 224 && signal != SPACE && signal != 0 )
			{
				if(  48 <= signal && signal <= 57 )
				{
					int numb = signal - 48;
					/*vi nhu nhap 13 la gio thi khong hop le*/
					if( result > LimitReach )
						continue;

					if ( (result * 10 + numb) < LimitReach)
					{
						cout << numb;
						result = result * 10 + (numb);
						count++;
					}
				}
				else if (signal == 8 && count > 0)
				{
					cout << (char)BACKSPACE << " " << (char)BACKSPACE;
					count--;
					result /= 10;
				}
				else if (signal == ENTER)
				{

					if (result > LimitReach || (DTordinal >  1 && result == 0 ))
						continue;
					return;
				}
			}// if( signal != 224 && signal != SPACE && signal != 0 )

		}// while( _kbhit() )
	}//while(true)
}

void ConstraintForOnlyGender(int &result,bool &MoveOrNot,int &ordinal,bool &SaveOrNot,int distance)
{
	gotoxy(X_Add + distance,ordinal*3 + Y_Add);
	if( result != 0)
	{
		cout << result;
	}
	int count = 0;
	while( true )
	{
		while( _kbhit() )
		{
			int signal = _getch();
			if( signal != 224 && signal != SPACE && signal != 0 )
			{
				/*  ---tu 0 den 1--- va count nho hon 3*/
				if( 48 <= signal && signal <= 49)
				{
					/* signal = 56 -> numb = 56 - 48 = 8 -> ung dung voi so 8*/
					int Numb = signal - 48;
					
					/* vi du LimitNumber = 100 co nghia may bay chi cho 
					nhap toi da 100 cho ngoi */
					if( -1 < result*10 + Numb && result*10 +Numb < 2) 
					{
						cout << Numb;
						result = result*10 + Numb;
						count ++;
					}
					else if(signal == ESC)
					{
						SaveOrNot = false;
						return;
					}

				}
				 
				else if (signal == 8 && count >= 0)
				{
					cout << (char)BACKSPACE << " " << (char)BACKSPACE;
					count--;
					result /= 10;
				}

				else if( signal == ENTER)
				{
					if (result > 1)
						continue;
					return;
				}
			}// ( signal != 224 && signal != BACKSPACE && signal != 0)
		}// while( _kbhit() )
	}// while(true)
}



/*Chuan hoa chuoi string ta nhap vao*/
void StandardName(char *a)
{
	a[0] = toupper(a[0]);
	int length = strlen(a);
	for (int i = 1; i < length; ++i)
	{
		if (a[i -1] == ' ' && a[i] != ' ') a[i] = toupper(a[i]);
		else a[i] = tolower(a[i]);
	}
}