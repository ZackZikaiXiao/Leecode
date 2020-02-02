#include<stdio.h>
//define a node
typedef struct node

{
     int data;
     struct node *next;
     struct node *prev;
}Node;

//define a link
typedef struct
{
    struct node *head;
    struct node *tail;
}List;


void createList(List *list){
    list->head->next = list->tail;
    list->tail->prev = list->head;
}


//add a node, default index:0
void add(List *list, Node *add_node, int index = 0){
    if(index == 0){
        add_node->prev = list->tail->prev;
        list->tail->next = add_node;
        list->tail->prev = add_node;
        add_node->next = list->tail;
    };
}
int main(){
    List list;
    Node nod = {5};
    add(&list, &nod);
    printf("%d", list.head->next->data);
    return 0;
}
