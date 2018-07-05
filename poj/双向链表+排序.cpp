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
	student *next,*previous;
};
student * getpos(student * link,student * stu){
	if(strcmp(stu->id,link->id)<0){
		if(link->previous==NULL) return link;
		if(strcmp(stu->id,link->previous->id)<0)
			return (getpos(link->previous,stu));
	}
	if(strcmp(stu->id,link->id)>0){
		if(link->next==NULL) return link;
		if(strcmp(stu->id,link->next->id)>0)
			return (getpos(link->next,stu));
	}
	return link;
}
int main(){	
	student *stu,*link,*previous,*next;
	link=NULL;
	while(1){	
		stu=new student;
	    scanf("%s%s%f",stu->id,stu->name,&stu->grade);
		if(stu->grade<0){
			delete stu;
			break;
		}
		stu->next=stu->previous=NULL;
		if(link==NULL){
			link=stu;
			continue;
		}
		link=getpos(link,stu);
		if(strcmp(stu->id,link->id)<0){
			previous=link->previous;
			stu->next=link;
			link->previous=stu;			
			if(previous!=NULL){
				stu->previous=previous;
				previous->next=stu;				
			}
		}
		if(strcmp(stu->id,link->id)>0){
			next=link->next;
			stu->previous=link;
			link->next=stu;			
			if(next!=NULL){
				stu->next=next;
				next->previous=stu;				
			}
	    }
    }
	while(link->previous!=NULL) link=link->previous;
	while(link->next!=NULL){
		printf("%s %s %.2f\n",link->id,link->name,link->grade);
		link=link->next;
	}
    printf("%s %s %.2f\n",link->id,link->name,link->grade);
	while(link->previous!=NULL){
		link=link->previous;
		delete link->next;
	}
	delete link;	
	return 0;
}