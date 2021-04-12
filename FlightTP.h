#pragma once
#include"AirplaneTP.h"
#include"GlobalVariableTP.h"
#include"TicketTP.h"
#include"DateTime.h"


/*=====Thong tin 1 chuyen bay=====*/
struct flight
{
	char MaChuyenBay[10];
	char SanBayDen[20];
	DateTime ThoiGianDi;
	char SoHieuMB[15];
	int TrangThai;// 0: hủy chuyến, 1: còn vé, 2: hết vé,3: hoàn tat
	// ve may bay
	int TongSoVe;
	int TongSoDaBan;
	Ticket *TicketList;
};
typedef struct flight Flight;
/*=== Danh Sach Chuyen Bay - Mang Con Tro ===*/
struct flightnode
{
	Flight data;
	struct flightnode *pNext;
};
typedef struct flightnode FlightNode;

struct flightlist
{
	FlightNode *pHead;
	FlightNode *pTail;
	int SoLuongChuyenBay;
};
typedef struct flightlist FlightList;

void InitFlight(Flight &F);
void InitFlightList(FlightList &FL);
FlightNode *CreateFlightNode(Flight Data);
void AddBeginningList(FlightList &FL,Flight Data);
void AddEndingList(FlightList &FL,Flight Data);
int FindIndexFlight( FlightList FL,const char *MaChuyenBayCanTim);
int FindDestination( FlightList FL,const char* SanBayDenCanTim);
FlightNode *FindFlight ( FlightList FL,const char *MaChuyenBayCanTim);
FlightNode *FindByOrdinal( FlightList FL,int ordinal);
void InputDateAndTimeInfor(DateTime &DT, int ordinal);
bool RemoveHead(FlightList &FL);
bool RemoveEnding(FlightList &FL);
bool RemoveAfterAnother(FlightList &FL,FlightNode *TempoFlight);
bool RemoveFlightFollowID(FlightList &FL,const char *MaChuyenBayCanXoa);
bool CleanUpFlightList(FlightList &FL);
void AutoUpdateFlightStatus(FlightList &FL);
void TicketChairBoard(Flight F);
void EffectTicketMenu(int index,int PreColor);
int ChooseTicket ( Flight &F);
void ShowFlight(Flight F,int position);
void ShowFlightList(FlightList FL);
void ShowFlightListPerPage(FlightList FL, int StartIndex);
void ChangePageManageFlightList(FlightList FL);
bool FlighDataIsEmpty(Flight F);
void InputFlight( FlightList &FL,bool EditedOrNot = false,bool DeleteOrNot = false);
void MenuManageFlightLisht( FlightList &FL);
int CheckOut(Flight F, int x);