
#pragma once
#include"AirplaneTP.h"
#include"GlobalVariableTP.h"
#include"TicketTP.h"
#include"DateTime.h"
#include"FlightTP.h"
#include"ConstraintTP.h"
#include"ProcessionTP.h"
/*Vi tri cua danh sach chuyen bay*/
int CurPosFlight = 0;
int CurPosPreFlight = 0;
int CurFlightPage = 1;
int TotalFlightPage = 0;

int CurPosTicket = 1;
int CurPosPreTicket = 1;

extern string ContentFlight[6];
extern ListAirplane LA;

void InitFlight(Flight &F)
{
	F.TongSoVe = 0;
	F.TongSoDaBan = 0;
	F.TicketList = new Ticket[100];// cap phat mang dong
	F.TrangThai = 2;// 1: hủy chuyến, 2: còn vé, 3: hết vé,4: hoàn tất ;
}

void InitFlightList(FlightList &FL)
{
	FL.pHead = NULL;
	FL.pTail = NULL;
	FL.SoLuongChuyenBay = -1;
}
/*tao moi 1 cai FlightNode chuyen bay*/
FlightNode *CreateFlightNode(Flight Data)
{
	FlightNode *tempo = new FlightNode;
	if( tempo == NULL)
	{
		return NULL;
	}
	tempo->data = Data;
	tempo->pNext = NULL;

	return tempo;
}
// them dau danh sach
void AddBeginningList(FlightList &FL,Flight Data)
{
	FlightNode *tempo = CreateFlightNode(Data);

	tempo->pNext = FL.pHead;
	FL.pHead = tempo;
	FL.SoLuongChuyenBay++;
}

void AddEndingList(FlightList &FL,Flight Data)
{
	FlightNode *tempo = CreateFlightNode(Data);

	if( FL.pHead == NULL )
	{
		FL.pHead = FL.pTail = tempo;
	}
	else
	{
		FL.pTail->pNext = tempo;
		FL.pTail = tempo;
	}
	FL.SoLuongChuyenBay++;
}
// tim so thu tu dua vao MaChuyenBay
int FindIndexFlight( FlightList FL,const char *MaChuyenBayCanTim)
{
	int index = 0;
	for( FlightNode *search = FL.pHead ; search != NULL; search = search->pNext)
	{
		/*so sanh 2 chuoi voi nhau co phan biet hoa thuong*/
		if( _stricmp(search->data.MaChuyenBay,MaChuyenBayCanTim) == 0 )
		{
			return index;
		}
		index++;
	}
	return -1;
}
int FindDestination( FlightList FL,const char* SanBayDenCanTim)
{
	int index = 0;
	for( FlightNode *search = FL.pHead ; search != NULL; search = search->pNext)
	{
		if( _stricmp(search->data.SanBayDen ,SanBayDenCanTim) == 0 )
		{
			return index;
		}
		index++;
	}
	return -1;
}
FlightNode *FindFlight ( FlightList FL,const char *MaChuyenBayCanTim)
{
	if( FL.pHead == NULL)
		return NULL;
	for( FlightNode *search = FL.pHead ; search != NULL; search = search->pNext)
	{
		if( _strcmpi(search->data.MaChuyenBay,MaChuyenBayCanTim) == 0 )
		{
			return search;
		}
	}
	return NULL;
}

