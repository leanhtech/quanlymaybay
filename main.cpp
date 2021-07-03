#include<graphics.h>
#include"khaibao.h"
#include<iostream>
#include<cmath>
#include<ctime>
#include <conio.h>
using namespace std;
//bool nhap_pt = false;
void normal_box(int, int, int, int, char*, int, int, int);
void hightline_box(int, int, int, int, char*, int, int, int);
void in_main_menu();
void xoa_cn();
void reset_all();
void normal_text();
void reset_them(char*, char*);
void in_ds_mb(DSMB &, char [][20]);
void form_mb(char *);
int LoadFileMB(char*, DSMB&);
void charValue(int , char *);
bool ktrVT(int,int,int,int,int,int);
bool ktrKyTu(char &, bool, bool, bool);
int intValue(char  *);
void nhap(int, int, int, int, int, int, int, char *, int &, int &, int &);	
bool ktSua(int &, int , int, int);
bool ktXoa(int &, int , int, int);
void from_xoa(char *);
int SaveFile_MB (char *, DSMB &);
void reset_temp(char *, char *, char *);
void xl_trang(int, int &, int &);
bool ktrMB(DSMB &,char *,bool,int);
bool xau_trung(char *,char *);


int ktrtime(TIME dat){
	//1:khong ton tai ngay
	//2:thoi gian qua khu
	//3:vuot qua 2 thang so voi luc dat ve
	//0:dung
	
	if(dat.thang==2){//nam nhuan la nam chia het cho 400 hoac chia het cho 4 va ko chia het cho 100
		if(dat.nam%400==0 ||(dat.nam%4==0 && dat.nam%100!=0)){
			if(dat.ngay>29) return 1;
		}
	}else{
		if(dat.ngay>max_day[dat.thang]) return 1;//kiem tra trong du lieu mang max_day
	}
	
	//tao 1 TIME có du lieu là thoi gian hien tai
	time_t now = time(0);
	tm *ltm = localtime(&now);
	TIME baygio;
	baygio.ngay=ltm->tm_mday;
	baygio.thang=1+ltm->tm_mon;
	baygio.nam=1900+ltm->tm_year;
	baygio.gio=ltm->tm_hour;
	baygio.phut=ltm->tm_min;
	
	//kt qua khu
	if(dat.nam<baygio.nam) return 2;
	else if(dat.thang<baygio.thang) return 2;
	else if(dat.ngay<baygio.ngay) return 2;
	else if(dat.gio<baygio.gio) return 2;
	else if(dat.phut<baygio.phut) return 2;
	
	//kt khoang cach 2 thang
	int kq;
	kq = ((dat.nam-baygio.nam)*365) + ((dat.thang-baygio.thang)*30) + (dat.ngay-baygio.ngay);
	if (kq>60) return 3;
	
	return 0;
}

void charTTMB(int ma, char *s){
	s[0]='\0';
	switch(ma){
		case 0:{
			char t[10]="HUY";
			strcpy(s,t);
		}
		break;
		case 1:{
			char t[10]="CON VE";
			strcpy(s,t);
		}
		break;
		case 2:{
			char t[10]="HET VE";
			strcpy(s,t);
		}
		break;
		case 3:{
			char t[10]="HOAN TAT";
			strcpy(s,t);
		}
		break;
	}
}

void charTime(TIME t, char *s){
	s[0]='\0';
	char temp[10];
	char ngan[2]="/";//ngan cac ngay
	char hc[2]=":";//hai cham
	char kc[2]=" ";//khoang cach gioi ngay
	charValue(t.gio,temp);
	strcat(s,temp);
	strcat(s,hc);
	charValue(t.phut,temp);
	strcat(s,temp);
	strcat(s,kc);
	charValue(t.ngay,temp);
	strcat(s,temp);
	strcat(s,ngan);
	charValue(t.thang,temp);
	strcat(s,temp);
	strcat(s,ngan);
	charValue(t.nam,temp);
	strcat(s,temp);
}

