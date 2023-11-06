#include "pch.h"
#include "maximum_depth_of_binary_tree.h"
using namespace std;
namespace LeetcodeSolutions {
	TEST(MaximumDepthOfBinaryTree, ShouldReturn0IfRootIsNull) {
		TreeNode* root = nullptr;
		int expected = 0;
		int actual = Solution().maxDepth(root);
		EXPECT_EQ(expected, actual);
	}

	TEST(MaximumDepthOfBinaryTree, ShouldReturn1IfRootDoesnotHaveAnyChildren) {
		TreeNode* root = new TreeNode(1);
		int expected = 1;
		int actual = Solution().maxDepth(root);
		EXPECT_EQ(expected, actual);
	}
	TEST(MaximumDepthOfBinaryTree, ShouldReturn3) {
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		root->right->left = new TreeNode(4);
		root->right->right = new TreeNode(5);
		int expected = 3;
		int actual = Solution().maxDepth(root);
		EXPECT_EQ(expected, actual);
	}
}