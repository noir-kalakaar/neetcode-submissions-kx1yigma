class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int n = gas.size();
       int ans=0,currTank=0,tCost=0,tGas=0;
       bool flg = false;
       for(int i=0;i<n;i++){
        tCost+=cost[i];tGas+=gas[i];
        currTank += gas[i]-cost[i];
        
        if(currTank<0){
            ans=i+1;
            currTank=0;
        }

       }

       return (tGas>=tCost) ? ans : -1;
    }
};
