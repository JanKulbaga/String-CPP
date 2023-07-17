#pragma once

void beginTest();
void endTest();
void cbeginTest();
void cendTest();
void rbeginTest();
void rendTest();
void crbeginTest();
void crendTest();

void iteratorOperatorDereferenceTest();
void iteratorOperatorEqualsTest();
void iteratorOperatorDoesntEqualsTest();

void reverseIteratorOperatorDereferenceTest();
void reverseIteratorOperatorEqualsTest();
void reverseiIteratorOperatorDoesntEqualsTest();


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

	iteratorOperatorDereferenceTest();
	iteratorOperatorEqualsTest();
	iteratorOperatorDoesntEqualsTest();

	reverseIteratorOperatorDereferenceTest();
	reverseIteratorOperatorEqualsTest();
	reverseiIteratorOperatorDoesntEqualsTest();
}