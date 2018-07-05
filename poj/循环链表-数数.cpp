#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
struct Monkey{
	int id;
	Monkey *next;
};

int main(){	
	Monkey * link,*monkey,*lastmonkey=NULL;
	int totalmonkey,stride;
	scanf("%d%d",&totalmonkey,&stride);
	link=NULL;
	for(int i=1;i<=totalmonkey;i++){
		monkey=new Monkey;
		monkey->id=i;
		if(link==NULL) link=lastmonkey=monkey;
		else{
			lastmonkey->next=monkey;
			lastmonkey=monkey;;
		}
	}
	lastmonkey->next=link;
	int count=1;
	while(link!=NULL){
		if(link->next==link){
		    printf("%d\n",link->id);
			delete link;
			break;
		}
		if(count==stride-1){
		    monkey=link->next;
			link->next=monkey->next;
			printf("%d\n",monkey->id);
			delete monkey;
			count=0;
		}
		link=link->next;
		count++;
	}
}