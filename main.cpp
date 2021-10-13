#include<graphics.h>
#include"khaibao.h"
#include<iostream>
#include<cmath>
#include<ctime>
#include <conio.h>
using namespace std;

// cac ham tong quat
void normal_box(int, int, int, int, char[], int, int, int);
void highlight_box(int, int, int, int, char[], int, int, int);
void in_main_menu();
void xoa_cn();
void reset_all();
void normal_text();
void charValue(int , char []);
bool ktrVT(int,int,int,int,int,int);
bool ktrKyTu(char &, bool, bool, bool);
int intValue(char  []);
void nhap(int, int, int, int, int, int, int, char[], int &, int &);
void reset_temp(char [], char [], char []);
bool xau_trung(char [],char []);
void xoa_tbloi();
void xu_ly_trang(int &,int,int,int);
void giaiphongcay(TREE);
void giaiphong(DSMB,PTR,TREE);

//cac ham may bay
void in_ds_mb(DSMB &, char [][20],int);
void form_mb(char []);
bool ktSua(int &, int , int, int);
bool ktXoa(int &, int , int, int);
void from_xoa(char []);
int SaveFile_MB (char [], DSMB &);
int LoadFileMB(char[], DSMB&);
bool ktrMB(DSMB &,char [],bool,int);
void themmb(DSMB &, char [], char [], char []);
void in_tk_mb(DSMB,int);
void swap_char(char [], char []);
bool check_mbincb(PTR,char[]);

//cac ham chuyen bay
void indsv(PTR, int);
KH getKH(TREE, char []);
void formkhve(TREE, char [],int, int);
int ktrtime(char [], char [],char[]);
void charTTMB(int, char []);
void charTime(TIME, char []);
void in_ds_cb(PTR,int);
void charPhai(bool, char []);
void getidcb(PTR, int, char []);
void setTime(PTR, int, char [], char [], char [], char [], char []);
void sethuyCB(PTR, int);
int ktslcb(PTR);
bool ktscb(int &, int, int, int);
void form_cb();
bool kthcb(int &, int, int, int);
void form_scb();
void from_huy(char []);
int getslchoMB(DSMB, char []);
void them_CB(PTR &,DSMB,char [],char [],char [],char [],char [],char [],char [],char []);
void getcmndghe(PTR ,int, int, char []);
void themve(PTR &,int, int, char []);
void in_ghe(int, char []);
int checkCMNDdatve(PTR,int,TREE,char[]);
void huy_ve(PTR&,int,int,char[]);
bool ktdsve(int &, int, int, int);
void in_dskhincb(PTR,TREE,int,int,int&);
bool ktidmb_dscb(PTR,char[]);
void form_tim_cb();
void in_ds_tim(PTR,char [],char [], char [], char []);
bool tim_cb_ds(CB cb,char [],char [],char [],char []);
int SaveFile_CB (char [], PTR);
int LoadFileCB (char [], PTR &);
void tangsl_bay(DSMB, char []);
void setTTCB(PTR);
bool kt_tt_cb(PTR, int);
bool ktvtve(PTR,int,int &,int x,int y);
bool kt_idcb(PTR,char[]);

//cac ham khach hang
void in_NLR(TREE, int &, int &, int &);
void in_dskh(TREE,int);
void them_1_kh(TREE &, char [], char [], char [], bool);
void getTime(PTR, int, char [], char [], char [], char [], char []);
bool ktdve(int &, int, int, int);
void form_kh();
bool checkCMND (TREE, char []);
void datvekh(PTR&,int,int,char []);
void getslKH(TREE,int&);
int SaveFile_KH(char [] , TREE);
void xuatkh(TREE, int &,char [][10], char [][10], char [][30], bool);
int LoadFile_KH(char [] , TREE &);
void doidaucach(bool, char []);


