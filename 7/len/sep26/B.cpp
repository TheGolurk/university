#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;

    int sum = a+b;
    int res = a-b;
    int div = a/b;
    int mul = a*b;

    string finalRes = "D:";

    if (sum == c){
        finalRes = "+";
    }
    if (res == c){
        finalRes = "-";
    }
    if (div == c) {
        finalRes = "/";
    }
    if (mul == c){
        finalRes = "*";
    }

    cout << finalRes;
    return 0;
}