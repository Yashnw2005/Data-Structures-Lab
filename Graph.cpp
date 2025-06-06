#include <iostream>
#include <cstring>

using namespace std;

#define MAX 10  // Maximum number of cities

class Graph {
public:
    int v, e;                    // Number of vertices and edges 
    int a[MAX][MAX];              // Adjacency Matrix
    char cityNames[MAX][20];      // Stores city/airport names

    struct Node {
        int cityIndex, cost;
        Node* next;
    };
    Node* adj[MAX];  // Adjacency list (array of linked lists)

    // Constructor to initialize the graph
    Graph() {
        v = e = 0;
        for (int i = 0; i < MAX; i++) {
            adj[i] = NULL;  // Initialize adjacency list
            for (int j = 0; j < MAX; j++) {
                a[i][j] = 0;  // Initialize adjacency matrix
            }
        }
    }

    // Function to find city index by name
    int getCityIndex(char name[]) {
        for (int i = 0; i < v; i++) {
            if (strcmp(cityNames[i], name) == 0)
                return i;
        }
        return -1;  // Not found
    }

    // Function to add an edge (flight) to the graph
    void insert() {
        cout << "Enter number of cities (airports): ";
        cin >> v;
        
        cout << "Enter city names:\n";
        for (int i = 0; i < v; i++) {
            cout << "City " << i + 1 << ": ";
            cin >> cityNames[i];  
        }

        cout << "Enter number of flights: ";
        cin >> e;

        cout << "Enter the source city, destination city, and flight cost:\n";
        for (int i = 0; i < e; i++) {
            char cityA[20], cityB[20];
            int cost;
            cout << "Source City: ";
            cin >> cityA;
            cout << "Destination City: ";
            cin >> cityB;
            cout << "Flight Cost (time/fuel): ";
            cin >> cost;

            int x = getCityIndex(cityA);
            int y = getCityIndex(cityB);

            if (x == -1 || y == -1) {
                cout << "Invalid city name! Try again.\n";
                i--;
                continue;
            }

            // Update adjacency matrix
            a[x][y] = cost;
            a[y][x] = cost; // Assuming bidirectional flights

            // Update adjacency list
            Node* newNode1 = new Node{y, cost, adj[x]};
            adj[x] = newNode1;

            Node* newNode2 = new Node{x, cost, adj[y]};
            adj[y] = newNode2;
        }
    }

    // Function to display adjacency matrix
    void displayMatrix() {
        cout << "\nAdjacency Matrix Representation:\n    ";
        for (int i = 0; i < v; i++) {
            cout << cityNames[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < v; i++) {
            cout << cityNames[i] << " ";
            for (int j = 0; j < v; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to display adjacency list
    void displayList() {
        cout << "\nAdjacency List Representation:\n";
        for (int i = 0; i < v; i++) {
            cout << cityNames[i] << " -> ";
            Node* temp = adj[i];
            while (temp) {
                cout << "(" << cityNames[temp->cityIndex] << ", Cost: " << temp->cost << ") -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    Graph g;
    g.insert();        
    g.displayMatrix(); 
    g.displayList();   

    return 0;
}

