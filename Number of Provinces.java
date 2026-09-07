class Solution {
    private int find(int ldr[], int node){
        if(ldr[node] != node){
            ldr[node] = find(ldr, ldr[node]);
        }
        return ldr[node];
    }
    private void join(int ldr[], int lt, int rt){
        ldr[find(ldr,rt)] = find(ldr,lt);
    }
    public int findCircleNum(int[][] g) {
        int N = g.length;
        int ldr[] = new int[N+1];
        for(int node = 1; node <= N; node++) ldr[node] = node;
        for(int col=1; col<=N; col++){
            for(int row=1; row<=N; row++){
                if (row == col) continue;
                if(g[row-1][col-1] == 1){
                    join(ldr,row,col);
                }
            }
        }
        int provinces = 0;
        for (int node = 1; node <= N; node++){
            if(ldr[node] == node){
                provinces++;
            }
        }
        return provinces;
    }
};
