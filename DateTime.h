#pragma once
#include <ctime>
// #include"ValidateTP.h"// dung de kiem tra cac ki tu nhap vao

struct datetime
{
	int y ; 
	int m ; 
	int d ; 
	int h ;
	int mi;
};
typedef struct datetime DateTime;
void InitDataTime(DateTime &DT);
bool DateTimeIsRightFormat(DateTime dt);
bool DateTimeIsValid(DateTime dt);
void OutputDateTime(DateTime &dt);
bool CompareDate(DateTime dt1, DateTime dt2);