#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cctype>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
//A1086 Tree Traversals Again

int n, in[50], pre[50];
stack <int> ss;
vector<int> post;
//满分做法
void postorder(int preL, int preR, int inL, int inR){
  if(preL > preR) return;
  int k = inL;
  while(k <= inR && pre[preL] != in[k]) k++;
  int leftnum = k - inL;
  postorder(preL + 1, preL + leftnum, inL, k - 1);
  postorder(preL + leftnum + 1, preR, k + 1, inR);
  post.push_back(pre[preL]);
}
int main() {
  scanf("%d", &n);
  char temp[5];
  int t;
  int i = 0, j = 0, cnt = 0;
  while(cnt++ < 2 * n){
    scanf("%s", temp);
    if(temp[1] == 'u'){
      scanf("%d", &t);
      pre[i++] = t;
      ss.push(t);
    }
    else{
      in[j++] = ss.top();
      ss.pop();
    }
  }
  postorder(0, n-1, 0, n - 1);
  for(int i = 0; i < n; i++){
    if(i != 0) printf(" ");
    printf("%d", post[i]);
  }
  return 0;
}

// //最后一个测试点没过
// int n, cnt = 0, i = 0, in[50], pre[50], value[50];
// stack <int> ss;
// string temp;
// void postorder(int root, int start, int end){
//   //有一个测试点过不了，应该是这里start和end的问题
//   if(start > end) return;
//   int k = start;
//   while(k < end && pre[root] != in[k]) k++;
//   postorder(root + 1, start, k - 1);
//   postorder(root + 1 + k - start, k + 1, end);
//   if(cnt != 0) printf(" ");
//   printf("%d", value[pre[root]]); cnt++;
// }
// int main() {
//   scanf("%d", &n);
//   getchar();
//   while(cnt < n){
//     getline(cin, temp);
//     int len = temp.length();
//     if(len > 4){
//       int k = (int)(temp[len-1] - '0');
//       pre[i] = i;
//       value[i] = k;
//       ss.push(i++);
//     }
//     else{
//       in[cnt++] = ss.top();
//       ss.pop();
//     }
//   }
//   cnt = 0;
//   postorder(0, 0, n - 1);
//   return 0;
// }

//another solution
// 采用二叉树的数组表示方法，用stack保存一下当前节点编号，
// 每push一下都将当前节点编号*2转向左子树，
// pop的时候就pop出来转向右子树。
// #include <stdio.h>
// #include <algorithm>
// #include <stack>
// #include <string.h>
// using namespace std;
// int n,k,current=1;
// int Tree[10000];
// int flag=0;
// char op[2][10]={"Push","Pop"};
// stack<int>s;
// void postorder(int root){
//     if (Tree[root*2]!=-1) postorder(root*2);
//     if (Tree[root*2+1]!=-1) postorder(root*2+1);
//     if (flag==0){
//         flag=1;
//         printf("%d",Tree[root]);
//     }
//     else
//         printf(" %d",Tree[root]);
// }
// int main(){
//     //freopen("/Users/pantingting/Documents/code/data/input", "r", stdin);
//     memset(Tree, 0xff, sizeof(Tree));
//     scanf("%d",&n);
//     char tempop[10];
//     for (int i=0; i<2*n; i++) {
//         scanf("%s",tempop);
//         if (strcmp(tempop, op[0])==0) {
//             scanf("%d",&k);
//             Tree[current]=k;
//             s.push(current);
//             current*=2;
//             continue;
//         }
//         if (strcmp(tempop, op[1])==0) {
//             int temp=s.top();
//             s.pop();
//             current=temp*2+1;
//         }
//     }
//     postorder(1);
//     printf("\n");
//     return  0;
// }


//传统做法，建立一棵树
// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <string>
// #include <cctype>
// #include <stack>
// #include <algorithm>
// using namespace std;
// //A1086 Tree Traversals Again
// int n, cnt = 0, i = 0, pre[50], in[50];
// stack <int> ss;
// string temp;
// struct node{
//   int data;
//   node* lchild;
//   node* rchild;
// };
// void postorder(node* root){
//   if(root == NULL) return;
//   postorder(root->lchild);
//   postorder(root->rchild);
//   if(cnt != 0) printf(" ");
//   printf("%d", root->data); cnt++;
// }
// node* create(int preL, int preR, int inL, int inR){
//   if(preL > preR) return NULL;
//   node* root = new node;
//   root->data = pre[preL];
//   int k = inL;
//   while(k <= inR && in[k] != pre[preL]) k++;
//   int numleft = k - inL;
//   root->lchild = create(preL + 1, preL + numleft, inL, k - 1);
//   root->rchild = create(preL + numleft + 1, preR, k + 1, inR);
//   return root;
// }
// int main() {
//   scanf("%d", &n);
//   getchar();
//   while(cnt < n){
//     getline(cin, temp);
//     int len = temp.length();
//     if(len > 4){
//       int k = (int)(temp[len-1] - '0');
//       pre[i++] = k;
//       ss.push(k);
//     }
//     else{
//       in[cnt++] = ss.top();
//       ss.pop();
//     }
//   }
//   node* root = create(0, n-1, n-1, 0);
//   cnt = 0;
//   postorder(root);
//   return 0;
// }
//
