## 从C到C++，常用函数、语法笔记

通用头文件
```
#include <bits/stdc++.h>
using namespace std;
```

### iostream
- `getline(cin, str);`
  - 输入一整行的字符串，包括空格等
  - 所需头文件： **iostream**

### cstdio
  - `sscanf(a, "%lf", &temp);`
    - 按照指定格式从字符串 a 中读取特定值
    - 所需头文件：**cstdio**
  - `sprintf(b, "%.2lf",temp);`
    - 按照指定格式将字符串输出到 b 中
    - 所需头文件：**cstdio**

### String
- `num = '0' + num; `
  - 字符串拼接
  - 需要的头文件：**string**
- `while(scanf("%d %d", &a, &b) != EOF){ }`
  - 可用于判断输入是否结束，自己测试运行时可用 `ctrl + z` 作为输入结束，程序可识别
- `stoi();`
  - 实现将字符串转换成对应字面的整数
  - 类似的函数还有：
    - `stod()` 将字符串转换为 double 型数
    - `stof()` 将字符串转换为 float 型数
  - 需要的头文件：**string**
- `to_string();`
  - 实现将一个数转换为字符串，这个数可以是整型或浮点型
  - 需要的头文件：**string**
- `ans.insert(<插入位置>, '<插入的字符>');`
  - 实现在字符串特定位置插入一个字符
  - 所需头文件： **string**
- `s.erase(s.begin(), s.begin() + 3);`
  - 删除字符串 [first, first + 3) 范围的部分
  - 所需头文件： **string**
- `s.erase(ans.begin());`
  - 删除字符串第一个字符
  - 所需头文件： **string**
- `s.empty()`
  - 判断一个字符串是否为空字符串
  - 所需头文件： **string**
- `s.substr(<截取部分的首地址>, <截取部分的长度>)`
  - 截取字符串的一部分生成新的字符串
  - 需要头文件 **string**

### cstring
  - `memset(s,0,sizeof(s));`
    - 将 s 所指向的某一块内存中的后一定范围内的内容全部设置为指定的 ASCII 值， `memset(<内存地址>, <指定的 ASCII 码>, <地址大小>);`
    - memset 函数按字节对内存块进行初始化，所以不能用它将 int 数组初始化为 0 和 -1 之外的其他值
    - 所需头文件：**cstring**
  - `char a[5];  memset(a, 97, 5 * sizeof(char));`
    - 可将字符数组 a 初始化为 `aaaaa`；

### cmath
  - **cmath** 中的取整函数
  - `y = ceil(x)`
    - 向下取整
  - `y = floor(x)`
    - 向上取整
  - `y = round(x)`
    - 四舍五入

### ctype
  - 该头文件包含一系列处理单个字符的函数:
  - `isalnum()`
    - 判断字符是否为字母或者数字
  - `isalpha()`
    - 判断字符是否为字母
  - `isblank()`
    - 判断字符是否为空格
  - `isdigit()`
    - 判断字符是否为数字
  - `islower()`
    - 判断字符是否为小写字母
  - `isupper()`
    - 判断字符是否为大写字母
  - `y = tolower(x)`
    - 将大写字母转换为小写字母
  - `y = toupper(x)`
    - 将小写字母转换为大写字母


### Vector
- `vector<int> ans;`
  - 实现变长数组，元素类型可任意指定
    - `ans.push_back(num[i])`往变长数组末尾中添加一个元素
    - `ans.pop_back()`删除变长数组中最后一个元素
  - 需要的头文件：**vector**
- `vector<int> path(p);`
  - 创建了一个指定长度为 p 的数组。
  - 所需头文件：**vector**
- `vector<int> id(n + 1, 1);`
  - 设置一个指定长度为 n + 1 且指定元素值为 1 的数组
  - 所需头文件：**vector**

### Algorithm
- `reverse(num, num + N);`
  - 对数组 [first, last) 范围内的元素逆转
  - 需要头文件：**algorithm**
- `sort(S, S + n, cmp);`
  - 排序函数，实现 [first, last) 范围内的排序，可以自定义排序策略 cmp 函数
  - 不带 cmp 参数的 sort 函数实现从小到大排序
  - 所需头文件： **algorithm**
- `swap(n1, n2)`
  - 交换两个变量的值
  - 所需头文件： **algorithm**

### map
- `map<int, int> m;`
  - 用于映射，键和值可以是任意类型
  - 直接使用 `m[<键>] = <值>` 即可向map中添加一组键值对
  - 需要的头文件：**map**
- `for(auto it = m.begin(); it != m.end(); it++){}`
  - 可用于遍历 map/vector/set 等容器， `auto` 实现自动匹配对应迭代器类型
  - 如果不用 `auto it = m.begin()` 则要写成 `std::map<char, int>::iterator it = m.begin()`
  - `map<char,int>` 在其他情况下可替换成对应元素的类型如 `vector<int>`
  - 包含该函数的容器： **map / set / vector**
