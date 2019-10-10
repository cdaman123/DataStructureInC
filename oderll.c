#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node  * next;
}Node;

void add(Node ** head){
    Node * P = (Node *)malloc(sizeof(Node));
    printf("Enter ele : ");
    int ele;
    scanf("%d",&ele);
    P->data = ele;
    P->next = NULL;
    if(*head == NULL){
        *head = P;
    }else{
        Node * q = *head;
        if(ele< (*head)->data){
            P->next = *head;
            *head = P;
        }else{
            while(q->next != NULL){
                if(q->next->data > ele){
                    P->next = q->next;
                    q->next = P;
                    break;
                }
                q = q->next;
            }if(q->next == NULL){
                q->next = P;
            }
        }
    }
}

void display(Node * head){
	if(head == NULL){
		printf("List is empty\n");
	}else{
		Node * q = head;
		while(q != NULL){
			printf("%d ->",q->data);
			q = q->next;
		}
		printf("\n");
	}
}

int main(){
    Node * head = NULL;
    printf("1.Add\n2.Display\n3.Exit\n");
    while(1){
        printf("Enter choice : ");
        int opt;
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            add(&head);
            break;
        
        case 2:
            display(head);
            break;
        case 3:
            exit(0);
        }
    }
}
