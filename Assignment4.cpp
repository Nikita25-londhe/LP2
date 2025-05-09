#include<iostream>
#include<climits>
using namespace std;

class Graph {
    int n;
    int** graph;
    int minColorsUsed;

public:
    Graph(int a) {
        n = a;
        graph = new int*[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new int[n];
            for (int j = 0; j < n; j++) {
                graph[i][j] = 0;
            }
        }
        minColorsUsed = INT_MAX;
    }

    void readGraph() {
        cout << "\nEnter graph matrix:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> graph[i][j];
    }

    void showGraph() {
        cout << "\nGraph Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << graph[i][j] << " ";
            cout << endl;
        }
    }

    bool canIColor(int v, int clr, int* color) {
        for (int i = 0; i < n; i++)
            if (graph[v][i] && color[i] == clr)
                return false;
        return true;
    }

    void colorVertex(int v, int* color, int m, int usedColors) {
        if (v == n) {
            if (usedColors < minColorsUsed) {
                minColorsUsed = usedColors;
                cout << "\nColoring with " << usedColors << " colors:\n";
                for (int i = 0; i < n; i++)
                    cout << color[i] << " ";
                cout << endl;
            }
            return;
        }

        // Prune if used colors already exceed best found
        if (usedColors >= minColorsUsed)
            return;

        for (int clr = 0; clr < m; clr++) {
            if (canIColor(v, clr, color)) {
                color[v] = clr;
                int newUsedColors = max(usedColors, clr + 1);
                colorVertex(v + 1, color, m, newUsedColors);
                color[v] = -1;
            }
        }
    }
};

int main() {
    int n;
    cout << "\nEnter number of vertices: ";
    cin >> n;

    Graph g1(n);
    g1.readGraph();
    g1.showGraph();

    int* color = new int[n];
    for (int i = 0; i < n; i++)
        color[i] = -1;

    int m;
    cout << "\nEnter number of available colors: ";
    cin >> m;

    g1.colorVertex(0, color, m, 0);
    return 0;
}
