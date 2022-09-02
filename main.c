#include <stdio.h>

int sum;
int blockx[91], blocky[91];
int sodoku[10][10];

int checking()
{
    
}

void filling(int arr_location)
{
    if (blockx[arr_location] == -1)
    {
        if(checking()) sum+=1;
        return;
    }
    for (int i = 1; i<=9; i++)
    {
        sodoku[blockx[arr_location]][blocky[arr_location]] = i;
        filling(arr_location+1);
    }
}

int main()
{
    int block_location = 0;
    for (int i = 0 ; i<9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d ", &sodoku[i][j]);
            if (sodoku[i][j] != '0') blockx[block_location] = i, blocky[block_location++] = j;
        }
    }
    blockx[block_location] = -1, blocky[block_location] = -1;
    filling(0);
    printf("%d", sum);
}