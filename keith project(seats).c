#include <stdio.h>
#include <stdlib.h>

void seats( double [] , int);
void mapSeats();
char movieMenu(char);

int main()
{
    const int rowNum = (12.0);
    double rowValue[rowNum]; //array to hold row pices
    char selection;
    int row2, col2;
    int i, j, k;
    const char TAKEN = 'T';//seats taken
    const char EMPTY = '*';//seats free
    const int row = 10;//number of rows
    const int col = 12;//number of col
    char map[row][col];//array to hold seat chart
    
    
    for(int i= 0;i<row;i++)//initiating array
    {
        for (int j=0;j<col;j++)
        {
            map[i][j]=EMPTY;
        }
    }
    
    mapSeats();
    
    seats(rowValue, rowNum);//ask user to enter price of each row
    printf("\n");
    
    do
    {
        printf("MOVIE THEATER MENU\n");
        printf("------------------\n");
        printf("1) Sell a ticket\n");
        printf("Q) Quit program\n");
        printf("Please make a selection\n");
        scanf("%c",&selection);
        
        if(selection =='1')
        {
            printf("Please enter a row number and a seat number for the ticket: ");
            printf("Row :");
            scanf("%d",&row2);
            printf("\n");
            printf("Seat :");
            scanf("%d",&col2);
            printf("\n");
            
            if(map[row2][col2] == TAKEN)// Check if seat is free
            {
                printf("This seat is taken! Try another one. \n");
                continue; // start the loop again
            }
            else // and if it is - sell the ticket
                map[row2][col2]=TAKEN;
            // Add the next loop to immediately see the effects:
            for (int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    printf("%c", map[i][j]);
                }
                printf("\n");
            }
            
        }
        else if(selection =='q'||selection=='Q')
        {
            printf("Thank you for using the program.\n");
        }
        else if(selection != '1' || selection !='q')
        {
            printf("Invalid selection.\n");
        }
    }while(selection != '1' || selection !='q');
    
    system("PAUSE");
    return 0;
}

void seats(double rowPrice[], int row)
{
    
    printf("Please enter a ticket price for each row.\n");
    
    for (int i = 0 ; i < row; i++)
    {
        printf("Row: ");
        scanf("%lf", &rowPrice[i]);
    }
}

void mapSeats()
{
    const char TAKEN = 'T';//seats taken
    const char EMPTY = '*';//seats free
    const int rw=10;
    const int cl=12;
    
    printf("Seats");
    for (int k = 0 ; k <12;k++) //loop to display nums 0 to 12
    {
        printf("%2d", k);
    }
    
    for (int i = 0 ; i <rw;i++)//making array display what's in it
    {
        printf("\nRow %d",i);
        for (int j = 0 ; j <cl;j++)
        {
            printf("%2c", EMPTY);
        }
    }
    printf("\n");
}

