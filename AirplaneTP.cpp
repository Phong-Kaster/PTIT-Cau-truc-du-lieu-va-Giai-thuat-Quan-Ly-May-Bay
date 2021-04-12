#pragma once
#include"GlobalVariableTP.h"// bien toan cuc
#include"UserInterfaceTP.h"// thu vien toan cuc
#include"AirplaneTP.h"
#include"ConstraintTP.h"// cac rang buoc nhap xuat
#include"ProcessionTP.h"

// thong tin vi tri hien tai
int CurPosAirplane = 0;
int CurAirplanePage = 1;
int TotalAirplanePage = 0;
extern string ContentAirplane[3];
// tim vi tri cua may bay trong danh sach

void InitListAirplane(ListAirplane &LA)
{
	LA.SoLuong = 0;
}
Airplane *FindAirplane(ListAirplane LA, const char* Ma)
{
	for (int i = 0; i < LA.SoLuong; i++)
	{
		if (_stricmp(LA.DSMB[i]->SoHieuMB, Ma) == 0)
		{
			return LA.DSMB[i];
		}
	}
	return NULL;
}
int FindIndexAirplane(ListAirplane LA,const char *Ma)
{
	for(int i = 0 ; i < LA.SoLuong ;i++)
	{
		if( _stricmp(LA.DSMB[i]->SoHieuMB,Ma) == 0 )
		{
			return i;
		}
	}
	return -1;
}
// Cai lai mau nhu cu
void NormalBGAirplan()
{
	SetColor(14);// yellow
	SetBGColor(0);// black
}

// kiem tra xem may bay co nhap day du cac du lieu chua
bool AirplaneDataIsEmpty(Airplane *A)
{
	/*false la nhap thieu - true la nhap du*/
	if( strlen(A->SoHieuMB) == 0 || strlen(A->LoaiMB) == 0 || A->SoChoMB == 0)
	{
		return false;
	}
	
	return true;
}
// kiem tra xem da xoa may bay thanh cong chua
bool RemoveAirplaneIsSucceed(ListAirplane &LA,int ViTri)
{
	if( ViTri < 0)
	{
		return false;// khong co so hieu nay
	}

	 /*XOA = 3 => LA.DSMB[3] = LA.DSMB[4]*/
	for(int i = ViTri; i < LA.SoLuong ;i++)
	{
			LA.DSMB[i] = LA.DSMB[i+1];
	}
	LA.SoLuong--;// giai phong bo nho
	return true;// xoa thanh cong
}
/*=========Ham xuat danh sach may bay===========*/
// hien thong tin 1 cai may bay
void ShowAirplane(Airplane *A,int position)
{
	int xKeyDisplay[7] = {1,20,45,63,80,95, 107};// toa do X cac diem nut

	//RemoveOldData( sizeof(ContentAirplane) / sizeof(string),position);// xoa du lieu cu di
	gotoxy(xKeyDisplay[0] + 3, Y_Display + 3 + position*3);printf("%-15s",A->SoHieuMB);
	gotoxy(xKeyDisplay[1] + 3, Y_Display + 3 + position*3);printf("%-15s",A->LoaiMB);
	gotoxy(xKeyDisplay[2] + 3, Y_Display + 3 + position*3);printf("%-15d",A->SoChoMB);
}

void ShowListAirplaneOnePage(ListAirplane LA,int StartIndex)
{
	gotoxy(1,2);
	cout << " So luong may bay : " << LA.SoLuong;
	int i;
	for( i = 0 ; i + StartIndex < LA.SoLuong && i < NumberPerPage ; i++)
	{
		ShowAirplane(LA.DSMB[i+StartIndex] , i);
	}
	RemoveExceedMember(i, 3);
	gotoxy(X_Page,Y_Page);
	cout <<" Trang " << CurAirplanePage <<"/"<< TotalAirplanePage; 
}

void ChangeAirplaneMenuManagerPage(ListAirplane LA)
{
	gotoxy(X_TitlePage,Y_TitlePage);
	cout << " Quan li may bay ";

	Display( ContentAirplane,sizeof(ContentAirplane)/sizeof(string) );
	ShowListAirplaneOnePage(LA,(CurAirplanePage-1)*NumberPerPage);
}

