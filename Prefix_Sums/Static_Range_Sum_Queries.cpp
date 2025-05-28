#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int  MAX = 1e6;
int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
  ll lol[MAX+1];
  int N,Q;
  cin >>N>>Q;
  for(int i=0;i<N;i++){
    cin >>lol[i];
  }
  for(int i=1;i<N;i++){
   lol[i]+=lol[i-1];
  }
  while(Q--){
   int a,b; 
   cin >>a>>b;
   a--;b--;
   if(a==0){
      cout <<lol[b]<<endl;
   }else{
      cout <<lol[b]-lol[a-1]<<endl;
   }
   
  }
  return 0;
}