void in_ds_cb(PTR First){
	int sl = 6;
	xoa_cn();
	normal_text();
	settextstyle(1,0,2);
	outtextxy(20,120,"Danh Sach Chuyen Bay");
	normal_box(1050,120,1230,155,"Them Chuyen Bay",f_vua,1,8);
	
	setfillstyle(1,12);
	bar3d(0,170,1270,210,0,0);
	setbkcolor(12);
	settextstyle(f_ds,0,1);
	
	outtextxy(8,178,ds_cb[0]);
	outtextxy(160,178,ds_cb[1]);
	outtextxy(400,178,ds_cb[2]);
	outtextxy(570,178,ds_cb[3]);
	outtextxy(730,178,ds_cb[4]);
	outtextxy(880,178,ds_cb[5]);
	
	int dau = 212;int cuoi = dau+50;
	setfillstyle(1,15);
	setbkcolor(15);
	settextstyle(f_ds,0,1);
	
	PTR p;
	//int chi so=9;
	char temp[15];
	int i;
	for(p=First,i = 0; (p!=NULL) ;p=p->next,i++){
		int j = 8;
		bar3d(0,dau,1270,cuoi,0,0);
		outtextxy(8,dau+8,p->data.machuyenbay);
		charTime(p->data.time_xp,temp);
		outtextxy(160,dau+8,temp);
		outtextxy(400,dau+8,p->data.noiden);
		charTTMB(p->data.trang_thai,temp);
		outtextxy(570,dau+8,temp);
		outtextxy(730,dau+8,p->data.sh_mb);
		
		normal_box(880,dau+12,930,cuoi-8,"Sua",f_ds,1,4);
		t_scb[i]=880;l_scb[i]=dau+12;r_scb[i]=930;b_scb[i]=cuoi-8;
		normal_box(950,dau+12,1000,cuoi-8,"Huy",f_ds,1,4);
		t_hcb[i]=950;l_hcb[i]=dau+12;r_hcb[i]=1000;b_hcb[i]=cuoi-8;
		normal_box(1020,dau+12,1090,cuoi-8,"Dat Ve",f_ds,1,4);
		t_dcb[i]=1020;l_dcb[i]=dau+12;r_dcb[i]=1090;b_dcb[i]=cuoi-8;
		normal_box(1110,dau+12,1250,cuoi-8,"Danh sach Ve",f_ds,1,4);
		t_dsv[i]=1110;l_dsv[i]=dau+12;r_dsv[i]=1250;b_dsv[i]=cuoi-8;
		
		dau += 50;cuoi+=50;
		setbkcolor(15);
		setfillstyle(1,15);
	}
}

void form_cb(){
	xoa_cn();
	normal_text();
	setfillstyle(1,7);
	bar3d(300,200,950,600,0,1);
	normal_box(850,550,920,580,cn[2],f_vua,2,3);
	normal_box(750,550,820,580,cn[3],f_vua,2,3);
	setbkcolor(7);
	settextstyle(f_lon,0,3);
	outtextxy(500,215,"Them Chuyen Bay");
	settextstyle(f_vua,0,1);
	setfillstyle(1,15);
	outtextxy(310,270,"IDCB");
	bar3d(360,270-5,580,270+25,0,1);
	outtextxy(600,270,"NOI DEN");
	bar3d(690,270-5,940,270+25,0,1);
	outtextxy(310,370,"Gio");
	bar3d(350,370-5,410,370+25,0,1);
	outtextxy(430,370,"Phut");
	bar3d(480,370-5,540,370+25,0,1);
	outtextxy(560,370,"Ngay");
	bar3d(610,370-5,670,370+25,0,1);
	outtextxy(690,370,"Thang");
	bar3d(750,370-5,810,370+25,0,1);
	outtextxy(830,370,"Nam");
	bar3d(870,370-5,948,370+25,0,1);
	outtextxy(310,470,"ID May Bay");
	bar3d(430,470-5,700,470+25,0,1);
}

//void ktrscb()

