# 剑指Offer

## **Contents:**
### 数组：

* [剑指Offer(三)：数组中重复的数字](./DuplicationInArray/README.md)(**多做几遍**)
* [剑指Offer(四)：二维数组中的查找](./FindInPartiallySortedMatrix/README.md) (遍历)
* [剑指Offer(十一)：旋转数组的最小数字](./MinNumberInRotatedArray/README.md) (二分查找)
* [剑指Offer(二十一)：调整数组顺序使奇数位于偶数前面](./ReorderArray/README.md) (**重要**，快速排序的思想，双指针)
* [剑指Offer(二十九)：顺时针打印矩阵](./PrintMatrix/README.md)
* [剑指Offer(三十九)：数组中出现次数超过一半的数字](./MoreThanHalfNumber/README.md)(摩尔投票法，注意判断是否存在超过一半的数字)
* [剑指Offer(四十)：最小的k个数](./KLeastNumbers/README.md)(**重要** 小顶堆)
* [剑指Offer(四十一)：数据流中的中位数](./StreamMedian/README.md)(**重要**,大顶堆+小顶堆)
* [剑指Offer(四十二)：连续子数组的最大和](./GreatestSumOfSubarrays/README.md)(**重要**,动态规划、分治法再做)
* [剑指Offer(四十五)：把数组排成最小的数](./SortArrayForMinNumber/README.md)(sort自定义排序)
* [剑指Offer(四十九)：丑数](./UglyNumber/README.md)(动态规划、小顶堆)
* [剑指Offer(五十一)：数组中的逆序对](./InversePairs/README.md)(归并排序的思想)
* [剑指Offer(五十三)： 数字在排序数组中出现的次数](./NumberOfK/README.md)(二分查找)
* [剑指Offer(五十三)： 0~n-1中缺失的数字](./MissingNumber/README.md)(数学方法：异或, 二分查找)
* [剑指Offer(五十三)： 数组中数值和下标相等的元素](./IntegerIdenticalToIndex/README.md)(数学方法：异或, 二分查找)
* [剑指Offer(五十六)：数组中只出现一次的数字](./NumberAppearingOnce/README.md)（**重要**，lowbit异或，二进制中最低位的1 lowbit = nums & (-num)）
* [剑指Offer(五十六)：数组中唯一只出现一次的数字](./NumbersAppearOnce/README.md)(**重要**，哈希表，位运算)
* [剑指Offer(五十七)： 和为s的两个数字](./TwoNumbersWithSum/README.md)(双指针)
* [剑指Offer(五十七)： 和为S的连续正数序列](./ContinuousSquenceWithSum/README.md)(双指针滑动窗口，根据条件判断low 或者 high 移动)
* [剑指Offer(六十一)： 扑克牌的顺子](./ContinousCards/README.md)
* [剑指Offer(六十二)： 圆圈中最后剩下的数字](./LastNumberInCircle/README.md)(约瑟夫环，(start+m-1)%len(nums)循环, 递归(f(n-1,m) + m) %n;)
* [剑指Offer(六十六)： 构建乘积数组](./ConstuctArray/README.md) 
* [LeetCode(11)：盛最多水的容器](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Container-With-Most-Water/README.md)(**重要**，双指针)
* [LeetCode(41)：缺失的第一个正数](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/First-Missing-Positive/README.md)(**重要**，交换座位法)
* [LeetCode(56)：合并区间](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Merge-Intervals/README.md)(**重要**，先sort再对后边进行合并，！！！！)
* [LeetCode(33)：搜索旋转排序数组](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Search-In-Rotated-Sorted-Array/README.md)(**重要**，二分查找)
* [LeetCode(69)：x 的平方根](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Sqrtx/README.md)(**重要**，二分查找， 注意考虑溢出)
* [LeetCode(81)：搜索旋转排序数组II](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Search-In-Rotated-Sorted-Array-II)(**重要**，二分查找)
* [LeetCode(128)：最长连续序列](./CodingInterviews/LongestConsecutive/README.md)(**重要**，哈希表)
* [LeetCode(287)：寻找重复数](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-The-Duplicate-Number/README.md)(**重要**，快慢指针O(n), 类似判断链表成环)
* [LeetCode(378)：有序矩阵中第K小的元素](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Kth-Smallest-Element-In-A-Sorted-Matrix)(**重要！！**，二分查找)
* [LeetCode(560)：和为K的子数组](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Merge-Intervals/README.md)(**重要**，前缀和)
* [LeetCode(945)：使数组唯一的最小增量](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Minimum-Increment-To-Make-Array-Unique/README.md)(**重要**，线性探测法(压缩))
* [LeetCode(1013)：将数组分成和相等的三个部分](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Partition-Array-Into-Three-Parts-With-Equal-Sum/README.md)(**重要**，sum三等分值)
* [LeetCode(1248)：统计「优美子数组」](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Count-Number-Of-Nice-Subarrays/README.md)(**重要**，滑动窗口、前缀和+哈希)
* [面试题 17.10. 主要元素](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-Majority-Element-Lccii/README.md)(**重要**，摩尔投票法)