/*Nhap thong tin may bay - kem theo cac rang buoc*/
void InputAirplane(ListAirplane &LA, bool EditedOrNot = false, bool DeleteOrNot = false )
{
	ShowCur(true);
	// kiem tra xem day la chinh sua thong tin hay nhap moi
	bool SaveOrNot = true;// kiem tra xem duoc luu lai hay chua
	bool MoveOrNot = false;// kiem tra xem nguoi dung co dung phim mui ten de di chuyen khong
	bool IDExisted = false;// kiem tra xem can tim kiem co ton tai khong - > false la khong ton tai
	string ID;// so hieu
	string TypeAirplane;// loai may bay
	int nChair = 0;// so cho ngoi
	int ordinal = 0;// so thu tu bat dau viet
	int target = -1;

	while(true)
	{
		switch(ordinal)
		{
		case 0:
		{
			//RemoveNotification();
			ConstraintForLetterAndNumber(ID, MoveOrNot, ordinal, SaveOrNot, 12);
			
			if (SaveOrNot == false)
			{
				RemoveFormComplete();
				return;
			}
			if (DeleteOrNot) {
				int target = RemoveConfirm();
				gotoxy(50,50);

				
				RemoveFormComplete();
				
				if (!RemoveAirplaneIsSucceed(LA, FindIndexAirplane(LA, ID.c_str()) ) )
				{
					gotoxy(X_Notification + 1, Y_Notification + 1);
					cout << " Xoa khong thanh cong";
				}
				else {
					gotoxy(X_Notification + 1, Y_Notification + 1);
					cout << " Xoa thanh cong";
				}
				
				system("color 0E");
				return;
			}

			

			if (ID == "") {
				gotoxy(X_Notification, Y_Notification + 1);
				cout << " Vui Long Khong Bo Trong ";
				break;
			}
			/*kIEM TRA XEM ID NHAP VAO CO Bi Trung khong*/
			
			target = FindIndexAirplane(LA, ID.c_str());
			if (target > -1 && EditedOrNot == false) {
				gotoxy(X_Notification, Y_Notification + 1);
				cout << " ID da ton tai ";
				break;
			}

			if (target < 0 && EditedOrNot == true) {
				gotoxy(X_Notification, Y_Notification + 1);
				cout << " ID khong ton tai ";
				break;
			}

			if (EditedOrNot)
			{
				ID = LA.DSMB[target]->SoHieuMB;
				TypeAirplane = LA.DSMB[target]->LoaiMB;
				nChair = LA.DSMB[target]->SoChoMB;

				gotoxy(X_Add + 12, 0 * 3 + Y_Add);
				cout << ID;
				gotoxy(X_Add + 12, 1 * 3 + Y_Add);
				cout << TypeAirplane;
				gotoxy(X_Add + 12, 2 * 3 + Y_Add);
				cout << nChair;
			}
			ordinal++;
			break;
		}
		case 1:// nhap hang may bay
			ConstraintForOnlyLetter(TypeAirplane,MoveOrNot,ordinal,SaveOrNot,12);
			if( SaveOrNot == false)
			{
				RemoveFormComplete();
				return;
			}
			if (TypeAirplane == "") {
				gotoxy(X_Notification, Y_Notification + 1);
				cout << " Vui Long Khong Bo Trong ";
				break;
			}
			ordinal++;
			break;
		case 2:// nhap so cho ngoi may bay
			ConstraintForOnlyNumber(nChair,MoveOrNot,ordinal,SaveOrNot,12, 999);
			if( SaveOrNot == false)
			{
				RemoveFormComplete();
				return;
			}
			if (nChair < 1) {
				gotoxy(X_Notification, Y_Notification + 1);
				cout << " Vui Long Khong Bo Trong ";
				break;
			}
			if( nChair < 20 ){
				gotoxy(X_Notification, Y_Notification + 1);
				cout << " So cho phai >= 20";
				break;
			}
			ordinal++;
			break;
		case 3:
			{
				/*Chinh sua thong tin*/
				if( EditedOrNot && target > -1)
				{
					strcpy(LA.DSMB[target]->SoHieuMB, ID.c_str());
					strcpy(LA.DSMB[target]->LoaiMB, TypeAirplane.c_str());
					LA.DSMB[target]->SoChoMB = nChair;
					gotoxy(X_Notification,Y_Notification+1);
					cout << " Sua Thanh Cong ";
				}
				/*Them moi*/
				else
				{
					LA.DSMB[LA.SoLuong] = new Airplane;
					strcpy(LA.DSMB[LA.SoLuong]->SoHieuMB, ID.c_str());
					strcpy(LA.DSMB[LA.SoLuong]->LoaiMB, TypeAirplane.c_str());
					LA.DSMB[LA.SoLuong]->SoChoMB = nChair;
					LA.DSMB[LA.SoLuong]->SoLanThucHienChuyenBay = 0;
					LA.SoLuong++;

					gotoxy(X_Notification,Y_Notification+1);
					cout << " Them thanh cong ";
				}

				WriteAirplaneToFile(LA);
				ID = "";
				TypeAirplane = "";
				nChair = 0;
				ordinal = 0;
				RemoveForm();
			}
			break;
		}// switch
	}// while(true)
	ShowCur(false);
}

