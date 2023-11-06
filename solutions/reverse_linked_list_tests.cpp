#include "pch.h"
#include "reverse_linked_list.h"
using namespace std;
namespace LeetcodeSolutions {
	TEST(ReverseLinkedList, ShouldReturnNullIfHeadIsNull) {
		ListNode* head = nullptr;
		ListNode* result = Solution().reverseList(head);
		EXPECT_EQ(result, nullptr);
	}

	TEST(ReverseLinkedList, ShouldReturnHeadIfHeadIsTheOnlyNode) {
		ListNode* head = new ListNode(1);
		ListNode* result = Solution().reverseList(head);
		EXPECT_EQ(result->val, 1);
		EXPECT_EQ(result->next, nullptr);
	}

	TEST(ReverseLinkedList, ShouldReturnReversedList) {
		ListNode* head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(3);

		ListNode* result = Solution().reverseList(head);
		EXPECT_EQ(result->val, 3);
		EXPECT_EQ(result->next->val, 2);
		EXPECT_EQ(result->next->next->val, 1);
		EXPECT_EQ(result->next->next->next, nullptr);
	}
}