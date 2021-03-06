#ifndef __DEBUG_H_
#define __DEBUG_H_

#include "config.h"	// Various macros
#include "typedefs.h"	// typedefs
#include "ctl_unit.h"	// flags

struct debug_state_t
{
	bool debug;		//! Enable debugging

	bool instr_dump;	//! Dump instructions

	uint8_t last_opcode;	//! Store last opcode
	uint8_t last_param[2];	//! Last parameters
};

extern const char * const mnemonics[0x100];
extern const char * const mnemonics_cb[0x100];
extern const char * const flags_expect[0x100];
extern const char * const flags_cb_expect[0x100];

void print_cpu_state(emu_state *restrict);
void print_cycles(emu_state *restrict);
void print_flags(emu_state *restrict);
void dump_all_state(emu_state *restrict);
void dump_state_pc(emu_state *restrict, uint16_t);

#endif /*!__DEBUG_H_*/
