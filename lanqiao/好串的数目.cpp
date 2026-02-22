#include<bits/stdc++.h>
using #include <bits/stdc++.h>
using namespace std;

long long count(long long L){
  return L * (L + 1) / 2;
}

int main(){
  string s;
  cin >> s;
  int n = s.length();

  vector<long long> v;
  int len = 1;
  for(int i = 1; i < n; i++){
    if(s[i] == s[i-1] || s[i] == s[i-1] + 1){
      len++;
    }else{
      v.push_back(len);
      len = 1;
    }
  }
  v.push_back(len);

  if(v.size() == 1){
    cout << count(v[0]) << endl;
    return 0;
  }

  long long ans = 0;
  for(int i = 0; i < v.size() - 1; i++){
    ans += count(v[i] + v[i+1]);
  }
  for(int i = 1; i < v.size() - 1; i++){
    ans -= count(v[i]);
  }
  cout << ans << endl;

  return 0;
}
