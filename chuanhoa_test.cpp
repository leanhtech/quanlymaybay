#include <string.h>
#include <iostream>
using namespace std;

bool kiemtraso(char &a){
	for(char i = '0'; i<='9'; i++){
		if(a==i)
		return true;
	}
	return false;
}

void chuanhoaso(char *a, int &l){
	for(int i=0; i<l;i++){
		//loc chu ra khoi chuoi so
		if(kiemtraso(a[i])==false/*a[i]>= 'A' && a[i]<='z'(a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')*/){
			for(int k = i; k<l; k++){
				a[k] = a[k+1];
			}
			l -= 1;
			i--;
		}
		//xoa dau cach o giua chuoi so
		if(a[i]==' '){
			for(int k = i; k<l; k++){
				a[k] = a[k+1];
			}
			l -= 1;
			i--;
		}
	}
	//xoa dau cach cuoi neu co
	if(a[l-1]==' ')
		l--;
}

bool kiemtrachuoichu(char &a){
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
	if(a==' ' || a==39) return true;
	return false;
}

void chuanhoachuoi(char *a, int &l){
	int i=0;
	//xoa dau cach dau chuoi chu
	while (a[0] == ' '){
		for(int k = 0; k<l; k++){
			a[k] = a[k+1];
		}
		l -= 1;
	}
	for(i=0; i<l;i++){
		//kiem tra chuoi khong phai thi khong them vao
		if(kiemtrachuoichu(a[i])==false){
			for(int k = i; k<l; k++){
				a[k] = a[k+1];
			}
			l -= 1;
			i--;
		}
		//xoa khoang cach du o giua chuoi chu
		if(a[i]==' '&& a[i+1]==' '){
			for(int k = i+1; k<l; k++){
				a[k] = a[k+1];
			}
			l -= 1;
			i--;
		}
	}
	//xoa khoang cach cuoi chuoi chu nen co
	if(a[l-1]==' ')
		l--;
}

int main(){
	char a[50];
	
	cout<<"Nhap chuoi :";
	fgets(a,50,stdin);
	int len = strlen(a)-1;//do nhap tu ban phi tu nhan them 1 ky tu phia sau
	chuanhoachuoi(a,len);
	cout<<a;
}
