#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_ARRAY_SIZE = 100000000;

struct person {
    char *name;
    char *rg;

    struct person *next;
};

struct header {
    struct person *first;
    struct person *last;
};

typedef struct person PEOPLE;

struct person people[MAX_ARRAY_SIZE];

struct header header;


void newDataLinkedListBeggining(char newName[50], char newRg[50]) {
    struct person *newNode = malloc (sizeof (struct person));
    if (newNode == NULL){
        printf("NULL");
    }

    newNode->name = strdup(newName);
    newNode->rg = strdup(newRg);
    newNode->next = header.first;
    header.first = newNode;
    if(header.last == NULL){
        header.last = newNode;
    }

}

void newDataLinkedListEnd(char *newName, char *newRg) {
    struct person *newNode = malloc (sizeof (struct person));
    if (newNode == NULL){
        printf("NULL");
    }
    newNode->name = strdup(newName);
    newNode->rg = strdup(newRg);
    if(header.first == NULL){
        header.first = newNode;
    }
    if(header.last == NULL){
        header.last = newNode;
    }else{
        struct person *lastNode = header.last;
        lastNode->next = newNode;
        header.last = newNode;
    }
}

void newDataLinkedListRandom(char *newName, char *newRg, int position) {
    int i;
    struct person *newNode = malloc (sizeof (struct person));
    if (newNode == NULL){
        printf("NULL");
    }
    newNode->name = strdup(newName);
    newNode->rg = strdup(newRg);

    struct person *helper = header.first;
    struct person *secondHelper = header.first;
    for(i=0; i<(position-1); i++){
        helper = helper->next;
    }
    for(i=0; i<position; i++){
        secondHelper = helper->next;
    }
    helper->next = newNode;
    if(secondHelper == NULL){
        header.last = (newNode);
        newNode->next = NULL;
    }else{
        newNode->next = secondHelper;
    } 
}


void newDataArrayBeggining(char *newName, char *newRg){
    int i = 0;    
        if(people[0].name != NULL && people[0].rg != NULL){

            for(i = (MAX_ARRAY_SIZE - 1); i >= 0; i--){
                if(people[i].name != NULL && people[i].rg != NULL){
                    people[i+1].name = strdup(people[i].name);
                    people[i+1].rg = strdup(people[i].rg);
                }
            }
            people[0].name = strdup(newName);
            people[0].rg = strdup(newRg);
        }else{
            people[i].name = strdup(newName);
            people[i].rg = strdup(newRg);
        }
    
}

void newDataArrayEnd(char *newName, char *newRg){
    int i;
    if(people[0].name == NULL && people[0].rg == NULL){
        people[0].name = strdup(newName);
        people[0].rg = strdup(newRg);

    }else{
        for(i = 0; i < MAX_ARRAY_SIZE; i++){
            if(people[i].name == NULL && people[i].rg == NULL){
                people[i].name = strdup(newName);
                people[i].rg = strdup(newRg);
                break;
            }
        }
    }
}

void newDataArrayPosition(char *newName, char *newRg, int position){
    int i;

    for(i= (MAX_ARRAY_SIZE - 1); i>=position; i--){
        if(people[i].name != NULL && people[i].rg != NULL){
            people[i+1].name = strdup(people[i].name);
            people[i+1].rg = strdup(people[i].rg);
        }
    }

    people[position].name = strdup(newName);
    people[position].rg = strdup(newRg);

}

