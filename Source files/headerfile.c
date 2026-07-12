#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "headerfile.h"

struct tm{
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

struct tm *data();
char *dayname(int dnum);
char *monthname(int mnum);
void cursor(int lines);
void userChoice();

int isRunning=1;
struct tm *pTime = NULL;

void currentTime(){
    while(isRunning){
        pTime= data();

        printf("\r%02d:%02d:%02d\n\n",pTime->tm_hour,pTime->tm_min,pTime->tm_sec);
        printf("\rPress (0 to exit) or (1 to restart)!\n");
        cursor(3);
        if(kbhit()){
            char exit=getch();
            if(exit=='0'){
                break;
            }
            else if(exit=='1'){
                system("cls");
                printf("Restarting.......");
                Sleep(1500);
                system("cls");
                userChoice();
            }
        }
        Sleep(1000);
    }
}

void currentDay(){
    while(isRunning){
        pTime= data();
        char *day="\0";
        day=dayname((*pTime).tm_wday);

        printf("\r%s     \n\n",day);
        printf("\rPress (0 to exit) or (1 to restart)!\n");
        cursor(3);
        if(kbhit()){
            char exit=getch();
            if(exit=='0'){
                break;
            }
            else if(exit=='1'){
                system("cls");
                printf("Restarting.......");
                Sleep(1500);
                system("cls");
                userChoice();
            }
        }
        Sleep(1000);
    }
}

void currentDate(){
    while(isRunning){
        pTime=data();
        char *month="\0";
        month=monthname((*pTime).tm_mon);

        printf("\r%02d %s %d \n\n",pTime->tm_mday,month,(pTime->tm_year)+1900);
        printf("\rPress (0 to exit) or (1 to restart)!\n");
        cursor(3);
        if(kbhit()){
            char exit=getch();
            if(exit=='0'){
                break;
            }
            else if(exit=='1'){
                system("cls");
                printf("Restarting.......");
                Sleep(1500);
                system("cls");
                userChoice();
            }
        }
        Sleep(1000);
    }
}

void current(){
    while(isRunning){
        pTime=data();
        char *month="\0";
        char *day="\0";
        month=monthname((*pTime).tm_mon);
        day=dayname((*pTime).tm_wday);
        
        printf("\r%02d %s %d \n",pTime->tm_mday,month,(pTime->tm_year)+1900);
        printf("\r%s     \n",day);
        printf("\r%02d:%02d:%02d\n\n",pTime->tm_hour,pTime->tm_min,pTime->tm_sec);
        printf("\rPress (0 to exit) or (1 to restart)!\n");
        cursor(5);
        if(kbhit()){
            char exit=getch();
            if(exit=='0'){
                break;
            }
            else if(exit=='1'){
                system("cls");
                printf("Restarting.......");
                Sleep(1500);
                system("cls");
                userChoice();
            }
        }
        Sleep(1000);
    }
}

void userChoice(){
    int choice=0;
    char buffer;
    
    printf("HELLO!\n\nFor Everything, Enter 1\nFor Time, Enter 2\nFor Day, Enter 3\nFor Date, Enter 4\n\nENTER YOUR CHOICE: ");
    scanf("%d", &choice);
    while((buffer=getchar())!= '\n'&& buffer!= '\0');
    Sleep(500);
    system("cls");
    switch(choice){
        case 1:
            current();
            break;
        case 2:
            currentTime();
            break;
        case 3:
            currentDay();
            break;
        case 4:
            currentDate();
            break;
        default:
            printf("Please Enter A Valid Choice!\nRestarting.......\n\n");
            Sleep(2000);
            system("cls");
            userChoice();
    }
}

char *dayname(int dnum){
    char *day="/0";
    
    switch(dnum){
        case 0:
            day="Sunday";
            break;
        case 1:
            day="Monday";
            break;
        case 2:
            day="Tuesday";
            break;
        case 3:
            day="Wednesday";
            break;
        case 4:
            day="Thursday";
            break;
        case 5:
            day="Friday";
            break;
        case 6:
            day="Saturday";
            break;
    }
    return day;
}

char *monthname(int mnum){
    char *month="\0";
    
    switch(mnum){
        case 0:
            month="Jan";
            break;
        case 1:
            month="Feb";
            break;
        case 2:
            month="Mar";
            break;
        case 3:
            month="Apr";
            break;
        case 4:
            month="May";
            break;
        case 5:
            month="Jun";
            break;
        case 6:
            month="Jul";
            break;
        case 7:
            month="Aug";
            break;
        case 8:
            month="Sep";
            break;
        case 9:
            month="Oct";
            break;
        case 10:
            month="Nov";
            break;
        case 11:
            month="Dec";
            break;
    }
    return month;
}

void cursor(int lines){
    HANDLE hConsole;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

    if(GetConsoleScreenBufferInfo(hConsole, &csbi)){
        csbi.dwCursorPosition.Y -=lines;
        if(csbi.dwCursorPosition.Y<0){
            csbi.dwCursorPosition.Y=0;
        }
        csbi.dwCursorPosition.X=0;
        SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
    }
}

struct tm *data(){
    time_t rawtime = 0;
    time(&rawtime);
    return localtime(&rawtime);
}