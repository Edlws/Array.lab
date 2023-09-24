#include <iostream>
using namespace std;

int main() {
    int elemAmnt, min, max, k, decider, b, g, h, c;
    double sum, tmp, hophey;
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
            int *dynArray = new int[2*elemAmnt];
            for (int i = 0; i < elemAmnt; i++) {
                dynArray[i] = rand();
                if (dynArray[i] > max) {
                    dynArray[i] = dynArray[i] % max;
                }
                if (dynArray[i] < min & dynArray[i] + min < max) {
                    dynArray[i] += min;
                }
            }
            for (int i = 0; i < elemAmnt; ++i) {
                cout << dynArray[i] << " ";
            }
            cout << endl;
            tmp = dynArray[0];
            for (int i = 0; i < elemAmnt; i+=1) {
                if (tmp>dynArray[i] & tmp > -1* dynArray[i]) {
                    tmp=dynArray[i];
                }
            }
            sum=0;
            k= elemAmnt - 1;
            while (dynArray[k]!=0 & k>=0) {
                sum+=dynArray[k];
                k-=1;
            }
            for(int i=0; i < elemAmnt; i++){
                dynArray[elemAmnt+i]=dynArray[i];
            }
            if (elemAmnt % 2 == 0){
                b= (elemAmnt) / 2 - 1;
            }
            else
            {
                b= (elemAmnt) / 2;
            }
            for(int i=1; i<b+1; i++){
                dynArray[i]=dynArray[i*2];
            }
            g=1;
            for(int i=b+1; i < elemAmnt; i++){
                dynArray[i]=dynArray[elemAmnt+g];
                g+=2;
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
            for(int i=0; i < elemAmnt; i++){
                Array[elemAmnt+i]=Array[i];
            }
            if (elemAmnt % 2 == 0){
                b= (elemAmnt) / 2 - 1;
            }
            else
            {
                b= (elemAmnt) / 2;
            }
            for(int i=1; i<b+1; i++){
                Array[i]=Array[i*2];
            }
            g=1;
            for(int i=b+1; i < elemAmnt; i++){
                Array[i]=Array[elemAmnt+g];
                g+=2;
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