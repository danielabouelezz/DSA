#include <iostream>

#define SPACE 10

using namespace std;



class TreeNode{

public:

    int value;

    TreeNode* left;

    TreeNode* right;



    TreeNode(){

        value = 0;

        left = NULL;

        right = NULL;

    }



    TreeNode(int v){

        value = v;

        left = NULL;

        right = NULL;

    }

};



class BST{

public:

    TreeNode* root;

    BST(){

        root = NULL;

    }



    bool isEmpty(){

        if(root == NULL) return true;

        return false;

    }



    void insertNode(TreeNode* new_node){

        if(root == NULL){

            root = new_node;

            cout<<"Value inserted as root node!"<<endl;

        }else{

            TreeNode* temp = root;

            while(temp != NULL){

                if(new_node->value == temp->value){

                    cout<<"Value already exist, insert another value!"<<endl;

                    return;

                }

                else if((new_node->value < temp->value)&&(temp->left ==NULL)){

                    temp->left = new_node;

                    cout<<"Value Inserted to the left!"<<endl;

                    break;

                }

                else if(new_node->value < temp->value){

                    temp = temp->left;

                }

                else if((new_node->value > temp->value)&&(temp->right == NULL)){

                    temp->right = new_node;

                    cout<<"Value Inserted to the right!" <<endl;

                    break;

                }else{

                    temp = temp->right;

                }

            }

        }

    }



    TreeNode* insertRecursive(TreeNode* root, TreeNode* new_node){

        if(root == NULL){

            root = new_node;

            return root;

        }

        if(new_node->value > root->value){

            root->right = insertRecursive(root->right, new_node);

        }

        else if(new_node->value < root->value){

            root->left = insertRecursive(root->left, new_node);

        }

        else{

            cout<<"NO DUPLICATES ARE ALLOWED!"<<'\n';

            return root;

        }

        return root;

    }



    void preOrder(TreeNode* root){

        if(root == NULL) return;



        cout<<root->value<<" ";

        preOrder(root->left);

        preOrder(root->right);

    }



    void inOrder(TreeNode* root){

        if(root == NULL) return;



        inOrder(root->left);

        cout<<root->value<<" ";

        inOrder(root->right);

    }



    void postOrder(TreeNode* root){

        if(root == NULL) return;



        postOrder(root->left);

        postOrder(root->right);

        cout<<root->value<<" ";

    }



    void print2D(TreeNode* root, int space){

        if(root == NULL) return ;

        space += SPACE;// Increase distance between levels

        print2D(root->right, space);// Process right child first

        cout<<endl;

        for(int i = SPACE; i < space; i++) cout<<" ";

        cout<<root->value<<"\n";

        print2D(root->left, space);// Process left child

    }



    TreeNode* iterativeSearch(int val){

        if(root == NULL) return root;

        else{

            TreeNode* temp = root;

            while(temp != NULL){

                if(temp->value == val) return temp;

                else if(temp->value > val){

                    temp = temp->left;

                }else{

                    temp = temp->right;

                }

            }

            return NULL;

        }

    }



    TreeNode* recursiveSearch(TreeNode* r, int val){

        if(r == NULL || r->value == val) return r;

        else if(r->value > val) return recursiveSearch(r->left, val);

        else return recursiveSearch(r->right, val);

    }



    int height(TreeNode* r){

        if(r == NULL) return -1;



        int lh = height(r->left);

        int rh = height(r->right);



        return lh > rh? lh+1 : rh+1;

    }



    void printGivenLevel(TreeNode* r, int h){

        if(r == NULL) return;

        else if(h == 0) cout<<r->value<<" ";

        else{

            printGivenLevel(r->left, h-1);

            printGivenLevel(r->right, h-1);

        }

    }



    void printLevelOrderBFS(TreeNode* r){

        int h = height(r);



        for(int i{0}; i <= h; i++){

            printGivenLevel(r, i);

        }

    }



    TreeNode* minValueNode(TreeNode* node){

        TreeNode* current = node;

        while(current->left != NULL){

            current = current->left;

        }

        return current;

    }



    TreeNode* deleteNode(TreeNode* r, int v){

        if(r == NULL) return NULL;

        else if(v < r->value){

            r->left = deleteNode(r->left, v);

        }

        else if(v > r->value){

            r->right = deleteNode(r->right, v);

        }

        else{

            if(r->left == NULL){

                TreeNode* temp = r->right;

                delete r;

                return temp;

            }

            else if(r->right == NULL){

                TreeNode* temp = r->left;

                delete r;

                return temp;

            }

            else{

                TreeNode* temp = minValueNode(r->right);

                r->value = temp->value;

                r->right = deleteNode(r->right, temp->value);

            }

        }

        return r;

    }

};





int main(){

    BST obj;

    int option, val;



    do{

        cout<<"What operation do you want to perform? "

        <<" Select Option number, Enter 0 to exit."<<endl;

        cout<<"1. Insert Node"<<endl;

        cout<<"2. Search Node"<<endl;

        cout<<"3. Delete Node" <<endl;

        cout<<"4. Print BST values"<<endl;

        cout<<"5. Height of Tree" <<endl;

        cout<<"6. Clear Screen" <<endl;

        cout<<"0. Exit Program"<<endl;



        cin>>option;

        TreeNode* new_node = new TreeNode();



        switch(option){

            case 0:

                break;

            case 1:

                cout<<"INSERT"<<endl;

                cout<<"Enter Value of Tree Node to insert in BST: ";

                cin>>val;

                new_node->value = val;

                //obj.insertNode(new_node);

                obj.root = obj.insertRecursive(obj.root, new_node);

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

                new_node = obj.iterativeSearch(val);

                if(new_node != NULL){

                    obj.deleteNode(obj.root, val);

                    cout<<"Value Deleted"<<endl;

                }else cout<<"Value Not Found"<<'\n';

                break;

            case 4:

                cout<<"PRINT"<<endl;

                obj.print2D(obj.root, 5);

                cout<<'\n'<<"Pre Order: ";

                obj.preOrder(obj.root);

                cout<<'\n'<<"In Order: ";

                obj.inOrder(obj.root);

                cout<<'\n'<< "Post Order: ";

                obj.postOrder(obj.root);

                cout<<'\n'<<"Level Order: ";

                obj.printLevelOrderBFS(obj.root);

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
