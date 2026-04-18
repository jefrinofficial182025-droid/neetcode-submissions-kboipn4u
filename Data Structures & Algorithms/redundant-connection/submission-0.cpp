class Solution {
public:
    vector<int> parent;

    int findparent(int x) {
        if (parent[x] != x)
            parent[x] = findparent(parent[x]); // path compression
        return parent[x];
    }

    void unionset(int a, int b) {
        int rta = findparent(a);
        int rtb = findparent(b);
        if (rta != rtb)
            parent[rta] = rtb;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);

        // initialize 1 → n
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (findparent(u) == findparent(v)) {
                return {u, v};
            }

            unionset(u, v);
        }

        return {};
    }
};