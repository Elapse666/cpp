
# 数组

## 二分法查找

#### [704. 二分查找](https://leetcode.cn/problems/binary-search/)

使用前提：数组是有序数组，数组中无重复元素

二分法查找的两种写法：

#### 左闭右闭区间：[left, right]

- while (left <= right) 要使用 <= ，因为left == right是有意义的，所以使用 <=

- if (nums[middle] > target) right 要赋值为 middle - 1，因为当前这个nums[middle]一定不是target，那么接下来要查找的左区间结束下标位置就是 middle - 1

  <img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230717155322762.png" alt="image-20230717155322762" style="zoom:80%;" />

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(target < nums[mid])
            {
                right = mid - 1;
            }
            else if(target > nums[mid])
            {
                left = mid + 1;
            }
            else 
            {
                return mid;
            }
        }
        return -1;
    }
};
```



## 移除元素

#### [27. 移除元素](https://leetcode.cn/problems/remove-element/)



## 有序数组的平方

### 双指针法

#### [977. 有序数组的平方](https://leetcode.cn/problems/squares-of-a-sorted-array/)

![image-20230717203508921](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230717203508921.png)

```c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int index = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        for(int i = 0, j = nums.size() - 1; i <= j; )
        {
            if(nums[i]*nums[i] > nums[j]*nums[j])
            {
                result[index] = nums[i]*nums[i];
                index--;
                i++;
            }
            else
            {
                result[index] = nums[j]*nums[j];
                index--;
                j--;
            }
        }
        return result;
    }
};
```



## 长度最小的子数组

#### [209. 长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/)

### 滑动窗口

窗口就是 满足其和 ≥ s 的长度最小的 连续 子数组

窗口的结束位置如何移动：当窗口里的值没有大于s，窗口要要向前移动（该扩大了）。

窗口的起始位置如何移动：如果当前窗口的值大于s了，窗口就要向前移动了（也就是该缩小了）

![image-20230717204700942](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230717204700942.png)

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;
        int i = 0;
        int length = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while(sum >= target)
            {
                length = j-i+1;
                result = result < length ? result : length;
                sum -= nums[i];
                i++;
            }
        }
        return result < INT32_MAX ? result : 0;
    }
};
```



## 螺旋矩阵II

没啥说的，螺旋升天

```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int startx = 0, starty = 0;
        int loop = n/2;
        int mid = n/2;
        int count = 1;
        int offset = 1;
        int i, j;
        while(loop--)
        {
            i = startx;
            j = starty;

            for(j = starty; j < n - offset; j++)
            {
                result[startx][j] = count++;
            }
            for(i = startx; i < n - offset; i++)
            {
                result[i][j] = count++;
            }
            for( ; j > starty; j--)
            {
                result[i][j] = count++;
            }
            for( ; i > startx; i--)
            {
                result[i][j] = count++;
            }
            startx++;
            starty++;
            offset++;
        }
        if(n%2)
            result[mid][mid] = count;
        return result;
    }
};
```



# 链表

链表和数组的区别：

数据更适合用于数据查询，链表更适合数据插入和删除。

![image-20230718214453481](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230718214453481.png)



## 移除链表元素

#### [203. 移除链表元素](https://leetcode.cn/problems/remove-linked-list-elements/)

删除普通元素

```c++
cur->next = cur->next->next;
```

![image-20230718150230311](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230718150230311.png)



删除头节点

先新建一个虚拟头节点，再删除原先的头节点

```c++
ListNode* dummyHead = new ListNode(0,head);
ListNode* cur = dummyHead;
cur->next = cur->next->next;
```

![image-20230718150249043](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230718150249043.png)

## 设计链表

## 反转链表

#### [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/)

### 双指针法

![image-20230718171742930](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230718171742930.png)

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur)
        {
            temp = cur->next;
            cur->next = pre;

            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
```



## 两两交换链表中的节点

看图操作

<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230718173713693.png" alt="image-20230718173713693" style="zoom:80%;" />

<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230718173752783.png" alt="image-20230718173752783" style="zoom:80%;" />

<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230718173806011.png" alt="image-20230718173806011" style="zoom:80%;" />

```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead;

        while(cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode* temp1 = cur->next;
            ListNode* temp2 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = temp1;
            cur->next->next->next = temp2;

            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};
```



## 删除链表的倒数第N个节点

#### [19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

### 快慢双指针法

具体实现：先让fast移动n步，然后让fast和slow同时移动，直到fast指向链表末尾，此时slow指向需要被删除的节点。删掉slow所指向的节点就可以了。

![image-20230718203054767](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230718203054767.png)

```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* fastIndex = dummyHead;
        ListNode* slowIndex = dummyHead;
        while(n-- && fastIndex != nullptr)
        {
            fastIndex = fastIndex->next;
        }
        while(fastIndex->next != nullptr)
        {
            fastIndex = fastIndex->next;
            slowIndex = slowIndex->next;
        }
        slowIndex->next = slowIndex->next->next;
        return dummyHead->next;
    }
};
```



# 链表相交

#### [面试题 02.07. 链表相交](https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/)

方法：求出两个链表的长度，并求出两个链表长度的差值，然后让curA移动到，和curB 末尾对齐的位置，如图。此时我们就可以比较

curA和curB是否相同，如果不相同，同时向后移动curA和curB，如果遇到curA == curB，则找到交点。

否则循环退出返回空指针。

<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230718210347946.png" alt="image-20230718210347946" style="zoom:80%;" />

```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;

        while(curA != nullptr)
        {
            lenA++;
            curA = curA->next;
        }
        while(curB != nullptr)
        {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if(lenA < lenB)
        {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int gap = lenA - lenB;
        while(gap--)
        {
            curA = curA->next;
        }
        while(curA != nullptr)
        {
            if(curA == curB)
            {
                return curA;
            }
            else
            {
                curA = curA->next;
                curB = curB->next;
            }
        }
        return nullptr;
    }
};
```



## 环形链表

此题具体看代码随想录链表章节，里面总结的比较好。

也是用快慢双指针法。

code：

```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
            {
                ListNode* index1 = head;
                ListNode* index2 = slow;

                while(index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return NULL;
    }
};
```



## 哈希表

哈希表作用：**速判断一个元素是否出现集合里**，时间复杂度为O(1)

### 常见的三种哈希结构

- 数组
- set （集合）
- map(映射)

![image-20230718223340323](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230718223340323.png)

![image-20230718223359521](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230718223359521.png)



## 有效的字母异位词

#### [242. 有效的字母异位词](https://leetcode.cn/problems/valid-anagram/)

定义一个数组叫做record用来上记录字符串s里字符出现的次数，再遍历所有字符串t中的字符，两字符串次数相减，最后检查所有次数减为零。

![image-20230719105849206](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230719105849206.png)

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> record(26, 0);
        for(int i = 0; i < s.size(); i++)
        {
            record[s[i] - 'a']++;
        }
        for(int j = 0; j < t.size(); j++)
        {
            record[t[j] - 'a']--;
        }
        for(int k = 0; k < record.size(); k++)
        {
            if(record[k] != 0)
                return false;
        }
        return true;
    }
};
```



## 两个数组的交集

#### [349. 两个数组的交集](https://leetcode.cn/problems/intersection-of-two-arrays/)

使用unordered_set

```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> num_set(nums1.begin(), nums1.end());
        for(int i = 0; i < nums2.size(); i++)
        {
            if(num_set.find(nums2[i]) != num_set.end())
            {
                result_set.insert(nums2[i]);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
```

#### [350. 两个数组的交集 II](https://leetcode.cn/problems/intersection-of-two-arrays-ii/)

使用unordered_map

```c++
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> firstMap;
        unordered_map<int, int> secondMap;
        for(int i = 0; i < nums1.size(); i++)
        {
            firstMap[nums1[i]]++;
        }
        for(int j = 0; j < nums2.size(); j++)
        {
            secondMap[nums2[j]]++;
        }
       for(auto iter = secondMap.begin(); iter != secondMap.end(); iter++)
       {
           if(firstMap.find(iter->first) != firstMap.end())
           {
               int count = min(firstMap[iter->first], iter->second);
               for(int k = 0; k < count; k++)
               {
                   result.push_back(iter->first);
               }
           }
       }
       return result;
    }
};
```

## 快乐数

#### [202. 快乐数](https://leetcode.cn/problems/happy-number/)

使用unordered_set

这道题使用unordered_set的原因是需要快速检测是否无限循环。

```c++
class Solution {
public:
    int getSum(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> my_set;
        while(n)
        {
            int sum = getSum(n);
            if(sum == 1)
                return true;
            
            if(my_set.find(sum) != my_set.end())
            {
                return false;
            }
            else
            {
                my_set.insert(sum);
            }
            n = sum;
        }
        return false;
    }
};
```



## 两数之和

#### [1. 两数之和](https://leetcode.cn/problems/two-sum/)

使用unordered_map

思路：在unordered_map中查找是否存在target和nums[i]的差值。

<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230719164249639.png" alt="image-20230719164249639" style="zoom:80%;" />

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> myMap;
        for(int i = 0; i < nums.size(); i++)
        {
            auto iter = myMap.find(target - nums[i]);
            if(iter != myMap.end())
            {
                result.push_back(iter->second);
                result.push_back(i);
                return result;
            }
            else
            {
                myMap.insert(pair<int, int>(nums[i], i));
            }
        }
        return result;
    }
};
```



## 四数之和II

#### [454. 四数相加 II](https://leetcode.cn/problems/4sum-ii/)

解题步骤：

1. 首先定义 一个unordered_map，key放a和b两数之和，value 放a和b两数之和出现的次数。
2. 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中。
3. 定义int变量count，用来统计 a+b+c+d = 0 出现的次数。
4. 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就用count把map中key对应的value也就是出现次数统计出来。
5. 最后返回统计值 count 就可以了

```c++
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int, int> myMap;
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                myMap[nums1[i] + nums2[j]]++;
            }
        }
        for(int i = 0; i < nums3.size(); i++)
            {
                for(int j = 0; j < nums4.size(); j++)
                {
                    if(myMap.find(0 - (nums3[i] + nums4[j])) != myMap.end())
                    {
                        count += myMap[0 - (nums3[i] + nums4[j])];
                    }
                }
            }
        return count;
    }
};
```



## 赎金信

#### [383. 赎金信](https://leetcode.cn/problems/ransom-note/)

使用数组记录magazine中每个字母的次数，在将ransomNote中的字母次数减去，判断数组中是否出现负数即可。

```c++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> record(26, 0);
        if(ransomNote.size() > magazine.size())
            return false;
        for(int i = 0; i < magazine.size(); i++)
        {
            record[magazine[i] - 'a']++;
        }
        for(int j = 0; j < ransomNote.size(); j++)
        {
            record[ransomNote[j] - 'a']--;
            if(record[ransomNote[j] - 'a'] < 0)
                return false;
        }
        return true;
    }
};
```



## 三数之和

#### [15. 三数之和](https://leetcode.cn/problems/3sum/)

双指针法

首先将数组排序，然后有一层for循环，i从下标0的地方开始，同时定一个下标left 定义在i+1的位置上，定义下标right 在数组结尾的位置

上。

依然还是在数组中找到 abc 使得a + b +c =0，我们这里相当于 a = nums[i]，b = nums[left]，c = nums[right]。

接下来如何移动left 和right呢， 如果nums[i] + nums[left] + nums[right] > 0 就说明 此时三数之和大了，因为数组是排序后了，所以

right下标就应该向左移动，这样才能让三数之和小一些。

如果 nums[i] + nums[left] + nums[right] < 0 说明 此时 三数之和小了，left 就向右移动，才能让三数之和大一些，直到left与right相遇为

止。

![image-20230719201740195](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230719201740195.png)

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
                return result;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else if(nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(right > left && nums[right] == nums[right-1])
                        right--;
                    while(right > left && nums[left] == nums[left+1])
                        left++;
                    
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};
```



## 四数之和

#### [18. 四数之和](https://leetcode.cn/problems/4sum/)

此题在三数之和基础上再加一个维度

思路：在第一层循环`i`上再增加一层循环`k`，保持`k`和`i`遍历的两个元素相邻，然后再根据nums[k]+nums[i] + nums[left] + nums[right]总和的大小前后移动`right`和`left`。

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int k = 0; k < nums.size(); k++)
        {
            if(nums[k] > target && (nums[k] > 0 || target > 0))
                break;
            if(k > 0 && nums[k] == nums[k-1])
                continue;
            for(int i = k + 1; i < nums.size(); i++)
            {
                if(nums[k] + nums[i] > target && (nums[k] + nums[i] > 0 || target > 0))
                    break;
                if(i > k+1 && nums[i] == nums[i-1])
                    continue;
                int left = i + 1;
                int right = nums.size() - 1;
                while(left < right)
                {
                    if((long) nums[k] + nums[i] + nums[left] + nums[right] > target)
                        right--;
                    else if((long) nums[k] + nums[i] + nums[left] + nums[right] < target)
                        left++;
                    else
                    {
                        result.push_back(vector<int>{nums[k],nums[i],nums[left],nums[right]});
                        while(left < right && nums[right] == nums[right-1])
                            right--;
                        while(left < right && nums[left] == nums[left+1])
                            left++;
                        
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};
```



# 字符串

## 反转字符串

#### [344. 反转字符串](https://leetcode.cn/problems/reverse-string/)

技术点：双指针

![image-20230719212434238](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230719212434238.png)

```c++
class Solution {
public:
    void mySwap(char& a, char& b)
    {
        char temp = a;
        a = b;
        b = temp;
    }
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right)
        {
            mySwap(s[left++], s[right--]);
        }
    }
};
```



## 反转字符串II

#### [541. 反转字符串 II](https://leetcode.cn/problems/reverse-string-ii/)



```c++
class Solution {
public:
    void myReverse(string& s, int left, int right)
    {
        while(left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            left++;
            right--;
        }
    }
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += 2*k)
        {
            if(i + k <= s.size())
            {
                myReverse(s, i, i + k - 1);
            }
            else
            {
                myReverse(s, i, s.size() - 1);
            }
        }
        return s;
    }
};
```



## 替换空格

#### [剑指 Offer 05. 替换空格](https://leetcode.cn/problems/ti-huan-kong-ge-lcof/)

只能在同一个字符串中操作，不要创建新的字符串。

思路：先扩展字符串容量，然后利用双指针从后面向前面填充，左指针遇到字符则右指针填充字符，遇到空格则右指针填充“%20”。

![image-20230719225444771](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230719225444771.png)

```c++
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int oldSize = s.size();
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
                count++;
        }
        s.resize(oldSize + 2*count);
        int newSize = s.size();
        for(int i = oldSize-1, j = newSize-1; i < j; i--, j--)
        {
            if(s[i] != ' ')
            {
                s[j] = s[i];
            }
            else
            {
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};
```



# 翻转字符串里的单词

#### [151. 反转字符串中的单词](https://leetcode.cn/problems/reverse-words-in-a-string/)

思路：

- 移除多余空格

- 将整个字符串反转
- 将每个单词反转

举个例子，源字符串为："the      sky is    blue     "

- 移除多余空格 : "the sky is blue"
- 字符串反转："eulb si yks eht"
- 单词反转："blue is sky the"

```c++
class Solution {
public:
    void myReverse(string& s, int left, int right)
    {
        for(; left< right; left++, right--)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] =temp;
        }
    }
    void removeSpace(string& s)
    {
        int slow = 0;
        for(int fast = 0; fast < s.size(); fast++)
        {
            if(s[fast] != ' ')
            {
                if(slow != 0)
                    s[slow++] = ' ';
                while(fast < s.size() && s[fast] != ' ')
                {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }
    string reverseWords(string s) {
        removeSpace(s);
        myReverse(s, 0, s.size() - 1);
        int start = 0;
        for(int i = 0; i <= s.size(); i++)
        {
            if(i == s.size() || s[i] == ' ')
            {
                myReverse(s, start, i-1);
                start = i+1;
            }
        }
        return s;
    }
};
```



# 左旋转字符串

#### [剑指 Offer 58 - II. 左旋转字符串](https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/)

思路：先反转n之前的字串，在反转n之后的字串，最后反转整个字符串。

<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230720215708950.png" alt="image-20230720215708950" style="zoom: 67%;" />

```c++
class Solution {
public:
    void myReverse(string& s, int left, int right)
    {
        for(; left< right; left++, right--)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] =temp;
        }
    }
    string reverseLeftWords(string s, int n) {
        myReverse(s, 0, n-1);
        myReverse(s, n, s.size()-1);
        myReverse(s, 0, s.size()-1);
        return s;
    }
};
```



## 实现 strStr()

暴力解法

```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.size(); i++)
        {
            if(haystack[i] == needle[0])
            {
                int oldIndex = i;
                int j = 0;
                while(j < needle.size())
                {
                    if(haystack[i] == needle[j])
                    {
                        i++;
                        j++;
                    }
                    else
                    {
                        i = oldIndex;
                        break;
                    }
                }
                if(j == needle.size())
                    return oldIndex;
            }
        }
        return -1;
    }
};
```



## 重复的子字符串

#### [459. 重复的子字符串](https://leetcode.cn/problems/repeated-substring-pattern/)

暴力解法

```c++
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == s[0])
            {
                string newStr;
                for(int j = 0; j < i; j++)
                {
                    newStr += s[j];
                }
                int k = 0;
                int oldIndex = i;
                while(i < s.size())
                {
                    if(s[i] == s[k])
                    {
                        i++;
                        k++;
                        if(k == newStr.size())
                            k = 0;
                    }
                    else
                    {
                        i = oldIndex;
                        break;
                    }
                }
                if(i == s.size() && k == 0)
                    return true;
            }
        }
        return false;
    }
};
```



# 栈与队列

## 理论基础

### 栈

栈不是容器，栈是容器适配器，不允许遍历行为，只能从顶部压入数据、提取数据，栈的底层实现可以是vector，deque，list。

<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230721155013502.png" alt="image-20230721155013502" style="zoom:67%;" />

### 队列

队列也不是容器，队列是容器适配器，不允许遍历行为，只能从队列为压入数据，队列头提取数据，队列的底层实现可以是vector，deque，list。



## 用栈实现队列

#### [232. 用栈实现队列](https://leetcode.cn/problems/implement-queue-using-stacks/)

```c++
class MyQueue {
public:
    stack<int> stkIn;
    stack<int> stkOut;
    MyQueue() {

    }
    void push(int x) {
        stkIn.push(x);
    }
    