### 字符串：
* [剑指Offer(五)：替换空格](./ReplaceSpaces/README.md)(双指针)
* [剑指Offer(十七)：打印从1到最大的n位数](./PrintNumbers/README.md)(大数问题)
* [剑指Offer(十九)：正则表达式匹配](./RegularExpressionsMatching/README.md)(**重要**，回溯，动态规划)
* [剑指Offer(二十)：表示数值的字符串](./NumericStrings/README.md)(模拟法，按实际分情况讨论)
* [剑指Offer(三十八)：字符串的排列](./StringPermutation/README.md)(**重要**，递归DFS)(扩展可以看一下)
* [剑指Offer(四十三)：1~n整数中1出现的次数](./NumberOf1/README.md)(数学归纳，非典型字符串题，只是数字转成字符串可表示数字更大)
* [剑指Offer(四十四)：数字序列中某一位的数字](./FindNthDigit/README.md)(数学模拟)
* [剑指Offer(四十六)：把数字翻译成字符串](./TranslateNum/README.md)(**重要**，动态规划)
* [剑指Offer(五十)：第一个只出现一次的字符 ](./FirstNotRepeatingChar/README.md)(**重要**，哈希表)
* [剑指Offer(五十)：字符流中第一个只出现一次的字符 ](./FirstCharacterInStream/README.md)(**重要**，哈希表)
* [剑指Offer(五十八)：翻转字符串 ](./ReverseWordsInSentence/README.md)(**重要**，1.翻转整个句子 2.翻转单词 3.删除多余空格)
* [剑指Offer(五十八)：左旋转字符串 ](./LeftRotateString/README.md)
* [剑指Offer(六十七)：把字符串转换成整数 ](./StringToInt/README.md)
* [LeetCode(3):无重复字符的最长子串](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Longest_Substring_Without_Repeating_Characters/README.md)(**重要**，双指针滑动窗口+hash)
* [LeetCode(5):最长回文子串](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Longest-Palindromic-Substring/README.md)(**重要**，dp 或者中心扩展)
* [LeetCode(8):字符串转换整数 (atoi)](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/String-To-Integer-Atoi/README.md)(**重要**)
* [LeetCode(516):最长回文子序列](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Longest-Palindromic-Subsequence)(**重要**，子序列dp问题)
* [LeetCode(43):字符串相乘](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Multiply-Strings/README.md)(**重要**，dp问题)
* [LeetCode(44):通配符匹配](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Wildcard-Matching/README.md)
* [LeetCode(76):最小覆盖子串](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Minimum-Window-Substring)(**重要**，滑动窗口模板)
* [LeetCode(409):最长回文串](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Longest-Palindrome/README.md)(**重要**，利用数组哈希char_map[128]提高效率)
* [LeetCode(415):字符串相加](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Add-Strings/README.md)
* [LeetCode(1071):字符串的最大公因子](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Greatest-Common-Divisor-Of-Strings/README.md)(**重要**，gcd最大公约数函数)
* [LeetCode(1160):拼写单词](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-Words-That-Can-Be-Formed-By-Characters/README.md)(**重要**，两个哈希进行比较)
* [面试题01.06:字符串压缩](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Compress-String-Lcci/README.md)(**重要**，双指针)
* [面试题 10.02. 变位词组](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Group-Anagrams-Lcci/README.md)(**重要**，哈希模拟排序)
* [LeetCode：滑动窗口解决字符串子串问题](https://bryceustc.github.io/2020/04/22/%E5%8F%8C%E6%8C%87%E9%92%88%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E7%AE%97%E6%B3%95%E6%80%BB%E7%BB%93/#more)(**重要**，双指针滑动窗口)
### 链表：
* [剑指Offer(六)：从尾到头打印链表](./PrintListInReversedOrder/README.md)(**重要** 递归和非递归法都要掌握)
* [剑指Offer(十八)：删除链表的节点](./DeleteNodeInList/README.md)
* [剑指Offer(十八)：删除链表中重复的节点](./DeleteDuplicatedNode/README.md)(**重要**，递归和非递归法都要掌握，多做几遍加深理解)
* [剑指Offer(二十二)：链表中倒数第k个节点](./KthNodeFromEnd/README.md)(**重要**，直接法，双指针)
* [剑指Offer(二十三)：链表中环的入口节点](./EntryNodeInListLoop/README.md)(**重要**，快慢双指针)
* [剑指Offer(二十四)：反转链表](./ReverseList/README.md)(**重要**，递归和非递归法，递归！递归！递归！)
* [剑指Offer(二十五)：合并两个排序的链表](./MergeSortedLists/README.md)(**重要**，递归与非递归法)
* [剑指Offer(三十五)：复杂链表的复制](./CopyComplexList/README.md)(**重要**，三步法)
* [剑指Offer(五十二)：两个链表的第一个公共节点](./FirstCommonNodesInLists/README.md)(**重要**)
* [LeetCode(23):合并K个排序链表](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Merge-K-Sorted-Lists/README.md)(**重要**，归并排序的思想)
* [LeetCode(25):K 个一组翻转链表](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Reverse-Nodes-In-K-Group/README.md)(**重要**)
* [LeetCode(92):区间翻转单向链表](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Reverse-Nodes-In-K-Group/README.md)(**重要**)
* [LeetCode(234):回文链表](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Palindrome-Linked-List)(**重要**)
* [LeetCode(445):两数相加 II](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Add-Two-Numbers-II)(**重要**)
* [LeetCode(876):链表的中间结点](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Middle-Of-The-Linked-List)(**重要**，快慢双指针)
### 栈和队列：
* [剑指Offer(九)：用两个栈实现队列](./QueueWithTwoStacks/README.md)
* [剑指Offer(三十)：包含min函数的栈](./MinInStack/README.md)(**重要**，利用两个栈，一个数据栈，一个辅助栈存储最小元素)
* [剑指Offer(三十一)：栈的压入、弹出元素](./StackPushPopOrder/README.md)(**重要**，利用一个辅助栈模拟)
* [剑指Offer(五十九)：滑动窗口的最大值](./MaxInSlidingWindow/README.md) (**重要**，利用deque双端队列)
* [剑指Offer(五十九)：队列的最大值](./MaxQueue/README.md) (**重要**，两个队列，一个普通队列正常存取元素，一个deque双端队列存取单调元素)
* [LeetCode(20):有效的括号](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Valid-Parentheses/Valid-Parentheses.cpp)(**重要**，栈的应用)
* [LeetCode(32):最长有效括号](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Longest-Valid-Parentheses/Longest-Valid-Parentheses.cpp)(**重要**，栈的应用)
* [LeetCode(84):柱状图中最大的矩形](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Largest-Rectangle-In-Histogram/README.md)(**重要**，单调栈的应用)
* [LeetCode(155):最小栈](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Min-Stack/README.md)(**重要**)
* [LeetCode(225):用队列实现栈](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Implement-Stack-Using-Queues/README.md)(**重要**)
* [LeetCode单调栈系列问题](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Monotone-Stack)(**重要!!**)
### 树：
* [剑指Offer(七)：重建二叉树](./ConstructBinaryTree/README.md)(**重要**，前序遍历，中序遍历，后序遍历要掌握)
* [剑指Offer(八：二叉树的下一个节点](./NextNodeInBinaryTrees/README.md)(**重要**，中序遍历，分情况讨论)
* [剑指Offer(二十六)：树的子结构](./SubstructureInTree/README.md)(**重要**，递归遍历思想)
* [剑指Offer(二十七)：二叉树的镜像](./MirrorOfBinaryTree/README.md)(**重要**，**递归**)
* [剑指Offer(二十八)：对称的二叉树](./SymmetricalBinaryTree/README.md)(**重要**，写个helper函数，判断是否是对称，分情况确定好递归条件，递归！！！)
* [剑指Offer(三十二)：从上往下打印二叉树](./PrintTreeFromTopToBottom/README.md)(**重要**，层序遍历，利用队列实现)
* [剑指Offer(三十二)：分行从上往下打印二叉树](./PrintTreesInLines/README.md)(**重要**，利用队列实现，递归)
* [剑指Offer(三十二)：之字形打印二叉树](./PrintTreesInZigzag/README.md)(**重要**，利用双端队列实现前取后放，后取前放，！！！)
* [剑指Offer(三十三)：二叉搜索树的后序遍历序列](./SquenceOfBST/README.md)(**重要**，递归的思想，注意下标)
* [剑指Offer(三十四)：二叉树中和为某一值的路径](./PathInTree/README.md)(**重要**，典型带记忆的（&引用）DFS递归方法)
* [剑指Offer(三十六)：二叉搜索树与双向链表](./ConvertBinarySearchTree/README.md)(**重要**，利用中序遍历进行递归)
* [剑指Offer(三十七)：序列化二叉树](./SerializeBinaryTrees/README.md)(**重要**，前序遍历，递归或者队列迭代，要用到字符串分割，推荐使用python)
* [剑指Offer(五十四)：二叉搜索树的第k个结点](./KthNodeInBST/README.md)(**重要**，利用递归 或者迭代(堆)进行中序遍历)
* [剑指Offer(五十五)：二叉树的深度](./TreeDepth/README.md)(**重要**，左右子树**dfs递归** 或者bfs迭代层次遍历)
* [剑指Offer(五十五)：平衡二叉树](./BalancedBinaryTree/README.md)(**重要**，递归，自顶向下或**自底向上**)
* [LeetCode(144):二叉树的前序遍历](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Binary-Tree-Preorder-Traversal/README.md)(**重要**)
* [LeetCode(94):二叉树的中序遍历](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Binary-Tree-Inorder-Traversal/README.md)(**重要**)
* [LeetCode(145):二叉树的后序遍历](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Binary-Tree-Postorder-Traversal/README.md)(**重要**)
* [LeetCode(98):验证搜索二叉树](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Validate-Binary-Search-Tree)(**重要**，中序遍历)
* [LeetCode(108):将有序数组转换为二叉搜索树](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Convert-Sorted-Array-To-Binary-Search-Tree)(**重要**)
* [LeetCode(109):将有序链表转换为二叉搜索树](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Convert-Sorted-List-To-Binary-Search-Tree)(**重要**，快慢指针找链表的中点)
* [LeetCode(104):二叉树的最大深度](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Maximum-Depth-Of-Binary-Tree/README.md)(**重要**，DFS和BFS实现)
* [LeetCode(111):二叉树的最小深度](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Minimum-Depth-Of-Binary-Tree/README.md)(**重要**，DFS和BFS实现)
* [LeetCode(124):二叉树中的最大路径和](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Binary-Tree-Maximum-Path-Sum)(**重要**，递归，max(root, root+left, root+right))
* [LeetCode(199):二叉树的右视图](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Binary-Tree-Right-Side-View)(**重要**，BFS)
* [LeetCode(543):二叉树的直径](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Diameter-Of-Binary-Tree/README.md)(**重要**，利用二叉树的深度公式)
* [LeetCode(563):二叉树的坡度](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Binary-Tree-Tilt)(**重要**)
* [LeetCode(236):二叉树的最近公共祖先](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Lowest-Common-Ancestor-Of-A-Binary-Tree/README.md)(**重要**，分清具体情况)
* [LeetCode(257):二叉树的所有路径](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Binary-Tree-Paths)(前序遍历即可)
* [LeetCode(572):另一个树的子树](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Subtree-Of-Another-Tree/README.md)(**重要**，递归判断，两棵树是否相同)

### 二分：
* [剑指Offer(十一)：旋转数组的最小数字](./MinNumberInRotatedArray/README.md) (二分查找)
* [剑指Offer(五十三)： 数字在排序数组中出现的次数](./NumberOfK/README.md)(二分查找)
* [LeetCode(33)：搜索旋转排序数组](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Search-In-Rotated-Sorted-Array/README.md)(**重要**，二分查找)
* [LeetCode(34)：在排序数组中查找元素的第一个和最后一个位置](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-First-And-Last-Position-Of-Element-In-Sorted-Array/README.md)(**重要**，二分查找)
* [LeetCode(35)：搜索插入位置](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Search-Insert-Position/README.md)(**重要**，二分查找)
* [LeetCode(81)：搜索旋转排序数组II](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Search-In-Rotated-Sorted-Array-II)(**重要**，二分查找)
* [LeetCode(153)：寻找旋转排序数组中的最小值](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-Minimum-In-Rotated-Sorted-Array/README.md)(**重要**，二分查找)
* [LeetCode(154)：寻找旋转排序数组中的最小值II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-Minimum-In-Rotated-Sorted-Array-II/README.md)(**重要**，二分查找)
* [LeetCode(275)：H指数](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/H-Index-II/README.md)
* [LeetCode(374)：猜数字大小](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Guess-Number-Higher-Or-Lower/README.md)
* [LeetCode(410)：分割数组的最大值](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Split-Array-Largest-Sum)(**重要**，二分应用，最小化最大值)
* [LeetCode(852)：山脉数组的峰顶索引](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Peak-Index-In-A-Mountain-Array/README.md)
* [LeetCode(941)：有效的山脉数组](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Valid-Mountain-Array/README.md)
* [LeetCode(1095)：山脉数组中查找目标值](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-In-Mountain-Array/README.md)(**重要**，二分查找)
* [LeetCode(1300)：转变数组后最接近目标值的数组和](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Sum-Of-Mutated-Array-Closest-To-Target/README.md)(**重要**，二分查找)
* [二分算法总结](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Find-First-And-Last-Position-Of-Element-In-Sorted-Array/BinarySearch.md)
### 位运算：
* [剑指Offer(十五)：二进制中1的个数](./NumberOf1InBinary/README.md)(**重要**，n与n-1做&运算）
* [剑指Offer(十六)：数值的整数次方](./Power/README.md)（二分法）
* [剑指Offer(六十四)：求1+2+3+…+n](./Accumulate/README.md)
* [剑指Offer(六十五)：不用加减乘除的加法](./AddTwoNumbers/README.md)（**重要**，异或 和与的结合，(a^b) ^((a&b)<<1) ）
### 动态规划：
* [剑指Offer(十)：斐波那契数列](./Fibonacci/README.md)(**重要**)
* [剑指Offer(十)：跳台阶](./JumpFloor/README.md)(**重要**，注意初始值)
* [剑指Offer(十)：变态跳台阶](./JumpFloorII/README.md)(通项公式数学归纳)
* [剑指Offer(十)：矩形覆盖问题](./RectCover/README.md)(斐波那契数列)
* [剑指Offer(十四)：剪绳子](./CuttingRope/README.md)(**重要**，动规，贪心)
* [剑指Offer(六十)：n个骰子的点数](./Nge/README.md)(**重要**，动规,dp[i][j] += dp[i-1][j-k] k∈[1,6])
* [剑指Offer(六十三)：股票的最大利润](./MaxProfit/README.md)(**重要**，动规)
* [LeetCode(53)：最大子数组](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Maximum-Subarray/README.md)(**重要**，dp[i],res=max(dp[i-1]+nums[i],nums[i]))
* [LeetCode(55)：跳跃游戏](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Jump-Game/README.md)(**重要**，贪心,reach=max(reach,i+nums[i]))
* [LeetCode(45)：跳跃游戏II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Jump-Game-II/README.md)(**重要**，贪心算法)
* [LeetCode(62)：不同路径](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Unique-Paths/README.md)(**重要**，dp[i][j] = dp[i][j-1]+dp[i-1][j]))
* [LeetCode(63)：不同路径 II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Unique-Paths-II/README.md)(**重要**，dp[i][j] = dp[i][j-1]+dp[i-1][j]) or dp[i][j] =0)
* [LeetCode(64)：最小路径和](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Minimum-Path-Sum)(**重要**，dp[i][j] = min(dp[i][j-1], dp[i-1][j],)+grid[i][j])
* [LeetCode(85):柱状图中最大的矩形](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Maximal-Rectangle/README.md)(**重要**，dp)
* [LeetCode(152):乘积最大子数组](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Maximum-Product-Subarray)(**重要**，dp)
* [LeetCode(120)：三角形最小路径和](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Triangle/README.md)(**重要**，自底向上，triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]))
* [LeetCode(221)：最大正方形](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Maximal-Square/README.md)(**重要**，dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])+1)
* [LeetCode(279)：完全平方数](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Perfect-Squares)(**重要**，dp[i] = min(dp[i], 1+dp[i-j\*j])
* [LeetCode(322)：零钱兑换](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Coin-Change/README.md)(**重要**，**重要**，dp[i] = min(dp[i], 1+dp[i-coin])
* [LeetCode(518)：零钱兑换II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Coin-Change-II/README.md)(**重要**，dp[i]+=dp[i-coin])
* [LeetCode：买卖股票的最佳时机系列问题](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Best-Time-To-Buy-And-Sell-Stock-Series)(**重要**，画出状态机理解动态规划)
* [LeetCode(300)：最长上升子序列](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Longest-Increasing-Subsequence/README.md)(**重要**，动态规划 遍历i之前的 dp[i] = max(dp[i], dp[j]+1))
* [LeetCode(516):最长回文子序列](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Longest-Palindromic-Subsequence)(**重要**，子序列dp问题，dp[i][j] = dp[i+1][j-1]+2 && s[i]==s[j], else dp[i][j]=max(dp[i+1][j],dp[i][j-1])
* [LeetCode(72):编辑距离](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Edit-Distance/README.md)(**重要**，dp[i][j] = dp[i-1][j-1]&& word1[i]==word2[j], else dp[i][j]=1 + min(dp[i-1][j-1],dp[i][j-1],dp[i][j-1]))
* [LeetCode(1143):最长公共子序列](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Longest-Common-Subsequence/README.md)(**重要**，LCS，经典dp问题，dp[i][j] = dp[i-1][j-1]+1 && s1[i-1]==s2[j-1], else dp[i][j]=max(dp[i-1][j],dp[i][j-1])
* [LeetCode(674)：长连续递增序列](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Longest-Continuous-Increasing-Subsequence/README.md)(**重要**，双指针or 动态规划 dp[i] = dp[i-1]+1 or dp[i] = 1)
* [LeetCode(887)：鸡蛋掉落](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Super-Egg-Drop/README.md)(**重要**，$dp[i][k]=\min _{1 \leq j \leq i}(\max (d p[j-1][k-1], dp[i-j][k])+1)$)
* [LeetCode(1014)：最佳观光组合](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Best-Sightseeing-Pair)(**重要**，贪心思想，掌握)
* [LeetCode：小偷打家劫舍系列问题](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Best-Time-To-Buy-And-Sell-Stock-Series)(**重要**，画出状态机理解动态规划)
### DFS与BFS：
* [剑指Offer(十二)：矩阵中的路径](./StringPathInMatrix/README.md)(**重要**，dfs)
* [剑指Offer(十三)：机器人的运动范围](./RobotMove/README.md)(**重要**，dfs)
* [LeetCode(39)：组合总和](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Combination-Sum/README.md)(**重要**，dfs)
* [LeetCode(40)：组合总和II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Combination-Sum-II/README.md)(**重要**，dfs)
* [LeetCode(216)：组合总和III](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Combination-Sum-III)(**重要**，dfs)
* [LeetCode(46)：全排列](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Permutations/README.md)(**重要**，dfs)
* [LeetCode(47)：全排列 II ](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Permutations-II/README.md)(**重要**，dfs)
* [LeetCode(51)：n皇后 ](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/N-Queens)(**重要**，dfs)
* [LeetCode(93)：复原IP地址](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Restore-Ip-Addresses/README.md)(**重要**，dfs)
* [LeetCode(130)：被围绕的区域](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Surrounded-Regions/README.md)(**重要**，dfs模板题)
* [LeetCode(133)：克隆图](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Clone-Graph/README.md)(**重要**，图的dfs、bfs，要掌握)
* [LeetCode(200)：岛屿数量](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Number-Of-Islands/README.md)(**重要**，dfs)
* [LeetCode(210)：课程表II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Course-Schedule-II/README.md)(**重要**，拓扑排序，利用BFS实现)
* [LeetCode(289)：生命游戏](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Game-Of-Life/README.md)(**重要**，类似bfs，注意利用状态机00,01,10,11)
* [LeetCode(542)：01矩阵](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/01-Matrix/README.md)(**重要**，bfs)
* [LeetCode(542)：图像渲染](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Flood-Fill/README.md)(**重要**，dfs)
* [LeetCode(695)：岛屿的最大面积](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Max-Area-Of-Island/README.md)(**重要**，dfs)
* [LeetCode(994)：腐烂的橘子](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Rotting-Oranges/README.md)(**重要**，bfs)
* [LeetCode(1162)：地图分析](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/As-Far-From-Land-As-Possible)(**重要**，bfs)
### 其他：
* [剑指Offer(一)：赋值运算符函数&hearts;](./CMyString/README.md)
* [剑指Offer(二)：实现Singleton模式&hearts;](./Singleton/README.md) 
* [LeetCode(365)：水壶问题](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Water-And-Jug-Problem)(**重要**，扩展欧几里得算法，gcd)
* [LeetCode(470)：用 Rand7() 实现 Rand10()](https://github.com/bryceustc/LeetCode_Note/tree/master/cpp/Implement-Rand10-Using-Rand7)(**重要**，经典题)
### 排序：
* [冒泡排序](./Sort/README.md)
* [选择排序](./Sort/README.md)
* [插入排序](./Sort/README.md)（**重要**）
* [归并排序](./Sort/README.md)（**重要**）
* [希尔排序](./Sort/README.md)
* [快速排序](./Sort/README.md)（**重要**）
* [堆排序](./Sort/README.md)（**重要**）
