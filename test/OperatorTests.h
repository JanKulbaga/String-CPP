#pragma once

void stringOperatorAssignmentWithStringReference();
void stringOperatorAssignmentWithConstCharPointer();
void stringOperatorAssignmentWithCharacter();
void stringOperatorEquals();
void stringOperatorDoesntEquals();
void stringOperatorLessThan();
void stringOperatorGreaterThan();
void stringOperatorLessThanOrEqualTo();
void stringOperatorGreaterThanOrEqualTo();
void stringOperatorPlus();
void stringOperatorPlusEquals();
void stringOperatorMultiply();
void stringOperatorMultiplyEquals();
void stringOperatorIndex();

inline void OperatorTests()
{
	stringOperatorAssignmentWithStringReference();
	stringOperatorAssignmentWithConstCharPointer();
	stringOperatorAssignmentWithCharacter();
	stringOperatorEquals();
	stringOperatorDoesntEquals();
	stringOperatorLessThan();
	stringOperatorGreaterThan();
	stringOperatorLessThanOrEqualTo();
	stringOperatorGreaterThanOrEqualTo();
	stringOperatorPlus();
	stringOperatorPlusEquals();
	stringOperatorMultiply();
	stringOperatorMultiplyEquals();
	stringOperatorIndex();
}