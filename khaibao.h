#include<string.h>

int top1[10],left1[10],right1[10],bottom1[10],top2[10],left2[10],right2[10],bottom2[10],
t_scb[10],l_scb[10],r_scb[10],b_scb[10],t_hcb[10],l_hcb[10],r_hcb[10],b_hcb[10],
t_dcb[10],l_dcb[10],r_dcb[10],b_dcb[10],t_dsv[10],l_dsv[10],r_dsv[10],b_dsv[10];


struct maybay{
	char sohieumb[16];
	char loaimaybay[41];
	int socho;
};
typedef struct maybay MB;

struct danhsachmaybay{
	MB *data[301];
	int sl_mb;
};
typedef struct danhsachmaybay DSMB;

struct thoi_gian{
	int phut;
	int gio;
	int ngay;
	int thang;
	int nam;
};
typedef struct thoi_gian TIME;

struct khach_hang{
	char CMND[10];
	char Ho[10];
	char Ten[20];
	bool Phai; //true:nam-false:nu
};
typedef struct khach_hang KH;

struct ve{
	char CMND[10];
	int ve;
};
typedef struct ve VE;

struct chuyen_bay{
	char machuyenbay[16];
	TIME time_xp;
	char tg[30];
	char noiden[16];
	int trang_thai=1;
	char sh_mb[16];
	//int slve;
	int stt;
	//VE *dsve[100];
};
typedef struct chuyen_bay CB;

struct nodeCB{
	CB data;
	VE *dsve[100];
	struct nodeCB* next = NULL;
};
typedef struct nodeCB* PTR;

const int f_lon = 1; //ma TRIPLEX_FONT settextstyle() trong box chinh kc là 2
const int f_vua = 10; //ma BOLD_FONT settextstyle() trong box chuc nang kc là 1
const int f_ds = 3;// kc là 1

const int ID = 1;
const int So = 2;
const int HoTen =3;

const int so_box = 3;
const int so_box1 = 3;
const int so_dsmb = 4;
const int so_cn = 5;
const int max_day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};


char ten[20] =   "QUAN LY SAN BAY";

char file_mb[20]= "datadsmaybay.txt";

char box[so_box][20] = {	"QUAN LY MAY BAY",
							"QUAN LY CHUYEN BAY",
							"  QUAN LY KHACH"	};

char box1[so_box1][20]=	{	"Danh sach May bay",
							"Them May bay",
							"Chinh Sua May Bay"		};
					
char ds_mb[so_dsmb][20]={	"ID May Bay",
							"Loai May Bay",
							"So Cho Tren May Bay",
							"Chuc Nang"				};
							
char cn[so_cn][20]=		{	"Chinh Sua",
							"     Xoa",		
							" Luu",
							" Huy",	
							" Co"				};

char ds_cb[6][20]=		{	"IDCB",
							"Thoi Gian Xuat Phat",
							"Noi Den",
							"Trang Thai",
							"IDMB",
							"Chuc Nang"					};
