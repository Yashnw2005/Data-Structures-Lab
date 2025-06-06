#include <iostream>
using namespace std;

class Graph {
public:
    int v, e;
    int a[100][100]; 

    Graph() {
        
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                a[i][j] = 0;
            }
        }
    }

    void insert() {
        int x, y;
        cout << "Enter number of vertices: ";
        cin >> v;
        cout << "Enter number of edges: ";
        cin >> e;

        cout << "Enter the vertices and edges" << endl;
        for (int i = 0; i < e; i++) {
           
            cin >> x >> y ;
            a[x][y] = 1;
            a[y][x] = 1; 
        }
    }

    void display() {
        cout << "\nThe adjacency matrix is:" << endl;
        cout<<"  ";
        for(int i=0;i<v;i++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        for (int i = 0; i < v; i++) {
            cout<<i<<" ";
            for (int j = 0; j < v; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Graph g;
    g.insert();
    g.display();
    return 0;
}