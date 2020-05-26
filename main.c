#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{    //узел списка
    int value11;
    int value12;
    int value21;
    int value22;
    int value31;
    int value32;
    struct Node *next;
} Node;

//добавление в конец списка
void add(Node** head, int x1, int y1, int x2, int y2, int x3, int y3) {
   Node* current = *head;
   Node* newNode;
   newNode = malloc(sizeof(Node));
   newNode->value11 = x1;
   newNode->value12 = y1;
   newNode->value21 = x2;
   newNode->value22 = y2;
   newNode->value31 = x3;
   newNode->value32 = y3;
   //printf("%d", y3);
   newNode->next = NULL;
   if (current == NULL) {
      *head = newNode;
   }
   else {
      while (current->next != NULL) {
          current = current->next;
      }
      current->next = newNode;
   }
}


void printLinkedList(const Node *head) {
    while (head) {
        printf("%d ", head->value11);
        printf("%d ", head->value12);
        printf("%d ", head->value21);
        printf("%d ", head->value22);
        printf("%d ", head->value31);
        printf("%d ", head->value32);
        printf("\n");
        head = head->next;
    }
    printf("\n");
}


void deleteList(Node **head) {  //удаление списка
    Node* prev = NULL;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}


int main(void){
    Node* head = NULL;
    Node* head1 = NULL;
    FILE* input;
    int size=1;
    int temp;
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    int f = 0;
    input = fopen("text.txt","r");
    if (!input){
        printf("Error! Cannot open file !\n");
        return -1;
    }
    else{
        if (fscanf(input, "%d", &temp) != 1){   //
            printf("Error! Cannot read from file!\n");
            fclose(input);
            return -1;
        }
        else{
            while(fscanf(input, "%d", &temp) == 1){
                size++;
            }
            rewind(input);
            for (int i=0; i < (size/6); i++){
                fscanf(input, "%d", &x1);
                fscanf(input, "%d", &y1);
                fscanf(input, "%d", &x2);
                fscanf(input, "%d", &y2);
                fscanf(input, "%d", &x3);
                fscanf(input, "%d", &y3);
                head1 = head;
                while(head1){
                    if((x1==head1->value11 && y1==head1->value12) && (x2==head1->value21 && y2==head1->value22) && (x3==head1->value31 && y3==head1->value32)){
                        f = 1;
                    }
                    head1 = head1->next;
                }
                //printf("%d\n",f);
                if (f==0){
                    add(&head, x1, y1, x2, y2, x3, y3);
                }
                f = 0;
            }
            printLinkedList(head);   //выводим
            deleteList(&head);
        }
    }
}
