#include <iostream>
#include <cmath>

using namespace::std;

int main(void)
{
    double r, c, n;

    cin >> r >> c >> n;

    cout << (long long) ceil(r/n) * (long long) ceil(c/n);
}