- `it->first` 和 `it->second`
  - `it->first` 为 map 中对应元素的关键字
  - `it->second` 为 map 中对应关键字的值
  - 所需头文件： **map**
- `if(couple.find(id1) == couple.end()){ }`
  - `couple.find(id1)` 函数可用于查找序列中是否有某元素，如找到则返回元素迭代器，如未找到则返回 `couple.end()`
  - 包含该函数的容器：**map**, **set**

### 集合set
- `set <int> ans;`
  - 创建了一个集合，用于存放结果
- `ans.insert(S[i])`
  - 向集合中插入一个元素
- 需要头文件 **set**
- `ans.erase(it)`
  - 删除集合中某元素，`it` 为迭代器
- 需要头文件 **set**
- `if(ans.find(c) == ans.end()){ }`
  - `ans.find(id1)` 函数可用于查找序列中是否有某元素，如找到则返回元素迭代器，如未找到则返回 `ans.end()`
  - 包含该函数的容器：**map**, **set**
- `for(auto it = ans.begin(); it != ans.end(); it++){ }`
  - 可用于遍历 map/vector/set 等容器， `auto` 实现自动匹配对应迭代器类型
  - `it` 为迭代器， `*it` 为对应元素
  - 包含该函数的容器： **map / set / vector**
- `if(a == b){ }`
  - 可判断两个集合是否相等
  - 需要头文件 **set**


### 结构体Struct
- `stu(){}`
  - 结构体中加上这句后，可以无需声明直接定义一个新的变量
- `stu(string _name, string _id, int _score):name(_name), id(_id), score(_score){}`
  - 实现直接用指定参数定义结构体变量
- `bool cmp(stu a, stu b){}`
  - 比较函数，可以自定义 sort 时的排序策略

### cctype
- `isdigit(temp)`
  - 判断该字符是否为数字，如是返回 true
- `isalpha(temp)`
  - 判断该字符是否为字母，如是返回 true
- `isupper(temp)`
  - 判断字符是否为大写
- `islower(temp)`
  - 判断字符是否为小写





- `y = (y < x ? x : y);`
    - 从两者中取较大值的简便表达式

- `int gcd(int a, int b){ return b == 0 ? abs(a) : gcd(b, a % b);}`
  - 获取最大公约数

### 求素数
``` cpp
bool isprime(int x){
  for(int i = 2; i * i <= x; i++){
    if(x % i == 0) return false;
  }
  return true;
}
```

  - 插入排序


  ``` cpp
  void InsertionSort1(){ // 标准操作
    j = i + 1;
    temp = S2[j];
    while(j > 0 && temp < S2[j - 1]){
      S2[j] = S2[j - 1];
      j--;
    }
    S2[j] = temp;
  }
  void InsertionSort2(){ // 偷懒操作
    sort(S1, S1 + i + 2);
  }
  ```

  - 归并排序

  ``` cpp
  void mergesort(){ //归并排序
    bool flag = false;
    for(int step = 2; !flag && step / 2 < N; step *= 2){
      if(issame(S1, S2) == true) flag = true;
      for(int i = 0; i < N; i+=step){
        sort(S1 + i, S1 + min(i + step, N));
      }
    }
  }
  ```

直接创建无需声明的结构体
```
struct Student{ // student
  char id[14];
  int score;
  int final_rank;
  int location_num;
  int local_rank;
  Student(){}
  Student(int _score, int _location_num){
    int score = _score;
    int location_num = _location_num;
  }
};
```

自动排序的 set（优先队列）
```
struct table{
  int id, end_time, serve_num, is_vip;
  friend bool operator < (table a, table b){
    if(a.end_time == b.end_time) return a.id < b.id;
    else return a.end_time < b.end_time;
  }
};
set<table> Table;
```

快速读操作
```
int read(){
  int input=0;
  char c=getchar();
  while(c<'0' || c>'9')
    c=getchar();
  while(c>='0' && c<='9'){
    input=input*10 + c - '0';
    c=getchar();
  }
  return input;
}
```

- 64 位系统，int 占 4 个字节，范围是 $[-2^{31}, 2^{31} - 1]$
- 64 位系统，long int 占 8 个字节，范围是 $[-2^{63}, 2^{63} - 1]$


那么每次的姓名输出使用putchar()循环四次输出一个学生的姓名会比printf("%s\n",char \*)这种字符串输出快很多。同理，使用getchar()循环读入学生的姓名也会较scanf()快很多。实际上，对于整数的读入，在这里我们手动实现一个基于getchar()的正整数的读取操作也会加速我们的程序运行。
