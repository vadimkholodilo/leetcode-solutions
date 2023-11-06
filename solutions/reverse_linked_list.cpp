#include "pch.h"
#include "reverse_linked_list.h"
using namespace std;
ListNode* Solution::reverseList(ListNode* head) {
	if (head == nullptr) {
		return nullptr;
	}
	ListNode* prev = nullptr;
	ListNode* current = head;
	ListNode* next = nullptr;
	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}