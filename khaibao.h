#include<string.h>

const int MACDINH=0;
const int MD_TTCB=1;
const int MAX_MB=300;
const int MAX_VE=200;

int top1[10],left1[10],right1[10],bottom1[10],top2[10],left2[10],right2[10],bottom2[10],
t_scb[10],l_scb[10],r_scb[10],b_scb[10],t_hcb[10],l_hcb[10],r_hcb[10],b_hcb[10],
t_dv[10],l_dv[10],r_dv[10],b_dv[10],t_dsv[10],l_dsv[10],r_dsv[10],b_dsv[10],
t_ghe[200],l_ghe[200],r_ghe[200],b_ghe[200],tt_ghe[200];
//tt_ghe: 0 la chua dat, 1 la da dat, 2 la da huy

struct maybay{
	char sohieumb[16];
	char loaimaybay[41];
	int socho;
	int sl_bay=MACDINH;
	bool tt=false;
};
typedef struct maybay MB;

struct danhsachmaybay{
	MB *data[MAX_MB];
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
	char Ten[30];
	bool Phai; //true:nam-false:nu
};
typedef struct khach_hang KH;

struct nodeKH{
	KH data;
	int n = MACDINH;
	struct nodeKH *left = NULL;
	struct nodeKH *right = NULL;
};
typedef nodeKH *TREE;

struct ve{
	char CMND[10];
	int ghe_so;
	bool tt=true;// true la co nguoi dat, false la ve bi huy
};
typedef struct ve VE;

struct chuyen_bay{
	char machuyenbay[16];
	TIME time_xp;
	char noiden[16];
	int trang_thai= MD_TTCB;
	char sh_mb[16];
};
typedef struct chuyen_bay CB;

struct nodeCB{
	CB data;
	int slve;
	int sldat;
	VE *dsve[MAX_VE];
	struct nodeCB* next = NULL;
};
typedef struct nodeCB* PTR;

const int f_lon = 1; //ma TRIPLEX_FONT settextstyle() trong box chinh kc là 2
const int f_vua = 10; //ma BOLD_FONT settextstyle() trong box chuc nang kc là 1
const int f_ds = 3;// kc là 1

const int ID = 1;
const int So = 2;
const int Ten = 3;
const int CMVE = 4;
const int CMND = 5;
const int Ho = 6;

const int so_box = 3;
const int so_box1 = 3;
const int so_dsmb = 4;
const int so_cn = 5;



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
