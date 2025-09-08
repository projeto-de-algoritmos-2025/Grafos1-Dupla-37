#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct No {
    int vizinho;
    struct No* prox;
} No;

void addAresta(No** adj, int u, int v) {
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


int* maxTargetNodes(int** edges1, int edges1Size, int* edges1ColSize, int** edges2, int edges2Size, int* edges2ColSize, int* returnSize) {
    int n = edges1Size + 1;
    int m = edges2Size + 1;

    No** adj1 = (No**)malloc(n * sizeof(No*));
    memset(adj1, 0, n * sizeof(No*));
    for (int i = 0; i < edges1Size; i++) { 
        addAresta(adj1, edges1[i][0], edges1[i][1]);
    }

    int* paridade1 = (int*)malloc(n * sizeof(int));
    dfs(0, -1, 0, adj1, paridade1);

    long long countPar1 = 0, countImpar1 = 0;
    for (int i = 0; i < n; i++) {
        if (paridade1[i] == 0)
            countPar1++;
        else
            countImpar1++;
    }

    No** adj2 = (No**)malloc(m * sizeof(No*));
    memset(adj2, 0, m * sizeof(No*));
    for (int i = 0; i < edges2Size; i++) {
        addAresta(adj2, edges2[i][0], edges2[i][1]);
    }

    int* paridade2 = (int*)malloc(m * sizeof(int));
    dfs(0, -1, 0, adj2, paridade2);

    long long countPar2 = 0, countImpar2 = 0;
    for (int i = 0; i < m; i++) {
        if (paridade2[i] == 0)
            countPar2++;
        else
            countImpar2++;
    }
    
    long long maxNum2 = (countPar2 > countImpar2) ? countPar2 : countImpar2;

    int* resultado = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (paridade1[i] == 0)
            resultado[i] = countPar1 + maxNum2;
        else
            resultado[i] = countImpar1 + maxNum2;
    }

    *returnSize = n;
    
    return resultado;
}