class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int size=0;
        for(int i=n-1;i>=0;i--){
            if(size==0 && s[i]==' ')
                continue;
            if(s[i]==' ')
                return size;
            size++;
        }
        return size;
    }
};