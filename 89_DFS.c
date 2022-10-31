// Depth First Search(DFS)
#include <stdio.h>
#include <stdlib.h>

int visitedMarker[7]={0,0,0,0,0,0,0}; // it's indexes are node elements
// using adjancy matrix approach here
int A[7][7]={
    {0,1,1,1,0,0,0},
    {1,0,0,1,0,0,0},
    {1,0,0,1,1,0,0},
    {1,1,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};

// DFS function
void DFS(int i){
    printf("%d ", i);
    visitedMarker[i]=1;
    for(int j=0; j<7; j++){
        if(A[i][j]==1 && visitedMarker[j]==0){
            DFS(j);
        }
    }
}
// Main function
int main(){
    // DFS implementation
    DFS(0);
    
    printf("\n");
    return 0;
}