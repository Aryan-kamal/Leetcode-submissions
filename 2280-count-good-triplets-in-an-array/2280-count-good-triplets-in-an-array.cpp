class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> elemToIndexMappingInB;
        int n = nums1.size();
        vector<long long> segmentTree(n * 4 + 1);
        long long ans = 0;
        for (int i = 0; i < nums2.size(); i++) 
            elemToIndexMappingInB[nums2[i]] = i;
        
        update(segmentTree, 1, 0, n - 1, elemToIndexMappingInB[nums1[0]]);
        for (int i = 1; i < n; i++) {
            int indexInB = elemToIndexMappingInB[nums1[i]];
            long long commonElementsOnLeft =
                query(segmentTree, 1, 0, n - 1, 0, indexInB);
            long long uniqueElementsOnLeftInA = i - commonElementsOnLeft;
            long long elementsAfterIndexInB = n - 1 - indexInB;
            long long commonElementsOnRight =
                elementsAfterIndexInB - uniqueElementsOnLeftInA;
            ans += commonElementsOnLeft * commonElementsOnRight;
            update(segmentTree, 1, 0, n - 1, indexInB);
        }
        return ans;
    }

private:
    void update(std::vector<long long>& st, int index, int start, int end,int updateIndex) {
        if (start == end) {
            st[index] += 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (updateIndex <= mid)
            update(st, index * 2, start, mid, updateIndex);
        else
            update(st, index * 2 + 1, mid + 1, end, updateIndex);
        st[index] = st[index * 2] + st[index * 2 + 1];
    }

    long long query(std::vector<long long>& st, int index, int start, int end,int queryStart, int queryEnd) {
        if (end < queryStart || start > queryEnd)
            return 0;
        if (start >= queryStart && end <= queryEnd)
            return st[index];
        int mid = start + (end - start) / 2;
        long long left = query(st, index * 2, start, mid, queryStart, queryEnd);
        long long right =
            query(st, index * 2 + 1, mid + 1, end, queryStart, queryEnd);
        return left + right;
    }
};