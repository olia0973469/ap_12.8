#include "pch.h"
#include "CppUnitTest.h"
#include "../ap_12.8/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Node* head = NULL;
			addNode(head, "A");
			addNode(head, "B");
			addNode(head, "C");
			addNode(head, "D");
			addNode(head, "A");

			Assert::IsTrue(hasCircularNext(head)); 
			removeNodesWithSameNeighbors(head);

			Assert::IsTrue(head == nullptr);
		}
	};
}
