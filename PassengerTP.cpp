#pragma once
#include"UserInterfaceTP.h"
#include"ConstraintTP.h"
#include"ProcessionTP.h"
#include"PassengerTP.h"
#include"GlobalVariableTP.h"
int CurPosPassenger = 1;
int CurPassengerPage = 1;
int TotalPassengerPage = 0;
extern FlightList FL;
extern ListAirplane LA;
extern string ContentPassenger[5];
extern string ContentFlight[6];
extern int nPassenger;
unsigned int *ArrPassengerId;
/*Noi dung cho chuc nang thu 8*/
string SpecifedFlight[6] = {
		"Ma Chuyen Bay",
		"So Hieu May Bay",
		"Tong So Ve",
		"Gio Khoi Hanh",
		"Da Ban",
		"Con Trong"};
void CreateAVLTree(AVLTree &root)
{
	root = NULL;
	nPassenger = 0;
}

// tim max giua a va b
int maxi(int a,int b)
{
	if(a >= b)
	{
		return a;
	}
	return b;
}
// chieu cao cua cay
int height(AVLTree root)
{
	if( root == NULL)
	{
		return 0;
	}
	return root->height;
}

AVLTree CreateTree(Passenger data)
{
	AVLTree newpassenger = new PassengerNode;
	newpassenger->data = data;
	newpassenger->pLeft = NULL;
	newpassenger->pRight = NULL;
	newpassenger->height = 1;
	return newpassenger;
}
/*BE LEFT*/
AVLTree RightRotate(AVLTree y)
{
	AVLTree x = y->pLeft;
	AVLTree T2= x->pRight;

	// thuc hien xoay
	x->pRight = y;
	y->pLeft = T2;
	// cap nhat chieu cao
	y->height = maxi( height(y->pLeft),height(y->pRight) )+1;
	x->height = maxi( height(x->pLeft), height(x->pRight) ) +1;
	
	// tra ve node moi
	return x;
}
/*BE RIGHT*/
AVLTree LeftRotate(AVLTree x)
{
	AVLTree y = x->pRight;
	AVLTree T2 = y->pLeft;
	
	// thuc hien phep quay
	y->pLeft = x; 
	x->pRight = T2;

	// cap nhat chieu cao
	x->height = maxi( height(x->pLeft),height(x->pRight)  )+1;
	y->height = maxi( height(y->pLeft), height(y->pRight) )+1;
	
	return y;
}

// lay gia tri can bang
int getBalanceFactor(AVLTree root)
{
	if( root == NULL)
	{
		return 0;
	}
	return height(root->pLeft) - height(root->pRight);
}

// them theo toan bo thong tin cua hanh khach
AVLTree AddPassenger(AVLTree &root,Passenger data)
{
	//them nhu cay nhi phan binh thuong
	if(root == NULL)
	{
		return CreateTree(data);
	}
	if (data.CMND < root->data.CMND)
	{
		root->pLeft = AddPassenger(root->pLeft, data);
	}
	else if (data.CMND > root->data.CMND)
	{
		root->pRight = AddPassenger(root->pRight, data);
	}
	else  return root;
	/*cap nhat lai chieu cao cho cay*/
	root->height = maxi( height(root->pLeft),height(root->pRight) ) + 1;
	

	/*kiem tra xem co bi mat can bang hay khong*/
	int BalanceFactor = getBalanceFactor(root);
	// height(root->pLeft) - height(root->pRight);

	/*neu no mat can bang thi xay ra 4 truong hop*/

	// Left left case
	if( BalanceFactor > 1 &&
		data.CMND < root->pLeft->data.CMND)
	{
		return RightRotate(root);
	}
	// right right case
	if( BalanceFactor < -1 &&
		data.CMND > root->pRight->data.CMND)
	{
		return LeftRotate(root);
	}
	// left right case
	if( BalanceFactor > 1 &&
		data.CMND > root->pLeft->data.CMND)
	{
		root->pLeft = LeftRotate(root->pLeft);
		return  RightRotate(root);
	}

	// right left case
	if( BalanceFactor < -1 &&
		data.CMND < root->pRight->data.CMND)
	{
		root->pRight = RightRotate(root->pRight);
		return LeftRotate(root);
	}

	return root;
	
}

