/*Noi nay quy dinh nhung rang buoc cua phan nhap lieu noi dung chu viet*/
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


void ConstraintForLetterAndNumber(string &result,bool &MoveOrNot,int &ordinal,bool &SaveOrNot,int distance);
void ConstraintForOnlyLetter(string &result,bool &MoveOrNot,int &ordinal,bool &SaveOrNot,int distance);
void ConstraintForOnlyNumber(int &result,bool &MoveOrNot,int &ordinal,bool &SaveOrNot,int distance,int LimitNumber);
void ConstraintForDateAndTime( int &result,int &DTordinal,bool &SaveOrCancel,int space , int LimitReach);
void ConstraintsForLetterAndSpace(string &result,bool &MoveOrNot,int &ordinal,bool &SaveOrNot,int distance);
void ConstraintForOnlyGender(int &result,bool &MoveOrNot,int &ordinal,bool &SaveOrNot,int distance);
void StandardName(char *a);