    int pop() {
        if(stkOut.empty())
        {
            while(!stkIn.empty())
            {
                int data = stkIn.top();
                stkIn.pop();
                stkOut.push(data);
            }
        }
        int topData = stkOut.top();
        stkOut.pop();
        return topData;
    }
    
    int peek() {
        int res = this->pop();
        stkOut.push(res);
        return res;
    }
    
    bool empty() {
        return stkIn.empty() && stkOut.empty();
    }
};
```



## 用队列实现栈

#### [225. 用队列实现栈](https://leetcode.cn/problems/implement-stack-using-queues/)

```c++
class MyStack {
public:
    queue<int> queIn;
    queue<int> queOut;
    MyStack() {

    }
    
    void push(int x) {
        queIn.push(x);
    }
    
    int pop() {
        int res;
        if(queOut.empty())
        {
            while(!queIn.empty())
            {
                res = queIn.front();
                queIn.pop();
                if(!queIn.empty())
                {
                    queOut.push(res);
                }
            }
            queIn = queOut;
            while(!queOut.empty())
            {
                queOut.pop();
            }
        }
        return res;
    }
    
    int top() {
        int res = this->pop();
        queIn.push(res);
        return res;
    }
    
    bool empty() {
        return queIn.empty() && queOut.empty();
    }
};
```



## 有效的括号

#### [20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/)

这里我使用了两个栈，其实一个栈也是可以的

```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> record;
        stack<char> match;
        for(int i = 0; i < s.size(); i++)
        {
            record.push(s[i]);
        }
        while(!record.empty())
        {
            char data = record.top();
            record.pop();
            if(data == '}' || data == ']' || data == ')')
            {
                match.push(data);
            }
            else if(data == '{' || data == '[' || data == '(')
            {
                char matchData;
                if(!match.empty())
                    matchData = match.top();
                else
                    return false;
                if(data == '{' && matchData == '}')
                    match.pop();
                else if(data == '[' && matchData == ']')
                    match.pop();
                else if(data == '(' && matchData == ')')
                    match.pop();
                else
                    return false;
            }
        }
        if(!match.empty())
            return false;
        return true;
    }
};
```



## 删除字符串中的所有相邻重复项

使用栈

```c++
class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        stack<char> record;
        for(int i = 0; i < s.size(); i++)
        {
            if(record.empty() || (!record.empty() && s[i] != record.top()))
            {
                record.push(s[i]);
            }
            else if(!record.empty() && s[i] == record.top())
            {
                record.pop();
            }
        }
        while(!record.empty())
        {
            result += record.top();
            record.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
```



## 逆波兰表达式求值

#### [150. 逆波兰表达式求值](https://leetcode.cn/problems/evaluate-reverse-polish-notation/)

需要注意的是`string`类型转换为`int`类型要使用 `stoi(tokens[i])`

```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> record;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int secondData = record.top();
                record.pop();
                int firstData = record.top();
                record.pop();
                if(tokens[i] == "+")
                    record.push(firstData + secondData);
                else if(tokens[i] == "-")
                    record.push(firstData - secondData);
                else if(tokens[i] == "*")
                    record.push(firstData * secondData);
                else if(tokens[i] == "/")
                    record.push(firstData / secondData);
            }
            else
            {
                record.push(stoi(tokens[i]));
            }
        }
        int result = record.top();
        return result;
    }
};
```



## 滑动窗口最大值

#### [239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/)

思路：需要自己构造单调减队列。

<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230721232754304.png" alt="image-20230721232754304" style="zoom:80%;" />

```c++
class Solution {
public:
    class myQueue{
    public:
        deque<int> que;
        void pop(int value)
        {
            if(!que.empty() && value == que.front())
                que.pop_front();
        }
        void push(int value)
        {
            while(!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }
        int getMax()
        {
            return que.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       myQueue record;
       vector<int> result;
       for(int i = 0; i < k; i++)
       {
           record.push(nums[i]);
       }
       result.push_back(record.getMax());
       for(int i = k; i < nums.size(); i++)
       {
           record.pop(nums[i - k]);
           record.push(nums[i]);
           result.push_back(record.getMax());
       }
       return result;
    }
};
```



## 前 K 个高频元素

#### [347. 前 K 个高频元素](https://leetcode.cn/problems/top-k-frequent-elements/)

技术点：小顶堆

思路：

1. 要统计元素出现频率
2. 对频率排序
3. 找出前K个高频元素

具体需要看代码随想录，这里不总结了

<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230722230535097.png" alt="image-20230722230535097" style="zoom:67%;" />



```c++
class Solution {
public:
    class myComparsion {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        for(int i = 0; i < nums.size(); i++)
        {
            record[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparsion> pri_que;

        for(unordered_map<int, int>::iterator it = record.begin(); it != record.end(); it++)
        {
            pri_que.push(*it);
            if(pri_que.size() > k)
                pri_que.pop();
        }
        
        vector<int> result(k);
        for(int i = k-1; i >= 0; i--)
        {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};
```





# 二叉树

## 二叉树的种类

## 满二叉树

满二叉树：如果一棵二叉树只有度为0的结点和度为2的结点，并且度为0的结点在同一层上，则这棵二叉树为满二叉树。

![image-20230412215324683](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230412215324683.png)

### 完全二叉树

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2^(h-1) 个节点。

![image-20230412215607617](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230412215607617.png)

### 二叉搜索树

二叉搜索树是有数值的了，二叉搜索树是一个有序树。

- 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；

- 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；

- 它的左、右子树也分别为二叉排序树

![image-20230412215857650](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230412215857650.png)

### 平衡二叉搜索树

平衡二叉搜索树：具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。

![image-20230412220833638](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230412220833638.png)

## 二叉树的存储方式

**二叉树可以链式存储，也可以顺序存储。**链式存储方式就用指针， 顺序存储的方式就是用数组。

顺序存储的元素在内存是连续分布的，而链式存储则是通过指针把分布在各个地址的节点串联一起。

### 链式存储

![image-20230412221103446](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230412221103446.png)

### 顺序存储

![image-20230412221117766](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230412221117766.png)

## 二叉树的遍历方式

![image-20230412221823241](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230412221823241.png)

## 二叉树的定义

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

## 二叉树的递归遍历

递归算法的三个要素：

**确定递归函数的参数和返回值**：一为传入的二叉树节点，二为保存节点的数值。

```cpp
void traversal(TreeNode* cur, vector<int>& vec)
```

**确定终止条件**：当前的节点为空时，递归终止。

```cpp
if (cur == NULL) return;
```

**确定单层递归的逻辑**：前序遍历是中左右的循序，中序遍历是左中右的循序，后序遍历是左右中的循序。

```cpp
vec.push_back(cur->val);    // 中
traversal(cur->left, vec);  // 左
traversal(cur->right, vec); // 右
```

**前序遍历完整代码：**

[144. 二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/)

```
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec)
    {
        if(cur == NULL)
        {
            return ;
        }
        vec.push_back(cur->val);		//中
        traversal(cur->left, vec);		//左
        traversal(cur->right, vec);		//右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};
```

中序遍历：

[94. 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

```
void traversal(TreeNode* cur, vector<int>& vec)
    {
        if(cur == NULL)
        {
            return;
        }
        traversal(cur->left, vec);		//左	
        vec.push_back(cur->val);		//中
        traversal(cur->right, vec);		//右
    }
```

后序遍历：

[145. 二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/)

```
void traversal(TreeNode* cur, vector<int>& vec)
    {
        if(cur == NULL)
        {
            return ;
        }
        traversal(cur->left, vec);		//左	
        traversal(cur->right, vec);		//右
        vec.push_back(cur->val);		//中
    }
```

## 二叉树的迭代遍历

### 前序遍历（迭代法）

[144. 二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal/)

前序遍历是中左右，每次先处理的是中间节点，那么先将根节点放入栈中，然后将右孩子加入栈，再加入左孩子。

![image-20230412225849375](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230412225849375.png)

```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        if(root == NULL) return res;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode* node = stk.top();		//中
            stk.pop();
            res.push_back(node->val);
            if(node->right) stk.push(node->right);		//先放入右孩子（先判断右孩子不为空）
            if(node->left) stk.push(node->left);		//再放入左孩子（先判断左孩子不为空）
        }
        return res;
    }
};
```

### 后序遍历（迭代法）

[145. 二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal/)

先序遍历是中左右，后续遍历是左右中，那么我们只需要调整一下先序遍历的代码顺序，就变成中右左的遍历顺序，然后在反转result数组，输出的结果顺序就是左右中了。

![image-20230413170236461](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230413170236461.png)

后序遍历的前序遍历的代码区别只有两个：1、后序遍历先放入左孩子再放入右孩子，2、在最后把结果进行翻转。

```
class Solution {
public:
    void rever(vector<int>& vec,int left, int right)
    {
        while(left < right)
        {
            swap(vec[left++],vec[right--]);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        if(root == NULL) return res;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode* node = stk.top();
            stk.pop();
            res.push_back(node->val);
            if(node->left) stk.push(node->left);		//先放入左孩子（先判断左孩子不为空）
            if(node->right) stk.push(node->right);		//再放入右孩子（先判断右孩子不为空）
        }
        rever(res,0,res.size()-1);						//将结果进行翻转
        return res;
    }
};
```



### 中序遍历（迭代法）

[94. 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

中序遍历是左中右，先把左孩子放入栈中，直到树的最底部，再开始处理节点。

![image-20230413170024884](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230413170024884.png)

```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur != NULL || !stk.empty())         //当前节点不为空或者栈不为空
        {
            if(cur != NULL)
            {
                stk.push(cur);          //把当前节点放入栈中
                cur = cur->left;        //继续遍历左孩子，如果不为空就放入栈中
            }
            else
            {
                cur = stk.top();                //如果当前节点为空，则处理栈顶的元素
                stk.pop();                      //把栈顶元素移除
                res.push_back(cur->val);        //栈顶元素放入结果
                cur= cur->right;                //遍历右孩子，如果不为空就放入栈中
            }
        }
        return res;
    }
};
```

## 二叉树的层序遍历

[102. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

使用队列实现二叉树广度优先遍历

![image-20230413194115723](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230413194115723.png)

```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root != NULL) que.push(root);        //把头结点放入栈中
        while(!que.empty())         //栈不为空就一直循环
        {
            int count = que.size();             //记录每一层的节点数
            vector<int> vec;                    //保存每一层的值
            for(int i = 0; i < count; i++)
            {
                TreeNode* node = que.front();               //获取队列头的节点
                que.pop();                                  //将队列头弹出
                vec.push_back(node->val);                   //记录队列头的值
                if(node->left) que.push(node->left);        //将节点的左孩子放入队列
                if(node->right) que.push(node->right);      //将节点的右孩子放入队列
            }
            res.push_back(vec);
        }
        return res;
    }
}; 
```

##  对称二叉树

![image-20230414222737398](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230414222737398.png)

### 利用递归法：

#### 终止条件

左节点为空，右节点不为空，不对称，return false

左不为空，右为空，不对称 return  false

左右都为空，对称，返回true

左右都不为空，比较节点数值，不相同就return false



#### 确定单层递归的逻辑

比较二叉树外侧是否对称：传入的是左节点的左孩子，右节点的右孩子。

比较内测是否对称，传入左节点的右孩子，右节点的左孩子。

如果左右都对称就返回true ，有一侧不对称就返回false 。

```
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right != NULL)   return false;
        else if(left != NULL && right == NULL)  return false;
        else if(left == NULL && right == NULL)  return true;
        else if(left != NULL && right != NULL && left->val != right->val)   return false;
        
        bool outside = compare(left->left, right->right);       //比较外侧子节点
        bool inside = compare(left->right, right->left);        //比较内侧子节点
        bool isSame = outside && inside;                        //外侧和内侧子节点都为真，则返回上一层节点
        return isSame;

    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)    return true;
        return compare(root->left, root->right);
    }
};
```

### 利用迭代法：

![image-20230416154011039](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230416154011039.png)

```
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)    return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while(!que.empty())
        {
            TreeNode* node1 = que.front();
            que.pop();
            TreeNode* node2 = que.front();
            que.pop();

            if(node1 == NULL && node2 == NULL)   continue;
            if(node1 != NULL && node2 == NULL)  return false;
            else if(node1 == NULL && node2 != NULL)     return false;
            else if(node1->val != node2->val)   return false;

            que.push(node1->left);      //外侧
            que.push(node2->right);     //外侧
            que.push(node1->right);     //内侧
            que.push(node2->left);      //内侧
        }
        return true;
    }
};
```

## 二叉树的所有路径

![image-20230418170531593](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230418170531593.png)

```
 /*递归法,前序遍历*/
class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result)
    {
        path.push_back(cur->val);                       //中
        if(cur->left == NULL && cur->right == NULL)     //如果左右孩子都为空节点，保存路径
        {
            string sPath;
            for(int i = 0;i < path.size()-1; i++)
            {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size()-1]);
            result.push_back(sPath);
            return;
        }

        if(cur->left)                           
        {
            traversal(cur->left, path, result);         //递归遍历左孩子
            path.pop_back();
        }
        if(cur->right)
        {
            traversal(cur->right, path, result);        //递归遍历右孩子
            path.pop_back();
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> realpath;
        vector<string> res;
        if(root == NULL) return res;
        traversal(root, realpath, res);
        return res;
    }
};
```

## 二叉树的路径总和

问：

递归函数什么时候需要有返回值，什么时候不需要返回值？

答：

1、如果需要**搜索整棵二叉树**且**不用处理递归返回值**，递归函数就**不要**返回值。

2、如果需要**搜索整棵二叉树**且**需要处理递归返回值**，递归函数就**需要**返回值。

3、如果要**搜索其中一条符合条件的路**径，那么递归**一定需要**返回值，因为遇到符合条件的路径了就要及时返回。

![image-20230418222133935](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230418222133935.png)

```
 /*有返回值的递归函数*/
