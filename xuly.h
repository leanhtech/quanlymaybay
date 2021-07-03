#include<graphics.h>



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

void xoa_cn(){ //xoa man hinh chuc nang
	setfillstyle(1,8);
	bar(0,100,1270,767);
}

int demChar(char *s){
	int dem = 0;
	while(s[dem]!='\0'){
		dem++;
	}
	return dem;
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
	//if(a==' ' || a==39) return true;
	return false;
}

int intValue(char  *s){
    int res = 0,dem=0;
	while(s[dem]!='\0'){
		dem++;
	}
    for(int i=0;i<dem;i++){
    	if(s[i]=='0'){
    		res = res*10;
		}
    	else
    		res = res*10 + (int)(s[i]-'0');
	}
    return res;
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
