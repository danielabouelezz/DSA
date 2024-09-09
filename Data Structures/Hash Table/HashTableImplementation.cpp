#include <iostream>

#include <list>

#include <cstring>



using namespace std;



class HashTable{

private:

    static const int hashGroups = 10;

    list<pair<int, string>> table[hashGroups];//list 1.index 0, list 2.index 1...



public:

    bool isEmpty() const;

    int hashFunction(int key);

    void insertItem(int key, string value);

    void removeItem(int key);

    string searchTable(int key);

    void printTable();

};



bool HashTable::isEmpty() const{

    int sum{};

    for(int i{}; i < hashGroups; i++){

        sum+= table[i].size();

    }



    if(!sum){

        return true;

    }

    return false;

}



int HashTable::hashFunction(int key){

    return key % hashGroups;//key: 985, in return this function will spit out 5;

}



void HashTable::insertItem(int key, string value){

    int hashValue = hashFunction(key);

    auto& cell = table[hashValue];

    auto bItr = begin(cell);

    bool keyExists = false;



    for(; bItr != end(cell); bItr++){

        if(bItr->first == key){

            keyExists = true;

            bItr->second = value;

            cout<< "[WARNING] key exists. Value replace."<<endl;

            break;

        }

    }



    if(!keyExists){

        cell.emplace_back(key, value);

    }

    return;

}



void HashTable::removeItem(int key){

    int hashValue = hashFunction(key);

    auto& cell = table[hashValue];

    auto bItr = begin(cell);

    bool keyExists = false;



    for(; bItr != end(cell); bItr++){

        if(bItr->first == key){

            keyExists = true;

            bItr = cell.erase(bItr);

            cout<< "[INFO] Item removed."<<endl;

            break;

        }

    }



    if(!keyExists){

        cout<<"[WARNING] Key not found. Pair not removed."<<endl;

    }

    return;

}



void HashTable::printTable(){

    for(int i{}; i< hashGroups; i++){

        if(table[i].size() == 0) continue;



        auto bItr = table[i].begin();

        for(; bItr != table[i].end();bItr++){

            cout<<"[INFO] Key: " <<bItr->first <<" Value: "<< bItr->second<<endl;

        }

    }

    return;

}



int main(){

    HashTable ht;

    if(ht.isEmpty()){

        cout<<"Correct"<<endl;

    }else {

        cout<<"Issue"<<endl;

    }



    ht.insertItem(905, "jim");

    ht.insertItem(201, "tom");

    ht.insertItem(332, "bob");

    ht.insertItem(124, "sandy");

    ht.insertItem(107, "dan");

    ht.insertItem(928, "rob");

    ht.insertItem(928, "rick");



    ht.printTable();



    ht.removeItem(332);

    ht.removeItem(100);



    if(ht.isEmpty()){

        cout<<"Issue"<<endl;

    }else {

        cout<<"Correct"<<endl;

    }



    return 0;

}
