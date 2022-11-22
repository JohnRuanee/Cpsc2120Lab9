/*
 * Name: John Ruane
 * Date Submitted: 11/21/22
 * Lab Section: 001
 * Assignment Name: Lab 9
 */

#include <iostream>
#include <vector>

using namespace std;

bool Row(int **arr, int curr, int r, int c){
    if(c == curr || arr[r][c] == 1)
        return false;
    else if((c == curr - 1) && arr[r][c] == 0)
        return true;
    
    return Row(arr, curr, r, ++c);

}

bool UpLeft(int **arr, int curr, int r, int c){
    if(c < 0 || r < 0 || arr[r][c] == 1)
        return false;
    else if((c == 0 || r == 0) && arr[r][c] == 0)
        return true;
    
    return UpLeft(arr, curr, --r, --c);

}

bool DownLeft(int **arr, int curr, int r, int c){
    if(c < 0 || r == curr || arr[r][c] == 1)
        return false;
    else if((c == 0 || r == curr - 1) && arr[r][c] == 0)
        return true;
    
    return DownLeft(arr, curr, ++r, --c);

}

int findQueens(int **arr, int curr, int c){
    int n = 0;
    
    if(c == curr)
        return 1;

    for(int r = 0; r < curr; r++){
        if(Row(arr, curr, r, 0) && DownLeft(arr, curr, r, c) && UpLeft(arr, curr, r, c)){
            arr[r][c] = 1;
            n += findQueens(arr, curr, c + 1);
            arr[r][c] = 0;
        }
    }
    return n;  
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n){
    int **arr = new int *[n];
    for(int r = 0; r < n; r++){
        arr[r] = new int[n];
        for(int c = 0; c < n; c++){
            arr[r][c] = 0;
        }
    }    
    return findQueens(arr, n, 0);
}

