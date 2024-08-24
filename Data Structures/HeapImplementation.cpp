#include <iostream>

#include <math.h>

#include <climits>



using namespace std;



void Swap(int &x, int &y){

    int temp = x;

    x = y;

    y = temp;

}



class MinHeap{

public:

    int* harr; //pointer to array of elements in heap

    int capacity; // maximum possible size of min heap

    int heap_size; // Current number of elements in min heap



    MinHeap(int cap){

        heap_size = 0;

        capacity = cap;

        harr = new int[cap];

    }



    void linearSearch(int val){

        for(int i = 0; i < heap_size;i++){

            if(harr[i] == val){

                cout<<"Value found!";

                return;

            }

        }

        cout<<"Value Not Found";

    }



    void printArray(){

        for(int i = 0; i < heap_size; i++){

            cout<<harr[i]<<" ";

        }

        cout<<endl;

    }



    int height(){

        return ceil(log2(heap_size +1)) -1;

    }



    int parent(int i){

        return (i - 1)/2;

    }



    int left(int i){

        return (2*i +1);

    }



    int right(int i){

        return (i*2 +2);

    }



    int getMin(){

        return harr[0];

    }



    void insertKey(int k){

        if(heap_size == capacity){

            cout<<"\nOverflow: could not insert key\n";

            return;

        }



        //First insert the new key at the end

        heap_size++;

        int i = heap_size -1;

        harr[i] = k;



        //Fix the min heap property if it is violated

        while(i != 0 && harr[parent(i)] > harr[i]){

            Swap(harr[i], harr[parent(i)]);

            i = parent(i);

        }

    }



    void MinHeapify(int i){

        int l = left(i);

        int r = right(i);

        int smallest = i;

        if(l < heap_size && harr[l] < harr[i])

            smallest = l;

        if(r < heap_size && harr[r] < harr[smallest])

            smallest = r;

        if(smallest != i){

            Swap(harr[i], harr[smallest]);

            MinHeapify(smallest);

        }

    }



    int extractMin(){

        if(heap_size == 0) return INT_MAX;

        if(heap_size == 1){

            heap_size--;

            return harr[0];

        }



        ///store the minimum value, and removee it from heap

        int root = harr[0];

        harr[0] = harr[heap_size-1];

        heap_size--;

        MinHeapify(0);



        return root;

    }



    void decreaseKey(int i, int new_value){

        harr[i] = new_value;

        while(i != 0 && harr[parent(i)] > harr[i]){

            Swap(harr[i], harr[parent(i)]);

            i = parent(i);

        }

    }

    // This function deletes key at index i. It first reduces the value to

    // minus infinity, then calls extracMin()

    void deletKey(int i){

        decreaseKey(i, INT_MIN);

        extractMin();

    }

};



int main(){

    int s;

    cout<<"Enter Size of Min Heap"<<endl;

    cin>>s;

    MinHeap obj(s);

    cout<<"Min Heap Created" <<endl;



    int option, val;



    do{

        cout<<"What operation do you want to perform?"

        <<"Select Option number. Enter 0 to exit." <<endl;

        cout<<"1. Insert key/Node"<<endl;

        cout<<"2. Search Key/Node" <<endl;

        cout<<"3. Delete Key/Node" <<endl;

        cout<<"4. Get Min"<<endl;

        cout<<"5. Extract Min"<<endl;

        cout<<"6. Height of Heap"<<endl;

        cout<<"7. Print/Traversal Heap values"<<endl;

        cout<<"8. Cleat Screen"<<endl;

        cout<<"0. Exit Program"<<endl;



        cin>>option;

        switch(option){

            case 0:

                break;

            case 1:

                cout<<"Insert Operation -"<<endl;

                cout<<"Enter Value to Insert in Heap: ";

                cin>> val;

                obj.insertKey(val);

                cout<<endl;

                break;

            case 2:

                cout<<"Search Operation -" <<endl;

                cout<<"Enter Value to Search in Heap: ";

                cin>>val;

                cout<<endl;

                break;

            case 3:

                cout<<"Delete Operation -"<<endl;

                cout<<"Enter Index of heap Array to Delete: ";

                cin>>val;

                obj.deletKey(val);

                break;

            case 4:

                cout<<"Get Min value: ";

                cout<<obj.getMin()<<endl;

                cout<<endl;

                break;

            case 5:

                cout<<"Extract Min value: ";

                cout<<obj.extractMin()<<endl;

                cout<<endl;

                break;

            case 6:

                cout<<"Heap tree Height: ";

                break;

            case 7:

                cout<<"Print Heap Array: "<<endl;

                obj.printArray();

                cout<<endl;

                break;

            case 8:

                system("cls");

                break;

            default:

                cout<<"Enter Proper Option number: "<<endl;

        }

    }while(option != 0);

}
