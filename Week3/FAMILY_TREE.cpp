#include <bits/stdc++.h>

using namespace std;

struct Relation {
    string child;
    string parent;
};

vector<Relation> relations;

int count_descendants(string person) {
    int count = 0;
    for (auto relation : relations) {
        if (relation.parent == person) {
            count += 1 + count_descendants(relation.child);
        }
    }
    return count;
}

int count_generations(string person) {
    int max = 0;
    for (auto relation : relations) {
        if (relation.parent == person) {
            int cur = 1 + count_generations(relation.child);
            if (cur > max) {
                max = cur;
            }
        }
    }
    return max;
}

int main() {
    string child, parent;

    while (true) {
        cin >> child;
        if (child == "***") break;
        cin >> parent;
        relations.push_back({child, parent});
    }

    string q, s;

    while (true) {
        cin >> q;
        if (q == "***") break;
        cin >> s;

        if (q == "descendants") {
            cout << count_descendants(s) << endl;
        } else if (q == "generation") {
            cout << count_generations(s) << endl;
        }
    }

    return 0;
}
