#include<iostream>
using namespace std;

class heaptree{
    public:
    int totalkeys;
    int heap[10];

    void insert(){
        
        cout<<"Enter total number of keys: ";
        cin>>totalkeys;

        
        for(int loc=0;loc<totalkeys;loc++){
            cout<<"Enter key: ";
            cin>>heap[loc];
           
            built(loc);
        }
    }

    void built(int loc){
        //update the parent location
        int parent = floor((loc - 1) / 2);
        while (loc > 0 && heap[parent] > heap[loc]){   
            swap(heap[parent], heap[loc]);   
            loc = parent;       
            parent = (loc - 1) / 2;
        }
    }

    void display(){
        if (totalkeys > 0) {   
            cout<<"Heap Tree: ";              
            for(int loc=0;loc<totalkeys;loc++){      
                cout<<heap[loc]<<" ";            
            }
            cout<<endl;
        } else {           
            cout<<"Heap is empty!\n";
        }
    }
}heapObject;         

int main(){
    int choice;
    do{
        cout<<"1. Accept Data \t 2. Display Heap \t 0. Exit Program\n";
        cout<<"Enter the Choice: ";
        cin>>choice;
        switch(choice){
            case 1: heapObject.insert(); break;
            case 2: heapObject.display(); break;
            case 0: cout<<"Exiting program...\n"; break;
            default: cout<<"Invalid choice! Please try again.\n"; break;
        }
    }while(choice != 0);
    return 0;
}