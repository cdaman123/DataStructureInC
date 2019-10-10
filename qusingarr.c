#include<stdio.h>
#define max 20

int arr[max], top = 0 , rear = -1;

void Add(){
    rear++;
    if(rear == max){
        printf("Queue is Full");
        rear--;
    }
    else{
        printf("Enter Element:");
        scanf("%d",&arr[rear]);
    }
}

void Remove(){
    if(top==max-1){
        printf("Queue is Empty");
    }
    else{
        printf("Pop element is : %d\n",arr[top]);
        top++;
    }
}

void Display(){
    if(top==rear) printf("Queue is empty");
    else{
        for(int i=top;i<=rear;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
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