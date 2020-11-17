#include <iostream>
#include <list> 
using namespace std;

class Graph {
    int n;
    struct nod{
        int info;
        nod* next;
    }lista[10000];

public:
    Graph();
    ~Graph();
    void addNode(int a);
    void addEdge(int source, int target);
    int hasEdge(int source, int target);
    void BFS(int startNode);
    void DFS(int startNode);
    void DFSUtil(int node, bool visited[]);
    int twoCycles();
    void getTwo(int s) {
        nod* ptr = &lista[s];
        while (ptr->next != NULL) {
            cout << ptr->info << " ";
            ptr = ptr->next;
        }
        cout << ptr->info << endl;
    }

};

Graph::Graph() {
    n = 0;
}
Graph::~Graph() {
    for (int i = 0; i < n; i++) {
        nod* ptr = &lista[i];
        while (ptr) {
            nod* old = ptr;
            ptr = ptr->next;
            delete old;
        }

    }
}
void Graph::addNode(int a) {
    lista[n].info = a;
    lista[n].next = NULL;
    n++;
}

void Graph::addEdge(int source, int target) {
    for (int i = 0; i < n; i++) {
        if (lista[i].info == source) {
            nod* ptr = &lista[i];
            while (ptr->next != NULL)ptr = ptr->next; 
            nod* nou = new nod;
            nou->info = target;
            nou->next = NULL;
            ptr->next = nou;
        }
    }
    
}
int Graph::hasEdge(int source, int target) {
    for (int i = 0; i < n; i++) {
        if (lista[i].info == source) {
            nod* ptr = &lista[i];
            while (ptr->next) {
                if (ptr->info == target)return 1;
                ptr = ptr->next;
            }
            if (ptr->info == target) return 1;
        }
    }
    return 0;
}

void Graph::BFS(int startNode) {
    bool* visited = new bool[n];
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    list<int> coada;
    visited[startNode] = true;
    coada.push_back(startNode);

    while (!coada.empty()) {
        startNode = coada.front();
        cout << startNode << " ";
        coada.pop_front();
        for (int i = 0; i < n; i++) {
            if (lista[i].info == startNode) {
                nod* ptr = &lista[i];
                while (ptr->next) {
                    ptr = ptr->next;
                    if (!visited[ptr->info]) {
                        visited[ptr->info] = true;
                        coada.push_back(ptr->info);
                    }

                }
            }
        }
    }
}


void Graph::DFS(int startNode) {
    bool* visited = new bool[n];
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    DFSUtil(startNode, visited);
}

void Graph::DFSUtil(int node, bool visited[]) {
    visited[node] = true;
    cout << node << " ";
    nod* ptr = NULL;
    for (int i = 0; i < n; i++) 
        if (lista[i].info == node) 
            ptr = &lista[i];
    while (ptr->next) {
        ptr = ptr->next;
        if (!visited[ptr->info]) {
            DFSUtil(ptr->info, visited);
        }
    }
}

int Graph::twoCycles() {
    int nr = 0;
    for (int i = 0; i < n; i++)
    {
        nod* ptr1 = &lista[i];
        while (ptr1->next) {
            ptr1 = ptr1->next;
            for (int j = 0; j < n; j++) {
                if (lista[j].info == ptr1->info) {
                    nod* ptr2 = &lista[j];
                    while (ptr2->next) {
                        ptr2 = ptr2->next;
                        if (ptr2->info == lista[i].info)nr++;
                    }
                }
            }

        }
    }
    return nr / 2;
}

int main()
{
    Graph graf;
    graf.addNode(1);
    graf.addNode(2);
    graf.addNode(3);
    graf.addNode(4);
    graf.addNode(5);
    graf.addEdge(3, 4);
    graf.addEdge(1, 2);
    graf.addEdge(1, 4);
    graf.addEdge(3, 2);
    graf.addEdge(4, 3);
    graf.addEdge(2, 5);
    graf.addEdge(5, 2);
    cout << graf.hasEdge(1, 4) << endl;
    graf.BFS(1);
    cout << endl;
    graf.DFS(1);
    cout << endl;
    cout << graf.twoCycles();
    return 0;
}
