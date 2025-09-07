#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct No {
    int vizinho;
    struct No* prox;
} No;

void addAresta (No** adj, int u, int v){
    No* novoNoU = (No*)malloc(sizeof(No));
    novoNoU->vizinho = v;
    novoNoU->prox = adj[u];
    adj[u] = novoNoU;

    No* novoNoV = (No*)malloc(sizeof(No));
    novoNoV->vizinho = u;
    novoNoV->prox = adj[v];
    adj[v] = novoNoV;
}

void dfs(int u, int p, int dist, No** adj, int* paridade) {
    paridade[u] = dist % 2;

    No* viz = adj[u];

    while (viz != NULL) {
        int v = viz->vizinho;
        if (v != p) {
            dfs(v, u, dist + 1, adj, paridade);
        }
        viz = viz->prox;
    }
}