void InputDateAndTimeInfor(DateTime &DT, int ordinal )
{
	int DTordinal = 0;// vi tri khoi dau cho viec nhap
	bool SaveOrCancel = false;
	/*Hien form hien thi ngay - gio*/
	gotoxy(X_Add + 12 + 2 , ordinal * 3 + Y_Add);
	cout << ":";
	gotoxy(X_Add + 12 + 8 , ordinal * 3 + Y_Add);
	cout << "/";
	gotoxy(X_Add + 12 + 11, ordinal * 3 + Y_Add);
	cout << "/";


	while( true )
	{
		/*Kiem tra theo trinh tu Hour->Minutes->Day->Month->Year*/
		switch(DTordinal)
		{
		case 0:
			ConstraintForDateAndTime(DT.h,DTordinal,SaveOrCancel,12,23);
			DTordinal++;
			break;
		case 1:
			ConstraintForDateAndTime(DT.mi,DTordinal,SaveOrCancel,12,59);
			DTordinal++;
			break;
		case 2:
			ConstraintForDateAndTime(DT.d,DTordinal,SaveOrCancel,12,31);
			DTordinal++;
			break;
		case 3:
			ConstraintForDateAndTime(DT.m,DTordinal,SaveOrCancel,12,13);
			DTordinal++;
			break;
		case 4:
			ConstraintForDateAndTime(DT.y,DTordinal,SaveOrCancel,12,2100);
			return;
		}
	}//while( true )
}

bool RemoveHead(FlightList &FL)
{
	if( FL.pHead == NULL)
		return false;
	FlightNode *tempo = FL.pHead;
	FL.pHead = FL.pHead->pNext;
	delete tempo;
	FL.SoLuongChuyenBay--;
	return true;
}

bool RemoveEnding(FlightList &FL)
{
	if( FL.pHead == NULL)
		return false;
	FlightNode *tempo = NULL;
	for( FlightNode *search = FL.pHead ; search != NULL;search = search->pNext)
	{
		if( search == FL.pTail)
		{
			tempo->pNext = NULL;
			FL.pTail = tempo;
			delete search;
			--FL.SoLuongChuyenBay;
			return true;
		}
		tempo = search;
	}
	
}
/*Muc tieu la xoa node dung sau node TempoFlight*/
bool RemoveAfterAnother(FlightList &FL,FlightNode *TempoFlight)
{
	if( TempoFlight == NULL || TempoFlight->pNext == NULL)
		return false;

	FlightNode*RemovedNode = TempoFlight->pNext;
	TempoFlight->pNext = RemovedNode->pNext;
	delete RemovedNode;
	FL.SoLuongChuyenBay--;
	return true;
}
// xoa chuyen bay theo Ma chuyen bay
// TRUE LA XOA THANH CONG , FASLSE LA THAT BAI
bool RemoveFlightFollowID(FlightList &FL,const char *MaChuyenBayCanXoa)
{
	FlightNode *CleanedFlight = FindFlight(FL,MaChuyenBayCanXoa);

	if( CleanedFlight == NULL)
		return false;
	else if( CleanedFlight == FL.pHead)
		return RemoveHead(FL);
	else if( CleanedFlight == FL.pTail)
		return RemoveEnding(FL);
	else
	{
		FlightNode *tempora = FL.pHead;
		while (true) {
			if (tempora->pNext == CleanedFlight) {
				break;
			}
			tempora = tempora->pNext;
		}
			
		return RemoveAfterAnother(FL,tempora);
	}
}
// giai phong bo nho
bool CleanUpFlightList(FlightList &FL)
{
	if( FL.pHead == NULL)
		return false;
	FlightNode *tempo;
	while(FL.pHead != NULL)
	{
		tempo = FL.pHead;
		FL.pHead = FL.pHead->pNext;
		delete tempo;
	}
	return true;
}
// cap nhat trang thai chuyen bay
void AutoUpdateFlightStatus(FlightList &FL)
{
	for( FlightNode *search = FL.pHead; search != NULL ; search = search->pNext)
	{
		if( DateTimeIsValid( search->data.ThoiGianDi ) == false )
			//// 1: hủy chuyến, 2: còn vé, 3: hết vé,4: hoàn tất ; 
			search->data.TrangThai = 4;
	}
}

int CheckOut(Flight F, int x)
{
	for (int i = 0; i < F.TongSoDaBan; i++)
	{
		if (x == F.TicketList[i].Status)
		{
			return 1;
		}
	}
	return 0;
}

