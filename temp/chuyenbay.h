#include"khoitao.h"
#include<iostream>

using namespace std;

void themCB(PTR &First, CB chuyenbay){
	if(First==NULL){
		PTR p = new nodeCB;
		p->info=chuyenbay;
		p->next=First;
		First=p;
		delete p;
		return true;
	}
	else{
		PTR p = new nodeCB;
		p->info=chuyenbay;
		p->next=First->next;
		First->next=p;
		delete p;
		return true;
	}
	return false;
}


bool huyCB(PTR &First, CB chuyenbay){
	PTR p=First;
	if(First==NULL) return false;
	else if(First->info==chuyenbay){
		p=First;
		First=p->next;
		delete p;
		return true;
	}
	for(p=First;p->next!=NULL && p->next->info!=chuyenbay;p=p->next);
	if(p->next!=NULL){
		PTR q=p->next;
		p->next=q->next;
		delete p,q; return true;
	}
	return false;
}

bool hieuchinhCB(PTR &First, char *shCB){
	PTR p;
	for(p=First; p!=NULL; p=p->next){
		if(p->info.sohieumb == shCB){
			cin>>p->info.minmute;cin>>p->info.hour;
			cin>>p->info.day;cin>>p->info.month;
			cin>>p->info.year;
		}
		return true;
	}
	return false;
}

