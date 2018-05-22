#include "solution.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char** argv){
	Solution s;
	std::vector<int> vec1;
	std::vector<int> vec2;

	srand(time(NULL));

	for(int i=0;i<10;i++){
		int tmp = rand()%1000;
		vec1.push_back(tmp);

		tmp = rand()%1000;
		vec2.push_back(tmp);
	}
	TNode* root1 = build(vec1);
	TNode* root2 = build(vec2);
	bool res = s.isSameTree(root1, root2);
	res = s.isValidBST(root1);
	res = s.isValidBST(root2);

	std::cout<<res<<std::endl;

	return 0;
}