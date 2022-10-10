#include <iostream>
using namespace std;

struct Node {
    int num;
    struct Node* next;
    struct Node* prev;
} Node;

struct Node* head = NULL;
struct Node* tail = NULL;


void insertback(int num){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->num = num;
    if (head == NULL){
        //this is the first node in the system
        head = new_node;
        tail = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    else{
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = NULL;
        tail = new_node;
    }
}

void insertfront(int num){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->num = num;
    if (head == NULL){
        //first node in the list
        new_node->next = NULL;
        new_node->prev = NULL;
        head = new_node;
        tail = new_node;
    }
    else{
        head->prev = new_node;
        new_node->next = head;
        new_node->prev = NULL;
        head = new_node;
    }
}

int deleteback(){
    int pop_val;
    if (head == NULL){
        cout << "Cannot delete back node from an empty list" << endl;
        return 0;
    }
    else{
        //what about case where head->next == NULL?
        struct Node* pop_node = tail;
        pop_val = pop_node->num;
        tail->prev->next = NULL;
        tail = tail->prev;
        free(pop_node);
        return pop_val;
    }
}

int deletefront(){
    int pop_val;
    if (head == NULL){
       cout << "Cannot delete front node from an empty list" << endl;
       return 0;
    } 
    else{ 
        //what about where tail->prev == NULL?
        struct Node* pop_node = head;
        pop_val = pop_node->num;
        head->next->prev = NULL;
        head = head->next;
        free(pop_node);
        return pop_val;
    }
}

void display(){
    struct Node* ptr = head;
    cout << "[ ";
    while (ptr != NULL){
        cout << ptr->num << " ";
        ptr = ptr->next;
    }
    cout << " ]" << endl;
}

void freelist(){
    if (head != NULL){
        while (head != NULL){
            struct Node* temp = head;
            head = head->next;
            free(temp);
        }
    }
    else{
        cout << "Cannot free an empty list." << endl;
    }
}


void sortlist(){
    struct Node* cur = head;
    struct Node* nxt = NULL;
    int temp;
    while (cur != NULL){
        nxt = cur->next;
        while (nxt != NULL){
            if (cur->num > nxt->num){
                temp = cur->num;
                cur->num = nxt->num;
                nxt->num = temp;
            }
            nxt = nxt->next;
        }
        cur = cur->next;
    }
}

int main(){
    insertback(3);  display();
    insertfront(5); display();
    cout << "Deleted back value: " << deleteback() << endl; 
    insertback(10);  display();
    insertback(14);  display();
    insertfront(27); display();
    cout << "Deleted front value: " << deletefront() << endl;
    display();
    insertfront(78); display();
    insertback(2);   display();
    cout << "Dispatching bubblesort function: " << endl;
    sortlist();
    display();
    

    freelist();
    return 0;
}
