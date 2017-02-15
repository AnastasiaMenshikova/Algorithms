class Stack 
{
	struct node
	{
		int value;
		node *next;
	};
	node *top;

public:
	Stack();
	~Stack();
	
	int push(int);		
	int pop();			
	bool Search(int key);
	void Del();
	void RandPush(int kol, int range);
	void Clear();
	typedef Node* iterater;
	iterater getTop();
	iterater getNext(iterater a);
	int getInf(iterater a);
	bool Isempty();
};
