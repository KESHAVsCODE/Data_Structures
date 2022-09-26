#include<stdio.h>
#include<conio.h>
void main()
{
    int a[4][4],b[4][4],c[4][4],sum=0,i,j,k;
    printf("ENTER 16 ELEMENT IN FIRST ARRAY :");
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("ENTER 16 ELEMENT IN SECOND ARRAY :");
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            sum=0;
            for(k=0;k<=3;k++)
                sum=sum+a[i][k]*b[k][j];
            c[i][j]=sum;
        }
    }
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            printf("  %d",c[i][j]);
        }
        printf("\n");
    }
    getch();
}