/*Ham nay ve tat cac cho ngoi ra thanh 1 bang -  moi vi tri duoc ke o
Ve da duoc ban se duoc danh dau mau RED*/
void TicketChairBoard(Flight F)
{
	int x = X_TicketChair + 8;
	int y = Y_TicketChair + 5;
	int Limit = F.TongSoVe;

	for ( int i = 1 ; i <= Limit ; i++ )
	{
		TicketStack(x , y, i, CheckOut(F,i));
		x += 8;
		/*i = 10 - da den vi tri cuoi cung cua hang do*/
		if (i % 10 == 0)
		{
			y += 5;
			x = X_TicketChair + 8;
		}
	}
}
/*Lam hieu ung cho cai ve duoc thanh sang tro toi chon*/
void EffectTicketMenu(int index)
{
	ShowCur(false);
	int Current = index;// lay vi tri cai ve hien tai

	int column = (Current - 1) % 10;//(18-1)%10 = 7 ->cot thu 8
	int row = (Current - 1) / 10;// (18-1)/10 = 1 ->hang thu 2

	SetBGColor(1);// highligh vi tri hien tai
	gotoxy( X_TicketChair + (column+1)*8, Y_TicketChair +(row+1)*5);
	cout << char(176) << setw(3) << setfill('0')<<Current<<char(176);

	/*Tam ve dung truoc tam ve hien tai truoc do*/
	column = (CurPosPreTicket - 1) % 10;// 18-1 = 7 ->> cai nay dang nam cot 7
	row = (CurPosPreTicket - 1) / 10; // 2

	SetBGColor(ColorCode_Black);
	gotoxy( X_TicketChair + (column+1)*8, Y_TicketChair +(row+1)*5);
	cout << char(176) << setw(3) << setfill('0')<<CurPosPreTicket<<char(176);
	CurPosPreTicket = Current;
}
/*Nut Dieu Khien De Chon Ve May Bay*/
int ChooseTicket (Flight &F)
{
	system("color 0E");
	// tao lai vi tri chon ve
	CurPosTicket = 1;
	CurPosPreTicket = 1;
	
	TicketChairBoard(F);
	int signal;
	int PASS = 1;// pass dung nhu 1 cai cong tac neu enter thi thoat ra ngoai
	SetBGColor(1);// blue
	gotoxy(X_TicketChair + (0 + 1) * 8, Y_TicketChair + (0 + 1) * 5);// (28,9)
	cout << char(176) << setw(3) << setfill('0') << 1 << char(176);

	while( PASS )
	{
		signal = _getch();
		if( signal == 0 ) signal = _getch();

		switch(signal)
		{
		case KEY_DOWN:
			if( CurPosTicket + 10 <= F.TongSoVe )
			{
				CurPosTicket = CurPosTicket + 10;
				EffectTicketMenu( CurPosTicket );
			}
			break;
		case KEY_UP:
			if( CurPosTicket - 10 >= 1)
			{
				CurPosTicket = CurPosTicket - 10;
				EffectTicketMenu( CurPosTicket  );
			}
			break;
		case KEY_LEFT:
			if( CurPosTicket > 1 )
			{
				CurPosTicket--;
				EffectTicketMenu( CurPosTicket  );
			}
			break;
		case KEY_RIGHT:
			if ( CurPosTicket < F.TongSoVe)
			{
				CurPosTicket++;
				EffectTicketMenu( CurPosTicket );
			}
			break;
		case ESC:
			return -1;
		case ENTER:
			if (CheckOut(F, CurPosTicket) == 1) {
				
				gotoxy(3, 5);
				cout << "Ve nay da co Hanh khach dat cho";
				Sleep(1000);
				gotoxy(3, 5);
				SetBGColor(ColorCode_Black);
				printf("%-50s", " ");
				break;
			}
			PASS = 0;
			return CurPosTicket;
		}// end switch
	}// while
	return 0;
}
/*xuat thong tin 1 chuyen bay*/
void ShowFlight(Flight F,int position)
{
	int xKeyDisplay[7] = {1,20,45,63,80,95, 107};// toa do X cac diem nut
	/*string ContentFlight[6] = { "Ma Chuyen Bay","San Bay Den"
	,"So Hieu May Bay","Thoi Gian Di","Tong So Ve","Trang Thai"};*/
	gotoxy(xKeyDisplay[0] + 3, Y_Display + 3 + position*3);printf("%-15s",F.MaChuyenBay);
	gotoxy(xKeyDisplay[1] + 3, Y_Display + 3 + position*3);printf("%-18s",F.SanBayDen);
	gotoxy(xKeyDisplay[2] + 3, Y_Display + 3 + position*3);printf("%-15s",F.SoHieuMB);
	gotoxy(xKeyDisplay[3] + 2, Y_Display + 3 + position*3);OutputDateTime(F.ThoiGianDi);
	gotoxy(xKeyDisplay[4] + 6, Y_Display + 3 + position*3);printf("%-3d",F.TongSoVe);
	gotoxy(xKeyDisplay[5] + 3, Y_Display + 3 + position*3);
	// 1: hủy chuyến, 2: còn vé, 3: hết vé,4: hoàn tất ; 
	switch(F.TrangThai)
	{
	case 1: cout << "Huy     ";
		break;
	case 2: cout << "Con ve  ";
		break;
	case 3: cout << "Het ve  ";
		break;
	case 4: cout << "Hoan tat";
		break;
	default:
		break;
	}


}

