#include <iostream>
#include <vector>



 typedef struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  } TNode;

 void insertTNode(TNode*, TNode*);

 TNode* build(std::vector<int>& vec){
	 TNode* root = NULL;
	 for(auto iter=vec.begin();iter!=vec.end();iter++){
		 if(root == NULL){
			root = new TNode(*iter);
		 }else{
			 TNode* t = new TNode(*iter);
			 insertTNode(root, t);
		 }
	 }
	 return root;
 }

void insertTNode(TNode* root, TNode* t){
	 if(root->val > t->val){
		 if(root->left == NULL){
			root->left = t;
		 }else{
			 insertTNode(root->left, t);
		 }
	 }else{
		 if(root->right == NULL){
			 root->right = t;
		 }else{
			 insertTNode(root->right, t);
		 }
	 }
 }

class Solution{
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if( p == NULL && q == NULL) 
			return true;
        if(p == NULL || q == NULL){
				return false;
		}
		if(p->val != q->val) 
			return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

	bool isValidBST(TreeNode* root) {
		std::vector<int> vec;
		wakeTree(root, vec);
		int pre = 0;
		for(auto iter=vec.begin(); iter!=vec.end(); iter++){
			if(iter == vec.begin())
				pre = *iter;
			else{
				if(*iter <= pre) return false;
				pre = *iter;
			}
		}
		return true;
	}

	void wakeTree(TNode* root, std::vector<int>& vec){
		if(root == NULL) return;
		if(root->left != NULL)
			wakeTree(root->left, vec);
		vec.push_back(root->val);
		if(root->right)
			wakeTree(root->right, vec);
	}
};