int main(){
	DSMB dsmb;
	dsmb.sl_mb=0;
	cout<<"\n\tTinh trang Load File MB:"<<LoadFileMB(file_mb,dsmb)<<endl;
	PTR dscb=NULL;
	cout<<"\n\tTinh trang Load File CB:"<<LoadFileCB("dscb.txt",dscb)<<endl;
	TREE dskh=NULL;
	cout<<"\n\tTinh trang Load File HK:"<<LoadFile_KH("khachhang.txt",dskh);
	setTTCB(dscb);
    int x,y;
    bool c_1,c_2,c_3,edit_mb,them_mb,xoa_mb,them_cb,edit_cb,huy_cb,them_kh,datve;
	c_1=c_2=c_3=edit_mb=them_mb=xoa_mb=them_cb=edit_cb=huy_cb=them_kh=datve=false;//C_... la trang thai chon
    initwindow(1280,780);
	normal_text();
    cleardevice();
    
    settextstyle(f_lon,0,4);
    outtextxy(420,1,ten);
    
    in_main_menu();
    
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
	char ho_temp[16]={'\0'};
	char cmnd_temp[11]={'\0'};
	char ten_temp[30]={'\0'};
	int chon_phai=0;//0 la chua chon, 1 la chon nam ,2 la chon nu
	int chiso = 0;
	int chisove=0;
	int trang=1;
	int pt_ds=0;
	int slkh_dsve=0;
	int slkh=0;
	int trang_khdsve=1;
	//int slv=0;
	bool editve=false;
	bool ktkh=false;
	bool huyve=false;
	bool indskh=false;
	bool tim_cb=false;
	bool tk_mb=false;
	bool menu_chinh;
	
    while(true) {
    	normal_text();
    	if (ismouseclick(WM_LBUTTONDOWN)){
    		getmouseclick(WM_LBUTTONDOWN,x,y);
    		cout<<"\nvi tri x:"<<x<<" - vi tri y:"<<y<<endl;
			
    		
    		if(ktkh||huyve||indskh||tim_cb||tk_mb||editve||edit_mb||them_mb||xoa_mb||them_cb||edit_cb||huy_cb||them_kh||datve) 
			menu_chinh=false;
    		else  menu_chinh = true;
    		
    		if(ktrVT(10,50,350,90,x,y)&&menu_chinh){
    			if(c_1==false){
    				reset_all();
    				highlight_box(10,50,350,90,box[0],f_lon,2,4);
    				c_1 = true; c_2 = c_3 = false;
    				trang=1;
					in_ds_mb(dsmb,ds_mb,trang);
				}
				else{
					reset_all();
					c_1 = false;
				}
			}
			else if(ktrVT(425,50,825,90,x,y)&&menu_chinh){
    			if(c_2==false){
    				reset_all();
    				highlight_box(425,50,825,90,box[1],f_lon,2,4);
    				c_2 = true; c_1 = c_3 = false;
    				trang=1;
    				in_ds_cb(dscb,trang);
				}
				else{
					reset_all();
					c_2 = false;
				}
			}
			else if(ktrVT(900,50,1270-18,90,x,y)&&menu_chinh){
    			if(c_3==false){
    				reset_all();
    				highlight_box(900,50,1270-18,90,box[2],f_lon,2,4);
    				c_3 = true; c_1 = c_2 = false;
    				trang=1;
    				in_dskh(dskh,trang);
				}
				else{
					reset_all();
					c_3 = false;
				}
			}
			else if(ktrVT(1090,5,1270,33,x,y)&&menu_chinh){
				setfillstyle(1,10);
				setbkcolor(10);
				bar(1090,5,1270,33);
				settextstyle(f_vua,0,2);
				outtextxy(1100,8,"THOAT UNG DUNG");
				delay(250);
				giaiphong(dsmb,dscb,dskh);
				closegraph();
				return 0;
			}
			//chuc nang trong ds may bay
			else if(c_1){
				if(them_mb==false&&edit_mb==false&&xoa_mb==false&&tk_mb==false){
					xu_ly_trang(trang,dsmb.sl_mb,x,y);
					in_ds_mb(dsmb,ds_mb,trang);
				}
				//them may bay
				if(ktrVT(1050,120,1200,155,x,y)&&them_mb==false&&edit_mb==false&&xoa_mb==false&&tk_mb==false){
					them_mb=true;
					highlight_box(1050,120,1200,155,box1[1],f_vua,1,2);
					delay(250);
					form_mb(box1[1]);
				}
				else if(them_mb){
					nhap(500,270-5,940,270+25,15,1,ID,sh_temp,x,y);
					nhap(470,370-5,940,370+25,25,1,ID,l_temp,x,y);
					nhap(530,470-5,700,470+25,200,20,So,sc_temp,x,y);
					
					if(ktrMB(dsmb,sh_temp,true,0)) xoa_tbloi();
					else if(ktrMB(dsmb,sh_temp,true,0)==false) {
						setbkcolor(14);
						outtextxy(460,630,"*So hieu may bay da ton tai");
					}
					//nut huy:
					if(ktrVT(750,550,820,580,x,y)){
						highlight_box(750,550,820,580,cn[3],f_vua,2,0);
		    			delay(250);
		    			xoa_cn();
						reset_temp(sh_temp,l_temp,sc_temp);
		    			them_mb=false;
						in_ds_mb(dsmb,ds_mb,trang);
					}
					//nut luu:
					else if(ktrVT(850,550,920,580,x,y)){
						if(ktrMB(dsmb,sh_temp,true,0)&&sh_temp!='\0'&&l_temp!='\0'&&sc_temp!='\0'){
							highlight_box(850,550,920,580,cn[2],f_vua,2,0);
			    			delay(250);
			    			xoa_cn();
			    			themmb(dsmb,sh_temp,l_temp,sc_temp);
			    			them_mb=false;
							SaveFile_MB(file_mb,dsmb);
							in_ds_mb(dsmb,ds_mb,trang);
						}
					}
				}
				//chinh sua may bay
				else if(ktSua(chiso,10,x,y)&&them_mb==false&&edit_mb==false&&xoa_mb==false&&tk_mb==false){
					edit_mb=true;
					highlight_box(left1[chiso],top1[chiso],right1[chiso],bottom1[chiso],cn[0],f_ds,1,0);
					delay(250);
					form_mb(box1[2]);
					pt_ds=chiso+trang*10-10;
					strcpy(sh_temp,dsmb.data[pt_ds]->sohieumb);
		    		strcpy(l_temp,dsmb.data[pt_ds]->loaimaybay);
		    		charValue(dsmb.data[pt_ds]->socho,sc_temp);
		    		setbkcolor(15);
		    		outtextxy(510,270,sh_temp);
		    		outtextxy(480,370,l_temp);
		    		outtextxy(540,470,sc_temp);
		    		if(check_mbincb(dscb,sh_temp)==false){
		    			setbkcolor(14);
						outtextxy(460,630,"*May bay da thuc hien chuyen bay");
						delay(1500);
						chiso=0;
						pt_ds=0;
		    			edit_mb=false;
		    			reset_temp(sh_temp,l_temp,sc_temp);
						SaveFile_MB(file_mb,dsmb);
						in_ds_mb(dsmb,ds_mb,trang);
					}
				}
				
				else if(edit_mb){
					nhap(500,270-5,940,270+25,15,1,ID,sh_temp,x,y);
					nhap(470,370-5,940,370+25,25,1,ID,l_temp,x,y);
					nhap(530,470-5,700,470+25,200,20,So,sc_temp,x,y);
					if(ktrMB(dsmb,sh_temp,false,pt_ds)) xoa_tbloi();
					else if(ktrMB(dsmb,sh_temp,false,pt_ds)==false){
						setbkcolor(14);
						outtextxy(460,630,"*So hieu may bay da ton tai");
					} 
					//nut huy
					if(ktrVT(750,550,820,580,x,y)){
						highlight_box(750,550,820,580,cn[3],f_vua,2,0);
		    			delay(250);
		    			xoa_cn();
						reset_temp(sh_temp,l_temp,sc_temp);
						chiso=0;
						pt_ds=0;
		    			edit_mb=false;
						in_ds_mb(dsmb,ds_mb,trang);
					}
					//nut luu
					else if(ktrVT(850,550,920,580,x,y)){
						if(ktrMB(dsmb,sh_temp,false,pt_ds)){
							highlight_box(850,550,920,580,cn[2],f_vua,2,0);
			    			delay(250);
			    			xoa_cn();
							strcpy(dsmb.data[pt_ds]->sohieumb,sh_temp);
			    			strcpy(dsmb.data[pt_ds]->loaimaybay,l_temp);
			    			int sc = intValue(sc_temp);
							dsmb.data[pt_ds]->socho = sc;
							chiso=0;
							pt_ds=0;
			    			edit_mb=false;
			    			reset_temp(sh_temp,l_temp,sc_temp);
							SaveFile_MB(file_mb,dsmb);
							in_ds_mb(dsmb,ds_mb,trang);
						}
						
					}
				}
				//xoa may bay
				else if(ktXoa(chiso,10,x,y)&&them_mb==false&&edit_mb==false&&xoa_mb==false&&tk_mb==false){
					xoa_mb=true;
					highlight_box(left2[chiso],top2[chiso],right2[chiso],bottom2[chiso],cn[1],f_ds,1,0);
					delay(250);
					pt_ds=chiso+trang*10-10;
					strcpy(sh_temp,dsmb.data[pt_ds]->sohieumb);
					from_xoa(sh_temp);
					if(check_mbincb(dscb,sh_temp)==false){
		    			setbkcolor(14);
						outtextxy(460,630,"*May bay da thuc hien chuyen bay");
						delay(1500);
						chiso=0;
						pt_ds=0;
		    			xoa_mb=false;
						in_ds_mb(dsmb,ds_mb,trang);
					}
				}
				else if(xoa_mb){
					//nut huy:
					if(ktrVT(750,550,820,580,x,y)){
						highlight_box(750,550,820,580,cn[3],f_vua,2,0);
		    			delay(250);
		    			xoa_cn();
		    			reset_temp(sh_temp,l_temp,sc_temp);
						chiso=0;
						pt_ds=0;
		    			xoa_mb=false;
						in_ds_mb(dsmb,ds_mb,trang);
					}
					//nut co:
					else if(ktrVT(850,550,920,580,x,y)){
						if(check_mbincb(dscb,sh_temp)){
							highlight_box(850,550,920,580,cn[4],f_vua,2,0);
			    			delay(250);
			    			xoa_cn();
			    			for(int i = pt_ds; i < dsmb.sl_mb-1; i++){
			    				strcpy(dsmb.data[i]->sohieumb,dsmb.data[i+1]->sohieumb);
			    				strcpy(dsmb.data[i]->loaimaybay,dsmb.data[i+1]->loaimaybay);
			    				dsmb.data[i]->socho=dsmb.data[i+1]->socho;
							}
							delete dsmb.data[--dsmb.sl_mb];
			    			chiso=0;
			    			pt_ds=0;
			    			xoa_mb=false;
			    			reset_temp(sh_temp,l_temp,sc_temp);
							SaveFile_MB(file_mb,dsmb);
							in_ds_mb(dsmb,ds_mb,trang);
						}	
					}
				}
				else if(ktrVT(800,120,1000,155,x,y)&&them_mb==false&&edit_mb==false&&xoa_mb==false&&tk_mb==false){
					highlight_box(800,120,1000,155,"Thong ke bay may",f_vua,1,2);
					delay(250);
					tk_mb=true;
					trang=1;
					in_tk_mb(dsmb,trang);
				}
				else if(tk_mb){
					if(ktrVT(1050,120,1230,155,x,y)){
						highlight_box(1050,120,1230,155,"Thoat thong ke",f_vua,1,2);
						delay(250);
						tk_mb=false;
						trang=1;
						in_ds_mb(dsmb,ds_mb,trang);
					}
					else{
						xu_ly_trang(trang,dsmb.sl_mb,x,y);
						in_tk_mb(dsmb,trang);
					}
					
				}
			}

			//quan ly chuyen bay
			else if(c_2){
				if(them_cb==false&&edit_cb==false&&huy_cb==false&&indskh==false&&tim_cb==false&&datve==false){
					xu_ly_trang(trang,ktslcb(dscb),x,y);
					in_ds_cb(dscb,trang);
				}
				if(ktrVT(1050,120,1200,155,x,y)&&them_cb==false&&edit_cb==false&&huy_cb==false&&indskh==false&&tim_cb==false&&datve==false){
					them_cb=true;
					highlight_box(1050,120,1230,155,"Them Chuyen Bay",f_vua,1,2);
					delay(250);
					form_cb();
				}
				else if(them_cb){
					nhap(360,270-5,580,270+25,15,1,ID,shcb_temp,x,y);
					nhap(690,270-5,940,270+25,15,1,Ho,nd_temp,x,y);
					nhap(430,470-5,700,470+25,15,1,ID,sh_temp,x,y);
					
					nhap(350,370-5,410,370+25,24,1,So,g_temp,x,y);
					nhap(480,370-5,540,370+25,59,0,So,p_temp,x,y);
					nhap(610,370-5,670,370+25,31,1,So,n_temp,x,y);
					nhap(750,370-5,810,370+25,12,1,So,t_temp,x,y);
					nhap(870,370-5,948,370+25,2100,2021,So,nam_temp,x,y);
					int maloitg = ktrtime(n_temp,t_temp,nam_temp);
					if(ktrMB(dsmb,sh_temp,true,0)&&sh_temp[0]!='\0'){
						xoa_tbloi();
						setbkcolor(14);
						outtextxy(460,630,"*May bay khong ton tai");
					}
					else if(ktidmb_dscb(dscb,sh_temp)==false){
						xoa_tbloi();
						setbkcolor(14);
						outtextxy(460,630,"*May bay dang thuc hien chuyen bay khac");
					}
					else if(kt_idcb(dscb,shcb_temp)==false&&shcb_temp[0]!='\0'){
						xoa_tbloi();
						setbkcolor(14);
						outtextxy(460,630,"*Ma chuyen bay da ton tai");
					}
					else if(maloitg==1){
						xoa_tbloi();
						setbkcolor(14);
						outtextxy(460,630,"*Ngay Khong Ton Tai");
					}
					else if(maloitg==2){
						xoa_tbloi();
						setbkcolor(14);
						outtextxy(460,630,"*Khong the lap chuyen bay trong ngay hoac qua khu");
					}
					else if(maloitg==3){
						xoa_tbloi();
						setbkcolor(14);
						outtextxy(460,630,"*Khong the lap chuyen bay som hon 2 thang");
					}
					else{
						xoa_tbloi();
					}
					//nut huy:
					if(ktrVT(750,550,820,580,x,y)){
						highlight_box(750,550,820,580,cn[3],f_vua,2,0);
		    			delay(250);
		    			xoa_cn();
						reset_temp(shcb_temp,nd_temp,sh_temp);
						reset_temp(g_temp,p_temp,n_temp);
						reset_temp(n_temp,t_temp,nam_temp);
		    			them_cb=false;
						in_ds_cb(dscb,trang);
					}
					
					//nut luu:
					else if(ktrVT(850,550,920,580,x,y)&&ktrMB(dsmb,sh_temp,true,0)==false&&kt_idcb(dscb,shcb_temp)&&ktidmb_dscb(dscb,sh_temp)&&ktrtime(n_temp,t_temp,nam_temp)==0){
						if((sh_temp[0]=='\0'||shcb_temp[0]=='\0'||nd_temp[0]=='\0'||sh_temp[0]=='\0'||g_temp[0]=='\0'||p_temp[0]=='\0'||n_temp[0]=='\0'||t_temp[0]=='\0'||nam_temp[0]=='\0'));
						else{
							highlight_box(850,550,920,580,cn[2],f_vua,2,0);
			    			delay(250);
			    			xoa_cn();
			    			them_CB(dscb,dsmb,shcb_temp,nd_temp,sh_temp,g_temp,p_temp,n_temp,t_temp,nam_temp);
							reset_temp(shcb_temp,nd_temp,sh_temp);
							reset_temp(g_temp,p_temp,n_temp);
							reset_temp(n_temp,t_temp,nam_temp);
			    			them_cb=false;
			    			cout<<SaveFile_CB("dscb.txt" ,dscb);
			    			//cout<<"da qua save file chuyen bay..."<<endl;
							cout<<SaveFile_MB(file_mb,dsmb);
							//cout<<"da qua save file may bay..."<<endl;

							in_ds_cb(dscb,trang);
						}
					}
				}
				//sua chuyen bay
				else if(ktscb(chiso,10,x,y)&&them_cb==false&&edit_cb==false&&huy_cb==false&&indskh==false&&tim_cb==false&&datve==false){
					//cout<<"chi so la :"<<chiso<<endl;
					edit_cb=true;
					highlight_box(l_scb[chiso],t_scb[chiso],r_scb[chiso],b_scb[chiso],"Sua",f_ds,1,0);
					delay(250);
					form_scb();
					pt_ds=chiso+trang*10-10;
					getTime(dscb,pt_ds,g_temp,p_temp,n_temp,t_temp,nam_temp);
					setbkcolor(15);
					outtextxy(350+10,370,g_temp);
					outtextxy(480+10,370,p_temp);
					outtextxy(610+10,370,n_temp);
					outtextxy(750+10,370,t_temp);
					outtextxy(870+10,370,nam_temp);
					if(kt_tt_cb(dscb,pt_ds)==false){
						setbkcolor(14);
						outtextxy(460,630,"*Chuyen bay da huy hoac hoan thanh");
						delay(1500);
						chiso=0;
						pt_ds=0;
						xoa_cn();
						reset_temp(g_temp,p_temp,n_temp);
						reset_temp(n_temp,t_temp,nam_temp);
		    			edit_cb=false;
						in_ds_cb(dscb,trang);
					}
				}
				else if(edit_cb){
					nhap(350,370-5,410,370+25,24,1,So,g_temp,x,y);
					nhap(480,370-5,540,370+25,59,0,So,p_temp,x,y);
					nhap(610,370-5,670,370+25,31,1,So,n_temp,x,y);
					nhap(750,370-5,810,370+25,12,1,So,t_temp,x,y);
					nhap(870,370-5,948,370+25,2100,2021,So,nam_temp,x,y);
					
					int maloitg = ktrtime(n_temp,t_temp,nam_temp);
					if(maloitg==0) xoa_tbloi();
					else if(maloitg==1){
						setbkcolor(14);
						outtextxy(460,630,"*Ngay Khong Ton Tai");
					}
					else if(maloitg==2){
						setbkcolor(14);
						outtextxy(460,630,"*Khong the lap chuyen bay trong ngay hoac qua khu");
					}
					else if(maloitg==3){
						setbkcolor(14);
						outtextxy(460,630,"*Khong the lap chuyen bay som hon 2 thang");
					}
					//nut huy:
					if(ktrVT(750,550,820,580,x,y)){
						highlight_box(750,550,820,580,cn[3],f_vua,2,0);
		    			delay(250);
		    			xoa_cn();
						reset_temp(g_temp,p_temp,n_temp);
						reset_temp(n_temp,t_temp,nam_temp);
						chiso=0;
						pt_ds=0;
		    			edit_cb=false;
						in_ds_cb(dscb,trang);
					}
					//nut luu:
					else if(ktrVT(850,550,920,580,x,y)){
						highlight_box(850,550,920,580,cn[2],f_vua,2,0);
		    			delay(250);
		    			xoa_cn();
		    			//cout<<"chi so la "<<chiso<<endl;
						setTime(dscb,pt_ds,g_temp,p_temp,n_temp,t_temp,nam_temp);
						reset_temp(g_temp,p_temp,n_temp);
						reset_temp(n_temp,t_temp,nam_temp);
						edit_cb=false;
						chiso=0;
						pt_ds=0;
						cout<<SaveFile_CB("dscb.txt" ,dscb);
						in_ds_cb(dscb,trang);
					}
				}	
				//huy chuyen bay
				else if(kthcb(chiso,ktslcb(dscb),x,y)&&them_cb==false&&edit_cb==false&&huy_cb==false&&indskh==false&&tim_cb==false&&datve==false){
					//cout<<"chi so la :"<<chiso<<endl;
					highlight_box(l_hcb[chiso],t_hcb[chiso],r_hcb[chiso],b_hcb[chiso],"Huy",f_ds,1,0);
					delay(250);
					pt_ds=chiso+trang*10-10;
					getidcb(dscb,pt_ds,shcb_temp);
					from_huy(shcb_temp);
					huy_cb=true;
				}
				else if(huy_cb){
					//nut huy:
					if(ktrVT(750,550,820,580,x,y)){
						highlight_box(750,550,820,580,cn[3],f_vua,2,0);
		    			delay(250);
		    			xoa_cn();
		    			huy_cb=false;
		    			shcb_temp[0]='\0';
		    			chiso=0;
		    			pt_ds=0;
						in_ds_cb(dscb,trang);
					}
					//nut co:
					else if(ktrVT(850,550,920,580,x,y)){
						highlight_box(850,550,920,580,cn[4],f_vua,2,0);
						//cout<<"chi so la "<<chiso<<endl;
		    			delay(250);
		    			xoa_cn();//
		    			sethuyCB(dscb,pt_ds);
						huy_cb=false;
						shcb_temp[0]='\0';
						chiso=0;
						pt_ds=0;
						cout<<SaveFile_CB("dscb.txt" ,dscb);
						in_ds_cb(dscb,trang);
					}
				}
				//dat ve
				else if(ktdve(chiso,ktslcb(dscb),x,y)&&them_cb==false&&edit_cb==false&&huy_cb==false&&indskh==false&&tim_cb==false&&datve==false){
					highlight_box(l_dv[chiso],t_dv[chiso],r_dv[chiso],b_dv[chiso],"Dat Ve",f_ds,1,0);
					delay(250);
					datve=true;
					pt_ds=chiso+trang*10-10;
					indsv(dscb,pt_ds);
					if(kt_tt_cb(dscb,pt_ds)==false){
						xoa_cn();
						setbkcolor(14);
						outtextxy(460,630,"*Chuyen bay da huy hoac hoan thanh");
						delay(1500);
						chiso=0;
						pt_ds=0;
						datve=false;
						in_ds_cb(dscb,trang);
					}
				}
				else if(datve){
					if(ktrVT(1100,700,1250,735,x,y)&&editve==false){
						highlight_box(1100,700,1250,735,"THOAT DAT VE",f_vua,1,2);
						chiso=0;
						pt_ds=0;
						datve=false;
						delay(250);
						in_ds_cb(dscb,trang);
					}
					else if(editve){
						if(tt_ghe[chisove]==0) nhap(200,630-5,610,630+25,9,9,CMVE,cmnd_temp,x,y);
						if(ktrVT(500,715,580,745,x,y)){
							highlight_box(500,715,580,745,"THOAT",f_vua,2,0);
							delay(250);
							editve=false;
							cmnd_temp[0]='\0';
							indsv(dscb,pt_ds);
							chisove=0;
						}
						else if(ktrVT(620,715,710,745,x,y)&&ktkh==false&&huyve==false&&ktkh==false&&them_kh==false){
							if(tt_ghe[chisove]==0){							
								highlight_box(620,715,710,745,"DAT VE",f_vua,2,0);
								delay(250);
								if(checkCMNDdatve(dscb,pt_ds,dskh,cmnd_temp)==2){
									formkhve(dskh,cmnd_temp,x,y);
									ktkh=true;
								}
								else if(checkCMNDdatve(dscb,pt_ds,dskh,cmnd_temp)==0){
									form_kh();
									setbkcolor(15);
									outtextxy(368,270,cmnd_temp);
									them_kh=true;
								}
								else if(checkCMNDdatve(dscb,pt_ds,dskh,cmnd_temp)==1){
									xoa_cn();
									setbkcolor(14);
									outtextxy(460,630,"*Khach hang trung trong danh sach ve");
									delay(2000);
									editve=false;
									cmnd_temp[0]='\0';
									chisove=0;
									indsv(dscb,pt_ds);
								}
							}
							else if(tt_ghe[chisove]==1){
								highlight_box(620,715,710,745,"HUY VE",f_vua,2,0);
								delay(250);
								huyve=true;
								from_huy("ve cua khach");
							}
						}
						else if(huyve){
							//nut huy:
							if(ktrVT(750,550,820,580,x,y)){
								highlight_box(750,550,820,580,cn[3],f_vua,2,0);
								delay(250);
								huyve=false;
								editve=false;
								cmnd_temp[0]='\0';
								chisove=0;
								indsv(dscb,pt_ds);
							}
							//nut co:
							else if(ktrVT(850,550,920,580,x,y)){
								highlight_box(850,550,920,580,cn[4],f_vua,2,0);
								delay(250);
								huy_ve(dscb,pt_ds,chisove,cmnd_temp);
								huyve=false;
								editve=false;
								cmnd_temp[0]='\0';
								chisove=0;
								cout<<SaveFile_CB("dscb.txt" ,dscb);
								indsv(dscb,pt_ds);
							}
						}
						else if(ktkh){
							//nut huy:
							if(ktrVT(750,550,820,580,x,y)){
								highlight_box(750,550,820,580,cn[3],f_vua,2,0);
								delay(250);
								xoa_cn();
								ktkh=false;
								editve=false;
								cmnd_temp[0]='\0';
								chisove=0;
								indsv(dscb,pt_ds);
							}
							//nut luu:
							else if(ktrVT(850,550,920,580,x,y)){
								highlight_box(850,550,920,580,cn[2],f_vua,2,0);
								//cout<<"chi so la "<<chiso<<endl;
								delay(250);
								datvekh(dscb,pt_ds,chisove,cmnd_temp);
								xoa_cn();
								ktkh=false;
								editve=false;
								cmnd_temp[0]='\0';
								chisove=0;
								cout<<SaveFile_CB("dscb.txt",dscb);
								indsv(dscb,pt_ds);
							}
						}
						else if(them_kh){
							nhap(690,270-5,940,270+25,10,2,Ho,ho_temp,x,y);
							nhap(350,370-5,940,370+25,28,2,Ten,ten_temp,x,y);
							//chon nam
							if(ktrVT(450,470-5,500,470+25,x,y)){
								settextstyle(f_vua,0,1);
								setfillstyle(1,10);
								setbkcolor(10);
								bar3d(450,470-5,500,470+25,0,1);
								outtextxy(458,470,"NAM");
								setfillstyle(1,15);
								setbkcolor(15);
								bar3d(550,470-5,600,470+25,0,1);
								outtextxy(558,470,"NU");
								normal_text();
								chon_phai = 1;
							}
							//chon nu
							if(ktrVT(550,470-5,600,470+25,x,y)){
								settextstyle(f_vua,0,1);
								setfillstyle(1,10);
								setbkcolor(10);
								bar3d(550,470-5,600,470+25,0,1);
								outtextxy(558,470,"NU");
								setfillstyle(1,15);
								setbkcolor(15);
								bar3d(450,470-5,500,470+25,0,1);
								outtextxy(458,470,"NAM");
								normal_text();
								chon_phai = 2;
							}
							//nut huy:
							if(ktrVT(750,550,820,580,x,y)){
								highlight_box(750,550,820,580,cn[3],f_vua,2,0);
				    			delay(250);
				    			xoa_cn();
				    			them_kh=false;
				    			editve=false;
				    			chisove=0;
				    			reset_temp(cmnd_temp,ho_temp,ten_temp);
				    			//in_dskh(dskh);
				    			indsv(dscb,pt_ds);
				    		}
				    		//nut luu:
				    		if(ktrVT(850,550,920,580,x,y)&&ho_temp[0]!='\0'&&ten_temp[0]!='\0'&&cmnd_temp[0]!='\0'&&chon_phai!=0&&checkCMND(dskh,cmnd_temp)==false){
								highlight_box(850,550,920,580,cn[2],f_vua,2,0);
				    			delay(250);
				    			xoa_cn();
				    			datvekh(dscb,pt_ds,chisove,cmnd_temp);
				    			bool phai;
				    			if(chon_phai == 1) phai=true;
				    			else if(chon_phai == 2) phai=false;
				    			them_1_kh(dskh,cmnd_temp,ho_temp,ten_temp,phai);
				    			reset_temp(cmnd_temp,ho_temp,ten_temp);
				    			chisove=0;
				    			cout<<SaveFile_CB("dscb.txt" ,dscb);
				    			cout<<"luu khach hang:"<<SaveFile_KH("khachhang.txt",dskh)<<endl;
								them_kh=false;
								editve=false;
				    			indsv(dscb,pt_ds);
				    		}
						}
					}
					else if(ktvtve(dscb,pt_ds,chisove,x,y)&&editve==false){
						//cout<<"chi so ve :"<<chisove<<endl;
						editve=true;
						if(tt_ghe[chisove]==1 || tt_ghe[chisove]==2) getcmndghe(dscb,pt_ds,chisove,cmnd_temp);
						else cmnd_temp[0]='\0';
						in_ghe(chisove,cmnd_temp);
					}
				}
				//in ds khanh dat ve
				else if(ktdsve(chiso,ktslcb(dscb),x,y)&&them_cb==false&&edit_cb==false&&huy_cb==false&&indskh==false&&tim_cb==false&&datve==false){
					highlight_box(l_dsv[chiso],t_dsv[chiso],r_dsv[chiso],b_dsv[chiso],"Danh Sach Ve",f_ds,1,0);
					delay(250);
					indskh=true;
					pt_ds=chiso+trang*10-10;
					in_dskhincb(dscb,dskh,trang_khdsve,pt_ds,slkh_dsve);
				}
				else if(indskh){
					if(ktrVT(1050,120,1230,155,x,y)){
						highlight_box(1050,120,1230,155,"Thoat Danh Sách",f_vua,1,2);
						delay(250);
						indskh=false;
						chiso=0;
						pt_ds=0;
						trang_khdsve=1;
						in_ds_cb(dscb,trang);
					}
					else{
						xu_ly_trang(trang_khdsve,slkh_dsve,x,y);
						in_dskhincb(dscb,dskh,trang_khdsve,pt_ds,slkh_dsve);
					}
				}
				//tim kiem chuyen bay
				else if(ktrVT(800,120,980,155,x,y)&&them_cb==false&&edit_cb==false&&huy_cb==false&&indskh==false&&tim_cb==false&&datve==false){
					highlight_box(800,120,980,155,"Tim Chuyen Bay",f_vua,1,2);
					delay(250);
					tim_cb=true;
					form_tim_cb();
				}
				else if(tim_cb){
					nhap(590,270-5,840,270+25,16,2,Ho,nd_temp,x,y);
					nhap(400,370-5,460,370+25,31,1,So,n_temp,x,y);
					nhap(600,370-5,660,370+25,12,1,So,t_temp,x,y);
					nhap(790,370-5,870,370+25,2100,2021,So,nam_temp,x,y);
					//nut huy:
					if(ktrVT(750,550,820,580,x,y)){
						highlight_box(750,550,820,580,cn[3],f_vua,2,0);
						delay(250);
						tim_cb=false;
						nd_temp[0]=n_temp[0]=t_temp[0]=nam_temp[0]='\0';
						in_ds_cb(dscb,trang);
					}
					//nut tim:
					else if(ktrVT(850,550,920,580,x,y)){
						highlight_box(850,550,920,580," Tim",f_vua,2,0);
						delay(250);
						in_ds_tim(dscb,nd_temp,n_temp,t_temp,nam_temp);
						nd_temp[0]=n_temp[0]=t_temp[0]=nam_temp[0]='\0';
					}
					else if(ktrVT(1050,120,1230,155,x,y)){
						highlight_box(1050,120,1230,155,"Thoat Tim",f_vua,1,2);
						delay(250);
						tim_cb=false;
						in_ds_cb(dscb,trang);
					}
				}	
			}
			
			//quan ly khach
			else if(c_3){
				if(ktrVT(1050,120,1230,155,x,y)&&them_kh==false){
					them_kh=true;
					highlight_box(1050,120,1230,155,"Them Khach Hang",f_vua,1,2);
					delay(250);
					form_kh();
				}
				else if(them_kh){
					nhap(360,270-5,580,270+25,9,9,CMND,cmnd_temp,x,y);
					nhap(690,270-5,940,270+25,10,2,Ho,ho_temp,x,y);
					nhap(350,370-5,940,370+25,28,2,Ten,ten_temp,x,y);
					//chon nam
					if(ktrVT(450,470-5,500,470+25,x,y)){
						settextstyle(f_vua,0,1);
						setfillstyle(1,10);
						setbkcolor(10);
						bar3d(450,470-5,500,470+25,0,1);
						outtextxy(458,470,"NAM");
						setfillstyle(1,15);
						setbkcolor(15);
						bar3d(550,470-5,600,470+25,0,1);
						outtextxy(558,470,"NU");
						normal_text();
						chon_phai = 1;
					}
					//chon nu
					else if(ktrVT(550,470-5,600,470+25,x,y)){
						settextstyle(f_vua,0,1);
						setfillstyle(1,10);
						setbkcolor(10);
						bar3d(550,470-5,600,470+25,0,1);
						outtextxy(558,470,"NU");
						setfillstyle(1,15);
						setbkcolor(15);
						bar3d(450,470-5,500,470+25,0,1);
						outtextxy(458,470,"NAM");
						normal_text();
						chon_phai = 2;
					}
					//nut huy:
					else if(ktrVT(750,550,820,580,x,y)){
						highlight_box(750,550,820,580,cn[3],f_vua,2,0);
		    			delay(250);
		    			xoa_cn();
		    			them_kh=false;
		    			reset_temp(cmnd_temp,ho_temp,ten_temp);
		    			in_dskh(dskh,trang);
		    		}
		    		//nut luu:
		    		else if(ktrVT(850,550,920,580,x,y)&&ho_temp[0]!='\0'&&ten_temp[0]!='\0'&&cmnd_temp[0]!='\0'&&chon_phai!=0&&checkCMND(dskh,cmnd_temp)==false){
						highlight_box(850,550,920,580,cn[2],f_vua,2,0);
		    			delay(250);
		    			xoa_cn();
		    			bool phai;
		    			if(chon_phai == 1) phai=true;
		    			else if(chon_phai == 2) phai=false;
		    			them_1_kh(dskh,cmnd_temp,ho_temp,ten_temp,phai);
		    			cout<<"luu khach hang:"<<SaveFile_KH("khachhang.txt",dskh)<<endl;
		    			them_kh=false;
		    			reset_temp(cmnd_temp,ho_temp,ten_temp);
		    			in_dskh(dskh,trang);
		    		}
				}
				else{
					slkh=0;
					getslKH(dskh,slkh);
					xu_ly_trang(trang,slkh,x,y);
					in_dskh(dskh,trang);
				}
			}
		}
    	delay(0.0001);
	}
    closegraph();
    return 0;
}

