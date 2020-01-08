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
    while(!feof(input)){//checks end of file
        if (loop <= 10){//takes first 10 values
            fscanf(input, "%lf",&val_double);//reads input into double
            fwrite(&val_double,sizeof(double),1,output);//input written in output file
        }
        if ((11 <= loop) && (loop <= 20)){//next 10 values
            if (loop == 11){
                fgets(str,(sizeof(char) * 40), input);//skips first read because its '\n'
            }
            fgets(str,(sizeof(char) * 40), input);//reads input into string
            fwrite(str,(sizeof(char) * 40),1,output);//input written in output file
        }
        if ((21 <= loop) && (loop <= 30)){//last 10 values
            fscanf(input, "%d",&val_int);//reads input into int
            fwrite(&val_int,sizeof(int),1,output);//input written in output file
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