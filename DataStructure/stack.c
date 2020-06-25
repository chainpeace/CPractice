/*
    20.06.25 v.1

*/

#include <stdio.h>
#include <stdlib.h>

struct intStack{
    int capacity;
    int top;
    int* contents;
};

void intStackInit(struct intStack* istack, int capacity){
    istack->capacity = capacity;
    istack->top = 0;
    istack->contents = (int *)malloc(capacity * sizeof(int));

}
int isEmpty(struct intStack * istack){
    if(istack->top==0){
        return 1;
    } else{
        return 0;
    }
}
int isFull(struct intStack* istack){
    if(istack->top >= istack->capacity)
        return 1;
    return 0;
}
int push(struct intStack* istack, int content){
    if(isFull(istack))
        return -1;
    istack->contents[istack->top++] = content;
}
int pop(struct intStack* istack){
    if(isEmpty(istack))
        return -1;
    return istack->contents[--(istack->top)];
}
int peek(struct intStack* istack){
    if(isEmpty(istack))
        return -1;
    return istack->contents[(istack->top)-1];
}
struct intStack* extend(struct intStack* istack, int newCapacity){
    if(newCapacity < istack->capacity)
        return NULL;
    
    struct intStack* newStack = (struct intStack*)malloc(sizeof(struct intStack));
    intStackInit(newStack, newCapacity);
    while(!isEmpty(istack)){
        push(newStack, pop(istack));
    }
}
void printStack(struct intStack* istack){
    int i;
    for(i=0;i<istack->top;i++){
        printf("%d : %d\n", i, istack->contents[i]);
    }
}

int main(){
    struct intStack* istack = (struct intStack*) malloc(sizeof(struct intStack));
    intStackInit(istack, 20);
    
    push(istack, 155);
    push(istack, 167);
    
    printf("%d\n", istack->top);
    printf("%d\n", peek(istack));
    printStack(istack);
    
    printf("%d\n", pop(istack));
    printStack(istack);

    return 1;
}