/*Xuat thong tin danh sach  chuyen bay*/
void ShowFlightList(FlightList FL)
{
	if( FL.pHead == NULL && FL.pTail == NULL) return;

	int count = -1 ;
	AutoUpdateFlightStatus(FL);

	for( FlightNode *search = FL.pHead ; search != NULL ; search = search->pNext)
	{
		count++;
		ShowFlight(search->data,count);
	}
}
/*hien thi chuyen bay theo trang*/
void ShowFlightListPerPage(FlightList FL, int StartIndex)
{
	gotoxy(1,2);
	cout << " So luong chuyen bay : " << FL.SoLuongChuyenBay;

	if( FL.pHead == NULL && FL.pTail == NULL) return;

	int count = -1 ;
	AutoUpdateFlightStatus(FL);

	for( FlightNode *search = FL.pHead ; search != NULL ; search = search->pNext)
	{
		count++;
		if( count == StartIndex)
		{
			int i = - 1;
			while( search != NULL && i < NumberPerPage - 1 )
			{
				ShowFlight(search->data,++i);
				search = search->pNext;
			}
			RemoveExceedMember(i+1, 7);
			break;
		}
	}
	gotoxy(X_Page,Y_Page);
	cout <<"Trang "<< CurFlightPage << "/" << TotalFlightPage;
}

void ChangePageManageFlightList(FlightList FL)
{
	gotoxy(1,2);
	cout << " So luong chuyen bay : " << FL.SoLuongChuyenBay;
	gotoxy(X_TitlePage,Y_TitlePage);
	cout << " Quan ly chuyen bay ";

	ShowFlightListPerPage(FL,(CurFlightPage-1)*NumberPerPage);

	gotoxy(X_Page,Y_Page);
	cout <<"Trang "<< CurFlightPage << "/" << TotalFlightPage;
}

