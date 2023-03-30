#include <iostream>
#include <vector>

using namespace std;

void sortLastElement(vector<int>& vec) {
    /*in this task we dont need a full sort, we just have to sort the last element*/
    int n = vec.size()-1;
    int key = vec[n];

    for (int i = n-1; i >= 0; i--) {
        if(vec[i]>key){
            vec[i+1]=vec[i];
        }else{
            vec[i+1]=key;
            return;
        }
     }
     vec[0]=key;
}

double getMedian(vector<int> vec){
    int n = vec.size();
    if(n % 2 == 0) {
        return (vec[n/2] + vec[(n/2) - 1]) / 2.0;
    } else {
        return vec[n/2];
    }
}

int main() {
    vector<int> input;
    int x;

    while (cin >> x) {
        input.push_back(x);
        sortLastElement(input);
        cout << "[";
        for(int i=0; i<input.size()-1; i++) {
            cout << input[i] << ",";
        }
        cout << input[input.size()-1] << "] ";
        cout << getMedian(input) << endl;
    }

    return 0;
}
