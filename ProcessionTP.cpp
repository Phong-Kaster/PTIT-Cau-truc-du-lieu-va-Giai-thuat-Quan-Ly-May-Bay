#pragma once
#include"UserInterfaceTP.h"
#include"AirplaneTP.h"
#include<fstream>
#include"ProcessionTP.h"
#include"FlightTP.h"
#include"PassengerTP.h"
#include <string>
int nPassenger;
void Introduction()
{
	system("color 0E");// nen den chu mau vang
	ShowCur(false);
	string temp;
	ifstream file("Introduction.txt", ios::in);

	if (file.good())
	{
		while ( file.eof() == false )
		{
			getline(file,temp);
			//Sleep(80);
			cout << temp << endl;
		}
	}
	else
	{
		cout << " \n Liet ket file that bai " << endl;
	}
	gotoxy(50, 25);
	cout << "Nguyen Thanh Phong";
	gotoxy(50, 27);
	cout << "N18DCCN147";
	gotoxy(50, 29);
	cout << "D18CQCN03-N";
	ShowCur(false);

	gotoxy(50, 31);
	SetBGColor(ColorCode_Black	);
	SetColor(ColorCode_Red );
	cout << "Please ! Press ENTER to continue !!!! ";
	SetBGColor(ColorCode_Black	);

	while (!_kbhit()) {
		gotoxy(45, 32);
		SetColor(1 + rand() % 15);
		Sleep(100);
		cout << "HOC VIEN CONG NGHE BUU CHINH VIEN THONG CO SO TP HO CHI MINH";
	}
	
	cin.ignore();
	return;
}

void ThankYouAndGoodBye()
{
	system("color 0E");// nen den chu mau vang
	ShowCur(false);
	string temp;
	ifstream file("ThankYouSoMuch.txt", ios::in);

	if (file.good())
	{
		while ( file.eof() == false )
		{
			getline(file,temp);
			cout << temp << endl;
		}
	}

	_getch();
}
/*Doc ghi file may bay*/
void ReadAirplaneFile(ListAirplane &LA)
{
	ifstream filein;
	filein.open("DSMB.TXT", ios_base::in);// ios_base::in la de doc

	
	string temp;
	int i = 0;
	if( filein.is_open() )
	{
		while(!filein.eof())
		{
			Airplane *A = new Airplane;

			filein >> A->SoHieuMB;
			if (strcmp(A->SoHieuMB, "") == 0) continue;
			filein >> A->LoaiMB;
			filein >> A->SoChoMB;
			filein.ignore();
			// cap nhat phan tu trong mang con tro
			LA.DSMB[i++] = A;
			// cap nhat so luong phan tu trong mang
			LA.SoLuong++;
		}
	}
	filein.close();
}

void WriteAirplaneToFile(ListAirplane &LA)
{
	ofstream fileout;
	fileout.open("DSMB.TXT",ios_base::out);// ios_base::out la de ghi vao file
	if( fileout.is_open() )
	{
		for( int i = 0 ; i < LA.SoLuong ; i++)
		{
			fileout << LA.DSMB[i]->SoHieuMB <<" "<<LA.DSMB[i]->LoaiMB<<" "<<LA.DSMB[i]->SoChoMB<<endl;
		}
	}
	else
	{
		gotoxy(X_Notification,Y_Notification+1);
		cout << " Ket noi file de ghi vao that bai";
	}
	fileout.close();
}
/*Doc ghi file chuyen bay*/
void ReadTicketListOfOneFlight(Flight &F)
{
	ifstream file;
	char filenameve[50] = "DSV\\";
	strcat(filenameve, F.MaChuyenBay);
	strcat(filenameve, ".TXT");
	/*kET QUA = DSS\\GERMANY.TXT*/
	/*Mo file de doc va thuc hien cac thao tac khac*/
	file.open(filenameve, ios_base::in);
	if (file.is_open()) 
	{
		file >> F.TongSoDaBan;
		string temp;
		getline(file, temp);
		F.TicketList = new Ticket[F.TongSoDaBan];

		for (int i = 0; i < F.TongSoDaBan; i++)
		{
			file >> F.TicketList[i].CMND;
			file >> F.TicketList[i].Status;
		}
	}
	file.close();
}
void ReadFlightFileFromFile(FlightList &FL,ListAirplane &LA)
{
	ifstream filein;
	filein.open("DSCB.TXT",ios_base::in);
	for( int i = 0; i < LA.SoLuong;i++)
	{
		LA.DSMB[i]->SoLanThucHienChuyenBay = 0;
	}
	
	Flight F;
	int i;
	if( filein.is_open() )
	{
		int nFlight;// doc so chuyen bay
		filein >> nFlight;

		string temp;
		getline(filein, temp);
		for(int j = 0 ; j<nFlight ;j++)
		{
			if (strcmp(F.MaChuyenBay,"") == 0) break;
			filein.getline(F.MaChuyenBay,15,'\n');
			filein.getline(F.SanBayDen,20,'\n');
			filein.getline(F.SoHieuMB,15,'\n');
			
			// do thoi gian khoi hanh
			filein >> F.ThoiGianDi.h;
			filein >> F.ThoiGianDi.mi;
			filein >> F.ThoiGianDi.d;
			filein >> F.ThoiGianDi.m;
			filein >> F.ThoiGianDi.y;
			filein >> F.TongSoVe;
			//filein >> F.TongSoDaBan;
			filein >> F.TrangThai;
			getline(filein,temp);
			//cout << F.MaChuyenBay << "-"<<F.SanBayDen<<"-"<<F.SoHieuMB<<"-"<<  F.ThoiGianDi.h<<":"<<F.ThoiGianDi.mi<<" "<<F.ThoiGianDi.d<<"-"<<F.ThoiGianDi.m<<"-"<<F.ThoiGianDi.y << endl;
		/*doc danh sach ve cua chuyen bay do*/
			for(i = 0 ;i < LA.SoLuong ;i++)
			{
				if( _stricmp(F.SoHieuMB,LA.DSMB[i]->SoHieuMB) == 0 )
				{
					
					LA.DSMB[i]->SoLanThucHienChuyenBay++;
					
				}
				//cout << LA.DSMB[i]->SoHieuMB <<"-"<< LA.DSMB[i]->SoLanThucHienChuyenBay <<endl;
			}
			ReadTicketListOfOneFlight(F);
			//cout << F.MaChuyenBay << "-" << F.TongSoDaBan << endl;
			AddEndingList(FL,F);
		//getline(filein,temp);
		}
	FL.SoLuongChuyenBay++;
	}
	filein.close();
}
/*luu 1 chuyen bay*/
void SaveTicketListOfOneFlight(Flight &F)
{
	ofstream file;
	char filenameve[50] = "DSV\\";
	strcat(filenameve, F.MaChuyenBay);
	strcat(filenameve, ".TXT");
	file.open(filenameve,ios_base::out);
	if( file.is_open() )
	{
		file << F.TongSoDaBan << endl;
		for( int i = 0; i < F.TongSoDaBan ;i++)
		{
			file << F.TicketList[i].CMND << endl;
			file << F.TicketList[i].Status << endl;
		}
	}
	file.close();
}

