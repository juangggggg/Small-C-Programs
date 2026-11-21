/*
Program Requirements
Ask the user to enter 5 temperatures.
Store them in an array.
Use functions to analyze the data.
Use loops to process the array.
*/
#include <stdio.h>
typedef struct{
    int temps[5];
    int chkH;
     int chkL;
    float chkA;
}tempinfo;
/*
OUTPUT:
Temperatures: 30 32 28 35 31
Highest: 35
Lowest: 28
Average: 31.2
*/
void get_temperature(int tempre[5]);
int check_Highest_tempre(int tempre[5]);
int check_lowest_tempre(int tempre[5]);
float get_Average_temp(float temp);
void Display_All_Functions();
// main 
int main(){
    Display_All_Functions();
    return 0;
}
void get_temperature(int tempre[5]){
    scanf("%d %d %d %d %d", &tempre[0], &tempre[1], &tempre[2], &tempre[3], &tempre[4]);
}
int check_Highest_tempre(int tempre[5]){
    int i, max = tempre[0];
    for(i = 0; i < 5;i++){
        if(tempre[i] > max){
            max = tempre[i];
        }
    }
    return max;
}
int check_lowest_tempre(int tempre[5]){
    int i, min = tempre[0];
    for(i = 0; i < 5;i++){
        if(tempre[i] < min){
            min = tempre[i];
        }
    }
    return min;
}
float get_Average_temp(float temp){
    return temp / 5;
}
void Display_All_Functions(){   
       tempinfo s;
    printf("Enter 5 Temperature: ");  
    get_temperature(s.temps);
    s.chkH = check_Highest_tempre(s.temps);
    s.chkL = check_lowest_tempre(s.temps);
    for(int i = 0; i < 5; i++){
    s.chkA = s. chkA + s.temps[i];
    }
    float ave = get_Average_temp(s.chkA);
    printf("Highest: %d\n", s.chkH);
    printf("Lowest: %d\n", s.chkL);
    printf("Average: %.1f\n", ave);
}