int main(){
	DSMB dsmb;
	cout<<"\n\tTinh trang Load:"<<LoadFileMB(file_mb,dsmb);
	PTR dscb = new nodeCB;
	char tempcb[30];
	strcpy(dscb->data.machuyenbay,"VNHN003");
	strcpy(dscb->data.noiden,"HANOI");
	strcpy(dscb->data.sh_mb,"VN005");
	dscb->data.time_xp.gio=8;
	dscb->data.time_xp.phut=30;
	dscb->data.time_xp.ngay=10;
	dscb->data.time_xp.thang=7;
	dscb->data.time_xp.nam=2021;
	dscb->data.trang_thai=1;
    int x,y;
    bool c_1,c_2,c_3,edit_mb,them_mb,xoa_mb,them_cb;
	c_1=c_2=c_3=edit_mb=them_mb=xoa_mb=them_cb=false;//C_... la trang thai chon
    initwindow(1280,780);
	normal_text();
    cleardevice();
    
    settextstyle(f_lon,0,4);
    outtextxy(420,1,ten);
    
    in_main_menu();
    
    int step_sh,step_loai,step_sc,step_nd,step_shcb,step_g,step_p,step_n,step_t,step_nam;
	step_sh=step_loai=step_sc=step_nd=step_shcb=step_g=step_p=step_n=step_t=step_nam=0;
	char sh_temp[16]={'\0'};
	char l_temp[41]={'\0'};
	char sc_temp[10]={'\0'};
	char nd_temp[16]={'\0'};
	char shcb_temp[16]={'\0'};
	char g_temp[5]={'\0'};
	char p_temp[5]={'\0'};
	char n_temp[5]={'\0'};
	char t_temp[5]={'\0'};
	char nam_temp[6]={'\0'};
	int chiso = 0;
	
	
	//int so_ds = 2;
	
    //cout<<getmaxx()<<" - "<<getmaxy()<<"\n\n";
    while(true) {
    	normal_text();
    	if (ismouseclick(WM_LBUTTONDOWN)){
    		getmouseclick(WM_LBUTTONDOWN,x,y);
    		cout<<"\nvi tri x:"<<x<<" - vi tri y:"<<y<<endl;
    		
			//quan ly may bay
    		if(ktrVT(10,50,350,90,x,y)&&(edit_mb==false)&&(them_mb==false)){//(x>=10)&&(x<=350)&&(y>=50)&&(y<=90)
    			if(c_1==false){
    				reset_all();
    				hightline_box(10,50,350,90,box[0],f_lon,2,4);
    				c_1 = true; c_2 = c_3 = false;
					in_ds_mb(dsmb,ds_mb);
				}
				else{
					reset_all();
					c_1 = false;
				}
			}
			//chuc nang trong ds may bay
			else if(c_1){
				//them may bay
				if(ktrVT(1050,120,1200,155,x,y)&&them_mb==false){//(x>=1050)&&(x<=1200)&&(y>=120)&&(y<=155)
					them_mb=true;
					hightline_box(1050,120,1200,155,box1[1],f_vua,1,2);
					delay(250);
					form_mb(box1[1]);
				}
				else if(them_mb){
					nhap(500,270-5,940,270+25,15,1,ID,sh_temp,step_sh,x,y);
					nhap(470,370-5,940,370+25,25,1,ID,l_temp,step_loai,x,y);
					nhap(530,470-5,700,470+25,99,20,So,sc_temp,step_sc,x,y);
					//nut huy:
					if(ktrVT(750,550,820,580,x,y)){//(x>=750)&&(x<=820)&&(y>=550)&&(y<=580)
						hightline_box(750,550,820,580,cn[3],f_vua,2,0);
		    			delay(250);
		    			xoa_cn();
						step_sh=step_loai=step_sc=0;
						reset_temp(sh_temp,l_temp,sc_temp);
		    			them_mb=false;
						in_ds_mb(dsmb,ds_mb);
					}
					//nut luu:
					else if(ktrVT(850,550,920,580,x,y)){
						if((sh_temp[0]=='\0'||l_temp[0]=='\0'||sc_temp[0]=='\0'||ktrMB(dsmb,sh_temp,true,0)==false));
						else{
							hightline_box(850,550,920,580,cn[2],f_vua,2,0);
			    			delay(250);
			    			xoa_cn();
			    			dsmb.data[dsmb.sl_mb] = new MB;
			    			strcpy(dsmb.data[dsmb.sl_mb]->sohieumb,sh_temp);
			    			strcpy(dsmb.data[dsmb.sl_mb]->loaimaybay,l_temp);
			    			int sc = intValue(sc_temp);
			    			dsmb.data[dsmb.sl_mb]->socho = sc;
							dsmb.sl_mb++;
			    			//edit_mb=false;
			    			them_mb=false;
			    			step_sh=step_loai=step_sc=0;
			    			reset_temp(sh_temp,l_temp,sc_temp);
							SaveFile_MB(file_mb,dsmb);
							in_ds_mb(dsmb,ds_mb);
						}
						
					}
				}
				//chinh sua may bay
				else if(ktSua(chiso,dsmb.sl_mb,x,y)){
					edit_mb=true;
					hightline_box(left1[chiso],top1[chiso],right1[chiso],bottom1[chiso],cn[0],f_ds,1,0);
					delay(250);
					form_mb(box1[2]);
					strcpy(sh_temp,dsmb.data[chiso]->sohieumb);
		    		strcpy(l_temp,dsmb.data[chiso]->loaimaybay);
		    		charValue(dsmb.data[chiso]->socho,sc_temp);
		    		setbkcolor(15);
		    		outtextxy(510,270,sh_temp);
		    		outtextxy(480,370,l_temp);
		    		outtextxy(540,470,sc_temp);
					//cout<<"chi so :"<<chiso<<endl;
				}
				else if(edit_mb){
					nhap(500,270-5,940,270+25,15,1,ID,sh_temp,step_sh,x,y);
					nhap(470,370-5,940,370+25,25,1,ID,l_temp,step_loai,x,y);
					nhap(530,470-5,700,470+25,99,20,So,sc_temp,step_sc,x,y);
					//nut huy
					if(ktrVT(750,550,820,580,x,y)){
						hightline_box(750,550,820,580,cn[3],f_vua,2,0);
		    			delay(250);
		    			xoa_cn();
						step_sh=step_loai=step_sc=0;
						reset_temp(sh_temp,l_temp,sc_temp);
						chiso=0;
		    			edit_mb=false;
						in_ds_mb(dsmb,ds_mb);
					}
					//nut luu
					else if(ktrVT(850,550,920,580,x,y)){
						if(ktrMB(dsmb,sh_temp,false,chiso)){
							hightline_box(850,550,920,580,cn[2],f_vua,2,0);
			    			delay(250);
			    			xoa_cn();
							strcpy(dsmb.data[chiso]->sohieumb,sh_temp);
			    			strcpy(dsmb.data[chiso]->loaimaybay,l_temp);
			    			int sc = intValue(sc_temp);
							dsmb.data[chiso]->socho = sc;
							chiso=0;
			    			//edit_mb=false;
			    			edit_mb=false;
			    			step_sh=step_loai=step_sc=0;
			    			reset_temp(sh_temp,l_temp,sc_temp);
							SaveFile_MB(file_mb,dsmb);
							in_ds_mb(dsmb,ds_mb);
						}
						
					}
				}
				//xoa may bay
				else if(ktXoa(chiso,dsmb.sl_mb,x,y)){
					xoa_mb=true;
					hightline_box(left2[chiso],top2[chiso],right2[chiso],bottom2[chiso],cn[1],f_ds,1,0);
					delay(250);
					strcpy(sh_temp,dsmb.data[chiso]->sohieumb);
					from_xoa(sh_temp);
				}
				else if(xoa_mb){
					//nut huy:
					if(ktrVT(750,550,820,580,x,y)){//(x>=750)&&(x<=820)&&(y>=550)&&(y<=580)
						hightline_box(750,550,820,580,cn[3],f_vua,2,0);
		    			delay(250);
		    			xoa_cn();
		    			reset_temp(sh_temp,l_temp,sc_temp);
						chiso=0;
		    			xoa_mb=false;
						in_ds_mb(dsmb,ds_mb);
					}
					//nut co:
					else if(ktrVT(850,550,920,580,x,y)){//(x>=850)&&(x<=920)&&(y>=550)&&(y<=580)
						hightline_box(850,550,920,580,cn[4],f_vua,2,0);
		    			delay(250);
		    			xoa_cn();
		    			for(int i = chiso; i < dsmb.sl_mb-1; i++){
		    				strcpy(dsmb.data[i]->sohieumb,dsmb.data[i+1]->sohieumb);
		    				strcpy(dsmb.data[i]->loaimaybay,dsmb.data[i+1]->loaimaybay);
		    				dsmb.data[i]->socho=dsmb.data[i+1]->socho;
		    				//cout<<"da vo :"<<i<<endl;
						}
						delete dsmb.data[--dsmb.sl_mb];
		    			chiso=0;
		    			xoa_mb=false;
		    			reset_temp(sh_temp,l_temp,sc_temp);
						SaveFile_MB(file_mb,dsmb);
						in_ds_mb(dsmb,ds_mb);
					}
				}
			}

			//quan ly chuyen bay
			else if(ktrVT(425,50,825,90,x,y)){//(edit==false)(x>=425)&&(x<=825)&&(y>=50)&&(y<=90)
    			if(c_2==false){
    				reset_all();
    				hightline_box(425,50,825,90,box[1],f_lon,2,4);
    				c_2 = true; c_1 = c_3 = false;
    				in_ds_cb(dscb);
				}
				else{
					reset_all();
					c_2 = false;
				}
			}
			else if(c_2){
				if(ktrVT(1050,120,1200,155,x,y)&&them_mb==false){//(x>=1050)&&(x<=1200)&&(y>=120)&&(y<=155)
					them_cb=true;
					hightline_box(1050,120,1230,155,"Them Chuyen Bay",f_vua,1,2);
					delay(250);
					form_cb();
				}
				else if(them_cb){
					nhap(360,270-5,580,270+25,15,1,ID,shcb_temp,step_shcb,x,y);
					nhap(690,270-5,940,270+25,15,1,ID,nd_temp,step_nd,x,y);
					nhap(430,470-5,700,470+25,15,1,ID,sh_temp,step_sh,x,y);
					
					nhap(350,370-5,410,370+25,24,1,So,g_temp,step_g,x,y);
					nhap(480,370-5,540,370+25,59,0,So,p_temp,step_p,x,y);
					nhap(610,370-5,670,370+25,31,1,So,n_temp,step_n,x,y);
					nhap(750,370-5,810,370+25,12,1,So,t_temp,step_t,x,y);
					nhap(870,370-5,948,370+25,2100,2021,So,nam_temp,step_nam,x,y);
					cout<<intValue(t_temp)<<endl;
					//nut huy:
					if(ktrVT(750,550,820,580,x,y)){//(x>=750)&&(x<=820)&&(y>=550)&&(y<=580)
						hightline_box(750,550,820,580,cn[3],f_vua,2,0);
		    			delay(250);
		    			xoa_cn();
						step_shcb=step_nd=step_sh=step_g=step_p=step_n=step_t=step_nam=0;
						reset_temp(shcb_temp,nd_temp,sh_temp);
						reset_temp(g_temp,p_temp,n_temp);
						reset_temp(n_temp,t_temp,nam_temp);
		    			them_cb=false;
						in_ds_cb(dscb);
					}
					//nut luu:
					else if(ktrVT(850,550,920,580,x,y)){
						if((sh_temp[0]=='\0'||shcb_temp[0]=='\0'||g_temp[0]=='\0'));
						else{
							hightline_box(850,550,920,580,cn[2],f_vua,2,0);
			    			delay(250);
			    			xoa_cn();
			    			PTR p= new nodeCB;
			    			strcpy(p->data.machuyenbay,shcb_temp);
			    			strcpy(p->data.noiden,nd_temp);			    			
			    			strcpy(p->data.sh_mb,sh_temp);
							cout<<"gia tri t_temp:"<<t_temp;		    			
			    			p->data.time_xp.gio=intValue(g_temp);
			    			p->data.time_xp.phut=intValue(p_temp);
			    			p->data.time_xp.ngay=intValue(n_temp);
			    			p->data.time_xp.thang=intValue(t_temp);
			    			p->data.time_xp.nam=intValue(nam_temp);
			    			p->next=dscb;
			    			
			    			dscb=p;
			    			
			    			step_shcb=step_nd=step_sh=step_g=step_p=step_n=step_t=step_nam=0;
							reset_temp(shcb_temp,nd_temp,sh_temp);
							reset_temp(g_temp,p_temp,n_temp);
							reset_temp(n_temp,t_temp,nam_temp);
			    			them_cb=false;
							in_ds_cb(dscb);
						}
					}
				}
				
				
			}
			
			//quan ly ve
			else if((x>=900)&&(x<=1270-18)&&(y>=50)&&(y<=90)){//&&(edit==false)
    			if(c_3==false){
    				reset_all();
    				hightline_box(900,50,1270-18,90,box[2],f_lon,2,4);
    				c_3 = true; c_1 = c_2 = false;
				}
				else{
					reset_all();
					c_3 = false;
				}
			}
		}
    	delay(0.0001);
	}
    closegraph();
    return 0;
}

