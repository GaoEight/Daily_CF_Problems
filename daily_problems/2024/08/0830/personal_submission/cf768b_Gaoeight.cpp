typedef long long ll;
ll n, l, r;

ll find(ll cur, ll l1, ll r1){
	if(l <= l1 && r >= r1)return cur;
	if(l > r1 || r < l1)return 0;
	if(r1 == l1)return cur;
	if(r1 < l1)return 0;
	ll ans = 0;
	if(cur == 0 || cur == 1)return cur;
	ans += find(cur / 2, l1, (l1 + r1) / 2 - 1);
	ans += find(cur % 2, (l1 + r1) / 2, (l1 + r1) / 2);
	ans += find(cur / 2, (l1 + r1) / 2 + 1, r1);
	
	return ans;
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n >> l >> r;
	
	ll all = 0;
	for(int i = 0;ll(n >> i) > 0;i++){
		all |= ll(1LL << i);
	}
	
	ll ans = find(n, 1, all);
	cout << ans << "\n";

}
