// for example

#include <bits/stdc++.h>
using namespace std;

struct Trie {
    static const int A = 26;

    // next[v][c] = index of child node, or -1 if no edge
    vector<array<int, A>> next;
    // is_terminate[v] = true iff some inserted word ends at node v
    vector<bool> is_terminate;

    Trie() {
        next.push_back(make_empty());
        is_terminate.push_back(false);
    }

    // Insert string s into the trie.
    void add(const string& s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (next[v][c] == -1) {
                next[v][c] = (int)next.size();
                next.push_back(make_empty());
                is_terminate.push_back(false);
            }
            v = next[v][c];
        }
        is_terminate[v] = true;
    }

    // Return true iff s was inserted as a whole word.
    bool is_terminal(const string& s) const {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (next[v][c] == -1) return false;
            v = next[v][c];
        }
        return is_terminate[v];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie trie;
    trie.add("apple");
    trie.add("app");
    trie.add("apply");

    cout << trie.is_terminal("app") << '\n'; // 1
    cout << trie.is_terminal("appl"); // 0
}
