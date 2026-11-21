#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototypes
void get_Passcode(char pass_code[50]);
bool check_Password_strenght(char pass_code[50]);
int check_lenght(char password[50]);
void Operating_Function();

// Variables
struct information {
    char passcode[50];
};

int main() {
    Operating_Function();
    return 0;
}

void get_Passcode(char pass_code[50]) {
    scanf("%49s", pass_code);
}

bool check_Password_strenght(char pass_code[50]) {
    bool upper = false;
    bool digit = false;
    bool punct = false;

    for(int i = 0; pass_code[i] != '\0'; i++) {
        if(isupper((unsigned char)pass_code[i]))
            upper = true;

        if(isdigit((unsigned char)pass_code[i]))
            digit = true;

        if(ispunct((unsigned char)pass_code[i]))
            punct = true;
    }

    if(upper && digit && punct) {
        return true;
    } else {
        return false;
    }
}

int check_lenght(char password[50]) {
    int i = 0;

    while(password[i] != '\0') {
        i++;
    }

    return i;
}

void Operating_Function() {
    struct information a1;
    int i = 0;

    while(i < 3) {

        printf("Input: ");
        get_Passcode(a1.passcode);

        bool chp;
        int ckl;

        chp = check_Password_strenght(a1.passcode);
        ckl = check_lenght(a1.passcode);

        if(ckl < 8 || chp != true) {
            printf("Password strength: Weak.\n");
            i++;
        } else {
            printf("Password strength: Strong\n");
            break;
        }
    }
}