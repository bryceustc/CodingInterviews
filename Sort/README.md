# 排序算法

基础排序算法： 冒泡排序、选择排序、**插入排序**、**归并排序**、希尔排序、**快速排序**、**堆排序**

![](http://pelhans.com/img/in-post/alg/sort_summary.jpg)

### 1. 冒泡排序

代码：
```c++
/*
    1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
    2. 对第0个到第n-1个数据做同样的工作。这时，最大的数就“浮”到了数组最后的位置上。
    3. 针对所有的元素重复以上的步骤，除了最后已经选出的元素（有序）。
    4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较.
*/

// 稳定排序，平均 O(n**2)，最好 O(n), 最差 O(n**2),辅助空间 O(1)

void bubble_sort(vector<int> &nums)
{
    int n = nums.size();
    if (n==0) return;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-1-i;j++)
        {
            if (nums[j] > nums[j+1])
            {
                // swap(nums[j], nums[j+1]);
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
}
```

### 2. 选择排序

代码：
```c++
/*
    1. 在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
    2. 再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
    3. 以此类推，直到所有元素均排序完毕。
*/

// 不稳定排序，平均 O(n**2)，最好 O(n**2), 最差 O(n**2),辅助空间 O(1)

void select_sort(vector<int> &nums)
{
    int n = nums.size();
    if (n==0) return;
    for (int i=0;i<n-1;i++)
    {
        int idx = i; //每一趟循环比较时，idx用于存放较小元素的数组下标，这样当前批次比较完毕最终存放的就是此趟内最小的元素的下标，避免每次遇到较小元素都要进行交换。
        for (int j=i+1;j<n;j++)
        {
            if (nums[idx] > nums[j]);
            {
                idx = j;
            }
            if (idx !=i)
            {
                int temp = nums[idx];
                nums[idx] = nums[i];
                nums[i] = temp;
            }
        }
}
```
