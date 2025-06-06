 /*A Medical Record System is a software application used to manage medical records, including patient information,
medical history, and treatment plans. Hash tables can be used as a data structure to efficiently store and
retrieve medical records.*/
#include <iostream>
using namespace std;

class Hashtable {
public:
    string name;
    string id;
    string history;
    string treatment;

    Hashtable() {
        name = "empty";
        id = "empty";
        history = "empty";
        treatment = "empty";
    }
};

// Function declarations
void rehash(Hashtable *&h, int *&array, int &n);

int getHash(string id, int n) {
    int val = 0;
    for (char c : id) {
        val += int(c);
    }
    return val % n;
}

void insert(Hashtable *&h, string name, string id, string history, string treatment, int *&array, int &n) {
    int val = getHash(id, n);
    int k = 0, j = 0;

    while (array[val] == 0) {
        k++;
        j++;
        val = (val + k * k) % n;
        if (j == n) {
            cout << "Hashtable is full! Rehashing..." << endl;
            rehash(h, array, n);
            insert(h, name, id, history, treatment, array, n);
            return;
        }
    }

    h[val].name = name;
    h[val].id = id;
    h[val].history = history;
    h[val].treatment = treatment;
    array[val] = 0;
    cout << "Inserted at: " << val << endl;
}

void rehash(Hashtable *&h, int *&array, int &n) {
    int old_n = n;
    n *= 2;

    Hashtable *new_h = new Hashtable[n];
    int *new_array = new int[n];
    for (int i = 0; i < n; i++) new_array[i] = -1;

    for (int i = 0; i < old_n; i++) {
        if (array[i] == 0) {
            insert(new_h, h[i].name, h[i].id, h[i].history, h[i].treatment, new_array, n);
        }
    }

    delete[] h;
    delete[] array;
    h = new_h;
    array = new_array;
}

void display(Hashtable h[], int array[], int n) {
    for (int i = 0; i < n; i++) {
        if (array[i] == 0) {
            cout << "\nName: " << h[i].name;
            cout << "\nID: " << h[i].id;
            cout << "\nHistory: " << h[i].history;
            cout << "\nTreatment: " << h[i].treatment << "\n";
        }
    }
}

void update(Hashtable h[], int array[], int n, string id) {
    int val = getHash(id, n);
    int k = 0, j = 0;

    while (j < n) {
        if (array[val] == 0 && h[val].id == id) {
            cout << "Enter new patient ID: ";
            cin >> h[val].id;
            cout << "Enter new patient Name: ";
            cin >> h[val].name;
            cout << "Enter new patient History: ";
            cin >> h[val].history;
            cout << "Enter new patient Treatment: ";
            cin >> h[val].treatment;
            return;
        }
        k++;
        j++;
        val = (val + k * k) % n;
    }
    cout << "Record not found!" << endl;
}

void search(Hashtable h[], int array[], int n, string id) {
    int val = getHash(id, n);
    int k = 0, j = 0;

    while (j < n) {
        if (array[val] == 0 && h[val].id == id) {
            cout << "\nName: " << h[val].name;
            cout << "\nID: " << h[val].id;
            cout << "\nHistory: " << h[val].history;
            cout << "\nTreatment: " << h[val].treatment << "\n";
            return;
        }
        k++;
        j++;
        val = (val + k * k) % n;
    }
    cout << "Record not found!" << endl;
}

void deleterecord(Hashtable h[], int array[], int n, string id) {
    int val = getHash(id, n);
    int k = 0, j = 0;

    while (j < n) {
        if (array[val] == 0 && h[val].id == id) {
            array[val] = -2;
            cout << "Record deleted!" << endl;
            return;
        }
        k++;
        j++;
        val = (val + k * k) % n;
    }
    cout << "Record not found!" << endl;
}

void displaybyhistory(Hashtable h[], int array[], int n, string history1) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] == 0 && h[i].history == history1) {
            cout << "\nName: " << h[i].name;
            cout << "\nID: " << h[i].id;
            cout << "\nHistory: " << h[i].history;
            cout << "\nTreatment: " << h[i].treatment << "\n";
            found = 1;
        }
    }
    if (!found) {
        cout << history1 << " is not present in records!" << endl;
    }
}

int main() {
    int n;
    cout << "Enter initial size of hashtable: ";
    cin >> n;

    Hashtable *h = new Hashtable[n];
    int *array = new int[n];
    for (int i = 0; i < n; i++) array[i] = -1;

    int ch;
    string name, id, history, treatment, id1, history1;

    do {
        cout << "\n1. Insert\n2. Search\n3. Update\n4. Delete\n5. Display All\n6. Display by History\n7. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter patient ID: ";
            cin >> id;
            cout << "Enter patient Name: ";
            cin >> name;
            cout << "Enter patient History: ";
            cin >> history;
            cout << "Enter patient Treatment: ";
            cin >> treatment;
            insert(h, name, id, history, treatment, array, n);
            break;
        case 2:
            cout << "Enter ID to search: ";
            cin >> id1;
            search(h, array, n, id1);
            break;
        case 3:
            cout << "Enter ID to update: ";
            cin >> id1;
            update(h, array, n, id1);
            break;
        case 4:
            cout << "Enter ID to delete: ";
            cin >> id1;
            deleterecord(h, array, n, id1);
            break;
        case 5:
            display(h, array, n);
            break;
        case 6:
            cout << "Enter History to search: ";
            cin >> history1;
            displaybyhistory(h, array, n, history1);
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (ch != 7);

    delete[] h;
    delete[] array;

    return 0;
}
