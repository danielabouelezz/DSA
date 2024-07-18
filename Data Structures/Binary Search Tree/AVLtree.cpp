#include <iostream>

#define SPACE 10



using namespace std;



class treeNode{

public:

    int value;

    treeNode* right;

    treeNode* left;



    treeNode(){

        value = 0;

        right = NULL;

        left = NULL;

    }



    treeNode(int val){

        value = val;

        right = NULL;

        left = NULL;

    }

};



class AVLTree{

public:

    treeNode* root;

    AVLTree(){

        root = NULL;

    }

    bool isEmpty(treeNode* root){

        if(root == NULL) return true;

        return false;

    }



    int height(treeNode* root){

        if(root == NULL) return -1;



        int lh = height(root->left);

        int rh = height(root->right);



        return lh > rh? lh+1 : rh+1;

    }



    int getBalanceFactor(treeNode* n){

        if(n == NULL) return -1;

        return height(n->left) - height(n->right);

    }



    treeNode* rightRotate(treeNode* y){

        treeNode* x = y->left;

        treeNode* T2 = x->right;



        //Perform Rotation

        x->right = y;

        y->left = T2;



        return x;

    }



    treeNode* leftRotate(treeNode* x){

        treeNode* y = x->right;

        treeNode* T2 = y->left;



        //Perform Rotation

        y->left = x;

        x->right = T2;



        return y;

    }



    treeNode* AVLinsertion(treeNode* root, treeNode* new_node){

        if(root == NULL){

            root = new_node;

            cout<<"Value inserted successfully"<<endl;

            return root;

        }

        if(new_node->value < root->value){

            root->left = AVLinsertion(root->left, new_node);

        }

        else if(new_node->value > root->value){

            root->right = AVLinsertion(root->right, new_node);

        }

        else{

            cout<<"Duplicate are not allowed!"<<'\n';

            return root;

        }



        int bf = getBalanceFactor(root);

        //Left Left case

        if(bf > 1 && new_node->value < root->left->value)

            return rightRotate(root);

        //Right Right case

        else if(bf < -1 && new_node->value > root->right->value)

            return leftRotate(root);

        //Left Right case

        else if(bf > 1 && new_node->value > root->left->value){

            root->left = leftRotate(root->left);

            return rightRotate(root);

        }

        //Right Left case

        else if(bf < -1 && new_node->value < root->right->value){

            root->right = rightRotate(root->right);

            return leftRotate(root);

        }

        return root;

    }



    treeNode* minValue(treeNode* root){

        treeNode* temp = root;



        while(temp->left != NULL){

            temp = temp->left;

        }

        return temp;

    }



    treeNode* AVLdeletion(treeNode* root, int val){

        if(root == NULL) return NULL;



        else if(root->value > val) root->left = AVLdeletion(root->left, val);

        else if(root->value < val) root->right = AVLdeletion(root->right, val);

        else{

            if(root->left == NULL){

                treeNode* temp = root->right;

                delete root;

                return temp;

            }

            else if(root->right == NULL){

                treeNode* temp = root->left;

                delete root;

                return temp;

            }

            else{

                treeNode* temp = minValue(root->right);

                root->value = temp->value;

                root->right = AVLdeletion(root->right, temp->value);

            }

        }

        int bf = getBalanceFactor(root);

        //left left case

        if(bf == 2 && getBalanceFactor(root->left) >= 0)

            return rightRotate(root);

        //left right case

        else if(bf == 2 && getBalanceFactor(root->left) == -1){

            root->left = leftRotate(root->left);

            return rightRotate(root);

        }

        //right right case

        else if(bf == -2 && getBalanceFactor(root->right) <= 0)

            return leftRotate(root);

        //right left case

        else if(bf == -2 && getBalanceFactor(root->right) == 1){

            root->right = rightRotate(root->right);

            return leftRotate(root);

        }

        return root;

    }



    void Print2D(treeNode* root, int space){

        if(root == NULL) return;



        space +=SPACE;

        Print2D(root->right, space);

        cout<<endl;

        for(int i{SPACE}; i < space; i++){

            cout<<" ";

        }

        cout<<root->value<<'\n';

        Print2D(root->left, space);

    }



    treeNode* recursiveSearch(treeNode* root, int val){

        if(root == NULL || root->value == val) return root;



        else if(root->value < val) return recursiveSearch(root->right, val);

        else return recursiveSearch(root->left, val);

    }

};



int main(){

    AVLTree obj;

    int option, val;



    do{

        cout<<"What operation do you want to perform? "

        <<" Select Option number, Enter 0 to exit."<<endl;

        cout<<"1. Insert Node"<<endl;

        cout<<"2. Search Node"<<endl;

        cout<<"3. Delete Node" <<endl;

        cout<<"4. Print/Traversal AVL Tree values"<<endl;

        cout<<"5. Height of Tree" <<endl;

        cout<<"6. Clear Screen" <<endl;

        cout<<"0. Exit Program"<<endl;



        cin>>option;



        treeNode* new_node = new treeNode();



        switch(option){

            case 0:

                break;

            case 1:

                cout<<"INSERT"<<endl;

                cout<<"Enter Value of Tree Node to insert in BST: ";

                cin>>val;

                new_node->value = val;

                //obj.insertNode(new_node);

                obj.root = obj.AVLinsertion(obj.root, new_node);

                cout<<endl;

                break;

            case 2:

                cout<<"SEARCH"<<endl;

                cout<<"Enter value of TREE NODE to SEARCH in BST: ";

                cin>> val;

                new_node = obj.recursiveSearch(obj.root, val);

                if(new_node != NULL){

                cout<<"Value found"<<'\n';

                }else{

                    cout<<"Value not found"<<'\n';

                }

                break;

            case 3:

                cout<<"DELETE"<<endl;

                cout<<"Enter the value to be deleted: ";

                cin>>val;

                new_node = obj.recursiveSearch(obj.root, val);

                if(new_node != NULL){

                    obj.root = obj.AVLdeletion(obj.root, val);

                    cout<<"Value Deleted"<<endl;

                }else cout<<"Value Not Found"<<'\n';

                break;

            case 4:

                cout<<"PRINT"<<endl;

                obj.Print2D(obj.root, 5);

                cout<<'\n';

                break;

            case 5:

                cout<<"Tree Height"<<'\n';

                cout<<"HEIGHT: " <<obj.height(obj.root)<<'\n';

                break;

            case 6:

                system("clear");

                break;

            default:

                cout<<"Enter a proper number."<<endl;

        }

    }while(option != 0);



    return 0;

}
