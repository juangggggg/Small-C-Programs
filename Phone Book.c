#include <stdio.h>
#include <string.h>


typedef struct {
    char name[50];
    char phone[20];
} Contact;



void displayMenu();

void addContact(Contact contacts[], int *count);
void displayContacts(Contact contacts[], int count);
int searchContact(Contact contacts[], int count);
void editContact(Contact contacts[], int count);
void deleteContact(Contact contacts[], int *count);

int main(){
    displayMenu();
    return 0;
}

//interface typeshi
void displayMenu(){
    Contact contacts[100];
    int count = 0;
    int choice;
    

    do{
        printf("\n______________Contact MAnager______________\n");
        printf("1. Add Contacts\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");

        printf("Enter Choice\n->");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            addContact(contacts, &count);
            break;

        case 2:
            if(count == 0){
                printf("No Contacts Yet :/");
            }else{
                displayContacts(contacts, count);
            }
            
            break;

        case 3:
            int index = searchContact(contacts, count);

                if(index != -1){
                    printf("\n______Contact Found______\n");
                    printf("Name   : %s\n", contacts[index].name);
                    printf("Phone  : %s\n", contacts[index].phone);
                }else{
                    printf("No Contact Found :/");
                }

            break;
        
        case 4:
            editContact(contacts, count);
            break;

        case 5:
            deleteContact(contacts, &count);
            break;

        case 6:
            printf("Exiting Platform........");
            break;
        default:
            break;
        }

    }while(choice != 6);
}
// add sumthn
void addContact(Contact contacts[], int *count){


    printf("\n_________Add Contact_________\n");
    printf("Enter Number\n->");
    scanf("%19s", contacts[*count].phone);

    printf("Enter Name\n->");
    scanf("%49s", contacts[*count].name);
    printf("Contact Added\n");

    (*count)++;
}

//display
void displayContacts(Contact contacts[], int count){

    for(int i = 0; i < count;i++){
        printf("\n\t\t______________________Contacts______________________\n");
        printf("\n%d. %s %s\n", i, contacts[i].name, contacts[i].phone);
    }

}

//search
int searchContact(Contact contacts[], int count){
    char searchname[50];

    printf("\n_________Search Contact_________\n");
    printf("Enter Name\n->");
    scanf("%49s", searchname);

    for(int i = 0;i < count;i++){
        if(strcmp(contacts[i].name, searchname) == 0){
            return i;
        }
    }
    return -1;
}


//edit contact
void editContact(Contact contacts[], int count){
    int index;

    index = searchContact(contacts, count);

    if(index != -1){
        printf("\n_________Search Contact_________\n");

        printf("Enter New Name\n->");
        scanf("%49s", contacts[index].name);

        printf("Enter New Phone\n->");
        scanf("%19s", contacts[index].phone);

        printf("Contact Updated Successfully!\n");
    }else{
        printf("No Contacts Found :/");
    }

}

//delete shi
void deleteContact(Contact contacts[], int *count){
    int index;


    index = searchContact(contacts, *count);
    if(index != -1){
        for(int i = index; i < *count - 1;i++){
            contacts[i]  = contacts[i + 1];
        }
        (*count)--;

        printf("Deleted Successfully ");
    }else{
        printf("No Contact Found :/");
    }

}