/*========== MENU quan li may bay ==========*/
void MenuManageAirplane(ListAirplane &LA)
{
	ShowCur(false);
	system("cls");
	//system("color 0E");
	CurAirplanePage = 1;
	// ceil lam tron len
	TotalAirplanePage = (int)ceil( (double)LA.SoLuong/NumberPerPage );

	Display(ContentAirplane,sizeof(ContentAirplane) / sizeof(string) );
	ShowListAirplaneOnePage(LA,0);

	gotoxy(X_TitlePage,Y_TitlePage);
	cout << "Quan li may bay";
	
	int signal;
	while(true)
	{
		while( _kbhit() )
		{
			signal = _getch();
			if (signal == ESC)
				return;
			if( signal == 224)
			{
				signal = _getch();
				if( signal == PAGE_UP && CurAirplanePage > 1)
				{
					CurAirplanePage--;
					ChangeAirplaneMenuManagerPage(LA);
				}
				else if( signal == PAGE_DOWN && CurAirplanePage < TotalAirplanePage)
				{
					CurAirplanePage++;
					ChangeAirplaneMenuManagerPage(LA);
				}
				// them moi
				else if( signal == INSERT )
				{
					if( LA.SoLuong == MaxAirplane )
					{
						gotoxy(X_Notification,Y_Notification+1);cout <<"Danh sach day,khong the them";
						return;
					}
					CreateForm(ContentAirplane,0,3,27);
					InputAirplane(LA);
					TotalAirplanePage = (int)ceil( (double)LA.SoLuong/NumberPerPage );
					ShowListAirplaneOnePage(LA,(CurAirplanePage - 1)*NumberPerPage);
					ShowCur(false);
					
				}// endif signal == INSERT

				// xoa di
				else if( signal == DEL)
				{
					if( LA.SoLuong == 0 )
					{
						gotoxy(X_Notification,Y_Notification+1);cout <<"Danh sach rong,khong the xoa";
						return;
					}
					CreateForm(ContentAirplane,0, 1, 27);
					InputAirplane(LA, false, true);
					TotalAirplanePage = (int)ceil((double)LA.SoLuong / NumberPerPage);
					ShowListAirplaneOnePage(LA, (CurAirplanePage - 1) * NumberPerPage);
				}//else if( signal == DEL)
				// HOME == chinh sua
				else if ( signal == HOME )
				{
					CreateForm(ContentAirplane,0, 3, 27);
					InputAirplane(LA, true, false);
					TotalAirplanePage = (int)ceil((double)LA.SoLuong / NumberPerPage);
					ShowListAirplaneOnePage(LA, (CurAirplanePage - 1) * NumberPerPage);
				}// signal == HOME
			}
		}//while( _kbhit)
	}// while(true)
}
/*=========== Ket Thuc Menu quan li may bay ============*/