bool xau_trung(char *a,char *b){
  int i=0;
  while(a[i]!='\0' && b[i]!='\0'){
    if(a[i]!=b[i]){
      return false;
      break;
    }
    i++;
  }
  return true;
}

bool ktrMB(DSMB &ds, char *sh, bool them, int chiso){
	int so_lan=0;
	for(int i = 0; i<ds.sl_mb; i++){
		if(xau_trung(ds.data[i]->sohieumb,sh)) so_lan++;
		cout<<"trung : "<<i<<endl;
	}
	cout<<"so lan :"<<so_lan<<endl;
	if(them) return ((so_lan==0) ? true : false);// ? return true : return false;
	else{
		if(xau_trung(ds.data[chiso]->sohieumb,sh)) so_lan--;
	 	return ((so_lan==0) ? true : false);//s(o_lan==1) ? return true : return false;
	}
}

void xl_trang(int sl, int trang, int &start, int &so_in){
	start = trang*10-1;
	so_in = sl-start;
	(so_in<10) ? so_in : so_in=10;
}

void reset_temp(char *temp1, char *temp2, char *temp3){
	temp1[0]='\0';
	temp2[0]='\0';
	temp3[0]='\0';
}

bool ktrVT(int l, int t, int r, int b, int x, int y){
	if((x>=l)&&(x<=r)&&(y>=t)&&(y<=b)) return true;
	else return false;
}

