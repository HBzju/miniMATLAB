#include "rank.h"
//求矩阵的秩
int myRank(Matrix* mat,int row, int column){
    int i=0;
    int j=0;
    double matr[row][column];
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            matr[i][j]=getMatrix(mat,i,j);
        }
    }
    double temp;
    for(j=0;j<column-1&&j<row;j++){
        for(i=0;i<row-1-j;i++){
            if(matr[i][j]!=0){
                temp=matr[i][j];
                for(int k=j;k<column;k++){
                    matr[i][k]-=matr[row-1-j][k]*temp/matr[row-1-j][j];;
                }
            }
        }
    }

    int ranks=row;
    bool flag;
    for(int k=0;k<row;k++){
        flag=true;
        for(int t=0;t<column;t++){
            if(matr[k][t]!=0){
                flag=false;
                break;
            }
        }
        if(!flag)
           continue;
        ranks-=1;
    }
    return ranks;
}
