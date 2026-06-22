#include <iostream>
#include <sstream>
#include <string>
#include <climits>  //使用INT_MIN

class linkedlist{
    private:
    int OutNumber;
    int Maxsize_;
    struct Node{
    int value;
    Node* next;
    Node (int va) : value(va),next(nullptr) {}
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    std::size_t size_=0;

    
    public:
    linkedlist() {};

    ~linkedlist(){
        clear();
    };

    void set_data(int n,int m){
        Maxsize_=n;
        OutNumber=m;
    }

    void push_back(int value){
        Node* new_node = new Node(value);
        if(size_==0){
            tail_=new_node;
            head_=new_node;
        }
        else{
            tail_->next=new_node;
            tail_=new_node;
        }
        size_++;  //要在结点建造完成后再更新size_
        if(size_==Maxsize_){
            tail_->next=head_;
        }
    }

    void Gaming(){
        int tmp=0;
        Node* Prom_=tail_;
        while(size_>1){
            tmp++;
            if(tmp==OutNumber){             
                size_--;
                Node* old_node = Prom_->next;
                if(old_node==head_){
                    head_ = old_node->next; //!!很重要，因为后续clear需要头节点，如果头没了，需要更新 
                }
                Prom_->next=old_node->next;
                delete old_node;
                tmp=0;
            }
            else{
                Prom_=Prom_->next;
            }
            
        }
        std::cout<<Prom_->value;
        size_--;
        delete Prom_;
    }

    void clear(){
     
    }
};



int main(){
   
    int n,m;
    std::cin>>n>>m;
    linkedlist list;
    list.set_data(n,m);
    for(int i=1;i<=n;i++){
        list.push_back(i);
    }
    list.Gaming();

}