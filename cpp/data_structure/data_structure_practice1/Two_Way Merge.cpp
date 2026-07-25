#include<iostream>
#include<string>
#include<sstream> 
void merge_and_playout(int a[],int b[],int n){
    int i=0,j=0,r=0;
    int c[201]={};
    while(i<n&&j<n){
        if(a[i]<=b[j]){
            c[r++]=a[i++];
        }
        else{
            c[r++]=b[j++];
        }
    }
     while(i<n){
        c[r++]=a[i++];
    }

    while(j<n){
        c[r++]=b[j++];
    }  //二段式while：先结束同时比较，然后剩下的单独继续

    for(int z=0;z<r;z++){
        std::cout<<c[z]<<' ';
    }

}

void getdata(){
    int a[100]={};
    int b[100]={};
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    for(int i=0;i<n;i++){
        std::cin>>b[i];
    }

    merge_and_playout(a,b,n);
}



int main(){
    getdata();
}