#include<cstring>
#include<cstdio>
int l[1000002];
char vis[1000002];
inline int read(){
    int sum=0;
    char c=getchar();
    while(c>='0'&&c<='9'){
        sum=sum*10+(c^48);
        c=getchar();
    }
    return sum;
}
int main(){
    int T,cnt,num,n;
    char c;
    long long ans;
    T=read();
    while(T--){
    memset(l,0,sizeof(l));
    memset(vis,0,sizeof(vis));   
    cnt=0,num=0;
    n=read();
    ans=0;
    c=getchar();
    while(c=='*'||c=='.'){
        num++;
        if(c=='*'){
            cnt++;
            l[num]=l[num-1]+1;
        }else{
            vis[num]=1;
            l[num]=l[num-1];
        }
        c=getchar();
    }
    int i=1;
    for(;i<=n&&l[i]<=cnt/2;++i){
        if(vis[i]){
            ans+=l[i];
        }
    }
    for(;i<=n;++i){
        if(vis[i]){
            ans+=cnt-l[i];
        }
    }
    printf("%lld\n",ans);
    }
    return 0;
}