// kiem tra xem da nhap du thong tin co du khong
bool FlighDataIsEmpty(Flight F)
{
	if( strlen(F.MaChuyenBay) == 0 || strlen(F.SanBayDen) == 0 || F.TongSoVe <= 0)
	{
		return false;
	}
	return true;
}
/*Edited = false de luon la nhap moi khi goi ham*/
void InputFlight( FlightList &FL,bool EditedOrNot, bool DeleteOrNot)
{
	ShowCur(true);
	
	int ordinal = 0;
	bool MoveOrNot = false;//ko di chuyen
	bool SaveOrNot = true;// mac dinh la nguoi dung se luu lai
	bool  IDExisted = false;// ma chuyen bay luon la nhap moi
	string ID;// Ma chuyen bay
	string destination;// San bay den
	string AirplaneID;//So hieu may bay
	DateTime DT;// ngay gio
	int nSoldTicket = 0;
	int nTicket = 0 ;// so ve trong chuyen bay 
	int status = 0 ;// luon con ve
	int target = -1;// kiem tra Ma chuyen bay ton tai hay chua
	/*string ContentFlight[6] = { "Ma Chuyen Bay","San Bay Den"
	,"So Hieu May Bay","Thoi Gian Di","Tong So Ve","Trang Thai"};*/
	int targett = -1;// kiem tra so hieu may bay co ton tai hay khong
	while( true )
	{
		switch(ordinal)
		{
		case 0:// nhap ma chuyen bay
			{
				
				ConstraintForLetterAndNumber(ID,MoveOrNot,ordinal,SaveOrNot,12);
				RemoveNotification();
				// neu nguoi dung thoat ra giua chung
				if (SaveOrNot == false)
				{
					RemoveFormComplete();
					return;
				}
				// xu ly neu bo trong
				if (ID == "")
				{
					gotoxy(X_Notification,Y_Notification);cout<<"Thong Bao";
					gotoxy(X_Notification, Y_Notification + 1);
					cout << "Vui Long Khong Bo Trong";
					break;
				}

				// xu ly neu la xoa
				if (DeleteOrNot) 
				{
					int target = RemoveConfirm();
					//RemoveNotification();
					gotoxy(50,50);

					RemoveFormComplete();
					// XOA THEO MA CHUYEN BAY DUOC NHAP
					if ( !RemoveFlightFollowID(FL,ID.c_str() )  )
					{ 
						gotoxy(X_Notification, Y_Notification    );cout <<" Thong Bao";
						gotoxy(X_Notification, Y_Notification + 1);cout <<" Xoa khong thanh cong";
					}
					else 
					{
						gotoxy(X_Notification, Y_Notification    );cout <<" Thong Bao";
						gotoxy(X_Notification, Y_Notification + 1);cout <<" Xoa thanh cong";
					}
					system("color 0E");
					return;
				}
				
				// tim kiem Ma Chuyen Bay
				target = FindIndexFlight(FL,ID.c_str() );
				
				if (target > -1 && EditedOrNot == false) {
						gotoxy(X_Notification, Y_Notification    );cout <<"Thong Bao";
						gotoxy(X_Notification, Y_Notification + 1);cout <<"ID da ton tai";
						gotoxy(X_Notification, Y_Notification + 2);cout <<"He thong khong chap nhan";
						gotoxy(X_Notification, Y_Notification + 3);cout <<"ID co cung noi dung";
						break;
				}

				else if (target < 0 && EditedOrNot == true) {
					gotoxy(X_Notification, Y_Notification    );cout << "Thong Bao";
					gotoxy(X_Notification, Y_Notification + 1);cout << "ID khong ton tai";
					break;
				}
				FlightNode *EditingFlight = FindFlight(FL,ID.c_str() );
				/*string ContentFlight[6] = { "Ma Chuyen Bay","San Bay Den"
				,"So Hieu May Bay","Thoi Gian Di","Tong So Ve","Trang Thai"};*/
				if (EditedOrNot)
				{
						//ordinal = 1;
						gotoxy(X_Add + 12, 0 * 3 + Y_Add);cout << EditingFlight->data.MaChuyenBay;
						gotoxy(X_Add + 12, 1 * 3 + Y_Add);cout << EditingFlight->data.SanBayDen;
						gotoxy(X_Add + 12, 2 * 3 + Y_Add);cout << EditingFlight->data.SoHieuMB;
						gotoxy(X_Add + 12, 3 * 3 + Y_Add);OutputDateTime(EditingFlight->data.ThoiGianDi);
						gotoxy(X_Add + 12, 4 * 3 + Y_Add);cout << EditingFlight->data.TongSoVe;
						gotoxy(X_Add + 12, 5 * 3 + Y_Add);cout << EditingFlight->data.TrangThai;
				}
				ordinal++;
				break;
			}
		case 1:// San bay den
			{
				ConstraintsForLetterAndSpace(destination,MoveOrNot,ordinal,SaveOrNot,12);
				RemoveNotification();
				if (SaveOrNot == false)
				{
					RemoveFormComplete();
					return;
				}
				if( destination =="")
				{
					gotoxy(X_Notification, Y_Notification    );cout << "Thong Bao";
					gotoxy(X_Notification, Y_Notification + 1);cout << " Vui Long Khong Bo Trong ";
					break;
				}
			}
			ordinal++;
			break;
		case 2:// So hieu may bay
			{
				 ConstraintForLetterAndNumber(AirplaneID,MoveOrNot,ordinal,SaveOrNot,12);
				 RemoveNotification();
				 if (SaveOrNot == false)
				 {
					RemoveFormComplete();
					return;
				 }
				 /*kiem tra xem So hieu may bay nhap vao co ton tai*/
				if (AirplaneID == "") {
					gotoxy(X_Notification, Y_Notification    );cout<<"Thong Bao";
					gotoxy(X_Notification, Y_Notification + 1);cout << " Vui Long Khong Bo Trong ";
					break;
				}

				 targett = FindIndexAirplane( LA,AirplaneID.c_str() );
				 
				 // neu may bay khong ton tai
				 
				 if( targett < 0 )
				 {
					 gotoxy(X_Notification,Y_Notification     );cout<<"Thong Bao";
					 gotoxy(X_Notification, Y_Notification + 1);cout <<"So hieu may bay khong ton tai";
					 break;
				 }
				 
			}
			
			ordinal++;
			break;
		case 3:// Nhap thoi gian di cua may bay
			{
				InitDataTime(DT);// khoi tao cac gia tri DateTime la thoi gian he thong
				InputDateAndTimeInfor(DT, ordinal);
				RemoveNotification();
				if (SaveOrNot == false)
				 {
					RemoveFormComplete();
					return;
				 }
				ordinal++;
			}
			break;
		case 4:// nhap so ve may bay
			{
				ConstraintForOnlyNumber(nTicket,MoveOrNot,ordinal,SaveOrNot,12,999);
				RemoveNotification();
				if (SaveOrNot == false)
				 {
					RemoveFormComplete();
					return;
				 }

				if( nTicket > LA.DSMB[targett]->SoChoMB || nTicket <20 )
				{
					gotoxy(X_Notification, Y_Notification    );cout << "Thong Bao";
					gotoxy(X_Notification, Y_Notification + 1);cout << "So Ve khong phu hoi voi";
					gotoxy(X_Notification, Y_Notification + 2);cout << "So cho tren May Bay";
					gotoxy(X_Notification, Y_Notification + 3);cout << "20 <= So cho <="<< LA.DSMB[targett]->SoChoMB;
					break;
				}
			}
			ordinal++;
			break;
		case 5:
			{
			/*
			thêm thông báo*/
			// 1: hủy chuyến, 2: còn vé, 3: hết vé,4: hoàn tất ; 
			gotoxy(X_Notification,Y_Notification+1);cout <<"1 = Huy     ";
			gotoxy(X_Notification,Y_Notification+2);cout <<"2 = Con ve  ";
			gotoxy(X_Notification,Y_Notification+3);cout <<"3 = Het ve  ";
			gotoxy(X_Notification,Y_Notification+4);cout <<"4 = Hoan tat";
			ConstraintForOnlyNumber(status, MoveOrNot, ordinal, SaveOrNot, 12, 4);
			RemoveNotification();
				if (SaveOrNot == false)
				{
					RemoveFormComplete();
					return;
				}
				ordinal++;
				break;
			}
		case 6:
			{
				Flight AddingFlight;
				strcpy(AddingFlight.MaChuyenBay,ID.c_str() );
				StandardName((char*)destination.c_str() );
				strcpy(AddingFlight.SanBayDen,destination.c_str());
				strcpy(AddingFlight.SoHieuMB,AirplaneID.c_str() );
				AddingFlight.ThoiGianDi = DT;
				AddingFlight.TongSoVe = nTicket;
				AddingFlight.TrangThai = status;
				/*string ContentFlight[6] = { "Ma Chuyen Bay","San Bay Den"
				,"So Hieu May Bay","Thoi Gian Di","Tong So Ve","Trang Thai"};*/

				/*Chinh sua*/
				if( EditedOrNot && target > -1)
				{
					/*Lay du lieu ve*/
					FlightNode *tempo = FindFlight(FL,AddingFlight.MaChuyenBay);
					AddingFlight.TongSoDaBan = tempo->data.TongSoDaBan;
					AddingFlight.TicketList  = tempo->data.TicketList;

					tempo->data = AddingFlight;
				}
				else// them moi
				{
					AddingFlight.TongSoDaBan = 0;
					AddEndingList(FL,AddingFlight);
				}

				//WriteFlightToFile(FL);

				ID="";
				destination="";
				AirplaneID ="";
				InitDataTime(DT);
				nTicket = 0;
				nSoldTicket = 0;
				status = 0;
				/*
				Chinh sua ham removeform cho danh sach chuyen bay phu hop
				*/
				RemoveNotification();
				RemoveForm();
				ordinal = 0;
			}
			break;
		} // end switch(ordinal)
	}// end while( true )
}

