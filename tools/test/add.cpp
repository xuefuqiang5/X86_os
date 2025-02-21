#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> a(10);
    for(int i = 0; i < 10; i++){
        a.push_back(i);
    }
    for(auto i:a ){
        cout<< i<<endl;
    }
    cout <<"hello, world !" << endl;
    return 0;
}
