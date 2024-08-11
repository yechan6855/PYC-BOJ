#include <bits/stdc++.h>
using namespace std;

int tc;
vector<char> cube(55);

void color() {
    vector<char> colorArr = {'w', 'r', 'g', 'o', 'b', 'y'};
    for(int i = 0; i < 6; i++)
        for(int j = 1; j <= 9; j++)
            cube[i*9+j] = colorArr[i];
}

void U() {
    vector<char> tmp(21);
    tmp[0] = cube[34]; tmp[1] = cube[35]; tmp[2] = cube[36];
    tmp[3] = cube[21]; tmp[4] = cube[1]; tmp[5] = cube[2]; tmp[6] = cube[3]; tmp[7] = cube[37];
    tmp[8] = cube[24]; tmp[9] = cube[4]; tmp[10] = cube[5]; tmp[11] = cube[6]; tmp[12] = cube[40];
    tmp[13] = cube[27]; tmp[14] = cube[7]; tmp[15] = cube[8]; tmp[16] = cube[9]; tmp[17] = cube[43];
    tmp[18] = cube[10]; tmp[19] = cube[11]; tmp[20] = cube[12];

    cube[37] = tmp[0]; cube[40] = tmp[1]; cube[43] = tmp[2];
    cube[36] = tmp[3]; cube[3] = tmp[4]; cube[6] = tmp[5]; cube[9] = tmp[6]; cube[12] = tmp[7];
    cube[35] = tmp[8]; cube[2] = tmp[9]; cube[8] = tmp[11]; cube[11] = tmp[12];
    cube[34] = tmp[13]; cube[1] = tmp[14]; cube[4] = tmp[15]; cube[7] = tmp[16]; cube[10] = tmp[17];
    cube[21] = tmp[18]; cube[24] = tmp[19]; cube[27] = tmp[20];
}

void D() {
    vector<char> tmp(21);
    tmp[0] = cube[30]; tmp[1] = cube[29]; tmp[2] = cube[28];
    tmp[3] = cube[39]; tmp[4] = cube[46]; tmp[5] = cube[47]; tmp[6] = cube[48]; tmp[7] = cube[19];
    tmp[8] = cube[42]; tmp[9] = cube[49]; tmp[10] = cube[50]; tmp[11] = cube[51]; tmp[12] = cube[22];
    tmp[13] = cube[45]; tmp[14] = cube[52]; tmp[15] = cube[53]; tmp[16] = cube[54]; tmp[17] = cube[25];
    tmp[18] = cube[18]; tmp[19] = cube[17]; tmp[20] = cube[16];

    cube[19] = tmp[0]; cube[22] = tmp[1]; cube[25] = tmp[2];
    cube[28] = tmp[3]; cube[48] = tmp[4]; cube[51] = tmp[5]; cube[54] = tmp[6]; cube[16] = tmp[7];
    cube[29] = tmp[8]; cube[47] = tmp[9]; cube[53] = tmp[11]; cube[17] = tmp[12];
    cube[30] = tmp[13]; cube[46] = tmp[14]; cube[49] = tmp[15]; cube[52] = tmp[16]; cube[18] = tmp[17];
    cube[39] = tmp[18]; cube[42] = tmp[19]; cube[45] = tmp[20];
}

void F() {
    vector<char> tmp(21);
    tmp[0] = cube[7]; tmp[1] = cube[8]; tmp[2] = cube[9];
    tmp[3] = cube[27]; tmp[4] = cube[10]; tmp[5] = cube[11]; tmp[6] = cube[12]; tmp[7] = cube[43];
    tmp[8] = cube[26]; tmp[9] = cube[13]; tmp[10] = cube[14]; tmp[11] = cube[15]; tmp[12] = cube[44];
    tmp[13] = cube[25]; tmp[14] = cube[16]; tmp[15] = cube[17]; tmp[16] = cube[18]; tmp[17] = cube[45];
    tmp[18] = cube[54]; tmp[19] = cube[53]; tmp[20] = cube[52];

    cube[43] = tmp[0]; cube[44] = tmp[1]; cube[45] = tmp[2];
    cube[9] = tmp[3]; cube[12] = tmp[4]; cube[15] = tmp[5]; cube[18] = tmp[6]; cube[52] = tmp[7];
    cube[8] = tmp[8]; cube[11] = tmp[9]; cube[17] = tmp[11]; cube[53] = tmp[12];
    cube[7] = tmp[13]; cube[10] = tmp[14]; cube[13] = tmp[15]; cube[16] = tmp[16]; cube[54] = tmp[17];
    cube[27] = tmp[18]; cube[26] = tmp[19]; cube[25] = tmp[20];
}