// tra ve gia tri cuc trai thap nhat
AVLTree minValuePassenger(AVLTree root)
{
	AVLTree current = root;
	if( current->pLeft != NULL)
	{
		current = current->pLeft;
	}
	return current;
}

// xoa theo CMND cua hanh khach
AVLTree RemovePassenger(AVLTree &root,Passenger data)
{
	// B1 tim vi tri ung voi cai node can xoa
	if(root == NULL)
	{
		return root;
	}

	if( data.CMND < root->data.CMND)
	{
		root->pLeft = RemovePassenger(root->pLeft,data);
	}
	else if( data.CMND > root->data.CMND)
	{
		root->pRight = RemovePassenger(root->pRight,data);
	}
	// neu da tim ra CMND bang dung CMND co trong cay AVL,thi no la node can xoa
	else
	{
		// TH1: ID co 1 cay con hoac khong co cay con nao
		if( (root->pLeft == NULL) || (root->pRight == NULL) )
		{
			AVLTree tempo = root->pLeft ? root->pLeft : root->pRight;

			// TH khong co nhanh con
			if( tempo == NULL)
			{
				tempo = root;
				root = NULL;
			}
			// TH co 1 nhanh con TRAI hoac PHAI
			else
			{
				*root = *tempo;/*TRUYEN DIA CHI CUA *TEMPO cho *ROOT*/
				free(tempo);/*GIAI PHONG VUNG NHO TEMPO DO khong dung toi nua*/
			}
		}
		// TH2 :node can xoa co 2 nhanh con
		else
		{
			/*Node thay the la node trai nhat cua nhanh ben PHAI*/
			/*Vi no lon hon tat ca node ben o nhanh ben trai va nho hon tat
			ca node o nhanh ben phai*/
			AVLTree tempo = minValuePassenger(root->pRight); 
			/*tim duoc thi chep noi dung cua node thay the vao vi tri node can
			xoa*/
			root->data = tempo->data;
			/*xoa node thay the o vi tri cu di*/
			root->pRight = RemovePassenger(root->pRight,tempo->data);
		}
		// B2: cap nhat do cao cua node
		root->height = maxi( height(root->pLeft) , height(root->pRight) )+1;
		// B3 : can bang cay
		int BalanceFactor = getBalanceFactor(root);

		// Left left case
		if( BalanceFactor > 1 &&
			data.CMND < root->pLeft->data.CMND)
		{
			return RightRotate(root);
		}
		// right right case
		if( BalanceFactor < -1 &&
			data.CMND > root->pRight->data.CMND)
		{
			return LeftRotate(root);
		}
		// left right case
		if( BalanceFactor > 1 &&
			data.CMND > root->pLeft->data.CMND)
		{
			root->pLeft = LeftRotate(root->pLeft);
			return RightRotate(root);
		}

		// right left case
		if( BalanceFactor < -1 && 
			data.CMND < root->pRight->data.CMND)
		{
			root->pRight = RightRotate(root->pRight);
			return LeftRotate(root);
		}
	}
}

bool FindPassengerFollowID(AVLTree root,unsigned int CMNDcantim)
{
	if( root != NULL)
	{
		if( root->data.CMND == CMNDcantim)
		{
			return true;
		}
		else if( root->data.CMND < CMNDcantim)
		{
			FindPassengerFollowID(root->pLeft,CMNDcantim);
		}
		else if( root->data.CMND > CMNDcantim)
		{
			FindPassengerFollowID(root->pRight,CMNDcantim);
		}
	}
	return false;
}

PassengerNode* FindPassenger(AVLTree root, unsigned int CMNDcantim)
{
	if (root == NULL) return NULL;
	if (root->data.CMND == CMNDcantim)
		return root;
	if (root->data.CMND > CMNDcantim)
		FindPassenger(root->pLeft, CMNDcantim);
	else
		FindPassenger(root->pRight, CMNDcantim);
}

