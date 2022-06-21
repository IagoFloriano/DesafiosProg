#include <bits/stdc++.h>
using namespace std;

void showlist(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
}
  
int main() {
  int n;
  cin >> n;

  list<int> fita;
  list<int>::iterator it;
  list<int>::iterator temp;
  for (int i = 0; i < n; i++){
    char op;
    cin >> op;
    int q;
    switch(op){

      case 'm':
        cin >> q;
        advance(it, q);
        break;

      case 'i':
        int nv;
        cin >> q >> nv;
        if (!fita.empty())
          it = fita.insert(it, q, nv);
        else
          it = fita.insert(fita.begin(), q, nv);
        break;

      case 'd':
        it = fita.erase(it);
        break;

      case 'q':
        cout << *it << "\n";
        break;
    }
    //showlist(fita);
  }

}
