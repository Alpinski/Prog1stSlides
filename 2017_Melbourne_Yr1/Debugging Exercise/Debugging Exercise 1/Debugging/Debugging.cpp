class MyThing
{
public:
	MyThing() : m_interestingNumber(1) {}

	void DoStuff() { m_interestingNumber++; };

private:
	int m_interestingNumber;
};


class ThingStack
{
public:
	void DoStuff() 
	{
		m_buffer[m_unusedIndex-1]->DoStuff();
	}

	void Push( MyThing* pThing )
	{
		m_buffer[m_unusedIndex] = pThing;
		m_unusedIndex++;
	}

	void Pop()
	{
		MyThing* pThing = m_buffer[m_unusedIndex-1];
		delete pThing;
		m_unusedIndex--;
		ClearUnused();
	}

	void ClearUnused() {
		for( int i = m_unusedIndex; i <= BUFFER_SIZE; i++ )
		{
			m_buffer[i] = nullptr;
		}
	}

private:
	static const int BUFFER_SIZE = 1024;

	MyThing* m_buffer[BUFFER_SIZE];
	int m_unusedIndex;
};



void main()
{
	ThingStack* pThingStack = new ThingStack;

	MyThing* pThing1 = new MyThing();
	MyThing* pThing2 = new MyThing;
	MyThing* pThing3;

	pThingStack->Push(pThing1);
	pThingStack->DoStuff();

	pThingStack->Push(pThing1);
	pThingStack->DoStuff();

	pThingStack->Push(pThing2);
	pThingStack->DoStuff();

	pThingStack->Push(pThing3);
	pThingStack->DoStuff();

	pThingStack->Pop();
	pThingStack->DoStuff();

	pThingStack->Pop();
	pThingStack->DoStuff();

	pThingStack->Pop();
	pThingStack->DoStuff();

	pThingStack->Pop();
	pThingStack->DoStuff();

	delete pThingStack;
}

