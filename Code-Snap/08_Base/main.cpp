#include <iostream>
#include <vector>

using namespace std;
class Msg {
public:
    Msg(int i){cout << i <<endl;};
};
int main()
{
    cout << "Hello, World!" << endl;
    vector<Msg> v;
    v.emplace_back(1);
    return 0;
}