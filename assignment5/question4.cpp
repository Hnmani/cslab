#include <iostream>
#include <algorithm>

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Decision
{
public:
    int robRoot, notRobRoot;

    Decision(int robRoot, int notRobRoot) : robRoot(robRoot), notRobRoot(notRobRoot) {}
};

Decision robDecision(TreeNode *root)
{
    if (!root)
        return Decision(0, 0);

    Decision left = robDecision(root->left);
    Decision right = robDecision(root->right);

    return Decision(root->val + left.notRobRoot + right.notRobRoot,
                    std::max(left.robRoot, left.notRobRoot) + std::max(right.robRoot, right.notRobRoot));
}

int rob(TreeNode *root)
{
    Decision decision = robDecision(root);
    return std::max(decision.robRoot, decision.notRobRoot);
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    std::cout << "Maximum amount of money robbed = " << rob(root) << std::endl;

    return 0;
}
