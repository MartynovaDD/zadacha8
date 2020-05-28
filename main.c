#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

typedef struct Node_{    //узел списка
    int value11;
    int value12;
    int value21;
    int value22;
    int value31;
    int value32;
    struct Node_ *next;
} Node;

Node* add(Node** head, int x1, int y1, int x2, int y2, int x3, int y3) {
   Node* current = *head;
   Node* newNode;
   newNode = (Node*)malloc(sizeof(Node));
   if (newNode == NULL){
        printf("Error! Can't allocate memory!");
        return NULL;
   }
   else{
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
       return (newNode);
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

void deleteList(Node **head, Node *fict) {  //удаление списка
    Node* prev = NULL;
    while ((*head)->next != fict) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}

int vekt (int ax,int ay,int bx,int by,int cx,int cy){
    int k;
    int m;
    k = ax*by-bx*ay;
    m = ax*cy-cx*ay;
    return k*m;
}

double area (int x1,int x2,int x3,int y1,int y2,int y3){
    double a, b, c, P, S;
    a = sqrt((pow(x1-x2,2))+(pow(y1-y2,2)));
    //printf ("%lf\n", a);
    b = sqrt((pow(x1-x3,2))+(pow(y1-y3,2)));
    c = sqrt((pow(x2-x3,2))+(pow(y2-y3,2)));
    P = (a+b+c)/2;
    //printf ("%lf\n", P);
    S = sqrt(P*(P-a)*(P-b)*(P-c));
    //printf ("%lf\n", S);
    return S;
}

int main(void){
    Node* head = NULL;
    Node* head1 = NULL;
    Node* tmp;
    Node* fict;
    FILE* input;
    int size=1;
    int temp;
    int x1;
    int y1;
    int x2;
    int v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18;
    //double a, b,c,S1,S2,S3,SS,S11,S22,S33,P;
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
        if (fscanf(input, "%d", &temp) != 1){
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
                    v1 = vekt(head1->value21-head1->value11,head1->value22-head1->value12,x1-head1->value11,y1-head1->value12,x2-head1->value11,y2-head1->value12);
                    v2 = vekt(x2-x1,y2-y1,head1->value11-x1,head1->value12-y1,head1->value21-x1,head1->value22-y1);
                    v3 = vekt(head1->value31-head1->value11,head1->value32-head1->value12,x1-head1->value11,y1-head1->value12,x2-head1->value11,y2-head1->value12);
                    v4 = vekt(x2-x1,y2-y1,head1->value11-x1,head1->value12-y1,head1->value31-x1,head1->value32-y1);
                    v5 = vekt(head1->value21-head1->value31,head1->value22-head1->value32,x1-head1->value31,y1-head1->value32,x2-head1->value31,y2-head1->value32);
                    v6 = vekt(x2-x1,y2-y1,head1->value31-x1,head1->value32-y1,head1->value21-x1,head1->value22-y1);

                    v7 = vekt(head1->value21-head1->value11,head1->value22-head1->value12,x1-head1->value11,y1-head1->value12,x3-head1->value11,y3-head1->value12);
                    v8 = vekt(x3-x1,y3-y1,head1->value11-x1,head1->value12-y1,head1->value21-x1,head1->value22-y1);
                    v9 = vekt(head1->value31-head1->value11,head1->value32-head1->value12,x1-head1->value11,y1-head1->value12,x3-head1->value11,y3-head1->value12);
                    v10 = vekt(x3-x1,y3-y1,head1->value11-x1,head1->value12-y1,head1->value31-x1,head1->value32-y1);
                    v11 = vekt(head1->value21-head1->value31,head1->value22-head1->value32,x1-head1->value31,y1-head1->value32,x3-head1->value31,y3-head1->value32);
                    v12 = vekt(x3-x1,y3-y1,head1->value31-x1,head1->value32-y1,head1->value21-x1,head1->value22-y1);

                    v13 = vekt(head1->value21-head1->value11,head1->value22-head1->value12,x3-head1->value11,y3-head1->value12,x2-head1->value11,y2-head1->value12);
                    v14 = vekt(x2-x3,y2-y3,head1->value11-x3,head1->value12-y3,head1->value21-x3,head1->value22-y3);
                    v15 = vekt(head1->value31-head1->value11,head1->value32-head1->value12,x3-head1->value11,y3-head1->value12,x2-head1->value11,y2-head1->value12);
                    v16 = vekt(x2-x3,y2-y3,head1->value11-x3,head1->value12-y3,head1->value31-x3,head1->value32-y3);
                    v17 = vekt(head1->value21-head1->value31,head1->value22-head1->value32,x3-head1->value31,y3-head1->value32,x2-head1->value31,y2-head1->value32);
                    v18 = vekt(x2-x3,y2-y3,head1->value31-x3,head1->value32-y3,head1->value21-x3,head1->value22-y3);
                    if((v1<=0 && v2<=0) || (v3<=0 && v4<=0) || (v5<=0 && v6<=0) || (v7<=0 && v8<=0) || (v9<=0 && v10<=0) || (v11<=0 && v12<=0) || (v13<=0 && v14<=0) || (v15<=0 && v16<=0) || (v17<=0 && v18<=0)){
                        f = 1;
                    }
                    head1 = head1->next;
                }
                //printf("%d\n",f);
                if (f==0){
                    tmp = add(&head, x1, y1, x2, y2, x3, y3);
                }
                f = 0;
            }
            printLinkedList(head);   //выводим
            fict = (Node*)malloc(sizeof(Node));
            if (fict == NULL){
                printf("Error! Can't allocate memory!");
                fclose(input);
                return -1;
            }
            else{
                fict->next = (head);
                tmp->next = fict;
                deleteList(&head,fict);
                fclose(input);
                return 0;
            }
        }
    }
}
