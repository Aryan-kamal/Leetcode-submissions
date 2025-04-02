class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        int pSum[n][m];
        for(int i=0;i<m;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=matrix[j][i]-'0';
                if(matrix[j][i]=='0')
                    sum=0;
                pSum[j][i]=sum;
            }
        }
        for(int i=0;i<n;i++)
        {
            vector<int> vec((pSum[i]), (pSum[i]) + m);
            maxArea=max(maxArea,largestRectangleArea(vec));
        }   
        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),maxArea=0;
        stack<int>st;
        for(int i =0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int element=st.top();
                st.pop();
                int nse=i,pse=st.empty()?-1:st.top();
                maxArea=max(maxArea,heights[element]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int element=st.top();
            st.pop();
            int nse=n,pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,heights[element]*(nse-pse-1));
        }
        return maxArea;
    }
};