void MenuManageFlightLisht( FlightList &FL)
{

	system("cls");

	gotoxy(X_TitlePage,Y_TitlePage);
	cout << " Quan ly chuyen bay ";

	CurFlightPage = 1;
	TotalFlightPage = (int)ceil( (double) FL.SoLuongChuyenBay/NumberPerPage );

	Display( ContentFlight,sizeof(ContentFlight)/sizeof(string) );
	ShowFlightListPerPage(FL,0);
	

	int signal;
	while(true)
	{
		while( _kbhit() )
		{
			signal = _getch();
			if (signal == ESC) {
				ShowCur(false);
				return;
			}
			if( signal == 224)
			{
				signal = _getch();
				if( signal == PAGE_UP && CurFlightPage > 1)
				{
					CurFlightPage--;
					ChangePageManageFlightList(FL);
				}
				else if( signal == PAGE_DOWN && CurFlightPage < TotalFlightPage)
				{
					CurFlightPage++;
					ChangePageManageFlightList(FL);
				}
				else if( signal == INSERT)
				{
					//nChair la so ghe trong cac may bay
					CreateForm(ContentFlight,0,6,30);
					InputFlight(FL);
					
					TotalFlightPage = (int)ceil( (double)FL.SoLuongChuyenBay/NumberPerPage );
					ShowFlightListPerPage(FL,(CurFlightPage-1)/NumberPerPage);
				}
				else if ( signal == DEL)
				{
					CreateForm(ContentFlight,0,1,30);
					InputFlight(FL,false,true);
					TotalFlightPage = (int)ceil( (double)FL.SoLuongChuyenBay/NumberPerPage );
					ShowFlightListPerPage(FL,(CurFlightPage-1)/NumberPerPage);
					ShowCur(false);
				}
				// chinh sua
				else if ( signal == HOME)
				{
					CreateForm(ContentFlight,0,6,30);
					InputFlight(FL,true,false);
					TotalFlightPage = (int)ceil( (double)FL.SoLuongChuyenBay/NumberPerPage );
					ShowFlightListPerPage(FL,(CurFlightPage-1)/NumberPerPage);
					ShowCur(false);
				}
			}
		}// while( _kbhit() )
	}// while( true)
}