void newData(int action){
    char newName[50];
    char newRg[50];
    int position;
    fflush(stdin);
    printf("\n\n\nType the new Name: ");
    // scanf("%d", &newName);
    scanf("%s", newName);
    fflush(stdin);
    printf("\nType the new RG: ");
    scanf("%s", newRg);
    // scanf("%s", newRg);
    if(action == 1){
        newDataArrayBeggining(newName, newRg);
        newDataLinkedListBeggining(newName, newRg);
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

void readFile(int option){
    int i = 0;
    FILE * file;

   char * buffer = malloc( 100 * sizeof(char));     
   char ret = '\0';
   int count = 0;

   switch(option){
        case 1:
            file = fopen("files/NomeRG10.txt","r");
            break;
        case 2:
            printf("HERE");
            file = fopen("files/NomeRG50.txt","r");
            break;
        case 3:
            file = fopen("files/NomeRG100.txt","r");
            break;
        case 4:
            file = fopen("files/NomeRG1K.txt","r");
            break;
        case 5:
            file = fopen("files/NomeRG10K.txt","r");
            break;
        case 6:
            file = fopen("files/NomeRG1M.txt","r");
            break;
        case 7:
            file = fopen("files/NomeRG100M.txt","r");
            break;
        default:
            printf("ERROR");
            break;
        
        

   }


    do {
        ret = fscanf(file, "%s", buffer);
        char * token = strtok(buffer, ",");
        struct person *newNode = malloc (sizeof (struct person));
        while( token != NULL ) {

            if(count%2 == 0){
                people[i].name = strdup(token);

                newNode->name = strdup(token);

                

            }else if(count%2 != 0){
                people[i].rg = strdup(token);
                
                newNode->rg = strdup(token);

            }

            count++;
            token = strtok(NULL, " ");

        }
        if(header.first == NULL){
            header.first = newNode;
        }
        if(header.last == NULL){
            header.last = newNode;
        }else{
            struct person *lastNode = header.last;
            lastNode->next = newNode;
            header.last = newNode;
        }
        i++;

    } while (ret != EOF);


    printf("|--------------------------------------------------------|\n");
    printf("|             DONE READING THE FILE                      |\n");
    printf("|--------------------------------------------------------|\n");
}

void displayList(){
    int i;
    int n =0;
    printf("\n\n\n|---------------------------------------------|\n");
    printf("|ARRAY LIST: ");
    for(i=0; i < MAX_ARRAY_SIZE; i++){
        if(people[i].name != NULL && people[i].rg != NULL){
            printf("\n| Name: %s", people[i].name);
            printf("\n| Rg: %s", people[i].rg);
            printf("\n| Position: %d", i);
            printf("\n|---------------------------------------------|");
            
        }else{
            break;
        }
    }
    printf("\n|---------------------------------------------|\n\n\n\n");


    struct person *temp = header.first;

    printf("\n\n\n|---------------------------------------------|\n");
    printf("|LINKED LIST: ");
    while(temp != NULL){
        printf("\n| Name: %s", temp->name);
        printf("\n| Rg: %s", temp->rg);
        printf("\n| Position: %d", n);
        temp = temp->next;
        n++;
        printf("\n|---------------------------------------------|");
    }
    printf("\n|---------------------------------------------|\n\n\n\n");

}

int main() {
    int action;
    int file;
    do{
        printf("|--------------------------------------------------------|\n");
        printf("|           SELECT THE WANTED OPTION                     |\n");
        printf("| 1 : Insert data at the beggining of the list           |\n");
        printf("| 2 : Insert data at the end of the list                 |\n");
        printf("| 3 : Insert data at a random position of the list       |\n");
        printf("| 8 : show the entire List                               |\n");
        printf("| 10: Read list from a file                              |\n");
        printf("|--------------------------------------------------------|\n");
        printf(" Select an Option: ");
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
            case 10:
                printf("\n\n");
                printf("|--------------------------------------------------------|\n");
                printf("|                 CHOOSE THE FILE                        |\n");
                printf("| 1: 10    Names                                         |\n");
                printf("| 2: 50    Names                                         |\n");
                printf("| 3: 100   Names                                         |\n");
                printf("| 4: 1K    Names                                         |\n");
                printf("| 5: 10K   Names                                         |\n");
                printf("| 6: 1M    Names                                         |\n");
                printf("| 7: 100M  Names                                         |\n");
                printf("|--------------------------------------------------------|\n");
                printf(" Select an Option: ");
                scanf("%d", &file);
                readFile(file);
                break;
            
            default:
                printf("ERROR");
                break;
        }
    }while(action != 11);

    return 0;
}
