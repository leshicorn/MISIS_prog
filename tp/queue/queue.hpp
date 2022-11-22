#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>

class QueueP
{
public:
	QueueP() noexcept;
	QueueP(const QueueP& p) noexcept;
	QueueP(QueueP&& p) noexcept;
	QueueP& operator=(const QueueP& p);
	QueueP& operator=(QueueP &&p);
	~QueueP();

	void push(int data) noexcept;
	void print() noexcept;
	void pop() noexcept;
	const int& top() const ;

	std::vector<int> drop();

	friend std::ostream& operator<<(std::ostream& os, QueueP& p) {
		auto h = p.head.get();
		while (h) {
			h->next ? os << h->num << " " : os << h->num;
			h = h->next.get();
		}
		return os;
	};

	friend std::istream& operator>>(std::istream& is, QueueP& p) {
		int n = 0;
		while (is >> n) {
			p.push(n);
			if (is.get() == '\n') {
				is.setstate(std::ios::failbit);
			}
		}
		return is;
	};

private:
	struct Node {
		int num;
		std::unique_ptr<Node> next;
	};
	std::unique_ptr<Node> head;
	void remove_all();
};

void random(std::vector<int>& vec, QueueP& p, int& size);
void print(std::vector<int> const& input);
QueueP init(int data);

#endif