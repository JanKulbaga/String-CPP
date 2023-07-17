#pragma once

void stringOperatorAssignmentWithStringReferenceTest();
void stringOperatorAssignmentWithConstCharPointerTest();
void stringOperatorAssignmentWithCharacterTest();
void stringOperatorEqualsTest();
void stringOperatorDoesntEqualsTest();
void stringOperatorLessThanTest();
void stringOperatorGreaterThanTest();
void stringOperatorLessThanOrEqualToTest();
void stringOperatorGreaterThanOrEqualToTest();
void stringOperatorPlusTest();
void stringOperatorPlusEqualsTest();
void stringOperatorMultiplyTest();
void stringOperatorMultiplyEqualsTest();
void stringOperatorIndexTest();

inline void OperatorTests()
{
	stringOperatorAssignmentWithStringReferenceTest();
	stringOperatorAssignmentWithConstCharPointerTest();
	stringOperatorAssignmentWithCharacterTest();
	stringOperatorEqualsTest();
	stringOperatorDoesntEqualsTest();
	stringOperatorLessThanTest();
	stringOperatorGreaterThanTest();
	stringOperatorLessThanOrEqualToTest();
	stringOperatorGreaterThanOrEqualToTest();
	stringOperatorPlusTest();
	stringOperatorPlusEqualsTest();
	stringOperatorMultiplyTest();
	stringOperatorMultiplyEqualsTest();
	stringOperatorIndexTest();
}