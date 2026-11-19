

#include <stdio.h>
#include <string.h>


typedef struct {
    int choice;
    char username[50];
    char password[50];
} Account;

void displayMenu(Account *infostack);


// account passsword limiter
void passwordCount(Account *accountt);


void registerAccount(Account *account);
void login(Account account);
void displayAccount(Account account);
void changePassword(Account *account);


int main(){
    Account infostack;
    displayMenu(&infostack);
    return 0;
}

void displayMenu(Account *infostack){

    while(infostack->choice != 5){
    printf("\n=== Sign in ===\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Display\n");
    printf("4. Change Password\n");
    printf("5. Exit\n");
    printf("Enter ");
    scanf("%d", &infostack->choice);


    switch (infostack->choice){
    case 1:
        registerAccount(infostack);
        break;

    case 2:
        login(*infostack);
        break;

    case 3:
        displayAccount(*infostack);
        break;

    case 4:
        changePassword(infostack);
        break;

    case 5:
        printf("Exiting Interface...");
        break;
    
    default:
        break;
    }
    }
}

void passwordCount(Account *accountt){
    int passcount[0];

    scanf("%49s", accountt->password);

    for(int i = 0;i < passcount;i++){
        if()

    }
}

void registerAccount(Account *account){
    printf("\n=== Sign In ===\n");
    printf("Create Username\n->");
    scanf("%49s", account->username);

    printf("Create Password\n->");
    scanf("%49s", account->password);
    printf("Successfully Signed In!\n");

}
void login(Account account){
    char Entered_password[50];
    char Entered_Username[50];

    do{
    printf("\n=== Login ===\n");
    printf("Enter Username\n");
    scanf("%49s", Entered_Username);

    printf("Enter Password\n");
    scanf("%49s", Entered_password);


    if (strcmp(Entered_Username, account.username) == 0 && strcmp(Entered_password, account.password) == 0){
        printf("Login Successful!");
    }else{
        printf("Wrong Username or Password, Try again.\n");
    }
    }while(strcmp(Entered_Username, account.username) != 0 || strcmp(Entered_password, account.password) != 0);
    
}
void displayAccount(Account account){
        printf("\n=== Accounts ===\n");
        printf("Username: %s\n", account.username);
        printf("Password: %s\n", account.password);
}
void changePassword(Account *account){
    char Entered_Password[50];
    char Enter_New_Password[50];


    printf("\n=== Change Password ===\n");

    printf("Enter Current Password: ");
    scanf("%49s", Entered_Password);

    if(strcmp(Entered_Password, account->password) == 0){
        printf("Enter New Password: ");
        scanf("%49s", Enter_New_Password);
        strcpy(account->password, Enter_New_Password);
        printf("New Password Entered Successfull.y");
    }else{
        printf("Current Password Incorrect.  :(");
    }

}