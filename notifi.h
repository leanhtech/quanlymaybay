#include<string.h>
#include<iostream>

typedef long long ll;

string notifi_mb(ll luachon){
	switch(luacchon){
		case 1: return "So hieu may bay da bi trung.";
		case 2: return "So cho tren may bay phai lon hoc hoac bang 20.";
		case 3: return "So luong may bay phai tu 0 den 300.";
	}
}

string notifi_cb(ll luachon){
	switch(luachon){
		case 1: return "Ma chuyen bay da bi trung.";
		case 2: return "Khong the dat chuyen bay ve qua khu.";
		case 3: return "Phai dat chuyen bay som hon 1 ngay.";
		case 4: return "Khong the dat chuyen bay som hon 1 thang.";
		case 5: return "Khong the huy chuyen bay.";
		case 6: return "Da huy chuyen bay thanh cong.";
		case 7: return "Chuyen bay van con ve.";
		case 8: return "Da dang ky ve thanh cong.";
		case 9: return "Chuyen bay da het ve.";
		case 10: return "Chuyen bay da hoan tat.";
	}
}

string notifi_kh(ll luachon){
	switch(luachon){
		case 1: return "Mot khach hang khong the dat hai ve may bay cung luc.";
}

