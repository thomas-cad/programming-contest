#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> signature(vector<int> notes) {
    sort(notes.begin(), notes.end());

    vector<int> ecarts;
    int precedente = notes[0];      
    bool premiere = true;

    for (int note : notes) {
        if (premiere) {                
            premiere = false;
        } else {
            ecarts.push_back(note - precedente);
        }
        precedente = note;             
    }

    return ecarts;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<int> song(N);
    for (int i = 0; i < N; i++) scanf("%d", &song[i]);

    int C;
    scanf("%d", &C);
    vector<int> chord(C);
    for (int i = 0; i < C; i++) scanf("%d", &chord[i]);

    vector<int> target = signature(chord);

    vector<int> answers;
    for (int i = 0; i + C - 1 < N; i++) {
        vector<int> window(song.begin() + i, song.begin() + i + C);
        if (signature(window) == target)
            answers.push_back(i + 1); // indices à partir de 1
    }

    printf("%d\n", (int)answers.size());
    for (int idx : answers) printf("%d\n", idx);
    return 0;
}