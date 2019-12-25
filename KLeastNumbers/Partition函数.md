# 基于Partition函数实现快排、超过一半数字、最小K个数

##  一、二分Partition函数详解

partition算法从字面上就非常好理解，就是分割算法嘛！简单讲就是可以把数组按照一定的分成几个部分，其中最常见的就是快速排序中使用的partition算法，算法就是从数组中找出一个基准，比这个元素小的值在数组左边，比他大的在数组右边。二分partition算法，将整个数组分解为小于某个数和大于某个数的两个部分，然后递归进行排序算法。


### 思路I:

算法思路:

  - 随机选取数组中的一个元素作为枢轴点，即为pivot；
  - 使用一个指针去扫描整个数组，凡是小于pivot的全部放到数组左端；
  - 最后将pivot放到数组中间的位置，pivot左边全部都是小于它的数字，右边反之，最后返回pivot的位置信息；
  
  ![](https://github.com/bryceustc/CodingInterviews/blob/master/KLeastNumbers/Images/Partition.png)
  
  
代码：
```c++
int RandInRang(int start, int end)
{
        int dis = end - start +1;
        srand((unsigned) time(NULL));
        int res = rand()%dis + start;
        return res;
}

int Partition(vector<int> &nums,int start, int end)
{
        int index = RandInRange(start, end);
        swap(nums[index],nums[end]);
        //凡是小于pivot的全部放到数组左端,pos指向<枢轴值的最后一个
        //pos++指向不满足条件的（用于交换，将满足条件的换过来)
        int pos = start;
        for (int i=start;i<=end;i++)
        {
                if (nums[i]<nums[end])
                {
                        pos++;
                        if (i!=pos) //避免自身交换
                                swap(nums[pos], nums[i]);
                }
        }
        swap(nums[pos],nums[end]);
        return pos;
}
```
算法分析:

这种实现思路比较直观，但是其实并不高效。从直观上来分析一下，每个小于pivot的值基本上（除非到现在为止还没有遇见大于pivot的值）都需要一次交换，大于pivot的值（有可能需要被交换多次才能到达最终的位置。


### 思路II:

算法思路:

  - 就如快速排序中最常使用的那样，使用两个指针分别从头部和尾部进行扫描，头部遇到大于pivot的数和尾部遇到小于pivot的数进行交换；
  - 使用了两个指针，效率更高一点；避免使用swap函数

如果我们考虑用 Two Pointers 的思想，保持头尾两个指针向中间扫描，每次在头部找到大于pivot的值，同时在尾部找到小于pivot的值，然后将它们做一个交换，就可以一次把这两个数字放到最终的位置。一种比较明智的写法如下：

代码：
```c++
int RandInRang(int start, int end)
{
        int dis = end - start +1;
        srand((unsigned) time(NULL));
        int res = rand()%dis + start;
        return res;
}

int Partition(vector<int> &nums,  int start , int end)
{
        //  int index = RandInRange(start, end);
        int pivot = nums[start];
        while(start <end)
        {
                while (start <end && nums[end]>=pivot)
                {
                        end--;
                }
                nums[start] = nums[end];   //尾部找到小于pivot的值,移到低端
                while (start <end && nums[start]<=pivot)
                {
                        start++;
                }
                nums[end] = nums[start];  //头部找到大于pivot的值,移到高端
        }
        nums[start] = pivot; //枢轴基准归位(此时start == end)
        return start;
}
```
算法分析:

直观上来看，赋值操作的次数不多，比前面单向扫描的swap次数都少，效率应该会更高。

##  二分Partition函数的应用

### 1. 快速排序算法
```c++
void quick_sort(vector<int> &nums, int start,  int end)
{
        if (start==end)
                return;
        int index = Partition(nums,start,end);
        if (index  > start)
                quick_sort(nums, start,index-1);
        if (index < end)
                quick_sort(nums, index+1,end);      
}
调用：
quick_sort(vec, 0, vec.size()-1); //end为n-1
```


### 2.数组中出现次数超过一半的数字
数组的特性 ：数组中有一个数字出现的次数超过了数组长度的一半。如果我把这个数组排序，那么排序之后位于数组中间的数字一定就是那个出现次数超过数组一半的数字。也就是说，这个数字就是统计学上的中位数，即长度为n的数组中第n/2的数字。 我们有成熟的O(n)的算法得到数组中任意第K大的数字 。

这种算法是受快速排序算法的启发。在随机快速排序算法中，我们现在数组中随机选择一个数字，然后调整数组中数字的顺序，使得比选中的数字小的数字都排在它的左边，比选中的数字大的数字都排在它的右边。如果这个选中的数字的下标刚好是n/2，那么这个数字就是数组的中位数。如果它的下标大于n/2，那么中位数应该位于它的左边，我们可以接着在它的左边部分的数组中查找。如果它的下标小于n/2，那么中位数应该位于它的右边，我们可以接着在它的右边部分的数组中查找。这是一个典型的递归过程，实现代码如下：
```c++
int MoreThanHalfNumbers(vectot<int> &nums)
{
        int res = 0;
        if (nums.empty()) return res;
        int n =nums.size();
        int start = 0;
        int end = n-1;
        int mid = start + (end-start)>>1;
        int index = Partition(nums,start,end);
        whilr(index != mid)
        {
                if(index > mid)
                {
                        end = index -1;
                        index  = Partition(nums,start,end);
                }
                if (index < mid)
                {
                        start = index+1;
                        index = Partition(nums,start , end);
                }
        }
        res = nums[mid];
        if (!checkMoreThanHalfNumber(nums,res))
                res = 0;  
        return res;
}

bool CheckMoreThanHalfNumber(vector<int> &nums，int res)
        {
            int times = 0;
            int n = nums.size();
            int half = n/2;
            for (int i=0;i<n;i++)
            {
                if (nums[i]==res)
                    times++;
            }
            if (times>half)
                return true;
            else
                return false;
        }
```


### 3.最小的K个数
基于数组的第k个数字来调整，使得比第k个数字小的所有数字都位于数组的左边，比第k个数字大的所有数字都位于数组的右边。调整之后，位于数组左边的k个数字就是最小的k个数字（这k个数字不一定是排序的）。时间复杂度O(N)
```c++
vector<int> GetLeastNumbers_Solution(vector<int> nums, int k) 
{
        vector<int> res;
        int n = nums.size();
        if (nums.empty() || k>n) return res; 
        int start = 0;
        int end = n-1;
        int index = Partition(nums,n,start,end);
        while(index!=k-1)
        {
            if (index >k-1)
            {
                end = index - 1;
                Partition(nums,n,start,end);
            }
            else
            {
                start = index+1;
                Partition(nums,n,start,end);
            }
        }
        for(int i = 0;i<k;i++)
        {
            res.push_back(nums[i]);
        }
        return res;
    }
```
# 参考

  -  [基于Partition函数实现快排、超过一半数字、最小K个数](https://www.cnblogs.com/zuilehongdou/p/6197716.html)
  -  [Partition算法剖析](https://www.cnblogs.com/zuilehongdou/p/6197716.html)
