#include<stdio.h>
#define max 20

int arr[max];
int top1 = -1;
int top2 = max;

void Push1(){
    top1++;
    if(top1==top2){
        printf("Stack 1 is Full");
        top1--;
    }
    else{
        printf("Enter Element:");
        scanf("%d",&arr[top1]);
    }
}

void Push2(){
    top2--;
    if(top1==top2){
        printf("Stack 2 is Full");
        top2++;
    }
    else{
        printf("Enter Element:");
        scanf("%d",&arr[top2]);
    }
}

void Pop1(){
    if(top1==-1){
        printf("Stack 1 is Empty");
    }
    else{
        printf("Pop element is : %d\n",arr[top1]);
        top1--;
    }
}
void Pop2(){
    if(top2==max){
        printf("Stack 2 is Empty");
    }
    else{
        printf("Pop element is : %d\n",arr[top2]);
        top2++;
    }
}

void Disp1(){
    if(top1==-1){
        printf("Stack 1 is empty");
    }
    else{
        for(int i=0;i<=top1;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}
void Disp2(){
    if(top2==max){
        printf("Stack 2 is empty");
    }
    else{
        for(int i=max-1;i>=top2;i--){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}

int main(){
    printf("Enter Option:\n");
    printf("1.Push in S1\n2.Pop from S1\n3.Display S1\n4.Push in S2\n5.Pop from S2\n6.Display S2\n7.Exit\n");
    int f;
    while(1){
        printf("Enter Choice:");
        scanf("%d",&f);
        switch(f){
            case 1:
                Push1();
                break;
            case 2:
                Pop1();
                break;
            case 3:
                Disp1();
                break;
            case 4:
                Push2();
                break;
            case 5:
                Pop2();
                break;
            case 6:
                Disp2();
                break;
            case 7:
                return 0;
                
        }
    }
}