#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

typedef struct graph{
    int size;
    node* arr;
} graph;

graph* createGraph(int size){
    graph* g = (graph*)malloc(sizeof(graph));
    g->size = size;
    g->arr = (node*)(malloc(sizeof(node)*size));
    return g;
}

void push(node** head,int data){
    if(head==NULL){
        node* h = (node*)(malloc(sizeof(node)));
        h->data = data;
        h->next = NULL;
        *head = h;
        return;
    }
    push(&((*head)->next), data);
}

void displayGraph(graph* g){
    for(int i=0;i<g->size;i++){
        displayNode(g->arr[i]);
    }
}

void displayNode(node* head){
    while(head!=NULL){
        printf("%d-> ",head->data);
        head = head->next;
    }
    printf("\n");
}
int main(){
    graph *g= createGraph(3);
    for(int i=0;i<g->size;i++){
        int data,ch,ele;
        printf("Source\n");
        scanf("%d",&data);
        g->arr[i]->data = data;
        while(1){
            printf("Connections\n");
            scanf("%d",&ch);
            if(ch==1){
                printf("Value\n");
                scanf("%d",&ele);
                push(&(g->arr[i]),ele);
            }
            else if(ch==0){
                printf("Break\n");
                break;
            }
            else{
                printf("Invalid Choice");
            }
        }
    }
    displayGraph(g);
}
