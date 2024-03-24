#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

struct User {
    string name;
    vector<int> following;
};
vector<string> findFollowers(const vector<User>& users, int userId) {
    vector<string> seguidores;
    for (const User& usuario : users) {
        for (int seguido : usuario.following) {
            if (seguido == userId) {
                seguidores.push_back(usuario.name);
                break;
            }
        }
    }
    return seguidores;
}
int main() {
    int N;
    cin >> N;
    vector<User> users(N);
    cin.ignore();

    for (int i = 0; i < N; ++i) {
        getline(cin, users[i].name);
    }

    for (int i = 0; i < N; ++i) {
        int followedId;
        while (true) {
            cin >> followedId;
            if (followedId == -1) {
                break;
            }
            users[i].following.push_back(followedId);
        }
    }


    int userId;
    cin >> userId;
    vector<string> followers = findFollowers(users, userId);
    for(int i=0;i<followers.size();i++){
        cout << followers[i] << endl;
    }

    return 0;
}
