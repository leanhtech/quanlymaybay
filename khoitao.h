#include<string.h>

struct maybay{
	char sohieumb[16];
	char loaimaybay[41];
	int socho;
};
typedef struct maybay MB;

struct dsve{
	int so_ve;
	string cmnd;
	string ten;
	string ho;
	bool nu; //dung la nu, sai la nam
};
typedef struct dsve DSV;

struct chuyenbay{
	char macb[16];
	long minmute,hour,day, month, year;
	string sanbayden;
	long trangthai[4]={0,1,2,3};
	char sohieumb[16];
	int socho;
	dsve *ve = new dsve[socho+1];
};
typedef struct chuyenbay CB;

struct nodeCB{
	CB info;
	struct nodeCB* next;
};
typedef struct nodeCB* PTR;

void newmb{
	PTR First = NULL;
	CB *MayBay = new CB[301];
}
