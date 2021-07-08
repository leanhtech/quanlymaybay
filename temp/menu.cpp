#include "mylib.h"

const int so_item = 4;
const int cot_menu = 1;
const int dong_menu = 7;
const int Up = 72;
const int Down = 80;
const int Right = 77;
const int Left = 75;
const int Esc = 27;
const int item_MB = 3;
const int item_CB = 5;
const int item_VE = 3;


char thucdon [so_item][30] = {"      Quan Ly May Bay        ",
			                  "      Quan Ly Chuyen Bay     ",
			                  "         Quan Ly Ve          ",
			                  "    Ket thuc chuong trinh   "};
			                  
char menu_MB [item_MB][30]={"         Them May Bay        ",
							"      Hieu Chinh May Bay     ",
					 		"         Xoa May Bay         "};
					 
char menu_CB [item_CB][30]={"        Lap Chuyen Bay       ",
					 		"    Hieu Chinh Chuyen Bay    ",
					 		"        Huy Chuyen Bay       ",
							"     Danh Sach Khach Hang    ",
							"     Danh Sach Chuyen Bay    "};

char menu_Ve [item_VE][30]={"            Dat Ve           ",
					 		"            Huy Ve           ",
							"     Danh Sach Ve Trong      "};

void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(10);
	SetBGColor(5);
}
			                  
void khung (){
	gotoxy(40,0);
  	SetColor(13);
  	cout<<char(3)<<"<<<---QUAN LY CAC CHUYEN BAY NOI DIA--->>>"<<char(3);
	SetColor(2);
  	gotoxy(0,1);
  	for(int i=0; i<120; i++){
  		cout<<char(220);
	}
	
  	for(int i=0, j=0; i<=120; i+=30){
  		if(i==120){
  			gotoxy(119,2);
  			cout<<char(219);
  			break;
		}
  		gotoxy(i,2);
  		cout<<char(219);
//  		if(j<4){
//  			//Normal();
//			cout<<thucdon[j++];
//		}
	}
	//Normal();
	gotoxy(0,3);
  	for(int i=0; i<120; i++){
  		cout<<char(223);
	}
}

void khung_phu(){
	SetColor(13);
	gotoxy(13,5);cout<<"MENU";
	SetColor(3);
	gotoxy(0,4);cout<<char(201);
	for(int i=0; i<29; i++){
		cout<<char(205);
	}
	cout<<char(187);
	for(int i=5; i<20; i++){
		gotoxy(0,i);
		cout<<char(186);
		gotoxy(30,i);
		cout<<char(186);
	}
	gotoxy(0,20);cout<<char(200);
	for(int i=0; i<29; i++){
		cout<<char(205);
	}
	cout<<char(188);
}

void xoa_menu(int item){
	Normal();
	for(int i=dong_menu,j=0; i<=dong_menu+item; i++,j++){
  		gotoxy(cot_menu,i);
  		cout<<"                             ";
	}
}

int MenuDong(char thucdon [so_item][30]){
	Normal();
	int cot_main=1,chon=0;
	for(int i=1, j=0; i<120; i+=30){
		gotoxy(i,2);
		cout<<thucdon[j++];
	}
	HighLight();
	gotoxy(cot_main,2);
	cout<<thucdon[chon];
	char kytu;
	do{
		kytu = getch();
		if (kytu==-32) kytu = getch();
		switch(kytu){
			case Right :if(chon+1<4){
				Normal();
				gotoxy(cot_main,2);cout<<thucdon[chon++];
				cot_main += 30;
				HighLight();
				gotoxy(cot_main,2);cout<<thucdon[chon];
				
			}break;
			case Left :if(chon>0){
				Normal();
				gotoxy(cot_main,2);cout<<thucdon[chon--];
				cot_main -= 30;
				HighLight();
				gotoxy(cot_main,2);cout<<thucdon[chon];
				
			}break;
			case 13: Normal(); return chon+1;
		}
	}while(1);
}

int Menu_phu(int item, char td[][30]){
	int chon=0;
	for(int i=dong_menu,j=0; i<=dong_menu+item; i++,j++){
  		gotoxy(cot_menu,i);
  		cout<<td[j];
	}
	HighLight();
	gotoxy(cot_menu,dong_menu);
	cout<<td[chon];
	char kytu;
	do{
		kytu = getch();
		if (kytu==-32) kytu = getch();
		switch(kytu){
			case Up:if(chon>0){
				Normal();
				gotoxy(cot_menu,dong_menu+chon);cout<<td[chon--];
				HighLight();
				gotoxy(cot_menu,dong_menu+chon);cout<<td[chon];
			}break;
			case Down:if(chon+1<item){
				Normal();
				gotoxy(cot_menu,dong_menu+chon);cout<<td[chon++];
				HighLight();
				gotoxy(cot_menu,dong_menu+chon);cout<<td[chon];
			}break;
			case Esc: return -1;
			case 13: Normal(); return chon+1;
		}
	}while(1);
}



int main (){
	//FontSize(24,24);
	//resizeConsole(1000,800);
  	int chon=0, chon_phu=0;
  	ShowCur(false);
  	khung();
  	khung_phu();

	while(1){
		if(kbhit())
		{
			char c = getch();
			cout<<"\nNguoi dung dang nhan vao phim:"<<(int)c-48;
			if('2'=='3') cout<<"ok";
		}
	}
	
    while(1){
        chon = MenuDong (thucdon);
        switch (chon) {
        case 1:	while(1){
        			chon_phu=Menu_phu(item_MB,menu_MB);
        			switch (chon_phu){
        				case -1:
        					xoa_menu(9);
					}break;
				}break;
        		
			
        case 2: while(1){
        			chon_phu=Menu_phu(item_CB,menu_CB);
        			switch (chon_phu){
        				case -1: xoa_menu(9);
					}break;
				}break;
		        
		case 3: while(1){
        			chon_phu=Menu_phu(item_VE,menu_Ve);
        			switch (chon_phu){
        				case -1: xoa_menu(9);
					}break;
				}break;
        case so_item  : return 0;
        }
    }
    return 0;
}
