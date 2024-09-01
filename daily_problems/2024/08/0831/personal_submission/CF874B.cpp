#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int,int>
#define se second
#define fi first
class cmp{
public:
    bool operator()(const pii i, const pii j){
        return i.se > j.se;
    }
};
int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    multiset<pii, cmp>st;
    int tot = 0;

    int n;
    cin >> n;
    vector<int>a(n);
    vector<vector<int>>ans;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        auto it = st.lower_bound(pii(0, a[i]));
        if(it == st.end()){
            ans.push_back(vector<int>(1, a[i]));
            st.insert(pii(tot++, a[i]));
        }
        else {
            ans[it->first].push_back(a[i]);
            pii temp(it->first, a[i]);
            st.erase(it);
            st.insert(temp);
        }
    }

    for(int i = 0;i < ans.size(); i++){
        for(int j = 0;j < ans[i].size(); j++){
            cout << ans[i][j] << ' ';
        }
        cout << "\n";
    }

}
