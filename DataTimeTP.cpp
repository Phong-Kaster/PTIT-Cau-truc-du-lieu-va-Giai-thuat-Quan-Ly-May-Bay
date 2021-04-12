#pragma once
#include <ctime>// dung cho ngay gio
#include"UserInterfaceTP.h"
#include"DateTime.h"

int nDayOfMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

void InitDataTime(DateTime &DT)
{
	time_t baygio = time(0);/*lay ngay gio he thong hien tai*/
	tm* ltm = localtime(&baygio);/*con tro de the hien ngay gio hien tai*/


	DT.h = ltm->tm_hour;//Hour
	DT.mi = ltm->tm_min;//Minute
	DT.d = ltm->tm_mday;//Day
	DT.m = 1 + ltm->tm_mon;//Month
	DT.y = 1900 + ltm->tm_year;//Year
}

// kiem tra so ngay va nam nhuan hay khong, return true nghia la dung
bool DateTimeIsRightFormat(DateTime dt)
{
	nDayOfMonth[2] = 28;
	if ((dt.y % 400 == 0) || (dt.y % 4 == 0 && dt.y % 100 != 0))//kiem tra nam nhuan
		nDayOfMonth[2] = 29;
	if (dt.d > nDayOfMonth[dt.m])// kiem tra xem so ngay nhap co lon hon so ngay mac dinh khong
		return false;
	return true;
}

//kiem tra dinh dang gio phu ngay thang nam, return true => nhap dung
bool DateTimeIsValid(DateTime dt)
{
	if (!DateTimeIsRightFormat(dt)) return false;

	nDayOfMonth[2] = 28;
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	DateTime dtNow;
	dtNow.y = 1900 + ltm->tm_year;
	dtNow.m = 1 + ltm->tm_mon;
	dtNow.d = ltm->tm_mday;
	dtNow.h = ltm->tm_hour;
	dtNow.mi = ltm->tm_min;

	// tra ve false neu nhu 
	if (dt.y < dtNow.y) return false;// nam nhap vao nho hon nam hien tai
	if ((dt.y == dtNow.y) && (dt.m < dtNow.m))  return false;// thang nhap vao nho hon thang hien tai
	if ((dt.y % 400 == 0) || (dt.y % 4 == 0 && dt.y % 100 != 0))
		nDayOfMonth[2] = 29;
	if (dt.y == dtNow.y && dt.m == dtNow.m && dt.d < dtNow.d)return false;// ngay nhap vao nho hon ngay hien tai
	if (dt.y == dtNow.y && dt.m == dtNow.m && dt.d == dtNow.d && dt.h < dtNow.h)return false;// gio nhap bi sai
	// so phut nhap vao bi sai
	if (dt.y == dtNow.y && dt.m == dtNow.m && dt.d == dtNow.d && dt.h == dtNow.h && dt.mi <= dtNow.mi)return false;
	return true;
}

void OutputDateTime(DateTime &dt)
{
	cout << dt.h << ":" << dt.mi << " " << dt.d << "/" << dt.m << "/" << dt.y;
}

bool CompareDate(DateTime dt1, DateTime dt2)
{
	return dt1.d == dt2.d && dt2.m == dt1.m && dt1.y == dt2.y;
}