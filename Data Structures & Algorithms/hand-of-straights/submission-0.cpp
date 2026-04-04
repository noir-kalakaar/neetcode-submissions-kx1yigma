class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0)return false;
        int numG = n/groupSize;
        sort(hand.begin(),hand.end());

        while(numG--){
            int tmp = groupSize;
            int tmp2 = hand[0];
            hand.erase(hand.begin());
            tmp--;
            for(int i=0;i<hand.size() && tmp>0;){
               if(hand[i]-tmp2==1){
                tmp2=hand[i];
                tmp--;
                hand.erase(hand.begin()+i);
               }
               else i++;
               
            }
            if(tmp!=0)return false;
            

        }
        return true;
        

    }
};
