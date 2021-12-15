#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{

  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<int>> right;

  int d;
  cin >> d;
  left.push(d);
  float median = d;
  cout << "Median : " << median << endl;
  cin >> d;
  while (d != -1)
  {
    if (left.size() > right.size())
    {
      if (d < median)
      {
        right.push(left.top());
        left.pop();
        left.push(d);
      }
      else
      {
        right.push(d);
      }
      median = float((left.top() + right.top())) / 2.0;
    }
    else if (left.size() == right.size())
    {

      if (d < median)
      {
        left.push(d);
        median = left.top();
      }
      else
      {
        right.push(d);
        median = right.top();
      }
    }
    else
    {

      if (d < median)
      {
        left.push(d);
      }
      else
      {
        left.push(right.top());
        right.pop();
        right.push(d);
      }
      median = float((left.top() + right.top())) / 2.0;
    }

    cout << "Median : " << median << endl;

    cin >> d;
  }

  return 0;
}