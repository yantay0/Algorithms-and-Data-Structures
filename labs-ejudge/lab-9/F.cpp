#include <iostream>
#include <vector> 
using namespace std;

vector <unsigned long long> prefixFunction(string s)
{
    vector <unsigned long long > pre(s.size());
    pre[0] = 0;
    for(int i = 1; i < s.size(); i++){
        int j = pre[i - 1];
        while(j > 0 and s[j] != s[i]){ 
            j = pre[j - 1];
        }
        if(s[j] == s[i]){
            pre[i] = j + 1;
        }
        else{
            pre[i] = 0;
        }
    }
    return pre;
}

vector <unsigned long long > kmp(string s, string t)
{
    s = t + '#' + s;
    vector <unsigned long long > ans;
    vector <unsigned long long> pre = prefixFunction(s);
    for(int i = 0; i < s.size(); i++){
        if(pre[i] == t.size()){
            ans.push_back(i - 2 * t.size());
        }
    }
    return ans;
}
int main(){
    string text; cin >> text;
    string pattern; cin >> pattern;
    vector <unsigned long long> ans = kmp(text,pattern);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] + 1 << " ";
    }

}