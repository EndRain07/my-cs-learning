#include <iostream>
using namespace std;

class Matrix {
private:
    int arr[9][9]; // N最大9，存矩阵
public:
    void create(int n) {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                arr[i][j]=(i+1)*(j+1);
    }
    void print(int n) {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j];
                if(j<n-1) cout<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Matrix m;
    int C,n;
    cin>>C;
    while(C--){
        cin>>n;
        m.create(n);
        m.print(n);
    }
    return 0;
}