class Solution {
public:
    bool travel(TreeNode* node, vector<int>& path, int target)
    {
        path.push_back(node->val);
        if(node->left == NULL && node->right == NULL)
        {
            int sum = 0;
            for(int i = 0; i < path.size(); i++)
            {
                sum += path[i];
            }
            if(sum == target)
                return true;
            else
                return false;
        }

        if(node->left)
        {
            if(travel(node->left, path, target)) return true;       //如果左孩子有一条路径符合，就直接返回真
            path.pop_back();
        }
        if(node->right)
        {
            if(travel(node->right, path, target)) return true;      //如果右孩子有一条路径符合，就直接返回真
            path.pop_back();
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        vector<int> path;
        return travel(root, path, targetSum);
        
    }
};
```



## 从中序与后序遍历序列构造二叉树

方法：后序数组的最后一个元素为切割点，先切中序数组，根据中序数组，反过来再切后序数组。一层一层切下去，每次后序数组最后一个元素就是节点元素。

![image-20230419155230614](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230419155230614.png)

步骤：

第一步：如果数组大小为零的话，说明是空节点了。

第二步：如果不为空，那么取**后序数组**最后一个元素作为节点元素。

第三步：找到后序数组最后一个元素在**中序数组**的位置，作为切割点

第四步：切割**中序数组**，切成中序左数组和中序右数组 （顺序别搞反了，一定是先切中序数组）

第五步：切割**后序数组**，切成后序左数组和后序右数组

第六步：递归处理左区间和右区间



```
class Solution {
public:
    TreeNode* travel(vector<int>& inorder, vector<int>& postorder)
    {
        //第一步
        if(postorder.size() == 0) return NULL;

        //第二步, 取后序数组最后一个元素作为节点元素
        int rootValue = postorder[postorder.size()-1];
        TreeNode* node = new TreeNode(rootValue);

        if(postorder.size() == 1) return node;

        //第三步，找到后序数组最后一个元素在中序数组的位置，作为切割点
        int cnt_inorder;
        for(cnt_inorder = 0; cnt_inorder < inorder.size(); cnt_inorder++)
        {
            if(inorder[cnt_inorder] == rootValue)
                break;
        }

        //第四步，切割中序数组，切成中序左数组和中序右数组
        //左开右闭
        vector<int> leftInorder(inorder.begin(), inorder.begin() + cnt_inorder);
        vector<int> rightInorder(inorder.begin() + cnt_inorder + 1, inorder.end());

        //第五步，切割后序数组，切成后序左数组和后序右数组
        //左开右闭
        postorder.resize(postorder.size() - 1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        //第六步，递归左区间和右区间
        node->left = travel(leftInorder, leftPostorder);
        node->right = travel(rightInorder, rightPostorder);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 && postorder.size() == 0) return NULL;
        TreeNode* root = travel(inorder, postorder);
        return root;
    }
};
```



## 从前序和中序遍历序列构造二叉树

步骤：

第一步：如果数组大小为零的话，说明是空节点了。

第二步：如果不为空，那么取**前序数组**第一个元素作为节点元素。

第三步：找到**前序数组**第一个元素在**中序数组**的位置，作为切割点

第四步：切割**中序数组**，切成中序左数组和中序右数组 （顺序别搞反了，一定是先切中序数组）

第五步：切割**前序数组**，切成后序左数组和后序右数组

第六步：递归处理左区间和右区间



## 最大二叉树

做题步骤：

1、找到数组最大的值作为根节点

2、把最大值左边的数组放入递归函数

3、把最大值右边的数组放入递归函数

![image-20230419201705302](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230419201705302.png)

#### [654. 最大二叉树](https://leetcode.cn/problems/maximum-binary-tree/)

```
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node = new TreeNode(0);           //每次进入递归，先构建一个节点
        if(nums.size() == 1)        //如果数组大小为一，直接返回该节点
        {
            node->val = nums[0];
            return node;
        }

        int maxValue = 0;
        int maxIndex = 0;
        for(int i = 0; i < nums.size(); i++)        //找到数组中最大的值，作为根节点
        {
            if(nums[i] > maxValue)
            {
                maxValue = nums[i];
                maxIndex = i;
            }
        }
        node->val = maxValue;

        if(maxIndex > 0)
        {
            vector<int> newnums(nums.begin(), nums.begin() + maxIndex);
            node->left = constructMaximumBinaryTree(newnums);               //递归左数组，构建左子树
        }

        if(maxIndex < nums.size()-1)
        {
            vector<int> newnums(nums.begin() + maxIndex + 1, nums.end());
            node->right = constructMaximumBinaryTree(newnums);              //递归右数组，构建右子树
        }
        
        return node; 
        
    }
};
```



## 合并二叉树

遍历两个二叉树，和遍历一个二叉树逻辑一样，只不过是传入两个二叉树的节点，同时操作。

![image-20230419205555440](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230419205555440.png)

#### [617. 合并二叉树](https://leetcode.cn/problems/merge-two-binary-trees/)

```
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;

        root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2->left);         //同时传入两个二叉树的左子树
        root1->right = mergeTrees(root1->right, root2->right);      //同时传入两个二叉树的右子树

        return root1;
    }
};
```

## 二叉搜索树中的众数

利用双指针和最大频率元素

如果 频率count 等于 maxCount（最大频率），当然要把这个元素加入到结果集中

频率count 大于 maxCount的时候，先清空结果集中旧的元素，再添加最大的maxCount的元素，并更新maxCount。

```
class Solution {
public:
    TreeNode* pre = NULL;
    int count = 1;
    int maxCount= 1;
    int mostValue;
    vector<int> data;
    void travel(TreeNode* cur)
    {
        if(cur == NULL) return ;
        travel(cur->left);
        if(pre != NULL)
        {
            if(pre->val == cur->val){
                count++;
            }
            else{
                count = 1;
            }
        }
        pre = cur;
        if(count == maxCount)		//如果元素达到了频率最高的次数，加入容器
        {
            data.push_back(cur->val);
        }
        if(count > maxCount)		//如果元素超过了频率最高的次数，清楚旧数据，并添加新元素
        {
            maxCount = count;
            while(!data.empty())
            {
                data.pop_back();
            }
            data.push_back(cur->val);
        }
        travel(cur->right);
    }
    vector<int> findMode(TreeNode* root) {
        if(root == NULL) return data;
        travel(root);
        return data;
    }
};
```

## 二叉树的最近公共祖先

总结

1、求最小公共祖先，需要从底向上遍历，那么二叉树，只能通过**后序遍历**（即：回溯）实现从底向上的遍历方式。

2、在回溯的过程中，**必然要遍历整棵二叉树**，即使已经找到结果了，依然要把其他节点遍历完，因为要使用递归函数的返回值（也就是代码中的left和right）做逻辑判断。

3、如果left为空，right不为空，就返回right；如果right为空，left不为空，就返回left。



遍历整棵树：采用后序遍历

![image-20230424123411964](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230424123411964.png)

```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);        //左
        TreeNode* right = lowestCommonAncestor(root->right, p, q);      //右
        if(left != NULL && right != NULL) return root;                  //中
        if(left != NULL && right == NULL) return left;
        else if(right != NULL && left == NULL) return right;
        else  
            return NULL;
    }
};
```

## 二叉搜索树的最近公共祖先

技巧：

​		如果 cur节点同时大于p和q，想左遍历

​		如果 cur节点同时小于p和q，想右遍历

​		如果cur节点介于p和q之间，则cur节点就是最近公共节点。



![image-20230425210810724](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230425210810724.png)

```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root->val > p->val && root->val > q->val)
        {
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            if(left != NULL)
                return left;
        }

        if(root->val < p->val && root->val < q->val)
        {
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if(right != NULL)
                return right;
        }
        return root;
    }
};
```

## 删除二叉搜索树中的节点

二叉搜索树中删除节点遇到的五种情况：

第一种情况：**没找到删除的节点**，遍历到空节点直接返回了

第二种情况：**左右孩子都为空**（叶子节点），直接删除节点， 返回NULL为根节点

第三种情况：删除节点的**右孩子为空，左孩子不为空**，删除节点，左孩子补位，返回左孩子为根节点

第四种情况：删除节点的**左孩子为空，右孩子不为空**，删除节点，右孩子补位，返回右孩子为根节点

第五种情况：**左右孩子节点都不为空**，则将删除节点的左子树头结点（左孩子）放到删除节点的右子树的最左面节点的左孩子上，返回删除节点右孩子为新的根节点。

![image-20230425223604302](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230425223604302.png)

```
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;       // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
        if(root->val == key)
        {       // 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            // 第三种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
            else if(root->left != NULL && root->right == NULL)
            {
                TreeNode* temproot = root->left;
                delete root;
                return temproot;
            }
            // 第四种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
            else if(root->right != NULL && root->left == NULL)
            {
                TreeNode* temproot = root->right;
                delete root;
                return temproot;
            }
            // 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置并返回删除节点右孩子为新的根节点。
            else
            {
                TreeNode* cur = root->right;
                while(cur->left != NULL)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* temproot = root->right;
                delete root;
                return temproot;
            }
        }
        

        if(root->val > key) root->left = deleteNode(root->left, key);
        if(root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};
```

## 修剪二叉搜索树

![image-20230427113139138](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230427113139138.png)

关键：

​	如果root（当前节点）的元素小于low的数值，那么应该递归右子树，并返回右子树符合条件的头结点。

```
if (root->val < low) {
    TreeNode* right = trimBST(root->right, low, high); // 寻找符合区间[low, high]的节点
    return right;
}
```

​	如果root(当前节点)的元素大于high的，那么应该递归左子树，并返回左子树符合条件的头结点。

```
if (root->val > high) {
    TreeNode* left = trimBST(root->left, low, high); // 寻找符合区间[low, high]的节点
    return left;
}
```

整体代码：

```
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;
        if(root->val < low)     //如果root（当前节点）的元素小于low的数值，那么应该递归右子树
        {
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        if(root->val > high)    //如果root(当前节点)的元素大于high的，那么应该递归左子树
        {
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
```

## 将有序数组转换为二叉搜索树

![image-20230427200444791](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230427200444791.png)

关键：

​	寻找分割点，分割点作为当前节点，然后递归左区间和右区间。

整体代码：

```
class Solution {
public:
    TreeNode* travel(vector<int>& nums, int left, int right)
    {
        if(left > right)    return NULL;
        int mid = left + ((right - left)/2);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = travel(nums, left, mid-1);
        root->right = travel(nums, mid+1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = travel(nums, 0, nums.size()-1);
        return root;
    }
};
```

## 把二叉搜索树转换为累加树

![image-20230427205450200](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230427205450200.png)

关键：

遍历顺序：右中左

值记录：定义一个全局变量pre，用来保存cur节点的前一个节点的数值

![image-20230427205553062](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230427205553062.png)

```
class Solution {
public:
    int pre = 0;
    void travel(TreeNode* node)
    {
        if(node == NULL) return;
        travel(node->right);            //右
        node->val += pre;               //中
        pre = node->val;
        travel(node->left);             //左
    }
    TreeNode* convertBST(TreeNode* root) {
        travel(root);
        return root;
    }
};
```

## 二叉树遍历顺序总结

1、涉及到二叉树的构造，无论普通二叉树还是二叉搜索树一定前序，都是先构造中节点。

2、求普通二叉树的属性，一般是后序，一般要通过递归函数的返回值做计算。

3、求二叉搜索树的属性，一定是中序了，要不白瞎了有序性了。







# 回溯算法

## 回溯算法理论基础

### 回溯算法题目分类大纲

![image-20230427222951198](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230427222951198.png)



### 回溯法解决的问题

- 组合问题：N个数里面按一定规则找出k个数的集合
- 切割问题：一个字符串按一定规则有几种切割方式
- 子集问题：一个N个数的集合里有多少符合条件的子集
- 排列问题：N个数按一定规则全排列，有几种排列方式
- 棋盘问题：N皇后，解数独等等

#### 组合和排列的区别

**组合是不强调元素顺序的，排列是强调元素顺序**

例如：{1, 2} 和 {2, 1} 在组合上，就是一个集合，因为不强调顺序，而要是排列的话，{1, 2} 和 {2, 1} 就是两个集合了。

记住组合无序，排列有序，就可以了。

### 回溯算法模板

#### 回溯函数模板返回值以及参数

回溯算法中函数返回值一般为void，回溯算法参数根据题目而定

```
void backtracking(参数)
```

#### 回溯函数终止条件

```
if (终止条件) {
    存放结果;
    return;
}
```

#### 回溯搜索的遍历过程

回溯法一般是在集合中递归搜索，集合的大小构成了树的宽度，递归的深度构成的树的深度。

横向遍历通俗来说是for循环的次数，纵向遍历通俗来说是递归的次数

![image-20230427223720823](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230427223720823.png)

```
for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
    处理节点;
    backtracking(路径，选择列表); // 递归
    回溯，撤销处理结果
}
```

#### 完整的回溯算法模板框架如下：

```
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}

```

## 组合

#### [77. 组合](https://leetcode.cn/problems/combinations/)



![image-20230427224340810](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230427224340810.png)

```
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(int n, int k, int startIndex)
    {
        if(path.size() == k)                //组合含有k个值，处理
        {
            result.push_back(path);
            return;
        }

        for(int i = startIndex; i <= n; i++)
        {
            path.push_back(i);              //处理节点
            backTracking(n, k, i + 1);      //递归
            path.pop_back();                //回溯
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backTracking(n, k, 1);
        return result;
    }
};
```

![image-20230428111749292](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230428111749292.png)



## 电话号码的字母组合

#### [17. 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

![image-20230428155038364](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230428155038364.png)

关键：

1、for循环：循环的元素是数字代表的字母

2、递归：递归的次数是数字的长度

```
class Solution {
public:
    vector<string> res;
    string path;
    const string letterMap[10] = {
        "",     //0
        "",     //1
        "abc",  //2
        "def",  //3
        "ghi",  //4
        "jkl",  //5
        "mno",  //6
        "pqrs", //7
        "tuv",  //8
        "wxyz", //9
    };
    void backTracking(const string& digits, int index)
    {
        if(index == digits.size())
        {
            res.push_back(path);
            return;
        }
        
        int number = digits[index] - '0';           //先取出数字
        string alphaList = letterMap[number];       //取出数字代表的字母集合
        for(int i = 0; i < alphaList.size(); i++)
        {
            path.push_back(alphaList[i]);           //集合
            backTracking(digits, index + 1);        //递归
            path.pop_back();                        //回溯
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res;
        backTracking(digits, 0);
        return res;
    }
};
```



## 组合总和

#### [39. 组合总和](https://leetcode.cn/problems/combination-sum/)

关键：

数字可以被重复选取

![image-20230428173024416](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230428173024416.png)

是否需要starIndex的问题：

如果是一个集合来求组合的话，就需要startIndex

如果是多个集合取组合，各个集合之间相互不影响，那么就不用startIndex

```
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backTracking(vector<int>& candidates, int target, int sum, int starIndex)
    {
        if(sum > target)
            return;
        if(sum == target)
        {
            res.push_back(path);
            return;
        }

        for(int i = starIndex; i < candidates.size(); i++)
        {
            int number = candidates[i];
            path.push_back(number);
            sum += number;
            backTracking(candidates, target, sum, i);
            sum -= number;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTracking(candidates, target, 0, 0);
        return res;
    }
};
```

## 需要去重的组合总和

#### [40. 组合总和 II](https://leetcode.cn/problems/combination-sum-ii/)

首先需要对数组进行排序

一个维度是同一树枝上使用过（树枝维度）不需要去重

一个维度是同一树层上使用过（树层维度）需要去重

- used[i - 1] == **true**，说明同一**树枝**candidates[i - 1]使用过， **不需要去重**
- used[i - 1] == **false**，说明同一**树层**candidates[i - 1]使用过，**需要去重**



另外一种在树层维度去重的方法是使用unordered_set<int> uset

![image-20230428210247620](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230428210247620.png)

```
/*使用vector<bool>& used的方法*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backTracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used)
    {
        if(sum > target)
            return;
        if(sum == target)
        {
            res.push_back(path);
            return;
        }
        for(int i = startIndex; i < candidates.size(); i++)
        {   //candidates[i] == candidates[i - 1]表示出现重复元素，
            //used[i-1] == false表示在上面的情况下，同一个树层使用重复的元素，continue
            if(i > 0 && candidates[i] == candidates[i-1] &&  used[i-1] == false)     
                continue;
            int number = candidates[i];
            path.push_back(number);
            sum += number;
            used[i] = true;     //表示使用过元素
            backTracking(candidates, target, sum, i+1, used);       //递归
            used[i] = false;    //回溯
            sum -= number;      //回溯
            path.pop_back();    //回溯
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        backTracking(candidates, target, 0, 0, used);
        return res;
    }
};
	
/*使用unordered_set<int> uset的方法*/	
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backTracking(vector<int>& candidates, int target, int sum, int startIndex)
    {
        if(sum > target)
            return;
        if(sum == target)
        {
            res.push_back(path);
            return;
        }
        unordered_set<int> uset;
        for(int i = startIndex; i < candidates.size(); i++)
        {   //candidates[i] == candidates[i - 1]表示出现重复元素，
            //used[i-1] == false表示在上面的情况下，同一个树层使用重复的元素，continue
            if(uset.find(candidates[i]) != uset.end())     
                continue;
            int number = candidates[i];
            path.push_back(number);
            sum += number;
            uset.insert(candidates[i]);
            backTracking(candidates, target, sum, i+1);       //递归
            sum -= number;      //回溯
            path.pop_back();    //回溯
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0, 0);
        return res;
    }
};
```



## 分割回文串

#### [131. 分割回文串](https://leetcode.cn/problems/palindrome-partitioning/)

组合问题和切个问题区别：

- 组合问题：选取一个a之后，在bcdef中再去选取第二个，选取b之后在cdef中再选取第三个.....。
- 切割问题：切割一个a之后，在bcdef中再去切割第二段，切割b之后在cdef中再切割第三段.....。

![image-20230428224635800](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230428224635800.png)

关键：

for循环中不只是循环单个元素，而是截取一段字符串。

在`for (int i = startIndex; i < s.size(); i++)`循环中，定义了起始位置startIndex，那么 [startIndex, i] 就是要截取的子串。

```
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    bool check(string example, int left, int right)         //判断字符串是否为回文串
    {
        while(left <= right)
        {
            if(example[left] == example[right])
            {
                left++;
                right--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    void backTracking(const string& s, int startIndex)
    {
        if(startIndex >= s.size())      //如果深度达到了最底部，把该路径的结果放入结果集
        {
            res.push_back(path);
            return ;
        }
        for(int i = startIndex; i < s.size(); i++)      //对字符串进行循环
        {
            if(check(s, startIndex, i))         //截取字符串，截取数量一次递增
            {
                string record = s.substr(startIndex, i-startIndex + 1);
                path.push_back(record);         //是回文串，就放入路径集
            }
            else
            {
                continue;
            }
            backTracking(s, i+1);           //递归
            path.pop_back();                //回溯
        }
    }
    vector<vector<string>> partition(string s) {
        backTracking(s, 0);
        return res;
    }
};
```

## 复原IP地址

#### [93. 复原 IP 地址](https://leetcode.cn/problems/restore-ip-addresses/)

![image-20230510220827180](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230510220827180.png)

```
class Solution {
public:
    vector<string> result;
    bool isValid(const string& s, int start, int end)
    {
        if(start > end)
            return false;
        if(s[start] == '0' && start != end)
            return false;
        int num = 0;
        for(int i = start; i <= end; i++)
        {
            if(s[i] > '9' || s[i] < '0')
                return false;
            num = num*10 + (s[i] - '0');
            if(num > 255)
                return false;
        }
        return true;
    }
    void backtracking(string& s, int startIndex, int pointNum)
    {
        if(pointNum >= 3)
        {
            if(isValid(s, startIndex, s.size()-1))
            {
                result.push_back(s);
            }
            return;
        }

        for(int i = startIndex; i < s.size(); i++)
        {
            if(isValid(s, startIndex, i))
            {
                s.insert(s.begin()+i+1, '.');
                pointNum++;
                backtracking(s, i+2, pointNum);
                pointNum--;
                s.erase(s.begin()+i+1);
            }
            else
                break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12) return result;
        backtracking(s, 0, 0);
        return result;
    }
};
```

## 子集

#### [78. 子集](https://leetcode.cn/problems/subsets/)

区别：与上面（组合问题）区别在于，组合问题在终止条件处收集结果，子集问题在每层递归开始就收集一个子集

关键：在每一层递归就收集一个子集

![image-20230510231409147](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230510231409147.png)

```
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex)
    {
        result.push_back(path);             //关键，每层递归就收集一个子集
        if(startIndex >= nums.size())
            return;
        
        for(int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};
```

## 子集Ⅱ

#### [90. 子集 II](https://leetcode.cn/problems/subsets-ii/)

关键：本题是子集和组合总和Ⅱ的结合，

关键：本题需要和子集一样在每一次递归开始收集一个子集，

​			和组合总和Ⅱ一样设计一个used[]，在数层时去重，在树枝时不去重

![image-20230511233028358](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230511233028358.png)

```
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used)
    {
        result.push_back(path);
        for(int i = startIndex; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i+1, used);
            used[i] = false;
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return result;
    }
};
```



## 递增子序列

#### [491. 递增子序列](https://leetcode.cn/problems/non-decreasing-subsequences/)

关键：使用unordered_set<int> uset，在for循环之前定义unordered_set<int> uset，下一次递归会在定义一个uset

​			所以`unordered_set<int> uset;` 是记录本层元素是否重复使用，新的一层uset都会重新定义（清空），所以要知道uset只负责			本层

![image-20230511233004500](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230511233004500.png)

```
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex)
    {
        if(path.size() >= 2)
        {
            result.push_back(path);
        }    
        unordered_set<int> uset;
        for(int i = startIndex; i < nums.size(); i++)
        {
            if((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end())
                continue;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
             
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};
```

## 全排列

#### [46. 全排列](https://leetcode.cn/problems/permutations/)

关键：

​	与组合问题不同点是，不再使用startIndex，每次递归从0开始搜索，

​	并且使用used[]，记录树枝上使用过的元素。

![image-20230511232936483](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230511232936483.png)

```
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& nums, vector<bool>& used)
    {
        if(path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(used[i] == true)
                continue;
            
            path.push_back(nums[i]);
            used[i] = true;
            backTracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backTracking(nums, used);
        return result;
    }
};
```





## 全排列 II

#### [47. 全排列 II](https://leetcode.cn/problems/permutations-ii/)

对于排列问题，不选取同一个元素，需要用到used[]，

​							树层去重，也可以使用used[]，但是unordered_set<int> uset更加好用

![image-20230511233054581](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230511233054581.png)

```
/*使用unordered_set<int> hasUseSet的方法*/
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& nums, vector<bool>& used)
    {
        if(path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }

        unordered_set<int> hasUseSet;
        for(int i = 0; i < nums.size(); i++)
        {
            if(hasUseSet.find(nums[i]) != hasUseSet.end())
                continue;
            if(used[i] == true)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            hasUseSet.insert(nums[i]);
            backTracking(nums, used);
            used[i] = false;
            path.pop_back();
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backTracking(nums, used);
        return result;
    }
};
	
