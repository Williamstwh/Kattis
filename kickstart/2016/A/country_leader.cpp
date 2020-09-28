#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        cin.ignore();
        
        string res = "";
        int count = 0;
        for (int j = 0; j < m; j++) {
            string s;
            getline(cin, s);
            
            set<char> ss;
    		    for (int k = 0; k < s.size(); k++) {
                if (s[k] < 'A' || s[k] > 'Z') {
        		        continue;
            		}
		            ss.insert(s[k]);
    		    }
            if (ss.size() > count) {
        		    res = s;
            		count = ss.size();
            } else if (ss.size() == count && s < res) {
    		         res = s;
    		    }
        }
        
        cout << "Case #" << (i + 1) << ": " << res << '\n' ;
    }
    return 0;  
}