void SaveFlight( Flight &F,ofstream &fileout)
{
	fileout << F.MaChuyenBay << endl;
	fileout << F.SanBayDen << endl;
	fileout << F.SoHieuMB << endl;
	fileout << F.ThoiGianDi.h << endl;
	fileout << F.ThoiGianDi.mi << endl;
	fileout << F.ThoiGianDi.d << endl;
	fileout << F.ThoiGianDi.m << endl;
	fileout << F.ThoiGianDi.y << endl;
	fileout << F.TongSoVe << endl;
	//fileout << F.TongSoDaBan << endl;
	fileout << F.TrangThai << endl;
	SaveTicketListOfOneFlight(F);
}

void WriteFlightToFile(FlightList &FL)
{
	ofstream fileout;
	fileout.open("DSCB.TXT",ios_base::out);

	
	if( fileout.is_open() )
	{
		fileout << FL.SoLuongChuyenBay << endl;
		for( FlightNode *search = FL.pHead ; search != NULL ; search = search->pNext)
		{
			SaveFlight(search->data,fileout);
		}
	}
	else
	{
		gotoxy(X_Notification,Y_Notification+1);
		cout << " Ket noi file de ghi vao that bai";
	}
	fileout.close();
}
extern string ContentPassenger[6];
void ReadPassengerFromFile(AVLTree &root)
{
	ifstream filein;
	filein.open("DSHK.TXT" ,ios_base::in);

	string temp;
	
	char lot[50];

	//DisplayForWatchOnly(ContentPassenger,sizeof(ContentPassenger)/sizeof(string) );

	if( filein.is_open() )
	{
		
		filein >> nPassenger;
		for( int i = 0 ; i < nPassenger ;i++)
		{
			Passenger P;
			getline(filein,temp);
		
			filein >> P.CMND;

			filein >> P.Ho;
			filein >> lot;

			strcat(P.Ho, " ");
			strcat(P.Ho, lot);

			filein >> P.Ten;

			if (strcmpi(P.Ten,"1") == 0 || strcmpi(P.Ten, "0") == 0) {
				P.GioiTinh = strcmpi(P.Ten, "1") == 0 ? 1 : 0;
				strcpy(P.Ten, lot);
			}
			else {
				filein >> P.GioiTinh;
			}
			
			filein >> P.Booked;
			
			//cout << P.Ten << "- " << P.GioiTinh << " - "<< P.CMND<<endl;
			//system("pause");
			
			root = AddPassenger(root, P);
			

			//OnlySeePassengerListPerPage(P,0);
			
		}
	}
	
	filein.close();
}

/*save 1 hanh khach*/
void SaveOnePassenger( AVLTree &root,ofstream &fileout)
{
	fileout << root->data.CMND << endl;
	fileout << root->data.Ho << endl;
	fileout << root->data.Ten << endl;
	fileout << root->data.GioiTinh << endl;
	fileout << "0" << endl;//book ve hay chua
}

void SavePassengerList( AVLTree &root,ofstream &fileout)
{
	if( root != NULL)
	{
		SaveOnePassenger(root,fileout);
		SavePassengerList(root->pLeft,fileout);
		SavePassengerList(root->pRight,fileout);
	}
}

void SavePassengerToFile(AVLTree &root)
{
	ofstream fileout;
	fileout.open("DSHK.TXT", ios_base::out);

	if( fileout.is_open() )
	{
		fileout << nPassenger << endl;
		SavePassengerList(root,fileout);
	}
	fileout.close();
}