/*使用used[]方法*/
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& nums, vector<bool>& used)
    {
        if(path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
                continue;
            if(used[i] == true)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backTracking(nums, used);
            used[i] = false;
            path.pop_back();
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backTracking(nums, used);
        return result;
    }
};
```

## N皇后

#### [51. N 皇后](https://leetcode.cn/problems/n-queens/)

首先来看一下皇后们的约束条件：

1. 不能同行
2. 不能同列
3. 不能同斜线

![image-20230515224024892](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230515224024892.png)



```
class Solution {
public:
    vector<vector<string>> result;
    // n 为输入的棋盘大小
    // row 是当前递归到棋盘的第几行了
    void backTracking(vector<string>& chessboard, int n, int row)
    {
        if(row >= n)
        {
            result.push_back(chessboard);
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(isValid(chessboard, row, i, n))
            {
                chessboard[row][i] = 'Q';
                backTracking(chessboard, n, row+1);
                chessboard[row][i] = '.';
            }
        }
    }

    bool isValid(vector<string>& chessboard, int row, int col, int n)
    {
        // 检查列
        for(int i = 0; i < row; i++)
        {
            if(chessboard[i][col] == 'Q')
                return false;
        }
        // 检查 45度角是否有皇后
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--,j--)
        {
            if(chessboard[i][j] == 'Q')
                return false;
        }
        // 检查 135度角是否有皇后
        for(int i = row-1, j= col+1; i >= 0 && j < n; i--,j++)
        {
            if(chessboard[i][j] == 'Q')
                return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backTracking(chessboard, n, 0);
        return result;
    }
};
```

## 解数独

#### [37. 解数独](https://leetcode.cn/problems/sudoku-solver/)

![image-20230515233433116](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230515233433116.png)



```
class Solution {
public:
    bool backTracking(vector<vector<char>>& board)
    {
        for(int i = 0; i < board.size(); i++)   // 遍历行
        {
            for(int j = 0; j < board[0].size(); j++)    // 遍历列
            {
                if(board[i][j] == '.')
                {
                    for(char k = '1'; k <= '9'; k++)    // (i, j) 这个位置放k是否合适
                    {
                        if(isValid(i, j, k, board))
                        {
                            board[i][j] = k;            // 放置k
                            if(backTracking(board))     // 如果找到合适一组立刻返回
                                return true;
                            board[i][j] = '.';          // 回溯，撤销k
                        }
                    }
                    return false;   // 9个数都试完了，都不行，那么就返回false
                }
            }
        }
        return true;    // 遍历完没有返回false，说明找到了合适棋盘位置了
    }
    bool isValid(int row, int col, char num, vector<vector<char>>& board)
    {
        for(int i = 0; i < board.size(); i++)    // 判断行里是否重复
        {
            if(board[row][i] == num)
                return false;
        }
        for(int j = 0; j < board.size(); j++)   // 判断列里是否重复
        {
            if(board[j][col] == num)
                return false;
        }
        int startRow = (row/3) * 3;
        int startCol = (col/3) * 3;
        for(int i = startRow; i < startRow+3; i++)  // 判断9方格里是否重复
        {
            for(int j = startCol; j < startCol+3; j++)
            {
                if(board[i][j] == num)
                    return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backTracking(board);
    }
};
```







# 贪心算法

## 分发饼干

#### [455. 分发饼干](https://leetcode.cn/problems/assign-cookies/)

```
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int index = 0;
        int result = 0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        for(int i = 0; i < s.size(); i++)       //遍历饼干
        {
            if(index < g.size() && s[i] >= g[index])    //胃口由小到大依次满足小孩
            {
                index++;
                result++;
            }
        }
        return result;
    }
};
```



## 摆动序列

#### [376. 摆动序列](https://leetcode.cn/problems/wiggle-subsequence/)

```
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)    return nums.size();
        int curDiff = 0;    // 当前一对差值
        int preDiff = 0;    // 前一对差值
        int result = 1;     // 记录峰值个数，序列默认序列最右边有一个峰值
        for(int i = 0; i < nums.size()-1; i++)
        {
            curDiff = nums[i+1] - nums[i];
            // 出现峰值
            if((preDiff >= 0 && curDiff < 0)||(preDiff <= 0 && curDiff > 0))
            {
                result++;
                preDiff = curDiff;      // 注意这里，只在摆动变化的时候更新prediff 
            }
        }
        return result;
    }
};
```



## 最大子序和

#### [53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/)

关键：

​		**贪心的思路为局部最优：当前“连续和”为负数的时候立刻放弃，从下一个元素重新计算“连续和”，因为负数加上下一个元素 “连续和”只会越来越小。从而推出全局最优：选取最大“连续和”**

​		遍历nums，从头开始用count累积，如果count一旦加上nums[i]变为负数，那么就应该从nums[i+1]开始从0累积count了，因为已经变为负数的count，只会拖累总和

![image-20230516223258569](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230516223258569.png)

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            count += nums[i];
            if(count > result)      // 取区间累计的最大值（相当于不断确定最大子序终止位置）
                result = count;
            if(count < 0)           // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
                count = 0;
        }
        return result;
    }
};
```



## 买卖股票的最佳时机II

#### [122. 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)

关键：

​		其实我们需要收集每天的正利润就可以，**收集正利润的区间，就是股票买卖的区间，而我们只需要关注最终利润，不需要记录区间。**

​		**局部最优：收集每天的正利润，全局最优：求得最大利润**。



