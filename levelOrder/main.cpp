vector<vector<int>> levelOrder(TreeNode *root) {
	// write your code here
	if (root == nullptr)
		return{};
	vector<vector<int>> ret;
	queue<TreeNode*> qTree;

	qTree.push(root);
	while (!qTree.empty()) {
		vector<int> val;
		int qSize = qTree.size();
		for (int i = 0; i < qSize; i++) {
			TreeNode *tmp = qTree.front();
			qTree.pop();
			val.push_back(tmp->val);
			if (tmp->left) {
				qTree.push(tmp->left);
			}
			if (tmp->right) {
				qTree.push(tmp->right);
			}
		}
		ret.push_back(val);
	}
	return ret;
}