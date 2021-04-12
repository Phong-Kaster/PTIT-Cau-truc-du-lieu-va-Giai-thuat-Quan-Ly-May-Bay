#pragma once
#include"UserInterfaceTP.h"
#include"ConstraintTP.h"
#include"ProcessionTP.h"

/*Thong tin 1 hanh khach*/
struct passenger
{
	unsigned int CMND;// day la key chinh
	char Ho[20];
	char Ten[10];
	int GioiTinh;// 1 la nam , 0 la nu
	bool Booked;// kiem tra xem da mua ve chua
};
typedef struct passenger Passenger;

struct passengernode
{
	Passenger data;
	struct passengernode *pLeft;
	struct passengernode *pRight;
	int height;// chieu cao cua node
};
typedef struct passengernode PassengerNode;
typedef PassengerNode* AVLTree;

void CreateAVLTree(AVLTree &root);
int maxi(int a,int b);
int height(AVLTree root);
AVLTree CreateTree(Passenger data);
AVLTree RightRotate(AVLTree root);
AVLTree LeftRotate(AVLTree root);
int getBalanceFactor(AVLTree root);
AVLTree AddPassenger(AVLTree& root, Passenger data);
AVLTree minValuePassenger(AVLTree root);
AVLTree RemovePassenger(AVLTree& root, Passenger data);
bool FindPassengerFollowID(AVLTree root,unsigned int CMNDcantim);
PassengerNode* FindPassenger(AVLTree root,unsigned int CMNDcantim);
void ShowPassenger(Passenger P,int position);
void ShowListPassengerPerPage(AVLTree root,int BeginIndex);
void ChangePassengerMenuManagePerPage(AVLTree root);
void InputPassenger( AVLTree &root,bool EditedOrNot,bool DeleteOrNot, int IDPassenger);
void SeePassengerList(AVLTree root);
void CancelFlightTicket(AVLTree root);
void BookTicket(AVLTree &root);
void WatchUnbookedTicket();
void WatchHowManyTimeFlightTookOff();
void WatchFlightsWithDateTimeAndDestination();
void ShowSpecificFlight(Flight F,int position);