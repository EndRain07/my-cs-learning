#include<iostream>

void Input(int n,int *Score){    

    int num,score;
    while(n--){ 
        std::cin>>num>>score;
        Score[num]=score;
        
    }return;
}

int get_number(int c,int *Score){
    return Score[c];
}
int main(){
    int n;
    int Score[10000000]={};
    std::cin>>n;
    //std::cout<<n;

    Input(n,Score);

    int c;
    std::cin>>c;
    std::cout<< get_number(c,Score);
}
