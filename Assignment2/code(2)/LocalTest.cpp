#include "assign2.cpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compare(uint64_t a, uint64_t b) {
	return a - b;
}

class LocalTest {
public:
	//���Ա���
	const int N = -10e7;
	const int E = -10e6;
	const int Q = -10e5;
	BST b;
	tree_node* t1 = nullptr;
	tree_node* t2 = nullptr;
	tree_node *tree_p = nullptr;
	tree_node **tree_pp = nullptr;
	vector<vector<int>> input01 = { {1},{2,3},{4,5,6,7},{8,9,10,11,12,13,14,15} };
	vector<vector<int>> input02 = { {5},{3,9},{2,4,7,12},{1,N,N,N,6,8,11,13} };

	LocalTest() {
		tree_node *root = deserialize(input02);
		b.root = root;
		b.comp = compare;
		tree_p = create_new_node(N);
		tree_pp = &tree_p;
		serialize(b.root);
		cout << endl;
	}

	~LocalTest() { delete tree_p; }

	tree_node* create_new_node(int c) {
		tree_node *t = new tree_node;
		t->data = c;
		t->l_child = nullptr;
		t->r_child = nullptr;
		t->father = nullptr;
		return t;
	}
	//======================  չ��������  ======================
	vector<vector<int>> serialize(tree_node* root) {
		vector<vector<int>> data;
		helper(root, data, 0);
		data.pop_back();
		cout << endl;
		int n = data.size();
		for (int i = 0; i < n; i++) {
			int m = data[i].size();
			for (int j = 0; j < m; j++) {
				if (data[i][j] == N)cout << "null" << "  ";
				else cout << data[i][j] << "  ";
			}
			cout << endl;
		}
		return data;
	}
	void helper(tree_node* root, vector<vector<int>> &data, int floor) {
		if (data.size() < floor + 1) {
			vector<int> t;
			data.push_back(t);
		}
		if (root == NULL) {
			data[floor].push_back(N);
			return;
		}
		int curr = root->data;
		data[floor].push_back(curr);
		helper(root->l_child, data, floor + 1);
		helper(root->r_child, data, floor + 1);
	}
	//=========================  �����ж�����  ========================
	tree_node* deserialize(vector<vector<int>> &data) {
		int n = data.size();
		vector<int> fs(n, 0);
		return build(0, fs, data, nullptr);
	}
	tree_node* build(int floor, vector<int> &fs, vector<vector<int>> &data, tree_node *father) {
		if (floor >= data.size() || fs[floor] >= data[floor].size())return nullptr;
		int value = data[floor][fs[floor]++];
		if (value == N)return nullptr;
		tree_node* new_tree_node = create_new_node(N);
		new_tree_node->father = father;
		new_tree_node->data = value;
		new_tree_node->l_child = build(floor + 1, fs, data, new_tree_node);
		new_tree_node->r_child = build(floor + 1, fs, data, new_tree_node);
		return new_tree_node;
	}
	//=========================  ����̨�������������  ========================
	vector<vector<int>> input_data() {
		cout << "����������Ľṹ�����н�����һ��\n����:(Q ����),(E ����),(N �սڵ�)" << endl;
		vector<vector<int>> res;
		int floor = 0;
		char c[8] = "" ;
		while (true) {
			if (floor >= res.size()) {
				vector<int> t;
				res.push_back(t);
			}
			cin >> c;
			if (c[0] == 'Q')break;
			else if (c[0] == 'E')floor++;
			else if (c[0] == 'N')res[floor].push_back(N);
			else { 
				int value;
				sscanf_s(c, "%d", &value);
				res[floor].push_back(value); 
			}
		}
		return res;
	}
	//=======================  ����ֵ���  ======================
	bool printException(assign2_exception::exception e) {
		if (e & NULL_POINTER_EXCEPTION)           cout << "�����쳣��NULL_POINTER_EXCEPTION" << endl;
		if (e & DUPLICATED_LEFT_CHILD_EXCEPTION)  cout << "�����쳣��DUPLICATED_LEFT_CHILD_EXCEPTION" << endl;
		if (e & DUPLICATED_RIGHT_CHILD_EXCEPTION) cout << "�����쳣��DUPLICATED_RIGHT_CHILD_EXCEPTION" << endl;
		if (e & DUPLICATED_FATHER_EXCEPTION)      cout << "�����쳣��DUPLICATED_FATHER_EXCEPTION" << endl;
		if (e & INVALID_CHILD_DIRECTION_EXCEPTION)cout << "�����쳣��INVALID_CHILD_DIRECTION_EXCEPTION" << endl;
		if (e & ROOTS_FATHER_EXCEPTION)           cout << "�����쳣��ROOTS_FATHER_EXCEPTION" << endl;
		if (e & NULL_COMP_FUNCTION_EXCEPTION)     cout << "�����쳣��NULL_COMP_FUNCTION_EXCEPTION" << endl;
		if (e & SPLAY_NODE_NOT_IN_TREE_EXCEPTION) cout << "�����쳣��SPLAY_NODE_NOT_IN_TREE_EXCEPTION" << endl;
		return e;
	}
	//=======================  ����ģ��  ======================
	void test01() {
		cout << "���Ե�һ��" << endl;
		int c1, c2, c3;
		cout << "����ֵѡȡ���ڵ�:"; cin >> c1;
		printException(find_in_BST(&b, c1, tree_pp));
		t1 = tree_p;
		cout << "\n���ӵ���������0�������ӵ���������1��:"; cin >> c2;
		cout << "���뺢�ӽڵ��ֵ: "; cin >> c3;
		t2 = create_new_node(c3);
		bool b = !c2 ? printException(ADD_NODE_LEFT(t1, t2)) : printException(ADD_NODE_RIGHT(t1, t2));
		if (!b) { cout << "\n���´˸��ڵ�:" << endl; serialize(t1); }
	}
	void test02() {
		cout << "���Եڶ���:" << endl;
		int c1 = 0, res = 0;
		cout << "����ֵѡ��ڵ�:"; cin >> c1;
		printException(find_in_BST(&b, c1, tree_pp));
		printException(judge_child_direction(tree_p, &res));
		if (res == CHILD_DIRECTION_LEFT)cout << "�ýڵ�Ϊ��ڵ�" << endl;
		else cout << "�ýڵ�Ϊ�ҽڵ�" << endl;
	}
	void test03() {
		cout << "���Ե�����:" << endl;
		int c;
		cout << "�������Ľڵ�ֵ:"; cin >> c;
		printException(insert_into_BST(&b, c, tree_pp));
		cout << "����֮��Ķ�����:" << endl;
		serialize(b.root);
	}
	void test04() {
		cout << "���Ե�����:" << endl;
		int c;
		cout << "����target:"; cin >> c;
		printException(find_in_BST(&b, c, tree_pp));
		cout << "�ýڵ�ṹΪ:" << endl;
		serialize(tree_p);
	}
	void test05() {
		cout << "���Ե�����:" << endl;
		int c;
		cout << "ѡ�����ת�Ľڵ�ֵ:"; cin >> c;
		printException(find_in_BST(&b, c, tree_pp));
		printException(splay(&b, tree_p));
		cout << "����֮��Ķ�����:" << endl;
		serialize(b.root);
	}
	void freeTest() {

	}
};

int main() {
	cout << "ԭ������:";
	LocalTest l;
	l.test05();
	return 0;
}