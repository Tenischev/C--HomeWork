#ifndef LIST_H
#define LIST_H

struct op
{
    op * next;
    op * prev;
    int num;
    op(){}
    op(op* _next,op* _prev,int _num)
    {
        this->next=_next;
        this->num=_num;
        this->prev=_prev;
    }
};


struct List
{
private:
    op* beg=new op;
    op* end=new op;
    int kol;
public:
    List()
    {
        this->end->prev=this->beg;
        this->beg->next=this->end;
        this->kol = 0;
    }
    List(List const& q)
    {
        this->operator =(q);
    }
    List& operator =(List const& b)
    {
        op *t=b.beg->next;
        for (int i=0;i<b.kol;i++)
        {
            this->push_back(t->num);
            t=t->next;
        }
        return *this;
    }
    void push_back(int q)
    {   // pp -> new -> end
        //op* pp = this->end->prev;
        op* n = new op;
        n->num=q;
        n->prev=this->end->prev;
        n->next=this->end;
        this->end->prev->next=n;
        this->end->prev=n;
        this->kol++;
    }
    void push_front(int q)
    {   // beg -> n -> pp
        //op* pp = this->beg->next;
        op* n = new op;
        n->num=q;
        n->next=this->beg->next;
        n->prev=this->beg;
        this->beg->next->prev=n;
        this->beg->next=n;
        this->kol++;
    }
    void pop_back()
    {   // pp -> p -> end ...to... pp -> end
        this->end->prev->prev->next= this->end;
        this->end->prev=this->end->prev->prev;
        this->kol--;
    }
    void pop_front()
    {   // beg -> p -> pp ...to... beg -> pp
        this->beg->next->next->prev=this->beg;
        this->beg->next=this->beg->next->next;
        this->kol--;
    }
    int (back() const)
    {   // return p ... p -> end
        return this->end->prev->num;
    }
    int (front() const)
    {   // return beg.num
        return this->beg->next->num;
    }
    struct iterator
    {
    public:
        op* _op;
        iterator (op* q)
        {
            this->_op=q;
        }
        int& operator * () const
        {
            return this->_op->num;
        }
        iterator& operator ++()
        {
            this->_op=this->_op->next;
            return *this;
        }
        iterator operator ++(int q)
        {
            for (int i=0;i<q;i++)
                this->operator ++();
            return *this;
        }
        iterator& operator --()
        {
            this->_op=this->_op->prev;
            return *this;
        }
        iterator operator --(int q)
        {
            for (int i=0;i<q;i++)
                this->operator --();
            return *this;
        }
        bool operator !=(iterator const& b) const
        {
            return !(this->_op==b._op);
        }
    };
    iterator begin()
    {
        return this->beg->next;
    }
    iterator ending()
    {
        return this->end;
    }
    iterator erase(iterator q)
    {
        q._op->prev->next=q._op->next;
        q._op->next->prev=q._op->prev;
        return q.operator ++();
    }
    iterator insert(iterator q, int w)
    {
        op* n=new op;
        n->num=w;
        n->next=q._op->next;
        n->prev=q._op;
        q._op->next->prev=n;
        q._op->next=n;
        return q.operator ++();
    }
    int print(iterator q)
    {
        return q._op->num;
    }
};
#endif // LIST_H
