//Name- Tasfique Enam
//Student ID- 5886429
//LabTask 3
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

string fileName; //Declaring variables.
int num1, num2, num3, num4, num5, num6, num7;
int num;
ifstream ifs;

struct Bstnode {
    int data;
    struct Bstnode *left;
    struct Bstnode *right;
};

struct Bstnode *newNode(int item) { //a function to create a new BST node.
    struct Bstnode *temp = new Bstnode[0];

    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
};

void inorder(struct Bstnode *root) { //in order function for in order transversal BST
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}

struct Bstnode* insert(struct Bstnode* Bstnode, int data)
{
    /* If the tree is empty, return a new node */
    if (Bstnode == NULL) return newNode(data);

    /* Otherwise, recur down the tree */
    if (data < Bstnode->data)
        Bstnode->left  = insert(Bstnode->left, data);
    else if (data > Bstnode->data)
        Bstnode->right = insert(Bstnode->right, data);

    /* return the (unchanged) node pointer */
    return Bstnode;
}

int main() {
    bool check = true; // it is used for looping if the file doesn't exist.

    do {
        cout << "Enter the name of the File with .txt extension." << endl;
        cin >> fileName;

        if(fileName != "document.txt") {
            cout << "File name is Invalid! " << endl;
        } else {

            //ifstream ifs;
            ifs.open("document.txt");

            if (ifs.is_open()) {
                cout<<"The File have been successfully opened." << endl;
                //ifs>>num1;
            } else {
                cout << "File failed to Open " << endl;
                check = false;
            }

        }

    } while(fileName != "document.txt" || check == false); //while loop for file not existing or wrong file name.

    int arrayStorage[7];
    for(int i=0; i<7; i++) {
        ifs >> num;
        arrayStorage[i] = num;
    }

    cout << "The values in the Arrays are " << endl;
    for(int x=0; x<7; x++) {
        cout << arrayStorage[x] << " ";
    }
    //int arrayStorage[] = {num1, num2, num3, num4, num5, num6, num7};

    struct Bstnode *root = NULL;
    root = insert(root, arrayStorage[0]);
    insert(root, arrayStorage[1]);
    insert(root, arrayStorage[2]);
    insert(root, arrayStorage[3]);
    insert(root, arrayStorage[4]);
    insert(root, arrayStorage[5]);
    insert(root, arrayStorage[6]);

    //displaying the values in ascending order.
    cout << "\nValues in Ascending Order:" << endl;

    inorder(root);

    return 0;
}

