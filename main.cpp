#include <iostream>
using namespace std;

int main() {
    int elrmAmnt, min, max, tmp, k, sum, decider, b, g;
    const int MAX_SIZE = 100;
    cout << "Enter the number of array elements:"<< endl;
    cin >> elrmAmnt;
    if (elrmAmnt <= 0 || elrmAmnt > MAX_SIZE) {
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
            int *dynArray = new int[elrmAmnt];
            for (int i = 0; i < elrmAmnt; i++) {
                dynArray[i] = rand();
                if (dynArray[i] > max) {
                    dynArray[i] = dynArray[i] % max;
                }
                if (dynArray[i] < min & dynArray[i] + min < max) {
                    dynArray[i] += min;
                }
            }
            for (int i = 0; i < elrmAmnt; ++i) {
                cout << dynArray[i] << " ";
            }
            cout << endl;
            tmp = abs(dynArray[0]);
            for (int i = 0; i < elrmAmnt; i+=1) {
                if (tmp>abs(dynArray[i])) {
                    tmp=dynArray[i];
                }
            }
            sum=0;
            k= elrmAmnt - 1;
            while (dynArray[k]!=0 & k>=0) {
                sum+=dynArray[k];
                k-=1;
            }
            int tmpArray[elrmAmnt];
            for(int i=0; i < elrmAmnt; i++){
                tmpArray[i]=dynArray[i];
            }
            if (elrmAmnt % 2 == 0){
                b= (elrmAmnt) / 2 - 1;
            }
            else
            {
                b= (elrmAmnt) / 2;
            }
            for(int i=1; i<b+1; i++){
                dynArray[i]=tmpArray[i*2];
            }
            g=1;
            for(int i=b+1; i < elrmAmnt; i++){
                dynArray[i]=tmpArray[g];
                g+=2;
            }
            cout << "The sum of the array elements located after the last zero element: " << sum << endl;
            cout << "Minimum modulo array element: " << tmp << endl;
            cout << "New array: " ;
            for (int i = 0; i < elrmAmnt; ++i) {
                cout << dynArray[i] << " ";
            }
        }else{ cout << "Enter the values of the array elements: " << endl;
            int Array[elrmAmnt];
            for (int i = 0; i < elrmAmnt; i++){
                cin >> Array[i];
            }
            for (int i = 0; i < elrmAmnt; ++i) {
                cout << Array[i] << " ";
            }
            cout << endl;
            tmp = abs(Array[0]);
            for (int i = 0; i < elrmAmnt; i++) {
                if (tmp>abs(Array[i])) {
                    tmp=Array[i];
                }
            }
            sum=0;
            k= elrmAmnt - 1;
            while (Array[k]!=0 & k>=0) {
                sum+=Array[k];
                k-=1;
            }
            int tmpArray[elrmAmnt];
            for(int i=0; i < elrmAmnt; i++){
                tmpArray[i]=Array[i];
            }
            if (elrmAmnt % 2 == 0){
                b= (elrmAmnt) / 2 - 1;
            } else{
                b= (elrmAmnt) / 2;
            }
            for(int i=1; i<b+1; i++){
                Array[i]=tmpArray[i*2];
            }
            g=1;
            for(int i=b+1; i < elrmAmnt; i++){
                Array[i]=tmpArray[g];
                g+=2;
            }
            cout << "The sum of the array elements located after the last zero element: " << sum << endl;
            cout << "Minimum modulo array element: " << tmp << endl;
            cout << "New array: " ;
            for (int i = 0; i < elrmAmnt; ++i) {
                cout << Array[i] << " ";
            }
        }
        return 0;
    }
}