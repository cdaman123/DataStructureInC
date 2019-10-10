#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node * link;
}Node;

Node * head = NULL;
int length(){
    if(head == NULL){
        return 0;
    }else{
        Node * q = head;
        int count = 0;
        while(q->link!=head){
            q = q->link;
            count++;
        }count++;
        return count;
    }
}
void ins_beg(){
    Node * P = (Node *)malloc(sizeof(Node));
    int val;
    printf("Enter ele : ");
    scanf("%d",&val);
    P->data = val;
    P->link = NULL;
    if(head == NULL){
        head = P;
        head->link = head;
    }else{
        Node * q = head;
        while(q->link != head){
            q = q->link;
        }
        P->link = head;
        head = P;
        q->link = head;
    }
}

void ins_pos(int pos){
    Node * P = (Node *)malloc(sizeof(Node));
    printf("Enter ele: ");
    int ele;
    scanf("%d",&ele);
    P->link = NULL;
    P->data = ele;
    int p = length();
    if(pos>=p-1){
        printf("Not Possible\n");
    }else{
        Node * q = head;
        for(int i=1;i<pos;i++){
            q = q->link;
        }
        P->link = q->link;
        q->link = P;
    }

}

void ins_end(){
    Node * P = (Node *)malloc(sizeof(Node));
    int val;
    printf("Enter ele : ");
    scanf("%d",&val);
    P->data = val;
    P->link = NULL;
    if(head == NULL){
        P->link = head;
        head = P;
    }else{
        Node * q = head;
        while(q->link != head){
            q=q->link;
        }P->link = q->link;
        q->link = P;
    }

}

void del_start(){
    if(head == NULL){
        printf("List is empty.\n");
    }else{
        Node * q = head;
        while(q->link != head){
            q = q->link;
        }
        printf("Deleted ele is %d\n",head->data);
        q->link = head->link;
        head = head->link;
    }
}

void del_pos(int pos){

    int p = length();
    if(pos>=p-1){
        printf("Not Possible\n");
    }else{
        Node * q = head;
        for(int i=1;i<pos;i++){
            q = q->link;
        }printf("deleted ele is %d\n",q->link->data);
        q->link = q->link->link;
    }
}

void del_end(){
    if(head == NULL){
        printf("List is empty.\n");
    }else{
        Node * q = head;
        while(q->link->link != head){
            q = q->link;
        }printf("Deleted item is %d\n",q->link->data);
        q->link = q->link->link;
    }
}

void display(){
    Node * q = head;
    if(head == NULL){
        printf("List is Empty");
    } else{
        for(int i=0;q->link != head;q = q->link){
            printf("%d ->",q->data);
        }printf("%d\n",q->data);
    }
}

int main(){
    printf("1.Ins start\n2.Ins Pos\n3.ins end\n4.Del start\n5.del Pos\n6.del end\n7.display\n8.exit\n");
    while(1){
        printf("Enter Choice : ");
        int opt,pos;
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:ins_beg();break;
        case 2:printf("Enter Pos : ");scanf("%d",&pos);ins_pos(pos);break;
        case 3:ins_end();break;
        case 4:del_start();break;
        case 5:printf("Enter Pos : ");scanf("%d",&pos);del_pos(pos);break;
        case 6:del_end();break;
        case 7:display();break;
        case 8:exit(0);
        }
    }
}