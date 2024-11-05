#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int low,int high,int& swaps,int& compars){
    int i=low;
    int j=high;
    int pivot = arr[low];
    
    while(i<j){

        do{
            i++;
            compars++;
        } while(i<high && arr[i]<=pivot);
        do{
            j--;
            compars++;
        } while(j>=low && arr[j]>pivot);

        if(i<j){
            swap(arr[i],arr[j]);
            swaps++;
        }
    }
    swap(arr[low],arr[j]);
    swaps++;
    return j;
}

void quickSort(vector<int> &arr,int low,int high,int& deterministic_swaps,int& deterministic_comparisons){

    if(low<high){
        int parti = partition(arr,low,high,deterministic_swaps,deterministic_comparisons);
        quickSort(arr,low,parti,deterministic_swaps,deterministic_comparisons);
        quickSort(arr,parti+1,high,deterministic_swaps,deterministic_comparisons);
    }

    
}

void quickSortRandomized(vector<int> &arr,int low,int high,int& random_swaps,int& random_comparisons){

    if(low<high){
        int random = rand() % (high - low) + low;
        swap(arr[low],arr[random]);
        random_swaps++;
        int parti = partition(arr,low,high,random_swaps,random_comparisons);
        quickSortRandomized(arr,low,parti,random_swaps,random_comparisons);
        quickSortRandomized(arr,parti+1,high,random_swaps,random_comparisons);
    }

    
}
int main(){

    vector<int> arr;
    srand(time(0));
    cout<<"Please enter the number of array elements: ";
    int n;
    cin>>n;
    int deterministic_swaps =0;
    int deterministic_comparisons = 0;
    int random_swaps=0;
    int random_comparisons=0;

    cout<<"Please provide the list of elements: "<<endl;
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        arr.push_back(s);
    }

    int low=0;
    int high=n;

    quickSort(arr,low,high,deterministic_swaps,deterministic_comparisons);

    for(auto x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<deterministic_swaps<<" swaps required"<<endl;
    cout<<deterministic_comparisons<<" comparisons required"<<endl;


    
    
    

    
    return 0;
}