#include<iostream>
#include<string>
using namespace std;

struct maybay{
	string sohieumaybay;
	string loaimaybay;
	long socho;
};

struct dsve{
	long so_ve;
	string cmnd;
	string ten;
	string ho;
	bool nu; //dung la nu, sai la nam
};

struct chuyenbay{
	maybay MB;
	string macb;
	long ngaykh;
	long thangkh;
	long namkh;
	string sanbayden;
	int trangthai[4]={0,1,2,3};
	string sohieumb;
	dsve *ve = new dsve[MB.socho+1];
};

struct nodeCB{
	chuyenbay cb;
	struct nodeCB* next;
};
typedef nodeCB* PTR;

int main{
	PTR First = NULL;
	maybay *MayBay = new maybay[301];
}

