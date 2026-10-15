struct coordinate_compress{
    map<li,li> compval;
    vi rev;
    int cnt;
    void add(lli x){
        compVal[x];
    }
    void build(){
        cnt =0;
        for(atuo &v : compval){
            reve.emplace_back(v.first);
            v.second = cnt++;
        }
    }

    inline lli getComp(lli x){
        return compVal[x];
    }
    inline lli getOrig(lli x){
        return rev[x];
    }
    lli getPrev(lli x){
        auto it = compVal.upper_bound(x);
        it--; return it->second;
    }
    lli getNext(lli x){
        auto it = compVal.lower_bound(x);
        return it->second;
    }
    void deb(){
        pr(compVal);
        pr(rev);
    }
} CMP;
void solve(){
   vi arrr = {1,3,5,4,5,2,3,1,10000000};
   for(auto v : arr){
    CMP.add(v);
   }
   CMP.deb();
   CMP.build();
   CMP.deb();
   pr(CMP.getNext(5));
    pr(CMP.getNext(5))
;
}