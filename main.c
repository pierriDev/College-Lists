#include <stdio.h>
#include <stdlib.h>

const MAX_ARRAY_SIZE = 10;
// const MAX_ARRAY_SIZE = 100000000;

struct person {
    char name;
    char rg;

    struct person *next;
    // struct person *before;
};

typedef struct person PEOPLE;
struct person *head = NULL;

struct person people[MAX_ARRAY_SIZE];


void newDataLinkedListBeggining(char newName, char newRg) {
    struct person *newNode = malloc (sizeof (struct person));
    if (newNode == NULL){
        printf("NULL");
    }
    newNode->name = newName;
    newNode->rg = newRg;
    newNode->next = head;
    head = newNode;
}

void newDataLinkedListEnd(char newName, char newRg) {
    struct person *newNode = malloc (sizeof (struct person));
    if (newNode == NULL){
        printf("NULL");
    }
    newNode->name = newName;
    newNode->rg = newRg;
    if(head == NULL){
        head = newNode;
    }
    else{
        struct person *lastNode = head;

        while(lastNode->next != NULL){
            lastNode = lastNode->next;
        }

        lastNode->next = newNode;
    }

}

void newDataLinkedListRandom(char newName, char newRg, int position) {
    int i;
    struct person *newNode = malloc (sizeof (struct person));
    if (newNode == NULL){
        printf("NULL");
    }
    newNode->name = newName;
    newNode->rg = newRg;

    struct person *helper = head;
    struct person *secondHelper = head;
    for(i=0; i<(position-1); i++){
        helper = helper->next;
    }
    for(i=0; i<position; i++){
        secondHelper = helper->next;
    }
    helper->next = newNode;
    newNode->next = secondHelper;
  
}


void newDataArrayBeggining(newName, newRg){
    int i;
    int auxName;
    int auxRg;
    
        if(people[0].name != NULL && people[0].rg != NULL){
            for(i = (MAX_ARRAY_SIZE - 1); i >= 0; i--){
                if(people[i].name != NULL && people[i].rg != NULL){
                    people[i+1].name = people[i].name;
                    people[i+1].rg = people[i].rg;
                }
            }
            people[0].name = newName;
            people[0].rg = newRg;
        }else{
            people[i].name = newName;
            people[i].rg = newRg;
        }
    
}

void newDataArrayEnd(newName, newRg){
    int i;

    if(people[0].name == NULL && people[0].rg == NULL){
        people[0].name = newName;
        people[0].rg = newRg;
    }else{
        for(i = 0; i < MAX_ARRAY_SIZE; i++){
            if(people[i].name == NULL && people[i].rg == NULL){
                people[i].name = newName;
                people[i].rg = newRg;
                break;
            }
        }   
    }
}

void newDataArrayPosition(newName, newRg, position){
    int i;

    for(i= (MAX_ARRAY_SIZE - 1); i>=position; i--){
        if(people[i].name != NULL && people[i].rg != NULL){
            people[i+1].name = people[i].name;
            people[i+1].rg = people[i].rg;
        }
    }

    people[position].name = newName;
    people[position].rg = newRg;

}

void newData(int action){
    char newName;
    char newRg;
    int position;
    fflush(stdin);
    printf("\n\n\nType the new Name: ");
    scanf("%c", &newName);
    fflush(stdin);
    printf("\nType the new RG: ");
    scanf("%c", &newRg);
    if(action == 1){
        newDataArrayBeggining(newName, newRg);
        newDataLinkedListBeggining(newName, newRg);
        // newDataLinkedListBeggining(&head, newName, newRg);
    }else if(action == 2){
        newDataArrayEnd(newName, newRg);
        newDataLinkedListEnd(newName, newRg);
    }else if(action == 3){
        printf("\nType the position: ");
        scanf("%d", &position);
        newDataArrayPosition(newName, newRg, position);
        newDataLinkedListRandom(newName, newRg, position);
    }
}

void displayList(){
    int i;
    int n =0;
    printf("\n\n\n|---------------------------------------------|\n");
    printf("|ARRAY LIST: ");
    for(i=0; i < MAX_ARRAY_SIZE; i++){
        if(people[i].name != NULL && people[i].rg != NULL){
            printf("\n| Name: %c", people[i].name);
            printf("\n| Rg: %c", people[i].rg);
            printf("\n| Position: %d", i);
            printf("\n|---------------------------------------------|");
            
        }else{
            break;
        }
    }
    printf("\n|---------------------------------------------|\n\n\n\n");


    struct person *temp = head;

    //iterate the entire linked list and print the data
    printf("\n\n\n|---------------------------------------------|\n");
    printf("|LINKED LIST: ");
    while(temp != NULL){
        printf("\n| Name: %c", temp->name);
        printf("\n| Rg: %c", temp->rg);
        printf("\n| Position: %d", n);
        temp = temp->next;
        n++;
        printf("\n|---------------------------------------------|");
    }
    printf("\n|---------------------------------------------|\n\n\n\n");

}

int main() {
    int action;
    // PEOPLE* Node;

    do{
        printf("|-------------------------------------------------------|\n");
        printf("|           SELECT THE WANTED OPTION                    |\n");
        printf("| 1: Insert data at the beggining of the list           |\n");
        printf("| 2: Insert data at the end of the list                 |\n");
        printf("| 3: Insert data at a random position of the list       |\n");
        printf("| 8: show the entire List                               |\n");
        printf("|-------------------------------------------------------|\n");
        printf(" Select and Option: ");
        scanf("%d", &action);
        switch (action){
            case 1:
                newData(action);
                break;
            case 2:
                newData(action);
                break;
            case 3:
                newData(action);
                break;
            case 8:
                displayList();
                break;
            
            default:
                break;
        }
    }while(action != 11);

    return 0;
}
