#include <iostream>

#include <vector>



using namespace std;



class DJS{

private:

    vector<int> Parent;

    vector<int> Rank;

public:

    DJS(int n){

        Parent.resize(n);

        Rank.resize(n, 0);



        //Initialize each element as separete set.

        for(int i = 0; i < n; i++){

            Parent[i] = i;

        }

    }



    int Find(int element){

        if(Parent[element] != element){

            Parent[element] = Find(Parent[element]);

        }

        return Parent[element];

    }



    void unionSets(int x, int y){

        int rootX = Find(x);

        int rootY = Find(y);



        if(rootX != rootY){

            if(Rank[rootX] < Rank[rootY]){

                Parent[rootX] = rootY;

            }

            else if(Rank[rootY] < Rank[rootX]){

                Parent[rootY] = rootX;

            }

            else{

                Parent[rootY] = rootX;

                Rank[rootX]++;

            }

        }

    }

};



int main(){

    int n = 5;



    DJS obj(n);



    obj.unionSets(0, 1);

    obj.unionSets(2, 3);

    obj.unionSets(0, 4);



    //Check if elements 1 and 4 are in the same set

    if(obj.Find(1) == obj.Find(4)){

        cout<<"1 and 4 are in the same set\n";

    }

    else{

        cout<<"1 and 4 are in different sets\n";

    }



    return 0;

}
