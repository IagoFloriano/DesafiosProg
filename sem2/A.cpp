#include <bits/stdc++.h>
using namespace std;

int main() {
  deque<long int> FIFO;
  stack<long int> LIFO;
  vector<long int> PRIO;
  long int I, E, n;
  bool bFIFO, bLIFO, bPRIO;
  bFIFO = bLIFO = bPRIO = true;

  cin >> n;
  for (int i = 0; i < n; i ++){
    cin >> I >> E;

    if ( I == 0 ) {
      FIFO.push_back(E);
      LIFO.push(E);
      PRIO.push_back(E);
      push_heap(PRIO.begin(), PRIO.end());
    }

    else{
      if ( bFIFO && FIFO[0] == E) {
        FIFO.pop_front();
      } else bFIFO = false;
      if ( bLIFO && LIFO.top() == E) {
        LIFO.pop();
      } else bLIFO = false;

      if ( bPRIO && PRIO[0] == E) {
        pop_heap(PRIO.begin(), PRIO.end());
        PRIO.pop_back();
      } else bPRIO = false;

    }

  }
  if (bFIFO + bLIFO + bPRIO > 1){
    cout << "ambiguous\n";
  }
  else if (bFIFO) cout << "fifo\n";
  else if (bLIFO) cout << "lifo\n";
  else if (bPRIO) cout << "priority\n";
  else cout << "unknown\n";

}
