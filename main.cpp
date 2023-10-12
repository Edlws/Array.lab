#include <iostream>
#include <random>
using namespace std;

int main() {
    int elemAmnt, min, max, k, decider, tmp, sum;
    const int MAX_SIZE = 100;
    cout << "Enter the number of array elements:"<< endl;
    cin >> elemAmnt;
    if (elemAmnt <= 0 || elemAmnt > MAX_SIZE) {
        cout << "Incorrect array size. Please enter a number from 1 to " << MAX_SIZE << endl;
        return 1;
    } else {
        cout << "Would uou like to create the array manually(enter 0) or generate it randomly(enter your favourite number)?"<< endl;
        cin >> decider;
        if (decider != 0) {
            cout << "Enter a lower bound for array element values:" << endl ;
            cin >> min;
            cout << "Enter a upper bound for array element values:" << endl; //min!=max & min<(max-min)
            cin >> max;
            int *dynArray = new int[elemAmnt];
            for (int i = 0; i < elemAmnt; i++) {
                dynArray[i] = rand();
                random_device random_device;
                mt19937 generator(random_device());
                uniform_int_distribution<> distribution(min, max);
                dynArray[i] = distribution(generator);
            }
            for (int i = 0; i < elemAmnt; ++i) {
                cout << dynArray[i] << " ";
            }
            cout << endl;
            tmp = dynArray[0];
            for (int i = 0; i < elemAmnt; i+=1) {
                if (abs(tmp)>abs(dynArray[i])) {
                    tmp=dynArray[i];
                }
            }
            sum=0;
            k= elemAmnt - 1;
            while (dynArray[k]!=0 & k>=0) {
                sum+=dynArray[k];
                k-=1;
            }
            if (elemAmnt%2==0){
                for (int i=1; i<=(elemAmnt-2)/2; i+=1){
                    for (int k=i; k<elemAmnt-1-i; k+=2){
                        int temp=dynArray[k];
                        dynArray[k]=dynArray[k+1];
                        dynArray[k+1]=temp;
                    }
                }
            }else{
                for (int i=1; i<=(elemAmnt-1)/2; i+=1){
                    for (int k=i; k<elemAmnt-i; k+=2){
                        int temp=dynArray[k];
                        dynArray[k]=dynArray[k+1];
                        dynArray[k+1]=temp;
                    }
                }
            }
            cout << "The sum of the array elements located after the last zero element: " << sum << endl;
            cout << "Minimum modulo array element: " << tmp << endl;
            cout << "New array: " ;
            for (int i = 0; i < elemAmnt; ++i) {
                cout << dynArray[i] << " ";
            }
        }else{ cout << "Enter the values of the array elements: " << endl;
            double Array[elemAmnt*2];
            for (int i = 0; i < elemAmnt; i++){
                cin >> Array[i];
            }
            for (int i = 0; i < elemAmnt; ++i) {
                cout << Array[i] << " ";
            }
            cout << endl;
            tmp = abs(Array[0]);
            for (int i = 0; i < elemAmnt; i++) {
                if (tmp>Array[i] & tmp>Array[i]*(-1)) {
                    tmp=Array[i];
                }
            }
            sum=0;
            k= elemAmnt - 1;
            while (Array[k]!=0 & k>=0) {
                sum+=Array[k];
                k-=1;
            }
            if (elemAmnt%2==0){
                for (int i=1; i<=(elemAmnt-2)/2; i+=1){
                    for (int k=i; k<elemAmnt-1-i; k+=2){
                        int temp=Array[k];
                        Array[k]=Array[k+1];
                        Array[k+1]=temp;
                    }
                }
            }else{
                for (int i=1; i<=(elemAmnt-1)/2; i+=1){
                    for (int k=i; k<elemAmnt-i; k+=2){
                        int temp=Array[k];
                        Array[k]=Array[k+1];
                        Array[k+1]=temp;
                    }
                }
            }


            cout << "The sum of the array elements located after the last zero element: " << sum << endl;
            cout << "Minimum modulo array element: " << tmp << endl;
            cout << "New array: " ;
            for (int i = 0; i < elemAmnt; i+=1) {
                cout << Array[i] << " ";
            }
        }
        return 0;
    }
}