![image-20230516224822913](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230516224822913.png)

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            result += max((prices[i] - prices[i-1]),0);
        }
        return result;
    }
};
```



## 跳跃游戏

#### [55. 跳跃游戏](https://leetcode.cn/problems/jump-game/)

关键：

**那么这个问题就转化为跳跃覆盖范围究竟可不可以覆盖到终点！**

每次移动取最大跳跃步数（得到最大的覆盖范围），每移动一个单位，就更新最大覆盖范围。

**贪心算法局部最优解：每次取最大跳跃步数（取最大覆盖范围），整体最优解：最后得到整体最大覆盖范围，看是否能到终点**

![image-20230516231808720](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230516231808720.png)



```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if(nums.size() <= 1)    return true;    // 只有一个元素，就是能达到
        for(int i = 0; i <= cover; i++)         // 注意这里是小于等于cover
        {
            cover = max(i + nums[i], cover);
            if(cover >= nums.size() - 1) return true;   // 说明可以覆盖到终点了
        }
        return false;
    }
};
```



## 跳跃游戏Ⅱ

#### [45. 跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/)

![image-20230517211958469](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230517211958469.png)

如图：当移动下标达到了当前覆盖的最远距离下标时，判断当前覆盖的最远距离下标是否达到终点，

​		如果没有

​				则更新下一次覆盖的最远距离作为当前覆盖的最远距离，并且跳跃步数增加一，判断最远距离是否达到终点，如果是则break；

​		如果已经达到

​				则跳出循环，返回跳跃步数



```
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int curDistance = 0;    // 当前覆盖最远距离下标
        int nextDistance = 0;   // 下一步覆盖最远距离下标
        int result = 0;     //记录跳跃步数
        for(int i = 0; i < nums.size(); i++)
        {
            nextDistance = max(nums[i] + i, nextDistance);      // 更新下一步覆盖最远距离下标
            if(i == curDistance)        // 遇到当前覆盖最远距离下标
            {
                if(curDistance < nums.size()-1)     // 如果当前覆盖最远距离下标不是终点
                {
                    result++;       //跳跃步数加一
                    curDistance = nextDistance;     // 更新当前覆盖最远距离下标
                    if(curDistance >= nums.size()-1)    // 下一步的覆盖范围已经可以达到终点，结束循环
                    {
                        break;
                    }
                }
                else        // 当前覆盖最远距到达集合终点，不用做ans++操作了，直接结束
                    break;
            }
        }
        return result;
    }
};
```



## K次取反后最大化的数组和

#### [1005. K 次取反后最大化的数组和](https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/)

解题步骤：

- 第一步：将数组按照绝对值大小从大到小排序，**注意要按照绝对值的大小**
- 第二步：从前向后遍历，遇到负数将其变为正数，同时K--
- 第三步：如果K还大于0，那么反复转变数值最小的元素，将K用完
- 第四步：求和



```
class Solution {
public:
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int sum = 0;
        sort(nums.begin(), nums.end(), cmp);
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0 && k > 0)
            {
                nums[i] = nums[i]*(-1);
                k--;
            }
        }
        if(k%2 == 1) nums[nums.size()-1] = nums[nums.size()-1]*(-1);
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        return sum;
    }
};
```



## 加油站

#### [134. 加油站](https://leetcode.cn/problems/gas-station/)

![image-20230517231854520](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230517231854520.png)



如果总油量减去总消耗大于等于零那么一定可以跑完一圈，说明 各个站点的加油站 剩油量rest[i]相加一定是大于等于零的。

每个加油站的剩余量rest[i]为gas[i] - cost[i]。

i从0开始累加rest[i]，和记为curSum，一旦curSum小于零，说明[0, i]区间都不能作为起始位置，因为这个区间选择任何一个位置作为起点，到i这里都会断油，那么起始位置从i+1算起，再从0计算curSum

**局部最优：当前累加rest[i]的和curSum一旦小于0，起始位置至少要是i+1，因为从i之前开始一定不行。全局最优：找到可以跑一圈的起始位置**。



```
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if(curSum < 0)      // 当前累加rest[i]和 curSum一旦小于0
            {
                start = i + 1;  // 起始位置更新为i+1
                curSum = 0;     // curSum从0开始
            }
        }
        if(totalSum < 0)
            return -1;      // 说明怎么走都不可能跑一圈了
        return start;
    }
};
```



## 分发糖果

#### [135. 分发糖果](https://leetcode.cn/problems/candy/)

![image-20230518205745874](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230518205745874.png)

采用了两次贪心的策略：

- 一次是从左到右遍历，只比较右边孩子评分比左边大的情况。
- 一次是从右到左遍历，只比较左边孩子评分比右边大的情况。

这样从局部最优推出了全局最优，即：相邻的孩子中，评分高的孩子获得更多的糖果



```
class Solution {
public:
    int candy(vector<int>& ratings) {
        int result = 0;
        vector<int> candyVec(ratings.size(), 1);
        // 从前向后
        for(int i = 1; i < ratings.size(); i++)
        {
            if(ratings[i] > ratings[i-1])
                candyVec[i] = candyVec[i-1] + 1;
        }
        // 从后向前
        for(int j = ratings.size()-2; j >= 0; j--)
        {
            if(ratings[j] > ratings[j+1])
                candyVec[j] = max(candyVec[j], candyVec[j+1] + 1);
        }
        // 统计结果
        for(int k = 0; k < candyVec.size(); k++)
        {
            result += candyVec[k];
        }
        return result;
    }
};
```



## 柠檬水找零

#### [860. 柠檬水找零](https://leetcode.cn/problems/lemonade-change/)

思路：

有如下三种情况：

- 情况一：账单是5，直接收下。
- 情况二：账单是10，消耗一个5，增加一个10
- 情况三：账单是20，优先消耗一个10和一个5，如果不够，再消耗三个5



```
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cashFive = 0;
        int cashTen = 0;
        int cashTwenty = 0;
        for(int i = 0 ; i < bills.size(); i++)
        {
            if(bills[i] == 5)
                cashFive++;
            if(bills[i] == 10)
            {
                cashTen++;
                if(cashFive > 0)
                    cashFive--;
                else
                    return false;
            }
            if(bills[i] == 20)
            {
                cashTwenty++;
                if(cashTen > 0 && cashFive > 0)
                {
                    cashTen--;
                    cashFive--;
                }
                else if(cashTen == 0 && cashFive >= 3)
                {
                    cashFive -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
```



## 根据身高重建队列

#### [406. 根据身高重建队列](https://leetcode.cn/problems/queue-reconstruction-by-height/)

![image-20230518213833060](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230518213833060.png)

思路：
		1、先按身高h来排序，身高一定是从大到小排（身高相同的话则k小的站前面），让高个子在前面

​		2、再按优先按身高高的people的k来插入

![image-20230518214058667](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230518214058667.png)

**局部最优：优先按身高高的people的k来插入。插入操作过后的people满足队列属性**

**全局最优：最后都做完插入操作，整个队列满足题目队列属性**



```
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> path;
        for(int i = 0; i < people.size(); i++)
        {
            int position = people[i][1];
            path.insert(path.begin() + position, people[i]);
        }
        return path;
    }
};
```



## 用最少数量的箭引爆气球

#### [452. 用最少数量的箭引爆气球](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/)

![image-20230521174309676](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230521174309676.png)



```
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0 ) return 0;
        // 根据气球直径的开始坐标从小到大排序
        sort(points.begin(), points.end(), cmp);
        int result = 1;     // points 不为空至少需要一支箭
        for(int i = 1; i < points.size(); i++)
        {
            if(points[i][0] > points[i-1][1])       // 气球i和气球i-1不挨着，注意这里不是>=
            {
                result++;       //增加一支箭
            }    
            else    // 气球i和气球i-1挨着
            {
                points[i][1] = min(points[i-1][1], points[i][1]);       // 更新重叠气球最小右边界
            }
        }
        return result;
    }
};
```



## 无重叠区间

#### [435. 无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals/)

```
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int result = 0;
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] < intervals[i-1][1])     //如果重叠了
            {
                result++;       //需要删除的区间加一
                intervals[i][1] = min(intervals[i][1] ,intervals[i-1][1]);  //更新重叠的区间右边界
            }
        }
        return result;
    }
};
```



## 划分字母区间

#### [763. 划分字母区间](https://leetcode.cn/problems/partition-labels/)



思路：

​		在遍历的过程中相当于是要找每一个字母的边界，**如果找到之前遍历过的所有字母的最远边界，说明这个边界就是分割点了**。此时前面出现过所有字母，最远也就到这个边界了

​		可以分为如下两步：

- 统计每一个字符最后出现的位置
- 从头遍历字符，并更新字符的最远出现下标，如果找到字符最远出现位置下标和当前下标相等了，则找到了分割点



![image-20230521225914163](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230521225914163.png)



```
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int position[27] = {0};     // i为字符，position[i]为字符出现的最后位置
        for(int i = 0 ; i < s.size(); i++)  
        {
            position[s[i] - 'a'] = i;    // 统计每一个字符最后出现的位置
        }

        int left = 0;
        int right = 0;
        vector<int> result;
        for(int i = 0; i < s.size(); i++)
        {
            right = max(right, position[s[i] - 'a']);       // 找到字符出现的最远边界
            if(i == right)
            {
                result.push_back(right-left+1);
                left = i + 1;
            }
        }
        return result;
    }
};
```



## 合并区间

#### [56. 合并区间](https://leetcode.cn/problems/merge-intervals/)



![image-20230522000404507](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230522000404507.png)

思路：

其实就是用合并区间后左边界和右边界，作为一个新的区间，加入到result数组里就可以了。如果没有合并就把原区间加入到result数组



```
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result;       // 区间集合为空直接返回
        sort(intervals.begin(), intervals.end(), cmp);
        result.push_back(intervals[0]);     // 第一个区间就可以放进结果集里，后面如果重叠，在result上直接合并
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= result.back()[1])     // 发现重叠区间
            {
                // 合并区间，只更新右边界就好，因为result.back()的左边界一定是最小值，因为我们按照左边界排序的
                result.back()[1] = max(result.back()[1], intervals[i][1]);      
            }
            else        // 区间不重叠 
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
```



## 单调递增的数字

#### [738. 单调递增的数字](https://leetcode.cn/problems/monotone-increasing-digits/)

思路：

​		从后向前遍历，98，一旦出现strNum[i - 1] > strNum[i]的情况（非单调递增），首先想让strNum[i - 1]--，然后strNum[i]给为9，这样这个整数就是89，即小于98的最大的单调递增整数



```
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
        // flag用来标记赋值9从哪里开始
        // 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
        int flag =  strNum.size();

        for(int i = strNum.size()-1; i > 0; i--)
        {
            if(strNum[i-1] > strNum[i])
            {
                strNum[i-1]--;
                flag = i;
            }
        }
        for(int j = flag; j < strNum.size(); j++)
        {
            strNum[j] = '9';
        }
        return stoi(strNum);
    }
};
```



## 监控二叉树

#### [968. 监控二叉树](https://leetcode.cn/problems/binary-tree-cameras/)

思路看代码随想录

```
class Solution {
public:
    int result = 0;
    int backTracking(TreeNode* cur)
    {
        // 空节点，该节点有覆盖
        if(cur == NULL) return 2;
        int left = backTracking(cur->left);     // 左
        int right = backTracking(cur->right);   // 右

        // 情况1
        // 左右节点都有覆盖
        if(left == 2 && right == 2)
            return 0;
        // 情况2
        // left == 0 && right == 0 左右节点无覆盖
        // left == 1 && right == 0 左节点有摄像头，右节点无覆盖
        // left == 0 && right == 1 左节点有无覆盖，右节点摄像头
        // left == 0 && right == 2 左节点无覆盖，右节点覆盖
        // left == 2 && right == 0 左节点覆盖，右节点无覆盖
        if(left ==0 || right == 0)
        {
            result++;
            return 1;
        }
        // 情况3
        // left == 1 && right == 2 左节点有摄像头，右节点有覆盖
        // left == 2 && right == 1 左节点有覆盖，右节点有摄像头
        // left == 1 && right == 1 左右节点都有摄像头
        // 其他情况前段代码均已覆盖
        if(left == 1 || right == 1)
            return 2;
        // 以上代码我没有使用else，主要是为了把各个分支条件展现出来，这样代码有助于读者理解
        // 这个 return -1 逻辑不会走到这里。
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        // 情况4
        if(backTracking(root) == 0)     // root 无覆盖
            result++;
        return result;
    }
};
```



# 动态规划

## 动态规划理论基础

### 动态规划四大类问题

背包问题

打家劫舍

股票问题

子序列问题

### 动态规划的解题步骤

动态规划五个解题步骤：

1. 确定dp数组（dp table）以及下标的含义
2. 确定递推公式
3. dp数组如何初始化
4. 确定遍历顺序
5. 举例推导dp数组



## 斐波那契数

#### [509. 斐波那契数](https://leetcode.cn/problems/fibonacci-number/)

动规五部曲：

1、确定dp数组以及下标的含义

​		dp[i]的定义为：第i个数的斐波那契数值是dp[i]

2、确定递推公式

​		**状态转移方程 dp[i] = dp[i - 1] + dp[i - 2]**

3、dp数组如何初始化

```text
dp[0] = 0;
dp[1] = 1;
```

4、确定遍历顺序

从递归公式dp[i] = dp[i - 1] + dp[i - 2];中可以看出，dp[i]是依赖 dp[i - 1] 和 dp[i - 2]，那么遍历的顺序一定是从前到后遍历的

5、举例推导dp数组



```
class Solution {
public:
    int fib(int n) {
        vector<int> number;
        number.push_back(0);
        number.push_back(1);
        if(n == 0) return 0;
        if(n == 1) return 1;
        for(int i = 2; i <= n; i++)
        {   
            int tempNum = number[i-1] + number[i-2];
            cout << tempNum << endl;
            number.push_back(tempNum);
        }
        return number.back();
    }
};
```



## 爬楼梯

####  [70. 爬楼梯](https://leetcode.cn/problems/climbing-stairs/)

此题属于斐波那契数列的应用

动规五部曲：

确定dp数组以及下标的含义

​		dp[i]： 爬到第i层楼梯，有dp[i]种方法

确定递推公式

​		首先是dp[i - 1]，上i-1层楼梯，有dp[i - 1]种方法，再一步跳一个台阶就是dp[i]。

​		还有就是dp[i - 2]，上i-2层楼梯，有dp[i - 2]种方法，再一步跳两个台阶就是dp[i]。

​		那么dp[i]就是 dp[i - 1]与dp[i - 2]之和！

​		所以dp[i] = dp[i - 1] + dp[i - 2] 

dp数组如何初始化

​		初始化dp[1] = 1，dp[2] = 2，然后从i = 3开始递推

确定遍历顺序

​		从递推公式dp[i] = dp[i - 1] + dp[i - 2];中可以看出，遍历顺序一定是从前向后遍历的

举例推导dp数组

​		![image-20230522232123805](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230522232123805.png)



```
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return n;    // 因为下面直接对dp[2]操作了，防止空指针
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++)     // 注意i是从3开始的
        {
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};
```



## 使用最小花费爬楼梯

#### [746. 使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs/)

1确定dp数组以及下标的含义

​		**dp[i]的定义：到达第i台阶所花费的最少体力为dp[i]**

2确定递推公式

​		**可以有两个途径得到dp[i]，一个是dp[i-1] 一个是dp[i-2]**。

​		dp[i - 1] 跳到 dp[i] 需要花费 dp[i - 1] + cost[i - 1]。

​		dp[i - 2] 跳到 dp[i] 需要花费  dp[i - 2] + cost[i - 2]

​		一定是选最小的，所以dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);

3dp数组如何初始化

​		初始化 dp[0] = 0，dp[1] = 0;

4确定遍历顺序

​		前到后遍历cost数组

5举例推导dp数组

![image-20230523204948107](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230523204948107.png)

```
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= cost.size(); i++)
        {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp.back();
    }
};
```



## 不同路径

#### [62. 不同路径](https://leetcode.cn/problems/unique-paths/)

1 确定dp数组（dp table）以及下标的含义

​		dp[i][j] ：表示从（0 ，0）出发，到(i, j) 有dp[i][j]条不同的路径

2 确定递推公式

​		想要求dp[i][j] ，只能有两个方向来推导出来，即![image-20230523212452239](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230523212452239.png)

​		所以 ![image-20230523212317445](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230523212317445.png)

3 dp数组的初始化

​		dp[0][0] = 1;

4 确定遍历顺序

​		从左到右一层一层遍历

5 举例推导dp数组

![image-20230523213032349](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230523213032349.png)



```
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
```



## 不同路径 II

#### [63. 不同路径 II](https://leetcode.cn/problems/unique-paths-ii/)

1 确定dp数组（dp table）以及下标的含义

​		dp[i][j] ：表示从（0 ，0）出发，到(i, j) 有dp[i][j]条不同的路径

2 确定递推公式

​		dp[i][j] =  dp[i - 1][j] + dp[i][j - 1]

3 dp数组如何初始化

​		dp[0][0] = 1;

4 确定遍历顺序

​		从左到右一层一层遍历

5 举例推导dp数组

![image-20230523220154873](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230523220154873.png)

```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for(int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    continue;
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
```



## 整数拆分

#### [343. 整数拆分](https://leetcode.cn/problems/integer-break/)

1 确定dp数组（dp table）以及下标的含义

​		dp[i]：分拆数字i，可以得到的最大乘积为dp[i]

2 确定递推公式

​		其实可以从1遍历j，然后有两种渠道得到dp[i]

​		一个是j * (i - j) 直接相乘。

​		一个是j * dp[i - j]，相当于是拆分(i - j)

​		所以递推公式：dp[i] = max({dp[i], (i - j) * j, dp[i - j] * j});

3 dp的初始化

​		dp[0] dp[1] 就不应该初始化，因为没有意义

​		只初始化dp[2] = 1

4 确定遍历顺序

​		dp[i] 是依靠 dp[i - j]的状态，所以遍历i一定是从前向后遍历，先有dp[i - j]再有dp[i]

5 举例推导dp数组

![image-20230523224851178](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230523224851178.png)



```
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[2] = 1;
        for(int i = 3; i <= n; i++)     //遍历dp[i]的i，一直遍历到n
        {
            for(int j = 1; j < i; j++)   //把i拆分成 j+(i-j), 这里遍历j从1到i
            {
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
                cout << i <<", "<<dp[i] << endl;
            }
        }
        return dp[n];
    }
};
```



## 不同的二叉搜索树

#### [96. 不同的二叉搜索树](https://leetcode.cn/problems/unique-binary-search-trees/)

思路：

dp[3]，就是 元素1为头结点搜索树的数量 + 元素2为头结点搜索树的数量 + 元素3为头结点搜索树的数量

元素1为头结点搜索树的数量 = 右子树有2个元素的搜索树数量 * 左子树有0个元素的搜索树数量

元素2为头结点搜索树的数量 = 右子树有1个元素的搜索树数量 * 左子树有1个元素的搜索树数量

元素3为头结点搜索树的数量 = 右子树有0个元素的搜索树数量 * 左子树有2个元素的搜索树数量

有2个元素的搜索树数量就是dp[2]。

有1个元素的搜索树数量就是dp[1]。

有0个元素的搜索树数量就是dp[0]。

所以dp[3] = dp[2] * dp[0] + dp[1] * dp[1] + dp[0] * dp[2]



1 确定dp数组（dp table）以及下标的含义

​		**dp[i] ： 1到i为节点组成的二叉搜索树的个数为dp[i]**

2 确定递推公式

​		在上面的分析中，其实已经看出其递推关系， **dp[i] += dp[以j为头结点左子树节点数量] * dp[以j为头结点右子树节点数量]**

​		j相当于是头结点的元素，从1遍历到i为止

​		所以递推公式：dp[i] += dp[j - 1] * dp[i - j]; ，j-1 为j为头结点左子树节点数量，i-j 为以j为头结点右子树节点数量

3 dp数组如何初始化

​		初始化dp[0] = 1

4 确定遍历顺序

​		遍历i里面每一个数作为头结点的状态，用j来遍历

5 举例推导dp数组

![image-20230524222337425](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230524222337425.png)



```
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
```



## 01背包问题

### 二维dp数组01背包

动规五部曲

1 确定dp数组以及下标的含义

​		**dp【i】【j】表示从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少**

​		i表示能放的物品的最大类型，j表示背包的容量，dp【i】【j】表示最大价值

​		![image-20230524231419848](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230524231419848.png)

2 确定递推公式

​		**不放物品i**：由dp【i - 1】【j】推出，即背包容量为j，里面不放物品i的最大价值，此时dp【i】【j】就是dp【i - 1】【j】。

​		**放物品i**：由dp【i - 1】【j - weight[i]】推出，dp【i - 1】【j - weight[i]】表示放了物品i之后，背包剩余容量为j - weight[i]，还能装入的最大价值，那么dp【i - 1】【j - weight[i]】+ value【i】（物品i的价值），就是背包放物品i得到的最大价值

​		所以递归公式： dp【i】【j】= max(dp【i - 1】【j】, dp【i - 1】【j - weight[i]】+ value【i】;

3 dp数组如何初始化

​		当 j < weight[0]的时候，dp[0][j] 应该是 0，因为背包容量比编号0的物品重量还小

​		当j >= weight[0]时，dp[0][j] 应该是value[0]，因为背包容量放足够放编号0物品

​		其他下标初始为0比较方便。

​		![image-20230524232900422](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230524232900422.png)



4 确定遍历顺序

​		先遍历物品再遍历背包重量

5 举例推导dp数组

​		![image-20230524233253595](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230524233253595.png)



代码：

```
void test_2_wei_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    // 二维数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));

    // 初始化
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0];
    }

    // weight数组的大小 就是物品个数
    for(int i = 1; i < weight.size(); i++) { // 遍历物品
        for(int j = 0; j <= bagweight; j++) { // 遍历背包容量
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);

        }
    }

    cout << dp[weight.size() - 1][bagweight] << endl;
}

