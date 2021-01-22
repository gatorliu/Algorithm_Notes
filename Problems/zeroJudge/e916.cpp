// https://zerojudge.tw/ShowProblem?problemid=e915
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

/*
#define len first 
#define no second



int solve_1(ll n, ll k) { // 超出記憶體
    if (k==1) return 1;
    if (k==2) return n;
    set< pair<ll, ll> > st; 
    st.insert({-(n-2), 1}); // 存負值，才可以sort
    ll ans;
    for (ll i=3; i<=k; i++) {
        auto it = st.begin();
//    cout << "   " << (*it).no << ":" << -(*it).len << endl;
        ll len = -(*it).len;
        ll no = (*it).no;
        // (*it).len = - ((l + 1) / 2 - 1);
        ans = no + ((len+1)/2);
        st.erase(it);
//    cout << "           " << ans << ":" << -(len/2) << endl;
//    cout << "           " << no << ":" << - ((len + 1) / 2 - 1) << endl;
        st.insert({ -(len/2) , ans });
        st.insert({ - ((len + 1) / 2 - 1) , no });

    } 
    return ans;
}
*/

struct SD {
    ll len;
    set<ll> *nos; // number set
    friend bool operator<( const SD& a, const SD& b) {
        return a.len > b.len;
    }
    
};


ll solve(ll n, ll k) { // 超出記憶體
    if (k==1) return 1;
    if (k==2) return n;
    set<SD> st;

    ll len, s,e,mid;
    set<ll> nos = {1};
    st.insert({n-1, &nos});
    
    for (ll i=3; i<=k;i++) {
        auto it = st.begin();
         cout << "\t" << (*it).len << " : " << *((*it).nos->begin()) << endl;
        while((*it).nos->size() == 0) {
            st.erase(it);
            it = st.begin();
            cout << "\t" << (*it).len << " : " << *((*it).nos->begin()) << endl;

        }
        cout << "\t" << (*it).len << " : " << *((*it).nos->begin()) << endl;
        auto nosit = (*it).nos->begin();
        //for(auto nosit = (*it).nos->begin(); nosit != (*it).nos->end(); nosit++) {
        //for (auto no : *((*it).nos) ) {
       // while((*it).nos->size()>0) {

            ll no =  *nosit;
            
            s = no; cout << s  << endl;
            e = no+(*(it)).len;
            mid= (s+e)/2;

            if (i == k) return mid;

            set<SD>::iterator it2;
            if (mid-s == e-mid && mid-s>1) {
                len = mid-s;
                cout << "\t1\t" << "i= " <<  i << " len=" << len <<  " : " << s << ", " << mid << endl;
                it2 = st.find({len});
                if ( it2 == st.end()) { // no find
                    set<ll> tmp={};
                    it2 = (st.insert({len, &tmp})).first;
                }
                (*it2).nos->insert(s);
                (*it2).nos->insert(mid);

            }  else {
                len = e-mid;
                if (len > 1) {
                    cout << "\t2\t" << "i= " <<  i << " len=" << len <<  " : m=" << mid << endl;
                    it2 = st.find({len});
                    if ( it2 == st.end()) { // no find
                        set<ll> tmp={};
                        it2 = (st.insert({len, &tmp})).first;
                    }
                    (*it2).nos->insert(mid);
                
                    len = mid-s;
                    if (len > 1) {
                        cout << "\t2\t" << "i= " <<  i << " len=" << len <<  " : s=" << s << endl;
                        it2 = st.find({len});
                        cout<< "@#@#@1 " << endl;
                        if ( it2 == st.end()) { // no find
                            set<ll> tmp={};
                            cout<< "@#@#@2" << endl;
                            it2 = (st.insert({len, &tmp})).first;
                            cout<< "@#@#@3" << endl;
                        }
                        cout<< "@#@#@4" << endl;
                        (* (st.find({len}))).nos->insert(s);
                        cout<< "@#@#@" << endl;
                    }
                }
            }
        cout << "erase: " << no << endl;
        (*it).nos-> erase(no);
    }
    return mid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        ll n, k ;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
        
    return 0;
}