bool kt_idcb(PTR dscb, char macb[]){
	PTR get;
	for(get=dscb;get!=NULL;get=get->next){
		if(xau_trung(get->data.machuyenbay,macb)) return false;
	}
	return true;
}

void xu_ly_trang(int &trang,int slpt,int x,int y){
	if(ktrVT(520,730,550,760,x,y)&&trang>1){
		setfillstyle(1,10);
		setbkcolor(10);
		bar3d(520,730,550,760,0,1);
		outtextxy(528,735,"<");
		delay(200);
		trang--;
	}
	else if(ktrVT(610,730,640,760,x,y)&&slpt>(trang*10)){
		setfillstyle(1,10);
		setbkcolor(10);
		bar3d(610,730,640,760,0,1);
		outtextxy(618,735,">");
		delay(200);
		trang++;
	}
}

void giaiphongcay(TREE dskh){
    if(dskh == NULL) return;
    giaiphongcay(dskh->left);
    giaiphongcay(dskh->right);
    delete dskh;
}

void giaiphong(DSMB dsmb,PTR dscb,TREE dskh){
	for(int i=0;i<dsmb.sl_mb;i++){
		delete dsmb.data[i];
	}
	PTR get;
	while(dscb=NULL){
		get=dscb;
		dscb=dscb->next;
		for(int i=0; i<get->sldat;i++){
			delete get->dsve[i];
		}
		delete get;
	}
	giaiphongcay(dskh);
	dskh=NULL;
}

