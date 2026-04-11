class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> ps(n);
        for(int i=0;i<n;i++){
            ps[i].first = position[i];
            ps[i].second = speed[i];
        }
        sort(ps.rbegin(),ps.rend());
        int res=1;
        double bestTimeToTarget = (target - ps[0].first)/ps[0].second;

        for(int i=1;i<n;i++){
            double timeToTarget = (double)(target - ps[i].first)/ps[i].second;
            if(timeToTarget>bestTimeToTarget){bestTimeToTarget=timeToTarget;res++;}

        }
        return res;
    }
};