int main() {
    test_2_wei_bag_problem1();
}


```



### 一维dp数组（滚动数组）

动规五部曲

1 确定dp数组的定义

​		dp[j]表示：容量为j的背包，所背的物品价值可以最大为dp[j]

2 一维dp数组的递推公式

​		dp[j]有两个选择，一个是取自己dp[j] 相当于 二维dp数组中的dp【i-1】【j】，即不放物品i，一个是取dp[j - weight[i]] + value[i]，即放物品i，指定是取最大的，毕竟是求最大价值

```
dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
```

3 一维dp数组如何初始化

​		dp数组初始化的时候，都初始为0

4 一维dp数组遍历顺序

​		先遍历物品再遍历背包，但背包要从容量最大开始遍历

```
for(int i = 0; i < weight.size(); i++) { // 遍历物品
    for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}
```

5 举例推导dp数组

​		![image-20230525211755754](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230525211755754.png)

代码：

```
void test_1_wei_bag_problem() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // 初始化
    vector<int> dp(bagWeight + 1, 0);
    for(int i = 0; i < weight.size(); i++) { // 遍历物品
        for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
}

int main() {
    test_1_wei_bag_problem();
}
```



## 分割等和子集

#### [416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/)

思路：

- 背包的体积为sum / 2
- 背包要放入的商品（集合里的元素）重量为 元素的数值，价值也为元素的数值
- 背包如果正好装满，说明找到了总和为 sum / 2 的子集。
- 背包中每一个元素是不可重复放入。

动规五部曲

1 确定dp数组以及下标的含义

​		**dp[j]表示 背包总容量（所能装的总重量）是j，放进物品后，背的最大重量为dp[j]**

2 确定递推公式

​		01背包的递推公式为：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

​		本题，相当于背包里放入数值，那么物品i的重量是nums[i]，其价值也是nums[i]。

​		所以递推公式：dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);

3 dp数组如何初始化

​		dp[0]一定是0

​		非0下标的元素也初始化为0

4 确定遍历顺序

​		如果使用一维dp数组，物品遍历的for循环放在外层，遍历背包的for循环放在内层，且内层for循环倒序遍历

5 举例推导dp数组

![image-20230525221039602](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230525221039602.png)

![image-20230530225024809](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230530225024809.png)

```
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        vector<int> dp(10001, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if(sum % 2 == 1) return false;
        int target = sum/2;
        

        for(int i = 0; i < nums.size(); i++)    //先遍历物品
        {
            for(int j = target; j >= nums[i]; j--)      //再遍历背包
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if(dp[target] == target)
            return true;
        return false;
    }
};
```



## 最后一块石头的重量II

#### [1049. 最后一块石头的重量 II](https://leetcode.cn/problems/last-stone-weight-ii/)

1 确定dp数组以及下标的含义

​		**dp[j]表示容量（这里说容量更形象，其实就是重量）为j的背包，最多可以背最大重量为dp[j]**

2 确定递推公式

​		01背包的递推公式为：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

​		本题则是：**dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);**

3 dp数组如何初始化

​		dp[j]都初始化为0就可以了

4 确定遍历顺序

​		如果使用一维dp数组，物品遍历的for循环放在外层，遍历背包的for循环放在内层，且内层for循环倒序遍历

5 举例推导dp数组

![image-20230525233052866](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230525233052866.png)

```
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        vector<int> dp(15001, 0);
        for(int i = 0; i < stones.size(); i++)
        {
            sum += stones[i];
        }
        int target = sum/2;

        for(int i = 0; i < stones.size(); i++)
        {
            for(int j = target; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        int bigBag = sum - dp[target];
        return bigBag -dp[target];
    }
};
```



## 目标和

#### [494. 目标和](https://leetcode.cn/problems/target-sum/)

1 确定dp数组以及下标的含义

​		dp[j] 表示：填满j（包括j）这么大容积的包，有dp[j]种方法

2 确定递推公式

​		例如：dp[j]，j 为5，

- 已经有一个1（nums[i]） 的话，有 dp[4]种方法 凑成 容量为5的背包。
- 已经有一个2（nums[i]） 的话，有 dp[3]种方法 凑成 容量为5的背包。
- 已经有一个3（nums[i]） 的话，有 dp[2]中方法 凑成 容量为5的背包
- 已经有一个4（nums[i]） 的话，有 dp[1]中方法 凑成 容量为5的背包
- 已经有一个5 （nums[i]）的话，有 dp[0]中方法 凑成 容量为5的背包

```
dp[j] += dp[j - nums[i]]
```

3 dp数组如何初始化

​		初始化 dp[0] 为 1

4 确定遍历顺序

​		对于01背包问题一维dp的遍历，nums放在外循环，target在内循环，且内循环倒序

5 举例推导dp数组

![image-20230529211311849](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230529211311849.png)



```
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if(abs(target) > sum) return 0;
        if((sum + target)%2 == 1) return 0;
        int bagSize = (sum + target)/2;
        vector<int> dp(bagSize+1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = bagSize; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};
```



## 一和零

#### [474. 一和零](https://leetcode.cn/problems/ones-and-zeroes/)

1 确定dp数组（dp table）以及下标的含义

​		**dp【i】【j】：最多有i个0和j个1的strs的最大子集的大小为dp【i】【j】**

2 确定递推公式

​		dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);

3 dp数组如何初始化

​		dp数组的值均初始化为0

4 确定遍历顺序

​		外层for循环遍历物品，内层for循环遍历背包容量且从后向前遍历！

5 举例推导dp数组

​		![image-20230530185824912](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230530185824912.png)



```
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int x = 0; x < strs.size(); x++)
        {
            int zeroNum = 0;
            int oneNum = 0;
            for(int y = 0; y < strs[x].size(); y++)
            {
                if(strs[x][y] == '0')
                    zeroNum++;
                else
                    oneNum++;
            }
            for(int i = m; i >= zeroNum; i--)
            {
                for(int j = n; j >= oneNum; j--)
                {
                    dp[i][j] = max(dp[i][j] , dp[i-zeroNum][j-oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
```



## 零钱兑换II

#### [518. 零钱兑换 II](https://leetcode.cn/problems/coin-change-ii/)

1 确定dp数组以及下标的含义

​		dp[j]：凑成总金额j的货币组合数为dp[j]

2 确定递推公式

​		dp[j]  就是所有的dp[j - coins[i]]（考虑coins[i]的情况）相加。

​		所以递推公式：dp[j] += dp[j - coins[i]];

3 dp数组如何初始化

​		 dp[0] = 1 ，下标非0的dp[j]初始化为0

4 确定遍历顺序

​		外层for循环遍历**物品**（钱币），内层for遍历**背包**（金钱总额）--**这种遍历顺序中dp[j]里计算的是组合数！**

```
for (int i = 0; i < coins.size(); i++) { // 遍历物品
    for (int j = coins[i]; j <= amount; j++) { // 遍历背包容量
        dp[j] += dp[j - coins[i]];
    }
}
```

![image-20230530225501520](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230530225501520.png)

​		外层for循环遍历背包（金钱总额），内层for遍历**物品**（钱币）--**这种遍历顺序中dp[j]里计算的是排列数！**

```
for (int j = 0; j <= amount; j++) { // 遍历背包容量
    for (int i = 0; i < coins.size(); i++) { // 遍历物品
        if (j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
    }
}
```

![image-20230530225437026](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230530225437026.png)

本题要使用组合数。

5 举例推导dp数组

![image-20230530223118802](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230530223118802.png)



```
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++)
        {
            for(int j = coins[i]; j <= amount; j++)
            {
                dp[j] += dp[j - coins[i]]; 
                cout << dp[j] << endl;
            }
        }
        return dp[amount];
    }
};
```



## 组合总和 Ⅳ

#### [377. 组合总和 Ⅳ](https://leetcode.cn/problems/combination-sum-iv/)

1 确定dp数组以及下标的含义

​		**dp[i]: 凑成目标正整数为i的排列个数为dp[i]**

2 确定递推公式

​		求装满背包有几种方法，递推公式一般都是**dp[i] += dp[i - nums[j]];**

3 dp数组如何初始化

​		dp[0] = 1 ，非0下标的dp[i]应该初始为0

4 确定遍历顺序

​		**如果求组合数就是外层for循环遍历物品，内层for遍历背包**。

​		**如果求排列数就是外层for遍历背包，内层for循环遍历物品**。

​		本题要求排列数，所以本题遍历顺序最终遍历顺序：**target（背包）放在外循环，将nums（物品）放在内循环，内循环从前到后遍历**。

5 举例来推导dp数组

![image-20230530231451505](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230530231451505.png)



```
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 0; i <= target; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]])
                {
                    dp[i] += dp[i - nums[j]];
                    cout << dp[i] << endl;
                }    
            }
        }
        return dp[target];
    }
};
```



## 爬楼梯

#### [70. 爬楼梯](https://leetcode.cn/problems/climbing-stairs/)

1 确定dp数组以及下标的含义

​		**dp[i]：爬到有i个台阶的楼顶，有dp[i]种方法**

2 确定递推公式

​		dp[i] += dp[i - j]

3 dp数组如何初始化

​		dp[0] 一定为1，下标非0的dp[i]初始化为0

4 确定遍历顺序

​		需将target放在外循环，将nums放在内循环

5 举例来推导dp数组

​		

```
class Solution {
public:
    int climbStairs(int n) {
        vector<int> nums;
        nums.push_back(1);
        nums.push_back(2);
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int j = 0; j <= n; j++)
        {
            for(int i = 0; i < nums.size(); i++)
            {
                if(j - nums[i] >= 0) 
                {
                    dp[j] += dp[j - nums[i]];
                    cout << dp[j] << endl;
                }
            }
        }
        return dp[n];
    }
};
```



## 零钱兑换

#### [322. 零钱兑换](https://leetcode.cn/problems/coin-change/)

1 确定dp数组以及下标的含义

​		**dp[j]：凑足总额为j所需钱币的最少个数为dp[j]**

2 确定递推公式

​		dp[j] =  min(dp[j - coins[i]] + 1, dp[j]);

3 dp数组如何初始化

​		凑足总金额为0所需钱币的个数一定是0，那么dp[0] = 0;

​		下标非0的元素都是应该是最大值

```
vector<int> dp(amount + 1, INT_MAX);
dp[0] = 0;
```

4 确定遍历顺序

​		采用coins放在外循环，target在内循环的方式

5 举例推导dp数组

![image-20230531224202743](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230531224202743.png)



```
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++)       //遍历物品
        {
            for(int j = coins[i]; j <= amount; j++)     //遍历背包
            {
                if(dp[j-coins[i]] != INT_MAX)       // 如果dp[j - coins[i]]是初始值则跳过
                {
                    dp[j] = min(dp[j], dp[j - coins[i]]+1);
                }
            }
            cout << "    i = " << i << endl; 
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};
```



## 完全平方数

#### [279. 完全平方数](https://leetcode.cn/problems/perfect-squares/)

1 确定dp数组（dp table）以及下标的含义

​		**dp[j]：和为j的完全平方数的最少数量为dp[j]**

2 确定递推公式

​		dp[j] = min(dp[j - i * i] + 1, dp[j])

3 dp数组如何初始化

​		dp[0]表示 和为0的完全平方数的最小数量，那么dp[0]一定是0

​		递归公式dp[j] = min(dp[j - i * i] + 1, dp[j]);中可以看出每次dp[j]都要选最小的，**所以非0下标的dp[j]一定要初始为最大值，这样dp[j]在递推的时候才不会被初始值覆盖**

4 确定遍历顺序

​		**本题外层for遍历背包，内层for遍历物品，还是外层for遍历物品，内层for遍历背包，都是可以的**

5 举例推导dp数组

![image-20230531233210715](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230531233210715.png)

 

```
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        vector<int> nums;
        for(int i = 1; i <= n; i++)
        {
            nums.push_back(i*i);
        }
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++)    //遍历物品
        {
            for(int j = nums[i]; j <= n; j++)   //遍历背包
            {
                    dp[j] = min(dp[j], dp[j -nums[i]] + 1);
            }
        }
        return dp[n];
    }
};
```



## 单词拆分

#### [139. 单词拆分](https://leetcode.cn/problems/word-break/)

1 确定dp数组以及下标的含义

​		**dp[i] : 字符串长度为i的话，dp[i]为true，表示可以拆分为一个或多个在字典中出现的单词**。

2 确定递推公式

​		如果确定dp[j] 是true，且 [j, i] 这个区间的子串出现在字典里，那么dp[i]一定是true。（j < i ）。

​		所以递推公式是 if([j, i] 这个区间的子串出现在字典里 && dp[j]是true) 那么 dp[i] = true

3 dp数组如何初始化

​		dp[0]一定要为true，下标非0的dp[i]初始化为false

4 确定遍历顺序

​		本题求排列数，先遍历 背包，再遍历物品

5 举例推导dp[i]

​		![image-20230601211636510](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230601211636510.png)



```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size()+1, false);
        dp[0] = true;

        for(int i = 0; i <= s.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                string word = s.substr(j, i - j);
                if(wordSet.find(word) != wordSet.end() && dp[j])
                    dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};
```



## 打家劫舍

#### [198. 打家劫舍](https://leetcode.cn/problems/house-robber/)

1 确定dp数组（dp table）以及下标的含义

​		**dp[i]：考虑下标i（包括i）以内的房屋，最多可以偷窃的金额为dp[i]**

2 确定递推公式

​		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);

3 dp数组如何初始化

​		dp[0] 一定是 nums[0]，

​		dp[1]就是nums[0]和nums[1]的最大值即：dp[1] = max(nums[0], nums[1]);

4 确定遍历顺序

​		从前到后遍历

5 举例推导dp数组

​		![image-20230601224318693](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230601224318693.png)



```
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};
```



## 打家劫舍II

#### [213. 打家劫舍 II](https://leetcode.cn/problems/house-robber-ii/)

三种情况：

![image-20230601232019622](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230601232019622.png)

![image-20230601232029502](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230601232029502.png)

![image-20230601232045693](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230601232045693.png)

​		**情况二 和 情况三 都包含了情况一了，所以只考虑情况二和情况三就可以了**



```
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> numstemp1 = nums;
        numstemp1.pop_back();
        int result1 = robRange(numstemp1);
        vector<int> numstemp2 = nums;
        for(int i = 0; i < numstemp2.size()-1; i++)
        {
            numstemp2[i] = numstemp2[i+1];
        }
        numstemp2.pop_back();
        int result2 = robRange(numstemp2);
        
        return max(result1, result2);
    }

    int robRange(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};
