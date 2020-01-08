#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
   if (argc != 3){// checks that 3 arguments are given
        printf("Error: Incorrect  Arguments!");// error message if incorrect argument
        exit(0);//exits program
    }
    FILE *input; //input file
    input = fopen(argv[1],"r"); //opens input file
    if (input == NULL){ //checks that there is data
        printf("Error: File Opening Failed!");//error message if it doesnt exist
        exit(1);//exits program
    }
    FILE *output; // output file
    output = fopen(argv[2],"w");//opens output file
    int loop = 1; // loop for keeping track
    double val_double;//double value that will hold input
    int val_int; //int value that will hold input
    char str[40]; //string value that will hold input
    while(!feof(input)){ //checks end of file
        if (loop <= 10){ // first 10 values
            fread(&val_double,sizeof(double),1, input); //input placed in double
            fprintf(output, "%.4lf\n", val_double);//input printed in output with 4 decimal places
        }
        if ((11 <= loop) && (loop <= 20)){ // next 10 values
            fread(str ,(sizeof(char) * 40),1 ,input); //input placed in string
            fprintf(output, "%s", str); //string printed in output file
        }
        if ((21 <= loop) && (loop <= 30)){//next 10 values
            fread(&val_int,sizeof(int),1, input);//input put into int
            fprintf(output, "%d\n", val_int);//input printed in output file
        }
        if(loop == 30){//last value complete
            printf("Conversion Complete!\n"); // prints completion message
            fclose(input); //closes input file
            fclose(output);//closes output file
            exit(0);//exits program
        }
        loop++;//loop increment
    }
}