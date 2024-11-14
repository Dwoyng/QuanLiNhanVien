#pragma once
#include<iostream>
using namespace std;

struct Date {
	int Day;
	int Month;
	int Year;
	Date& operator=(const Date& another) {
		Day = another.Day;
		Month = another.Month;
		Year = another.Year;
		return *this;
	}
};

void InitDate(Date& a) {
	a.Day = a.Month = a.Year = 0;
}

int Limit(int v, int max, int min) {
	if (v < min) return min;
	return v < max ? v : max;
}

int DayOfMonth(int m, Date& a) {

	switch (m)
	{
	case 2: return a.Year & 3 ? 28 : 29;
	case 4: case 9: case 11: case 6: return 30;
	default:
		return 31;
	}
}


void SetDate(Date& a, int d, int m, int y) {
	a.Day = Limit(d, 1, DayOfMonth(m, a));
	a.Month = Limit(m, 1, 12);
	a.Year = y;
}

void CoutDate(Date& a) {
	cout << a.Day << '/' << a.Month << '/' << a.Year << endl;
}

bool operator==(const Date& a, const Date& b) {
	return (a.Day == b.Day && a.Month == b.Month && a.Year == b.Year);
}