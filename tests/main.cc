#include "bst.cc"

int main()
{
    Bst bst;

    std::vector<int> insert{5, 9, 2, 3, 4, 10, 1, 8, 10};
    std::vector<int> erase{5, 1, 3, 11};

    for (auto i : insert)
        if (bst.insert(i))
		{
            std::cout << i << " inserted\n";
		}

    std::cout << '\n';

    bst.print();
    std::cout << "Min: " << bst.findMin().value() << '\n';
    std::cout << "Max: " << bst.findMax().value() << '\n';

    std::cout << '\n';

	for (auto i : erase)
            if (bst.erase(i))
                std::cout << i << " deleted" << '\n';

    std::cout << '\n';

    bst.print();
    std::cout << "Min: " << bst.findMin().value() << '\n';
    std::cout << "Max: " << bst.findMax().value() << '\n';
	return 0;
}
