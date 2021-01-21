#include <iostream>

#define SPACE 10

using namespace std;

class TreeNode {
public:
    TreeNode *left;
    int value;
    TreeNode *right;

    TreeNode() {
        value = 0;
        left = right = nullptr;
    }

    explicit TreeNode(int v) {
        value = v;
        left = right = nullptr;
    }
};

class BST {
public:
    TreeNode *root;

    BST() {
        root = nullptr;
    }

    bool isEmpty() const;

    void print2D(TreeNode *r, int space);

    void insertNode(TreeNode *new_node);

    void printPreorder(TreeNode *r);

    void printInorder(TreeNode *r);

    void printPostorder(TreeNode *r);

    TreeNode *iterativeSearch(int data) const;

    int height(TreeNode *r);

    void printLevelOrderBFS(TreeNode *r);

    void printGivenLevel(TreeNode *r, int level);

    TreeNode *minValueNode(TreeNode *node);

    TreeNode *maxValueNode(TreeNode *node);

    TreeNode *deleteNode(TreeNode *r, int v);
};

bool BST::isEmpty() const {
    return root == nullptr;
}

void BST::print2D(TreeNode *r, int space) {
    if (r == nullptr)
        return;
    space += SPACE;
    print2D(r->right, space);
    cout << endl;
    for (int i = SPACE; i < space; i++)
        cout << " ";
    cout << r->value << "\n";
    print2D(r->left, space);
}

void BST::insertNode(TreeNode *new_node) {
    if (root == nullptr) {
        root = new_node;
        cout << "Value inserted as New Node!" << endl;
    } else {
        TreeNode *temp = root;
        while (temp != nullptr) {
            if (new_node->value == temp->value) {
                cout << "Value Already Exists ! Insert New Value" << endl;
                return;
            } else if (new_node->value < temp->value && temp->left == nullptr) {
                temp->left = new_node;
                cout << "Value Inserted at Left" << endl;
                break;
            } else if (new_node->value < temp->value) {
                temp = temp->left;
            } else if (new_node->value > temp->value && temp->right == nullptr) {
                temp->right = new_node;
                cout << "Value Inserted at Right" << endl;
                break;
            } else {
                temp = temp->right;
            }
        }
    }
}

void BST::printPreorder(TreeNode *r) {
    if (r == nullptr)
        return;
    cout << r->value << " ";
    printPreorder(r->left);
    printPreorder(r->right);
}

void BST::printInorder(TreeNode *r) {
    if (r == nullptr)
        return;
    printPreorder(r->left);
    cout << r->value << " ";
    printPreorder(r->right);
}

void BST::printPostorder(TreeNode *r) {
    if (r == nullptr)
        return;
    printPostorder(r->left);
    printPostorder(r->right);
    cout << r->value << " ";
}

TreeNode *BST::iterativeSearch(int data) const {
    if (root == nullptr) {
        return root;
    } else {
        TreeNode *temp = root;
        while (temp != nullptr) {
            if (data == temp->value) {
                return temp;
            } else if (data < temp->value) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
    }
    return nullptr;
}

int BST::height(TreeNode *r) {
    if (r == nullptr)
        return -1;
    else {

        int leftHeight = height(r->left);
        int rightHeight = height(r->right);

        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

void BST::printLevelOrderBFS(TreeNode *r) {
    int h = height(r);
    for (int i = 0; i <= h; ++i) {
        printGivenLevel(r, i);
    }
}

void BST::printGivenLevel(TreeNode *r, int level) {
    if (r == nullptr)
        return;
    else if (level == 0) {
        cout << r->value << " ";
    } else {
        printGivenLevel(r->left, level - 1);
        printGivenLevel(r->right, level - 1);
    }
}

TreeNode *BST::minValueNode(TreeNode *node) {
    TreeNode *current = node;
    while (current != nullptr) {
        current = current->left;
    }
    return current;
}

TreeNode *BST::maxValueNode(TreeNode *node) {
    TreeNode *current = node;
    while (current != nullptr) {
        current = current->right;
    }
    return current;
}

TreeNode *BST::deleteNode(TreeNode *r, int v) {
    if (r == nullptr)
        return nullptr;
    else if (v < r->value)
        r->left = deleteNode(r->left, v);
    else if (v > r->value)
        r->right = deleteNode(r->right, v);
    else {
        if (r->left == nullptr) {
            TreeNode *temp = r->right;
            delete r;
            return temp;
        } else if (r->right == nullptr) {
            TreeNode *temp = r->left;
            delete r;
            return temp;
        } else {
            TreeNode *temp = minValueNode(r->right);
            r->value = temp->value;
            r->right = deleteNode(r->right, temp->value);
        }
    }
    return r;
}

int main() {
    BST object;
    int option, value;

    do {
        cout << endl << "What operation do you want to perform? " <<
             " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal BST values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        auto *new_node = new TreeNode();

        switch (option) {
            case 0:
                break;
            case 1:
                cout << "INSERT" << endl;
                cout << "Enter value of tree Node for Insertion" << endl;
                cin >> value;
                new_node->value = value;
                object.insertNode(new_node);
                cout << endl;
                break;
            case 2:
                cout << "SEARCH" << endl;
                cout << "Enter value of tree Node for Searching" << endl;
                cin >> value;
                new_node = object.iterativeSearch(value);
                if (new_node != nullptr)
                    cout << "Value Found." << endl;
                else
                    cout << "Value doesn't exist." << endl;
                break;
            case 3:
                cout << "DELETE" << endl;
                break;
            case 4:
                cout << "PRINT 2D: " << endl;
                object.print2D(object.root, 5);

                cout << "Printing in Pre-Order: " << endl;
                object.printPreorder(object.root);
                cout << endl << "Printing in Post-Order: " << endl;
                object.printPostorder(object.root);
                cout << endl << "Printing in In-Order: " << endl;
                object.printInorder(object.root);
                cout << endl << "Printing in Level-Order: " << endl;
                object.printLevelOrderBFS(object.root);
                break;
            case 5:
                cout << "TREE HEIGHT " << endl;
                cout << "Height: " << object.height(object.root) << endl;
                break;
            case 6:
                system("cls");
                break;
            default:
                cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);
}
