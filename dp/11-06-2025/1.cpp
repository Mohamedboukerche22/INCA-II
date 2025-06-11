#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
         cin >>a[i];
        }
        sort(a.rbegin(), a.rend()); 

        int res = 0, size = 0;

        for (int i = 0; i < n; ++i)
        {
            size++;
            if (size * a[i] >= x) 
            {
                res++;           
                size = 0;   
            }
        }

        cout << res << "\n";
    }

    return 0;
}