bool kt_tt_cb(PTR dscb, int chiso){
	PTR get;
	int i;
	for(get=dscb,i=0;i<chiso;get=get->next,i++);
	if(get->data.trang_thai==0) return false;
	else if(get->data.trang_thai==3) return false;
	return true;
}

void setTTCB(PTR dscb){
	PTR set;
	char ngay[5];
	char thang[5];
	char nam[5];
	for(set=dscb;set!=NULL;set=set->next){
		charValue(set->data.time_xp.ngay,ngay);
		charValue(set->data.time_xp.thang,thang);
		charValue(set->data.time_xp.nam,nam);
		int kt= ktrtime(ngay,thang,nam);
		if(kt==2) set->data.trang_thai=3;
		else if((set->slve-set->sldat)==0) set->data.trang_thai=2;
	}
}

void doidaucach(bool savefile, char s[]){
	if(savefile){
		for(int i=0; s[i]!='\0';i++){
			if(s[i]==' ') s[i]='_';
		}
	}
	else if(savefile==false){
		for(int i=0; s[i]!='\0';i++){
			if(s[i]=='_') s[i]=' ';
		}
	}
}

int LoadFile_KH(char tenfile[], TREE &dskh){
	FILE *f;
	f=fopen(tenfile,"rt");
	if (f==NULL) return 0;
	int slkh;
	fscanf(f,"%d ", &slkh);
	if(slkh==0) {
		dskh=NULL;
		return 0;
	}
	char cmnd_t[slkh][10];
	char ho_t[slkh][10];
	char ten_t[slkh][30];
	char phai_char[slkh][10];
	bool phai_t[slkh];
	
	for(int i=0;i<slkh;i++){
		fscanf(f,"%s", &cmnd_t[i]);
		fscanf(f,"%s", &ho_t[i]);
		fscanf(f,"%s", &ten_t[i]);
		doidaucach(false,ten_t[i]);
		fscanf(f,"%s", &phai_char[i]);
		xau_trung(phai_char[i],"Nam") ? phai_t[i]=true : phai_t[i]=false;
		them_1_kh(dskh,cmnd_t[i],ho_t[i],ten_t[i],phai_t[i]);
	}
	fclose (f);
	return 1;
}

void xuatkh(TREE dskh, int &chiso,char cmnd[][10], char ho[][10], char ten[][30], bool phai[]){
	if(dskh!=NULL){
		strcpy(cmnd[chiso],dskh->data.CMND);
		strcpy(ho[chiso],dskh->data.Ho);
		strcpy(ten[chiso],dskh->data.Ten);
		phai[chiso]=dskh->data.Phai;
		chiso++;
		xuatkh(dskh->left,chiso,cmnd,ho,ten, phai);
		xuatkh(dskh->right,chiso,cmnd,ho,ten, phai);
	}
}

void getslKH(TREE dskh,int &kq){
	if(dskh!=NULL){
		kq++;
		getslKH(dskh->left,kq);
		getslKH(dskh->right,kq);
	}
}

int SaveFile_KH (char tenfile[] , TREE ds){
	FILE *f;
	f=fopen(tenfile,"wt");
	if (f==NULL) return 0;
	int slkh =0;
	getslKH(ds,slkh);
	fprintf(f,"%d ",slkh);
	fprintf(f,"\n");
	char cmnd_t[slkh][10];
	char ho_t[slkh][10];
	char ten_t[slkh][30];
	bool phai_t[slkh];
	int chiso=0;
	xuatkh(ds,chiso,cmnd_t,ho_t,ten_t, phai_t);
	for(int i=0;i<slkh;i++){
		fprintf(f,"%30s",cmnd_t[i]);
		fprintf(f,"%30s",ho_t[i]);
		doidaucach(true,ten_t[i]);
		fprintf(f,"%30s",ten_t[i]);
		fprintf(f,"%50s", phai_t[i] ? "Nam" : "Nu");
		fprintf(f,"\n");
	}
	
	fclose (f);
	cout << "Da ghi xong day so"; return 1;
}

int SaveFile_CB (char tenfile[], PTR ds) {
	FILE *f;
	f=fopen(tenfile,"wt");
	if (f==NULL) return 0;
	PTR get;
	int slcb=ktslcb(ds);
	fprintf(f,"%d ", slcb);
	fprintf(f,"\n");
	bool tt_g;
	
	for(get=ds;get!=NULL;get=get->next){
		fprintf(f,"%30d", get->sldat);
		fprintf(f,"%30d", get->slve);
		fprintf(f,"%30s", get->data.machuyenbay);
		fprintf(f,"%30s", get->data.noiden);
		fprintf(f,"%30s", get->data.sh_mb);
		fprintf(f,"%30d", get->data.trang_thai);
		fprintf(f,"%30d", get->data.time_xp.gio);
		fprintf(f,"%30d", get->data.time_xp.phut);
		fprintf(f,"%30d", get->data.time_xp.ngay);
		fprintf(f,"%30d", get->data.time_xp.thang);
		fprintf(f,"%30d", get->data.time_xp.nam);
		fprintf(f,"\n");
		//cout<<"da qua vong lap for thu 1..."<<endl;
		//cout<<"so luong ve dat:"<<get->sldat<<endl;
		for(int i=0;i<get->sldat;i++){
			fprintf(f,"%30s", get->dsve[i]->CMND);
			fprintf(f,"%30d", get->dsve[i]->ghe_so);
			//tt_g=get->dsve[i]->tt;
			fprintf(f,"%50s", get->dsve[i]->tt ? "true" : "false");
			fprintf(f,"\n");
		}
		//cout<<"da qua vong lap for thu 2..."<<endl;
		fprintf(f,"\n\n");
		
	}
	//cout<<"ket thuc vong lap..."<<endl;
	fclose (f);
	cout << "Da ghi xong day so"; return 1;
}


int LoadFileCB (char tenfile[], PTR &dscb) {
	FILE *f;
	f=fopen(tenfile,"rt");
	if (f==NULL) return 0;
	char tt[10];
	int slcb;
	fscanf(f,"%d ", &slcb);
	if(slcb==0) {
		dscb=NULL;
		return 0;
	}
	int i;
	PTR ds;
	//cout<<"so luong cb:"<<slcb<<endl;
	for(i=0;i<slcb;i++){
		ds = new nodeCB;
		fscanf(f,"%d", &ds->sldat);
		fscanf(f,"%d", &ds->slve);
		//cout<<"so luong Ve:"<<ds->slve;
		fscanf(f,"%s", &ds->data.machuyenbay);
		fscanf(f,"%s", &ds->data.noiden);
		fscanf(f,"%s", &ds->data.sh_mb);
		fscanf(f,"%d", &ds->data.trang_thai);
		fscanf(f,"%d", &ds->data.time_xp.gio);
		fscanf(f,"%d", &ds->data.time_xp.phut);
		fscanf(f,"%d", &ds->data.time_xp.ngay);
		fscanf(f,"%d", &ds->data.time_xp.thang);
		fscanf(f,"%d", &ds->data.time_xp.nam);
		//cout<<"sl dat ve:"<<ds->sldat<<endl;
		for(int j=0;j<ds->sldat;j++){
			//cout<<" thu tu:"<<j<<endl;
			ds->dsve[j]=new VE;
			fscanf(f,"%s", &ds->dsve[j]->CMND);
			fscanf(f,"%d", &ds->dsve[j]->ghe_so);
			fscanf(f,"%s", &tt);
			xau_trung(tt,"false") ? ds->dsve[j]->tt=false : ds->dsve[j]->tt=true;
			//cout<<"trang thai la:"<<tt<<" thu tu:"<<i<<endl;
		}
		if(i==0){
			ds->next=dscb;
			dscb=ds;
		}else {
			PTR get;
			for(get=dscb;get->next!=NULL;get=get->next);
			get->next=ds->next;
			get->next=ds;
		}
		ds=ds->next;
	}
//	PTR get;
//	for(get=dscb;get!=NULL;get=get->next){
//		cout<<"so luong ve :"<<get->slve<<endl;
//		cout<<"so luong dat :"<<get->sldat<<endl;
//		cout<<"id cb:"<<get->data.machuyenbay<<endl;
//	}
	fclose (f);
	return 1;
}

