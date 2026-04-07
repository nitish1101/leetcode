class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        stack<int> s; int c=32;
        while(c--)
        {
            s.push(n & 1);
            n=n>>1;
        }
        uint32_t x=0; int i=0;
        while(!s.empty())
        {
            x=x+pow(2,i)*s.top();
            s.pop();
            i++;
        }
        return x;
        
    }
};