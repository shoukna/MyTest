#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
struct student{
	char id[20];
	char name[20];
	float grade;
	student *next;
};
struct studentlist{
    int totalstudent;
	int unqualifiedstudent;
	float totalscore;
	student * head;
	student * tail;
};
int main(){	
	studentlist link;
	student *first;
	first=NULL;   //³õÊ¼»¯Ö¸Õë
	link.head=link.tail=NULL;
	link.totalscore=0.0;
	link.totalstudent=0;
	link.unqualifiedstudent=0;
	student *stu;
	while(1){	
		stu=new student;
	    scanf("%s%s%f",stu->id,stu->name,&stu->grade);
		if(stu->grade<0){
			delete stu;
			break;
		}
		stu->next=NULL;
		if(link.tail==NULL){
		    first=stu;
			link.head=link.tail=first;
		}
		else{
		    link.tail->next=stu;
			link.tail=stu;
		}
		link.totalstudent++;
		link.totalscore+=stu->grade;
		if(stu->grade<60)
			link.unqualifiedstudent++;
	}
	float avg=link.totalscore/link.totalstudent;
	printf("%.2f\n",avg);
	stu=link.head;
	printf("%d\n",link.unqualifiedstudent);
	while(stu!=NULL){
		if(stu->grade<60){
			printf("%s: %s\n",stu->id,stu->name);
		}
		stu=stu->next;
	}
	while(link.head!=NULL){
		stu= link.head;
		link.head=stu->next;
		delete stu;
	}
	return 0;
}