void swap_char(char a[], char b[]){
	char temp[30];
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}

void insertionSort(char arr1[][5],char arr2[][16], int n)
{
   	int i, key, j;
	char temp [5];
   	for (i = 1; i < n; i++){
       	key = intValue(arr1[i]);
       	j = i-1;
       	while (j >= 0 && intValue(arr1[j]) < key){
       		swap_char(arr1[j+1],arr1[j]);
       		swap_char(arr2[j+1],arr2[j]);
           	j = j-1;
       	}
       	charValue(key,temp);
       	strcpy(arr1[j+1],temp);
   	}
}

void in_tk_mb(DSMB dsmb, int trang){
	char id_temp[dsmb.sl_mb][16];
	char sl_bay_temp[dsmb.sl_mb][5];
	for(int i=0; i<dsmb.sl_mb; i++){
		strcpy(id_temp[i],dsmb.data[i]->sohieumb);
		charValue(dsmb.data[i]->sl_bay,sl_bay_temp[i]);
	}
	insertionSort(sl_bay_temp,id_temp,dsmb.sl_mb);
	xoa_cn();
	normal_text();
	settextstyle(1,0,2);
	normal_box(1050,120,1230,155,"Thoat thong ke",f_vua,1,8);
	
	setfillstyle(1,12);
	bar3d(0,170,1270,210,0,0);
	setbkcolor(12);
	settextstyle(f_ds,0,1);
	
	outtextxy(8,178,"So hieu may bay");
	outtextxy(730,178,"So luot thuc hien chuyen bay");
	
	setbkcolor(8);
	setfillstyle(1,15);
	char trangso[4];
	charValue(trang,trangso);
	outtextxy(570,735,trangso);
	setbkcolor(15);
	bar3d(520,730,550,760,0,1);
	outtextxy(528,735,"<");
	bar3d(610,730,640,760,0,1);
	outtextxy(618,735,">");
	
	int dau = 212;int cuoi = dau+50;
	setfillstyle(1,15);
	setbkcolor(15);
	settextstyle(f_ds,0,1);
	int chisodau=(trang*10-10);
	
	for(int i=chisodau; i<dsmb.sl_mb && i<chisodau+10; i++){
		
		bar3d(0,dau,1270,cuoi,0,0);
		outtextxy(8,dau+8,id_temp[i]);
		outtextxy(730,dau+8,sl_bay_temp[i]);
			
		dau += 50;cuoi+=50;
		setbkcolor(15);
		setfillstyle(1,15);
	}
}

bool tim_cb_ds(CB cb, char nd[], char n[], char t[],char nam[]){
	bool ngay = (cb.time_xp.ngay!=intValue(n));
	bool thang = (cb.time_xp.thang!=intValue(t));
	bool nam_bool = (cb.time_xp.nam!=intValue(nam));
	bool check_nd=xau_trung(nd,cb.noiden);
	if(check_nd==false||ngay||thang||nam_bool) return false;
	return true;
}

void in_ds_tim(PTR dscb,char nd[], char n[], char t[],char nam[]){
	xoa_cn();
	normal_text();
	settextstyle(1,0,2);
	normal_box(1050,120,1230,155,"Thoat Tim",f_vua,1,8);
	
	setfillstyle(1,12);
	bar3d(0,170,1270,210,0,0);
	setbkcolor(12);
	settextstyle(f_ds,0,1);
	
	outtextxy(8,178,ds_cb[0]);
	outtextxy(160,178,ds_cb[1]);
	outtextxy(400,178,ds_cb[2]);
	outtextxy(570,178,ds_cb[3]);
	outtextxy(730,178,ds_cb[4]);
	outtextxy(880,178,"So ghe trong");
	
	int dau = 212;int cuoi = dau+50;
	setfillstyle(1,15);
	setbkcolor(15);
	settextstyle(f_ds,0,1);
	
	PTR p = dscb;
	char temp[15];
	int i;
	if(p==NULL);
	else{
		for(i = 0; (p!=NULL) ;p=p->next,i++){
			if(tim_cb_ds(p->data,nd,n,t,nam)){
				bar3d(0,dau,1270,cuoi,0,0);
				outtextxy(8,dau+8,p->data.machuyenbay);
				charTime(p->data.time_xp,temp);
				outtextxy(160,dau+8,temp);
				outtextxy(400,dau+8,p->data.noiden);
				charTTMB(p->data.trang_thai,temp);
				outtextxy(570,dau+8,temp);
				outtextxy(730,dau+8,p->data.sh_mb);
				charValue(p->slve-p->sldat,temp);
				outtextxy(880,dau+8,temp);
				
				dau += 50;cuoi+=50;
				setbkcolor(15);
				setfillstyle(1,15);
			}		
		}
	}	
}

void form_tim_cb(){
	xoa_cn();
	normal_text();
	setfillstyle(1,7);
	bar3d(300,200,950,600,0,1);
	normal_box(850,550,920,580," Tim",f_vua,2,3);
	normal_box(750,550,820,580,cn[3],f_vua,2,3);
	setbkcolor(7);
	settextstyle(f_lon,0,3);
	outtextxy(550,215,"Tim May Bay");
	settextstyle(f_vua,0,1);
	setfillstyle(1,15);
	outtextxy(500,270,"NOI DEN");
	bar3d(590,270-5,840,270+25,0,1);
	outtextxy(350,370,"Ngay");
	bar3d(400,370-5,460,370+25,0,1);
	outtextxy(540,370,"Thang");
	bar3d(600,370-5,660,370+25,0,1);
	outtextxy(750,370,"Nam");
	bar3d(790,370-5,870,370+25,0,1);
}

bool ktidmb_dscb(PTR dscb, char idmb[]){//dung la may bay du dk
	PTR get;
	for(get=dscb;get!=NULL;get=get->next){
		if(xau_trung(get->data.sh_mb,idmb)){
			if(get->data.trang_thai==1||get->data.trang_thai==2) return false;
		}
	}
	return true;
}


bool check_mbincb(PTR dscb,char idmb[]){ //dung la may bay chua co chuyen bay
	PTR get;
	
	for(get=dscb;get!=NULL;get=get->next){
		if(xau_trung(get->data.sh_mb,idmb)) return false;
	}
	return true;
}

void xoa_tbloi(){
	setfillstyle(1,8);
	bar(300,605,1200,750);
}

void themmb(DSMB &dsmb, char sh_temp[], char l_temp[], char sc_temp[]){
	dsmb.data[dsmb.sl_mb] = new MB;
	strcpy(dsmb.data[dsmb.sl_mb]->sohieumb,sh_temp);
	strcpy(dsmb.data[dsmb.sl_mb]->loaimaybay,l_temp);
	int sc = intValue(sc_temp);
	dsmb.data[dsmb.sl_mb]->socho = sc;
	dsmb.sl_mb++;
	reset_temp(sh_temp,l_temp,sc_temp);
}

void in_dskhincb(PTR dscb,TREE dskh,int trang,int chisocb,int &slkh){
	PTR get;
	int i;
	char temp[5];
	char time[15];
	for(get=dscb,i=0;i<chisocb;get=get->next,i++);
	
	xoa_cn();
	normal_text();
	settextstyle(1,0,2);
	outtextxy(20,110,"Danh Khach Thuoc Chuyen Bay");
	outtextxy(485,110,get->data.machuyenbay);
	normal_box(1050,120,1230,155,"Thoat Danh Sách",f_vua,1,8);
	normal_text();
	settextstyle(f_ds,0,1);
	outtextxy(20,140,"Ngay Gio Khoi Hanh :");
	charTime(get->data.time_xp,time);
	outtextxy(210,140,time);
	outtextxy(360,140,"Noi Den :");
	outtextxy(450,140,get->data.noiden);
	setbkcolor(12);
	setfillstyle(1,12);
	bar3d(0,170,1270,210,0,0);
	
	
	outtextxy(8,178,"So TT");
	outtextxy(120,178,"So VE");
	outtextxy(250,178,"So CMND");
	outtextxy(430,178,"Ho");
	outtextxy(680,178,"Ten");
	outtextxy(1150,178,"Phai");
	
	settextstyle(f_ds,0,1);
	setbkcolor(8);
	setfillstyle(1,15);
	char trangso[4];
	charValue(trang,trangso);
	outtextxy(570,735,trangso);
	setbkcolor(15);
	bar3d(520,730,550,760,0,1);
	outtextxy(528,735,"<");
	bar3d(610,730,640,760,0,1);
	outtextxy(618,735,">");
	
	int dau = 212;int cuoi = dau+50;
	setfillstyle(1,15);
	setbkcolor(15);
	settextstyle(f_ds,0,1);
	
	slkh=get->sldat;
	int chisodau=trang*10-10;
	
	for(int j=0; chisodau<get->sldat && j<10 ;j++,chisodau++){
		KH temp_kh=getKH(dskh,get->dsve[chisodau]->CMND);
		bar3d(0,dau,1270,cuoi,0,0);
		charValue(chisodau+1,temp);
		outtextxy(8,dau+8,temp);
		if(get->dsve[chisodau]->ghe_so==0) strcpy(temp,"0");
		else charValue(get->dsve[chisodau]->ghe_so,temp);
		outtextxy(120,dau+8,temp);
		outtextxy(250,dau+8,temp_kh.CMND);
		outtextxy(430,dau+8,temp_kh.Ho);
		outtextxy(680,dau+8,temp_kh.Ten);
		charPhai(temp_kh.Phai,temp);
		outtextxy(1150,dau+8,temp);
		dau+=50;cuoi+=50;
	}
}

void huy_ve(PTR &dscb,int chiso, int chisove, char cmnd[]){
	PTR get;
	int i;
	for(get=dscb,i=0;i<chiso;get=get->next,i++);
	for(int j =0; j<get->sldat;j++){
		if(xau_trung(get->dsve[j]->CMND,cmnd)) {
			get->dsve[j]->tt=false;
		}
	}
}

void datvekh(PTR &dscb,int chiso, int chisove, char cmnd[]){
	PTR get;
	int i;
	for(get=dscb,i=0;i<chiso;get=get->next,i++);
	get->dsve[get->sldat] = new VE;
	strcpy(get->dsve[get->sldat]->CMND,cmnd);
	get->dsve[get->sldat]->ghe_so=chisove;
	get->dsve[get->sldat]->tt=true;
	get->sldat++;
}

void indsv(PTR Frist, int chiso){
	xoa_cn();
	PTR get;
	int i;
	for(get=Frist,i=0;i<chiso;get=get->next,i++);
	char temp[4];
	normal_box(1100,700,1250,735,"THOAT DAT VE",f_vua,1,8);
	normal_text();
	settextstyle(f_ds,0,1);
	outtextxy(750,650,"TRANG:Chua Dat - DO:Da Dat - TIM:Da Huy Ve - XANH:Chon");
	setfillstyle(1,15);
	int l,r,t,b;
	l=20,r=55,t=70,b=100;
	//slv=get->slve;
	for(int i=0;i<get->slve;i++){
		if(i%25==0) {
			t+=50;
			b+=50;
			l=20;
			r=55;
		}
		bar3d(l,t,r,b,0,1);
		charValue(i,temp);
		setbkcolor(15);
		if(i==0)outtextxy(l+2,t+4,"0");
		else outtextxy(l+2,t+4,temp);
		
		l_ghe[i]=l;t_ghe[i]=t;r_ghe[i]=r;b_ghe[i]=b;
		//cout<<"\n"<<i<<" co: l="<<l<<" - r="<<r<<" - t="<<t<<" - b="<<b<<endl;
		tt_ghe[i]=0;
		l+=50;
		r+=50;
	}
	for(int i=0;i<get->sldat;i++){
		if(get->dsve[i]->tt){
			setfillstyle(1,12);
			bar3d(l_ghe[get->dsve[i]->ghe_so],t_ghe[get->dsve[i]->ghe_so],r_ghe[get->dsve[i]->ghe_so],b_ghe[get->dsve[i]->ghe_so],0,1);
			charValue(get->dsve[i]->ghe_so,temp);
			setbkcolor(12);
			if(get->dsve[i]->ghe_so==0)outtextxy(l_ghe[get->dsve[i]->ghe_so]+2,t_ghe[get->dsve[i]->ghe_so]+4,"0");
			else outtextxy(l_ghe[get->dsve[i]->ghe_so]+2,t_ghe[get->dsve[i]->ghe_so]+4,temp);
			tt_ghe[get->dsve[i]->ghe_so]=1;
		}
		else{
			setfillstyle(1,9);
			bar3d(l_ghe[get->dsve[i]->ghe_so],t_ghe[get->dsve[i]->ghe_so],r_ghe[get->dsve[i]->ghe_so],b_ghe[get->dsve[i]->ghe_so],0,1);
			charValue(get->dsve[i]->ghe_so,temp);
			setbkcolor(9);
			if(get->dsve[i]->ghe_so==0)outtextxy(l_ghe[get->dsve[i]->ghe_so]+2,t_ghe[get->dsve[i]->ghe_so]+4,"0");
			else outtextxy(l_ghe[get->dsve[i]->ghe_so]+2,t_ghe[get->dsve[i]->ghe_so]+4,temp);
			tt_ghe[get->dsve[i]->ghe_so]=2;
		}
	}
	
}

