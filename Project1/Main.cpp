#include<iostream>
#include<string.h>
#include "Doubledlinked.h"
#include "Date.h"
#include "Employee.h"
//#include<filesystem>

Employee a{ "Thai Tuan Duong", "H20223927", "Hanh Chinh", Date{18,8,2004}, "Nhan vien", "0915963236" };
Employee b{ "Nguyen Minh Quan", "K20224109", "Kinh Doanh", Date{17,10,2004}, "Truong Phong", "091231233" };
Employee c{ "Truong Thanh Phong", "N20222134", "Nhan Su", Date{9,5,2004}, "Pho Truong Phong", "0356234678" };
Employee d{ "Dinh Tuan Anh", "H20223844", "Hanh Chinh", Date{19,8,2004}, "Nhan vien", "0231321323" };
Employee e{ "Ho Quoc Khanh", "K20227621", "Kinh Doanh", Date{11,12,2004}, "Nhan vien", "0432456487" };
Employee f{ "Dang Duc Thinh", "H20227293", "Nhan Su", Date{30,4,2004}, "Truong Phong", "0231233123" };
DoubleLinkedList DL;

void ThemNhanVien(DoubleLinkedList& H) {
	Employee* employee = new Employee;
	InitEmployee(*employee);
	CinInfEmployee(*employee);
	InsertBegin(DL, *employee);
}

void Menu(DoubleLinkedList& H) {
	while (1) {
		cout << "1. Them nhan vien" << endl;
		cout << "2. Lay thong tin nhan vien bang ma nhan vien" << endl;
		cout << "3. Xoa nhan vien" << endl;
		cout << "4. Hien thi toan bo danh sach nhan vien" << endl;

		int m;
		cout << "Nhap lua chon: ";  cin >> m;
		switch (m)
		{

		case 1: {
			ThemNhanVien(H);
			break;
		}

		case 2: {
			string s;
			cout << "Nhap ma nhan vien: "; cin >> s;
			Node* P = DL.Head;
			while (P != NULL)
			{
				if (P->employee.MaNhanVien == s) {
					CoutE(P->employee);
					break;
				}
					P = P->nextR;
			}
			if (P == NULL) {
				cout << "Khong tim thay nhan vien nay !" << endl;
			}
			cout << endl;
			break;
		}

		case 3: {
			string s;
			cout << "Vui long nhap ma nhan vien muon xoa: " << endl; cin >> s;
			Node* P = DL.Head;
			while (P->nextR != NULL) {
				if (P->employee.MaNhanVien == s) {
					DeleteSelected(H, P);
					cout << "Xoa thanh cong!" << endl;
					break;
				}
				P = P->nextR;
			}
			if (P->employee.MaNhanVien == s) {
				DeleteSelected(H, P);
				cout << "Xoa thanh cong!" << endl;
				break;
			}
			else {
				cout << "Khong tim thay nhan vien nay!" << endl;
				break;
			}
		}

		case 4: {
			string s;
			cout << "Hay nhap thong tin phong ban muon truy cap :";
			cin.ignore();
			getline(cin, s);
			cout << endl;
			Node* P = DL.Head;
			while (P) {
				if (P == NULL) {
					cout << "Phong nay khong co nhan vien nao!" << endl;
					break;
				}
				if(P->employee.PhongBan == s) CoutE(P->employee);
				P = P->nextR;
			}
			break;
		}

		default:
			cout << "Vui long nhap lai yeu cau!" << endl;
			break;
		}

	}
}

int main() {
	InitDoubleLinkedList(DL);
	InsertBegin(DL, a); 
	InsertBegin(DL, b);
	InsertBegin(DL, c); 
	InsertBegin(DL, d); 
	InsertBegin(DL, e); 
	InsertBegin(DL, f); 
	Menu(DL);

}