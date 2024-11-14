#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include "Date.h"
#include <direct.h>   // Th? vi?n cho Windows ?? t?o th? m?c
#include <sys/stat.h>
using namespace std;



struct Employee {
	string Name;
	string MaNhanVien;
	string PhongBan;
	Date Birth;
	string ChucVu;
	string SoDienThoai;

	Employee& operator=(Employee& b) {

		Name = b.Name;
		MaNhanVien = b.MaNhanVien;
		PhongBan = b.PhongBan;
		Birth = b.Birth;
		ChucVu = b.ChucVu;
		SoDienThoai = b.SoDienThoai;
		return *this;
	}

};

void InitEmployee(Employee& a) {
	a.MaNhanVien = a.ChucVu = a.Name = a.PhongBan = a.SoDienThoai = " ";
	InitDate(a.Birth);
}

void CinE(Employee& a) {
	cout << "Nhap ho va ten: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Lo?i b? ph?n còn l?i c?a dòng tr??c ?ó (n?u có)
	getline(cin, a.Name);
	cout << '\n';

	cout << "Nhap ngay sinh (dd mm yyyy): ";
	int d, m, y;
	cin >> d >> m >> y;
	SetDate(a.Birth, d, m, y);
	cout << '\n';

	cout << "Nhap chuc vu: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Lo?i b? ký t? xu?ng dòng tr??c khi g?i getline
	getline(cin, a.ChucVu);
	cout << '\n';

	cout << "Nhap ma nhan vien: ";
	getline(cin, a.MaNhanVien);
	cout << '\n';

	cout << "Nhap so dien thoai: ";
	getline(cin, a.SoDienThoai);
	cout << '\n';

	cout << "Nhap phong ban: ";
	getline(cin, a.PhongBan);
	cout << '\n';
}


/*string SearchingDepartment(Employee& a) {
	string s;
	char c = a.MaNhanVien[0];
	switch (c)
	{
	case 'K': return  s = "Kinh Doanh";
	case 'N': return s = "Nhan Su";
	case'H': return s = "Hanh Chinh";
	}
	return " ";
}
*/

/*void CinInfEmployee(Employee& a) {
	//string outline = SearchingDepartment(a);
	CinE(a);
	string outline = a.PhongBan;
	int day = a.Birth.Day;
	int month = a.Birth.Month;
	int year = a.Birth.Year;
	string name = a.Name;


	ofstream file;
	file.open("C:\\Users\\ADMIN\\Downloads\\Data_Base_Of_Employee\\" + outline + "\\" + name + ".txt", ios::app);
	if (file.is_open()) {
		file << a.Name << endl
			<< a.ChucVu << endl
			<< day << '/' << month << '/' << year << endl
			<< a.MaNhanVien << endl
			<< a.PhongBan << endl
			<< a.SoDienThoai << endl;
		file.close();
	}
	else {
		cout << "Khong tim thay phong ban nay !" << endl;
	}

}*/
// Hàm ki?m tra xem th? m?c có t?n t?i hay không
bool directoryExists(const std::string& dirPath) {
	struct stat info;
	if (stat(dirPath.c_str(), &info) != 0) {
		return false; // Không th? truy c?p th? m?c
	}
	return (info.st_mode & S_IFDIR) != 0; // Ki?m tra n?u là th? m?c
}

// Hàm ghi thông tin nhân viên vào file
void CinInfEmployee(Employee& a) {
	CinE(a);
	std::string outline = a.PhongBan;
	std::string name = a.Name;
	std::string folderPath = "C:\\Users\\ADMIN\\Downloads\\Data_Base_Of_Employee\\" + outline;

	// T?o th? m?c n?u ch?a t?n t?i
	if (!directoryExists(folderPath)) {
		_mkdir(folderPath.c_str());
	}

	std::ofstream file(folderPath + "\\" + name + ".txt", std::ios::app);
	if (file.is_open()) {
		file << a.Name << std::endl
			<< a.ChucVu << std::endl
			<< a.Birth.Day << '/' << a.Birth.Month << '/' << a.Birth.Year << std::endl
			<< a.MaNhanVien << std::endl
			<< a.PhongBan << std::endl
			<< a.SoDienThoai << std::endl;
		file.close();
	}
	else {
		std::cout << "Khong tim thay phong ban nay!" << std::endl;
	}
}
void CoutE(Employee& a) {
	cout << "Ho va Ten: " << a.Name << endl
		<< "Chuc Vu: " << a.ChucVu << endl
		<< "Ma Nhan Vien; " << a.MaNhanVien << endl
		<< "Phong: " << a.PhongBan << endl
		<< "Ngay Sinh: "; CoutDate(a.Birth); cout << endl;
	cout << "So Dien Thoai: " << a.SoDienThoai << endl;
}

bool operator==(const Employee& a, const Employee& b) {
	if (a.Birth == b.Birth && a.ChucVu == b.ChucVu && a.MaNhanVien == b.MaNhanVien && a.Name == b.Name && a.PhongBan == b.PhongBan && a.SoDienThoai == b.SoDienThoai) return true;
	return false;
}
