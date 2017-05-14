class Solution {
public:
	/**
	* @param node: a node in the list should be deleted
	* @return: nothing
	*/
	void deleteNode(ListNode *node) {
		// write your code here
		if (node == nullptr || node->next == nullptr)
			return;
		ListNode *tmp = node->next;
		node->val = tmp->val;
		node->next = tmp->next;
		delete[]tmp;
	}
};