void ShowPassenger(Passenger P,int position)
{
	int xKeyDisplay[7] = {1,20,45,63,80,95, 107};// toa do X cac diem nut
	gotoxy(xKeyDisplay[0] + 3, Y_Display + 3 + position*3);printf("%-5d",position+1);
	gotoxy(xKeyDisplay[1] + 3, Y_Display + 3 + position*3);printf("%-12d",P.CMND);
	gotoxy(xKeyDisplay[2] + 3, Y_Display + 3 + position*3);printf("%-20s",P.Ho);
	gotoxy(xKeyDisplay[3] + 3, Y_Display + 3 + position*3);printf("%-10s",P.Ten);
	gotoxy(xKeyDisplay[4] + 5, Y_Display + 3 + position*3);
	if( P.GioiTinh == 1)
		cout << "Nam";
	if( P.GioiTinh == 0)
		cout << "Nu";
}

void ShowListPassengerPerPage(AVLTree root,int BeginIndex)
{
	int i;

	for(  i = 0 ; i + BeginIndex <= nPassenger && i < NumberPerPage;i++)
	{
		PassengerNode* tempo = FindPassenger(root,ArrPassengerId[i+BeginIndex] );
		ShowPassenger(tempo->data,i);
	}

	RemoveExceedMember(i, 4);
	gotoxy(X_Page,Y_Page);
	cout << CurPassengerPage << "/" << TotalPassengerPage;
}

void swap ( unsigned int &x,unsigned int  &y)
{
	unsigned int tempo;
	tempo = x;
	x = y;
	y = tempo;
}
/*sap xep so CMND trong mang CMND[100]*/
void QuickSort(int left, int right, unsigned int a[]) {
	int key = a[(left + right) / 2];
	int i = left, j = right;
	do {
		while (a[i] < key) i++;// tien den khi gap a[i] > KEY
		while (a[j] > key) j--;// lui ve den khi a[j] < KEY
		if (i <= j) {// neu vi tri i < j trong mang thi doi cho
			if (i < j) 
				swap(a[i], a[j]);
			i++;	j--;// tiep tuc thuc hien duyet
		}
	} while (i <= j);
	if (left < j) QuickSort(left, j, a);
	if (right > i) QuickSort(i, right, a);
}
void WatchRoot(AVLTree root)
{
	if (root != NULL)
	{
		WatchRoot(root->pLeft);
		cout << root->data.Ten << "- " << root->data.CMND << endl;
		WatchRoot(root->pRight);
	}
}
void InputPassenger(AVLTree &root,bool EditedOrNot,bool DeleteOrNot, int IDPassenger)
{
	ShowCur(true);
	bool SaveOrNot = true;
	bool MoveOrNot = false;
	bool IDExisted = false;
	
	string FirstName;// Ho
	string LastName;// Ten
	int gender = 1;// 0 la nu , 1 la nam

	int ordinal = 1;
	gotoxy(X_Notification,Y_Notification);cout << " Thong Bao ";
	gotoxy(X_Notification,Y_Notification+1);cout << " 0 la Nu , 1 la Nam";

	int signal;
	while(true)
	{
		system("color 0E");
		switch(ordinal)
		{
		case 1:// NHAP Ho
			{
				ConstraintsForLetterAndSpace(FirstName,MoveOrNot,ordinal,SaveOrNot,12);
				if (SaveOrNot == false)
				{
					RemoveFormComplete();
					return;
				}
				if( FirstName =="")
				{
					gotoxy(X_Notification,Y_Notification);
					cout << " Thong Bao ";
					gotoxy(X_Notification, Y_Notification + 1);
					cout << "Khong bo trong";
				}
				
				ordinal++;
			}

			break;
		case 2:// Nhap ten
			{
				ConstraintForOnlyLetter(LastName,MoveOrNot,ordinal,SaveOrNot,12);
				if (SaveOrNot  == false)
				{
					RemoveFormComplete();
					return;
				}
				if( LastName =="")
				{
					gotoxy(X_Notification,Y_Notification);cout << " Thong Bao ";
					gotoxy(X_Notification, Y_Notification + 1);cout << "Khong bo trong";
				}
				ordinal++;
			}
			break;
		case 3:// nhap gioi tinh
			{
				 ConstraintForOnlyGender(gender,MoveOrNot,ordinal,SaveOrNot,12);
				 if (SaveOrNot == false)
				{
					RemoveFormComplete();
					return;
				}
				 // 0 la nu , 1 la nam
				if( gender == -1)
				{
					gotoxy(X_Notification,Y_Notification);
					cout << " Thong Bao ";
					gotoxy(X_Notification, Y_Notification + 1);
					cout << "Khong bo trong";
				}
				ordinal++;
			}
			break;
		case 4:
			{
				Passenger P;
				P.CMND = IDPassenger;
				strcpy(P.Ho,FirstName.c_str() );
				strcpy(P.Ten,LastName.c_str() );
				StandardName(P.Ho);
				StandardName(P.Ten);
				P.GioiTinh = gender;
				
				AddPassenger(root, P);

				gotoxy(X_Notification,Y_Notification);
				cout << " Thong Bao ";
				gotoxy(X_Notification, Y_Notification + 1);
				cout << " Dat ve thanh cong !!!";
				RemoveNotification();
				RemoveFormComplete();
				return;
			}
			break;
		}/*switch(ordinal)*/
	}/*While(true)*/
}


