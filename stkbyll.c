#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node * link;
}Node;

Node  * head = NULL;

void Push(){
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

void Pop(){
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

void Display(){
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
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    while(1){
        printf("Enter choice : ");
        int opt;
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:Push();break;
        case 2:Pop();break;
        case 3:Display();break;
        case 4:exit(0); 
        }
    }
}
