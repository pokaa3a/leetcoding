class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        if(nums1.empty()||nums2.empty()||k==0) return res;
        int n=nums1.size(), m=nums2.size();
        vector<int> rows(m,0);
        k=min(k,n*m);
        int colmin=0;
        for(int i=0; i<k; i++){
            int icolmin = colmin;
            int min = nums1[rows[colmin]] + nums2[colmin];
            for(int icol=colmin+1; icol<m; icol++){
                if(rows[icol]==rows[icol-1]) continue;
                int val = nums1[rows[icol]] + nums2[icol];
                if(val<min){
                    min = val;
                    icolmin = icol;
                }
            }
            res.push_back({nums1[rows[icolmin]], nums2[icolmin]});
            if(++rows[icolmin]==n) colmin++;
        }
        return res;
    }
};