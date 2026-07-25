#include<iostream>
#include<vector>
#include<algorithm>

struct InsertData{
    int position;
    int data;
};

int main(){
    int n;
    std::cin>>n;

    std::vector<int> integer;

    for(int i=0;i<n;i++){
        int a;
        std::cin>>a;
        integer.push_back(a);
    }

    int k;
    std::cin>>k;

    std::vector<InsertData> insertData(k);

    for(int i=0;i<k;i++){
        std::cin>>insertData[i].position>>insertData[i].data;
    }

    std::sort(insertData.begin(),insertData.end(),[](InsertData a,InsertData b){
        return a.position<b.position;
    });

    for(int i=0;i<k;i++){
        
        integer.insert(integer.begin()+insertData[i].position-1+i,insertData[i].data);
        n++;
    }

    for(int i=0;i<n;i++){
          
        std::cout<<integer[i]<< ' ';
    }

    return 0;
}