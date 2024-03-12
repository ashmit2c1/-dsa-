// ARRAYS 
#include<bits/stdc++.h>
using namespace std;

//==================================//
//==FIND THE LAST OCCURENCE OF AN ELEMENT=//
//==================================//
int findLastOccurence(vector<int> &v,int x){
    int n = v.size();
    int occ=0;
    for(int i = 0; i<n ; i++){
        if(v[i]==x){
            occ=i;
        }
    }
    return occ;
}

int findLastOccurenceBetter(vector<int> &v, int x){
    int n = v.size();
    int occ=0;
    for(int i = n-1; i>=0 ; i--){
        if(v[i]==x){
            occ=i;
            break;
        }
    }
    return occ;
}

//==================================//
//=FIND THE COUNT OF PAIRS WHOSE SUM IS EQUAL TO GIVEN VALUE=//
//==================================//
int findPairs(vector<int>&v, int x){
    int n = v.size();
    int count=0;
    for(int i = 0; i<n ; i++){
        for(int j = i+1;j<n;j++){
            if((v[i]+v[j])==x){
                count++;
            }
        }
    }
    return count;
}

int findTriplets(vector<int> &v, int x){
    int n = v.size();
    int count=0;
    for(int i = 0; i<n ; i++){
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                if((v[i]+v[j]+v[k])==x){
                    count++;
                }
            }
        }
    }
    return count;
}
//==================================//
//=AN ARRAY HAS PAIR OF DUPLICATE ELEMENT EXCEPT ONE, FIND THE UNIQUE ELEMENT=//
//==================================//
int findUniqueElement(vector<int>&v){
    int n = v.size();
    for(int i = 0; i<n ; i++){
        for(int j=i+1;j<n;j++){
            if(v[i]==v[j]){
                v[i]=-1;
                v[j]=-1;
            }
        }
    }
    int el = 0;
    for(int i = 0; i<n ; i++){
        if(v[i]>=0){
            el = v[i];
        }
    }
    return el;
}
//==================================//
//=FIND THE SECOND LARGEST ELEMENT IN THE ARRAY=//
//==================================//
void secondLargest(vector<int>&v){
    int n = v.size();
    int max=INT_MIN;
    int maxIndex=0;
    for(int i = 0; i<n ; i++){
        if(v[i]>max){
            max=v[i];
            maxIndex=i;
        }
    }
    v[maxIndex]=-1;
    int max2=INT_MIN;
    for(int i = 0; i<n ; i++){
        if(v[i]>max2){
            max2=v[i];
        }
    }
    cout << max2 << "\n";
}
//==================================//
//ROTATE THE ARRAY BY K//
//==================================//
void rotateArrayByK(vector<int>&v,int k){
    int n = v.size();
    int j=0;
    int temp[n];
    for(int i = n-k; i<n ; i++){
        temp[j]=v[i];
        j++;
    }
    for(int i = 0; i<=k ; i++){
        temp[j]=v[i];
        j++;
    }
    for(int i = 0; i<n ; i++){
        cout << temp[i] << " ";
    }
}
//==================================//
//=SORT AN ARRAY OF 0 AND 1 WITHOUT USING ANY SORTING ALGORITHM=//
//==================================//
void sortCountApproach(vector<int>&v){
    int count=0;
    int n = v.size();
    for(int i = 0; i<n ; i++){
        if(v[i]==0){
            count++;
        }
    }
    vector<int>w;
    for(int i = 0; i<n ; i++){
        if(i<count){
            w.push_back(0);
        }
        else{
            w.push_back(1);
        }
    }
    for(int i = 0; i<n ; i++){
        cout << w[i] << " ";
    }
}

