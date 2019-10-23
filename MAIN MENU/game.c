#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<dos.h>
#include <MMsystem.h>

main()
{
    PlaySound(("bgm.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

    start:
    system("cls");
    printf("Press: \n");
    printf("\t1. For TIC TAC TOE\n");
    printf("\t2. For TETRIS\n");
    printf("\t3. For STAR WARS\n");
    printf("\t4. For TREASURE ISLAND\n");
    printf("And enter ");
    int n; scanf("%d", &n);

    switch (n){
        case 1:
            ShellExecute(NULL, "open", "Tic Tac Toe.exe", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 2:
            ShellExecute(NULL, "open", "mainmenu tetris.exe", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 3:
            ShellExecute(NULL, "open", "StarWar.exe", NULL, NULL, SW_SHOWNORMAL);
            break;
        case 4:
            ShellExecute(NULL, "open", "Game Production(201914044).exe", NULL, NULL, SW_SHOWNORMAL);
            break;

    }

    PlaySound(NULL, NULL, 0);
    getchar();
    printf("Wanna play another game??? y/n: ");
    char ch;
    ch = getchar();

    if(ch == 'y' || ch == 'Y') goto start;

    return 0;
}
