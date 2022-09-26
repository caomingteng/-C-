#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

//构造节点
struct Node
{
	int val;
	Node* next;
	
	//构造函数
	Node(int v)
	{
		val = v;
		next = NULL;
	}
};

class Queue
{
	int size;
	Node* head;
	Node* tail;
public:
	Queue()
	{
		size = 0;
		head = tail = NULL;
	}
	//判断是否为空
	bool empty()
	{
		return size == 0;
	}
	
	//加入几个元素
	/*int size()
	{
		return size;
	}
	*/

	void offer(int v)
	{
		Node* cur = new Node(v);	//新进来的节点
		//判断在该节点之前是否有节点
		if (tail == NULL)
		{
			head = cur;
			tail = cur;
		}
		else
		{
			tail->next = cur;
			tail = cur;
		}
		size++;
	}
	//弹出节点
	int pop()
	{
		int ans = NULL;
		if (head != NULL)
		{
			ans = head->val;
			Node* temp = head;
			head = head->next;
			delete temp;	//释放前一个节点
			size--;
		}
		if (head == NULL)
		{
			tail = NULL;
		}
		return ans;
	}
	//只要某一节点的值，并非真弹出
	int peek()
	{
		int ans = NULL;
		if (head != NULL)
		{
			ans = head->val;
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		return ans;
	}
};

void test_queue()
{
	Queue queue;
	int n;
	cout << "请输入队列的节点数：" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cout << "请输入当前节点的值：" << endl;
		cin >> temp;
		queue.offer(temp);
	}
	cout << "将队列返回如下" << endl;
	//在使用字节点时需要先判断是否为空
	while (queue.empty() == false)
	{
		cout<<queue.pop()<<endl;
	}
}

int main()
{
	test_queue();
	system("pause");
	return 0;
}
