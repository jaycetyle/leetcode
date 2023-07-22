#pragma once
#include <gtest/gtest.h>

#include <vector>
#include <limits>

#include "tree_node.h"

// Tree root will be the index 0
class IsValidBSTTestCaseFactory {
 public:
  // valid bst
  std::vector<TreeNode> create_valid_bst_1() {
    //    0
    //   / \
    // -1   1
    std::vector<TreeNode> output = {
      TreeNode(0),
      TreeNode(-1),
      TreeNode(1)
    };

    output[0].left = &output[1];
    output[0].right = &output[2];

    return output;
  }

  std::vector<TreeNode> create_valid_bst_2() {
    //     0
    //    /
    //  -1
    //  /
    //-2
    std::vector<TreeNode> output = {
      TreeNode(0),
      TreeNode(-1),
      TreeNode(-2)
    };

    output[0].left = &output[1];
    output[1].left = &output[2];

    return output;
  }

  std::vector<TreeNode> create_valid_bst_3() {
    //     0
    std::vector<TreeNode> output = {
      TreeNode(0)
    };
    return output;
  }

  std::vector<TreeNode> create_valid_bst_4() {
    //     0
    //    / \
    //  -1   2
    //      /
    //     1
    std::vector<TreeNode> output = {
      TreeNode(0),
      TreeNode(-1),
      TreeNode(2),
      TreeNode(1)
    };

    output[0].left = &output[1];
    output[0].right = &output[2];
    output[2].left = &output[3];

    return output;
  }

  std::vector<TreeNode> create_valid_bst_5() {
    //  INT_MIN
    //      \
    //     INT_MAX
    std::vector<TreeNode> output = {
      TreeNode(std::numeric_limits<int32_t>::min()),
      TreeNode(std::numeric_limits<int32_t>::max())
    };

    output[0].right = &output[1];

    return output;
  }

  std::vector<TreeNode> create_valid_bst_6() {
    //    INT_MAX
    //     /
    //  INT_MIN
    std::vector<TreeNode> output = {
      TreeNode(std::numeric_limits<int32_t>::max()),
      TreeNode(std::numeric_limits<int32_t>::min())
    };

    output[0].left = &output[1];

    return output;
  }

  // invalid bst
  std::vector<TreeNode> create_invalid_bst_1() {
    //     0
    //    / \
    //  -1  -2
    std::vector<TreeNode> output = {
      TreeNode(0),
      TreeNode(-1),
      TreeNode(-2)
    };

    output[0].left = &output[1];
    output[0].right = &output[2];

    return output;
  }

  std::vector<TreeNode> create_invalid_bst_2() {
    //     0
    //    / \
    //  -1   0
    std::vector<TreeNode> output = {
      TreeNode(0),
      TreeNode(-1),
      TreeNode(0)
    };

    output[0].left = &output[1];
    output[0].right = &output[2];

    return output;
  }

  std::vector<TreeNode> create_invalid_bst_3() {
    //     0
    //      \
    //       1
    //      /
    //     -1
    std::vector<TreeNode> output = {
      TreeNode(0),
      TreeNode(1),
      TreeNode(-1)
    };

    output[0].right = &output[1];
    output[1].left = &output[2];

    return output;
  }

  std::vector<TreeNode> create_invalid_bst_4() {
    //     0
    //      \
    //       3
    //      / \
    //     1   2
    std::vector<TreeNode> output = {
      TreeNode(0),
      TreeNode(3),
      TreeNode(1),
      TreeNode(2)
    };

    output[0].right = &output[1];
    output[1].left = &output[2];
    output[1].right = &output[3];

    return output;
  }

  std::vector<TreeNode> create_invalid_bst_5() {
    //    INT_MIN
    //     /
    //  INT_MAX
    std::vector<TreeNode> output = {
      TreeNode(std::numeric_limits<int32_t>::min()),
      TreeNode(std::numeric_limits<int32_t>::max())
    };

    output[0].left = &output[1];

    return output;
  }

  // circular
  std::vector<TreeNode> create_circular_bst_1() {
    //        0
    //       /
    //     -1
    //     /
    //   -2
    //   /
    // loop -1
    std::vector<TreeNode> output = {
      TreeNode(0),
      TreeNode(-1),
      TreeNode(-2)
    };

    output[0].left = &output[1];
    output[1].left = &output[2];
    output[2].left = &output[1];

    return output;
  }

  std::vector<TreeNode> create_circular_bst_2() {
    //        0
    //       /
    //     -1
    //     /
    //   -2
    //     \
    //   loop -1
    std::vector<TreeNode> output = {
      TreeNode(0),
      TreeNode(-1),
      TreeNode(-2)
    };

    output[0].left = &output[1];
    output[1].left = &output[2];
    output[2].right = &output[1];

    return output;
  }

  std::vector<TreeNode> create_circular_bst_3() {
    //        0
    //       /
    //     -1
    //     /
    //   -2
    //   /
    // loop -2
    std::vector<TreeNode> output = {
      TreeNode(0),
      TreeNode(-1),
      TreeNode(-2),
    };

    output[0].left = &output[1];
    output[1].left = &output[2];
    output[2].left = &output[2];

    return output;
  }

  std::vector<TreeNode> create_circular_bst_4() {
    //        0
    //       / \
    //     -1  2
    //     /  /
    //   -2  loop -2
    std::vector<TreeNode> output = {
      TreeNode(0),
      TreeNode(-1),
      TreeNode(-2),
      TreeNode(2),
    };

    output[0].left = &output[1];
    output[0].right = &output[3];
    output[1].left = &output[2];
    output[3].left = &output[2];

    return output;
  }
}; // class IsValidBSTTestCaseFactory

template<typename TSolution>
void run_test() {
  IsValidBSTTestCaseFactory factory;

  EXPECT_TRUE(TSolution().isValidBST(nullptr));

  EXPECT_TRUE(TSolution().isValidBST(&factory.create_valid_bst_1()[0]));
  EXPECT_TRUE(TSolution().isValidBST(&factory.create_valid_bst_2()[0]));
  EXPECT_TRUE(TSolution().isValidBST(&factory.create_valid_bst_3()[0]));
  EXPECT_TRUE(TSolution().isValidBST(&factory.create_valid_bst_4()[0]));
  EXPECT_TRUE(TSolution().isValidBST(&factory.create_valid_bst_5()[0]));
  EXPECT_TRUE(TSolution().isValidBST(&factory.create_valid_bst_6()[0]));

  EXPECT_FALSE(TSolution().isValidBST(&factory.create_invalid_bst_1()[0]));
  EXPECT_FALSE(TSolution().isValidBST(&factory.create_invalid_bst_2()[0]));
  EXPECT_FALSE(TSolution().isValidBST(&factory.create_invalid_bst_3()[0]));
  EXPECT_FALSE(TSolution().isValidBST(&factory.create_invalid_bst_4()[0]));
  EXPECT_FALSE(TSolution().isValidBST(&factory.create_invalid_bst_5()[0]));

  EXPECT_FALSE(TSolution().isValidBST(&factory.create_circular_bst_1()[0]));
  EXPECT_FALSE(TSolution().isValidBST(&factory.create_circular_bst_2()[0]));
  EXPECT_FALSE(TSolution().isValidBST(&factory.create_circular_bst_3()[0]));
  EXPECT_FALSE(TSolution().isValidBST(&factory.create_circular_bst_4()[0]));
}
