/*
** Author: Yangyang Liu
** Date: 2022-08-06
** Description: 912. 排序数组
** link: https://leetcode.cn/problems/sort-an-array/
** reference: 
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void bubbleSort(vector<int>& nums) {
        // 异常情况
        if (nums.size() <= 1) {
            return;
        }

        // 外层for循环控制循环的次数为nums.size() - 1 次
        for (int i = nums.size() - 1; i > 0; i--) {
            // 内层for循环从0开始到i结束，每次循环都把最大的数放到最后
            for (int j = 0; j < i; j++) {
                // 如果前面的数比后面的数大，就交换两个数的位置
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }

    void selectionSort(vector<int>& nums) {
        // 异常情况
        if (nums.size() <= 1) {
            return;
        }

        // 外层for循环控制循环的次数为nums.size() - 1 次
        for (int i = nums.size() - 1; i > 0; i--) {
            // 定义一个变量保存最大值的下标
            int maxIndex = 0;
            // 内层for循环从0开始到i（包括i）结束，每次循环都把最大的数放到最后
            for (int j = 0; j <= i; j++) {
                // 不断记录最大值的位置索引
                if (nums[j] > nums[maxIndex]) {
                    maxIndex = j;
                }
            }
            // 交换最大值和最后一个数的位置
            swap(nums[maxIndex], nums[i]);
        }
    }

    // 构建大顶堆的仿函数
    class Cmp {
    public:
        bool operator()(int a, int b) {
            return a < b;
        }
    };

    void heapSort(vector<int>& nums) {
        // 异常情况
        if (nums.size() <= 1) {
            return;
        }

        // 构建大顶堆
        priority_queue<int, vector<int>, Cmp> pri_que;

        // 把数组中的元素依次放入堆中
        for (int i = 0; i < nums.size(); i++) {
            pri_que.push(nums[i]);
        }

        // 依次从堆中取出元素放入数组中
        for (int i = nums.size() - 1; i >= 0; i--) {
            nums[i] = pri_que.top();
            pri_que.pop();
        }
    }

    void insertionSort(vector<int>& nums) {
        // 异常情况
        if (nums.size() <= 1) {
            return;
        }

        // for循环从1开始遍历，第一个数（索引为0）默认是有序的
        for (int begin = 1; begin < nums.size(); begin++) {
            int cur = begin;
            while (cur > 0 && nums[cur] < nums[cur - 1]) {
                swap(nums[cur], nums[cur - 1]);
                cur--;
            }
        }
    }

    vector<int> shellStepSequence(vector<int>& nums) {
        // 定义一个vector保存步长序列
        vector<int> stepSequence;
        int step = nums.size();

        // 步长序列
        while((step >>= 1) > 0) {
            stepSequence.push_back(step);
        }

        return stepSequence;
    }

    void insertionSortForEachColumn(vector<int>& nums, int step) {
        // 对第col列进行排序
        for (int col = 0; col < step; col++) {
            // 对每一列进行插入排序，col，col + step，col + 2 * step，col + 3 * step
            for (int begin = col + step; begin < nums.size(); begin += step) {
                int cur = begin;
                while (cur > col && nums[cur] < nums[cur - step]) {
                    swap(nums[cur], nums[cur - step]);
                    cur -= step;
                }
            }
        }
    }

    void shellSort(vector<int>& nums) {
        // 定义步长序列
        vector<int> stepSequence = shellStepSequence(nums);

        // for循环每次处理一个步长序列
        for (int i = stepSequence.size() - 1; i >= 0; i--) {
            // 使用插入排序，分成step列进行排序
            insertionSortForEachColumn(nums, stepSequence[i]);
        }
    }

    int pivotIndex(vector<int>& nums, int begin, int end) {
        // 备份begin位置的元素
        int pivot = nums[begin];

        // end指向最后一个元素
        end--;

        // 循环结束条件是begin == end
        while (begin < end) {
            while (begin < end) {
                // 右边元素 > 轴点元素
                if (pivot < nums[end]) { 
                    end--;
                // 右边元素 <= 轴点元素
                } else {
                    nums[begin++] = nums[end];
                    break; // 此时该调换左边元素了
                }
            }
            
            while (begin < end) {
                // 左边元素 < 轴点元素
                if (pivot > nums[begin]) {
                    begin++;
                // 左边元素 >= 轴点元素
                } else {
                    nums[end--] = nums[begin];
                    break; // 此时该调换右边元素了
                }
            }
        }

        // 把轴点元素放入最终的位置
        nums[begin] = pivot;

        // 返回轴点元素的位置
        return begin;
    }

    void quickSortKernel(vector<int>& nums, int begin, int end) {
        // 异常情况，这儿异常判断必须有，而且必须在这个位置，保证是有效区间，否则报segmentation错误
        // 这儿不能使用nums.size() <= 1，因为nums是不变的，变的是它的区间
        if (end - begin < 2) {
            return;
        }

        // 确定轴点位置，构造出 [begin, end) 范围的轴点元素
        int mid = pivotIndex(nums, begin, end);

        // 对子序列进行快速排序
        quickSortKernel(nums, begin, mid);
        quickSortKernel(nums, mid + 1, end);
    }

    void quickSort(vector<int>& nums) {
        // 这儿不用判断异常情况，因为quickSortKernel函数中已经判断了

        // 对 [begin, end) 范围的元素快速排序
        quickSortKernel(nums, 0, nums.size());
    }

    void merge(vector<int>& nums, int begin, int mid, int end) {
        int li = 0;
        int le = mid - begin;
        int ri = mid;
        int re = end;
        int ai = begin;

        // 备份左边数组
        for (int i = li; i < le; i++) {
            leftArray[i] = nums[begin + i];
        }

        // 如果左边还没有结束
        while (li < le) {
            if (ri < re && (nums[ri] < leftArray[li])) {
                nums[ai++] = nums[ri++];
            } else {
                nums[ai++] = leftArray[li++];
            }
        }
    }

    void mergeSortKernel(vector<int>& nums, int begin, int end) {
        // 异常情况
        if (end - begin < 2) {
            return;
        }

        // 确定中间位置
        int mid = (begin + end) >> 1;

        // 对左边进行归并排序
        mergeSortKernel(nums, begin, mid);

        // 对右边进行归并排序
        mergeSortKernel(nums, mid, end);

        // 归并，把[begin, mid)和[mid, end)范围的序列合并成一个有序序列
        merge(nums, begin, mid, end);
    }

    vector<int> leftArray;

    void mergeSort(vector<int>& nums) {
        leftArray = vector<int>(nums.size() >> 1);
        mergeSortKernel(nums, 0, nums.size());
    }

    void mergeSecondEdition(vector<int>& nums, int begin, int mid, int end) {
        // 定义left指向左区间，right指向右区间，index指向临时数组
        int left = begin;
        int right = mid;
        int index = 0;

        // 合并两个区间
        while (left < mid && right < end) {
            if (nums[left] <= nums[right]) { // 如果左边元素小于等于右边，则把左边的复制到临时数组
                vec[index++] = nums[left++];
            } else { // 如果左边元素大于右边，则把右边的复制到临时数组
                vec[index++] = nums[right++];
            }
        }

        // 把左边剩余的复制到临时数组
        while (left < mid) {
            vec[index++] = nums[left++];
        }

        // 把右边剩余的复制到临时数组
        while (right < end) {
            vec[index++] = nums[right++];
        }

        // 把临时数组复制到原数组
        //for (int i = 0; i < (end - begin); i++) {
        //    nums[i + begin] = vec[i];
        //}

        // 把临时数组赋值到原来的数组，这个版本的容易理解
        for (int i = begin; i < end; i++) {
            nums[i] = vec[i - begin];
        }
    }

    void mergeSortKernelSecondEdition(vector<int>& nums, int begin, int end) {
        // 异常情况
        if (end - begin < 2) {
            return;
        }

        // 确定中间位置
        int mid = (begin + end) >> 1;

        // 对左边进行归并排序
        mergeSortKernelSecondEdition(nums, begin, mid);

        // 对右边进行归并排序
        mergeSortKernelSecondEdition(nums, mid, end);

        // 归并，把[begin, mid)和[mid, end)范围的序列合并成一个有序序列
        mergeSecondEdition(nums, begin, mid, end);
    }

    vector<int> vec;

    void mergeSortSecondEdition(vector<int>& nums) {
        vec = vector<int>(nums.size());
        mergeSortKernelSecondEdition(nums, 0, nums.size());
    }

    vector<int> sortArray(vector<int>& nums) {
        //bubbleSort(nums);
        //selectionSort(nums);
        //heapSort(nums);
        //insertionSort(nums);
        //shellSort(nums);
        //quickSort(nums);
        //mergeSort(nums);
        mergeSortSecondEdition(nums);
        return nums;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {5, 2, 3, 1};

    cout << "nums:" << endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    Solution s;
    vector<int> res = s.sortArray(nums);

    cout <<"The sorted array is: " << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}