```



## 打家劫舍 III

#### [337. 打家劫舍 III](https://leetcode.cn/problems/house-robber-iii/)

1 确定递归函数的参数和返回值

​		dp数组（dp table）以及下标的含义：下标为0记录不偷该节点所得到的的最大金钱，下标为1记录偷该节点所得到的的最大金钱

2 确定终止条件

​		在遍历的过程中，如果遇到空节点的话，很明显，无论偷还是不偷都是0，所以就返回

```
if (cur == NULL) return vector<int>{0, 0};
```

3 确定遍历顺序

​		首先明确的是使用后序遍历。 因为要通过递归函数的返回值来做下一步计算。

​		通过递归左节点，得到左节点偷与不偷的金钱。

​		通过递归右节点，得到右节点偷与不偷的金钱。

4 确定单层递归的逻辑

​		如果是偷当前节点，那么左右孩子就不能偷，val1 = cur->val + left[0] + right[0];  （**如果对下标含义不理解就再回顾一下dp数组的含义**）

​		如果不偷当前节点，那么左右孩子就可以偷，至于到底偷不偷一定是选一个最大的，所以：val2 = max(left[0], left[1]) + max(right[0], right[1]);

​		最后当前节点的状态就是{val2, val1}; 即：{不偷当前节点得到的最大金钱，偷当前节点得到的最大金钱}

5 举例推导dp数组

<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230607220457086.png" alt="image-20230607220457086" style="zoom: 80%;" />



```
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
    vector<int> robTree(TreeNode* cur)
    {
        if(cur == NULL) return vector<int> {0,0};
       
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);

        int steal = cur->val + left[0] + right[0];

        int noSteal = max(left[0], left[1]) + max(right[0], right[1]);

        return vector<int>{noSteal, steal};
    }
};
```



## 买卖股票的最佳时机

#### [121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/)

1 确定dp数组（dp table）以及下标的含义

​		dp【i】【0】表示第 i 天持有股票所花的最少的钱

​		dp【i】【1】表示第 i 天不持有股票所得最多现金

2 确定递推公式

如果第i天持有股票即dp[i][0]， 那么可以由两个状态推出来

- 第i-1天就持有股票，那么就保持现状，所得现金就是昨天持有股票的所花的钱 即：dp【i】【0】
- 第i天买入股票，所花费的钱就是买入今天的股票所花费的钱即：prices[i]

那么dp【i】【0】应该选花费金钱最小的，所以dp【i】【0】= min(dp【i-1】【0】, prices[i]);



如果第i天不持有股票即dp[i][1]， 也可以由两个状态推出来

- 第i-1天就不持有股票，那么就保持现状，所得现金就是昨天不持有股票的所得现金 即：dp【i】【1】
- 第i天卖出股票，所得现金就是按照今天股票价格卖出后所得现金即：prices[i] - dp【i-1】【0】

同样dp【i】【1】取最大的，dp【i】【1】 = max(dp【i-1】【1】, prices[i] - dp【i-1】【0】);

3 dp数组如何初始化

dp【0】【0】表示第0天持有股票，此时的持有股票就一定是买入股票了，因为不可能有前一天推出来，所以dp【0】【0】 = prices[0];

dp【0】【1】表示第0天不持有股票，不持有股票那么现金就是0，所以dp【0】【1】 = 0;

4 确定遍历顺序

从递推公式可以看出dp[i]都是由dp[i - 1]推导出来的，那么一定是从前向后遍历。

5 举例推导dp数组

![image-20230607230941286](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230607230941286.png)

此题写法与代码随想录略有不同

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = min(dp[i-1][0], prices[i]);
            dp[i][1] = max(dp[i-1][1], prices[i] - dp[i-1][0]);
        } 
        return dp[prices.size()-1][1];
    }
};
```



## 买卖股票的最佳时机II

#### [122. 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)

1 确定dp数组（dp table）以及下标的含义

- dp【i】【0】表示第i天持有股票所得现金。
- dp【i】【1】表示第i天不持有股票所得最多现金

2 确定递推公式

如果第i天持有股票即dp[i][0]， 那么可以由两个状态推出来

- 第i-1天就持有股票，那么就保持现状，所得现金就是昨天持有股票的所得现金 即：dp【i】【0】
- 第i天买入股票，所得现金就是昨天不持有股票的所得现金减去 今天的股票价格 即：dp【i】【1】- prices[i]

如果第i天不持有股票即dp[i][1]的情况， 依然可以由两个状态推出来

- 第i-1天就不持有股票，那么就保持现状，所得现金就是昨天不持有股票的所得现金 即：dp[i - 1][1]
- 第i天卖出股票，所得现金就是按照今天股票价格卖出后所得现金即：prices[i] + dp[i - 1][0]

3 dp数组如何初始化

dp【0】【0】表示第0天持有股票，此时的持有股票就一定是买入股票了，因为不可能有前一天推出来，所以dp【0】【0】- = prices[0];

dp【0】【1】表示第0天不持有股票，不持有股票那么现金就是0，所以dp【0】【1】 = 0;

4 确定遍历顺序

从递推公式可以看出dp[i]都是由dp[i - 1]推导出来的，那么一定是从前向后遍历。



```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        } 
        return dp[prices.size()-1][1];
    }
};
```



## 买卖股票的最佳时机III

#### [123. 买卖股票的最佳时机 III](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/)

1 确定dp数组以及下标的含义

​		一天一共就有五个状态，

1. 没有操作  （其实我们也可以不设置这个状态）
2. 第一次持有股票
3. 第一次不持有股票
4. 第二次持有股票
5. 第二次不持有股票

dp【i】【j】中 i表示第i天，j为 [0 - 4] 五个状态，dp【i】【j】表示第i天状态j所剩最大现金。

2 确定递推公式

​		达到dp【i】【1】状态，有两个具体操作：

- 操作一：第i天买入股票了，那么dp【i】【1】= dp【i-1】【0】 - prices[i]
- 操作二：第i天没有操作，而是沿用前一天买入的状态，即：dp【i】【1】= dp【i-1】【1】

​		一定是选最大的，所以dp【i】【1】= max(dp【i-1】【0】- prices[i], dp【i-1】【1】);

​		同理dp【i】【2】也有两个操作：

- 操作一：第i天卖出股票了，那么dp【i】【2】= dp【i-1】【1】 + prices[i]
- 操作二：第i天没有操作，沿用前一天卖出股票的状态，即：dp【i】【2】= dp【i-1】【2】

​		所以dp【i】【2】= max(dp【i-1】【1】- prices[i], dp【i-1】【2】);

​		同理可推出剩下状态部分：

​		dp【i】【3】= max(dp【i-1】【2】- prices[i], dp【i-1】【3】);

​		dp【i】【4】= max(dp【i-1】【3】- prices[i], dp【i-1】【4】);

3 dp数组如何初始化

​		第0天没有操作，这个最容易想到，就是0，即：dp【0】【0】 = 0;

​		第0天做第一次买入的操作，dp【0】【1】= -prices[0];

​		大家可以理解当天买入，当天卖出，所以dp【0】【2】= 0;

​		第二次买入操作，初始化为：dp【0】【3】= -prices[0];

​		同理第二次卖出初始化dp【0】【4】= 0;

4 确定遍历顺序

​		定是从前向后遍历，因为dp[i]，依靠dp[i - 1]的数值。

5 举例推导dp数组

![image-20230608212050291](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230608212050291.png)



```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][1] = - prices[0];
        dp[0][3] = - prices[0];

        for(int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
        }
        return dp[prices.size()-1][4];
    }
};
```



## 买卖股票的最佳时机IV

#### [188. 买卖股票的最佳时机 IV](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/)

1 确定dp数组以及下标的含义

使用二维数组 dp[i][j] ：第i天的状态为j，所剩下的最大现金是dp[i][j]

j的状态表示为：

- 0 表示不操作
- 1 第一次买入
- 2 第一次卖出
- 3 第二次买入
- 4 第二次卖出

2 确定递推公式

达到dp【i】【1】状态，有两个具体操作：

- 操作一：第i天买入股票了，那么dp【i】【1】= dp【i-1】【0】 - prices[i]
- 操作二：第i天没有操作，而是沿用前一天买入的状态，即：dp【i】【1】= dp【i-1】【1】

​		一定是选最大的，所以dp【i】【1】= max(dp【i-1】【0】- prices[i], dp【i-1】【1】);

​		同理dp【i】【2】也有两个操作：

- 操作一：第i天卖出股票了，那么dp【i】【2】= dp【i-1】【1】 + prices[i]
- 操作二：第i天没有操作，沿用前一天卖出股票的状态，即：dp【i】【2】= dp【i-1】【2】

​		所以dp【i】【2】= max(dp【i-1】【1】- prices[i], dp【i-1】【2】);

同理可以类比剩下的状态，代码如下：

```
for (int j = 0; j < 2 * k - 1; j += 2) {
    dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
    dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
}
```

3 dp数组如何初始化

​		第0天没有操作，这个最容易想到，就是0，即：dp【0】【0】 = 0;

​		第0天做第一次买入的操作，dp【0】【1】= -prices[0];

​		大家可以理解当天买入，当天卖出，所以dp【0】【2】= 0;

​		第二次买入操作，初始化为：dp【0】【3】= -prices[0];

​		同理第二次卖出初始化dp【0】【4】= 0;

​		**所以同理可以推出dp[0][j]当j为奇数的时候都初始化为 -prices[0]**

4 确定遍历顺序

​		从递归公式其实已经可以看出，一定是从前向后遍历，因为dp[i]，依靠dp[i - 1]的数值。

5 举例推导dp数组

![image-20230608223307468](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230608223307468.png)



```
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2*k+1, 0));
        for(int i = 1; i < 2*k; i+=2)
        {
            dp[0][i] = - prices[0];
        }
        for(int i = 1; i < prices.size(); i++)
        {
            for(int j = 0; j < 2*k; j+=2)
            {
                dp[i][j+1] = max(dp[i-1][j+1], dp[i-1][j] - prices[i]);
                dp[i][j+2] = max(dp[i-1][j+2], dp[i-1][j+1] + prices[i]);
            }
        }
        return dp[prices.size()-1][2*k];
    }
};
```



## 最佳买卖股票时机含冷冻期

#### [309. 最佳买卖股票时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

1 确定dp数组以及下标的含义

dp<i><j>，第i天状态为j，所剩的最多现金为dp<i><j>。

- 状态一：持有股票状态（今天买入股票，或者是之前就买入了股票然后没有操作，一直持有）
- 不持有股票状态，这里就有两种卖出股票状态
  - 状态二：保持卖出股票的状态（两天前就卖出了股票，度过一天冷冻期。或者是前一天就是卖出股票状态，一直没操作）
  - 状态三：今天卖出股票
- 状态四：今天为冷冻期状态，但冷冻期状态不可持续，只有一天！

2 确定递推公式

​		**达到买入股票状态**（状态一）即：dp[i][0]，有两个具体操作：

- 操作一：前一天就是持有股票状态（状态一），dp[i][0] = dp[i - 1][0]

- 操作二：今天买入了，有两种情况
  - 前一天是冷冻期（状态四），dp[i - 1][3] - prices[i]
  - 前一天是保持卖出股票的状态（状态二），dp[i - 1][1] - prices[i]

那么dp[i][0] = max(dp[i - 1][0], dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]);

​		**达到保持卖出股票状态**（状态二）即：dp[i][1]，有两个具体操作：

- 操作一：前一天就是状态二
- 操作二：前一天是冷冻期（状态四）

dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);

​		**达到今天就卖出股票状态**（状态三），即：dp[i][2] ，只有一个操作：

昨天一定是持有股票状态（状态一），今天卖出

即：dp[i][2] = dp[i - 1][0] + prices[i];

​		**达到冷冻期状态**（状态四），即：dp[i][3]，只有一个操作：

昨天卖出了股票（状态三）

dp[i][3] = dp[i - 1][2];

```
dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
dp[i][2] = dp[i - 1][0] + prices[i];
dp[i][3] = dp[i - 1][2];
```

3 dp数组如何初始化

如果是持有股票状态（状态一）那么：dp[0][0] = -prices[0]，一定是当天买入股票。

dp[0][1]初始化为0，dp[0][2]初始化为0，dp[0][3]也初始为0

4 确定遍历顺序

从递归公式上可以看出，dp[i] 依赖于 dp[i-1]，所以是从前向后遍历。

5 举例推导dp数组

![image-20230608232943228](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230608232943228.png)



```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int> (4, 0));
        dp[0][0] = -prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            //持有股票状态
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][3] - prices[i], dp[i-1][1] - prices[i]));
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);     //不持有股票转台
            dp[i][2] = dp[i-1][0] + prices[i];      //当天卖出股票状态
            dp[i][3] = dp[i-1][2];      //冷冻期状态
        }

        return max(dp[prices.size()-1][1], max(dp[prices.size()-1][2], dp[prices.size()-1][3]));
    }
};
```



## 买卖股票的最佳时机含手续费

#### [714. 买卖股票的最佳时机含手续费](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

本题和买卖股票II的区别只有卖出时需要减去手续费

代码：

```
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if(len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]-fee);
        } 
        return dp[prices.size()-1][1];
    }
};
```





## 最长递增子序列

#### [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)

1 dp[i]的定义

​		**dp[i]表示i之前包括i的以nums[i]结尾的最长递增子序列的长度**

2 状态转移方程

​		位置i的最长升序子序列等于j从0到i-1各个位置的最长升序子序列 + 1 的最大值。

​		所以：if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);

​		**注意这里不是要dp[i] 与 dp[j] + 1进行比较，而是我们要取dp[j] + 1的最大值**。

3 dp[i]的初始化

​		每一个i，对应的dp[i]（即最长递增子序列）起始大小至少都是1

4 确定遍历顺序

​		dp[i] 是有0到i-1各个位置的最长递增子序列 推导而来，那么遍历i一定是从前向后遍历。

​		j其实就是遍历0到i-1，那么是从前到后，还是从后到前遍历都无所谓，只要吧 0 到 i-1 的元素都遍历了就行了。 所以默认习惯 从前向后遍历

5 举例推导dp数组

![image-20230618205636084](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230618205636084.png)

```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int result = 1;
        vector<int> dp(nums.size(), 1);
        if(nums.size() <= 1) return nums.size();
        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if(dp[i] > result) result = dp[i];
        }
        return result;
    }
};
```



## 最长连续递增序列

#### [674. 最长连续递增序列](https://leetcode.cn/problems/longest-continuous-increasing-subsequence/)

1 确定dp数组（dp table）以及下标的含义

​		**dp[i]：以下标i为结尾的连续递增的子序列长度为dp[i]**

2 确定递推公式

​		如果 nums[i] > nums[i - 1]，那么以 i 为结尾的连续递增的子序列长度 一定等于 以i - 1为结尾的连续递增的子序列长度 + 1 。

​		即：dp[i] = dp[i - 1] + 1;

3 dp数组如何初始化

​		dp[i]应该初始1

4 确定遍历顺序

​		从前向后遍历

5 例推导dp数组

![image-20230618224523811](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230618224523811.png)



```
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int result = 0;
        vector<int> dp(nums.size(), 1);
        if(nums.size() <= 1) return nums.size();
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i-1]) dp[i] = dp[i-1]+1;
            if(dp[i] > result) result = dp[i];
        }
        return result;
    }
};
```





## 最长重复子数组

#### [718. 最长重复子数组](https://leetcode.cn/problems/maximum-length-of-repeated-subarray/)

1 确定dp数组（dp table）以及下标的含义

​		dp【i】【j】 ：以下标i - 1为结尾的A，和以下标j - 1为结尾的B，最长重复子数组长度为dp【i】【j】 。  （**特别注意**： “以下标i - 1为结尾的A” 标明一定是 以A[i-1]为结尾的字符串 ）

2 确定递推公式

​		根据dp[i][j]的定义，dp[i][j]的状态只能由dp[i - 1][j - 1]推导出来。

​		即当A[i - 1] 和B[j - 1]相等的时候，dp[i][j] = dp[i - 1][j - 1] + 1;

