#include <iostream>

using namespace std;

int main()
{
    int n;
   
    cin >> n;
    int a[101][101];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int res1 = 0;
    int res2 = 0;
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (h != 0) {
            if (h % 2 == 0) {
                res1++;
            }
            else {

                res2++;

            }

        }
        h = 0;
        for (int j = 0; j < n; j++) {
            if(a[i][j] == 1){
               h++;
            }
            if(i == j && a[i][j] == 1){
               h++;
            }

        }
    }
    if (h != 0) {
        if (h % 2 == 0) {
            res1++;
        }
        else {
            res2++;
        }
    }


    cout << res1 << " " << res2;
    return 0;

}