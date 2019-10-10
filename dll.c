#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
}Node;

Node * head = NULL;
int max = 0;

void ins_loc(int n){
    if(n>max){
        printf("Not Possible.\n");
    }else{
        Node * P = (Node *)malloc(sizeof(Node));
        max ++;
        printf("Enter element: ");
        int val;
        scanf("%d",&val);
        P->next = NULL;
        P->prev = NULL;
        P->data = val;
        if(n==0){
            head = P;
        }else{
            Node * q = head;
            for(int i=0;i<n;i++){
                q = q->next;
            }
            P->prev = q;
            P->next = q->next;
            if(n!=max){
                q->next->prev = P;
            }q->next = P;
        }
    }
}

void del_loc(int n){
    if(n>=max){
        printf("Not Possible.\n");
    }else{
        max--;
        if(n==0){
            printf("Deleted ele is %d.\n",head->data);
            head = head->next;
            head->prev = NULL;
        }else{
            Node * q = head;
            for(int i=0;i<n;i++){
                q = q->next;
            }printf("Deleted ele is %d.\n",q->next->data);
            if(n!= max-1){
                q->next->next->prev = q;
            }q->next = q->next->next;
        }
    }
}

void display(){
    if(head == NULL){
        printf("List is empty.\n");
    }else{
        for(Node * q = head; q != NULL; q = q->next){
            printf("%d ->");
        }printf("\n");
    }
}

int main(){
    printf("1.Insert Start\n2.Insert Any Position\n3.Insert End\n4.Delet Start\n5.Delet any Position\n6.Delet end\n7.Display\n8.Exit\n");
    while(1){
        printf("Enter Choice : ");
        int opt;
        scanf("%d",&opt);
        switch(opt){
            case 1:ins_loc(0);break;
            case 2:printf("Enter loc: ");int loc;scanf("%d",&loc);ins_loc(loc);break;
            case 3:ins_loc(max);break;
            case 4:del_loc(0);break;
            case 5:printf("Enter loc: ");int locd;scanf("%d",&locd);del_loc(locd);break;
            case 6:del_loc(max-1);break;
            case 7:display();break;
            case 8:return 0;

        }

    }

}