void normal_box(int l, int t, int r, int b, char* s, int font, int f_size, int kc){
	setfillstyle(1,11);
    bar3d(l,t,r,b,8,1);
    setbkcolor(11);
    settextstyle(font,0,f_size);
    outtextxy(l+8,t+kc,s);
}


void hightline_box(int l, int t, int r, int b, char* s, int font, int f_size, int kc){
	setfillstyle(1,7);
    bar3d(l,t-8,r+8,b,0,0);
	setfillstyle(1,10);
    bar3d(l+4,t-4,r+4,b-4,0,1);
    setbkcolor(10);
    settextstyle(font,0,f_size);
    outtextxy(l+8,t+kc,s);
}

void in_main_menu(){ //in khung menu chinh
	setfillstyle(1,7);
	bar3d(0,35,1270,100,0,0);
    normal_box(10,50,350,90,box[0],f_lon,2,8);
	normal_box(425,50,825,90,box[1],f_lon,2,8);
	normal_box(900,50,1270-18,90,box[2],f_lon,2,8);
}

void xoa_cn(){ //xoa man hinh chuc nang
	setfillstyle(1,8);
	bar(0,100,1270,767);
}

void reset_all(){ //in lai khung ban dau luc khoi dong
	xoa_cn();
	in_main_menu();
}

