#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ostream>

using namespace std;

int indexOf(vector<vector<int>> arrs, int value) {
    for (int i = 0; i < arrs.size(); i++)
        if (find(arrs[i].begin(), arrs[i].end(), value) != arrs[i].end())
            return i;
    return -1;
}

vector<string> split(string s, string delim) {
    size_t pos_start = 0, pos_end, delim_len = delim.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delim, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

void insert(vector<int>& base, vector<int>& extend) {
    base.reserve(base.size() + distance(extend.begin(), extend.end()));
    base.insert(base.end(), extend.begin(), extend.end());            
}

void exibir(vector<int> vetor) {
    int S = vetor.size();
    for (int s = 0; s < S; s++)
    {
        printf("%d", vetor[s]);
        if (s + 1 < S) printf(" ");
    }
    printf("\n");
}

int main(void) {
    int P, E, p, e;
    scanf("%d %d", &P, &E);
    getchar();
    
    vector<vector<int>> Seguros;
    vector<vector<int>> Inseguros;

    for (p = 1; p <= P; p++) {
        vector<int> data;
        data.push_back(p);
        Seguros.push_back(data);
    }

    for (e = 0; e < E; e++) {
        string cmd_;
        getline(cin, cmd_);
        vector<string> cmd = split(cmd_, " ");

        if (cmd[0] == "c") {
            int P1 = stoi(cmd[1]);
            int P2 = stoi(cmd[2]);

            int iP1 = indexOf(Seguros, P1), iP2 = indexOf(Seguros, P2), tmp;
            if (iP1 != -1 && iP2 != -1) {
                if (iP1 == iP2) continue;
                if (iP1 > iP2) {
                    tmp = iP2;
                    iP2 = iP1;
                    iP1 = tmp;

                    tmp = P2;
                    P2 = P1;
                    P1 = tmp;
                }

                insert(Seguros[iP1], Seguros[iP2]);
                Seguros.erase(Seguros.begin() + iP2);
            } else {
                if (iP1 == -1 && iP2 != -1) {
                    iP1 = indexOf(Inseguros, P1);
                    insert(Inseguros[iP1], Seguros[iP2]);
                    Seguros.erase(Seguros.begin() + iP2);
                } 
                else if (iP2 == -1 && iP1 != -1) {
                    iP2 = indexOf(Inseguros, P2);
                    insert(Inseguros[iP2], Seguros[iP1]);
                    Seguros.erase(Seguros.begin() + iP1);
                } 
                else {
                    iP1 = indexOf(Inseguros, P1);
                    iP2 = indexOf(Inseguros, P2);
                    if (iP1 == iP2) continue;
                    insert(Inseguros[iP1], Inseguros[iP2]);
                    Inseguros.erase(Inseguros.begin() + iP2);
                }
            }
        }
        else if (cmd[0] == "p") {
            int P = stoi(cmd[1]);
            int iP = indexOf(Seguros, P);

            if (iP != -1) {
                vector<int> S_;
                S_ = Seguros[iP];
                Seguros.erase(Seguros.begin() + iP);
                Inseguros.push_back(S_);
            }
        }
        else if (cmd[0] == "n") printf("%d\n", (Seguros.size() + Inseguros.size()));
        else if (cmd[0] == "ns") printf("%d\n", Seguros.size());
        else if (cmd[0] == "ni") printf("%d\n", Inseguros.size());
        else if (cmd[0] == "ii") {
            int T = Inseguros.size(), t;
            if (T == 0) printf("vazio\n");
            else {
                vector<int> result;
                for (t = 0; t < T; t++) insert(result, Inseguros[t]);
                sort(result.begin(), result.end());
                exibir(result);
            }
        }
    }
    return 0;
}