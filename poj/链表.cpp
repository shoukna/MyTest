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
int main(){	
	student *first,*linkedlist;
	first=linkedlist=NULL;   //³õÊ¼»¯Ö¸Õë
	while(1){	
		student *stu=new student;
	    scanf("%s%s%f",stu->id,stu->name,&stu->grade);
		if(stu->grade<0){
			delete stu;
			break;
		}
		stu->next=NULL;
		if(first==NULL){
		    first=stu;
			linkedlist=first;
		}
		else{
		    linkedlist->next=stu;
			linkedlist=stu;
		}
	}
	float avg=0.0;
	float sum=0.0;
	linkedlist=first;
	int i=0;
	while(linkedlist!=NULL){
		float grade=linkedlist->grade;
		sum=sum+grade;
		i++;
		linkedlist=linkedlist->next;
	}
	printf("%.2f\n",(float)sum/i);
	while(first!=NULL){
		linkedlist= first;
		first=first->next;
		delete linkedlist;
	}

	return 0;
}