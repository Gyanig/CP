#include<stdio.h>

int main()
{
   
    int i,j,temp;
    scanf("%d",&n);
    int mat[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }

//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<n;j++)
//        {
//            printf("%d\t",mat[i][j]);
//        }
//        printf("\n");
//    }

    //transpose logic using same matrix
    for(i=0;i<row;i++)
    {
        for(j=0;j<i;j++)
        {
            temp=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=temp;
        }
    }

    printf("The transpose of the matrix is\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
