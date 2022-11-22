#include "queue.h"

QueueP::QueueP() noexcept
{
	head = nullptr;
}

QueueP::QueueP(const QueueP& p) noexcept {
	auto temp = p.head.get();
	while (temp) {
		push(temp->num);
		temp = temp->next.get();
	}
}

QueueP::QueueP(QueueP&& p) noexcept : head(std::move(p.head)) { p.head = nullptr;}

QueueP& QueueP::operator=(QueueP &&p) {
	remove_all();
	head = std::move(p.head);
	p.head = nullptr;
	return *this;
}

QueueP& QueueP::operator=(const QueueP& p)
{
	remove_all();

	auto temp = p.head.get();
	while (temp) {
		push(temp->num);
		temp = temp->next.get();
	}
	return *this;
}

QueueP::~QueueP()
{
	remove_all();
}

void QueueP::remove_all(){
	while (head)
		head = std::move(head->next);
}


void QueueP::push(int data) noexcept {

	if (head == nullptr || data < head.get()->num) {
		head = std::unique_ptr<Node>(new Node{ data, std::move(head) });
	}
	else {
		auto h = head.get();
		while (h->next != nullptr && data >= h->next.get()->num)
			h = h->next.get();
		h->next = std::unique_ptr<Node>(new Node{ data, std::move(h->next) });
	}
}

void QueueP::pop() noexcept
{
	if (head) {
		head = std::move(head.get()->next);
	}
}

int QueueP::top()
{
	if (head) {
		return head.get()->num;
	}
	else {
		throw std::out_of_range("Nullptr");
	}
}

std::vector<int> QueueP::drop()
{
	std::vector<int> vec;
	auto h = head.get();
	while (h) {
		vec.push_back(h->num);
		h = h->next.get();
	}
	return vec;
}

void QueueP::print() noexcept {
	auto h = head.get();
	while (h) {
		std::cout << h->num << " ";
		h = h->next.get();
	}

}
//------------------------------------------------------

void print(std::vector<int> const& input)
{
	for (auto const& i : input) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

QueueP init(int data)
{
	QueueP temp;
	temp.push(data);
	return temp;
}


void random(std::vector<int>& vec, QueueP& p, int& size) {
	for (int i = 0; i < size; i++) {
		int r = rand() % 1000;
		vec[i] = r;
		p.push(r);
	}
	std::sort(vec.begin(), vec.end());

}