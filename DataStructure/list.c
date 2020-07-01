//Practice for
//List data structure
//2020.07.01

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

list_t* listInit(int capacity){ 

  list_t* newList = malloc(sizeof(list_t));
  newList->size = 0;
  newList->curr = 0;
  newList->capacity = capacity;
  newList->contents = malloc(capacity*sizeof(int));

  return newList;
}
void freeList(list_t* list){
  free(list->contents);
  free(list);
}
void clear(list_t* list){

  list->size = 0;
  list->curr = 0;

}
int is_full(list_t* list){

  if(list->size < list->capacity)
	return 0;

  return 1;

}
int is_empty(list_t* list){
  
  if(list->size == 0)
    return 1;

  return 0;
}
void moveToStart(list_t* list){
  list->curr = 0;
}
void moveToEnd(list_t* list){
  list->curr = list->size;
}
void prev(list_t* list){
  if(list->curr!=0)
    list->curr--;
}
void next(list_t* list){
  if(list->curr < list->size)
    list->curr++;
}
void moveToPos(list_t* list, int pos){
  if(pos < 0 || pos > list->size)
    return ;

  list->curr = pos;
}
int getValue(list_t* list){
  assert(list->curr >= 0 && list->curr <= list->size && "invalid cursor");
  return list->contents[list->curr];
}
void swap(list_t* list, int p1, int p2){
  if(p1 > list->size || p2 > list->size)
	return;
  if(p1 < 0 || p2 < 0)
	return;

  int tmp = list->contents[p1];
  list->contents[p1] = list->contents[p2];
  list->contents[p2] = tmp;
  
}
void insert(list_t* list, int item){
  if(is_full(list))
    return;

  int i;
  for(i=list->size; i>list->curr; i--){
    list->contents[i] = list->contents[i-1];  
  }
  list->contents[list->curr] = item;
  list->size++;
}
void append(list_t* list, int item){
  if(is_full(list))
    return;

  list->contents[list->size++] = item;

}
int listRemove(list_t* list){
  assert(list->curr >= 0 && list->curr <= list->size);
  
  int item = list->contents[list->curr];
  int i;
  for(i=list->curr; i<list->size-1; i++){
    list->contents[i] = list->contents[i+1];
  }
  list->size--;
  return item;
}
void printList(list_t* list){

  printf("start print list info\n");
  printf("list size : %d\n", list->size);
  printf("current : %d\n", list->curr);
  printf("capacity : %d\n", list->capacity); 
  
  int i = 0;
  for(i=0;i<list->size;i++){
    printf("%d : %d\n", i, list->contents[i]);

  }
  printf("end print list info\n");
}

int main(){

  printf("hello list\n");
  list_t* list = listInit(10);
  insert(list, 10);
  insert(list, 12);
  insert(list, 8);
  printList(list);  

  moveToEnd(list);
  insert(list, 9);
  printList(list);

  prev(list);
  printList(list);

  moveToStart(list);
  next(list);
  insert(list,1);
  printList(list);
 
  append(list, 15);
  printList(list);

  printf("remove item : %d\n", listRemove(list));
  printf("remove item : %d\n", listRemove(list));
  printList(list);
  
  printf("get value : %d\n", getValue(list));
  moveToPos(list,0);
  printList(list);

  prev(list);
  getValue(list);

  list->curr--;
  getValue(list);

  return 0;
}

