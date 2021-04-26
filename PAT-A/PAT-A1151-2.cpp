// #include <cbits>
#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct node{                //block maximum & minimum
    int Min=INT_MAX,Max=INT_MIN;
};
int read(){                 //fast read-in
    int input=0, flag=1;
    char c=getchar();
    while((c<'0' || c>'9') && c!='-')
        c=getchar();
    if(c=='-'){             //if below zero
        flag=0;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        input=input*10 + c - '0';
        c=getchar();
    }
    return flag? input : ~input+1;
}
int read2(){                 //fast read-in
    int input;
    scanf("%d", &input);
    return input > 0 ? input : ~(-input)+1;
}
int main(){
    int n,m,tmp, blockid, x, y, a;
    cin >> m >> n;
    unordered_map<int,int> encrypt,decrypt;
    for(int i=1;i<=n;i++){
        tmp=read();
        encrypt[tmp]=i;         //encrypt procedure
        decrypt[i]=tmp;         //decrypt procedure
    }
    int blocksize = ceil( sqrt(n) );
    int blockcnt = n%blocksize? n/blocksize+1 : n/blocksize;
    vector<node> block(blockcnt);
    vector<int> pre(n);
    for(int i=0;i<n;i++){
        tmp=encrypt[read()];
        pre[i]=tmp;                                         //encrypt the pre-sequence
        blockid=i/blocksize;
        block[blockid].Max=max(block[blockid].Max,tmp);     //construction of block matrix
        block[blockid].Min=min(block[blockid].Min,tmp);
    }
    while(m--){
        x=read(), y=read();
        if(!encrypt[x] && !encrypt[y])                      //if both not in the tree
            printf("ERROR: %d and %d are not found.\n",x,y);
        else if(!encrypt[x] || !encrypt[y])                 //if one node is not in the tree
            printf("ERROR: %d is not found.\n",!encrypt[x]?x:y);
        else{
            x=encrypt[x], y=encrypt[y];                     //acquire the encrypted value of the two node
            int larger=max(x,y), smaller=min(x,y);
            bool found=false;
            for(blockid=0; !found ;blockid++){              //if not found, traverse all blocks
                if(block[blockid].Max < smaller || block[blockid].Min>larger)
                    continue;
                for(int i=blockid*blocksize;i<(blockid+1)*blocksize;++i){   //for a potential block, traverse all elements within the block
                    if(smaller<=pre[i] && pre[i]<=larger){
                        a=pre[i];
                        found=true;
                        break;
                    }
                }
            }
            if(a==x || a==y)
                printf("%d is an ancestor of %d.\n",a==x?decrypt[x]:decrypt[y],a==x?decrypt[y]:decrypt[x]); //decrypt & output result
            else
                printf("LCA of %d and %d is %d.\n",decrypt[x],decrypt[y],decrypt[a]);
        }
    }
    return 0;
}
// https://blog.csdn.net/wsxyh1071652438/article/details/82560853
