#include <stdio.h>
#include<stdlib.h>

// I tested this on your computer and was able to get the program to work there. 

int main() {


    FILE *fptr;
    char ch; // variable to read the content
    fptr= fopen("test.txt","r");// opening of file


 /*   if (fptr == NULL)
    {
        printf("Can't open testFile1.txt");
        return(1);
    } // End if*/

    ch = fgetc(fptr);
    printf("%c", ch);
    while(ch!= EOF){
       ch = fgetc(fptr);
       printf("%c", ch);
   }

   fclose(fptr);
//
//    if ( (stream = fopen("testFile1.txt","r")) != NULL)
//        fscanf(stream,"%s", string);

    printf("Hello, World!\n");
    //printf("%s",string);
    return 0;


} // End main