KH getKH(TREE t, char cmnd[]){
	if(xau_trung(t->data.CMND,cmnd)) return t->data;
	else if(intValue(t->data.CMND)>intValue(cmnd)) return (getKH(t->left,cmnd));
	else if(intValue(t->data.CMND)<intValue(cmnd)) return (getKH(t->right,cmnd));
}

void formkhve(TREE t, char cmnd[],int x, int y){
	xoa_cn();
	normal_text();
	setfillstyle(1,7);
	bar3d(300,200,950,600,0,1);
	normal_box(850,550,920,580,cn[2],f_vua,2,3);
	normal_box(750,550,820,580,cn[3],f_vua,2,3);
	setbkcolor(7);
	settextstyle(f_lon,0,3);
	outtextxy(450,215,"Kiem Tra Khach Hang");
	settextstyle(f_vua,0,1);
	setfillstyle(1,15);
	outtextxy(310,270,"CMND");
	bar3d(360,270-5,580,270+25,0,1);
	outtextxy(650,270,"HO");
	bar3d(690,270-5,940,270+25,0,1);
	outtextxy(310,370,"TEN");
	bar3d(350,370-5,940,370+25,0,1);
	outtextxy(310,470,"GIOI TINH");
	normal_text();
	KH temp = getKH(t,cmnd);
	setbkcolor(15);
	outtextxy(368,270,temp.CMND);
	outtextxy(698,270,temp.Ho);
	outtextxy(358,370,temp.Ten);
	if(temp.Phai) {
		bar3d(450,470-5,500,470+25,0,1);
		outtextxy(458,470,"NAM");
	}else{
		bar3d(550,470-5,600,470+25,0,1);
		outtextxy(558,470,"NU");
	}
}


