class MRUQueue {
public:
    list<int> li;
    list<int> :: iterator it;
    MRUQueue(int n) {
        int i;
        li.clear();
        for(i=1;i<=n;i++)
        {
            li.push_back(i);
        }
    }
    
    int fetch(int k) {
       int count=0;
        for(it=li.begin();it!=li.end();it++)
        {
            count++;
            if(k==count)
            {
                int val=*it;
                li.erase(it);
                li.push_back(val);
                return val;
                break;
            }
        }
        return -1;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */