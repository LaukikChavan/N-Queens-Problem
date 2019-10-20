#include<iostream>
#include <stdbool.h> 
#define MAX_NO 100;

using namespace std;

class chessBorad{
    int N, board[100][100];
public:
    chessBorad(){
        cout << "Enter The Number Of Queens :- ";
        cin >> N;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                board[i][j] = 0;
            }
        }
        
        printBorad();
        
        if(placingQueen(0) == false){
            cout << "\n\n***** Not Solution to this Problem *****\n\n";
        }else{
            printBorad();        
        }
    }
    
    bool isSafeToPlace(int row, int col){
            int i, j;
            for (i = 0; i < col; i++) 
                if (board[row][i]) 
                    return false; 
        
            for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
                if (board[i][j]) 
                    return false; 
        
            for (i = row, j = col; j >= 0 && i < N; i++, j--) 
                if (board[i][j]) 
                    return false; 
        
            return true; 
    }
    
    bool placingQueen(int col){
        if(col >= N){
            return true;
        }
        for(int i=0;i<N;i++){
            if(isSafeToPlace(i , col)){
                board[i][col] = 1;
                if(placingQueen(col+1)) 
                    return true;
                    
                board[i][col] = 0;
            }
        }
        return false;
    }
    
    void printBorad(){
        cout << "\n\nOutput :- \n";
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i][j] == 1)
                    cout << "Q" << " ";
                else
                    cout << "_" << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    chessBorad b;
    return 0;
}
