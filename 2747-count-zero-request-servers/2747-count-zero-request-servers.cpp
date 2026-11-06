class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m= logs.size();
        // on the basis of time
        auto lambda=[](vector<int>&vec1,vector<int>&vec2){
               return vec1[1]<vec2[1]; // sort on basis of time
        };
        sort(begin(logs),end(logs), lambda);
        int q= queries.size();
        vector<int>result(q);

        vector<pair<int,int>>timeIndex(q);
        for(int i=0;i<q;i++){
            timeIndex[i]={queries[i],i};
        }
         sort(begin(timeIndex),end(timeIndex)); //on the bais of time

         unordered_map<int,int>mp;
         int i=0;
         int j=0;

         for(auto [time, idx]: timeIndex){
            // range
            int start= time-x;
            int end=time;

            //exp
            while(j<m && logs[j][1]<=end){
                mp[logs[j][0]]++;
                j++;
            }
            
            while(i<m && logs[i][1]<start){
                mp[logs[i][0]]--;
                if( mp[logs[i][0]]==0){
                    mp.erase(logs[i][0]);
                }
                i++;
            }

            result[idx]=n-mp.size();  // no of server getting request

         } 
         return result;
    }
};