#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
}Node;

Node * head = NULL;

int length(){
    if(head == NULL){
        return 0;
    }else{
        int count = 0;
        Node * q = head;
        while(q!=NULL){
            count ++;
            q = q->next;
        }
        return count;
    }
}

void ins_start(){
    Node * P = (Node * )malloc(sizeof(Node));
    printf("Enter Data : ");
    int ele;
    scanf("%d",&ele);
    P->data = ele;
    P->next = NULL;
    P->prev = NULL;
    if(head == NULL)
        head = P;
    else{
        head->prev = P;
        P->next = head;
        head = P;
    }
}
void ins_any(int pos){
    int p = length();
    if(pos>=p){
        printf("Not Possible.\n");
    }else{
        Node * P = (Node * )malloc(sizeof(Node));
        printf("Enter Data : ");
        int ele;
        scanf("%d",&ele);
        P->data = ele;
        P->next = NULL;
        P->prev = NULL;
        Node * q = head;
        for(int i=0;i<pos-1;i++){
            q = q->next;
        }
        q->next->prev  = P;
        P->next = q->next;
        q->next = P;
        P->prev = q;
    }
}
void ins_end(){
    Node * P = (Node * )malloc(sizeof(Node));
    printf("Enter Data : ");
    int ele;
    scanf("%d",&ele);
    P->data = ele;
    P->next = NULL;
    P->prev = NULL;
    if(head == NULL)
        head = P;
    else{
        Node * q = head;
        while(q->next != NULL){
            q = q->next;
        }q->next = P;
        P->prev = q;
    }
}

void del_start(){
    if(head == NULL)
        printf("List is Empty\n");
    else{
        printf("Deleted ele is %d.\n",head->data);
        head->next->prev = NULL;
        head = head->next;
    }
}

void del_pos(int pos){
    if(head == NULL){
        printf("List is Empty");
    }else{
        int p = length();
        Node * q = head;
        if(pos>=p-1){
            printf("Not Possible!\n");
        }else{
            for(int i=0;i<pos-1;i++){
                q = q->next;
            }
            printf("Deleted ele is %d.\n",q->next->data);
            q->next->next->prev = q;
            q->next = q->next->next;
        }
    }
}

void del_end(){
    if(head == NULL){
        printf("List is empty.\n");
    }else{
        Node * q = head;
        while(q->next->next != NULL){
            q = q->next;
        }printf("Deleted ele is %d.\n",q->next->data);
        q->next = NULL;
    }

}
void display(){
    if(head == NULL){
        printf("List is empty.\n");
    }else{
        for(Node * q = head; q != NULL; q = q->next){
            printf("%d ->",q->data);
        }printf("\n");
    }
}


int main(){
    printf("1.Insert Start\n2.Ins at Pos\n3.Insert End\n4.Delet Start\n5.Delet at Pos\n6.Delet end\n7.Display\n8.Exit\n");
    while(1){
        printf("Enter Choice : ");
        int opt;
        scanf("%d",&opt);
        switch(opt){
            case 1:ins_start();break;
            case 2:printf("Enter Pos : ");int pos;scanf("%d",&pos);ins_any(pos);break;
            case 3:ins_end();break;
            case 4:del_start();break;
            case 5:printf("Enter Pos : ");int poss;scanf("%d",&poss);del_pos(poss);break;
            case 6:del_end();break;
            case 7:display();break;
            case 8:return 0;
        }
    }
}