void B() {
    vector<char> tmp(21);
    tmp[0] = cube[48]; tmp[1] = cube[47]; tmp[2] = cube[46];
    tmp[3] = cube[19]; tmp[4] = cube[28]; tmp[5] = cube[29]; tmp[6] = cube[30]; tmp[7] = cube[39];
    tmp[8] = cube[20]; tmp[9] = cube[31]; tmp[10] = cube[32]; tmp[11] = cube[33]; tmp[12] = cube[38];
    tmp[13] = cube[21]; tmp[14] = cube[34]; tmp[15] = cube[35]; tmp[16] = cube[36]; tmp[17] = cube[37];
    tmp[18] = cube[1]; tmp[19] = cube[2]; tmp[20] = cube[3];

    cube[39] = tmp[0]; cube[38] = tmp[1]; cube[37] = tmp[2];
    cube[46] = tmp[3]; cube[30] = tmp[4]; cube[33] = tmp[5]; cube[36] = tmp[6]; cube[3] = tmp[7];
    cube[47] = tmp[8]; cube[29] = tmp[9]; cube[35] = tmp[11]; cube[2] = tmp[12];
    cube[48] = tmp[13]; cube[28] = tmp[14]; cube[31] = tmp[15]; cube[34] = tmp[16]; cube[1] = tmp[17];
    cube[19] = tmp[18]; cube[20] = tmp[19]; cube[21] = tmp[20];
}

void L() {
    vector<char> tmp(21);
    tmp[0] = cube[28]; tmp[1] = cube[31]; tmp[2] = cube[34];
    tmp[3] = cube[48]; tmp[4] = cube[19]; tmp[5] = cube[20]; tmp[6] = cube[21]; tmp[7] = cube[1];
    tmp[8] = cube[51]; tmp[9] = cube[22]; tmp[10] = cube[23]; tmp[11] = cube[24]; tmp[12] = cube[4];
    tmp[13] = cube[54]; tmp[14] = cube[25]; tmp[15] = cube[26]; tmp[16] = cube[27]; tmp[17] = cube[7];
    tmp[18] = cube[16]; tmp[19] = cube[13]; tmp[20] = cube[10];

    cube[1] = tmp[0]; cube[4] = tmp[1]; cube[7] = tmp[2];
    cube[34] = tmp[3]; cube[21] = tmp[4]; cube[24] = tmp[5]; cube[27] = tmp[6]; cube[10] = tmp[7];
    cube[31] = tmp[8]; cube[20] = tmp[9]; cube[26] = tmp[11]; cube[13] = tmp[12];
    cube[28] = tmp[13]; cube[19] = tmp[14]; cube[22] = tmp[15]; cube[25] = tmp[16]; cube[16] = tmp[17];
    cube[48] = tmp[18]; cube[51] = tmp[19]; cube[54] = tmp[20];
}

void R() {
    vector<char> tmp(21);
    tmp[0] = cube[36]; tmp[1] = cube[33]; tmp[2] = cube[30];
    tmp[3] = cube[3]; tmp[4] = cube[37]; tmp[5] = cube[38]; tmp[6] = cube[39]; tmp[7] = cube[46];
    tmp[8] = cube[6]; tmp[9] = cube[40]; tmp[10] = cube[41]; tmp[11] = cube[42]; tmp[12] = cube[49];
    tmp[13] = cube[9]; tmp[14] = cube[43]; tmp[15] = cube[44]; tmp[16] = cube[45]; tmp[17] = cube[52];
    tmp[18] = cube[12]; tmp[19] = cube[15]; tmp[20] = cube[18];

    cube[46] = tmp[0]; cube[49] = tmp[1]; cube[52] = tmp[2];
    cube[30] = tmp[3]; cube[39] = tmp[4]; cube[42] = tmp[5]; cube[45] = tmp[6]; cube[18] = tmp[7];
    cube[33] = tmp[8]; cube[38] = tmp[9]; cube[44] = tmp[11]; cube[15] = tmp[12];
    cube[36] = tmp[13]; cube[37] = tmp[14]; cube[40] = tmp[15]; cube[43] = tmp[16]; cube[12] = tmp[17];
    cube[3] = tmp[18]; cube[6] = tmp[19]; cube[9] = tmp[20];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tc;
    for(int i = 0; i < tc; i++) {
        color();
        int n;
        cin >> n;
        for(int j = 0; j < n; j++) {
            string str;
            cin >> str;
            char dir = str[0], clock = str[1];
            int cnt = (clock == '-') ? 3 : 1;
            for(int k = 0; k < cnt; k++) {
                switch(dir) {
                    case 'U': U(); break;
                    case 'D': D(); break;
                    case 'F': F(); break;
                    case 'B': B(); break;
                    case 'L': L(); break;
                    case 'R': R(); break;
                }
            }
        }
        for(int j = 1; j <= 9; j++){
            cout << cube[j];
            if(j%3 == 0) cout << '\n';
        }
    }
    return 0;
}