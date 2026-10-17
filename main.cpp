#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<ll> all(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>all[i];
    }

    sort(all.begin(),all.end());

    //n个数相加是否满足要求
    //前i个数累加和
    vector<ll> prve(n+1,0);
    for(int i=0;i<n;i++)
    {
        prve[i+1]=prve[i]+all[i];
    }
    auto check=[&](int len)->bool{
        int right=0;
        for(int l=0;l<n-len+1;l++)
        {
            int r=l+len-1;
            int middle=(l+r)/2;

            ll leftsum=all[middle]*(middle-l)-(prve[middle]-prve[l]);
            ll rightsum=(prve[r+1]-prve[middle+1])-all[middle]*(r-middle);

            ll sum=leftsum+rightsum;
            if(sum<=k)
            return true;
        }
        return false;
    };

    //二分差个数
    int left=1;
    int right=n;
    int ans=0;
    while(left<=right)
    {
        int mid=(left+right)/2;

        //小巧思：大的不行就只能小的了
        if(check(mid))
        {
            ans=mid;
            left=mid+1;
        }
        else{
        right=mid-1;
        }
    }

    cout<<ans<<endl;
    return 0;
}
