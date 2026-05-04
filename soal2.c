/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 04 - Dynamic Structures
 *   Hari dan Tanggal    : Senin, 4 Mei 2026
 *   Nama (NIM)          : Bismar Alwi Khadavi (13224016)
 *   Nama File           : soal2.c
 *   Deskripsi           : Mengurutkan dan menggabungkan 2 linked list yang sudah tersort dari kecil ke besar, lalu disort dari kecil ke besar
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertTail(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    int cek = 0;
    printf("MERGED ");
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
        cek++;
    } 
    if(cek==0){
        printf("EMPTY\n");
    } 
    else{
        printf("\n");
    }
}

void deleteTail(struct Node** head) {
    if(*head == NULL) return;

    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void mergeSort(struct Node** head1, struct Node** head2) {
    struct Node* temp1 = *head1;
    struct Node* temp2 = *head2;
    struct Node* mergedHead = NULL;
    //drpd gabungin langsung dan bubblesort, better bikin linked list baru karena list1 & list 2 udah terurut
    while(temp1!= NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            insertTail(&mergedHead, temp1->data);
            temp1 = temp1->next;
        } 
        else {
            insertTail(&mergedHead, temp2->data);
            temp2 = temp2->next;
        }
    }

    while(temp1 != NULL){
        insertTail(&mergedHead, temp1->data);
        temp1 = temp1->next;
    }

    while(temp2 != NULL){
        insertTail(&mergedHead, temp2->data);
        temp2 = temp2->next;
    }

    printList(mergedHead);

    while(mergedHead != NULL){
        deleteTail(&mergedHead);
    } //diprint dan difree di dalam karena variabel lokal
}

int main(){
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    int N1, N2;
    scanf("%d", &N1);
    for(int i=0; i<N1; i++) {
        int angka;
        scanf("%d", &angka); 
        insertTail(&head1, angka);
    }
    scanf("%d", &N2);
    for(int i=0; i<N2; i++) {
        int angka;
        scanf("%d", &angka);
        insertTail(&head2, angka);
    }

    mergeSort(&head1, &head2);

    while (head1 != NULL) {
        deleteTail(&head1);
    }
    while (head2 != NULL) {
        deleteTail(&head2);
    }

    return 0;
}
