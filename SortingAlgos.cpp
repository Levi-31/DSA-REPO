 #include<bits/stdc++.h>
using namespace std;


void BubbleSort(vector<int>& nums){
      int n=nums.size();
        bool swapped=false;
        for(int i=0;i<n;i++){
            for(int j=1;j<n-i;j++){
                if(nums[j]<nums[j-1]){
                    swap(nums[j],nums[j-1]);
                    swapped=true;
                }
            }
            if(!swapped) break;
        }

}

void SelectionSort(vector<int>&nums){
    int n=nums.size();

    for(int i=0;i<n;i++){
        int last= n-i-1;
        int max_index = 0;
        for(int j=0;j<=last;j++){
            if(nums[max_index]<nums[j])max_index=j;
        }
        swap(nums[max_index],nums[last]);
    }

}

void InsertionSort(vector<int>&nums){
    int n=nums.size();

    for(int i=0;i<=n-2;i++){
        for(int j=i+1;j>0;j--){
            if(nums[j]<nums[j-1]){
                swap(nums[j],nums[j-1]);
            }
            else {
                  break;
            }
          
        }
    }
}
void Merge(vector<int>&nums, int low, int mid, int high){
    vector<int> temp;
    int left=low,right=mid+1;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left++]);
        }
        else{
            temp.push_back(nums[right++]);
        }
    }
    while(left<=mid){
        temp.push_back(nums[left++]);
    }
    while(right<=high){
        temp.push_back(nums[right++]);
    }
    for(int i=low;i<=high;i++){
        nums[i]=temp[i-low];
    }
}
void MergeSort(vector<int>&nums, int low, int high){
    if(low==high) return ;

    int mid= low+(high-low)/2;

    MergeSort(nums,low,mid);
    MergeSort(nums,mid+1,high);
    Merge(nums,low,mid,high);

}

void QuickSort(vector<int>& nums,int low, int high){
    if(low>=high) return;

    int s=low,e=high;
    int mid= s+(e-s)/2;
    int pivot= nums[mid];

    while(s<=e){
        while(nums[s]<pivot)s++;
        while(nums[e]>pivot)e--;

        if(s<=e){
            swap(nums[s],nums[e]);
            s++;e--;
        }
    }

    QuickSort(nums,low,e);
    QuickSort(nums,s,high);

}


int main(){

  return 0;
}
