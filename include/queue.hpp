#include <iostream>

template <typename T>
class queue_t
{
private:
	struct node_t {
		node_t * next;
		T value;
	};
private:
	node_t * head;
	node_t * tail;
public:
	queue_t() {
		head = nullptr;
		tail = nullptr;
	}
	
	queue_t(queue_t<T> const & other) : queue_t()
	{
		for (auto it = other.head_; it; it = it->next)
		{
			push(it->value);
		}

	}
	
	~queue_t() {
		while (head) {
			node_t * p = head;
			head = head->next;
			delete p;
		}
	}
	node_t * push(T val) {
		if (!head) {
			head = new node_t;
			head->next = nullptr;
			head->value = val;
			tail = head;
		}
		else {
			tail->next = new node_t;
			tail = tail->next;
			tail->value = val;
			tail->next = nullptr;
		}
		return tail;
	}

	T pop() {	
		T a;
			if (head) {
				node_t * oldhead = head;
				head = head->next;
				a = oldhead->value;
				delete oldhead;
				if (!head) {
					tail = nullptr;
				}
			}
			else {
				throw std::logic_error("void head");
			}	
			return a;
	}

	node_t * heads() {
		return head;
	}
	node_t * tails() {
		return tail;
	}

	queue_t<T> & operator =(queue_t<T> & other) {
		if (other.head) {
			this->~queue_t();
		}
		node_t * p = other.heads();
		while (p) {
			push(p->value);
			p = p->next;
		}
		return *this;
	}

	void print(std::ostream & ostream) {
		node_t * p = head;
		while (p) {
			ostream << p->value << ' ';
			p = p->next;
		}
		ostream << '\n';
	}
};
