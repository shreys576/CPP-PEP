#include<iostream>
#include <vector>
using namespace std;

int linearsearch(vector<int> arr, int key){
    for(int i: arr){
        if(i == key && key > 5){
            return key*2;
        }
        else if(i == key && key <= 5){
            return key/2;
        }
    }
    return -1;
}


int main(){

    vector<int> arr = {3,1,6,4,2};
    int key = 5;
    cout << linearsearch(arr, key);

}