void normal_text(){ //set mau mac dinh cua ung dung
	setbkcolor(8);
	setcolor(0);
}

void charValue(int x, char *s){
	int dem=0,temp=x;
	while(temp!=0){
		temp=temp/10;
		dem++;
	}
	for(int i=dem-1;i>=0;i--){
		s[i]=(char)(x%10+'0');
		x=x/10;
	}
	s[dem]='\0';
}

int LoadFileMB (char *tenfile , DSMB &ds) {
	FILE *f;
	f=fopen(tenfile,"rt");
	if (f==NULL) return 0;
	int sc1,sl;
	char sh1[16];
	char loai1[41];
	fscanf(f,"%d ", &sl);
	ds.sl_mb = sl;
	fscanf(f,"\n");
	for ( int i=0 ; i<sl ; i++){
		ds.data[i] = new MB;
		fscanf(f,"%s", &sh1);
		strcpy(ds.data[i]->sohieumb,sh1);
		fscanf(f,"%s", &loai1);
		strcpy(ds.data[i]->loaimaybay,loai1);
		fscanf(f,"%d", &sc1);
		ds.data[i]->socho=sc1;
		fscanf(f,"\n");
		//if ((i+1) %10 ==0)
	}
	fclose (f);
	return 1;
}

int SaveFile_MB (char *tenfile , DSMB &ds) {
	FILE *f;
	f=fopen(tenfile,"wt");
	if (f==NULL) return 0;
	
	fprintf(f,"%d ", ds.sl_mb);
	
	fprintf(f,"\n");
	int sc1;
	char sh1[16];
	char loai1[41]; 
	for ( int i=0 ; i<ds.sl_mb ; i++)
	{
		strcpy(sh1,ds.data[i]->sohieumb);
		strcpy(loai1,ds.data[i]->loaimaybay);
		sc1=ds.data[i]->socho;
		fprintf(f,"%50s", sh1);
		fprintf(f,"%50s", loai1);
		fprintf(f,"%50d", sc1);
		fprintf(f,"\n");
	//if ((i+1) %10 ==0)
	
	}
	fclose (f);
	cout << "Da ghi xong day so"; return 1;
}


void in_ds_mb(DSMB &dsmb, char ds[][20]){
	int sl_ptuDS = 4;
	char sc_temp[5]={'\0'};
	
	xoa_cn();
	normal_text();
	settextstyle(1,0,2);
	outtextxy(20,120,box1[0]);
	normal_box(1050,120,1200,155,box1[1],f_vua,1,8);
	
	setfillstyle(1,12);
	bar3d(0,170,1270,210,0,0);
	setbkcolor(12);
	settextstyle(f_ds,0,1);
	for(int i=0,j=8; i<sl_ptuDS; i++){
		outtextxy(j,178,ds[i]);
		j+=(1270/sl_ptuDS+20);
	}
	
	int dau = 212;int cuoi = dau+50;
	setfillstyle(1,15);
	setbkcolor(15);
	settextstyle(f_ds,0,1);
	for(int k=0; k<dsmb.sl_mb; k++){
		int j =8;
		bar3d(0,dau,1270,cuoi,0,0);
		outtextxy(j,dau+8,dsmb.data[k]->sohieumb);
		j+=(1270/sl_ptuDS+20);
		outtextxy(j,dau+8,dsmb.data[k]->loaimaybay);
		j+=(1270/sl_ptuDS+20);
		charValue(dsmb.data[k]->socho,sc_temp);
		outtextxy(j,dau+8,sc_temp);
		j+=(1270/sl_ptuDS+20);
		//normal 4 - hightline 0
		normal_box(j,dau+12,1270-150,cuoi-8,cn[0],f_ds,1,4);
		left1[k]=j;top1[k]=dau+12;right1[k]=1270-150;bottom1[k]=cuoi-8;
		normal_box(j+120,dau+12,1270-30,cuoi-8,cn[1],f_ds,1,4);
		left2[k]=j+120;top2[k]=dau+12;right2[k]=1270-30;bottom2[k]=cuoi-8;
		setbkcolor(15);
		setfillstyle(1,15);
		
		dau += 50;cuoi+=50;
	}
}

