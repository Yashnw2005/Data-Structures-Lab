#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

class WeddingPlanner {
    int graph[MAX][MAX];
    int n;
    string names[MAX];

public:
    WeddingPlanner(int totalHalls) {
        n = totalHalls + 1; // +1 for Home
        names[0] = "Home";

        // Initialize graph with 0
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                graph[i][j] = 0;
    }

    void inputHallNames() {
        cout << "Enter names of marriage halls:\n";
        for (int i = 1; i < n; i++) {
            cin >> names[i];
        }
    }

    void inputRoads() {
        int roads;
        cout << "Enter number of roads: ";
        cin >> roads;

        cout << "Enter each road as: <from_index> <to_index> <distance>\n";
        cout << "(Use 0 for your home)\n";
        for (int i = 0; i < roads; i++) {
            int u, v, d;
            cin >> u >> v >> d;
            graph[u][v] = d;
            graph[v][u] = d;
        }
    }

    void findNearestHall() {
        int dist[MAX];
        bool visited[MAX];

        for (int i = 0; i < n; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
        }

        dist[0] = 0; // Distance from Home to Home is 0

        for (int count = 0; count < n - 1; count++) {
            int u = -1, minDist = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1) break;
            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        cout << "\nShortest distance from your home to each marriage hall:\n";
        int nearest = -1, minHallDist = INT_MAX;

        for (int i = 1; i < n; i++) {
            cout << "To " << names[i] << " : " << dist[i] << " units\n";
            if (dist[i] < minHallDist) {
                minHallDist = dist[i];
                nearest = i;
            }
        }

        if (nearest != -1) {
            cout << "\nBest option: " << names[nearest]
                 << " is the nearest hall with a distance of " << minHallDist << " units.\n";
        } else {
            cout << "\nNo reachable marriage hall from your home.\n";
        }
    }
};

int main() {
    int totalHalls;
    cout << "Enter number of marriage halls: ";
    cin >> totalHalls;

    WeddingPlanner planner(totalHalls);
    planner.inputHallNames();
    planner.inputRoads();
    planner.findNearestHall();

    return 0;
}
