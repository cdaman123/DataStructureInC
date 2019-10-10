#include<stdio.h>
#define max 20

int arr[max];
int top = -1;

void Push(){
    top++;
    if(top==max-1){
        printf("Stack is Full!\n");
    }
    else{
        printf("Enter element: ");
        scanf("%d",&arr[top]);
    }

}


void Pop(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("Removed item is %d\n",arr[top]);
        top--;
    }


}

void Display(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        for(int i=0;i<=top;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }

}

int main(){
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    while(1){
        int o;
        printf("Enter option :");
        scanf("%d",&o);
        switch(o){
            case 1:Push();break;
            case 2:Pop();break;
            case 3:Display();break;
            case 4:return 0;
            
        }
    }


}