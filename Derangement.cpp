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

int n;
int qpow(int x,int a){
	if(a==0) return 1;
	int p=qpow(x,a>>1);
	return (a&1?p*p%mod*x%mod:p*p%mod);
}
int inv(int x){
	return qpow(x,mod-2);
}
int fac[10000005]; 
void solve1(){
	fac[0]=1;
	int ans=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod,ans+=(i&1?-inv(fac[i]):inv(fac[i])),ans+=mod,ans%=mod;
	printf("If there are %lld envelopes, the answer modula 998244353 should be: %lld.\n",n,fac[n]*ans%mod);
}
int D[10000005];
void solve2(){
	D[0]=1,D[1]=0;
	for(int i=2;i<=n;i++)D[i]=(D[i-1]+D[i-2])*(i-1)%mod;
	printf("If there are %lld envelopes, the answer modula 998244353 should be: %lld.\n",n,D[n]);
}
int d[10000005];
void solve3(){
	d[0]=1;
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]*i%mod+(i&1?mod-1:1);
		d[i]%=mod;
	}
	printf("If there are %lld envelopes, the answer modula 998244353 should be: %lld.\n",n,d[n]);
}
signed main(){
	n=Read(); 
	solve1();
	solve2();
	solve3(); 
	return 0;
}