void WatchPassengerListOfFlight(AVLTree root,Flight F)
{
	ShowCur(false);
	DisplayForWatchOnly(ContentPassenger,sizeof(ContentPassenger)/sizeof(string), F.TongSoDaBan);

	for( int i = 0; i < F.TongSoDaBan;i++)
	{ 
		
		PassengerNode *tempora = FindPassenger(root, F.TicketList[i].CMND);
		if (tempora == NULL) continue;
		//gotoxy(1,1);.
		//cout << F.TicketList[i].CMND << endl;
		ShowPassenger(tempora->data,i);
		
	}
}
/*"5.Xem Danh Sach Hanh Khach Chi Tiet"*/
void SeePassengerList(AVLTree root)
{
	system("cls");
	
	gotoxy(X_TitlePage - 55,Y_TitlePage+3);
	cout <<"Kinh moi Thay nhap Ma chuyen bay theo phan danh sach chuyen bay hien co de kiem tra thong tin --->";
	/*Kiem tra xem MaChuyenBay co ton tai*/
	string result;
	CreateForm(ContentFlight,0,1,30);
	bool flag = false;
	bool MoveOrNot = false;
	bool SaveOrNot = true;
	int ordinal = 0;
	FlightNode* WatchingFlight = NULL;
	while( flag == false)
	{
		ShowCur(true);
		ConstraintForLetterAndNumber(result,MoveOrNot,ordinal,SaveOrNot,12);
		if (SaveOrNot == false)
		{
			RemoveFormComplete();
			return;
		}

		WatchingFlight = FindFlight(FL,result.c_str() );
		if (WatchingFlight == NULL )
		{
			gotoxy(X_Notification,Y_Notification);
			cout << " Thong Bao ";
			gotoxy(X_Notification,Y_Notification+1);
			cout << "So hieu khong ton tai";
		}
		else
		{
			flag = true;
		}
	}

	system("cls");
	gotoxy(X_TitlePage - 35 ,Y_TitlePage);

	cout <<" Danh sach hanh khach co ma chuyen bay "<<WatchingFlight->data.MaChuyenBay<<" toi "<<WatchingFlight->data.SanBayDen;
	cout <<" luc ";OutputDateTime(WatchingFlight->data.ThoiGianDi);

	//int countdown = nPassenger;
	
	WatchPassengerListOfFlight(root, WatchingFlight->data);

	/*thao tac de thoat ve man hinh chinh*/
	int signal;
	while( true )
	{
		while( _kbhit() )
		{
			signal = _getch();
			if( signal == ESC )
			{
				return;
			}
		}
	}
}
/*"4.Huy Bo Ve May Bay",*/
void CancelFlightTicket( AVLTree root)
{
	system("cls");
	
	gotoxy(X_TitlePage - 55, Y_TitlePage + 3);
	cout << "Kinh moi Thay nhap CMND theo phan danh sach chuyen bay hien co de HUY ve -->>";
	gotoxy(X_Notification,Y_Notification);cout << " Thong Bao ";
	/*Kiem tra xem MaChuyenBay co ton tai*/
	string result;
	CreateForm(ContentFlight,0, 1, 30);
	bool flag = false;
	bool MoveOrNot = false;
	bool SaveOrNot = true;
	int ordinal = 0;
	FlightNode* WatchingFlight = NULL;
	while (flag == false)
	{
		system("color 0E");
		ShowCur(true);
		ConstraintForLetterAndNumber(result, MoveOrNot, ordinal, SaveOrNot, 12);
		if (SaveOrNot == false)
		{
			RemoveFormComplete();
			return;
		}

		WatchingFlight = FindFlight(FL, result.c_str());
		if (WatchingFlight == NULL)
		{
			
			gotoxy(X_Notification, Y_Notification + 1);
			cout << "Chuyen bay khong ton tai       ";
			gotoxy(X_Notification, Y_Notification + 2);
			cout << "Vui long nhap lai";
		}
		else
		{
			if( WatchingFlight->data.TrangThai == 1 || WatchingFlight->data.TrangThai == 4 )
			{
				ShowCur(false);
				gotoxy(X_Notification, Y_Notification + 1);
				cout << "Chuyen bay da HUY hoac HOAN TAT";
				gotoxy(X_Notification, Y_Notification + 2);
				cout << "Vui long nhap lai";
				continue;
			}
			flag = true;
		}
	}
	RemoveNotification();
	gotoxy(X_TitlePage - 55, Y_TitlePage + 3);
	cout << "Kinh moi Thay nhap CMND theo phan danh sach chuyen bay hien co de kiem tra thong tin --->";
	CreateForm(ContentPassenger,1, 2, 30);
	int IDHanhKhach = 0;
	int target = -1;
	while (true)
	{
		ShowCur(true);
		ConstraintForOnlyNumber(IDHanhKhach, MoveOrNot, ordinal, SaveOrNot, 12, 999999);
		if (SaveOrNot == false)
		{
			RemoveFormComplete();
			return;
		}

		for (int i = 0; i < WatchingFlight->data.TongSoDaBan; i++)
		{
			if (WatchingFlight->data.TicketList[i].CMND == IDHanhKhach) {
				target = i; break;
			}
		}

		if (target == -1) 
		{
			gotoxy(X_Notification,Y_Notification);
			cout << " Thong Bao ";
			gotoxy(X_Notification , Y_Notification + 1);
			cout << "So CMND khong co";
			gotoxy(X_Notification , Y_Notification + 2);
			cout << "o danh sach hanh khach";
		}
		else break;
	}
	RemoveNotification();
	int confirm = RemoveConfirm();
	if (confirm == 0) {

		for (int i = target; i < WatchingFlight->data.TongSoDaBan; i++)
		{
			WatchingFlight->data.TicketList[i - 1] = WatchingFlight->data.TicketList[i];
		}
		WatchingFlight->data.TongSoDaBan--;
	}
	else {
		RemoveFormComplete();
	}
	return;
}
/*3.Dang Ky Ve May Bay*/
void BookTicket(AVLTree &root)
{
	system("cls");

	gotoxy(X_TitlePage - 55, Y_TitlePage + 3);
	cout << "Kinh moi Thay nhap Ma chuyen bay theo phan danh sach chuyen bay hien co de kiem tra thong tin --->";
	/*Kiem tra xem MaChuyenBay co ton tai*/

	string result;
	CreateForm(ContentFlight, 0, 1, 30);
	bool flag = false;
	bool MoveOrNot = false;
	bool SaveOrNot = true;
	int ordinal = 0;
	FlightNode* WatchingFlight = NULL;
	while (flag == false)
	{
		system("color 0E");
		ShowCur(true);
		ConstraintForLetterAndNumber(result, MoveOrNot, ordinal, SaveOrNot, 12);
		if (SaveOrNot == false)
		{
			RemoveFormComplete();
			return;
		}

		WatchingFlight = FindFlight(FL, result.c_str());
		if (WatchingFlight == NULL)
		{
			gotoxy(X_Notification,Y_Notification);
			cout << " Thong Bao ";
			gotoxy(X_Notification, Y_Notification + 1);
			cout << "Chuyen bay khong ton tai       ";
			gotoxy(X_Notification, Y_Notification + 2);
			cout << "Vui long nhap lai";

		}
		else
		{

			if(WatchingFlight->data.TrangThai == 3 || WatchingFlight->data.TrangThai == 1 || WatchingFlight->data.TrangThai == 4 )
			{
				ShowCur(false);
				gotoxy(X_Notification, Y_Notification + 1);
				cout << "Chuyen bay da HUY hoac HOAN TAT";
				gotoxy(X_Notification, Y_Notification + 2);
				cout << "Vui long nhap lai";
				continue;
			}
			flag = true;
		}
	}
	/*CHON VE MUON DAT*/
	system("cls");

	gotoxy(X_TitlePage - 32, Y_TitlePage);
	cout << " Danh sach hanh khach co ma chuyen bay " << WatchingFlight->data.MaChuyenBay << " toi " << WatchingFlight->data.SanBayDen;
	cout << " luc "; OutputDateTime(WatchingFlight->data.ThoiGianDi);

	gotoxy(3, 4);
	cout << "CHU Y ->> Ve co mau Do = ve da co nguoi dat cho!!!!";

	while (true) {
		system("color 0E");
		int ChoosenTicket = ChooseTicket(WatchingFlight->data);

		if (ChoosenTicket == -1) return;
		int IDHanhKhach = 0, target = -1;

		
		gotoxy(X_TitlePage + 30, Y_TitlePage + 3);
		system("color 0E");
		cout << "Vui Long Nhap CMND ->";
		CreateForm(ContentPassenger, 1, 2, 30);
		ShowCur(true);
		ConstraintForOnlyNumber(IDHanhKhach, MoveOrNot, ordinal, SaveOrNot, 12, 999999);
		if (SaveOrNot == false)
		{
			gotoxy(X_TitlePage + 30, Y_TitlePage + 3);
			printf("%-50s", " ");
			RemoveFormComplete();
			continue;
		}
		/*Tim kiem xem cai ID nay co nam trong danh sach ve chua*/
		for (int i = 0; i < WatchingFlight->data.TongSoDaBan; i++)
		{
			if (WatchingFlight->data.TicketList[i].CMND == IDHanhKhach) {
				target = i;
				break;
			}
		}
		/*Da dat ve roi va dat them lan nua*/
		if (target > -1) {
			gotoxy(3, 5);
			cout << "Ban da dat ve roi !!! (^_^)";
			Sleep(1000);
			gotoxy(3, 5);
			printf("%-50s", " ");


			gotoxy(X_TitlePage + 30, Y_TitlePage + 3);
			printf("%-50s", " ");
			RemoveFormComplete();
			continue;
		}
		/*Khong tim ra*/
		if (target == -1)
		{
			PassengerNode* tempora = FindPassenger(root, IDHanhKhach);
			/*Neu chua ton tai thi nhap moi*/
			if (tempora == NULL) {
				CreateForm(ContentPassenger, 1, sizeof(ContentPassenger) / sizeof(string), 27);
				gotoxy(X_Add + 12, 0 * 3 + Y_Add);
				cout << IDHanhKhach;
				InputPassenger(root, false, false, IDHanhKhach);
				nPassenger++;
			}
			Ticket AddingTicket;
			AddingTicket.CMND = IDHanhKhach;
			AddingTicket.Status = ChoosenTicket;
			WatchingFlight->data.TicketList[WatchingFlight->data.TongSoDaBan] = AddingTicket;
			WatchingFlight->data.TongSoDaBan++;
		}
	}
}
/*"6.Xem So Do Cho Ngoi & Danh Sach Ve Con Trong",*/
void WatchUnbookedTicket()
{
	system("cls");
	
	gotoxy(X_TitlePage - 55, Y_TitlePage + 3);
	cout << "Kinh moi Thay nhap Ma chuyen bay theo phan danh sach chuyen bay hien co de kiem tra thong tin --->";
	string IDFlight;
	CreateForm(ContentFlight, 0, 1, 30);
	bool SaveOrNot = true;
	bool DeleteOrNot;
	bool MoveOrNot = false;
	FlightNode* WatchingFlight = NULL;
	int ordinal = 0;
	while (true)
	{
		system("color 0E");
		ShowCur(true);
		ConstraintForLetterAndNumber(IDFlight, MoveOrNot, ordinal, SaveOrNot, 12);
		if(SaveOrNot == false)
		{
			RemoveFormComplete();
			return;
		}
		WatchingFlight = FindFlight(FL, IDFlight.c_str());
		if (WatchingFlight == NULL)
		{
			gotoxy(X_Notification, Y_Notification + 1);
			cout << "Chuyen bay khong ton tai";
			gotoxy(X_Notification, Y_Notification + 2);
			cout << "Vui long nhap lai";
		}
		else
		{
			break;
		}
	}

	system("cls");
	ShowCur(false);
	gotoxy(X_TitlePage, Y_TitlePage);
	cout << "Danh sach cho ngoi cua chuyen bay " << WatchingFlight->data.MaChuyenBay << " toi " << WatchingFlight->data.SanBayDen;
	cout << " luc ";  OutputDateTime(WatchingFlight->data.ThoiGianDi);
	gotoxy(3, 4);
	cout << " Ve mau Do = ve da co Hanh khach dat ve";
	TicketChairBoard(WatchingFlight->data);

	int signal;
	while (true)
	{
		signal = _getch();
		if (signal == ESC)
		{
			return;
		}
	}
}

