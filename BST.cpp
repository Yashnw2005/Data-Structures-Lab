#include <iostream>
using namespace std;

class BST {
public:
    string emp_id;
    string emp_name;
    float salary;
    BST* left;
    BST* right;

    BST(string emp_name, string emp_id, float salary) {
        this->emp_id = emp_id;
        this->emp_name = emp_name;
        this->salary = salary;
        left = nullptr;
        right = nullptr;
    }
};

BST* root = nullptr;

void insert(BST*& temp, BST* current) {
    if (current->salary < temp->salary) {
        if (temp->left == nullptr) temp->left = current;
        else insert(temp->left, current);
    } else {
        if (temp->right == nullptr) temp->right = current;
        else insert(temp->right, current);
    }
}

void create() {
    float sal;
    string name, id;
    cout << "Enter the name: ";
    cin >> name;
    cout << "Enter the employee ID: ";
    cin >> id;
    cout << "Enter the salary: ";
    cin >> sal;
    BST* newnode = new BST(name, id, sal);

    if (root == nullptr) root = newnode;
    else insert(root, newnode);
}

int count = 0;
float total = 0.0;

void inorder(BST* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << "Name: " << root->emp_name << ", ID: " << root->emp_id << ", Salary: " << root->salary << endl;
    count++;
    total += root->salary;
    inorder(root->right);
}

void total_emp() {
    cout << "Total employees: " << count << endl;
}

void search(BST* root, float key) {
    if (root == nullptr) {
        cout << "Key not found!" << endl;
        return;
    }
    if (key == root->salary) {
        cout << "Key found: " << root->emp_name << ", ID: " << root->emp_id << ", Salary: " << root->salary << endl;
    } else if (key > root->salary) {
        search(root->right, key);
    } else {
        search(root->left, key);
    }
}

float min_salary(BST* root) {
    if (root == nullptr) return -1;
    while (root->left != nullptr) root = root->left;
    return root->salary;
}

float max_salary(BST* root) {
    if (root == nullptr) return -1;
    while (root->right != nullptr) root = root->right;
    return root->salary;
}

void avg_salary() {
    if (count == 0) cout << "No employees to calculate average salary." << endl;
    else cout << "Average salary: " << total / count << endl;
}

// Delete node by salary
BST* deleteNode(BST* root, float key) {
    if (root == nullptr) return root;

    if (key < root->salary)
        root->left = deleteNode(root->left, key);
    else if (key > root->salary)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (root->left == nullptr) {
            BST* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            BST* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        BST* succ = root->right;
        while (succ->left != nullptr) succ = succ->left;

        root->emp_id = succ->emp_id;
        root->emp_name = succ->emp_name;
        root->salary = succ->salary;

        root->right = deleteNode(root->right, succ->salary);
    }
    return root;
}

// Update employee data by salary
void update(BST* root, float key) {
    if (root == nullptr) {
        cout << "Employee not found!" << endl;
        return;
    }

    if (key == root->salary) {
        cout << "Current details:" << endl;
        cout << "Name: " << root->emp_name << ", ID: " << root->emp_id << ", Salary: " << root->salary << endl;

        cout << "Enter new name: ";
        cin >> root->emp_name;
        cout << "Enter new ID: ";
        cin >> root->emp_id;
        cout << "Salary cannot be updated here. To change salary, delete and re-insert the employee." << endl;
    }
    else if (key > root->salary) update(root->right, key);
    else update(root->left, key);
}

int main() {
    int ch;
    do {
        count = 0;
        total = 0.0;

        cout << "\nMENU:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Search" << endl;
        cout << "4. Total Employees" << endl;
        cout << "5. Minimum Salary" << endl;
        cout << "6. Maximum Salary" << endl;
        cout << "7. Average Salary" << endl;
        cout << "8. Delete" << endl;
        cout << "9. Update" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                inorder(root);
                break;
            case 3: {
                float key;
                cout << "Enter salary to search: ";
                cin >> key;
                search(root, key);
                break;
            }
            case 4:
                inorder(root);
                total_emp();
                break;
            case 5:
                cout << "Minimum salary: " << min_salary(root) << endl;
                break;
            case 6:
                cout << "Maximum salary: " << max_salary(root) << endl;
                break;
            case 7:
                inorder(root);
                avg_salary();
                break;
            case 8: {
                float key;
                cout << "Enter salary of employee to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                cout << "Deleted (if existed)." << endl;
                break;
            }
            case 9: {
                float key;
                cout << "Enter salary of employee to update: ";
                cin >> key;
                update(root, key);
                break;
            }
            case 10:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

    } while (ch != 10);

    return 0;
}