void form_mb(char *ten){//form dien them may bay / normal 3 - hightline 0
	xoa_cn();
	normal_text();
	setfillstyle(1,7);
	bar3d(300,200,950,600,3,1);
	normal_box(850,550,920,580,cn[2],f_vua,2,3);
	normal_box(750,550,820,580,cn[3],f_vua,2,3);
	setbkcolor(7);
	settextstyle(f_lon,0,3);
	outtextxy(500,215,ten);
	settextstyle(f_vua,0,1);
	setfillstyle(1,15);
	outtextxy(310,270,ds_mb[0]);
	bar3d(500,270-5,940,270+25,0,1);
	outtextxy(310,370,ds_mb[1]);
	bar3d(470,370-5,940,370+25,0,1);
	outtextxy(310,470,ds_mb[2]);
	bar3d(530,470-5,700,470+25,0,1);
}


bool ktrKyTu(char &a, bool space, bool chu, bool so){
	if(space&&a==' ') return true;
	if(chu){
		for(char i='a'; i<='z'; i++){
			if(a==i){
				a -= 32;// chu thuong in thanh chu in hoa
				return true;
			}
		}
		for(char i='A'; i<='Z'; i++){
			if(a==i)
			return true;
		}
	}
	if(so){
		for(char i = '0'; i<='9'; i++){
			if(a==i) return true;
		}
	}
	return false;
}

int intValue(char  *s){
    int res = 0,dem=0;
	dem=strlen(s);
    for(int i=0;i<dem;i++){
    	if((s[i]>='0')&&(s[i]<='9')){
    		if(s[i]=='0') res = res*10;	
	    	else res = res*10 + (int)(s[i]-'0');	
		}
    	
	}
    return res;
}

