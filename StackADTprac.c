#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define Max 10
int count=0;

struct stack{
    int items[Max];
    int top;
};
typedef struct stack st;

void createEmptyStack(st *s){
    s->top=-1;
}

int isFull(st *s){
    if(s->top==Max-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(st *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(st *s, int newitem){
    if(isFull(s)){
        printf("Stack is full");
    }
    else{
        s->top++;
        s->items[s->top]=newitem;
    }
}

void pop(st *s){
    if(isEmpty(s)){
        printf("Stack is empty");
    }
    else{
        printf("Item popped= %d\n", s->items[s->top]);
        s->top--;
    }
}

int main(){
    int ch;
    int item;
    st *s=(st*)malloc(sizeof(st));
    createEmptyStack(s);
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Exit\n");
    do{
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d", &item);
                push(s, item);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice");
        }
    }while(ch!=3);
    
    free(s);
    return 0;
}