3 dp数组如何初始化

​		根据dp【i】【j】的定义，dp【i】【0】和dp【0】【j】其实都是没有意义的！

​		所以dp【i】【0】和dp【0】【j】[j]初始化为0

4 确定遍历顺序

​		外层for循环遍历A，内层for循环遍历B

5 举例推导dp数组

![image-20230618232751898](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230618232751898.png)



```
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        for(int i = 1; i <= nums1.size(); i++)
        {
            for(int j = 1; j <= nums2.size(); j++)
            {
                if(nums2[j-1] == nums1[i-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > result) result = dp[i][j];
            }
        }
        return result;
    }
};
```





## 最长公共子序列

#### [1143. 最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/)

1 确定dp数组（dp table）以及下标的含义

​		dp【i】【j】：长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]

2 确定递推公式

​		如果text1[i - 1] 与 text2[j - 1]相同，那么找到了一个公共元素，所以dp【i】【j】 = dp【i-1】【j-1】 + 1;

​		如果text1[i - 1] 与 text2[j - 1]不相同，那就看看text1[0, i - 2]与text2[0, j - 1]的最长公共子序列 和 text1[0, i - 1]与text2[0, j - 2]的最长公共子序列，取最大的。即：dp【i】【j】= max(dp【i-1】【j】, dp【i】【j-1】;

3 dp数组如何初始化

​		test1[0, i-1]和空串的最长公共子序列自然是0，所以dp【i】【0】= 0;

​		同理dp【0】【j】也是0；

​		所以全部都统一初始化为0。

4 确定遍历顺序

​		从上到下、从左到右。

5 举例推导dp数组

![image-20230619212241519](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230619212241519.png)



```
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int result = 0;
        vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1, 0));
        for(int i = 1; i <= text1.size(); i++)
        {
            for(int j = 1; j <= text2.size(); j++)
            {
                if(text1[i-1] == text2[j-1]) 
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

                if(dp[i][j] > result) result = dp[i][j];
            }
        }
        return result;
    }
};
```



## 最大子序和

#### [53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/)

1 确定dp数组（dp table）以及下标的含义

​		**dp[i]：包括下标i（以nums[i]为结尾）的最大连续子序列和为dp[i]**。

2 确定递推公式

​		dp[i]只有两个方向可以推出来：

- dp[i - 1] + nums[i]，即：nums[i]加入当前连续子序列和
- nums[i]，即：从头开始计算当前连续子序列和

​		一定是取最大的，所以dp[i] = max(dp[i - 1] + nums[i], nums[i]);

3 dp数组如何初始化

​		很明显dp[0]应为nums[0]即dp[0] = nums[0]

4 确定遍历顺序

​		递推公式中dp[i]依赖于dp[i - 1]的状态，需要从前向后遍历

5 举例推导dp数组

![image-20230619224516127](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230619224516127.png)



```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int result = dp[0];
        for(int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            if(dp[i] > result) result = dp[i];
        }
        return result;
    }
};
```



## 判断子序列

#### [392. 判断子序列](https://leetcode.cn/problems/is-subsequence/)

1 确定dp数组（dp table）以及下标的含义

​		**dp【i】【j】表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同子序列的长度为dp【i】【j】**

2 确定递推公式

​		在确定递推公式的时候，首先要考虑如下两种操作，整理如下：

- if (s[i - 1] == t[j - 1])
  - t中找到了一个字符在s中也出现了
- if (s[i - 1] != t[j - 1])
  - 相当于t要删除元素，继续匹配

​		if (s[i - 1] == t[j - 1])，那么dp【i】【j】= dp【i-1】【j-1】+ 1;，因为找到了一个相同的字符，相同子序列长度自然要在dp【i-1】【j-1】的基础上加1（**如果不理解，在回看一下dp【i】【j】的定义**）

​		if (s[i - 1] != t[j - 1])，此时相当于t要删除元素，t如果把当前元素t[j - 1]删除，那么dp[i][j] 的数值就是 看s[i - 1]与 t[j - 2]的比较结果了，即：dp【i】【j】= dp【i】【j-1】;

3 dp数组如何初始化

​		dp【i】【0】和dp【0】【j】是一定要初始化为0。其实所有都可初始化为0。

4 确定遍历顺序

​		从上到下，从左到右

5 举例推导dp数组

![image-20230619233251033](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230619233251033.png)



```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 1; j <= t.size(); j++)
            {
                if(s[i-1] == t[j-1]) 
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = dp[i][j-1];
            }
        }
        if(dp[s.size()][t.size()] == s.size()) return true;
        else return false;
    }
};
```



## 不同的子序列----未理解

#### [115. 不同的子序列](https://leetcode.cn/problems/distinct-subsequences/)

1 确定dp数组（dp table）以及下标的含义

​		dp【i】【j】：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp【i】【j】

2 确定递推公式

​		这一类问题，基本是要分析两种情况

- s[i - 1] 与 t[j - 1]相等
- s[i - 1] 与 t[j - 1] 不相等

​		当s[i - 1] 与 t[j - 1]相等时，dp【i】【j】可以有两部分组成。

​		一部分是用s[i - 1]来匹配，那么个数为dp【i-1】【j-1】。即不需要考虑当前s子串和t子串的最后一位字母，所以只需要 dp【i-1】【j-1】。

​		一部分是不用s[i - 1]来匹配，个数为dp【i-1】【j】。

3 dp数组如何初始化

​		dp【i】【0】表示：以i-1为结尾的s可以随便删除元素，出现空字符串的个数。

​		那么dp【i】【0】一定都是1，因为也就是把以i-1为结尾的s，删除所有元素，出现空字符串的个数就是1

​		再来看dp【0】【j】，dp【0】【j】：空字符串s可以随便删除元素，出现以j-1为结尾的字符串t的个数。

​		那么dp【0】【j】一定都是0，s如论如何也变成不了t

4 确定遍历顺序

​		遍历顺序一定是从上到下，从左到右。

5 举例推导dp数组

![image-20230623161111624](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230623161111624.png)



```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint64_t>> dp(s.size()+1, vector<uint64_t>(t.size()+1));
        for(int i = 0; i < s.size(); i++)   dp[i][0] = 1;
        for(int j = 1; j < t.size(); j++)   dp[0][j] = 0;
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 1; j <= t.size(); j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};
```





## 两个字符串的删除操作----未理解

#### [583. 两个字符串的删除操作](https://leetcode.cn/problems/delete-operation-for-two-strings/)

1 确定dp数组（dp table）以及下标的含义

​		dp【i】【j】：以i-1为结尾的字符串word1，和以j-1位结尾的字符串word2，想要达到相等，所需要删除元素的最少次数

2 确定递推公式

- 当word1[i - 1] 与 word2[j - 1]相同的时候
- 当word1[i - 1] 与 word2[j - 1]不相同的时候

当word1[i - 1] 与 word2[j - 1]相同的时候，dp【i】【j】 = dp【i-1】【j-1】;

当word1[i - 1] 与 word2[j - 1]不相同的时候，有三种情况：

情况一：删word1[i - 1]，最少操作次数为dp【i-1】【j】+ 1

情况二：删word2[j - 1]，最少操作次数为dp【i】【j-1】 + 1

情况三：同时删word1[i - 1]和word2[j - 1]，操作的最少次数为dp【i-1】【j-1】 + 2

3 dp数组如何初始化

从递推公式中，可以看出来，dp[i][0] 和 dp[0][j]是一定要初始化的。

dp[i][0]：word2为空字符串，以i-1为结尾的字符串word1要删除多少个元素，才能和word2相同呢，很明显dp[i][0] = i。

dp[0][j]的话同理，所以代码如下：

```cpp
vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
```

4 确定遍历顺序

​		遍历顺序一定是从上到下，从左到右

5 举例推导dp数组

![image-20230623165548512](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230623165548512.png)



```
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size()+1));
        for(int i = 0; i <= word1.size(); i++)  dp[i][0] = i;
        for(int j = 0; j <= word2.size(); j++)  dp[0][j] = j;
        for(int i = 1; i <=word1.size(); i++)
        {
            for(int j = 1; j <= word2.size(); j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else 
                {
                    dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
```



## 编辑距离----未理解

#### [72. 编辑距离](https://leetcode.cn/problems/edit-distance/)

1 确定dp数组（dp table）以及下标的含义

​		**dp【i】【j】表示以下标i-1为结尾的字符串word1，和以下标j-1为结尾的字符串word2，最近编辑距离为dp【i】【j】**

2 确定递推公式

```text
if (word1[i - 1] == word2[j - 1])
    不操作
if (word1[i - 1] != word2[j - 1])
    增
    删
    换
```



代码：

```
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size()+1, 0));
        for(int i = 0; i <= word1.size(); i++)  dp[i][0] = i;
        for(int j = 0; j <= word2.size(); j++)  dp[0][j] = j;
        for(int i = 1; i <= word1.size(); i++)
        {
            for(int j = 1; j <= word2.size(); j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j],dp[i][j-1]}) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
```





## 回文子串

#### [647. 回文子串](https://leetcode.cn/problems/palindromic-substrings/)

1 确定dp数组（dp table）以及下标的含义

​		dp数组是要定义成一位二维dp数组

​		布尔类型的dp【i】【j】：表示区间范围[i,j] （注意是左闭右闭）的子串是否是回文子串，如果是，则dp【i】【j】为true，否则为false

2 确定递推公式

​		整体上是两种，就是s[i]与s[j]相等，s[i]与s[j]不相等这两种。

​		当s[i]与s[j]不相等，那没啥好说的了，dp【i】【j】一定是false。

​		当s[i]与s[j]相等时，这就复杂一些了，有如下三种情况

- 情况一：下标i 与 j相同，同一个字符例如a，当然是回文子串
- 情况二：下标i 与 j相差为1，例如aa，也是回文子串
- 情况三：下标：i 与  j相差大于1的时候，例如cabac，此时s[i]与s[j]已经相同了，我们看i到j区间是不是回文子串就看aba是不是回文就可以了，那么aba的区间就是 i+1 与 j-1区间，这个区间是不是回文就看dp【i-1】【j-1】是否为true。

3 dp数组如何初始化

​		dp[i][j]初始化为false

4 确定遍历顺序

![image-20230623185205543](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230623185205543.png)

​		由于dp【i】【j】是由左下角的dp【i+1】【j-1】决定的，所以遍历顺序是由下到上，由左到右。

5 举例推导dp数组

![image-20230623185235972](C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230623185235972.png)



```
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> bp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for(int i = s.size()-1; i >= 0; i--)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(s[i] == s[j])
                {
                    if(j - i <= 1)
                    {
                        result++;
                        bp[i][j] = true;
                    }
                    else
                    {
                        if(bp[i+1][j-1] == true)
                        {
                            result++;
                            bp[i][j] = true;
                        }
                    }
                }
            }
        }
        return result;
    }
};
```





## 最长回文子序列

#### [516. 最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence/)

1 确定dp数组（dp table）以及下标的含义

​		**dp【i】【j】：字符串s在[i, j]范围内最长的回文子序列的长度为dp【i】【j】**

2 确定递推公式

​		如果s[i]与s[j]相同，那么dp【i】【j】 = dp【i+1】【j-1】 + 2;

<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230623194759267.png" alt="image-20230623194759267" style="zoom: 50%;" />

​		如果s[i]与s[j]不相同，说明s[i]和s[j]的同时加入 并不能增加[i,j]区间回文子序列的长度，那么分别加入s[i]、s[j]看看哪一个可以组成最长的回文子序列。

​		加入s[j]的回文子序列长度为dp【i+1】【j】。

​		加入s[i]的回文子序列长度为dp【i】【j-1】。

​		那么dp【i】【j】一定是取最大的，即：dp【i】【j】= max(dp【i+1】【j】,dp【i】【j-1】);

<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230623195016464.png" alt="image-20230623195016464" style="zoom:50%;" />

3 dp数组如何初始化

​		当i与j相同，那么dp【i】【j】一定是等于1的，即：一个字符的回文子序列长度就是1

​		其他情况dp【i】【j】初始为0就行

4 确定遍历顺序

<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230623195226633.png" alt="image-20230623195226633" style="zoom:67%;" />

由上图所示，遍历顺序应该是由下到上，由左到右。

5 举例推导dp数组

<img src="C:\Users\86155\AppData\Roaming\Typora\typora-user-images\image-20230623195331824.png" alt="image-20230623195331824" style="zoom:80%;" />



```
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), 0));
        for(int i = 0; i < s.size(); i++)
            dp[i][i] = 1;
        for(int i = s.size()-1; i >= 0; i--)
        {
            for(int j = i+1; j < s.size(); j++)
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};
```





# 单调栈

## 每日温度

#### [739. 每日温度](https://leetcode.cn/problems/daily-temperatures/)

```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> stk;
        stk.push(0);
        for(int i = 1; i < temperatures.size(); i++)
        {
            if(temperatures[i] <= temperatures[stk.top()])
            {
                stk.push(i);
            }
            else
            {
                while(!stk.empty() && temperatures[i] > temperatures[stk.top()])
                {
                    result[stk.top()] = i - stk.top();
                    stk.pop();
                }
                stk.push(i);
                
            }
        }
        return result;
    }
};
```





## 下一个更大元素 I

#### [496. 下一个更大元素 I](https://leetcode.cn/problems/next-greater-element-i/)

```
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1);
        if(nums1.size() == 0) return result;
        unordered_map<int, int> umap;
        for(int i = 0; i < nums1.size(); i++)
        {
            umap[nums1[i]] = i;
        }
        stack<int> stk;
        stk.push(0);
        for(int i = 1; i < nums2.size(); i++)
        {
            if(nums2[i] <= nums2[stk.top()])
            {
                stk.push(i);
            }
            else
            {
                while(!stk.empty() && nums2[i] > nums2[stk.top()])
                {
                    if(umap.count(nums2[stk.top()]))
                    {
                        int index = umap[nums2[stk.top()]];
                        result[index] = nums2[i];
                    }
                    stk.pop();
                }
                stk.push(i);
            }
        }
        return result;
    }
};
```





## 下一个更大元素II

#### [503. 下一个更大元素 II](https://leetcode.cn/problems/next-greater-element-ii/)

```
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nums1(nums.begin(), nums.end());
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        vector<int> result(nums.size(), -1);
        stack<int> stk;
        stk.push(0);
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= nums[stk.top()])
            {
                stk.push(i);
            }
            else
            {
                while(!stk.empty() && nums[i] > nums[stk.top()])
                {
                    result[stk.top()] = nums[i];
                    stk.pop();
                }
                stk.push(i);
            }
        }
        result.resize(nums.size()/2);
        return result;
    }
};
```





## 接雨水

#### [42. 接雨水](https://leetcode.cn/problems/trapping-rain-water/)

```
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        stk.push(0);
        int sum = 0;
        for(int i = 1; i < height.size(); i++)
        {
            if(height[i] < height[stk.top()])
            {
                stk.push(i);
            }
            else if(height[i] == height[stk.top()])
            {
                stk.pop();
                stk.push(i);
            }
            else
            {
                while(!stk.empty() && height[i] > height[stk.top()])
                {
                    int mid = stk.top();
                    stk.pop();
                    if(!stk.empty())
                    {
                        int h = min(height[i], height[stk.top()]) - height[mid];
                        int w = i - stk.top() - 1;
                        sum = sum + h*w;
                    }
                }
                stk.push(i);
            }
        }
        return sum;
    }
};
```





## 柱状图中最大的矩形

#### [84. 柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram/)



```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        
        stack<int> stk;
        stk.push(0);

        for(int i = 0; i < heights.size(); i++)
        {
            if(heights[i] > heights[stk.top()])
            {
                stk.push(i);
            }
            else if(heights[i] == heights[stk.top()])
            {
                stk.pop();
                stk.push(i);
            }
            else
            {
                while(!stk.empty() && heights[i] < heights[stk.top()])
                {
                    int mid = stk.top();
                    stk.pop();
                    if(!stk.empty())
                    {
                        int left = stk.top();
                        int right = i;
                        int w = right- left - 1;
                        int h = heights[mid];
                        int sum = h * w;
                        if(result < sum) result = sum;
                    }
                }
                stk.push(i);
            }
        }
        return result;
    }
};
```

