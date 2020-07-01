//List header file
// 2020.07.01

typedef struct list{

  int size;
  int curr;
  int capacity;
  int* contents;
   
}list_t;

void clear(list_t*);
void insert(list_t*, int);
void append(list_t*,int);
int listRemove(list_t*);
void moveToStart(list_t*);
void moveToEnd(list_t*);
void prev(list_t*);
void next(list_t*);
void moveToPos(list_t*, int pos);
int getValue(list_t*);

