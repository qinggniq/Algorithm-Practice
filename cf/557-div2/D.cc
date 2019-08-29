#define IOS                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#include <bitset>
#include <cstdio>   //sprintf islower isupper
#include <cstdlib>  //malloc  exit strcat itoa system("cls")
#include <fstream>
#include <iostream>  //pair
//#include <map>
//#include<unordered_map>  https://codeforc.es/contest/1201/problem/D
#include <string.h>  //strstr substr
#include <time.h>    //srand(((unsigned)time(NULL))); Seed n=rand()%10 - 0~9;
#include <cmath>
#include <deque>
#include <queue>  //priority_queue<int, vector<int>, greater<int> > q;//less
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <vector>  //emplace_back
//#include <math.h>
//#include <windows.h>//reverse(a,a+len);// ~ ! ~ ! floor
#include <algorithm>  //sort + unique : sz=unique(b+1,b+n+1)-(b+1);+nth_element(first, nth, last, compare)
using namespace std;  // next_permutation(a+1,a+1+n);//prev_permutation
#define fo(a, b, c) for (register int a = b; a <= c; ++a)
#define fr(a, b, c) for (register int a = b; a >= c; --a)
#define mem(a, b) memset(a, b, sizeof(a))
#define pr printf
#define sc scanf
void swapp(int &a, int &b);
double fabss(double a);
int maxx(int a, int b);
int minn(int a, int b);
int Del_bit_1(int n);
int lowbit(int n);
int abss(int a);
const long long INF = (1LL << 60);
const double E = 2.718281828;
const double PI = acos(-1.0);
const int inf = (1 << 29);
const double ESP = 1e-9;
const int mod = (int)1e9 + 7;
const int N = (int)2e5 + 10;

int dis(int a, int b) { return abss(a - b); }
int L[N], R[N], LV[N], RV[N];
struct node {
  int x, y;
  friend bool operator<(node a, node b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
  }
} _[N];
int is[N];

int main() {
  int n, m, k, q, n_ = 0;
  sc("%d%d%d%d", &n, &m, &k, &q);
  fo(i, 1, k) sc("%d%d", &_[i].y, &_[i].x);  //题目中取完一行只可能停留在头和尾
  sort(_ + 1, _ + 1 + k);                    //下一行进行转移就行了
  fo(i, 1, k) {
    int tx = _[i].x, ty = _[i].y;
    n_ = maxx(n_, ty);
    if (!LV[ty])
      LV[ty] = tx;  //预处理
    else
      LV[ty] = minn(tx, LV[ty]);  //宝藏的最左
    if (!RV[ty])
      RV[ty] = tx;
    else
      RV[ty] = maxx(tx, RV[ty]);  //宝藏的最右
  }
  fo(i, 1, q) sc("%d", &is[i]), L[is[i]] = R[is[i]] = is[i];
  sort(is + 1, is + 1 + q);                //预处理
  fo(i, 1, m) if (!L[i]) L[i] = L[i - 1];  //左邻近的安全列
  fr(i, m, 1) if (!R[i]) R[i] = R[i + 1];  //右邻近的安全列
  int posl = 1, posr = 1;
  long long ans = 0, preresl = 0, preresr = 0;
  fo(i, 1, n_) {
    if (i == 1) {
      if (RV[i]) ans = dis(posl, RV[i]), posl = posr = RV[i];
      preresl = preresr = ans;
    } else {
      preresl++;
      preresr++;  //除了第一行其他只要上升了,用于转移的左右停留状态都要+1;
      if (LV[i] == 0 && RV[i] == 0) continue;
      long long resl = INF, resr = INF;
      if (L[posl])
        resl = min(resl, preresl + dis(posl, L[posl]) + dis(L[posl], RV[i]) +
                             dis(RV[i], LV[i]));
      if (R[posl])
        resl = min(resl, preresl + dis(posl, R[posl]) + dis(R[posl], RV[i]) +
                             dis(RV[i], LV[i]));
      if (L[posr])
        resl = min(resl, preresr + dis(posr, L[posr]) + dis(L[posr], RV[i]) +
                             dis(RV[i], LV[i]));
      if (R[posr])
        resl = min(resl, preresr + dis(posr, R[posr]) + dis(R[posr], RV[i]) +
                             dis(RV[i], LV[i]));
      //进行转移;
      if (L[posl])
        resr = min(resr, preresl + dis(posl, L[posl]) + dis(L[posl], LV[i]) +
                             dis(RV[i], LV[i]));
      if (R[posl])
        resr = min(resr, preresl + dis(posl, R[posl]) + dis(R[posl], LV[i]) +
                             dis(RV[i], LV[i]));
      if (L[posr])
        resr = min(resr, preresr + dis(posr, L[posr]) + dis(L[posr], LV[i]) +
                             dis(RV[i], LV[i]));
      if (R[posr])
        resr = min(resr, preresr + dis(posr, R[posr]) + dis(R[posr], LV[i]) +
                             dis(RV[i], LV[i]));
      ans = min(resl, resr);
      preresl = resl;
      preresr = resr;
      posl = LV[i];
      posr = RV[i];
    }
  }
  pr("%lld\n", ans);
  return 0;
}

/**************************************************************************************/

int maxx(int a, int b) { return a > b ? a : b; }

void swapp(int &a, int &b) { a ^= b ^= a ^= b; }

int lowbit(int n) { return n & (-n); }

int Del_bit_1(int n) { return n & (n - 1); }

int abss(int a) { return a > 0 ? a : -a; }

double fabss(double a) { return a > 0 ? a : -a; }

int minn(int a, int b) { return a < b ? a : b; }