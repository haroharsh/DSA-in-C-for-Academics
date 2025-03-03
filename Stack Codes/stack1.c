//As a stack is linear data structure, we can implement it using array or linked list.

/*We know that stack_arr is an array and insertion and deletion operations can be performed at any place
but we want the stack_arr to behave like a stack*/
//Hence, the insertions and deletions must be performed at the end

/*For this we will keep a variable top which will keep track of the last inserted element or the topmost element in an error*/
#include<stdio.h>
#define MAX 4

int stack_arr[MAX];//Global declaration of stack
int top=-1;//Declared globally because it will be used many times in main and functions

void push(int data);

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);//Stack Overflow
    return 0;
}
void push(int data){
    if(top == MAX - 1)
    {
        printf("\nStack Overflow");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
}