void GotoDetailForWatchFlightHistory()
{
	string GotoDetail[5] = { "Chu thich" ,
							"1.Aircraft Number = So Hieu May Bay",
							"2.Airline Company = Hang May Bay",
							"3.Number Of Seats = So Luong Ghe Ngoi",
							"4.Flights Times = So lan thuc hien chuyen bay"};
	for( int i = 0 ; i < 5 ; i++)
	{
		gotoxy(X_Add - 30 ,Y_Add + i*2);
		cout << GotoDetail[i];
	}
}
void ShowHowManyTimesAirplaneTookOff(Airplane *A,int position)
{
	int xKeyDisplay[7] = { 1,20,45,63,80,95, 107 };
	gotoxy(xKeyDisplay[0] + 3, Y_Display + 3 + position * 3); printf("%-20s", A->SoHieuMB);
	gotoxy(xKeyDisplay[1] + 3, Y_Display + 3 + position * 3); printf("%-20s", A->LoaiMB );
	gotoxy(xKeyDisplay[2] + 3, Y_Display + 3 + position * 3); printf("%-5d",  A->SoChoMB );
	gotoxy(xKeyDisplay[3] + 3, Y_Display + 3 + position * 3); printf("%-5d",  A->SoLanThucHienChuyenBay);
}
/*"7.Xem Chi Tiet So Lan Thuc Hien Chuyen Bay",*/
void WatchHowManyTimeFlightTookOff()
{
	system("cls");

	gotoxy(X_TitlePage, Y_TitlePage);
	cout << " SO CHUYEN BAY DA THUC HIEN CUA CAC MAY BAY";

	string StaticsTable[4] = { "Aircraft Number","Airline Company" ,"Number Of Seat","Flights Times"};
	GotoDetailForWatchFlightHistory();
	

	for (int i = 0; i < LA.SoLuong; i++)
	{
		ShowHowManyTimesAirplaneTookOff(LA.DSMB[i], i);
	}
	DisplayForWatchOnly(StaticsTable, 4, LA.SoLuong);
	/*ESC de quay lai man hinh chinh*/
	int signal;
	while (true)
	{
		signal = _getch();
		if (signal == ESC)
		{
			return;
		}
	}
}
void ShowSpecificFlight(Flight F,int position)
{
	int xKeyDisplay[7] = {1,20,45,63,80,95, 107};// toa do X cac diem nut
	gotoxy(xKeyDisplay[0] + 3, Y_Display + 3 + position*3);printf("%-20s",F.MaChuyenBay);
	gotoxy(xKeyDisplay[1] + 3, Y_Display + 3 + position*3);printf("%-20s",F.SoHieuMB);
	gotoxy(xKeyDisplay[2] + 3, Y_Display + 3 + position*3);printf("%-5d",F.TongSoVe);
	gotoxy(xKeyDisplay[3] + 3, Y_Display + 3 + position*3);OutputDateTime(F.ThoiGianDi);
	gotoxy(xKeyDisplay[4] + 5, Y_Display + 3 + position*3);printf("%-3d",F.TongSoDaBan);
	gotoxy(xKeyDisplay[5] + 5, Y_Display + 3 + position*3);printf("%-3d",(F.TongSoVe-F.TongSoDaBan));
}
/*Xem Cac Chuyen Bay Di Toi Cac Dia Danh & Ngay Gio Cu The*/
void WatchFlightsWithDateTimeAndDestination()
{
	system("cls");
	int ordinal = 0;
	bool SaveOrNot = true;
	bool MoveOrNot = false;
	bool flag = true;
	int DestinationExisted = -1;// tim kiem san bay den co ton tai khong
	string destination;
	DateTime DT;
	/*Man hinh mo dau*/
	gotoxy(X_TitlePage - 55, Y_TitlePage + 3);
	cout << "Kinh moi Thay nhap Ma chuyen bay theo phan danh sach chuyen bay hien co de kiem tra thong tin -->>        San Bay Den : ";
	/*string ContentFlight[6] = {
	"MaChuyenBay",
	"SanBayDen",
	"SoHieuMayBay",
	"ThoiGianDi",
	"TongSoVe",
	"TrangThai"};*/
	while( flag == true )
	{
		switch(ordinal)
		{
		case 0:
			{
				//CreateForm(ContentFlight,1,2,30);
				ShowCur(true);
				ConstraintsForLetterAndSpace(destination,MoveOrNot,ordinal,SaveOrNot,12);
				/*Neu nhan phim ESCAPE*/
				if( SaveOrNot == false)
				{
					RemoveFormComplete();
					return;
				}
				/*Neu bi bo trong*/
				if( destination == "")
				{
					gotoxy(X_Notification,Y_Notification    );cout << "Thong Bao";
					gotoxy(X_Notification,Y_Notification + 1);cout << "Vui Long Khong Bo Trong";
				}
				/*Xu li xem co ton tai dia danh nay khong*/
				DestinationExisted = FindDestination(FL,destination.c_str() );
				StandardName((char *)destination.c_str());

				if( DestinationExisted == -1 )
				{
					gotoxy(X_Notification,Y_Notification    );cout << "Thong Bao";
					gotoxy(X_Notification,Y_Notification + 1);cout << "Khong co chuyen bay toi "<<destination;
					gotoxy(X_Notification,Y_Notification + 2);cout << "Vui long chon dia diem khac";
					break;
				}
			}
			ordinal++;
			break;
		case 1:
			{
				flag = false;
				break;
			}
		}
	}
	system("cls");
	gotoxy(X_TitlePage -35,Y_TitlePage);
	cout <<" Danh sach cac chuyen bay toi thanh pho "<<destination;

	int count = 0;
	for (FlightNode *search = FL.pHead;search != NULL;search = search->pNext)
	{
		if( strcmpi( search->data.SanBayDen,destination.c_str()) == 0 )
		{
			ShowSpecificFlight(search->data,count++);
		}
	}
	DisplayForWatchOnly(SpecifedFlight,sizeof(SpecifedFlight)/sizeof(string),count);
	int signal;
	while(true)
	{
		while( _kbhit() )
		{
			signal = _getch();
			if( signal == ESC )
			{
				return;
			}
		}
	}
}