#include <iostream>
#include <set>
using namespace std;

struct SLNode {
  int val;
  SLNode* next;
  SLNode(int t = 0, SLNode *p = NULL) 
    : val(t), next(p) {}
};

class MemPool {
public:
  MemPool() {}
  ~MemPool() {
    set<SLNode*>::iterator it = mem_.begin();
    for (; it != mem_.end(); ++it) {
      //cout << "Deleting  " << (*it)->val << endl;
      delete *it;
    }
  }
  SLNode* Create(int t, SLNode *next = NULL) {
    SLNode *p = new SLNode(t, next);
    mem_.insert(p);
    return p;
  }
  bool Delete(SLNode *p) {
    delete p;
    return mem_.erase(p);
  }
private:
  MemPool( MemPool& mp);
  MemPool& operator=( MemPool& mp);
private:
  set<SLNode*> mem_;
};

class SList {
public:
  SList(MemPool &mem) 
    : head_(NULL), mem_(mem) {}
  void Insert(int t);
  SLNode* Find(int i);
  void MakeCircle(int intersect);
  SLNode* head()  {return head_;} 
  SLNode* tail()  {return tail_;} 
  void set_tail(SLNode* tail) {tail_ = tail;}
private:
  SLNode *head_;
  SLNode *tail_;
  MemPool &mem_;
};

void SList::Insert(int t) {
  SLNode *p = mem_.Create(t); 
  if (!head_) tail_ = p;
  p->next = head_;
  head_ = p;
}

SLNode* SList::Find(int i) {
  SLNode* p = head_;
  while (p && p->val != i) p = p->next;
  //cout << "found val " << p->val << endl;
  return p;
}

void SList::MakeCircle(int i) {
  SLNode* p = Find(i);
  if (!p) return;
  tail_->next = p;
}

SLNode* CheckCircle( SList &slist) {
  //Caution!! shall both start from head
  SLNode *step1 = slist.head(), *step2 = slist.head(); 
  if (!step1) return NULL;
  while (step1 && step2 && step2->next) {
    step1 = step1->next;
    step2 = step2->next->next;
    if (step1 == step2) break;
  }
  if (step1 != step2) return NULL; 
  //cout << "step1 val " << step1->val << endl;
  step1 = slist.head();
  while (step1 != step2) {
    step1 = step1->next;
    step2 = step2->next;
  }
  return step1;
}

bool CheckIntersect( SList &slist1,  SList &slist2) {
   SLNode *p1 = slist1.head(), *p2 = slist2.head();
  if (!p1 || !p2) return false;
  SLNode* cross1 = CheckCircle(slist1);
  SLNode* cross2 = CheckCircle(slist2);
  // both has no circle
  if (!cross1 && !cross2) {
    // method1: check tails
    //while (p1->next) p1 = p1->next;
    //while (p2->next) p2 = p2->next;
    //return p1 == p2;
    
    //method2: connect list1 head and tail, check circle
    //         circle cross point is intersect point
    slist1.tail()->next = slist1.head();
    cross2 = CheckCircle(slist2);
    cout << "Intersect point " << cross2->val << endl;
    if (cross2) return true;
  } else if (cross1 && cross2){
    // both has circle 
    p1 = slist1.head();
    bool pass = false;
    while (p1) {
      p1 = p1->next;
      if (p1 == cross2) return true;
      if (p1 == cross1) {
        if (pass) break;
        pass = true;
      } 
    }
  }
  return false;
}

int main() {
  MemPool mem;
  SList slist(mem);
  for (int i = 20; i >= 1; --i) {
    slist.Insert(i);
  } 
   SLNode *p = slist.head();
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
  if (CheckCircle(slist))
    cout << "Has circle!";
  else
    cout << "No circle!";
  cout << endl;

  cout << "making circle" << endl;
  slist.MakeCircle(5);

  SLNode* cross = CheckCircle(slist);
  if (cross)
    cout << "Has circle! Cross point is " << cross->val << endl;
  else
    cout << "No circle!";
  cout << endl;

  // no circle, intersect
  SList ls1(mem), ls2(mem);
  for (int i = 20; i >= 1; --i) {
    ls1.Insert(i);
  } 
  for (int i = 40; i >= 21; --i) {
    ls2.Insert(i);
  } 
  ls1.tail()->next = ls2.Find(30);
  ls1.set_tail(ls2.tail());         //Caution: need to set tail!!
  bool flag = CheckIntersect(ls1, ls2);
  if (flag)
    cout << "Intersect!!!" << endl;
  else
    cout << "No intersect!!!" << endl;
  
  // both circle, intersect
  ls1.MakeCircle(8);
  ls2.tail()->next = ls1.Find(5);
  flag = CheckIntersect(ls1, ls2);
  if (flag)
    cout << "Intersect!!!" << endl;
  else
    cout << "No intersect!!!" << endl;
}
