#include <iostream>
#include <itkTreeContainer.h>
#include <itkTreeNode.h>

//1.TreeContainerBase 抽象
//|
//|--2.TreeContainer

int main()
{
	using TreeType = itk::TreeContainer<double>;
	using TreeNodeType = TreeType::TreeNodeType;

	TreeNodeType::Pointer node = TreeNodeType::New();
	node->Set(0);

	TreeNodeType::Pointer child1 = TreeNodeType::New();
	child1->Set(11);

	TreeNodeType::Pointer child2 = TreeNodeType::New();
	child2->Set(22);

	TreeNodeType::Pointer child3 = TreeNodeType::New();
	child3->Set(33);

	{	
		std::cout << "HasChildren:" << node->HasChildren() << std::endl;
		std::cout << "HasParent:" << node->HasParent() << std::endl;
		int dep = 0;
		std::cout << "NumberOfChildren(" << dep << ")" << node->GetNumberOfChildren(dep) << std::endl;
		std::cout << "CountChildren:" << node->CountChildren() << std::endl;
	}

	

	node->AddChild(child1);
	node->AddChild(child2);
	child2->AddChild(child3);

	{
		std::cout << "HasChildren:" << node->HasChildren() << std::endl;
		std::cout << "HasParent:" << node->HasParent() << std::endl;
		int dep = 0;
		std::cout << "NumberOfChildren(" << dep << ")" << node->GetNumberOfChildren(dep) << std::endl;
		//std::cout << "NumberOfChildren(" << 1 << ")" << node->GetNumberOfChildren(1) << std::endl;
		std::cout << "CountChildren:" << node->CountChildren() << std::endl;
	}

	TreeType::Pointer tree = TreeType::New();
	tree->SetRoot(node);
	tree->Print(std::cout);

	system("pause");
}