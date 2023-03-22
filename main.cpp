#include <iostream>

int nr_fruits = 4;
FILE *file1;
char fileName[300];
int runs = 10000;
bool smarter_children = false;

int fruitsLeft(int fruitArray[], int sizeOfArray) {
    int f = 0;
    for(int i=0;i<sizeOfArray;i++) {
        f += fruitArray[i];
    }
    return f;
}

float procedure(int k) {
    int total_success = 0;
    float final_average = 0;
    for(int i=0;i<k;i++) {
        int success = 0; 
        int position_raven = 0;
        int fruits[nr_fruits];
        for(int ii=0;ii<nr_fruits;ii++) {
            fruits[ii] = 3;
        }
        while(fruitsLeft(fruits, nr_fruits) > 0 && position_raven < 5) {
            int i2 = rand()%6;
            if(i2 < nr_fruits) {
                if(fruits[i2] > 0) {
                fruits[i2]--;
                }
                else {
                    int i3;
                    if(smarter_children) {
                        if(fruitsLeft(fruits, position_raven) > 0) {
                            i3 = rand()%position_raven;
                            while(fruits[i3] == 0) {
                                i3 = rand()%position_raven;
                            }
                        }
                        else {
                            int i3 = rand()%nr_fruits;
                            while(fruits[i3] == 0) {
                                i3 = rand()%nr_fruits;
                            }
                        }
                    }
                    else {
                        int i3 = rand()%nr_fruits;
                        while(fruits[i3] == 0) {
                            i3 = rand()%nr_fruits;
                        }                        
                    }
                    fruits[i3]--;
                }
            }
            else {
                position_raven++;
                if(fruits[position_raven] > 0) {
                    fruits[position_raven]--;
                }
            }    
        }
        if(fruitsLeft(fruits, nr_fruits) == 0) {
            total_success++;
        }
        float running_average = ((float)total_success)/(float)(i+1);
        fprintf(file1, "%f\n", running_average);
        final_average = running_average;
    }
    return final_average;
}

int main(int argc, const char * argv[]) {
    strcpy(fileName, "out.txt");
    file1=fopen(fileName,"w");      
    float running_average = procedure(runs);
    std::cout << "Running Average: ";
    std::cout << std::to_string(running_average);
    std::cout << "\n";
    fclose(file1);
    return 0;    
}