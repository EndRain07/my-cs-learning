#include <iostream>
using namespace std;

class Seq{
private:
    int a[5];
public:
    int geta(int i){
        return a[i];
    }
    void setData(){
        for(int i=0;i<5;i++) cin>>a[i];
    }
    //等差
    bool isA(){
        int d=a[1]-a[0];
        return a[2]-a[1]==d && a[3]-a[2]==d && a[4]-a[3]==d;
    }
    //等比
    bool isB(){
        if(a[0]==0) return false;
        int q=a[1]/a[0];
        return a[1]*q==a[2] && a[2]*q==a[3] && a[3]*q==a[4];
    }
    void out(){
        int cur=a[4];
        if(isA()){
            int d=a[1]-a[0];
            for(int i=0;i<5;i++){cur+=d;cout<<cur<<(i==4?"\n":" ");}
        }else if(isB()){
            int q=a[1]/a[0];
            for(int i=0;i<5;i++){cur*=q;cout<<cur<<(i==4?"\n":" ");}
        }else{//斐波
            int x=a[3],y=a[4],t;
            for(int i=0;i<5;i++){
                t=x+y;cout<<t<<(i==4?"\n":" ");
                x=y;y=t;
            }
        }
    }
};

int main(){
    Seq s;
    while(1){
        s.setData();
        if(s.geta(0)==0&&s.geta(1)==0&&s.geta(2)==0&&s.geta(3)==0&&s.geta(4)==0) break;
        s.out();
    }
    return 0;
}