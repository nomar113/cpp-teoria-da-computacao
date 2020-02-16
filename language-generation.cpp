#include <bits/stdc++.h>
using namespace std;

int maxSize = 0;
unordered_map<int, vector<vector<int>>> adjacencyList(40);

void permutation(vector<int> &vectorPermutation, int inf, int sup) {
    if (inf == sup) {
        if (vectorPermutation.size() > maxSize) {
            maxSize = vectorPermutation.size();
        }
        adjacencyList[vectorPermutation.size()].push_back(vectorPermutation);
    } else {
        for (int i = inf; i <= sup; i++) {
            swap(vectorPermutation[inf], vectorPermutation[i]);
            permutation(vectorPermutation, (inf + 1), sup);
            swap(vectorPermutation[inf], vectorPermutation[i]);  //backtracking
        }
    }
}

void combination(vector<int> &v, int v_bool[], int i, int tam_v) {
    vector<int> valuesToPermutation;
    if (i == tam_v) {
        for (int j = 0; j < tam_v; j++) {
            if (v_bool[j] == 1) {
                valuesToPermutation.push_back(v[j]);
            }
        }
        permutation(valuesToPermutation, 0, valuesToPermutation.size() - 1);
        valuesToPermutation.clear();
    } else {
        v_bool[i] = true;
        combination(v, v_bool, i + 1, tam_v);
        v_bool[i] = false;
        combination(v, v_bool, i + 1, tam_v);
    }
}

int main() {
    vector<int> v;
    v = {1, 2, 3, 4};
    int tam_v = v.size();
    int v_bool[tam_v];

    for (int i = 0; i < tam_v; i++) {
        v_bool[i] = false;
    }

    combination(v, v_bool, 0, tam_v);

    for (int i = 1; i <= maxSize; i++) {
        for (auto &v : adjacencyList[i]) {
            for (auto &e : v) {
                cout << e << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
