#include "pch.h"
#include "maximum_depth_of_binary_tree.h"
using namespace std;
int Solution::maxDepth(TreeNode* root) {
if (!root) {
return 0;
}
int maxLeft = maxDepth(root->left);
int maxRight = maxDepth(root->right);
return max(maxLeft, maxRight) + 1;
}