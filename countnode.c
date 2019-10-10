#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node * link;
}Node;

Node  * head = NULL;
Node * tail = NULL;


void add_ele(){
	Node * P = (Node *)malloc(sizeof(Node));
	printf("Enter Data :");
	int d;
	scanf("%d",&d);
	P->data = d;
	P->link = NULL;
	if(head == NULL){
		head = P;
        tail = P;
	}else{
		tail->link = P;
        tail = P;
	}
}
int count_node(){
    if(head == NULL)
        return 0;
    else{
        Node * p = head;
        int count =0;
        while(p!=NULL){
            count++;
            p = p->link;
        }
        return count;

    }
}

int main(){
    printf("1.Add Node\n2.Count Node\n3.Exit\n");
    while(1){
        int o,p;
        printf("Enter choice :");
        scanf("%d",&o);
        switch (o){
        case 1:
            add_ele();
            break;
        case 2:
            p= count_node();
            printf("No. of Nodes = %d",p);
            break;
        case 3:
            return 0;
        }
    }
}
