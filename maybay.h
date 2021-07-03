#include"xuly.h"

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
		fprintf(f,"%12s", sh1);
		fprintf(f,"%12s", loai1);
		fprintf(f,"%12d", sc1);
		fprintf(f,"\n");
	//if ((i+1) %10 ==0)
	
	}
	fclose (f);
	cout << "Da ghi xong day so"; return 1;
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

void nhap_mb(int l, int t, int r, int b, int max, bool space, bool chu, bool so, char *temp, int &step, int &x, int &y){//l,t,r,b
	if(ktrVT(l,t,r,b,x,y)){
		settextstyle(f_vua,0,1);
		setfillstyle(1,10);
		bar3d(l,t,r,b,0,1);
		setbkcolor(10);
		char nhap[2] = "_";
		step = demChar(temp);
		
		if(temp[0]=='\0') outtextxy(l+10,t+5,nhap);
		else outtextxy(l+10,t+5,temp);
		
		bool kt=true;
		while(true){
			if(step>max){
				setbkcolor(7);
				char gh[20]="*Qua gioi han";
				outtextxy(l+10,t+35,gh);
				setbkcolor(10);
				outtextxy(l+10,t+5,temp);
				kt = false;
			}else{
				setfillstyle(1,7);
				bar(l,b+5,r,b+30);
				setfillstyle(1,10);
				kt = true;
			}
			if(kbhit()){
				
				char key = getch();
				
				if(key==13&&kt==true&&temp[0]!='\0'){//nut  enter
					if(temp[step-1]==' '){//xoa dau space o cuoi
						temp[step-1]=95;
						temp[step]='\0';
						step--;	
					}
					temp[step]='\0';
					settextstyle(f_vua,0,1);
					setfillstyle(1,15);
					bar3d(l,t,r,b,0,1);
					setbkcolor(15);
					outtextxy(l+10,t+5,temp);
					//x=0;y=0;
					break;
				}
				
				
				
				else if(key==8){ //nut backspace
					step--;
					temp[step]=95;
					temp[step+1]='\0';
					bar3d(l,t,r,b,0,1);
					outtextxy(l+10,t+5,temp);
					cout<<temp<<endl;
				}
				else if(ktrKyTu(key,space,chu,so)){
					if(key==' '){
						if(temp[step-1]==' '||temp[step-1]=='\0');
						else{
							temp[step]=key;
							step++;
							temp[step]=95;
							temp[step+1]='\0';
							//bar3d(l,t,r,b,0,1);
							outtextxy(l+10,t+5,temp);
							//cout<<temp<<endl;
						}
					}
					else{
						temp[step]=key;
						step++;
						temp[step]=95;
						temp[step+1]='\0';
						//bar3d(l,t,r,b,0,1);
						outtextxy(l+10,t+5,temp);
					}	
				}
				cout<<"\nso step:"<<step;
				step = (step<0) ? 0 : step;//khong cho so chu sh duoi 0
			}
		}
		normal_text();
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
