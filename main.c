#include <stdio.h>
#include <stdlib.h>

const MAX_ARRAY_SIZE = 100000000;

struct list {
    char name[50];
    char rg[50];
    struct list *next;
    struct list *before;
};

typedef struct list LIST;

// void newDataLinkedListBeggining(LIST* l, name, rg) {
//     struct list *new = malloc (sizeof (struct list));
//     if (new == NULL){
//         return NULL;
//     }
//     new->name = name;
//     new->rg = rg;
//     new->next = l;
// }

void newDataArrayBeggining(arrayList, nameList, rgList, newName, newRg){
    int i;
    char auxName[50];
    char auxRg[50];
    for(i=0; i < MAX_ARRAY_SIZE; i++){
        if(nameList[i] != null && rgList[i] != null){
            if(i=0){
                auxName = nameList[i];
                auxRg = rgList[i];
                name[i] = newName;
                rg[i] = newRg;
            }else {
                name[]
            }
        }
    }
}

void newDataBegginning(arrayList, nameList, rgList){

}

void main() {
    int arrayList[MAX_ARRAY_SIZE];
    char nameList[MAX_ARRAY_SIZE][50];
    char rgList[MAX_ARRAY_SIZE][50];
    int action = 0;
    LIST* Node; 

    do{
        printf("|---------------------------------------------|\n");
        printf("|           SELECT THE WANTED OPTION          |\n");
        printf("| 1: Insert data at the beggining of the list |\n");
        printf("|---------------------------------------------|\n");
        printf(" Type: ");
        scanf("%d", &action);
        switch (action)
        {
        case 1:
            newDataBegginning(arrayList, nameList, rgList);
            break;
        
        default:
            break;
        }
    }while(action != 11)
}
