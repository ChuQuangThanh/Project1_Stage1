//C++
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 0)
        if(b == 0)
            cout << "NO SOLUTION";
        else printf("%.2lf",-(c*1.0)/b);
            else{
                double delta = b*b - 4.0*a*c;
                if(delta == 0)
                {
                    printf("%.2lf",-(b*1.0)/(2 *a));
                }
                else if(delta < 0)
                cout << "NO SOLUTION";
                else
                {
                    printf("%.2lf %.2lf",(-b-sqrt(delta))/(2*a),(-b+sqrt(delta))/(2*a));
                }
            }
    return 0;
}
