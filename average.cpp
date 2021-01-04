#include <iostream>
using namespace std;

double getAverage(double sum,int pointer){
    return sum / pointer;
}

int initializePointer(int pointer){
    while (true){
        cout << "How many grades you want to input(from 1-20): ";
        cin >> pointer;
        if (pointer >=1 && pointer <=20){
            cout << "input accepted!!" << "\n";
            return pointer;
        }
        cout << "Invalid input!!" << "\n";
    }
}

void printArray(int grades[],int pointer){
    cout << "Inserted numbers are: ";
    for (int i = 0; i < pointer; ++i) {
        cout << grades[i];
        if (i+1 != pointer) {cout << ", ";}
        else {cout <<"";}
    }
    cout << "\n";
}

double fillArray(int grades[],double percentage[],int pointer){
    int sum = 0;
    for (int i = 0; i < pointer; ++i) {
        while (true) {
            cout << "Give grade(from 0-20): ";
            cin >> grades[i];
            if (grades[i]>=0 && grades[i] <=20) {
                break;
            }
            cout << "Invalid grade!!" << "\n";
        }
        while (true){
            cout << "Give grade percentage(max of all percentages sum is 100): ";
            cin >> percentage[i];
            if (percentage[i] >= 0 && percentage[i] <= 100){
                percentage[i] /= 100;
                double n = grades[i] * percentage[i];
                sum += n;
                break;
            }
            cout << "Invalid percentage!!" << "\n";
        }
    }

    return sum;
}

double fillArray(int grades[],int pointer){
    int sum = 0;
    for (int i = 0; i < pointer; ++i) {
        while (true) {
            cout << "Give grade(from 0-20): ";
            cin >> grades[i];
            if (grades[i]>=0 && grades[i] <=20) {
                sum += grades[i];
                break;
            }
            cout << "Invalid grade!!" << "\n";
        }
    }

    return sum;
}

void firstOperation(){
    int pointer = 0;
    pointer = initializePointer(pointer);
    int grades[pointer];
    double sum = fillArray(grades,pointer);
    printArray(grades,pointer);
    cout << "The average is: " << getAverage(sum,pointer) << "\n";

}

void secondOperation(){
    int pointer = 0;
    pointer = initializePointer(pointer);
    int gradesSecond[pointer];
    double percentage[pointer];
    double sum = fillArray(gradesSecond,percentage,pointer);
    printArray(gradesSecond,pointer);
    cout << "The average is: " << sum << "\n";
}

void program(){
    while (true){
        //menu
        int menu;
        cout << "If you want to find the average of some numbers press 1 " << "\n";
        cout << "If you want to find your grade and there is a percentage to every grade press 2 " << "\n";
        cout << "If you want to exit press 3: ";
        cin >> menu;
        if (menu == 1) {
            firstOperation();
        }
        else if(menu == 2){
            secondOperation();
        }
        else if (menu == 3){
            exit(0);
        }
        else{
            cout << "Invalid input!!";
        }
    }

}

int main() {
    program();
    return 0;
}
