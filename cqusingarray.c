#include<stdio.h>
#define max 5

int arr[max], rear = -1, front = -1;

void Add(){
    if((rear+1)%max == front){
        printf("Queue is Full");
    }
    else{
        rear++;
        rear%=max;
        printf("Enter element:");
        scanf("%d",&arr[rear]);
    }
    if(front == -1) front = 0;
}

void Remove(){
    if(front == -1 || (front+1)%max == rear){
        printf("Queue is empty");
    }
    else{
        printf("Removed item is :%d\n",arr[front]);
        front++;
        front%=max;
    }
}

void Display(){
    if(front == -1 || (front+1)%max == rear){
        printf("Queue is empty");
    }
    else if (rear>front)
    {
        for(int i=front;i<=rear;i++){
            printf("%d ",arr[i] );
        }printf("\n");
    }
    else{
        for(int i=front;i<max;i++){
            printf("%d ",arr[i]);
        }
        for(int i=0;i<=rear;i++){
            printf("%d ",arr[i]);
        }printf("\n");
    }
}
int main(){
    printf("Enter Option:\n");
    printf("1.Add\n2.Remove\n3.Display\n4.Exit\n");
    int f;
    while(1){
        printf("Enter Choice:");
        scanf("%d",&f);
        switch(f){
            case 1:
                Add();
                break;
            case 2:
                Remove();
                break;
            case 3:
                Display();
                break;
            case 4:
                return 0;
                
        }
    }
}