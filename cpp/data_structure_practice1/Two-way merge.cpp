#include<iostream>
#include<string>
#include<sstream> //比strstream更现代
void merge_and_playout(int a[],int b[],int numa,int numb){
    int i=0,j=0,r=0;
    int c[201]={};
    while(i<numa&&j<numb){
        if(a[i]<=b[j]){
            c[r++]=a[i++];
        }
        else{
            c[r++]=b[j++];
        }
    }
     while(i<numa){
        c[r++]=a[i++];
    }

    while(j<numb){
        c[r++]=b[j++];
    }  //二段式while：先结束同时比较，然后剩下的单独继续

    for(int z=0;z<r;z++){
        std::cout<<c[z]<<' ';
    }

}

void getdata(){
    int a[100]={};
    int b[100]={};
    int numa=0,numb=0;
    std::string A,B;

    getline(std::cin,A);
    getline(std::cin,B);

    std::stringstream ssA(A); //使用sstream-stringstream
    std::stringstream ssB(B);

    while(ssA>>a[numa]){
        numa++;
    }

    while(ssB>>b[numb]){
        numb++;
    }

    merge_and_playout(a,b,numa,numb);
}



int main(){
    getdata();
}