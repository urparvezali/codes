use std::cell::RefCell;
use std::rc::Rc;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}
struct Solution;
impl Solution {
    pub fn is_same_tree(
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        if p.is_none() && q.is_some() || p.is_some() && q.is_none() {
            return false;
        }
        if let Some(nodex) = p {
            if let Some(nodey) = q {
                let borrow1 = nodex.borrow();
                let borrow2 = nodey.borrow();
                return (borrow1.val == borrow2.val)
                    & Solution::is_same_tree(borrow1.left.clone(), borrow2.left.clone())
                    & Solution::is_same_tree(borrow1.right.clone(), borrow2.right.clone());
            }
        }
        true
    }
}
