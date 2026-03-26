// WAP to implement Vertex Cover Problem using approximation algorithm.
#include <iostream>
#define max 20
using namespace std;

int main(){
    int n,e;
    int u[max],v[max];
    int visited[max] = {0};
    int i,j;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    cout << "Enter edges (u v):" << endl;
    for(i=0;i<e;i++){
        cin >> u[i] >> v[i];
    }
    for(i=0;i<e;i++){
        if(!visited[u[i]] == 0 && !visited[v[i]] == 0){
            visited[u[i]] = 1;
            visited[v[i]] = 1;
        }
    }
    cout << "Vertex Cover: ";
    for(i=0;i<n;i++){
        if(visited[i] == 1){
            cout << i << " ";
        }
    }
    return 0;

}