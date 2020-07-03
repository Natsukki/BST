#pragma once

#include <memory>
#include <optional>
#include <vector>
#include <iostream>

class Bst
{
public:
    struct Node
    {
        int value_;
        std::unique_ptr<Node> left_;
        std::unique_ptr<Node> right_;
    };

    Bst()
        : head_(nullptr)
        {}

    bool ex_rec(int v, const std::unique_ptr<Bst::Node>& head) const;
    bool exist(int v) const;
    std::optional<int> findMin() const;
    std::optional<int> findMax() const;
    void print() const;
    void print_rec(const std::unique_ptr<Bst::Node> &head) const;
    bool insert(int v);
    bool erase(int v);
    bool rec(int v, std::unique_ptr<Bst::Node> &head);

private:
    std::unique_ptr<Node> head_;
};
