#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned long seed = 0;
const unsigned long a = 1664525L;
const unsigned long c = 1013904223L;

void customSeed(unsigned long value)
{
    seed = value;
} // end customSeed()


unsigned long customRandom()
{
    seed = (a * seed + c);
    return seed;
} // end customRandom

void create(char outputFileName[],int count,int digits){
    customSeed((unsigned int)time(NULL));
    FILE *File;
    unsigned long temp;
    File = fopen(outputFileName, "w");
    for(int i = 0; i < count; i++){
        int digtemp = pow(10, digits);
        temp = customRandom() %  digtemp;
        fprintf(File, "%lu\n" , temp);

    }
}
int main(){
    char OutputFiles[5][12] = {"data5K.txt","data40K.txt","data300K.txt","data2M.txt","data10M.txt"};
    int count[5] = {5000,40000 ,300000,2000000,10000000};
    int digits[5] = {4,5,6,7,8};
    double milliseconds;
    double seconds;
    double minutes;
    for(int i = 0; i < 5; i++){
        clock_t startTime = clock();
        create(OutputFiles[i], count[i], digits[i]);
        clock_t stopTime = clock();     // Save the stopping time

    // Calculate milliseconds, seconds, minutes
    milliseconds = 1000.0 * (stopTime - startTime) / CLOCKS_PER_SEC;
    seconds = milliseconds / 1000.0;
    minutes = seconds / 60.0;

    printf("\n%s Elapsed time:\n\n", OutputFiles[i]);
    printf("%0.3f minutes\n", minutes);
    printf("%0.3f seconds\n", seconds);
    printf("%.1f milliseconds\n", milliseconds);
    }
}