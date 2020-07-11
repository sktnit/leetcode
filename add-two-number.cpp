/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
// Recursive way to solve the problem of two numbers
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    /* carry var is used to keep track of carry generation
    from one node to next node*/
    static int carry = 0;
    int val; // val is to store the sum of l1 and l2 data

    //in case both linked list is empty  
    if (l1 == NULL && l2 == NULL)
    {
      if (carry == 0)
        return NULL;
      else //if carry exist then create a node with data 1
      {
        ListNode *p = new ListNode(1);
        carry = 0;
        return p;
      }
    }
    
    // l1 is empty
    if (l1 == NULL)
    {
      // if carry is 0 simply return l2 
      if (carry == 0)
        return l2;
      else // otherwise add carry with val of l2 
      {
        val = l2->val + 1;
        l2->val = val % 10;
        if (val >= 10) // after add carry val greater than 10
        {
          carry = 1;
          l2->next = addTwoNumbers(NULL, l2->next);// forward carry
        }
        else
          carry = 0;
        return l2; //else if carry is 1 return l2
      }
    }
    if (l2 == NULL)
    {
      if (carry == 0)
        return l1;
      else
      {
        val = l1->val + 1;
        l1->val = val % 10;
        if (val >= 10)
        {
          carry = 1;
          l1->next = addTwoNumbers(l1->next, NULL);
        }
        else
          carry = 0;
        return l1;
      }
    }

    
    if (carry == 0)
    {
      val = l1->val + l2->val;

      l1->val = val % 10;
    }
    else if (carry == 1)
    {
      val = (l1->val + l2->val) + 1;

      l1->val = val % 10;
    }
    if (val >= 10)
      carry = 1;
    else
      carry = 0;

    l1->next = addTwoNumbers(l1->next, l2->next);
    return l1;
  }
};