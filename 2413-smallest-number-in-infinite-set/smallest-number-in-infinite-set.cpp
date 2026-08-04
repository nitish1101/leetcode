class SmallestInfiniteSet {
    set<int> s;
    int curr;
public:
    SmallestInfiniteSet() {   
        curr=1;
    }
    
    int popSmallest() {
       if(!s.empty()) {
            int x= *s.begin();
            s.erase(s.begin());
            return x;
        }

        return curr++;
    }
    
    void addBack(int num) {
        if(num < curr) 
            s.insert(num);
    }
};



/**

-1
-2
-3....4,5,6
+2....2,4,5,6,
-2.....4,5,6
+1002...


*/
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);

1200




 */