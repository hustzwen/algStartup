#include <iostream>
#include <vector>

namespace algstartup{

using std::vector;

template <typename T>
class Heap{
public:
	Heap(vector<T> &arg){
		m_data = arg;
		m_size = static_cast<int>(arg.size());
		build_heap();
	}

int left(int i) {return 2 * i + 1;}
int right(int i) {return 2 * i + 2;}
int size() {return m_size;}
vector<T> data() {return m_data;}
void print() {
	for(auto val:m_data){
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

void sort();
void push(T val);
void pop();

void build_heap();
void heapify(int idx);
void heapify(int size, int idx);

private:
	int m_size;
	vector<T> m_data;
};

template <typename T>
void Heap<T>::build_heap(){
	// 从倒数第一个非叶子节点开始堆化
	for(int i = m_size / 2 - 1; i >= 0; i--){
		heapify(i);
	}
}

template <typename T>
void Heap<T>::heapify(int idx){
	int largest = idx, l = left(idx), r = right(idx);
	if(l < m_size && m_data[l] > m_data[largest]) largest = l;
	if(r < m_size && m_data[r] > m_data[largest]) largest = r;
	// 当前不是最大
	if(largest != idx){
		std::swap(m_data[largest], m_data[idx]);
		heapify(largest);
	}
}

template <typename T>
void Heap<T>::heapify(int size, int idx){
	int largest = idx, l = left(idx), r = right(idx);
	if(l < size && m_data[l] > m_data[largest]) largest = l;
	if(r < size && m_data[r] > m_data[largest]) largest = r;
	// 当前不是最大
	if(largest != idx){
		std::swap(m_data[largest], m_data[idx]);
		heapify(size, largest);
	}
}

template <typename T>
void Heap<T>::sort(){
	int k = m_size;
	while (k > 0) // stop condition k == 0, 只剩一个元素时完成排序
	{
		std::swap(m_data[0], m_data[k-1]);
		--k;
		heapify(k, 0);
	}
}

template <typename T>
void Heap<T>::push(T val){
	m_data.push_back(val);
	m_size = static_cast<int>(m_data.size());
	int k = m_size - 1;
	while (k/2 >= 0 && m_data[k] > m_data[k/2])
	{
		std::swap(m_data[k], m_data[k/2]);
		k = k / 2;
	}
	heapify(k);
}

template <typename T>
void Heap<T>::pop(){
	if(m_size == 0) return;
	m_data[0] = m_data[m_size-1];
	--m_size;
	m_data.pop_back();
	heapify(0);
}

}


using namespace algstartup;
int main(int argc, char** argv){
	
	int size = 10;
	vector<int> nums(10, 0);
	for (int k = 0; k < size; k++)
	{
		nums[k] = k + 1;
	}

	Heap<int> maxHeap(nums);
	maxHeap.print();
	maxHeap.pop();
	maxHeap.print();
	maxHeap.push(12);
	maxHeap.print();
	maxHeap.sort();
	maxHeap.print();

	system("pause");
	return 0;
}