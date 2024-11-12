using namespace std;

long long  gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}


long long solution(int w,int h) {
    return  (long long)w * h - ((long long)w + h - gcd(w, h));
}
