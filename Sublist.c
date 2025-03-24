#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

struct node *newNode(int data) {
    struct node *val = (struct node*)malloc(sizeof(struct node));
    val->data = data;
    val->next = NULL;

    return val;
}

bool sublist_search(struct node* list_ptr, struct node* sub_ptr) {
    struct node* ptr1 = list_ptr, *ptr2 = sub_ptr;

    if(list_ptr == NULL && sub_ptr == NULL) // 빈 배열을 비교 할 경우
        return true;

    if(list_ptr == NULL || sub_ptr == NULL) // 하나만 비어있는 경우
        return false;
    
    while(list_ptr != NULL) {

        ptr1 = list_ptr;

        while(ptr2 != NULL) {

            if(ptr1 == NULL) // 주 배열이 끝났다면 false를 반환
                return false;
            else if(ptr2->data == ptr1->data) { // 값이 일치하다면 다음 노드로 이동
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            } else // 값이 일치하지 않다면 서브 배열의 순환 종료
                break;
        }

        if(ptr2 == NULL) // 서브 배열을 모두 순환했다면 즉, 값이 모두 일치하다면
            return true;
        
        list_ptr = list_ptr->next; // 주 배열의 노드를 다음으로 이동
        ptr2 = sub_ptr; // 서브 배열을 처음 값으로 이동
    }

    return false;
}

int main() {

    struct node *list = newNode(1);
    list->next = newNode(5);
    list->next->next = newNode(3);
    list->next->next->next = newNode(3);
    list->next->next->next->next = newNode(6);
    list->next->next->next->next->next = newNode(7);
    list->next->next->next->next->next->next = newNode(0);
    
    struct node *sub_list = newNode(3);
    sub_list->next = newNode(6);
    sub_list->next->next = newNode(7);

    int res = sublist_search(list, sub_list);

    if(res)
        printf("TRUE\n");
    else
        printf("FALSE\n");

    return 0;
}