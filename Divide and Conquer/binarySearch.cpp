#include <iostream>

#include <vector>



using namespace std;



int binarySearch(vector<int> v,int low, int high, int k){

    if(high < low) return low -1;



    int m = (low + (high - low)/2);



    if(k == v[m]) return m;



    else if(k < v[m]){

        return binarySearch(v, low, m -1, k);

    }



    else {

        return binarySearch(v, m +1, high, k);

    }

}



int main(){

    int n;

    cin >> n;

    vector<int> v(n);



    for(int i = 0; i < n; ++i){

        cin>>v[i];

    }



    int result = binarySearch(v, 0, n-1,20);

    cout<< result<<endl;



    return 0;

}
