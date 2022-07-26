#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
//*************************  FUNCTION 1 --> Generating the random number  *************************

int generateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

//*************************  FUNCTION 2 --> Introduction of the game  *************************

void intro()
{
    printf("\t\t\t\t\t\t||ROCK||PAPER||SCISSOR||\n");
    printf("\t\t\t\t\t\t\t  |GAME|     \t\t\t\t by -> CodeEaze.com \n");
    printf("_______________________________________________________________________________________________________________________________________\n");
    printf("\t\t\t\t\t\t        ||WELCOME||\n");
    printf("\n\nINSTRUCTIONS :\n\n1.THIS GAME IS BETWEEN YOU AND THE COMPUTER.\n2.YOU HAVE TO FIRST ENTER YOUR NAME.\n");
    printf("3.CHOOSE 1 FOR ROCK \t2 FOR PAPER \t3 FOR SCISSOR.\n");
    printf("4.IF YOU NOT ENTER ONE THE THREE NUMBERS IT WILL BE THE WRONG INPUT.\n");
    printf("5.ROCK(r) VS SCISSOR(p)  --> ROCK(s) WINS!\n6.ROCK(r) VS PAPER(p)    --> PAPER(s) WINS!\n7.SCISSOR(s) VS PAPER(p) --> PAPER(p) WINS!\n");
    printf("\n\n\t\t\t\t\t\t    ||Best of luck||\n");
    printf("_______________________________________________________________________________________________________________________________________\n");
}

//*************************  FUNCTION 3 --> For calculating the winner of each turn   *************************

int largest(char p1, char c1)
{

    if (p1 == c1)
    {
        return -1;
    }
    if ((p1 == 'r') && (c1 == 's'))
    {
        return 1;
    }
    if ((p1 == 's') && (c1 == 'p'))
    {
        return 1;
    }
    if ((p1 == 'p') && (c1 == 'r'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//*************************  FUNCTION 4 --> For generating the time and also for greeting the user   *************************

void greet(char *playerName)
{

    time_t t;
    time(&t);
    printf("\n%s", ctime(&t));
    time_t s, val = 1;
    struct tm *current_time;

    // time in seconds
    s = time(NULL);

    // to get current time
    current_time = localtime(&s);
    if (current_time->tm_hour >= 5 && current_time->tm_hour < 12)
    {
        printf("\nA Very GOOD MORNING %s !\n", playerName);
    }
    else if (current_time->tm_hour >= 12 && current_time->tm_hour < 17)
    {
        printf("\nGOOD AFTERNOON %s !\n", playerName);
    }
    else if (current_time->tm_hour >= 17 && current_time->tm_hour < 21)
    {
        printf("\nGOOD EVENING %s !\n", playerName);
    }
    else
    {
        printf("\nGOOD NIGHT %s !\n", playerName);
    }
}

//*************************  FUNCTION 5 --> For thanks the user for playing the game   *************************
void thanks(char *playerName)
{
    printf("\n\n ----->>>>>     THANKS FOR PLAYING OUR GAME %s.     <<<<<-----\n", playerName);
    printf("______________________________________________________________________________________\n");
}

//*************************  FUNCTION 6 --> For the gamePlay   *************************

void gameBuild()
{
    int pScore = 0, comScore = 0, extra, turns;
    char pChar, comChar;
    char rps[] = {'r', 'p', 's'};
    char playerName[50];
    printf("\n\nPlease Enter Your Name :");
    gets(playerName);
    greet(playerName);

    printf("\nEnter the times you want to play:");
    scanf("%d", &turns);
    fflush(stdin);
    for (int i = 0; i < turns; i++)
    {
        printf("\n.................................................\n");
        //player1's input
        printf("%s's Turn!  [%d]\n", playerName, i + 1);
        printf("\nChoose : 1 for Rock. 2 for Paper. 3 for Scissor :");
        scanf("%d", &extra);
        if (extra != 1 && extra != 2 && extra != 3)
        {
            printf("\n oops!!Wrong input So 1 turn waste\n");
            printf("\nScores :\n| %s's score :   %d | --> | com's score : %d |\n", playerName, pScore, comScore);

            continue;
        }
        else
        {
            pChar = rps[extra - 1];
            //generate com's input
            printf("\nCom's Turn!  [%d]\n", i + 1);
            extra = generateRandomNumber(3) + 1;
            printf("\nCom's choose %d\n", extra);
            comChar = rps[extra - 1];
            if (largest(pChar, comChar) == 1)
            {
                pScore += 1;
                printf("\n*************************");
                printf("\n%s earn a point!\n", playerName);
                printf("*************************");
            }
            else if (largest(pChar, comChar) == -1)
            {
                pScore += 1;
                comScore += 1;
                printf("\n*************************");
                printf("\nBoth Players earn a point!\n");
                printf("*************************");
            }
            else
            {
                comScore += 1;
                printf("\n*************************");
                printf("\ncom's earn a point!\n");
                printf("*************************");
            }
            printf("\nScores :\n| %s's score : %d | --> | com's score : %d |\n", playerName, pScore, comScore);
        }
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    if (pScore > comScore)
    {

        printf("\t\t\a\aCongrats...!!! %s wins !", playerName);
    }
    else if (pScore == comScore)
    {
        printf("\t\tOOPS, MATCH TIED!");
    }
    else
    {
        printf("\t\t%s LOST THE GAME!", playerName);
    }

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    thanks(playerName);
}

//*************************  FUNCTION 7 --> Driver Function   *************************

int main()
{
   
    
    intro();
    gameBuild();    
    getch();
    return 0;
}