int ktrtime(char ngay[], char thang[], char nam_t[]){
	//1:khong ton tai ngay
	//2:thoi gian trong ngay hoac ve qua khu
	//3:vuot qua 2 thang so voi luc dat ve
	//0:dung
	int n =intValue(ngay);
	int t =intValue(thang);
	int nam =intValue(nam_t);
	int max_day_dich[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int max_day_hientai[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	//tao 1 TIME có du lieu là thoi gian hien tai
	time_t now = time(0);
	tm *ltm = localtime(&now);
	TIME baygio;
	baygio.ngay=ltm->tm_mday;
	baygio.thang=1+ltm->tm_mon;
	baygio.nam=1900+ltm->tm_year;
	
	//nam nhuan la nam chia het cho 400 hoac chia het cho 4 va ko chia het cho 100
	if(nam%400==0 ||(nam%4==0 && nam%100!=0)){
		max_day_dich[2]=29;
	}
	if(baygio.nam%400==0 ||(baygio.nam%4==0 && baygio.nam%100!=0)){
		max_day_hientai[2]=29;
	}
	if(n>max_day_dich[t]) return 1;
	else if(n<=0||t<=0||nam<=0) return 1;
	//check chuan don vi ngay:
//	int kc_ngay=0;
//	if((nam-baygio.nam)>1) return 3;
//	else if((nam-baygio.nam)<0) return 2;
//	else if((nam-baygio.nam)==0&&(t-baygio.thang)<0) return 2;
//	else if(((nam-baygio.nam)==0&&(t-baygio.thang)==0)&&(n-baygio.ngay)<1) return 2;//truoc 1 ngay
//	else if(((nam-baygio.nam)==0&&(t-baygio.thang)==0)) kc_ngay=n-baygio.ngay;
//	else{
//		int man_step=baygio.nam;
//		int thang_step=baygio.thang;
//		//int ngay_step=baygio.ngay;
//		int i;
//		kc_ngay-=baygio.ngay;
//		for(i=thang_step;i!=t||i!=13;i++){
//			kc_ngay+=max_day_hientai[i];
//		}
//		if(i==13){
//			for(i=1;i!=t;i++){
//				kc_ngay+=max_day_dich[i];
//			}
//		}
//		kc_ngay+=n;
//	}
	
	//check chuan don vi thang:
	int kq;
	kq = ((nam-baygio.nam)*365) + ((t-baygio.thang)*30) + (n-baygio.ngay);
	//kt trong ngay va qua khu
	if(kq<1) return 2;
	
	//kt khoang cach 2 thang
	if (kq>60) return 3;
	
	return 0;
}

void charTTMB(int ma, char s[]){
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

void charTime(TIME t, char s[]){
	s[0]='\0';
	char temp[10];
	char ngan[2]="/";//ngan cac ngay
	char hc[2]=":";//hai cham
	char kc[2]=" ";//khoang cach gioi ngay
	charValue(t.gio,temp);
	strcat(s,temp);
	strcat(s,hc);
	if(t.phut==0) strcpy(temp,"0");
	else charValue(t.phut,temp);
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

void in_ds_cb(PTR dscb,int trang){
	xoa_cn();
	normal_text();
	settextstyle(1,0,2);
	outtextxy(20,120,"Danh Sach Chuyen Bay");
	normal_box(800,120,980,155,"Tim Chuyen Bay",f_vua,1,8);
	normal_box(1050,120,1230,155,"Them Chuyen Bay",f_vua,1,8);
	
	settextstyle(f_ds,0,1);
	setbkcolor(8);
	setfillstyle(1,15);
	char trangso[4];
	charValue(trang,trangso);
	outtextxy(570,735,trangso);
	setbkcolor(15);
	bar3d(520,730,550,760,0,1);
	outtextxy(528,735,"<");
	bar3d(610,730,640,760,0,1);
	outtextxy(618,735,">");
	
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
	
	for(int i=0; i<10;i++){
		l_scb[i]=0;t_scb[i]=0;r_scb[i]=0;b_scb[i]=0;
		l_hcb[i]=0;t_hcb[i]=0;r_hcb[i]=0;b_hcb[i]=0;
		l_dv[i]=0;t_dv[i]=0;r_dv[i]=0;b_dv[i]=0;
		l_dsv[i]=0;t_dsv[i]=0;r_dsv[i]=0;b_dsv[i]=0;
	}
	
	PTR p = dscb;
	char temp[20];
	int i;
	int chisodau=(trang*10-10);
	for(int i=0;i<chisodau;p=p->next,i++);
	if(p==NULL);
	else{
		for(i = 0; p!=NULL && i<10 ;p=p->next,i++){
			//cout<<"gia tri i:"<<i<<endl;
			bar3d(0,dau,1270,cuoi,0,0);
			outtextxy(8,dau+8,p->data.machuyenbay);
			charTime(p->data.time_xp,temp);
			outtextxy(160,dau+8,temp);
			outtextxy(400,dau+8,p->data.noiden);
			charTTMB(p->data.trang_thai,temp);
			outtextxy(570,dau+8,temp);
			outtextxy(730,dau+8,p->data.sh_mb);
			normal_box(880,dau+12,930,cuoi-8,"Sua",f_ds,1,4);
			l_scb[i]=880;t_scb[i]=dau+12;r_scb[i]=930;b_scb[i]=cuoi-8;
			normal_box(950,dau+12,1000,cuoi-8,"Huy",f_ds,1,4);
			l_hcb[i]=950;t_hcb[i]=dau+12;r_hcb[i]=1000;b_hcb[i]=cuoi-8;
			normal_box(1020,dau+12,1090,cuoi-8,"Dat Ve",f_ds,1,4);
			l_dv[i]=1020;t_dv[i]=dau+12;r_dv[i]=1090;b_dv[i]=cuoi-8;
			normal_box(1110,dau+12,1250,cuoi-8,"Danh sach Ve",f_ds,1,4);
			l_dsv[i]=1110;t_dsv[i]=dau+12;r_dsv[i]=1250;b_dsv[i]=cuoi-8;
			
			dau += 50;cuoi+=50;
			setbkcolor(15);
			setfillstyle(1,15);
			
		}
	}	
}

void charPhai(bool phai, char s[]){
	switch(phai){
		case true: {
			strcpy(s,"NAM");
		}break;
		
		case false: {
			strcpy(s,"NU");
		}break;
	}
}

void in_NLR(TREE t, int &dau, int &cuoi, int &i,int chisodau)
{
	if(t!=NULL && i<chisodau+10)
	{
		if(i<chisodau) {
			i++;
			in_NLR(t->left,dau,cuoi,i,chisodau);
			in_NLR(t->right,dau,cuoi,i,chisodau);
		}
		else{
			bar3d(0,dau,1270,cuoi,0,0);
			outtextxy(8,dau+8,t->data.CMND);
			outtextxy(150,dau+8,t->data.Ho);
			outtextxy(350,dau+8,t->data.Ten);
			char temp_phai[5];
			charPhai(t->data.Phai,temp_phai);
			outtextxy(800,dau+8,temp_phai);
			t->n=i;
			dau += 50;cuoi+=50;
			i++;
			setbkcolor(15);
			setfillstyle(1,15);
			
			in_NLR(t->left,dau,cuoi,i,chisodau);
			in_NLR(t->right,dau,cuoi,i,chisodau);
		}
			
	}
}

void in_dskh(TREE ds,int trang){
	xoa_cn();
	normal_text();
	settextstyle(1,0,2);
	outtextxy(20,120,"Danh Sach Khach Hang");
	normal_box(1050,120,1230,155,"Them Khach Hang",f_vua,1,8);
	
	setfillstyle(1,12);
	bar3d(0,170,1270,210,0,0);
	setbkcolor(12);
	settextstyle(f_ds,0,1);
	
	outtextxy(8,178,"CMND");
	outtextxy(150,178,"HO");
	outtextxy(350,178,"TEN");
	outtextxy(800,178,"PHAI");
	//outtextxy(900,178,"Chuc Nang");
	
	settextstyle(f_ds,0,1);
	setbkcolor(8);
	setfillstyle(1,15);
	char trangso[4];
	charValue(trang,trangso);
	outtextxy(570,735,trangso);
	setbkcolor(15);
	bar3d(520,730,550,760,0,1);
	outtextxy(528,735,"<");
	bar3d(610,730,640,760,0,1);
	outtextxy(618,735,">");
	
	int dau = 212;int cuoi = dau+50;
	setfillstyle(1,15);
	setbkcolor(15);
	settextstyle(f_ds,0,1);
	
	int chisodau=trang*10-10;
	int i=0;
	in_NLR(ds,dau,cuoi,i,chisodau);
}

void them_1_kh(TREE &t, char cmnd[], char ho[], char ten[], bool phai)
{
	if(t== NULL)
	{
		TREE p = new nodeKH;
		strcpy(p->data.CMND,cmnd);
		strcpy(p->data.Ho,ho);
		strcpy(p->data.Ten,ten);
		p->data.Phai=phai;
		p->left = NULL;
		p->right = NULL;
		t = p;
	}
	else
	{
		if(intValue(t->data.CMND) > intValue(cmnd))
		{
			them_1_kh(t->left,cmnd,ho,ten,phai);
		}
		else if(intValue(t->data.CMND) < intValue(cmnd))
		{
			them_1_kh(t->right,cmnd,ho,ten,phai);
		}
	}
}

void getTime(PTR Frist, int chiso, char g[], char p[], char n[], char t[], char nam[]){
	PTR get;
	//cout<<"da qua khai bao";
	int i;
	for(get=Frist,i=0;i<chiso;get=get->next,i++);
	charValue(get->data.time_xp.gio,g);
	charValue(get->data.time_xp.phut,p);
	charValue(get->data.time_xp.ngay,n);
	charValue(get->data.time_xp.thang,t);
	charValue(get->data.time_xp.nam,nam);
}

void getidcb(PTR Frist, int chiso, char id[]){
	PTR get;
	int i;
	for(get=Frist,i=0;i<chiso;get=get->next,i++);
	strcpy(id,get->data.machuyenbay);
}

void setTime(PTR Frist, int chiso, char g[], char p[], char n[], char t[], char nam[]){
	PTR set;
	int i;
	for(set=Frist, i=0; i<chiso; set=set->next,i++);
	set->data.time_xp.gio=intValue(g);
	set->data.time_xp.phut=intValue(p);
	set->data.time_xp.ngay=intValue(n);
	set->data.time_xp.thang=intValue(t);
	set->data.time_xp.nam=intValue(nam);
}

void sethuyCB(PTR Frist, int chiso){
	PTR set;
	int i;
	for(set=Frist, i=0; i<chiso; set=set->next,i++);
	set->data.trang_thai=0;
}

int ktslcb(PTR Frist){
	PTR p;
	int i;
	for(p=Frist, i=0; p!=NULL; p=p->next,i++);
	return i;
}

bool ktscb(int &start, int slpt, int x, int y){
	for(int i=0; i<slpt; i++){
		if(ktrVT(l_scb[i],t_scb[i],r_scb[i],b_scb[i],x,y)){
			start+=i;
			return true;
		}
	}
	return false;
}

bool kthcb(int &start, int slpt, int x, int y){
	for(int i=0; i<slpt; i++){
		if(ktrVT(l_hcb[i],t_hcb[i],r_hcb[i],b_hcb[i],x,y)){
			start+=i;
			return true;
		}
	}
	return false;
}

bool ktdsve(int &start,int slpt,int x, int y){
	for(int i=0; i<slpt; i++){
		if(ktrVT(l_dsv[i],t_dsv[i],r_dsv[i],b_dsv[i],x,y)){
			start+=i;
			return true;
		}
	}
	return false;
}

bool ktdve(int &start, int slpt, int x, int y){
	for(int i=0; i<slpt; i++){
		if(ktrVT(l_dv[i],t_dv[i],r_dv[i],b_dv[i],x,y)){
			start+=i;
			return true;
		}
	}
	return false;
}

bool ktvtve(PTR dscb,int chiso,int &chisove,int x,int y){
	char temp[4];
	settextstyle(f_ds,0,1);
	PTR get;
	int i;
	for(get=dscb,i=0;i<chiso;get=get->next,i++);
	//cout<<"i :"<<i<<endl;
	int slve=get->slve;
	//cout<<"ten cb:"<<get->data.machuyenbay<<endl;
	//cout<<"so luong ghe :"<<slve;
	for(int i = 0;i<slve;i++){
		//cout<<i<<endl;
		if(ktrVT(l_ghe[i],t_ghe[i],r_ghe[i],b_ghe[i],x,y)){
			chisove+=i;
			setfillstyle(1,10);
			bar3d(l_ghe[i],t_ghe[i],r_ghe[i],b_ghe[i],0,1);
			charValue(i,temp);
			setbkcolor(10);
			if(i==0)outtextxy(l_ghe[i]+2,t_ghe[i]+4,"0");
			else outtextxy(l_ghe[i]+2,t_ghe[i]+4,temp);
			return true;
		}
	}
	return false;
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
	outtextxy(400,215,"Them Chuyen Bay");
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

void form_kh(){
	xoa_cn();
	normal_text();
	setfillstyle(1,7);
	bar3d(300,200,950,600,0,1);
	normal_box(850,550,920,580,cn[2],f_vua,2,3);
	normal_box(750,550,820,580,cn[3],f_vua,2,3);
	setbkcolor(7);
	settextstyle(f_lon,0,3);
	outtextxy(450,215,"Them Khach Hang");
	settextstyle(f_vua,0,1);
	setfillstyle(1,15);
	outtextxy(310,270,"CMND");
	bar3d(360,270-5,580,270+25,0,1);
	outtextxy(650,270,"HO");
	bar3d(690,270-5,940,270+25,0,1);
	outtextxy(310,370,"TEN");
	bar3d(350,370-5,940,370+25,0,1);
	outtextxy(310,470,"GIOI TINH");
	bar3d(450,470-5,500,470+25,0,1);
	bar3d(550,470-5,600,470+25,0,1);
	setbkcolor(15);
	outtextxy(458,470,"NAM");
	outtextxy(558,470,"NU");
	normal_text();
}


void form_scb(){
	xoa_cn();
	normal_text();
	setfillstyle(1,7);
	bar3d(300,200,950,600,0,1);
	normal_box(850,550,920,580,cn[2],f_vua,2,3);
	normal_box(750,550,820,580,cn[3],f_vua,2,3);
	setbkcolor(7);
	settextstyle(f_lon,0,3);
	outtextxy(500,215,"Hieu Chinh Thoi Gian");
	settextstyle(f_vua,0,1);
	setfillstyle(1,15);
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
}

void from_huy(char s[]){
	xoa_cn();
	normal_text();
	setfillstyle(1,7);
	bar3d(300,200,950,600,3,1);
	normal_box(850,550,920,580,cn[4],f_vua,2,3);
	normal_box(750,550,820,580,cn[3],f_vua,2,3);
	setbkcolor(7);
	settextstyle(f_lon,0,4);
	char char_temp[20]="BAN CO MUON HUY";
	outtextxy(350,215,char_temp);
	outtextxy(450,315,s);
	char char_t[20]="KHONG ???";
	outtextxy(400,415,char_t);
}



int getslchoMB(DSMB ds, char sh[]){
	for(int i = 0; i<ds.sl_mb; i++){
		if(xau_trung(ds.data[i]->sohieumb,sh)){
			return ds.data[i]->socho;
		}
	}
	return -1;
}

void tangsl_bay(DSMB dsmb, char sh_mb[]){
	int i;
	for(i=0; i<dsmb.sl_mb;i++){
		if(xau_trung(sh_mb,dsmb.data[i]->sohieumb)) break;
	}
	dsmb.data[i]->sl_bay++;
}

void them_CB(PTR &Frist,DSMB dsmb,char shcb[],char nd[],char shmb[],char g[],char p[],char n[],char t[],char nam[]){
	PTR them = new nodeCB;
	strcpy(them->data.machuyenbay,shcb);
	strcpy(them->data.noiden,nd);			    			
	strcpy(them->data.sh_mb,shmb);
	//cout<<"gia tri t_temp:"<<t_temp;	    			
	them->data.time_xp.gio=intValue(g);
	them->data.time_xp.phut=intValue(p);
	them->data.time_xp.ngay=intValue(n);
	them->data.time_xp.thang=intValue(t);
	them->data.time_xp.nam=intValue(nam);
	them->sldat=0;
	them->slve=getslchoMB(dsmb,shmb);
	tangsl_bay(dsmb,shmb);
	them->next=Frist;
	//cout<<"so luong ve :"<<them->slve<<endl;
	Frist=them;
	//cout<<"da qua duoc them ve.."<<endl;
}

void getcmndghe(PTR Frist,int chisocb, int chisoghe, char temp[]){
	PTR get;
	int i;
	for(get=Frist,i=0;i<chisocb;get=get->next,i++);
	for(int i=0; i<get->sldat; i++){
		if(get->dsve[i]->ghe_so==chisoghe){
			strcpy(temp,get->dsve[i]->CMND);
		}
	}
}

void themve(PTR &Frist,int chisocb, int chisoghe, char temp[]){
	PTR get;
	int i;
	for(get=Frist,i=0;i<chisocb;get=get->next,i++);
	get->dsve[get->sldat]= new VE;
	(get->sldat)++;
	for(int i=0; i<get->sldat; i++){
		if(get->dsve[i]->ghe_so==chisoghe){
			strcpy(get->dsve[i]->CMND,temp);
		}
	}
}


bool checkCMND (TREE t, char s[]){
	cout<<"cmnd la:"<<t->data.CMND;
	if(t==NULL) return false;
	else if(xau_trung(t->data.CMND,s)) return true;
	else if(intValue(t->data.CMND)>intValue(s)) return (checkCMND(t->left,s));
	else if(intValue(t->data.CMND)<intValue(s)) return (checkCMND(t->right,s));
}

int checkCMNDdatve(PTR dscb,int chiso,TREE dskh,char s[]){ //0 la khong ton tai trong ve vs dskh-1 la ca ve vs dskh - 2ton tai trong dskh ma ko trong ve 
	if(checkCMND(dskh,s)==false) return 0;
	else if(checkCMND(dskh,s)){
		//cout<<"cmnd trong kt :"<<s;
		PTR get;
		int i;
		for(get=dscb,i=0;i<chiso;get=get->next,i++);
		for(int j=0;j<get->sldat;j++){
			//cout<<"cmnd trong cb:"<<get->dsve[j]->CMND<<endl;
			if(xau_trung(get->dsve[j]->CMND,s)==true) return 1;
		}
	}
	return 2;
}


void in_ghe(int chisoghe, char temp[]){
	int chon = tt_ghe[chisoghe];
	switch(chon){
		
		case 0:{
			normal_text();
			setfillstyle(1,7);
			bar3d(0,600,730,760,0,1);
			normal_box(620,715,710,745,"DAT VE",f_vua,2,3);
			normal_box(500,715,580,745,"THOAT",f_vua,2,3);
			setbkcolor(7);
			outtextxy(80,630,"Nhap CMND");
			setfillstyle(1,15);
			bar3d(200,630-5,610,630+25,0,1);
			setbkcolor(15);
			
		}break;
		
		case 1:{
			normal_text();
			setfillstyle(1,7);
			bar3d(0,600,730,760,0,1);
			normal_box(620,715,710,745,"HUY VE",f_vua,2,3);
			normal_box(500,715,580,745,"THOAT",f_vua,2,3);
			setbkcolor(7);
			outtextxy(80,630,"CMND");
			setfillstyle(1,15);
			bar3d(200,630-5,610,630+25,0,1);
			setbkcolor(15);
			outtextxy(208,630,temp);
		}break;
		
		case 2:{
			normal_text();
			setfillstyle(1,7);
			bar3d(0,600,730,760,0,1);
			highlight_box(600,715,720,745,"VE DA HUY",f_vua,2,0);
			normal_box(500,715,580,745,"THOAT",f_vua,2,3);
			setbkcolor(7);
			outtextxy(80,630,"CMND");
			setfillstyle(1,15);
			bar3d(200,630-5,610,630+25,0,1);
			setbkcolor(15);
			outtextxy(208,630,temp);
		}break;
	}
}

bool xau_trung(char a[],char b[]){
  int i=0;
  while(a[i]!='\0' || b[i]!='\0'){
    if(a[i]!=b[i]){
      return false;
      
     // break;
    }
    i++;
  }
  return true;
}


bool ktrMB(DSMB &ds, char sh[], bool them, int chiso){
	int so_lan=0;
	for(int i = 0; i<ds.sl_mb; i++){
		if(xau_trung(ds.data[i]->sohieumb,sh)) so_lan++;
		//cout<<"trung : "<<i<<endl;
	}
	//cout<<"so lan :"<<so_lan<<endl;
	if(them) return ((so_lan==0) ? true : false);
	else{
		if(xau_trung(ds.data[chiso]->sohieumb,sh)) so_lan--;
	 	return ((so_lan==0) ? true : false);
	}
}


void reset_temp(char temp1[], char temp2[], char temp3[]){
	temp1[0]='\0';
	temp2[0]='\0';
	temp3[0]='\0';
}

bool ktrVT(int l, int t, int r, int b, int x, int y){
	if((x>=l)&&(x<=r)&&(y>=t)&&(y<=b)) return true;
	else return false;
}

void normal_box(int l, int t, int r, int b, char s[], int font, int f_size, int kc){
	setfillstyle(1,11);
    bar3d(l,t,r,b,8,1);
    setbkcolor(11);
    settextstyle(font,0,f_size);
    outtextxy(l+8,t+kc,s);
}


void highlight_box(int l, int t, int r, int b, char s[], int font, int f_size, int kc){
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
	setbkcolor(7);
	bar(1090,5,1270,33);
	settextstyle(f_vua,0,2);
	outtextxy(1100,8,"THOAT UNG DUNG");
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

void charValue(int x, char s[]){
	if(x==0){
		strcpy(s,"0");
		return;
	}
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

int LoadFileMB (char tenfile[] , DSMB &ds) {
	FILE *f;
	f=fopen(tenfile,"rt");
	if (f==NULL) return 0;
	char tt[10];
	fscanf(f,"%d ", &ds.sl_mb);
	fscanf(f,"\n");
	for ( int i=0 ; i<ds.sl_mb ; i++){
		ds.data[i] = new MB;
		fscanf(f,"%s", &ds.data[i]->sohieumb);
		fscanf(f,"%s", &ds.data[i]->loaimaybay);
		fscanf(f,"%d", &ds.data[i]->socho);
		fscanf(f,"%d", &ds.data[i]->sl_bay);
		fscanf(f,"%s", &tt);
		xau_trung(tt,"false") ? ds.data[i]->tt=false : ds.data[i]->tt=true;
		fscanf(f,"\n");
	}
	fclose (f);
	return 1;
}

int SaveFile_MB (char tenfile[] , DSMB &ds) {
	FILE *f;
	f=fopen(tenfile,"wt");
	if (f==NULL) return 0;
	
	fprintf(f,"%d ", ds.sl_mb);
	
	fprintf(f,"\n");
	bool trangthai; 
	for ( int i=0 ; i<ds.sl_mb ; i++){
		trangthai=ds.data[i]->tt;
		fprintf(f,"%50s", ds.data[i]->sohieumb);
		fprintf(f,"%50s", ds.data[i]->loaimaybay);
		fprintf(f,"%50d", ds.data[i]->socho);
		fprintf(f,"%50d", ds.data[i]->sl_bay);
		fprintf(f,"%50s", trangthai ? "true" : "false");
		fprintf(f,"\n");
	}
	fclose (f);
	cout << "Da ghi xong day so"; return 1;
}


void in_ds_mb(DSMB &dsmb, char ds[][20],int trang){
	int sl_ptuDS = 4;
	char sc_temp[5]={'\0'};
	
	xoa_cn();
	normal_text();
	settextstyle(f_ds,0,2);
	outtextxy(20,120,box1[0]);
	normal_box(800,120,1000,155,"Thong ke bay may",f_vua,1,8);
	normal_box(1050,120,1200,155,box1[1],f_vua,1,8);
	
	settextstyle(f_ds,0,1);
	setbkcolor(8);
	setfillstyle(1,15);
	char trangso[4];
	charValue(trang,trangso);
	outtextxy(570,735,trangso);
	setbkcolor(15);
	bar3d(520,730,550,760,0,1);
	outtextxy(528,735,"<");
	bar3d(610,730,640,760,0,1);
	outtextxy(618,735,">");
	
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
	int chisodau=(trang*10-10);
	
	for(int i=0; i<10;i++){
		left1[i]=0;top1[i]=0;right1[i]=0;bottom1[i]=0;
		left2[i]=0;top2[i]=0;right2[i]=0;bottom2[i]=0;
	}
	
	for(int k=0; chisodau<dsmb.sl_mb && k<10; chisodau++,k++){
		int j =8;
		bar3d(0,dau,1270,cuoi,0,0);
		outtextxy(j,dau+8,dsmb.data[chisodau]->sohieumb);
		j+=(1270/sl_ptuDS+20);
		outtextxy(j,dau+8,dsmb.data[chisodau]->loaimaybay);
		j+=(1270/sl_ptuDS+20);
		charValue(dsmb.data[chisodau]->socho,sc_temp);
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

void form_mb(char ten[]){//form dien them may bay / normal 3 - hightline 0
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

int intValue(char  s[]){
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

void nhap(int l, int t, int r, int b, int max, int min, int loai, char output[], int &x, int &y){//l,t,r,b
	if(ktrVT(l,t,r,b,x,y)){
		settextstyle(f_vua,0,1);
		setfillstyle(1,10);
		bar3d(l,t,r,b,0,1);
		setbkcolor(10);
		char nhap[2] = "_";
		char temp[50];
		int step = strlen(output);
		strcpy(temp,output);
		strcat(temp,nhap);
		outtextxy(l+10,t+5,temp);
		bool ktmax=true;
		bool ktmin=false;
		int x1,y1;
		switch(loai){
			case ID:{
				while(true){
					if(kbhit()){
						if (ismouseclick(WM_LBUTTONDOWN)){
    						getmouseclick(WM_LBUTTONDOWN,x1,y1);
    						x1=0;y1=0;
						}
						char key = getch();
						if(key==8){ //nut backspace
							step--;
							temp[step]=95;//_
							temp[step+1]='\0';
							bar3d(l,t,r,b,0,1);
							outtextxy(l+10,t+5,temp);
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
						if(key==13&&ktmax&&ktmin){//nut  enter
							temp[step]='\0';
							settextstyle(f_vua,0,1);
							setfillstyle(1,15);
							bar3d(l,t,r,b,0,1);
							setbkcolor(15);
							outtextxy(l+10,t+5,temp);
							strcpy(output,temp);
							normal_text();
							break;
						}
					}
				}		
			}
			break;
			case So:{
				int gt;//gia tri
				while(true){
					if(kbhit()){
						if (ismouseclick(WM_LBUTTONDOWN)){
    						getmouseclick(WM_LBUTTONDOWN,x1,y1);
    						x1=0;y1=0;
						}
						char key = getch();
						
						if(key==8){ //nut backspace
							step--;
							temp[step]=95;//_
							temp[step+1]='\0';
							bar3d(l,t,r,b,0,1);
							outtextxy(l+10,t+5,temp);
							//gt=intValue(temp);
						}
						else if(ktrKyTu(key,false,false,true)&&ktmax&&gt>=0){
							//if(temp[1]=='\0'&&key=='0');//loai so 0 o dau
							if(temp[2]=='\0'&&temp[0]=='0'&&key=='0');
							else{
								temp[step]=key;
								step++;
								temp[step]=95;
								temp[step+1]='\0';
								outtextxy(l+10,t+5,temp);
								//gt=intValue(temp);
								//cout<<"da vo check"<<endl;
							}
							
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
						
						if(key==13&&ktmax&&ktmin){//nut  enter
							temp[step]='\0';
							settextstyle(f_vua,0,1);
							setfillstyle(1,15);
							bar3d(l,t,r,b,0,1);
							setbkcolor(15);
							outtextxy(l+10,t+5,temp);
							strcpy(output,temp);
							normal_text();
							break;
						}
					}
				}
			}
			break;
			case Ten:{
				while(true){
						
					if(kbhit()){
						if (ismouseclick(WM_LBUTTONDOWN)){
    						getmouseclick(WM_LBUTTONDOWN,x1,y1);
    						x1=0;y1=0;
						}
						char key = getch();
						if(key==8){ //nut backspace
							step--;
							temp[step]=95;//_
							temp[step+1]='\0';
							bar3d(l,t,r,b,0,1);
							outtextxy(l+10,t+5,temp);
						}
						else if(ktrKyTu(key,true,true,false)&&ktmax){
							if((key==' '&&temp[step-1]==' ')||(key==' '&&temp[1]=='\0'));
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
							setfillstyle(1,10);
							if(step<=max) ktmax= true;
							if(step>=min) ktmin = true;
						}
						cout<<"temp la :"<<temp<<endl;
						cout<<"key la :"<<key<<endl;
						
						if(key==13&&ktmax&&ktmin){//nut  enter
							if(temp[step-1]==' ') temp[--step]='\0'; //xoa dau space o cuoi
							else temp[step]='\0';
							settextstyle(f_vua,0,1);
							setfillstyle(1,15);
							bar3d(l,t,r,b,0,1);
							setbkcolor(15);
							outtextxy(l+10,t+5,temp);
							strcpy(output,temp);
							normal_text();
							break;
						}
					}
				}
			}
			break;
			case CMVE:{
				while(true){
					if(kbhit()){
						if (ismouseclick(WM_LBUTTONDOWN)){
    						getmouseclick(WM_LBUTTONDOWN,x1,y1);
    						x1=0;y1=0;
						}
						char key = getch();
						if(key==8){ //nut backspace
							step--;
							temp[step]=95;//_
							temp[step+1]='\0';
							bar3d(l,t,r,b,0,1);
							outtextxy(l+10,t+5,temp);
						}
						
						else if(ktrKyTu(key,false,false,true)&&ktmax){
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
							bar(200,b+5,710,b+30);
							setfillstyle(1,10);
							if(step<=max) ktmax= true;
							if(step>=min) ktmin = true;
						}
						cout<<"temp la :"<<temp<<endl;
						cout<<"key la :"<<key<<endl;
						if(key==13&&ktmax&&ktmin){//nut  enter
							temp[step]='\0';
							settextstyle(f_vua,0,1);
							setfillstyle(1,15);
							bar3d(l,t,r,b,0,1);
							setbkcolor(15);
							outtextxy(l+10,t+5,temp);
							strcpy(output,temp);
							normal_text();
							break;
						}
					}
				}		
			}break;
			case CMND:{
				while(true){
					if(kbhit()){
						if (ismouseclick(WM_LBUTTONDOWN)){
    						getmouseclick(WM_LBUTTONDOWN,x1,y1);
    						x1=0;y1=0;
						}
						char key = getch();
						if(key==8){ //nut backspace
							step--;
							temp[step]=95;//_
							temp[step+1]='\0';
							bar3d(l,t,r,b,0,1);
							outtextxy(l+10,t+5,temp);
						}
						
						else if(ktrKyTu(key,false,false,true)&&ktmax){
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
						if(key==13&&ktmax&&ktmin){//nut  enter
							temp[step]='\0';
							settextstyle(f_vua,0,1);
							setfillstyle(1,15);
							bar3d(l,t,r,b,0,1);
							setbkcolor(15);
							outtextxy(l+10,t+5,temp);
							strcpy(output,temp);
							normal_text();
							break;
						}
					}
				}		
			}
			break;
			case Ho:{
				while(true){
						
					if(kbhit()){
						if (ismouseclick(WM_LBUTTONDOWN)){
    						getmouseclick(WM_LBUTTONDOWN,x1,y1);
    						x1=0;y1=0;
						}
						char key = getch();
						if(key==8){ //nut backspace
							step--;
							temp[step]=95;//_
							temp[step+1]='\0';
							bar3d(l,t,r,b,0,1);
							outtextxy(l+10,t+5,temp);
						}
						
						else if(ktrKyTu(key,false,true,false)&&ktmax){
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
						
						if(key==13&&ktmax&&ktmin){//nut  enter
							if(temp[step-1]==' ') temp[--step]='\0'; //xoa dau space o cuoi
							else temp[step]='\0';
							settextstyle(f_vua,0,1);
							setfillstyle(1,15);
							bar3d(l,t,r,b,0,1);
							setbkcolor(15);
							outtextxy(l+10,t+5,temp);
							strcpy(output,temp);
							normal_text();
							break;
						}
					}
				}
			}
		}
	}
}

bool ktSua(int &start, int slpt, int x, int y){
	for(int i=0; i<slpt; i++){
		if(ktrVT(left1[i],top1[i],right1[i],bottom1[i],x,y)){
			start+=i;
			return true;
		}
	}
	return false;
}

bool ktXoa(int &start, int slpt, int x, int y){
	for(int i=0; i<slpt; i++){
		if(ktrVT(left2[i],top2[i],right2[i],bottom2[i],x,y)){
			start+=i;
			return true;
		}
	}
	return false;
}

void from_xoa(char s[]){
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
