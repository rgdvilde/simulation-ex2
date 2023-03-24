#include <iostream>
#include <stdlib.h> 

int nr_fruits = 4;
FILE *file1;
char fileName[300];
int runs = 10000;
std::string running_average_replication[10000];
bool smarter_children = true;


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
                            i3 = rand()%nr_fruits;
                            while(fruits[i3] == 0) {
                                i3 = rand()%nr_fruits;
                            }
                        }
                    }
                    else {
                        i3 = rand()%nr_fruits;
                        while(fruits[i3] == 0) {
                            i3 = rand()%nr_fruits;
                        }                        
                    }
                    fruits[i3]--;
                }
            }
            else {
                position_raven++;
                if(position_raven < 5) {
                    if(fruits[position_raven-1] > 0) {
                        fruits[position_raven-1]--;
                    }
                }
            }    
        }
        if(fruitsLeft(fruits, nr_fruits) == 0) {
            total_success++;
        }
        float running_average = ((float)total_success)/(float)(i+1);
        // fprintf(file1, "%f\n", running_average);
        // s.append()
        running_average_replication[i].append(" ");
        running_average_replication[i].append(std::to_string(running_average));
        // running_average_replication[i] = running_average_replication + " f"s + std::to_string(running_average);
        // std::string s = 
        // strcpy(running_average_replication[i],strcat(running_average_replication[i], " "));
        // strcpy(running_average_replication[i],std:running_average_replication[i] + ));

        final_average = running_average;
    }
    return final_average;
}

int main(int argc, const char * argv[]) {
    strcpy(fileName, "out.txt");
    // srand(5); //0.595120
    // srand(50); //0.597880
    // srand(455454); //0.584600 smarter: 0.593330
    int random_numbers[] = {
    5,50,56565,84754,154845,
    548478, 4845, 4875, 2256, 547848,
    88522, 1, 45864, 668, 420,
    22233366, 44741, 191919, 1564,
    29, 45454, 555555, 424194, 2
    };
    int replication_amount = 25;
    file1=fopen(fileName,"w");
    for(int i=0;i<25;i++) {
        srand(random_numbers[i]);
        float running_average = procedure(runs);
        std::cout << "Running Average: ";
        std::cout << std::to_string(running_average);
        std::cout << "\n";
    }
    for(int i=0;i<runs;i++) {
        fprintf(file1, "%s\n", running_average_replication[i].c_str());
    }
    fclose(file1);
    return 0;    
}