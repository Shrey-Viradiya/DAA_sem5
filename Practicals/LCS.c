#include<stdio.h> 
#include<stdlib.h>
#include <string.h>
   
int max(int a, int b); 
   
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
   int i, j; 
   
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note  
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++) 
   { 
     for (j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
   
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
   
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
    
    for (int o = 0; o < m+1; o++)
    {
        for (int t = 0; t < n+1; t++)
        {
            printf("%d ", L[o][t]);
        }
        printf("\n");
        
    }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n]; 
} 
   
/* Utility function to get max of 2 integers */
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
   
/* Driver program to test above function */
int main() 
{ 
  char X[] = "ABCDEFGHABCD"; 
  char Y[] = "ABCEFADEFGDBCH"; 
   
  int m = strlen(X); 
  int n = strlen(Y); 
   
  printf("Length of LCS is %d", lcs( X, Y, m, n ) ); 
  
  return 0; 
} 