#include <iostream>
using namespace std;
long long lan[10001];
int K,N;

bool ispossible(long long len){
    int count=0;
    for(int i=0; i<K;i++){
        count+=lan[i]/len;
    }
    if (count>=N)
        return true;
    else
        return false;
}

int main(void){
    cin>>K>>N;
	long long mid;
    long long high=0;
    for(int i=0; i<K; i++) {
        cin >> lan[i];
        high=max(high,lan[i]);
    }
    long long result=0;
    long long low=1;
    while(low<=high){
        mid = (low+high)/2;

		// cout<<"low : "<<low<<"\n";
    	// cout<<"mid : "<<mid<<"\n";
    	// cout<<"high : "<<high<<"\n";
		// cout<<"result : "<<result<<"\n\n";

        if(ispossible(mid)){
            result=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }

    }
    // cout<<"----- result : "<<result;
    cout<<result;


}