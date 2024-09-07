#include <iostream>

#include <queue>

#include <vector>



using namespace std;



struct compare{

    bool operator()(int left, int right){

        //return left > right;

        return (left >= 50) < (right >= 50);

    }

};



int main(){



    //priority_queue<int,vector<int>,greater<int>> pq;

    priority_queue<int,vector<int>,compare> pq;



    /*pq.push(50);

    pq.push(60);

    pq.push(70);

    pq.push(40);

    pq.emplace(100);*/



    for(int n : {21, 5, 10, 50, 100, 70, 80, 20, 10, 5}){

        pq.push(n);

    }





    while(!pq.empty()){

        cout<<pq.top()<<" ";

        pq.pop();

    }





    return 0;

}
