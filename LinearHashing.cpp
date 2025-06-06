/*A Music Library System is a software application used to manage the storage
and retrieval of music tracks and albums. Hash tables can be used as a data
structure to efficiently store and retrieve music track and album information*/
#include <iostream>
using namespace std;
class Hashtable
{
public:
    string name;
    string id;
    string type;
    Hashtable()
    {
        name = "empty";
        id = "empty";
        type = "empty";
    }
};

void insert(Hashtable h[], string name, string id, string type, int array[], int n)
{
    int val = 0;
    for (char c : id)
    {
        val += (int)c;
    }
    val = val % n;
    int i = 0, j = 1;
    if (array[val] == -1 || array[val] == -2)
    {
        h[val].name = name;
        h[val].id = id;
        h[val].type = type;
        array[val] = 0;
        cout << "inserted at:" << val << endl;
    }
    else
    {
        while (i != 1)
        {
            cout << "collision occur at:" << val << endl;
            val = (val + 1) % n;
            j++;
            if (array[val] == -1 || array[val] == -2)
            {

                h[val].name = name;
                h[val].id = id;
                h[val].type = type;
                array[val] = 0;
                cout << "inserted at:" << val << endl;
                i = 1;
            }
            if (j == n)
            {
                cout << "Hashtable table is full!!!";
                i = 1;
            }
        }
    }
}

void display(Hashtable h[], int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == 0)
        {
            cout << "Name: " << h[i].name << endl;
            cout << "id: " << h[i].id << endl;
            cout << "type: " << h[i].type << endl;
        }
    }
}

void update(Hashtable h[], int array[], int n, string id)
{
    int val = 0;
    int i = 0, j = 1;
    for (char c : id)
    {
        val += (int)c;
    }
    val = val % n;
    if (h[val].id == id && array[val] == 0)
    {
        string name1, type1, id1;
        cout << "Enter the new music id: ";
        cin >> id1;
        cout << "Enter the new music name: ";
        cin >> name1;
        cout << "Enter the new music type: ";
        cin >> type1;
        h[val].name = name1;
        h[val].id = id1;
        h[val].type = type1;
        return;
    }
    while (i != 1)
    {
        val = (val + 1) % n;
        j++;
        if (h[val].id == id && array[val] == 0)
        {
            string name1, type1, id1;
            cout << "Enter the new music id: ";
            cin >> id1;
            cout << "Enter the new music name: ";
            cin >> name1;
            cout << "Enter the new music type: ";
            cin >> type1;
            h[val].name = name1;
            h[val].id = id1;
            h[val].type = type1;
            i = 1;
        }
        if (j == n)
        {
            cout << "Track not found" << endl;
            i = 1;
        }
    }
}

void search(Hashtable h[], int array[], int n, string id)
{
    int val = 0;
    int i = 0, j = 1;
    for (char c : id)
    {
        val += (int)c;
    }
    val = val % n;
    if (h[val].id == id && array[val] == 0)
    {
        cout << "Name: " << h[val].name << endl;
        cout << "id: " << h[val].id << endl;
        cout << "type: " << h[val].type << endl;
        return;
    }
    while (i != 1)
    {
        val = (val + 1) % n;
        j++;
        if (h[val].id == id && array[val] == 0)
        {
            cout << "Name: " << h[val].name << endl;
            cout << "id: " << h[val].id << endl;
            cout << "type: " << h[val].type << endl;
            i = 1;
        }
        if (j == n)
        {
            cout << "Record is not found!!";
            i = 1;
        }
    }
}

void deleterecord(Hashtable h[], int array[], int n, string id)
{
    int val = 0;
    int i = 0, j = 1;
    for (char c : id)
    {
        val += (int)c;
    }
    val = val % n;
    if (h[val].id == id && array[val] == 0)
    {
        array[val] = -2;
        cout << "Record deleted!!!";
        return;
    }
    while (i != 1)
    {
        val = (val + 1) % n;
        j++;
        if (h[val].id == id && array[val] == 0)
        {
            array[val] = -2;
            cout << "Record deleted!!!";
            i = 1;
        }
        if (j == n)
        {
            cout << "Track not found" << endl;
            i = 1;
        }
    }
}

void displaybytype(Hashtable h[], int array[], int n, string type1)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == 0 && h[i].type == type1)
        {
            cout << "Name: " << h[i].name << endl;
            cout << "id: " << h[i].id << endl;
            cout << "type: " << h[i].type << endl;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << type1 << " is not present in record!!!";
    }
}

int main()
{
    int n;
    cout << "Enter number of music track you want to insert(Hashtable table size): ";
    cin >> n;
    Hashtable h[n];
    int array[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = -1;
    }
    int ch;
    string name, type, id, id1, type1;
    do
    {
        cout << "1.Insert\n2.search\n3.update\n4.delete\n5.display\n6.display by type\n7.Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {

        case 1:
            cout << "Enter the music id: ";
            cin >> id;
            cout << "Enter the music name: ";
            cin >> name;
            cout << "Enter the music type: ";
            cin >> type;
            insert(h, name, id, type, array, n);
            break;

        case 2:
            cout << "Enter the id which you want search: ";
            cin >> id1;
            search(h, array, n, id1);
            break;

        case 3:
            cout << "Enter the id which you want update: ";
            cin >> id1;
            update(h, array, n, id1);
            break;

        case 4:
            cout << "Enter the id which you want delete: ";
            cin >> id1;
            deleterecord(h, array, n, id1);
            break;

        case 5:
            display(h, array, n);
            break;

        case 6:
            cout << "Enter the type which you want display: ";
            cin >> type1;
            displaybytype(h, array, n, type1);
            break;

        case 7:
            cout << "Exiting!!";
            break;

        default:
            cout << "Wrong choice! try again!!!";
        }

    } while (ch != 7);
    return 0;
}
