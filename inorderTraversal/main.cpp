vector<int> inorderTraversal(TreeNode *root) {
	// write your code here
	if (root == nullptr)
		return{};
	vector<int> order;
	inorderCore(root, order);
	return order;
}
void inorderCore(TreeNode *node, vector<int> &order) {
	if (node == nullptr)
		return;
	inorderCore(node->left, order);
	order.push_back(node->val);
	inorderCore(node->right, order);
}