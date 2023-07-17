#pragma once

void beginTest();
void endTest();
void cbeginTest();
void cendTest();
void rbeginTest();
void rendTest();
void crbeginTest();
void crendTest();

void iteratorOperatorDereference();
void iteratorOperatorEquals();
void iteratorOperatorDoesntEquals();

void reverseIteratorOperatorDereference();
void reverseIteratorOperatorEquals();
void reverseiIteratorOperatorDoesntEquals();


inline void IteratorTests()
{
	beginTest();
	endTest();
	cbeginTest();
	cendTest();
	rbeginTest();
	rendTest();
	crbeginTest();
	crendTest();

	iteratorOperatorDereference();
	iteratorOperatorEquals();
	iteratorOperatorDoesntEquals();

	reverseIteratorOperatorDereference();
	reverseIteratorOperatorEquals();
	reverseiIteratorOperatorDoesntEquals();
}