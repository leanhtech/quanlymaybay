#include<string.h>

struct maybay{
	char sohieumb[16];
	char loaimaybay[41];
	int socho;
};

struct dsve{
	int so_ve;
	string cmnd;
	string ten;
	string ho;
	bool nu; //dung la nu, sai la nam
};

struct chuyenbay{
	char macb[16];
	long day, month, year;
	string sanbayden;
	long trangthai[4]={0,1,2,3};
	char sohieumb[16];
	int socho;
	dsve *ve = new dsve[socho+1];
};

struct nodeCB{
	chuyenbay cb;
	struct nodeCB* next;
};
typedef nodeCB* PTR;

void newmb{
	PTR First = NULL;
	maybay *MayBay = new maybay[301];
}
