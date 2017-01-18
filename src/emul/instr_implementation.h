/*
	Implementation of _fetch, _execute and _writeback of
	every possible instruction
*/

#include "interstate.h"
#include "proc.h"

//add instruction implementation
int add_fetch(interstate*, proc*);
int add_execute(interstate*);
int add_writeback(interstate*, proc*);
