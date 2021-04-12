#pragma once
#include"GlobalVariableTP.h"// bien toan cuc
#include"UserInterfaceTP.h"// thu vien toan cuc
#include"AirplaneTP.h"

// cau truc may bay
struct airplane
{
	char SoHieuMB[15];
	char LoaiMB[40];
	int SoChoMB;// so cho >= 20
	int SoLanThucHienChuyenBay;
};
typedef struct airplane Airplane;
/*Mang con tro chua toi da 300 may bay cac loai*/
struct listairplane
{
	int SoLuong;
	Airplane *DSMB[MaxAirplane];
};
typedef struct listairplane ListAirplane;


/*Cac ham xuat hien trong AirplaneTP.cpp*/
void InitListAirplane(ListAirplane &LA);
int FindIndexAirplane(ListAirplane LA,const char *Ma);
void NormalBGAirplan();
bool AirplaneDataIsEmpty(Airplane *A);
bool RemoveAirplaneIsSucceed(ListAirplane &LA,char SoHieuMBCanXoa[]);
void ShowAirplane(Airplane *A,int position);
void ShowListAirplaneOnePage(ListAirplane LA,int StartIndex);
void ChangeAirplaneMenuManagerPage(ListAirplane LA);
void InputAirplane(ListAirplane &LA, bool EditedOrNot );
void MenuManageAirplane(ListAirplane &LA);