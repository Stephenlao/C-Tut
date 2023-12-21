#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::string;


class Facebooker {
    private:
        string name;
        vector<Facebooker*> friends;
    public:
        Facebooker(string name_val = "", vector<Facebooker*> friends_val = {})
        : name(name_val) , friends(friends_val) {};

        void addFriend(Facebooker &aFriend) {
            if (!friends.empty()) {
                for (int i= 0 ; i < friends.size(); i++) {
                    if (friends[i]->name == aFriend.name) {
                        cout << friends[i]->name << "is already a friend of " << this->name << "\n";
                        return;
                    } 
                }
            }
            friends.push_back(&aFriend);
            aFriend.friends.push_back(this);
        }

        void viewFriends() {
            cout << "All friends of " << this->name << "\n";
            for (Facebooker* afriend : friends) {
                cout << afriend->name << " ";
            }
        }

        void viewFriendOfFriend() {
            cout << "Friend of friends: " << this->name << "\n";
            for (Facebooker* aFriend : friends) {
                for (Facebooker* aFriend1 : aFriend->friends) {
                    if (aFriend1 != this) {
                        cout << aFriend1->name << "  ";
                    }
                }
            }
            cout << "\n";
        }


        void viewMutualFriend(Facebooker &aFriend) {
            cout << "Mutual friend of " << this->name <<  " and " << aFriend.name << "\n";
            for (Facebooker* myFriend : friends) {
                for (Facebooker* hisfriend : aFriend.friends) {
                    if (myFriend == hisfriend) {
                        cout << myFriend->name << "  ";
                    }
                }
            }
        }
};

int main() {
    Facebooker Stephen("StephenLao"), Khanh("Khanhle"), Vivi("VivienDoan"), Amber("Amber"), Giang("Giang"), Nhu("Nhu");

    Stephen.addFriend(Khanh);
    Stephen.addFriend(Vivi);

    Vivi.addFriend(Khanh);
    Vivi.addFriend(Amber);
    Vivi.addFriend(Giang);
    Vivi.addFriend(Nhu);
    
    Stephen.viewFriendOfFriend();
    Stephen.viewMutualFriend(Vivi);

}