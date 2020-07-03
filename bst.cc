#include "bst.hh"
#include <iostream>
#include <vector>

bool Bst::ex_rec(int v, const std::unique_ptr<Bst::Node>& head) const
{
    if (!head)
        return false;
    if (v < head->value_)
        return this->ex_rec(v, head->left_);
    if (v > head->value_)
        return this->ex_rec(v, head->right_);
    return true;
}

bool Bst::exist(int v) const
{
    return this->ex_rec(v, this->head_);
}

std::optional<int> Bst::findMin() const
{
    if (this->head_ == nullptr)
        return std::nullopt;
    auto min = (this->head_)->value_;
    auto* head = &this->head_;
    while ((*head)->left_)
    {
        head = &(*head)->left_;
        min = (*head)->value_;
    }
    return min;
}

std::optional<int> Bst::findMax() const
{
    if (this->head_ == nullptr)
        return std::nullopt;
    auto max = (this->head_)->value_;
    auto* head = &this->head_;
    while ((*head)->right_)
    {
        head = &(*head)->right_;
        max = (*head)->value_;
    }
    return max;
}
void Bst::print_rec(const std::unique_ptr<Bst::Node> &head) const
{
    if (head == nullptr)
        std::cout << "NULL";
    else
    {
        std::cout << '(' << head->value_ << " l:";
        this->print_rec(head->left_);
        std::cout << ", r:";
        this->print_rec(head->right_);
        std::cout << ')';
    }
}

void Bst::print() const
{
    if (this->head_ == nullptr)
        std::cout << "NULL\n";
    else
    {
        std::cout << '(' << this->head_->value_ << " l:";
        this->print_rec(this->head_->left_);
        std::cout << ", r:";
        this->print_rec(head_->right_);
        std::cout << ')' << '\n';
    }
}

bool Bst::insert(int v)
{
    if (this->head_ == nullptr)
    {
        this->head_ = std::unique_ptr<Node>(new Node{v, nullptr, nullptr});
        return true;
    }
    auto *prev = &this->head_;
    auto *head = &this->head_;
    while (*head)
    {
        prev = head;
        int tmp = (*head)->value_;
        if (tmp == v)
            return false;
        if (tmp < v)
            head = &(*head)->right_;
        if (tmp > v)
            head = &(*head)->left_;
    }
    int tmp = (*prev)->value_;
    if (tmp > v)
        (*prev)->left_ = std::unique_ptr<Node>(new Node{v, nullptr, nullptr});
    else
        (*prev)->right_ = std::unique_ptr<Node>(new Node{v, nullptr, nullptr});
    return true;
}

bool Bst::rec(int v, std::unique_ptr<Bst::Node> &head)
{
    if (!head)
        return false;
    if (head->value_ > v)
        return this->rec(v, head->left_);
    if (head->value_ < v)
        return this->rec(v, head->right_);
    if (head->left_ && head->right_)
    {
        auto tmp = head->right_.get();
        while (tmp->left_)
            tmp = tmp->left_.get();
        head->value_ = tmp->value_;
        this->rec(head->value_, head->right_);
    }
    else if (head->left_)
        head.swap(head->left_);
    else if (head->right_)
        head.swap(head->right_);
    else
        head.reset(nullptr);
    return true;
}

bool Bst::erase(int v)
{
    if (!this->exist(v))
        return false;
    return this->rec(v, this->head_);
}
