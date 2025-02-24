#include<bits/stdc++.h>
#define int long long
using namespace std;
int Read(){
	int x=0;
	char ch=getchar();
	bool f=0;
	while(ch<'0'||ch>'9') if(ch==EOF) return 0; else if(ch=='-') f=1,ch=getchar(); else ch=getchar();
	while(ch>='0'&&ch<='9') if(f) x=(x<<3)+(x<<1)-(ch^48),ch=getchar(); else x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
const int mod=998244353;
int d[1000005]; 
signed main(){
	int n=Read(); 
	d[0]=1;
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]*i%mod+(i&1?mod-1:1);
		d[i]%=mod;
		printf("If there are %lld envelopes, the answer modula 998244353 should be: %lld.\n",i,d[i]);
	}
	return 0;
}

