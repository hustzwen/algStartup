#include <vector>
#include <iostream>

namespace algstartup{

using std::vector;

class UnionFind{
public:

UnionFind (int n){
	m_size = n;
	m_parent.reserve(n);
	m_weight.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		m_parent.push_back(i);
		m_weight.push_back(1);
	}
}

int find(int x);

int size() {return m_size;}

bool connected(int p, int q);

void union_elem(int p, int q);

private:
	int m_size;
	vector<int> m_parent;
	vector<int> m_weight;
};

int UnionFind::find(int x){
	while (m_parent[x] != x) // x == parent[x]
	{
		// 路径压缩
		m_parent[x] = m_parent[m_parent[x]];
		x = m_parent[x];
	}
	return x;
}

bool UnionFind::connected(int p, int q){
	return find(p) == find(q);
}

void UnionFind::union_elem(int p, int q){
	int rootP = find(p);
	int rootQ = find(q);
	if(rootP == rootQ) return;

	// 小树接到大树下
	if(m_weight[rootP] > m_weight[rootQ]){
		m_parent[rootQ] = rootP;
		m_weight[rootP] += m_weight[rootQ];
	}else
	{
		m_parent[rootP] = rootQ;
		m_weight[rootQ] += m_weight[rootP];
	}
	--m_size;
}

}


using namespace algstartup;
int main(int argc, char** argv){

	UnionFind uf(10);
	uf.union_elem(1, 3);
	uf.union_elem(3, 9);
	uf.union_elem(5, 7);
	uf.union_elem(7, 1);

	std::cout << "1, 9 connected: " << uf.connected(1, 9) << std::endl;
	std::cout << "5 parent is: " << uf.find(5) << std::endl;


	system("pause");
	return 0;
}