#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node * link;
}Node;

Node  * head = NULL;

void ins_start(){
	Node * P = (Node *)malloc(sizeof(Node));
	printf("Enter Data :");
	int d;
	scanf("%d",&d);
	P->data = d;
	P->link = NULL;
	if(head == NULL){
		head = P;
	}else{
		Node * q = head;
		while(q->link != head){
			q = q->link;
		}
		q->link = P;
		P->link = head;
		head = P;
	}
}

void ins_end(){
	Node * P = (Node *)malloc(sizeof(Node));
	printf("Enter Data :");
	int d;
	scanf("%d",&d);
	P->data = d;
	P->link = NULL;
	if(head == NULL){
		head = P;
	}else{
		Node * q = head;
		while(q->link != NULL){
			q = q->link;
		}
		q->link = P;
		P->link = NULL;
	}
}

void ins_mid(){
	printf("After which element add node: ");
	int ele,f;
	scanf("%d",&ele);
	Node * q = head;
	while(q->data != ele && q->link != NULL){
		q = q->link;
	}
	if(q->data == ele){
		Node * P = (Node *)malloc(sizeof(Node));
		printf("Enter Data :");
		int d;
		scanf("%d",&d);
		P->data = d;
		P->link = q->link;
		q->link = P;
	}else{
		printf("%d is not available in list.\n",ele);
	}	
}

void del_start(){
	if(head == NULL){
		printf("List is empty.\n");
	}else{
		printf("Deleted element is %d.\n",head->data);
		head = head->link;
	}
}

void del_end(){
	if(head == NULL){
		printf("List is empty.\n");
	}else{
		Node * q = head;
		while(q->link->link !=NULL){
			q = q->link;
		}
		printf("Deleted element is %d.\n",q->link->data);
		q->link = NULL;
	}
}

void del_ele(){
	if(head == NULL){
		printf("List is empty.\n");
	}else{
		Node * q = head;
		printf("Enter element :");
		int ele;
		scanf("%d",&ele);
		while(q->link->data !=ele && q->link->link != NULL){
			q = q->link;
		}
		if(q->link->data == ele){
			printf("Element deleted.\n");
			q->link = q->link->link;			
		}else{
			printf("Element not found.\n");
		}
	}
}

void display(){
	if(head == NULL){
		printf("List is empty\n");
	}else{
		Node * q = head;
		while(q != NULL){
			printf("%d ->",q->data);
			q = q->link;
		}
		printf("\n");
	}
}

int main(){
	printf("1.Insert at Start\n2.Insert at end\n3.Insert after element\n4.Delet from start\n5.Delet from end\n6.Delet element\n7.Display\n8.Exit\n");
	while(1){
		int o;
		printf("Enter option : ");
		scanf("%d",&o);
		switch (o){
			case 1 : ins_start();break;
			case 2 : ins_end();break;
			case 3 : ins_mid();break;
			case 4 : del_start();break;
			case 5 : del_end();break;
			case 6 : del_ele();break;
			case 7 : display();break;
			case 8 : return 0;
		}		
	}
}