void nhap(int l, int t, int r, int b, int max, int min, int loai, char *temp, int &step, int &x, int &y){//l,t,r,b
	if(ktrVT(l,t,r,b,x,y)){
		//nhap_pt=true;
		settextstyle(f_vua,0,1);
		setfillstyle(1,10);
		bar3d(l,t,r,b,0,1);
		setbkcolor(10);
		char nhap[2] = "_";
		step = strlen(temp);
		strcat(temp,nhap);
		outtextxy(l+10,t+5,temp);
		bool ktmax=true;
		bool ktmin=false;
		
		switch(loai){
			case ID:{
				while(true){
					if(kbhit()){
						char key = getch();
						if(key==8){ //nut backspace
							step--;
							temp[step]=95;//_
							temp[step+1]='\0';
							bar3d(l,t,r,b,0,1);
							outtextxy(l+10,t+5,temp);
						}
						else if(key==13&&ktmax&&ktmin){//nut  enter
							temp[step]='\0';
							settextstyle(f_vua,0,1);
							setfillstyle(1,15);
							bar3d(l,t,r,b,0,1);
							setbkcolor(15);
							outtextxy(l+10,t+5,temp);
							normal_text();
							//nhap_pt=false;
							break;
						}
						else if(ktrKyTu(key,false,true,true)&&ktmax){
							temp[step]=key;
							step++;
							temp[step]=95;
							temp[step+1]='\0';
							outtextxy(l+10,t+5,temp);
						}
						step = (step<0) ? 0 : step;
						if(step>max){
							setbkcolor(7);
							char gh[20]="*Qua gioi han";
							outtextxy(l+10,t+35,gh);
							setbkcolor(10);
							outtextxy(l+10,t+5,temp);
							ktmax = false;
						}
						else if(step<min){
							setbkcolor(7);
							char gh[20]="*Vui long nhap";
							outtextxy(l+10,t+35,gh);
							setbkcolor(10);
							outtextxy(l+10,t+5,temp);
							ktmin = false;
						}
						else{
							setfillstyle(1,7);
							bar(305,b+5,950,b+30);
							setfillstyle(1,10);
							if(step<=max) ktmax= true;
							if(step>=min) ktmin = true;
						}
						cout<<"temp la :"<<temp<<endl;
						cout<<"key la :"<<key<<endl;
					}
				}		
			}
			break;
			case So:{
				int gt;//gia tri
				while(true){
					if(kbhit()){
						char key = getch();
						
						if(key==8){ //nut backspace
							step--;
							temp[step]=95;//_
							temp[step+1]='\0';
							bar3d(l,t,r,b,0,1);
							outtextxy(l+10,t+5,temp);
							//gt=intValue(temp);
						}
						else if(key==13&&ktmax&&ktmin){//nut  enter
							temp[step]='\0';
							settextstyle(f_vua,0,1);
							setfillstyle(1,15);
							bar3d(l,t,r,b,0,1);
							setbkcolor(15);
							outtextxy(l+10,t+5,temp);
							normal_text();
							break;
						}
						else if(ktrKyTu(key,false,false,true)&&ktmax){
							temp[step]=key;
							step++;
							temp[step]=95;
							temp[step+1]='\0';
							outtextxy(l+10,t+5,temp);
							//gt=intValue(temp);
							cout<<"da vo check"<<endl;
						}
						gt=intValue(temp);
						step = (step<0) ? 0 : step;
						if(gt>max){
							setbkcolor(7);
							char gh[20]="*Qua gioi han";
							outtextxy(l+10,t+35,gh);
							setbkcolor(10);
							outtextxy(l+10,t+5,temp);
							ktmax = false;
						}
						else if(gt<min){
							setbkcolor(7);
							char gh[20]="*Gia tri nho qua";
							outtextxy(l+10,t+35,gh);
							setbkcolor(10);
							outtextxy(l+10,t+5,temp);
							ktmin = false;
							ktmax = true;
						}
						else{
							setfillstyle(1,7);
							bar(305,b+5,950,b+30);
							setfillstyle(1,8);
							bar(950,b+5,1200,b+30);
							setfillstyle(1,10);
							if(gt<=max) ktmax= true;
							if(gt>=min) ktmin = true;
						}
						cout<<"temp la :"<<temp<<endl;
						cout<<"key la :"<<key<<endl;
						cout<<"gia tri la :"<<gt<<endl;	
					}
				}
			}
			break;
			case HoTen:{
				while(true){
						
					if(kbhit()){
						char key = getch();
						if(key==13&&ktmax&&ktmin){//nut  enter
							if(temp[step-1]==' ') temp[--step]='\0'; //xoa dau space o cuoi
							else temp[step]='\0';
							settextstyle(f_vua,0,1);
							setfillstyle(1,15);
							bar3d(l,t,r,b,0,1);
							setbkcolor(15);
							outtextxy(l+10,t+5,temp);
							normal_text();
							break;
						}
						else if(key==8){ //nut backspace
							step--;
							temp[step]=95;//_
							temp[step+1]='\0';
							bar3d(l,t,r,b,0,1);
							outtextxy(l+10,t+5,temp);
						}
						else if(ktrKyTu(key,true,true,false)){
							if((key==' '&&temp[step-1]==' ')||(key==' '&&temp[step-1]=='\0'));
							else{
								temp[step]=key;
								step++;
								temp[step]=95;
								temp[step+1]='\0';
								outtextxy(l+10,t+5,temp);
							}	
						}
						step = (step<0) ? 0 : step;
						
						if(step>max){
							setbkcolor(7);
							char gh[20]="*Qua gioi han";
							outtextxy(l+10,t+35,gh);
							setbkcolor(10);
							outtextxy(l+10,t+5,temp);
							ktmax = false;
						}
						else if(step<min){
							setbkcolor(7);
							char gh[20]="*Vui long nhap";
							outtextxy(l+10,t+35,gh);
							setbkcolor(10);
							outtextxy(l+10,t+5,temp);
							ktmin = false;
						}
						else{
							setfillstyle(1,7);
							bar(305,b+5,950,b+30);
							//setfillstyle(1,7);
							setfillstyle(1,10);
							ktmin = true;
							ktmax = true;
						}
					}
				}
			}
			break;
		}
	}
}

bool ktSua(int &start, int so_ds, int x, int y){
	for(int i=0; i<so_ds; i++){
		if(ktrVT(left1[i],top1[i],right1[i],bottom1[i],x,y)){
			start+=i;
			return true;
		}
	}
	return false;
}

bool ktXoa(int &start, int so_ds, int x, int y){
	for(int i=0; i<so_ds; i++){
		if(ktrVT(left2[i],top2[i],right2[i],bottom2[i],x,y)){
			start+=i;
			return true;
		}
	}
	return false;
}

void from_xoa(char *s){
	xoa_cn();
	normal_text();
	setfillstyle(1,7);
	bar3d(300,200,950,600,3,1);
	normal_box(850,550,920,580,cn[4],f_vua,2,3);
	normal_box(750,550,820,580,cn[3],f_vua,2,3);
	setbkcolor(7);
	settextstyle(f_lon,0,4);
	char char_temp[20]="BAN CO MUON XOA";
	outtextxy(350,215,char_temp);
	outtextxy(450,315,s);
	char char_t[20]="KHONG ???";
	outtextxy(400,415,char_t);
}


