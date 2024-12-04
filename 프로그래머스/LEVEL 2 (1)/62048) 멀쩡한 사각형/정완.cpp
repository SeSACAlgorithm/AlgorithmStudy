typedef long long ll;

using namespace std;

ll gcd(int w, int h) {
    int c;
    
    while(h != 0)
    {
        c = w % h;
        w = h;
        h = c;
    }
    
    return w;
}

ll solution(int w,int h) {
    ll ans = 1;
    ans = (ll)w * (ll)h - (w+h);
    ans += gcd(w, h);
    
    return ans;
}
