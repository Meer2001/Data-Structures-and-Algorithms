#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct car{
    int id;
    char name[30];
}arr[5],waitqueue[100];

int stack[5];
int top = -1;
int front = -1;
int rear = -1;
int front1 = -1;
int rear1 = -1;

void waitpush(){
    
    printf("Enter car id and name: \n");
    
    if(front1 == -1 && rear1 == -1){
        rear1++;
        front1 = rear1;
        
        scanf("%d %s",&waitqueue[rear1].id,waitqueue[rear1].name);
    }
    else if(rear1 == 100){
        printf("Full\n");
    }
    else{
        rear1++;
        scanf("%d %s",&waitqueue[rear1].id,waitqueue[rear1].name);
    }
    
    printf("\n");
    
}

int waitpop(){
    
   // if(front1 == -1 || front1>rear1){
       // printf("Queue empty\n");
    if(front1 == rear1){
        //printf("popped car of id: %d",waitqueue[front1].id);
        int start = front1;
        front1 = -1;
        rear1 = -1;
        return start;
    }else{
        //printf("popped car of id: %d",waitqueue[front1].id);
        int start = front1;
        front1++;
        return start;
    }
}


void push(int id){
    
    if(top == 5){
        printf("Stack full\n");
    }else{
        top++;
        stack[top] = id;
    }
}

int search(int num){
    for(int i=front;i<=rear;i++){
        if(num == arr[i].id){
            return i;
        }
    }
    
    return 0;
}


void enqueue(){
    
    printf("Enter car id and name: \n");

    
    if(front == -1 && rear == -1){
        rear++;
        front++;
        
        scanf("%d %s",&arr[rear].id,arr[rear].name);
    }
    else if(rear == 4){
        printf("Full\n");
        waitpush();
    }
    else{
        rear++;
        scanf("%d %s",&arr[rear].id,arr[rear].name);
    }
    
    printf("\n");
    
}

void dequeue(){
    
    if(front == -1){
        printf("Queue empty\n");
    }else if(front == rear){
       // printf("popped car of id: %d",arr[front].id);
        front = -1;
        rear = -1;
    }else{
        
        printf("Enter id of car to pop: \n");
        int num,i,j=front;
        scanf("%d",&num);
        
        int loc = search(num);
        
        
        for(i=j;i<loc;i++){
            push(arr[i].id);
            front++;
        }
            
            if(loc == 4){
            int pos = waitpop();
            arr[rear].id = waitqueue[pos].id;
            strcpy(arr[rear].name,waitqueue[pos].name);
            }else{
                
                
                for(i=loc;i<rear;i++){
                    arr[i].id = arr[i+1].id;
                    strcpy(arr[i].name,arr[i+1].name);
                }
                if(front1 == -1 && rear1 == -1){
                    rear--;
                }else{
                int pos = waitpop();
                arr[rear].id = waitqueue[pos].id;
                strcpy(arr[rear].name,waitqueue[pos].name);
                }
            }
            
            while(top != -1){
                front--;
                arr[front].id = stack[top];
                top--;
            }
            
        
        
        
    }
    
    printf("\n");
}


void print(){
    for(int i=front;i<=rear;i++){
        printf("Car id: %d\tCar name: %s\n\n",arr[i].id,arr[i].name);
    }
    
    printf("\n");
}

int main()
{
    
    int data;
    char ch;
    for(int i=0;i<5;i++){
        arr[i].id = 0;
    }
    
    printf("Do u want to push/pop/print queue?\n");
    printf("Enter y if yes and n if no\n");
    scanf("%c",&ch);
    
    
    while(ch == 'y' || ch == 'Y'){
        
        
        
        printf("Enter 1 - push / 2 - pop / 3 - print / 4 - exit\n");
        scanf("%d",&data);
        
        switch(data){
            
            case 1: enqueue();
                    break;
            
            case 2: dequeue();
                    break;
                    
            case 3: print();
                    break;
                    
            case 4: exit(0);
        }
        getchar();
        
        
    }
    

    return 0;
}


