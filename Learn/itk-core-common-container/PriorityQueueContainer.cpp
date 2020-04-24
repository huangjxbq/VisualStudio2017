#include <itkPriorityQueueContainer.h>

using IntMinPriorityQueueElementWrapper = itk::MinPriorityQueueElementWrapper<int>;
using IntMaxPriorityQueueElementWrapper = itk::MaxPriorityQueueElementWrapper<int>;

using IntMinPriorityQueueContainer = itk::PriorityQueueContainer<IntMinPriorityQueueElementWrapper, IntMinPriorityQueueElementWrapper>;
using IntMaxPriorityQueueContainer = itk::PriorityQueueContainer<IntMaxPriorityQueueElementWrapper, IntMaxPriorityQueueElementWrapper>;

using PriorityQueueContainer = IntMaxPriorityQueueContainer;
using ElementWrapperType = PriorityQueueContainer::ElementWrapperType;
using ElementPriorityType = ElementWrapperType::ElementPriorityType;
using ElementIdentifierType = PriorityQueueContainer::ElementIdentifierType;

void PriorityQueueContainerTest()
{
	PriorityQueueContainer::Pointer queue = PriorityQueueContainer::New();

	ElementWrapperType wrapper1(2, 1.3);
	ElementWrapperType wrapper2(3, 2.3);
	ElementWrapperType wrapper3(4, 0.3);

	queue->Push(wrapper1);
	queue->Push(wrapper2);
	queue->Push(wrapper3);

	while (!queue->Empty())
	{
		ElementWrapperType wrapper = queue->Peek();
		std::cout << "Location:" << wrapper.m_Location << " ";
		std::cout << "Priority:" << wrapper.m_Priority << " ";
		std::cout << "Element:" << wrapper.m_Element << std::endl;
		queue->Pop();
	}
}