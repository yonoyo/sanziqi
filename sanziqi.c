#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void menu(){
    printf("*********************\n");
    printf("1.play        0.exit\n");
    printf("*********************\n");
}


void Intnboard(char arr[ROW][COL], int row, int col){
    int i = 0, j = 0;

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            arr[i][j] = ' ';
}
void display(char arr[ROW][COL], int row, int col){
    int i = 0, j = 0;
    for (i = 0; i < row; i++){
        printf(" %c | %c | %c \n", arr[i][0], arr[i][1], arr[i][2]);
        if (i < row - 1)
            printf("---|---|---\n");
    }
}

void player(char arr[ROW][COL], int row, int col){
    int x = 0, y = 0;
    printf("ÕÊº“◊ﬂ£∫\n");
    while (1)
    {
        printf("«Î ‰»Î“™◊ﬂµƒŒª÷√:");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= row  &&  y >= 1 && y <= col)
        {
            if (arr[x - 1][y - 1] ==' ')
            {
                arr[x - 1][y - 1] = '*';
                break;
            }

            else
            {

                printf("∏√Œª÷√±ª’º¡Ï\n");
            }

        }
        else
        {
            printf(" ‰»Î∑«∑®£¨«Î÷ÿ–¬ ‰»Î");
        }
    }
}

void computer(char arr[ROW][COL], int row, int col){
    int x = 0, y = 0;
    printf("µÁƒ‘£∫\n");
    while (1){
        x = rand() % row;
        y = rand() % col;
        if (arr[x][y] ==' '){
            arr[x][y] = '#';
            break;
        }

    }

}

int isfull(char arr[ROW][COL], int row, int col){
    int i = 0, j = 0;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            if (arr[i][j] == ' ')
                return 0;
        }

    }
  return 1;
}


char boolw(char arr[ROW][COL], int row, int col){
    for (int i = 0; i < row; i++){
        if (arr[i][0] == arr[i][1] == arr[i][2] && arr[i][0] != ' ')
            return arr[i][0];
    }


    for (int i = 0; i < row; i++){
        if (arr[0][i] == arr[1][i] == arr[2][i] && arr[0][i] != ' ')
            return arr[0][0];
    }



    if (arr[0][0] == arr[1][1] == arr[2][2] && arr[0][0] != ' ')
        return arr[1][1];

    if (arr[2][0] == arr[1][1] == arr[2][2] && arr[0][2] != ' ')
        return arr[1][1];

    if (1 == isfull(arr, ROW, COL)){
        return 'C';
    }
    else
        return 'Q';



}



void play(){
    int ret = 0;
    char arr[ROW][COL] = { 0 };
    Intnboard(arr, ROW, COL);
    display(arr, ROW, COL);
    while (1){
        player(arr, ROW, COL);
        display(arr, ROW, COL);
        ret=boolw(arr, ROW, COL);
        if (ret == 'C')
            break;
        computer(arr,ROW,COL);
        display(arr, ROW, COL);
        ret=boolw(arr, ROW, COL);
        if (ret == 'C')
            break;
    }
    if (ret == '*')
        printf("ÕÊº“”Æ\n");
    else if (ret == '#')
        printf("µÁƒ‘”Æ\n");
    else
        printf("∆Ωæ÷\n");
    
    
}
    


int main(){
    srand((unsigned int)time(NULL));
    menu();
    int input = 0;
    do{
        printf("«Î—°‘Ò£∫\n");
        scanf("%d", &input);
        switch (input){
        case 1:
            play();
            break;
        case 0:
            printf("ÕÀ≥ˆ\n");
            break;
        default:
            printf("—°‘Ò¥ÌŒÛ£¨«Î÷ÿ–¬ ‰»Î£°£°£°\n");
            break;
        }
        }while (input);
        system("pause");
        return 0;
    }
    
