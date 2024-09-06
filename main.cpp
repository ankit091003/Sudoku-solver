#include <bits/stdc++.h>
bool ispossible(int row,int col,int val,vector<vector<int>>& sudoku){

    for(int i=0;i<sudoku.size();i++){

        if(sudoku[row][i]==val){
            return 0;
        }
        if(sudoku[i][col]==val){
            return 0;
        }
        if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>& sudoku){

    for(int i=0;i<sudoku.size();i++){

        for(int j=0;j<sudoku.size();j++){

            if(sudoku[i][j]==0){

                for(int val=1;val<=9;val++){

                    if(ispossible(i,j,val,sudoku)){

                        sudoku[i][j]=val;
                        bool forward=solve(sudoku);
                        if(forward){
                            return 1;
                        }else{
                            sudoku[i][j]=0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;

}
void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
    return;
} 
