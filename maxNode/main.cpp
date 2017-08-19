TreeNode* maxNode(TreeNode* root) {
	// Write your code here
	TreeNode();
	if (root == nullptr)
		return nullptr;
	TreeNode *max_node = root;
	maxCore(root, &max_node);
	return max_node;
}
void maxCore(TreeNode *node, TreeNode **max_node) {
	if (node == nullptr)
		return;
	if (node->val > (*max_node)->val)
		*max_node = node;
	maxCore(node->left, max_node);
	maxCore(node->right, max_node);
}