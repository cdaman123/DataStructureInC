#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node * link;
}Node;

Node  * head = NULL;

void Add(){
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

void Remove(){
	if(head == NULL){
		printf("List is empty.\n");
	}else{
		printf("Deleted element is %d.\n",head->data);
		head = head->link;
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
    printf("1.Add\n2.Remove\n3.Display\n4.Exit\n");
    while(1){
        printf("Enter choice : ");
        int opt;
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:Add();break;
        case 2:Remove();break;
        case 3:Display();break;
        case 4:exit(0); 
        }
    }
}
