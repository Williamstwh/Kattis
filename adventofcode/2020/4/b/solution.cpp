#define INPUT "1.in"
#define DEBUG 1

#include <bits/stdc++.h>

using namespace std;

#ifndef ENABLE_DEBUG
#define DEBUG 0
#endif
#if DEBUG == 1
#define DE(x) x;
#else
#define DE(x)
#endif

#define IOSBASE ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define mst(a,b) memset((a),(b),sizeof(a))
#define mp(a,b) make_pair(a,b)
#define pi acos(-1)
#define pii pair<int,int>
#define pb push_back
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const ll mod = 1e9 + 7;

void reset(map<string, string>& m) {
    m["ecl"] =  "";
    m["pid"] =  "";
    m["eyr"] =  "";
    m["hcl"] =  "";
    m["byr"] =  "";
    m["iyr"] =  "";
    m["cid"] =  "";
    m["hgt"] =  "";
}

bool isNumber(string s) {
    if (s == "") return false;
    for (char c : s) {
      if (c < '0' || c > '9') {
          return false;
      }
    };
    return true;
}

bool numInRange(string num, int start, int end) {
    if (!isNumber(num)) return false;
    int n = stoi(num);
    return start <= n && n <= end;
}

bool isValidHeight(string h) {
    string f = h.substr(0, h.size() - 2);
    string b = h.substr(h.size() - 2, 2);
    if (b == "cm") {
        return numInRange(f, 150, 193);
    }
    if (b == "in") {
        return numInRange(f, 59, 76);
    }

    return false;
}

bool isValidHairColor(string h) {
    if (h.size() != 7) return false;

    if (h[0] != '#') {
        return false;
    }

    for (int i = 1; i <= 6; i++) {
        if ((h[i] < '0' || h[i] > '9') && (h[i] < 'a' || h[i] > 'f')) {
            return false;
        }
    }
    return true;
}

bool isValidEyeColor(string ecl) {
    set<string> s{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    return s.find(ecl) != s.end();
}

bool isValidPid(string pid) {
    if (pid.size() != 9) return false;
    return isNumber(pid);
}

bool isValid(map<string, string> &m) {
    return
            numInRange(m["byr"], 1920, 2002) &&
            numInRange(m["iyr"], 2010, 2020) &&
            numInRange(m["eyr"], 2020, 2030) &&
            isValidHeight(m["hgt"]) &&
    isValidHairColor(m["hcl"]) &&
    isValidEyeColor(m["ecl"]) &&
    isValidPid(m["pid"]);
}

void solve() {
    map<string, string> m;
    string s;
    reset(m);

    int count = 0;
    while (getline(cin, s)) {
        if (s == "") {
            if (isValid(m)) {
                count++;
            }
            cout << (isValid(m) ? "VALID" : "INVALID") << "\n\n";
            reset(m);
        } else {
            stringstream ss(s);
            string kvp;
            cout << s << ' ';
            while(ss >> kvp) {
                stringstream ss2(kvp);
                string key, value;
                getline(ss2, key, ':');
                getline(ss2, value, ':');
                m[key] = value;
            }
            cout << '\n';
        }
    }
    if (isValid(m)) {
        count++;
    }
    cout << (isValid(m) ? "VALID" : "INVALID") << "\n\n";
    cout << count << '\n';
}

int main() {
#ifdef READ_STDIN_FROM_FILE
    freopen(INPUT, "r", stdin);
#endif
    IOSBASE;
    solve();
    return 0;
}
