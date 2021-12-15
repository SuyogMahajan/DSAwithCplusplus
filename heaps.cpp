#include <iostream>
#include <vector>
using namespace std;

class heap
{

  bool cmpr(int child, int prnt)
  {
    if (minheap)
      return prnt > child;

    else
      return prnt < child;
  }
  // o(NlogN) approach
  void makeitheap()
  {

    for (int i = 1; i < a.size(); i++)
    {
      int idx = i;
      int pidx = i / 2;

      while (idx > 1 && cmpr(a[idx], a[pidx]))
      {
        swap(a[idx], a[pidx]);
        idx = pidx;
        pidx = idx / 2;
      }
    }
  }

  void makeitheap2()
  {
    int n = a.size() - 1;

    for (int i = n / 2; i >= 1; i--)
    {
      if (cmpr(a[i * 2], a[i]) or cmpr(a[i * 2 + 1], a[i]))
      {
        heapify(i);
      }
    }
  }

public:
  vector<int> a;
  bool minheap;

  heap(int defsize = 10, bool m = true)
  {
    a.reserve(defsize);
    a.push_back(-1);
    minheap = m;
  }

  heap(vector<int> &v, bool m = true)
  {
    a = v;
    makeitheap2();
  }

  void push(int x)
  {
    a.push_back(x);
    int idx = a.size() - 1;
    int prnt = idx / 2;

    while (idx > 1 and cmpr(a[idx], a[prnt]))
    {
      swap(a[idx], a[prnt]);
      idx = prnt;
      prnt /= 2;
    }
  }

  void heapify(int i)
  {

    if (i >= a.size())
      return;

    int t = a.size() - 1;
    int min3 = i;

    int l = i * 2;
    int r = l + 1;

    if (l <= t && cmpr(a[l], a[min3]))
    {
      min3 = l;
    }
    if (r <= t && cmpr(a[r], a[min3]))
    {
      min3 = r;
    }
    if (min3 != i)
    {
      swap(a[min3], a[i]);
      heapify(min3);
    }
  }

 /* void sortTheHeap(heap h){

    int n = h.a.size()-1;
    
    while(n>1){ 
      swap(h.a[1],h.a[n]);
      n--;
      
    }

  }*/

  int pop()
  {

    // swap 1st and last
    swap(a[1], a.back());
    // stor last i.e. answer
    int ans = a.back();
    // pop from vector
    a.pop_back();

    heapify(1);
    return ans;
  }
  int top() const
  {
    return a[1];
  }
  void print()
  {
    for (auto x : a)
      cout << x << " ";
  }
};
 bool cmpr2(int child, int prnt)
  {
      return prnt > child;
  }
void heapify2(vector<int> a,int i,int n)
  {

    if (i > n)
      return;

    int t = n;
    int min3 = i;

    int l = i * 2;
    int r = l + 1;

    if (l <= t && cmpr2(a[l], a[min3]))
    {
      min3 = l;
    }
    if (r <= t && cmpr2(a[r], a[min3]))
    {
      min3 = r;
    }
    if (min3 != i)
    {
      swap(a[min3], a[i]);
      heapify2(a,min3,n);
    }
  }
int main()
{

  vector<int> v;
  int n;
  cin >> n;
  v.push_back(-1);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }

  heap a(v, true);

  a.print();
  cout << endl;

  while (n--)
  {
    cout << a.pop() << endl;
  }

  return 0;
}