#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void insertion_sort(int arr[], int first, int last) {
  for (int i = first + 1; i < last + 1; i++) {
    // hold first position in temp
    // use the postion before it as starting iterator
    int tmp = arr[i], j = i-1;
    

    // iterating from last to first 
    // check whether the starting number is smaller or not
    // shift till the position is found
    while (tmp < arr[j] && j >= 0) {
        arr[j + 1] = arr[j];
        --j;
    }

    // place the number at its sorted position
    arr[j + 1] = tmp;
  }  
}

void printArray(int arr[], int size) 
{ 
    // simple function to print an array
    for (int i=0; i < size; i++) printf("%d ", arr[i]); 
    // printf("\n"); 
} 

void printNums(char *p)
{
    // utility function to print the content of the files
    FILE *fp ;
    int c;

    fp = fopen(p,"rb" ) ;
    if ( fp == NULL )
    {
        printf ( "Can not open File." ) ;
        return;
    }

    c = fgetc(fp); 
    while (c != EOF) 
    { 
        printf ("%c", c);   
        c = fgetc(fp); 
    }

    fclose(fp);
}

int main() {
	
	char filename[100];
    int c, numbers[50];

    // Get the filename from the user
	printf("Enter the location of the file containing integers: ");
    scanf("%s",filename);

    // fetch the first 50 numbers from the file and print the array
    // and then increase jump
    int jump = 50;
    int iteration = 0; 

    while(jump*iteration < 500){
        // Try to open the file
        // exit showing error if unable to open the file
        FILE *fp;
        if ((fp = fopen(filename, "r")) == NULL) {
		    printf("Can not open %s\n",filename);
		    return 1;
	    }

        FILE *fo;
        fo = fopen("temp.txt","w");
        if (fo == NULL) {
            printf("File creation unsuccessful!\n");
            return 1;
        } 
        

        // from iteration 0 to the maximum number size
        // it will get the jump number of elements
        // sort it and then
        // store it in the file
        while(jump*iteration < 500){

            for ( int k = 0 + iteration*jump; k < (iteration + 1) *jump ; k++){
                fscanf(fp, "%d", &numbers[k - iteration*jump]);
            }

            insertion_sort(numbers, 0, jump - 1);

            for(int i = 0;i < jump;++i) { 
                fprintf(fo, "%d\n", numbers[i]); 
            }
            // printArray(numbers, jump);
            // printf("\n-------------\n");
            iteration++;
        }

    
        fclose(fo);
        fclose(fp);

        // change the content of the file
        {
        FILE *source, *target; 
        int ch;
        source = fopen("temp.txt", "r");        
        if( source == NULL )
        {
            printf("Can not open File...\n");
        }        
        
        target = fopen(filename, "w");        
        if( target == NULL )
        {
            fclose(source);
            printf("Can not open File...\n");
        }        
        while( ( ch = fgetc(source) ) != EOF )
            fputc(ch, target);
        
        // printf("File copied.\n");
        
        fclose(source);
        fclose(target);
        }

        iteration = 0;
        jump+=50;
    }

	return 0;
}