void sortTwoPointerApproach(vector<int>&v){
    int n = v.size();
    int right=n-1;
    int left = 0;
    while(left<right){
        if(v[left]==1 && v[right]==0){
            swap(v[left],v[right]);
            left++;
            right--;
        }
        if(v[left]==0){
            left++;
        }
        if(v[right]==1){
            right--;
        }
    }
    for(int i = 0; i<n ; i++){
        cout << v[i] << " ";
    }
}
//==================================//
// SORT AN ARRAY WITH EVEN INTEGERS IN FRONT AND ODD INTEGERS AT THE BACK//
//==================================//
void sortEvenOdd(vector<int>&v){
    int n = v.size();
    int right=n-1;
    int left=0;
    while(left<right){
        if(v[left]%2!=0 && v[right]%2==0){
            swap(v[left],v[right]);
            left++;
            right--;
        }
        if(v[left]%2==0){
            left++;
        }
        if(v[right]%2!=0){
            right--;
        }
    }
}
//==================================//
//=GIVEN AN ARRAY OF INTEGERS, RETURN THE SORTED ARRAY OF SQUARES OF INTEGERS=//
//==================================//
vector<int> returnSortedSquare(vector<int>&v){
    vector<int>ans;
    int n = v.size();
    int right = n-1;
    int left = 0;
    int index=n-1;
    while(left<right){
        if(abs(v[left])<abs(v[right])){
            ans[index]=v[right]*v[right];
            right--;
            index--;
        }
        else{
            ans[index]=v[left]*v[left];
            left++;
            index--;
        }
    }
    return ans;
}
//==================================//
//=RETURN THE PREFIX SUM OF THE ARRAY IN THE SAME ARRAY=//
//==================================//
vector<int> prefixSum(vector<int>&v){
    int n = v.size();
    for(int i = 1 ; i < n ; i++){
        v[i]=v[i]+v[i-1];
    }
    return v;
}
//==================================//
//GIVEN AN INTEGER ARRAY, CHECK IF WE CAN PARTITION THE ARRAY IN TWO EQUAL HALVES//
//==================================//
bool checkForEqualParition(vector<int>&v){
    int n = v.size();
    int sum=0;
    int prefixSum=0;
    int suffixSum=0;
    for(int i = 0; i<n ; i++){
        sum = sum + v[i];
    }
    for(int i = 0; i<n ; i++){
        prefixSum=prefixSum+v[i];
        suffixSum = sum-prefixSum;
        if(prefixSum==suffixSum){
            return true;
        }
    }
    return false;
}
//==================================//
//FIND THE LONGEST SEQUENCE OF ONES IN A GIVEN ARRAY OF 0 AND 1//
//==================================//
int longestSequenceOfone(vector<int>&v){
    int one_count=0;
    int one_streak=0;
    int n = v.size();
    for(int i = 0; i<n ; i++){
        if(v[i]==1){
            one_count++;
            one_streak=max(one_count,one_streak);
        }
        else{
            one_count=0;
        }
    }
    return one_streak;
}
//==================================//
//FIND THE SUM OF THE LARGEST AND SECOND LARGEST IN ARRAY, THE ARRAY CAN HAVE DUPLICATES AS WELL//
//==================================//
int largestSecondLargest(vector<int>&v){
    int n = v.size();
    int max1=INT_MIN;
    int max2=INT_MIN;
    for(int i = 0; i<n ; i++){
        if(v[i]>max1){
            max1=v[i];
        }
    }
    for(int i = 0; i<n ; i++){
        if(v[i]>max2 && v[i]!=max1){
            max2=v[i];
        }
    }
    return max1+max2;
}
//==================================//
//FIND THE SUB ARRAY WITH THE MAXSUM//
//==================================//
int maxSumSubArray(vector<int>&v,int k){
    int n = v.size();
    int sum=0;
    int maxSum=0;
    for(int i = 0; i<k ; i++){
        sum=sum+v[i];
    }
    maxSum=sum;
    for(int i =k;i<n;i++){
        sum=sum+v[i]-v[i-k];
        maxSum=max(maxSum,sum);
    }
    return maxSum;
}
//==================================//
//FIND THE INDEX OF THE SUB ARRAY WITH THE GIVEN SUM//
//==================================//
vector<int> findIndex(vector<int>&v,int s){
    int n = v.size();
    int sum = 0;
    int start = 0;
    int end = 0;
    vector<int> ans;
    for(int i = 0; i<n ; i++){
        sum=sum+v[i];
        if(sum>=s){
            end=i;
            while(sum>s && end>start){
                sum=sum-v[start];
                start++;
            }
        }
        if(sum==s){
            ans.push_back(start+1);
            ans.push_back(end+1);
            return ans;
        }
    }
    ans.push_back(-1);
    return ans;
}
//==================================//
//FIND THE MINIMUM NUMBER OF OPERATIONS REQUIRED TO MAKE ALL THE ELEMENTS IN ARRAY EQUAL//
//==================================//
int minOps(vector<int>&v){
    int n = v.size();
    int occ=0;
    int maxOcc=0;
    sort(v.begin(),v.end());
    for(int i = 0; i<n ; i++){
        if(v[i]==v[i+1]){
            occ++;
            maxOcc=max(maxOcc,occ);
        }
        else{
            occ=1;
        }
    }
    int minOps=n-maxOcc;
    return minOps;
}
//==================================//
//FIND THE MAJORITY ELEMENT IN ARRAY//
//==================================//
int findMajElement(vector<int>&v){
    int n = v.size();
    int majEl = -1;
    int count=0;
    for(int i = 0; i<n ; i++){
        for(int j = 0;j<n;j++){
            if(v[i]==v[j]){
                count++;
            }
            if(count>n/2){
                majEl=v[i];
            }
        }
    }
    return majEl;
}
int main(){
    
}