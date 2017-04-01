/* PLEASE DO NOT MODIFY THIS FILE. ALL CHANGES WILL BE LOST! LOOK FOR README FOR DETAILS */

/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "inertiaplayer.h"

namespace InertiaPlayer {

void InertiaPlayerContext::_moduleread() {
	STACK_CHECK;
	_push(ds);
	_push(dx);
	_push(cs);
	_snd_offx();
	_push(cs);
	_memfree_125da();
	_pop(dx);
	ax = 0x3D00;
	// _int(0x21);
	bx = ;
	ds = bx;
	data.word(k_savesp_245d0) = sp;
	data.word(k_fhandle_module) = ax;
	dx = 6405;
	ax = 0x0FFFF;
		_jc(_lfreaderr);
	_ems_save_mapctx();
	_write_df(false);
 	data.byte(k_byte_2461b) = 0;
	data.word(k_word_24662) = 0;
	dx = 6905;
	cx = 1084;
	_dosfread();
	_push(cs);
	_clean_11c43();
	bx = 6267;
	dl = 23;
loc_10045:
	cx = ds.byte(bx+4);
	di = 6905;
	_add(di, ds.word(bx+2));
	si = ds.word(bx+5);
	ax = ds.word(bx);
	bx = si;
	_add(bx, cx);
	_write_df(false);
 	while(cx-- && flags.z())
			_jz(loc_10064);
	_dec(dl);
		_jnz(loc_10045);
	ax = 49156;
loc_10064:
	data.byte(k_byte_24665) = 1;
	__dispatch_call(ax);
	bx = data.word(k_fhandle_module);
	ah = 0x3E;
	// _int(0x21);
	_adc(data.word(k_word_24662), 0);
	_ems_restore_mapctx();
	ax = data.byte(k_byte_2461b);
	_inc(ax);
	_cmp(ax, data.word(k_word_245d4));
		_jbe(loc_1008a);
	ax = data.word(k_word_245d4);
loc_1008a:
	_push(cs);
	sub_12b83();
	si = 6886;
	_push(cs);
	sub_12b18();
	ax = 0;
	_pop(ds);
	return;
	dx = 6409;
	ax = 0x0FFFE;
_lfreaderr:
	_push(ax);
	_push(dx);
	bx = data.word(k_fhandle_module);
	ah = 0x3E;
	// _int(0x21);
	_ems_restore_mapctx();
	_push(cs);
	_memfree_125da();
	ax = ds;
	fs = ax;
	_pop(dx);
	_pop(ax);
	sp = data.word(k_savesp_245d0);
	_pop(ds);
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_1008a from _moduleread:67-96*/
loc_1008a:
	_push(cs);
	sub_12b83();
	si = 6886;
	_push(cs);
	sub_12b18();
	ax = 0;
	_pop(ds);
	return;
	dx = 6409;
	ax = 0x0FFFE;
_lfreaderr:
	_push(ax);
	_push(dx);
	bx = data.word(k_fhandle_module);
	ah = 0x3E;
	// _int(0x21);
	_ems_restore_mapctx();
	_push(cs);
	_memfree_125da();
	ax = ds;
	fs = ax;
	_pop(dx);
	_pop(ax);
	sp = data.word(k_savesp_245d0);
	_pop(ds);
	_write_cf(true);
 	return;
loc_1008a:
}

void InertiaPlayerContext::_mod_n_t_module() {
	STACK_CHECK;
	data.dword(k_module_type_text) = 0x2E542E4E;
	data.word(k_word_245d2) = 0x0F;
	data.word(k_word_245d4) = 4;
	si = 7034;
	_mod_1021e();
	_mod_102f5();
	dx = 0x258;
	cx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
	_adc(data.word(k_word_24662), 0);
	loc_101b7;
	data.dword(k_module_type_text) = 0x38544C46;
	data.word(k_moduleflag_246d0) = 0x3;
	data.word(k_word_245d2) = 0x1F;
	data.word(k_word_245d4) = 8;
	si = 7035;
	_mod_1021e();
	si = 6899;
	cx = 0x80;
loc_10118:
	_shr(ds.byte(si), 1);
	_inc(si);
	_dec(cx);
		_jnz(loc_10118);
	_mod_1024a();
	_mod_102f5();
	_mod_read_10311();
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
	al = data.byte(k_byte_30943);
	loc_10137;
	al = data.byte(k_byte_30940);
loc_10137:
	ah = 0;
	_inc(data.word(k_word_24662));
	_sub(al, 0x30);
		_jbe(locret_10154);
	_cmp(al, 9);
		_ja(locret_10154);
	_dec(data.word(k_word_24662));
	data.word(k_word_245d2) = 0x1F;
	data.word(k_word_245d4) = ax;
	loc_101a6;
locret_10154:
	return;
	_inc(data.word(k_word_24662));
	ax = data.byte(k_byte_30940);
	_sub(al, '0');
		_jc(locret_10154);
	_cmp(al, 9);
		_ja(locret_10154);
	_mul(dx, ax, 10);
	al = data.byte(kUnk_30941);
	_sub(al, '0');
		_jc(locret_10154);
	_cmp(al, 9);
		_ja(locret_10154);
	_add(ax, dx);
		_jz(locret_10154);
	_cmp(ax, ' ');
		_ja(locret_10154);
	_dec(data.word(k_word_24662));
	data.word(k_word_245d2) = 0x1F;
	data.word(k_word_245d4) = ax;
	loc_101a6;
	data.word(k_word_245d2) = 0x1F;
	data.word(k_word_245d4) = 8;
	loc_101a6;
	data.word(k_word_245d2) = 0x1F;
	data.word(k_word_245d4) = 4;
loc_101a6:
	eax = data.byte(k_byte_30940);
	data.dword(k_module_type_text) = eax;
	si = 7035;
	_mod_1021e();
	_mod_102f5();
loc_101b7:
	_mod_1024a();
	_cmp(data.dword(k_module_type_text), 0x2E4B2E4D);
		_jnz(loc_10213);
	dx = 0;
	cx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4202;
	// _int(0x21);
	_shl(edx, 0x10);
	dx = ax;
	_push(edx);
	dx = 1084;
	cx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
	_pop(edx);
	eax = data.word(k_word_245f2);
	_shl(eax, 0x0B);
	_add(eax, data.dword(k_dword_245c4));
	_add(eax, 1084);
	_cmp(eax, edx);
		_jnz(loc_10213);
	data.word(k_word_245d4) = 8;
	data.dword(k_module_type_text) = 0x20574F57;
loc_10213:
	_mod_read_10311();
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
	return;
/*continuing to unbounded code: loc_101a6 from _mod_n_t_module:81-118*/
loc_101a6:
	eax = data.byte(k_byte_30940);
	data.dword(k_module_type_text) = eax;
	si = 7035;
	_mod_1021e();
	_mod_102f5();
loc_101b7:
	_mod_1024a();
	_cmp(data.dword(k_module_type_text), 0x2E4B2E4D);
		_jnz(loc_10213);
	dx = 0;
	cx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4202;
	// _int(0x21);
	_shl(edx, 0x10);
	dx = ax;
	_push(edx);
	dx = 1084;
	cx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
	_pop(edx);
	eax = data.word(k_word_245f2);
	_shl(eax, 0x0B);
	_add(eax, data.dword(k_dword_245c4));
	_add(eax, 1084);
	_cmp(eax, edx);
		_jnz(loc_10213);
	data.word(k_word_245d4) = 8;
	data.dword(k_module_type_text) = 0x20574F57;
loc_10213:
	_mod_read_10311();
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
loc_101a6:
}

void InertiaPlayerContext::_mod_1021e() {
	STACK_CHECK;
	ax = ds;
	es = ax;
	_write_df(false);
 	_lodsb();
	ah = 0;
	data.word(k_word_245fa) = ax;
	_lodsb();
	_cmp(al, 0x78);
		_jc(loc_10230);
	al = 0;
loc_10230:
	data.word(k_word_245f8) = ax;
	di = 6899;
	cx = 0x20;
	_write_df(false);
 	while(cx--)
		_movsd();
	si = 6905;
	di = 3151;
	cx = 0x14;
	_copy_printable();
	return;
}

void InertiaPlayerContext::_mod_1024a() {
	STACK_CHECK;
	si = 6905;
	di = 6885;
	cx = data.word(k_word_245d2);
loc_10254:
	_push(cx);
	_add(si, 20);
	cx = 0x16;
	_copy_printable();
	_sub(si, 20);
	_pop(cx);
	edx = ds.word(si+0x2A);
	_xchg(dl, dh);
	_shl(edx, 1);
	_cmp(edx, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	ds.dword(di+0x20) = edx;
	_add(data.dword(k_dword_245c4), edx);
	al = ds.byte(si+0x2C);
	_and(al, 0x0F);
	ds.byte(di+0x3E) = al;
	ax = data.word(k_freq_245de);
	ds.word(di+0x36) = ax;
	al = ds.byte(si+0x2D);
	ds.byte(di+0x3D) = al;
	ebx = ds.word(si+0x2E);
	_xchg(bl, bh);
	_shl(ebx, 1);
	eax = ds.word(si+0x30);
	_xchg(al, ah);
	_shl(eax, 1);
	ds.dword(di+0x28) = eax;
	_cmp(eax, 2);
		_jbe(loc_102dc);
	_cmp(ebx, edx);
		_jc(loc_102c1);
	_shr(ebx, 1);
	_cmp(ebx, edx);
		_jnc(loc_102dc);
loc_102c1:
	_or(ds.byte(di+0x3C), 8);
	_add(eax, ebx);
	_cmp(eax, edx);
		_jbe(loc_102df);
	eax = ds.dword(di+0x28);
	_shr(eax, 1);
	_add(eax, ebx);
	_cmp(eax, edx);
		_jbe(loc_102df);
loc_102dc:
	eax = edx;
loc_102df:
	_dec(eax);
	ds.dword(di+0x2C) = eax;
	ds.dword(di+0x24) = ebx;
	_add(si, 0x1E);
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_10254);
	return;
	return;
/*continuing to unbounded code: loc_102c1 from _mod_1024a:40-60*/
loc_102c1:
	_or(ds.byte(di+0x3C), 8);
	_add(eax, ebx);
	_cmp(eax, edx);
		_jbe(loc_102df);
	eax = ds.dword(di+0x28);
	_shr(eax, 1);
	_add(eax, ebx);
	_cmp(eax, edx);
		_jbe(loc_102df);
loc_102dc:
	eax = edx;
loc_102df:
	_dec(eax);
	ds.dword(di+0x2C) = eax;
	ds.dword(di+0x24) = ebx;
	_add(si, 0x1E);
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_10254);
	return;
loc_102c1:
}

void InertiaPlayerContext::_mod_102f5() {
	STACK_CHECK;
	si = 6899;
	bx = 0;
	cx = 0x80;
	_write_df(false);
 loc_102fe:
	_lodsb();
	_and(al, 0x7F);
	_cmp(al, bl);
		_jc(loc_10307);
	bl = al;
loc_10307:
	_dec(cx);
		_jnz(loc_102fe);
	_inc(bl);
	data.word(k_word_245f2) = bx;
	return;
	return;
/*continuing to unbounded code: loc_102fe from _mod_102f5:5-16*/
loc_102fe:
	_lodsb();
	_and(al, 0x7F);
	_cmp(al, bl);
		_jc(loc_10307);
	bl = al;
loc_10307:
	_dec(cx);
		_jnz(loc_102fe);
	_inc(bl);
	data.word(k_word_245f2) = bx;
	return;
loc_102fe:
}

void InertiaPlayerContext::_mod_read_10311() {
	STACK_CHECK;
	cx = data.word(k_word_245f2);
loc_10315:
	_push(cx);
	dx = 7042;
	cx = data.word(k_word_245d4);
	_shl(cx, 8);
	_dosfread();
	_test(data.word(k_moduleflag_246d0), 0x2);
		_jz(loc_1035c);
	ax = ds;
	es = ax;
	si = 7042;
	di = 7047;
	cx = 0x200;
	_write_df(false);
 	while(cx--)
		_movsd();
	si = 7047;
	di = 7042;
	bx = 0x40;
loc_10345:
	cx = 4;
	while(cx--)
		_movsd();
	_add(si, 0x3F0);
	cx = 4;
	while(cx--)
		_movsd();
	_sub(si, 0x400);
	_dec(bx);
		_jnz(loc_10345);
loc_1035c:
	_memalloc12k();
	si = 7042;
	cx = 0x40;
loc_10365:
	_push(cx);
	cx = data.word(k_word_245d4);
	ch = 0;
loc_1036c:
	_push(cx);
	eax = ds.dword(si);
	_add(si, 4);
	edx = eax;
	_xchg(al, ah);
	bl = 0;
	_and(ax, 0x0FFF);
		_jz(loc_103b9);
	bx = 72;
	_cmp(ax, 214);
		_jbe(loc_10399);
	bx = 48;
	_cmp(ax, 428);
		_jbe(loc_10399);
	bx = 24;
	_cmp(ax, 856);
		_jbe(loc_10399);
	bx = 0;
loc_10399:
	_cmp(ax, data.word(k_table_25118)[bx]);
		_jnc(loc_103a8);
	_add(bx, 2);
	_cmp(bx, 166);
		_jc(loc_10399);
loc_103a8:
	ax = bx;
	_shr(ax, 1);
	bl = 12;
	_div(bl);
	_inc(ah);
	_shl(al, 4);
	_or(al, ah);
	bl = al;
loc_103b9:
	bh = dl;
	_and(bh, 0x30);
	_rol(edx, 0x10);
	al = dl;
	_shr(al, 4);
	_or(bh, al);
	_and(dl, 0x0F);
	cl = 0x0FF;
	sub_11ba6();
	_pop(cx);
	_inc(ch);
	_cmp(ch, cl);
		_jc(loc_1036c);
	es.byte(di) = 0;
	_inc(di);
	_pop(cx);
	_dec(cx);
		_jnz(loc_10365);
	_mem_reallocx();
	_pop(cx);
	_dec(cx);
		_jnz(loc_10315);
	return;
	return;
/*continuing to unbounded code: loc_1035c from _mod_read_10311:32-97*/
loc_1035c:
	_memalloc12k();
	si = 7042;
	cx = 0x40;
loc_10365:
	_push(cx);
	cx = data.word(k_word_245d4);
	ch = 0;
loc_1036c:
	_push(cx);
	eax = ds.dword(si);
	_add(si, 4);
	edx = eax;
	_xchg(al, ah);
	bl = 0;
	_and(ax, 0x0FFF);
		_jz(loc_103b9);
	bx = 72;
	_cmp(ax, 214);
		_jbe(loc_10399);
	bx = 48;
	_cmp(ax, 428);
		_jbe(loc_10399);
	bx = 24;
	_cmp(ax, 856);
		_jbe(loc_10399);
	bx = 0;
loc_10399:
	_cmp(ax, data.word(k_table_25118)[bx]);
		_jnc(loc_103a8);
	_add(bx, 2);
	_cmp(bx, 166);
		_jc(loc_10399);
loc_103a8:
	ax = bx;
	_shr(ax, 1);
	bl = 12;
	_div(bl);
	_inc(ah);
	_shl(al, 4);
	_or(al, ah);
	bl = al;
loc_103b9:
	bh = dl;
	_and(bh, 0x30);
	_rol(edx, 0x10);
	al = dl;
	_shr(al, 4);
	_or(bh, al);
	_and(dl, 0x0F);
	cl = 0x0FF;
	sub_11ba6();
	_pop(cx);
	_inc(ch);
	_cmp(ch, cl);
		_jc(loc_1036c);
	es.byte(di) = 0;
	_inc(di);
	_pop(cx);
	_dec(cx);
		_jnz(loc_10365);
	_mem_reallocx();
	_pop(cx);
	_dec(cx);
		_jnz(loc_10315);
	return;
loc_1035c:
}

void InertiaPlayerContext::__2stm_module() {
	STACK_CHECK;
	data.dword(k_module_type_text) = 0x4D545332;
	loc_103ff;
	data.dword(k_module_type_text) = 0x204D5453;
loc_103ff:
	data.word(k_moduleflag_246d0) = 0x8;
	data.word(k_word_245d4) = 4;
	data.word(k_word_245d2) = 0x1F;
	data.word(k_freq_245de) = 8448;
	al = 0x60;
	sub_13e9b();
	data.byte(k_byte_24679) = ah;
	data.byte(k_byte_2467a) = al;
	ax = data.byte(k_byte_30529);
	data.word(k_word_245f2) = ax;
	ax = ds;
	es = ax;
	si = 6905;
	di = 3151;
	cx = 0x14;
	_copy_printable();
	si = 6953;
	di = 6885;
	cx = data.word(k_word_245d2);
loc_10445:
	_push(cx);
	cx = 0x0C;
	_copy_printable();
	_pop(cx);
	eax = ds.word(si+0x10);
	edx = eax;
	_add(eax, 0x0F);
	_and(al, 0x0F0);
	_cmp(eax, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	ds.dword(di+0x20) = eax;
	_add(data.dword(k_dword_245c4), eax);
	eax = ds.word(si+0x0E);
	_shl(eax, 4);
	ds.dword(di+0x38) = eax;
	ax = ds.word(si+0x18);
	_or(ax, ax);
		_jnz(loc_10487);
	ax = data.word(k_freq_245de);
loc_10487:
	ds.word(di+0x36) = ax;
	al = ds.byte(si+0x16);
	ds.byte(di+0x3D) = al;
	ebx = ds.word(si+0x12);
	ds.dword(di+0x24) = ebx;
	eax = ds.word(si+0x14);
	_cmp(ax, 0x0FFFF);
		_jnz(loc_104b6);
	eax = 0;
	ds.dword(di+0x24) = eax;
	ds.dword(di+0x28) = eax;
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	loc_104c7;
loc_104b6:
	ds.dword(di+0x2C) = eax;
	_sub(eax, ebx);
	_inc(eax);
	ds.dword(di+0x28) = eax;
	_or(ds.byte(di+0x3C), 8);
loc_104c7:
	_add(si, 0x20);
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_10445);
	dx = 6899;
	cx = 0x80;
	eax = 0x410;
	_dosseek();
	si = 6899;
	ax = 0;
loc_104e6:
	_cmp(ds.byte(si), 0x63);
		_jnc(loc_104f2);
	_inc(ax);
	_inc(si);
	_cmp(ax, 0x80);
		_jc(loc_104e6);
loc_104f2:
	data.word(k_word_245fa) = ax;
	cx = data.word(k_word_245f2);
loc_104f9:
	_push(cx);
	dx = 6905;
	cx = 0x400;
	_dosfread();
	_memalloc12k();
	si = 6905;
	cx = 0x40;
loc_1050c:
	_push(cx);
	cx = data.word(k_word_245d4);
	ch = 0;
loc_10513:
	_push(cx);
	bx = 0;
	dx = 0;
	cl = 0;
	al = ds.byte(si);
	_cmp(al, 0x0FE);
		_jz(loc_10565);
	cl = 0x0FF;
	_cmp(al, 0x0FF);
		_jz(loc_1052e);
	_cmp(al, 0x0FB);
		_jnc(loc_10565);
	_inc(al);
	bl = al;
loc_1052e:
	bh = ds.byte(si+1);
	_shr(bh, 3);
	ax = ds.word(si+1);
	_and(ax, 0x0F007);
	_shr(ah, 1);
	_or(al, ah);
	_cmp(al, 0x40);
		_jbe(loc_10544);
	al = 0x0FF;
loc_10544:
	cl = al;
	ax = ds.word(si+2);
	_and(al, 0x0F);
		_jz(loc_10565);
	_cmp(al, 0x0A);
		_ja(loc_10565);
	dh = ah;
	_rol(ebx, 0x10);
	bl = al;
	_and(bx, 0x0F);
	dl = data.byte(kAsc_1058c)[bx];
	_ror(ebx, 0x10);
loc_10565:
	sub_11ba6();
	_add(si, 4);
	_pop(cx);
	_inc(ch);
	_cmp(ch, cl);
		_jc(loc_10513);
	es.byte(di) = 0;
	_inc(di);
	_pop(cx);
	_dec(cx);
		_jnz(loc_1050c);
	_mem_reallocx();
	_pop(cx);
	_dec(cx);
		_jnz(loc_104f9);
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
	return;
/*continuing to unbounded code: loc_103ff from __2stm_module:5-158*/
loc_103ff:
	data.word(k_moduleflag_246d0) = 0x8;
	data.word(k_word_245d4) = 4;
	data.word(k_word_245d2) = 0x1F;
	data.word(k_freq_245de) = 8448;
	al = 0x60;
	sub_13e9b();
	data.byte(k_byte_24679) = ah;
	data.byte(k_byte_2467a) = al;
	ax = data.byte(k_byte_30529);
	data.word(k_word_245f2) = ax;
	ax = ds;
	es = ax;
	si = 6905;
	di = 3151;
	cx = 0x14;
	_copy_printable();
	si = 6953;
	di = 6885;
	cx = data.word(k_word_245d2);
loc_10445:
	_push(cx);
	cx = 0x0C;
	_copy_printable();
	_pop(cx);
	eax = ds.word(si+0x10);
	edx = eax;
	_add(eax, 0x0F);
	_and(al, 0x0F0);
	_cmp(eax, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	ds.dword(di+0x20) = eax;
	_add(data.dword(k_dword_245c4), eax);
	eax = ds.word(si+0x0E);
	_shl(eax, 4);
	ds.dword(di+0x38) = eax;
	ax = ds.word(si+0x18);
	_or(ax, ax);
		_jnz(loc_10487);
	ax = data.word(k_freq_245de);
loc_10487:
	ds.word(di+0x36) = ax;
	al = ds.byte(si+0x16);
	ds.byte(di+0x3D) = al;
	ebx = ds.word(si+0x12);
	ds.dword(di+0x24) = ebx;
	eax = ds.word(si+0x14);
	_cmp(ax, 0x0FFFF);
		_jnz(loc_104b6);
	eax = 0;
	ds.dword(di+0x24) = eax;
	ds.dword(di+0x28) = eax;
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	loc_104c7;
loc_104b6:
	ds.dword(di+0x2C) = eax;
	_sub(eax, ebx);
	_inc(eax);
	ds.dword(di+0x28) = eax;
	_or(ds.byte(di+0x3C), 8);
loc_104c7:
	_add(si, 0x20);
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_10445);
	dx = 6899;
	cx = 0x80;
	eax = 0x410;
	_dosseek();
	si = 6899;
	ax = 0;
loc_104e6:
	_cmp(ds.byte(si), 0x63);
		_jnc(loc_104f2);
	_inc(ax);
	_inc(si);
	_cmp(ax, 0x80);
		_jc(loc_104e6);
loc_104f2:
	data.word(k_word_245fa) = ax;
	cx = data.word(k_word_245f2);
loc_104f9:
	_push(cx);
	dx = 6905;
	cx = 0x400;
	_dosfread();
	_memalloc12k();
	si = 6905;
	cx = 0x40;
loc_1050c:
	_push(cx);
	cx = data.word(k_word_245d4);
	ch = 0;
loc_10513:
	_push(cx);
	bx = 0;
	dx = 0;
	cl = 0;
	al = ds.byte(si);
	_cmp(al, 0x0FE);
		_jz(loc_10565);
	cl = 0x0FF;
	_cmp(al, 0x0FF);
		_jz(loc_1052e);
	_cmp(al, 0x0FB);
		_jnc(loc_10565);
	_inc(al);
	bl = al;
loc_1052e:
	bh = ds.byte(si+1);
	_shr(bh, 3);
	ax = ds.word(si+1);
	_and(ax, 0x0F007);
	_shr(ah, 1);
	_or(al, ah);
	_cmp(al, 0x40);
		_jbe(loc_10544);
	al = 0x0FF;
loc_10544:
	cl = al;
	ax = ds.word(si+2);
	_and(al, 0x0F);
		_jz(loc_10565);
	_cmp(al, 0x0A);
		_ja(loc_10565);
	dh = ah;
	_rol(ebx, 0x10);
	bl = al;
	_and(bx, 0x0F);
	dl = data.byte(kAsc_1058c)[bx];
	_ror(ebx, 0x10);
loc_10565:
	sub_11ba6();
	_add(si, 4);
	_pop(cx);
	_inc(ch);
	_cmp(ch, cl);
		_jc(loc_10513);
	es.byte(di) = 0;
	_inc(di);
	_pop(cx);
	_dec(cx);
		_jnz(loc_1050c);
	_mem_reallocx();
	_pop(cx);
	_dec(cx);
		_jnz(loc_104f9);
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
loc_103ff:
}

void InertiaPlayerContext::_s3m_module() {
	STACK_CHECK;
	data.dword(k_module_type_text) = 0x204D3353;
	data.word(k_moduleflag_246d0) = 0x10;
	data.byte(k_byte_2467e) = 1;
	data.byte(k_byte_24673) = 0x80;
	data.word(k_freq_245de) = 8363;
	data.byte(k_byte_2461a) = 2;
	_cmp(data.word(k_word_30532), 2);
		_jnc(loc_105c7);
	data.byte(k_byte_24673) = 0;
loc_105c7:
	ax = ds;
	es = ax;
	si = 6905;
	di = 3151;
	cx = 0x1C;
	_copy_printable();
	_test(data.word(k_config_word)[1], 0x20);
		_jz(loc_1061e);
	dx = 0x64;
	cl = data.byte(k_byte_3053b);
	_and(cx, 0x7F);
		_jz(loc_10618);
	_test(data.byte(k_byte_3053b), 0x80);
		_jz(loc_105ff);
	ax = 0x0B;
	_mul(cx);
	_shrd(ax, dx, 3);
	_sub(ax, 2);
	cx = ax;
loc_105ff:
	ax = 100;
	_mul(cx);
	cx = '0';
	_div(cx);
	dx = 100;
	_cmp(ax, 100);
		_jbe(loc_10618);
	_cmp(ax, 2500);
		_ja(loc_10618);
	dx = ax;
loc_10618:
	ax = dx;
	_change_amplif();
loc_1061e:
	si = 0;
	di = 6884;
	dx = 0;
	cx = 0x20;
loc_10628:
	al = data.byte(k_byte_30548)[si];
	_cmp(al, 0x0FF);
		_jz(loc_10640);
	dx = si;
	_shr(al, 4);
	ah = 1;
	_cmp(al, 1);
		_jz(loc_1063d);
	ah = 0;
loc_1063d:
	ds.byte(di+0x1D) = ah;
loc_10640:
	_inc(si);
	_add(di, 0x50);
	_dec(cx);
		_jnz(loc_10628);
	_inc(dx);
	data.word(k_word_245d4) = dx;
	cx = data.word(k_word_245d4);
	si = 0;
loc_10652:
	al = data.byte(k_byte_2461e);
	_test(data.byte(k_byte_30548)[si], 8);
		_jz(loc_1065f);
	al = data.byte(k_byte_2461f);
loc_1065f:
	data.dword(k_dword_27bc8)[si] = al;
	_inc(si);
	_dec(cx);
		_jnz(loc_10652);
	ax = data.word(k_word_3052a);
	_cmp(ax, 0x63);
		_jc(loc_10672);
	ax = 0x63;
loc_10672:
	data.word(k_word_245d2) = ax;
	ax = data.word(k_word_3052c);
	_cmp(ax, 0x100);
		_jc(loc_10680);
	ax = 0x100;
loc_10680:
	data.word(k_word_245f2) = ax;
	al = data.byte(k_byte_30539);
	data.byte(k_byte_24679) = al;
	al = data.byte(k_byte_3053a);
	data.byte(k_byte_2467a) = al;
	ax = ds;
	es = ax;
	di = 6885;
	bx = ( data.dword(k_dword_30566)+2);
	_add(bx, data.byte(kUnk_30528));
	ecx = data.word(k_word_245d2);
loc_106a3:
	_push(bx);
	_push(cx);
	dx = 7042;
	cx = 0x50;
	eax = ds.word(bx);
	_shl(eax, 4);
	_dosseek();
	si = 7042;
	eax = 0;
	edx = 0;
	_cmp(ds.byte(si), 1);
		_jnz(loc_106d8);
	eax = ds.word(si+0x10);
	edx = eax;
	_cmp(eax, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
loc_106d8:
	ds.dword(di+0x20) = eax;
	_add(data.dword(k_dword_245c4), eax);
	eax = ds.word(si+0x0E);
	_shl(eax, 4);
	ds.dword(di+0x38) = eax;
	ax = ds.word(si+0x20);
	_or(ax, ax);
		_jnz(loc_106f8);
	ax = data.word(k_freq_245de);
loc_106f8:
	ds.word(di+0x36) = ax;
	al = ds.byte(si+0x1C);
	_cmp(al, 0x3F);
		_jc(loc_10704);
	al = 0x3F;
loc_10704:
	ds.byte(di+0x3D) = al;
	_test(ds.byte(si+0x1F), 1);
		_jnz(loc_10720);
loc_1070d:
	eax = 0;
	ds.dword(di+0x24) = eax;
	ds.dword(di+0x28) = eax;
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	loc_1074f;
loc_10720:
	_cmp(ds.word(si+0x14), 0x0FFFF);
		_jz(loc_1070d);
	edx = ds.word(si+0x14);
	ds.dword(di+0x24) = edx;
	eax = ds.word(si+0x18);
	_or(eax, eax);
		_jz(loc_1070d);
	_dec(eax);
		_jz(loc_1070d);
	ds.dword(di+0x2C) = eax;
	_inc(eax);
	_sub(eax, ds.dword(di+0x24));
	ds.dword(di+0x28) = eax;
	_or(ds.byte(di+0x3C), 8);
loc_1074f:
	_add(si, 0x30);
	cx = 0x1C;
	_copy_printable();
	_pop(cx);
	_pop(bx);
	_add(di, 0x40);
	_add(bx, 2);
	_dec(cx);
		_jnz(loc_106a3);
	si = ( data.dword(k_dword_30566)+2);
	di = 0;
	bx = 0;
	ax = data.byte(kUnk_30528);
	_cmp(ax, 0x80);
	ah = al;
		_ja(loc_1079a);
	cl = 0;
loc_10778:
	al = ds.byte(si);
	_cmp(al, 0x0F0);
		_jnc(loc_1078f);
	data.byte(k_byte_27fe8)[di] = al;
	_inc(bl);
	_inc(di);
	_cmp(cl, 0x0F0);
		_jc(loc_1078f);
	data.byte(k_byte_280e7)[di] = 0x0FF;
loc_1078f:
	cl = al;
	_inc(si);
	_inc(bh);
	_cmp(bh, ah);
		_jc(loc_10778);
	loc_107ac;
loc_1079a:
	al = ds.byte(si);
	_cmp(al, 0x0FF);
		_jz(loc_107ac);
	data.byte(k_byte_27fe8)[di] = al;
	_inc(bl);
	_inc(di);
	_inc(si);
	_cmp(bl, ah);
		_jc(loc_1079a);
loc_107ac:
	bh = 0;
	data.word(k_word_245fa) = bx;
	ax = 0;
loc_107b4:
	_push(ax);
	bx = ( data.dword(k_dword_30566)+2);
	_add(bx, data.byte(kUnk_30528));
	_add(ax, data.word(k_word_3052a));
	_shl(ax, 1);
	_add(bx, ax);
	dx = 7042;
	cx = 2;
	eax = ds.word(bx);
	_or(ax, ax);
		_jnz(loc_107e0);
loc_107d2:
	_memalloc12k();
	cx = 0x40;
	al = 0;
	_write_df(false);
 	_stosb(cx, true);
	loc_108b1;
loc_107e0:
	_shl(eax, 4);
	_dosseek();
	dx = 7042;
	cx = data.word(k_word_31508);
	_cmp(cx, 0x308F);
		_jnc(loc_107d2);
	_add(cx, 0x0F);
	_and(cl, 0x0F0);
	_sub(cx, 2);
	_dosfread();
	_memalloc12k();
	si = 7042;
	cx = 0x40;
loc_10809:
	_push(cx);
	_lodsb();
	_or(al, al);
		_jz(loc_108a6);
loc_10811:
	bx = 0;
	ch = al;
	_test(ch, 0x20);
		_jz(loc_1082d);
	bx = ds.word(si);
	_add(si, 2);
	_cmp(bl, 0x0FE);
		_jnc(loc_10826);
	_inc(bl);
loc_10826:
	_cmp(bh, 0x63);
		_jbe(loc_1082d);
	bh = 0;
loc_1082d:
	cl = 0x0FF;
	_test(ch, 0x40);
		_jz(loc_1083e);
	cl = ds.byte(si);
	_inc(si);
	_cmp(cl, 0x40);
		_jbe(loc_1083e);
	cl = 0x0FF;
loc_1083e:
	_test(ch, 0x80);
		_jz(loc_1088d);
	dx = ds.word(si);
	_add(si, 2);
	_cmp(dl, 0x19);
		_ja(loc_1088d);
	_rol(ebx, 0x10);
	bx = dl;
	dl = data.byte(k_s3mtable_108d6)[bx];
	_cmp(dl, 0x0FF);
		_jz(loc_10885);
	_cmp(dl, 0x0F);
		_jz(loc_10880);
	_cmp(dl, 0x0E);
		_jnz(loc_10887);
	bl = dh;
	_shr(bl, 4);
	al = data.byte(k_s3mtable_108f0)[bx];
	_cmp(al, 0x0FF);
		_jz(loc_10885);
	_shl(al, 4);
	_and(dh, 0x0F);
	_or(dh, al);
	loc_10887;
loc_10880:
	_cmp(dh, 0x20);
		_ja(loc_10887);
loc_10885:
	dx = 0;
loc_10887:
	_ror(ebx, 0x10);
	loc_1088f;
loc_1088d:
	dx = 0;
loc_1088f:
	_and(ch, 0x1F);
	_cmp(data.word(k_word_245d4)[1], ch);
		_jnc(loc_1089c);
	data.word(k_word_245d4)[1] = ch;
loc_1089c:
	sub_11ba6();
	_lodsb();
	_or(al, al);
		_jnz(loc_10811);
loc_108a6:
	es.byte(di) = 0;
	_inc(di);
	_pop(cx);
	_dec(cx);
		_jnz(loc_10809);
loc_108b1:
	_mem_reallocx();
	_pop(ax);
	_inc(ax);
	_cmp(ax, data.word(k_word_245f2));
		_jc(loc_107b4);
	ax = data.word(k_word_245d4);
	_inc(ah);
	_cmp(al, ah);
		_jc(loc_108c9);
	al = ah;
loc_108c9:
	ah = 0;
	data.word(k_word_245d4) = ax;
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
	return;
/*continuing to unbounded code: loc_105c7 from _s3m_module:10-340*/
loc_105c7:
	ax = ds;
	es = ax;
	si = 6905;
	di = 3151;
	cx = 0x1C;
	_copy_printable();
	_test(data.word(k_config_word)[1], 0x20);
		_jz(loc_1061e);
	dx = 0x64;
	cl = data.byte(k_byte_3053b);
	_and(cx, 0x7F);
		_jz(loc_10618);
	_test(data.byte(k_byte_3053b), 0x80);
		_jz(loc_105ff);
	ax = 0x0B;
	_mul(cx);
	_shrd(ax, dx, 3);
	_sub(ax, 2);
	cx = ax;
loc_105ff:
	ax = 100;
	_mul(cx);
	cx = '0';
	_div(cx);
	dx = 100;
	_cmp(ax, 100);
		_jbe(loc_10618);
	_cmp(ax, 2500);
		_ja(loc_10618);
	dx = ax;
loc_10618:
	ax = dx;
	_change_amplif();
loc_1061e:
	si = 0;
	di = 6884;
	dx = 0;
	cx = 0x20;
loc_10628:
	al = data.byte(k_byte_30548)[si];
	_cmp(al, 0x0FF);
		_jz(loc_10640);
	dx = si;
	_shr(al, 4);
	ah = 1;
	_cmp(al, 1);
		_jz(loc_1063d);
	ah = 0;
loc_1063d:
	ds.byte(di+0x1D) = ah;
loc_10640:
	_inc(si);
	_add(di, 0x50);
	_dec(cx);
		_jnz(loc_10628);
	_inc(dx);
	data.word(k_word_245d4) = dx;
	cx = data.word(k_word_245d4);
	si = 0;
loc_10652:
	al = data.byte(k_byte_2461e);
	_test(data.byte(k_byte_30548)[si], 8);
		_jz(loc_1065f);
	al = data.byte(k_byte_2461f);
loc_1065f:
	data.dword(k_dword_27bc8)[si] = al;
	_inc(si);
	_dec(cx);
		_jnz(loc_10652);
	ax = data.word(k_word_3052a);
	_cmp(ax, 0x63);
		_jc(loc_10672);
	ax = 0x63;
loc_10672:
	data.word(k_word_245d2) = ax;
	ax = data.word(k_word_3052c);
	_cmp(ax, 0x100);
		_jc(loc_10680);
	ax = 0x100;
loc_10680:
	data.word(k_word_245f2) = ax;
	al = data.byte(k_byte_30539);
	data.byte(k_byte_24679) = al;
	al = data.byte(k_byte_3053a);
	data.byte(k_byte_2467a) = al;
	ax = ds;
	es = ax;
	di = 6885;
	bx = ( data.dword(k_dword_30566)+2);
	_add(bx, data.byte(kUnk_30528));
	ecx = data.word(k_word_245d2);
loc_106a3:
	_push(bx);
	_push(cx);
	dx = 7042;
	cx = 0x50;
	eax = ds.word(bx);
	_shl(eax, 4);
	_dosseek();
	si = 7042;
	eax = 0;
	edx = 0;
	_cmp(ds.byte(si), 1);
		_jnz(loc_106d8);
	eax = ds.word(si+0x10);
	edx = eax;
	_cmp(eax, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
loc_106d8:
	ds.dword(di+0x20) = eax;
	_add(data.dword(k_dword_245c4), eax);
	eax = ds.word(si+0x0E);
	_shl(eax, 4);
	ds.dword(di+0x38) = eax;
	ax = ds.word(si+0x20);
	_or(ax, ax);
		_jnz(loc_106f8);
	ax = data.word(k_freq_245de);
loc_106f8:
	ds.word(di+0x36) = ax;
	al = ds.byte(si+0x1C);
	_cmp(al, 0x3F);
		_jc(loc_10704);
	al = 0x3F;
loc_10704:
	ds.byte(di+0x3D) = al;
	_test(ds.byte(si+0x1F), 1);
		_jnz(loc_10720);
loc_1070d:
	eax = 0;
	ds.dword(di+0x24) = eax;
	ds.dword(di+0x28) = eax;
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	loc_1074f;
loc_10720:
	_cmp(ds.word(si+0x14), 0x0FFFF);
		_jz(loc_1070d);
	edx = ds.word(si+0x14);
	ds.dword(di+0x24) = edx;
	eax = ds.word(si+0x18);
	_or(eax, eax);
		_jz(loc_1070d);
	_dec(eax);
		_jz(loc_1070d);
	ds.dword(di+0x2C) = eax;
	_inc(eax);
	_sub(eax, ds.dword(di+0x24));
	ds.dword(di+0x28) = eax;
	_or(ds.byte(di+0x3C), 8);
loc_1074f:
	_add(si, 0x30);
	cx = 0x1C;
	_copy_printable();
	_pop(cx);
	_pop(bx);
	_add(di, 0x40);
	_add(bx, 2);
	_dec(cx);
		_jnz(loc_106a3);
	si = ( data.dword(k_dword_30566)+2);
	di = 0;
	bx = 0;
	ax = data.byte(kUnk_30528);
	_cmp(ax, 0x80);
	ah = al;
		_ja(loc_1079a);
	cl = 0;
loc_10778:
	al = ds.byte(si);
	_cmp(al, 0x0F0);
		_jnc(loc_1078f);
	data.byte(k_byte_27fe8)[di] = al;
	_inc(bl);
	_inc(di);
	_cmp(cl, 0x0F0);
		_jc(loc_1078f);
	data.byte(k_byte_280e7)[di] = 0x0FF;
loc_1078f:
	cl = al;
	_inc(si);
	_inc(bh);
	_cmp(bh, ah);
		_jc(loc_10778);
	loc_107ac;
loc_1079a:
	al = ds.byte(si);
	_cmp(al, 0x0FF);
		_jz(loc_107ac);
	data.byte(k_byte_27fe8)[di] = al;
	_inc(bl);
	_inc(di);
	_inc(si);
	_cmp(bl, ah);
		_jc(loc_1079a);
loc_107ac:
	bh = 0;
	data.word(k_word_245fa) = bx;
	ax = 0;
loc_107b4:
	_push(ax);
	bx = ( data.dword(k_dword_30566)+2);
	_add(bx, data.byte(kUnk_30528));
	_add(ax, data.word(k_word_3052a));
	_shl(ax, 1);
	_add(bx, ax);
	dx = 7042;
	cx = 2;
	eax = ds.word(bx);
	_or(ax, ax);
		_jnz(loc_107e0);
loc_107d2:
	_memalloc12k();
	cx = 0x40;
	al = 0;
	_write_df(false);
 	_stosb(cx, true);
	loc_108b1;
loc_107e0:
	_shl(eax, 4);
	_dosseek();
	dx = 7042;
	cx = data.word(k_word_31508);
	_cmp(cx, 0x308F);
		_jnc(loc_107d2);
	_add(cx, 0x0F);
	_and(cl, 0x0F0);
	_sub(cx, 2);
	_dosfread();
	_memalloc12k();
	si = 7042;
	cx = 0x40;
loc_10809:
	_push(cx);
	_lodsb();
	_or(al, al);
		_jz(loc_108a6);
loc_10811:
	bx = 0;
	ch = al;
	_test(ch, 0x20);
		_jz(loc_1082d);
	bx = ds.word(si);
	_add(si, 2);
	_cmp(bl, 0x0FE);
		_jnc(loc_10826);
	_inc(bl);
loc_10826:
	_cmp(bh, 0x63);
		_jbe(loc_1082d);
	bh = 0;
loc_1082d:
	cl = 0x0FF;
	_test(ch, 0x40);
		_jz(loc_1083e);
	cl = ds.byte(si);
	_inc(si);
	_cmp(cl, 0x40);
		_jbe(loc_1083e);
	cl = 0x0FF;
loc_1083e:
	_test(ch, 0x80);
		_jz(loc_1088d);
	dx = ds.word(si);
	_add(si, 2);
	_cmp(dl, 0x19);
		_ja(loc_1088d);
	_rol(ebx, 0x10);
	bx = dl;
	dl = data.byte(k_s3mtable_108d6)[bx];
	_cmp(dl, 0x0FF);
		_jz(loc_10885);
	_cmp(dl, 0x0F);
		_jz(loc_10880);
	_cmp(dl, 0x0E);
		_jnz(loc_10887);
	bl = dh;
	_shr(bl, 4);
	al = data.byte(k_s3mtable_108f0)[bx];
	_cmp(al, 0x0FF);
		_jz(loc_10885);
	_shl(al, 4);
	_and(dh, 0x0F);
	_or(dh, al);
	loc_10887;
loc_10880:
	_cmp(dh, 0x20);
		_ja(loc_10887);
loc_10885:
	dx = 0;
loc_10887:
	_ror(ebx, 0x10);
	loc_1088f;
loc_1088d:
	dx = 0;
loc_1088f:
	_and(ch, 0x1F);
	_cmp(data.word(k_word_245d4)[1], ch);
		_jnc(loc_1089c);
	data.word(k_word_245d4)[1] = ch;
loc_1089c:
	sub_11ba6();
	_lodsb();
	_or(al, al);
		_jnz(loc_10811);
loc_108a6:
	es.byte(di) = 0;
	_inc(di);
	_pop(cx);
	_dec(cx);
		_jnz(loc_10809);
loc_108b1:
	_mem_reallocx();
	_pop(ax);
	_inc(ax);
	_cmp(ax, data.word(k_word_245f2));
		_jc(loc_107b4);
	ax = data.word(k_word_245d4);
	_inc(ah);
	_cmp(al, ah);
		_jc(loc_108c9);
	al = ah;
loc_108c9:
	ah = 0;
	data.word(k_word_245d4) = ax;
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
loc_105c7:
}

void InertiaPlayerContext::_e669_module() {
	STACK_CHECK;
	data.dword(k_module_type_text) = 0x39363645;
	loc_10914;
	data.dword(k_module_type_text) = 0x20393636;
loc_10914:
	data.word(k_moduleflag_246d0) = 0x4;
	data.byte(k_byte_24673) = 0x80;
	data.byte(k_byte_2467e) = 2;
	data.word(k_word_245d4) = 8;
	ax = data.byte(k_byte_30576);
	data.word(k_word_245d2) = ax;
	al = data.byte(k_byte_30577);
	data.word(k_word_245f2) = ax;
	ah = data.byte(k_byte_2461f);
	al = data.byte(k_byte_2461e);
	_shl(eax, 0x10);
	ah = data.byte(k_byte_2461f);
	al = data.byte(k_byte_2461e);
	data.dword(k_dword_27bc8) = eax;
	data.dword(k_dword_27bcc) = eax;
	ax = ds;
	es = ax;
	si = ( data.dword(k_chrin)+1);
	cx = 0x4C;
loc_1095c:
	_inc(si);
	_cmp(ds.byte(si), 0x20);
	if (--cx && flags.z())
		loc_1095c;
	di = 3151;
	cx = 0x20;
	_copy_printable();
	si = 0;
	bh = 0;
loc_1096f:
	bl = data.byte(k_byte_30579)[si];
	_cmp(bl, 0x0FF);
		_jz(loc_10993);
	data.byte(k_byte_27fe8)[si] = bl;
	al = data.byte(k_byte_305f9)[bx];
	data.byte(k_byte_280e8)[si] = al;
	al = data.byte(k_byte_30679)[bx];
	data.byte(k_byte_281e8)[si] = al;
	_inc(si);
	_cmp(si, 0x80);
		_jc(loc_1096f);
loc_10993:
	data.word(k_word_245fa) = si;
	al = data.byte(k_byte_280e8);
	data.byte(k_byte_24679) = al;
	data.byte(k_byte_2467a) = 0x50;
	dx = 6905;
	_mul(cx, data.word(k_word_245d2), 25);
	eax = 497;
	_dosseek();
	si = 6905;
	di = 6885;
	cx = data.word(k_word_245d2);
loc_109bd:
	_push(cx);
	cx = 0x0D;
	_copy_printable();
	_pop(cx);
	edx = ds.dword(si+0x0D);
	_cmp(edx, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	ds.dword(di+0x20) = edx;
	_add(data.dword(k_dword_245c4), edx);
	ds.byte(di+0x3D) = 0x3F;
	ds.word(di+0x36) = 0x2100;
	ebx = ds.dword(si+0x11);
	ds.dword(di+0x24) = ebx;
	eax = ds.dword(si+0x15);
	_cmp(eax, 0x0FFFFF);
		_jc(loc_10a0f);
	eax = 0;
	ds.dword(di+0x24) = eax;
	ds.dword(di+0x28) = eax;
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	loc_10a20;
loc_10a0f:
	ds.dword(di+0x2C) = eax;
	_sub(eax, ebx);
	_inc(eax);
	ds.dword(di+0x28) = eax;
	_or(ds.byte(di+0x3C), 8);
loc_10a20:
	_add(si, 0x19);
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_109bd);
	cx = data.word(k_word_245f2);
loc_10a2d:
	_push(cx);
	dx = 7042;
	cx = 0x600;
	_dosfread();
	_memalloc12k();
	si = 7042;
	cx = 0x40;
loc_10a40:
	_push(cx);
	cx = data.word(k_word_245d4);
	ch = 0;
loc_10a47:
	_push(cx);
	al = ds.byte(si);
	bx = 0;
	cl = 0x0FF;
	_cmp(al, 0x0FF);
		_jz(loc_10a83);
	_cmp(al, 0x0FE);
		_jz(loc_10a75);
	_shr(al, 2);
	ah = 0;
	dl = 0x0C;
	_div(dl);
	_inc(ah);
	_shl(al, 4);
	_or(al, ah);
	bl = al;
	ax = ds.word(si);
	_xchg(al, ah);
	_shr(ax, 4);
	_and(al, 0x3F);
	_inc(al);
	bh = al;
loc_10a75:
	al = ds.byte(si+1);
	_and(al, 0x0F);
	ah = 0x44;
	_mul(ah);
	_shr(ax, 4);
	cl = al;
loc_10a83:
	al = ds.byte(si+2);
	ah = al;
	_and(ah, 0x0F);
	dh = ah;
	_shr(al, 4);
	_cmp(al, 5);
		_ja(loc_10aaa);
	dl = 0x0F;
		_jz(loc_10aac);
	_cmp(al, 4);
		_jz(loc_10aaa);
	_cmp(al, 2);
		_jz(loc_10aaa);
	_cmp(al, 3);
		_jnz(loc_10aaa);
	dl = 1;
	dh = ah;
	loc_10aac;
loc_10aaa:
	dx = 0;
loc_10aac:
	sub_11ba6();
	_add(si, 3);
	_pop(cx);
	_inc(ch);
	_cmp(ch, cl);
		_jc(loc_10a47);
	es.byte(di) = 0;
	_inc(di);
	_pop(cx);
	_dec(cx);
		_jnz(loc_10a40);
	_mem_reallocx();
	_pop(cx);
	_dec(cx);
		_jnz(loc_10a2d);
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
	return;
/*continuing to unbounded code: loc_1095c from _e669_module:25-175*/
loc_1095c:
	_inc(si);
	_cmp(ds.byte(si), 0x20);
	if (--cx && flags.z())
		loc_1095c;
	di = 3151;
	cx = 0x20;
	_copy_printable();
	si = 0;
	bh = 0;
loc_1096f:
	bl = data.byte(k_byte_30579)[si];
	_cmp(bl, 0x0FF);
		_jz(loc_10993);
	data.byte(k_byte_27fe8)[si] = bl;
	al = data.byte(k_byte_305f9)[bx];
	data.byte(k_byte_280e8)[si] = al;
	al = data.byte(k_byte_30679)[bx];
	data.byte(k_byte_281e8)[si] = al;
	_inc(si);
	_cmp(si, 0x80);
		_jc(loc_1096f);
loc_10993:
	data.word(k_word_245fa) = si;
	al = data.byte(k_byte_280e8);
	data.byte(k_byte_24679) = al;
	data.byte(k_byte_2467a) = 0x50;
	dx = 6905;
	_mul(cx, data.word(k_word_245d2), 25);
	eax = 497;
	_dosseek();
	si = 6905;
	di = 6885;
	cx = data.word(k_word_245d2);
loc_109bd:
	_push(cx);
	cx = 0x0D;
	_copy_printable();
	_pop(cx);
	edx = ds.dword(si+0x0D);
	_cmp(edx, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	ds.dword(di+0x20) = edx;
	_add(data.dword(k_dword_245c4), edx);
	ds.byte(di+0x3D) = 0x3F;
	ds.word(di+0x36) = 0x2100;
	ebx = ds.dword(si+0x11);
	ds.dword(di+0x24) = ebx;
	eax = ds.dword(si+0x15);
	_cmp(eax, 0x0FFFFF);
		_jc(loc_10a0f);
	eax = 0;
	ds.dword(di+0x24) = eax;
	ds.dword(di+0x28) = eax;
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	loc_10a20;
loc_10a0f:
	ds.dword(di+0x2C) = eax;
	_sub(eax, ebx);
	_inc(eax);
	ds.dword(di+0x28) = eax;
	_or(ds.byte(di+0x3C), 8);
loc_10a20:
	_add(si, 0x19);
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_109bd);
	cx = data.word(k_word_245f2);
loc_10a2d:
	_push(cx);
	dx = 7042;
	cx = 0x600;
	_dosfread();
	_memalloc12k();
	si = 7042;
	cx = 0x40;
loc_10a40:
	_push(cx);
	cx = data.word(k_word_245d4);
	ch = 0;
loc_10a47:
	_push(cx);
	al = ds.byte(si);
	bx = 0;
	cl = 0x0FF;
	_cmp(al, 0x0FF);
		_jz(loc_10a83);
	_cmp(al, 0x0FE);
		_jz(loc_10a75);
	_shr(al, 2);
	ah = 0;
	dl = 0x0C;
	_div(dl);
	_inc(ah);
	_shl(al, 4);
	_or(al, ah);
	bl = al;
	ax = ds.word(si);
	_xchg(al, ah);
	_shr(ax, 4);
	_and(al, 0x3F);
	_inc(al);
	bh = al;
loc_10a75:
	al = ds.byte(si+1);
	_and(al, 0x0F);
	ah = 0x44;
	_mul(ah);
	_shr(ax, 4);
	cl = al;
loc_10a83:
	al = ds.byte(si+2);
	ah = al;
	_and(ah, 0x0F);
	dh = ah;
	_shr(al, 4);
	_cmp(al, 5);
		_ja(loc_10aaa);
	dl = 0x0F;
		_jz(loc_10aac);
	_cmp(al, 4);
		_jz(loc_10aaa);
	_cmp(al, 2);
		_jz(loc_10aaa);
	_cmp(al, 3);
		_jnz(loc_10aaa);
	dl = 1;
	dh = ah;
	loc_10aac;
loc_10aaa:
	dx = 0;
loc_10aac:
	sub_11ba6();
	_add(si, 3);
	_pop(cx);
	_inc(ch);
	_cmp(ch, cl);
		_jc(loc_10a47);
	es.byte(di) = 0;
	_inc(di);
	_pop(cx);
	_dec(cx);
		_jnz(loc_10a40);
	_mem_reallocx();
	_pop(cx);
	_dec(cx);
		_jnz(loc_10a2d);
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
loc_1095c:
}

void InertiaPlayerContext::_mtm_module() {
	STACK_CHECK;
	data.dword(k_module_type_text) = 0x204D544D;
	data.word(k_moduleflag_246d0) = 0x20;
	data.byte(k_byte_24679) = 6;
	data.byte(k_byte_2467a) = 0x7D;
	data.byte(k_byte_24673) = 0x80;
	ax = ds;
	es = ax;
	si = 6909;
	di = 3151;
	cx = 0x14;
	_copy_printable();
	_cmp(data.byte(k_sndcard_type), 0);
		_jnz(loc_10b25);
	si = 0;
	cx = 0x10;
loc_10b0f:
	al = data.word(k_word_3052a)[si];
	di = ax;
	_and(di, 0x0F);
	al = data.byte(k_byte_13c54)[di];
	data.dword(k_dword_27bc8)[si] = al;
	_inc(si);
	_dec(cx);
		_jnz(loc_10b0f);
loc_10b25:
	ax = data.byte(k_byte_30526);
	data.word(k_word_245d2) = ax;
	al = data.byte(k_byte_30522);
	_inc(al);
	data.word(k_word_245f2) = ax;
	ax = data.byte(k_byte_30523);
	_inc(ax);
	data.word(k_word_245fa) = ax;
	dx = 6905;
	_mul(cx, data.word(k_word_245d2), 0x25);
	_add(cx, 0x0C2);
	eax = 0;
	_dosseek();
	si = 6971;
	di = 6885;
	cx = data.word(k_word_245d2);
	return;
/*continuing to unbounded code: loc_10b0f from _mtm_module:16-41*/
loc_10b0f:
	al = data.word(k_word_3052a)[si];
	di = ax;
	_and(di, 0x0F);
	al = data.byte(k_byte_13c54)[di];
	data.dword(k_dword_27bc8)[si] = al;
	_inc(si);
	_dec(cx);
		_jnz(loc_10b0f);
loc_10b25:
	ax = data.byte(k_byte_30526);
	data.word(k_word_245d2) = ax;
	al = data.byte(k_byte_30522);
	_inc(al);
	data.word(k_word_245f2) = ax;
	ax = data.byte(k_byte_30523);
	_inc(ax);
	data.word(k_word_245fa) = ax;
	dx = 6905;
	_mul(cx, data.word(k_word_245d2), 0x25);
	_add(cx, 0x0C2);
	eax = 0;
	_dosseek();
	si = 6971;
	di = 6885;
	cx = data.word(k_word_245d2);
loc_10b0f:
}

void InertiaPlayerContext::_snd_off_chunk() {
	STACK_CHECK;
loc_10b5a:
	_push(cx);
	cx = 0x16;
	_copy_printable();
	_pop(cx);
	edx = ds.dword(si+0x16);
	_cmp(edx, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	ds.dword(di+0x20) = edx;
	_add(data.dword(k_dword_245c4), edx);
	al = ds.byte(si+0x23);
	ds.byte(di+0x3D) = al;
	al = ds.byte(si+0x22);
	_and(al, 0x0F);
	ds.byte(di+0x3E) = al;
	ax = data.word(k_freq_245de);
	ds.word(di+0x36) = ax;
	ebx = ds.dword(si+0x1A);
	ds.dword(di+0x24) = ebx;
	eax = ds.dword(si+0x1E);
	_cmp(eax, 2);
		_ja(loc_10bb5);
	eax = 0;
	ds.dword(di+0x24) = eax;
	ds.dword(di+0x28) = eax;
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	loc_10bc6;
loc_10bb5:
	ds.dword(di+0x2C) = eax;
	_sub(eax, ebx);
	_inc(eax);
	ds.dword(di+0x28) = eax;
	_or(ds.byte(di+0x3C), 8);
loc_10bc6:
	_add(si, 0x25);
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_10b5a);
	di = 6899;
	cx = 0x20;
	_write_df(false);
 	while(cx--)
		_movsd();
	_mul(ax, data.word(k_word_245d2), 37);
	_add(ax, 0x0C2);
	eax = ax;
	data.dword(k_chrin) = eax;
	eax = data.word(k_word_30520);
	_mul(eax, 192);
	_add(eax, data.dword(k_chrin));
	dx = 7048;
	cx = data.word(k_word_245f2);
	_shl(cx, 6);
	_dosseek();
	si = 7048;
	cx = data.word(k_word_245f2);
	ax = 4;
loc_10c12:
	bp = 1;
loc_10c15:
	_cmp(ds.word(si), 0);
		_jz(loc_10c20);
	_cmp(bp, ax);
		_jc(loc_10c20);
	ax = bp;
loc_10c20:
	_add(si, 2);
	_inc(bp);
	_cmp(bp, 0x20);
		_jbe(loc_10c15);
	_dec(cx);
		_jnz(loc_10c12);
	data.word(k_word_245d4) = ax;
	bx = 7048;
	cx = data.word(k_word_245f2);
loc_10c36:
	_push(bx);
	_push(cx);
	si = 7042;
	cx = data.word(k_word_245d4);
loc_10c3f:
	_push(bx);
	_push(cx);
	_push(si);
	ax = ds.word(bx);
	_or(ax, ax);
		_jnz(loc_10c5a);
	ax = ds;
	es = ax;
	di = si;
	cx = 48;
	eax = 0;
	_write_df(false);
 	while(cx--)
		_stosd();
	loc_10c73;
loc_10c5a:
	_dec(ax);
	eax = ax;
	_mul(eax, 192);
	_add(eax, data.dword(k_chrin));
	dx = si;
	cx = 192;
	_dosseek();
loc_10c73:
	_pop(si);
	_pop(cx);
	_pop(bx);
	_add(bx, 2);
	_add(si, 192);
	_dec(cx);
		_jnz(loc_10c3f);
	_memalloc12k();
	si = 7042;
	cx = 0x40;
loc_10c89:
	_push(cx);
	_push(si);
	cx = data.word(k_word_245d4);
	ch = 0;
loc_10c91:
	_push(cx);
	bx = 0;
	al = ds.byte(si);
	_shr(al, 2);
		_jz(loc_10caa);
	ah = 0;
	dl = 0x0C;
	_div(dl);
	_inc(ah);
	_shl(al, 4);
	_or(al, ah);
	bl = al;
loc_10caa:
	ax = ds.word(si);
	dl = ah;
	_xchg(al, ah);
	_shr(ax, 4);
	_and(al, 0x3F);
	bh = al;
	_and(dl, 0x0F);
	dh = ds.byte(si+2);
	cl = 0x0FF;
	sub_11ba6();
	_add(si, 192);
	_pop(cx);
	_inc(ch);
	_cmp(ch, cl);
		_jc(loc_10c91);
	es.byte(di) = 0;
	_inc(di);
	_pop(si);
	_pop(cx);
	_add(si, 3);
	_dec(cx);
		_jnz(loc_10c89);
	_mem_reallocx();
	_pop(cx);
	_pop(bx);
	_add(bx, 0x40);
	_dec(cx);
		_jnz(loc_10c36);
	ax = 192;
	_mul(data.word(k_word_30520));
	cx = dx;
	_mul(dx, data.word(k_word_245d2), 37);
	_add(dx, 0x0C2);
	_add(dx, data.word(k_word_30524));
	_adc(cx, 0);
	_add(dx, ax);
	_adc(cx, 0);
	ax = data.word(k_word_245f2);
	_shl(ax, 6);
	_add(dx, ax);
	_adc(cx, 0);
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
	_adc(data.word(k_word_24662), 0);
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
	return;
/*continuing to unbounded code: loc_10b5a from _snd_off_chunk:1-186*/
loc_10b5a:
	_push(cx);
	cx = 0x16;
	_copy_printable();
	_pop(cx);
	edx = ds.dword(si+0x16);
	_cmp(edx, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	ds.dword(di+0x20) = edx;
	_add(data.dword(k_dword_245c4), edx);
	al = ds.byte(si+0x23);
	ds.byte(di+0x3D) = al;
	al = ds.byte(si+0x22);
	_and(al, 0x0F);
	ds.byte(di+0x3E) = al;
	ax = data.word(k_freq_245de);
	ds.word(di+0x36) = ax;
	ebx = ds.dword(si+0x1A);
	ds.dword(di+0x24) = ebx;
	eax = ds.dword(si+0x1E);
	_cmp(eax, 2);
		_ja(loc_10bb5);
	eax = 0;
	ds.dword(di+0x24) = eax;
	ds.dword(di+0x28) = eax;
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	loc_10bc6;
loc_10bb5:
	ds.dword(di+0x2C) = eax;
	_sub(eax, ebx);
	_inc(eax);
	ds.dword(di+0x28) = eax;
	_or(ds.byte(di+0x3C), 8);
loc_10bc6:
	_add(si, 0x25);
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_10b5a);
	di = 6899;
	cx = 0x20;
	_write_df(false);
 	while(cx--)
		_movsd();
	_mul(ax, data.word(k_word_245d2), 37);
	_add(ax, 0x0C2);
	eax = ax;
	data.dword(k_chrin) = eax;
	eax = data.word(k_word_30520);
	_mul(eax, 192);
	_add(eax, data.dword(k_chrin));
	dx = 7048;
	cx = data.word(k_word_245f2);
	_shl(cx, 6);
	_dosseek();
	si = 7048;
	cx = data.word(k_word_245f2);
	ax = 4;
loc_10c12:
	bp = 1;
loc_10c15:
	_cmp(ds.word(si), 0);
		_jz(loc_10c20);
	_cmp(bp, ax);
		_jc(loc_10c20);
	ax = bp;
loc_10c20:
	_add(si, 2);
	_inc(bp);
	_cmp(bp, 0x20);
		_jbe(loc_10c15);
	_dec(cx);
		_jnz(loc_10c12);
	data.word(k_word_245d4) = ax;
	bx = 7048;
	cx = data.word(k_word_245f2);
loc_10c36:
	_push(bx);
	_push(cx);
	si = 7042;
	cx = data.word(k_word_245d4);
loc_10c3f:
	_push(bx);
	_push(cx);
	_push(si);
	ax = ds.word(bx);
	_or(ax, ax);
		_jnz(loc_10c5a);
	ax = ds;
	es = ax;
	di = si;
	cx = 48;
	eax = 0;
	_write_df(false);
 	while(cx--)
		_stosd();
	loc_10c73;
loc_10c5a:
	_dec(ax);
	eax = ax;
	_mul(eax, 192);
	_add(eax, data.dword(k_chrin));
	dx = si;
	cx = 192;
	_dosseek();
loc_10c73:
	_pop(si);
	_pop(cx);
	_pop(bx);
	_add(bx, 2);
	_add(si, 192);
	_dec(cx);
		_jnz(loc_10c3f);
	_memalloc12k();
	si = 7042;
	cx = 0x40;
loc_10c89:
	_push(cx);
	_push(si);
	cx = data.word(k_word_245d4);
	ch = 0;
loc_10c91:
	_push(cx);
	bx = 0;
	al = ds.byte(si);
	_shr(al, 2);
		_jz(loc_10caa);
	ah = 0;
	dl = 0x0C;
	_div(dl);
	_inc(ah);
	_shl(al, 4);
	_or(al, ah);
	bl = al;
loc_10caa:
	ax = ds.word(si);
	dl = ah;
	_xchg(al, ah);
	_shr(ax, 4);
	_and(al, 0x3F);
	bh = al;
	_and(dl, 0x0F);
	dh = ds.byte(si+2);
	cl = 0x0FF;
	sub_11ba6();
	_add(si, 192);
	_pop(cx);
	_inc(ch);
	_cmp(ch, cl);
		_jc(loc_10c91);
	es.byte(di) = 0;
	_inc(di);
	_pop(si);
	_pop(cx);
	_add(si, 3);
	_dec(cx);
		_jnz(loc_10c89);
	_mem_reallocx();
	_pop(cx);
	_pop(bx);
	_add(bx, 0x40);
	_dec(cx);
		_jnz(loc_10c36);
	ax = 192;
	_mul(data.word(k_word_30520));
	cx = dx;
	_mul(dx, data.word(k_word_245d2), 37);
	_add(dx, 0x0C2);
	_add(dx, data.word(k_word_30524));
	_adc(cx, 0);
	_add(dx, ax);
	_adc(cx, 0);
	ax = data.word(k_word_245f2);
	_shl(ax, 6);
	_add(dx, ax);
	_adc(cx, 0);
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
	_adc(data.word(k_word_24662), 0);
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
loc_10b5a:
}

void InertiaPlayerContext::_psm_module() {
	STACK_CHECK;
	data.dword(k_module_type_text) = 0x204D5350;
	data.word(k_moduleflag_246d0) = 0x40;
	ax = data.word(k_word_30556);
	data.word(k_word_245d4) = ax;
	ax = data.word(k_word_30554);
	data.word(k_word_245d2) = ax;
	data.word(k_freq_245de) = 8448;
	al = data.byte(k_byte_3054b);
	data.byte(k_byte_24679) = al;
	al = data.byte(k_byte_3054c);
	data.byte(k_byte_2467a) = al;
	ax = data.byte(k_byte_30550);
	data.word(k_word_245fa) = ax;
	ax = data.word(k_word_30552);
	data.word(k_word_245f2) = ax;
	ax = ds;
	es = ax;
	si = 6909;
	di = 3151;
	cx = 30;
	_copy_printable();
	dx = 7019;
	cx = data.word(k_word_245d2);
	_shl(cx, 6);
	eax = data.dword(k_dword_30566);
	_dosseek();
	si = 7019;
	di = 6885;
	cx = data.word(k_word_245d2);
loc_10d8c:
	_push(cx);
	_push(si);
	_add(si, 0x0D);
	cx = 0x16;
	_copy_printable();
	_pop(si);
	_pop(cx);
	edx = ds.dword(si+0x30);
	_cmp(edx, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	ds.dword(di+0x20) = edx;
	_add(data.dword(k_dword_245c4), edx);
	ds.byte(di+0x3F) = 1;
	eax = ds.dword(si+0x25);
	ds.dword(di+0x38) = eax;
	ax = ds.word(si+0x3E);
		_jnz(loc_10dc7);
	ax = data.word(k_freq_245de);
loc_10dc7:
	ds.word(di+0x36) = ax;
	al = ds.byte(si+0x3D);
	ds.byte(di+0x3D) = al;
	ebx = ds.dword(si+0x34);
	ds.dword(di+0x24) = ebx;
	_or(ebx, ebx);
		_jnz(loc_10df0);
	eax = 0;
	ds.dword(di+0x24) = eax;
	ds.dword(di+0x28) = eax;
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	loc_10e19;
loc_10df0:
	eax = ds.dword(si+0x38);
	ds.dword(di+0x28) = eax;
	_add(eax, ebx);
	_dec(eax);
	ds.dword(di+0x2C) = eax;
	_cmp(eax, edx);
		_jc(loc_10e15);
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	_sub(edx, ebx);
	_inc(edx);
	ds.dword(di+0x28) = edx;
loc_10e15:
	_or(ds.byte(di+0x3C), 8);
loc_10e19:
	_add(si, 0x40);
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_10d8c);
	dx = 6899;
	cx = data.word(k_word_245fa);
	eax = data.dword(k_dword_3055a);
	_dosseek();
	dx = data.word(k_word_30562);
	cx = data.word(k_word_30564);
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
	_adc(data.word(k_word_24662), 0);
	cx = data.word(k_word_245f2);
loc_10e4c:
	_push(cx);
	dx = 7042;
	cx = 4;
	_dosfread();
	si = 0;
	cx = data.word(k_word_245fa);
	ax = data.word(k_my_seg_index);
	dl = data.byte(k_byte_3150a);
	_dec(dl);
	_and(dl, 0x3F);
loc_10e68:
	_cmp(data.byte(k_byte_27fe8)[si], al);
		_jnz(loc_10e72);
	data.byte(k_byte_281e8)[si] = dl;
loc_10e72:
	_inc(si);
	_dec(cx);
		_jnz(loc_10e68);
	dx = 7046;
	cx = data.word(k_word_31508);
	_sub(cx, 4);
	_dosfread();
	_memalloc12k();
	si = 7046;
	cx = 0x40;
loc_10e8c:
	_push(cx);
	_lodsb();
	_or(al, al);
		_jz(loc_10ef4);
loc_10e92:
	bx = 0;
	ch = al;
	_test(ch, 0x80);
		_jz(loc_10ebd);
	bx = ds.word(si);
	_add(si, 2);
	_or(bl, bl);
		_jz(loc_10eb6);
	_dec(bl);
	ax = bl;
	bl = 0x0C;
	_div(bl);
	_inc(ah);
	_shl(al, 4);
	_or(al, ah);
	bl = al;
loc_10eb6:
	_cmp(bh, 0x63);
		_jbe(loc_10ebd);
	bh = 0;
loc_10ebd:
	cl = 0x0FF;
	_test(ch, 0x40);
		_jz(loc_10ece);
	cl = ds.byte(si);
	_inc(si);
	_cmp(cl, 0x40);
		_jbe(loc_10ece);
	cl = 0x0FF;
loc_10ece:
	_test(ch, 0x20);
		_jz(loc_10edd);
	dx = ds.word(si);
	_add(si, 2);
	_cmp(dl, 0x0F);
		_jbe(loc_10edf);
loc_10edd:
	dx = 0;
loc_10edf:
	_and(ch, 0x1F);
	_cmp(data.word(k_word_245d4)[1], ch);
		_jnc(loc_10eec);
	data.word(k_word_245d4)[1] = ch;
loc_10eec:
	sub_11ba6();
	_lodsb();
	_or(al, al);
		_jnz(loc_10e92);
loc_10ef4:
	es.byte(di) = 0;
	_inc(di);
	_pop(cx);
	_dec(cx);
		_jnz(loc_10e8c);
	_mem_reallocx();
	_pop(cx);
	_dec(cx);
		_jnz(loc_10e4c);
	ax = data.word(k_word_245d4);
	_inc(ah);
	_cmp(al, ah);
		_jc(loc_10f11);
	al = ah;
loc_10f11:
	ah = 0;
	data.word(k_word_245d4) = ax;
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
	return;
/*continuing to unbounded code: loc_10d8c from _psm_module:30-195*/
loc_10d8c:
	_push(cx);
	_push(si);
	_add(si, 0x0D);
	cx = 0x16;
	_copy_printable();
	_pop(si);
	_pop(cx);
	edx = ds.dword(si+0x30);
	_cmp(edx, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	ds.dword(di+0x20) = edx;
	_add(data.dword(k_dword_245c4), edx);
	ds.byte(di+0x3F) = 1;
	eax = ds.dword(si+0x25);
	ds.dword(di+0x38) = eax;
	ax = ds.word(si+0x3E);
		_jnz(loc_10dc7);
	ax = data.word(k_freq_245de);
loc_10dc7:
	ds.word(di+0x36) = ax;
	al = ds.byte(si+0x3D);
	ds.byte(di+0x3D) = al;
	ebx = ds.dword(si+0x34);
	ds.dword(di+0x24) = ebx;
	_or(ebx, ebx);
		_jnz(loc_10df0);
	eax = 0;
	ds.dword(di+0x24) = eax;
	ds.dword(di+0x28) = eax;
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	loc_10e19;
loc_10df0:
	eax = ds.dword(si+0x38);
	ds.dword(di+0x28) = eax;
	_add(eax, ebx);
	_dec(eax);
	ds.dword(di+0x2C) = eax;
	_cmp(eax, edx);
		_jc(loc_10e15);
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	_sub(edx, ebx);
	_inc(edx);
	ds.dword(di+0x28) = edx;
loc_10e15:
	_or(ds.byte(di+0x3C), 8);
loc_10e19:
	_add(si, 0x40);
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_10d8c);
	dx = 6899;
	cx = data.word(k_word_245fa);
	eax = data.dword(k_dword_3055a);
	_dosseek();
	dx = data.word(k_word_30562);
	cx = data.word(k_word_30564);
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
	_adc(data.word(k_word_24662), 0);
	cx = data.word(k_word_245f2);
loc_10e4c:
	_push(cx);
	dx = 7042;
	cx = 4;
	_dosfread();
	si = 0;
	cx = data.word(k_word_245fa);
	ax = data.word(k_my_seg_index);
	dl = data.byte(k_byte_3150a);
	_dec(dl);
	_and(dl, 0x3F);
loc_10e68:
	_cmp(data.byte(k_byte_27fe8)[si], al);
		_jnz(loc_10e72);
	data.byte(k_byte_281e8)[si] = dl;
loc_10e72:
	_inc(si);
	_dec(cx);
		_jnz(loc_10e68);
	dx = 7046;
	cx = data.word(k_word_31508);
	_sub(cx, 4);
	_dosfread();
	_memalloc12k();
	si = 7046;
	cx = 0x40;
loc_10e8c:
	_push(cx);
	_lodsb();
	_or(al, al);
		_jz(loc_10ef4);
loc_10e92:
	bx = 0;
	ch = al;
	_test(ch, 0x80);
		_jz(loc_10ebd);
	bx = ds.word(si);
	_add(si, 2);
	_or(bl, bl);
		_jz(loc_10eb6);
	_dec(bl);
	ax = bl;
	bl = 0x0C;
	_div(bl);
	_inc(ah);
	_shl(al, 4);
	_or(al, ah);
	bl = al;
loc_10eb6:
	_cmp(bh, 0x63);
		_jbe(loc_10ebd);
	bh = 0;
loc_10ebd:
	cl = 0x0FF;
	_test(ch, 0x40);
		_jz(loc_10ece);
	cl = ds.byte(si);
	_inc(si);
	_cmp(cl, 0x40);
		_jbe(loc_10ece);
	cl = 0x0FF;
loc_10ece:
	_test(ch, 0x20);
		_jz(loc_10edd);
	dx = ds.word(si);
	_add(si, 2);
	_cmp(dl, 0x0F);
		_jbe(loc_10edf);
loc_10edd:
	dx = 0;
loc_10edf:
	_and(ch, 0x1F);
	_cmp(data.word(k_word_245d4)[1], ch);
		_jnc(loc_10eec);
	data.word(k_word_245d4)[1] = ch;
loc_10eec:
	sub_11ba6();
	_lodsb();
	_or(al, al);
		_jnz(loc_10e92);
loc_10ef4:
	es.byte(di) = 0;
	_inc(di);
	_pop(cx);
	_dec(cx);
		_jnz(loc_10e8c);
	_mem_reallocx();
	_pop(cx);
	_dec(cx);
		_jnz(loc_10e4c);
	ax = data.word(k_word_245d4);
	_inc(ah);
	_cmp(al, ah);
		_jc(loc_10f11);
	al = ah;
loc_10f11:
	ah = 0;
	data.word(k_word_245d4) = ax;
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
loc_10d8c:
}

void InertiaPlayerContext::_far_module() {
	STACK_CHECK;
	data.dword(k_module_type_text) = 0x20524146;
	data.word(k_moduleflag_246d0) = 0x80;
	data.byte(k_byte_24673) = 0;
	data.byte(k_byte_2467e) = 2;
	data.word(k_word_245d4) = 0x10;
	al = data.word(k_word_30552)[1];
	_and(ax, 0x0F);
	di = ax;
	al = data.byte(k_table_14057)[di];
	data.byte(k_byte_2467b) = al;
	data.byte(k_byte_2467c) = 0;
	_calc_14043();
	data.byte(k_byte_2467a) = al;
	data.byte(k_byte_24679) = 4;
	_cmp(data.byte(k_sndcard_type), 0);
		_jnz(loc_10f80);
	si = 0;
	cx = data.word(k_word_245d4);
loc_10f6a:
	al = data.word(k_word_30554)[si];
	di = ax;
	_and(di, 0x0F);
	al = data.byte(k_byte_13c54)[di];
	data.dword(k_dword_27bc8)[si] = al;
	_inc(si);
	_dec(cx);
		_jnz(loc_10f6a);
loc_10f80:
	ax = ds;
	es = ax;
	si = 6909;
	di = 3151;
	cx = 0x20;
	_copy_printable();
	dx = ( data.dword(k_dword_30566)+2);
	cx = 0x303;
	eax = data.dword(k_dword_30566)[2];
	_add(eax, 0x62);
	_dosseek();
	ax = data.byte(k_byte_30669);
	_cmp(ax, 0x100);
		_jc(loc_10fb0);
	ax = 0x100;
loc_10fb0:
	data.word(k_word_245fa) = ax;
	ax = data.byte(k_byte_3066a);
	data.word(k_word_245f8) = ax;
	si = ( data.dword(k_dword_30566)+2);
	di = 6899;
	cx = data.word(k_word_245fa);
	_write_df(false);
 	_movsb(cx, true);
	bx = 7032;
	ax = 0;
	dx = 0;
loc_10fcf:
	_inc(dx);
	_cmp(ds.word(bx), 0);
		_jz(loc_10fd7);
	ax = dx;
loc_10fd7:
	_add(bx, 2);
	_cmp(dx, 0x100);
		_jc(loc_10fcf);
	_or(ax, ax);
	_write_cf(true);
 		_jz(loc_10099);
	_cmp(ax, 0x100);
		_jc(loc_10fef);
	ax = 0x100;
loc_10fef:
	data.word(k_word_245f2) = ax;
	data.dword(k_chrin)[3] = 0;
	si = 7032;
	cx = data.word(k_word_245f2);
loc_10ffe:
	_push(cx);
	_push(si);
	ax = ds.word(si);
	_or(ax, ax);
		_jnz(loc_1100f);
	_memalloc12k();
	cx = 0x40;
	loc_11120;
loc_1100f:
	_sub(ax, 2);
	_shr(ax, 2);
	dx = 0;
	_div(data.word(k_word_245d4));
	_push(ax);
	_dec(al);
	_and(al, 0x3F);
	data.dword(k_chrin) = al;
	di = 0;
	cx = data.word(k_word_245fa);
	ah = data.dword(k_chrin)[3];
loc_1102d:
	_cmp(ah, data.byte(k_byte_27fe8)[di]);
		_jnz(loc_11037);
	data.byte(k_byte_281e8)[di] = al;
loc_11037:
	_inc(di);
	_dec(cx);
		_jnz(loc_1102d);
	dx = 7042;
	cx = ds.word(si);
	_dosfread();
	data.dword(k_chrin)[1] = 0;
	_memalloc12k();
	_pop(cx);
	ch = 0;
	si = 7044;
loc_11051:
	_push(cx);
	cx = data.word(k_word_245d4);
	ch = 0;
loc_11058:
	_push(cx);
	bx = 0;
	cl = 0x0FF;
	al = ds.byte(si);
	_or(al, al);
		_jz(loc_11082);
	_dec(al);
	ah = 0;
	dl = 0x0C;
	_div(dl);
	_inc(al);
	_inc(ah);
	_shl(al, 4);
	_or(al, ah);
	bl = al;
	bh = ds.byte(si+1);
	_inc(bh);
	_cmp(bh, 0x63);
		_jc(loc_11082);
	bh = 0;
loc_11082:
	cl = 0x0FF;
	al = ds.byte(si+2);
	_or(al, al);
		_jz(loc_11094);
	_dec(al);
	_and(al, 0x0F);
	_shl(al, 2);
	cl = al;
loc_11094:
	dl = ds.byte(si+3);
	dh = dl;
	_shr(dl, 4);
	_and(dh, 0x0F);
	_cmp(dl, 3);
		_jz(loc_110cb);
	_cmp(dl, 4);
		_jz(loc_110e4);
	_cmp(dl, 5);
		_jz(loc_110cf);
	_cmp(dl, 6);
		_jz(loc_110d9);
	_cmp(dl, 0x0B);
		_jz(loc_110fa);
	_cmp(dl, 0x0D);
		_jz(loc_110ef);
	_cmp(dl, 0x0E);
		_jz(loc_110f3);
	_cmp(dl, 0x0F);
		_jz(loc_110eb);
	dx = 0;
	loc_110ff;
loc_110cb:
	dl = 0x19;
	loc_110ff;
loc_110cf:
	_shr(dh, 1);
	data.dword(k_chrin)[1] = dh;
	dx = 0;
	loc_110ff;
loc_110d9:
	_shl(dh, 4);
	_or(dh, data.dword(k_chrin)[1]);
	dl = 4;
	loc_110ff;
loc_110e4:
	dl = 0x0E;
	_or(dh, 0x90);
	loc_110ff;
loc_110eb:
	dl = 0x1F;
	loc_110ff;
loc_110ef:
	dl = 0x20;
	loc_110ff;
loc_110f3:
	dl = 0x20;
	_shl(dh, 4);
	loc_110ff;
loc_110fa:
	dl = 0x0E;
	_or(dh, 0x80);
loc_110ff:
	sub_11ba6();
	_add(si, 4);
	_pop(cx);
	_inc(ch);
	_cmp(ch, cl);
		_jc(loc_11058);
	es.byte(di) = 0;
	_inc(di);
	_pop(cx);
	_dec(cx);
		_jnz(loc_11051);
	cx = 0x3F;
	_sub(cl, data.dword(k_chrin));
loc_11120:
	al = 0;
	_write_df(false);
 	_stosb(cx, true);
	_mem_reallocx();
	_pop(si);
	_pop(cx);
	_inc(data.dword(k_chrin)[3]);
	_add(si, 2);
	_dec(cx);
		_jnz(loc_10ffe);
	ax = ds;
	es = ax;
	dx = 6909;
	cx = 8;
	_dosfread();
	si = 6909;
	di = 6885;
	ax = 0;
	data.word(k_word_245d2) = ax;
	ch = 8;
loc_11150:
	cl = 8;
loc_11152:
	_inc(ax);
	_shr(ds.byte(si), 1);
		_jnc(loc_11217);
	_push(ax);
	_push(cx);
	_push(si);
	_push(di);
	data.word(k_word_245d2) = ax;
	_push(di);
	dx = 7042;
	cx = 0x30;
	_dosfread();
	dx = 0;
	cx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4201;
	// _int(0x21);
	_pop(di);
	ds.word(di+0x38) = ax;
	ds.word(di+0x3A) = dx;
	si = 7042;
	edx = ds.dword(si+0x20);
	_cmp(edx, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	ds.dword(di+0x20) = edx;
	_add(data.dword(k_dword_245c4), edx);
	al = ds.byte(si+0x25);
	_ror(al, 4);
	_shr(al, 2);
	ds.byte(di+0x3D) = al;
	ax = data.word(k_freq_245de);
	ds.word(di+0x36) = ax;
	_test(ds.byte(si+0x2F), 8);
		_jnz(loc_111c6);
loc_111b3:
	eax = 0;
	ds.dword(di+0x24) = eax;
	ds.dword(di+0x28) = eax;
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	loc_111e8;
loc_111c6:
	eax = ds.dword(si+0x2A);
	_or(eax, eax);
		_jz(loc_111b3);
	ds.dword(di+0x2C) = eax;
	ebx = ds.dword(si+0x26);
	ds.dword(di+0x24) = ebx;
	_sub(eax, ebx);
	_inc(eax);
	ds.dword(di+0x28) = eax;
	_or(ds.byte(di+0x3C), 8);
loc_111e8:
	cx = 0x20;
	_copy_printable();
	_test(ds.byte(si+0x2E), 1);
		_jz(loc_11204);
	_or(ds.byte(di+0x3C), 4);
	_shr(ds.dword(di+0x24), 1);
	_shr(ds.dword(di+0x2C), 1);
	_shr(ds.dword(di+0x28), 1);
loc_11204:
	dx = ds.word(si+0x20);
	cx = ds.word(si+0x22);
	bx = data.word(k_fhandle_module);
	ax = 0x4201;
	// _int(0x21);
	_pop(di);
	_pop(si);
	_pop(cx);
	_pop(ax);
loc_11217:
	_add(di, 0x40);
	_dec(cl);
		_jnz(loc_11152);
	_inc(si);
	_dec(ch);
		_jnz(loc_11150);
	_cmp(data.word(k_word_245d2), 0);
	_write_cf(true);
 		_jz(loc_10099);
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
	return;
/*continuing to unbounded code: loc_10f6a from _far_module:19-333*/
loc_10f6a:
	al = data.word(k_word_30554)[si];
	di = ax;
	_and(di, 0x0F);
	al = data.byte(k_byte_13c54)[di];
	data.dword(k_dword_27bc8)[si] = al;
	_inc(si);
	_dec(cx);
		_jnz(loc_10f6a);
loc_10f80:
	ax = ds;
	es = ax;
	si = 6909;
	di = 3151;
	cx = 0x20;
	_copy_printable();
	dx = ( data.dword(k_dword_30566)+2);
	cx = 0x303;
	eax = data.dword(k_dword_30566)[2];
	_add(eax, 0x62);
	_dosseek();
	ax = data.byte(k_byte_30669);
	_cmp(ax, 0x100);
		_jc(loc_10fb0);
	ax = 0x100;
loc_10fb0:
	data.word(k_word_245fa) = ax;
	ax = data.byte(k_byte_3066a);
	data.word(k_word_245f8) = ax;
	si = ( data.dword(k_dword_30566)+2);
	di = 6899;
	cx = data.word(k_word_245fa);
	_write_df(false);
 	_movsb(cx, true);
	bx = 7032;
	ax = 0;
	dx = 0;
loc_10fcf:
	_inc(dx);
	_cmp(ds.word(bx), 0);
		_jz(loc_10fd7);
	ax = dx;
loc_10fd7:
	_add(bx, 2);
	_cmp(dx, 0x100);
		_jc(loc_10fcf);
	_or(ax, ax);
	_write_cf(true);
 		_jz(loc_10099);
	_cmp(ax, 0x100);
		_jc(loc_10fef);
	ax = 0x100;
loc_10fef:
	data.word(k_word_245f2) = ax;
	data.dword(k_chrin)[3] = 0;
	si = 7032;
	cx = data.word(k_word_245f2);
loc_10ffe:
	_push(cx);
	_push(si);
	ax = ds.word(si);
	_or(ax, ax);
		_jnz(loc_1100f);
	_memalloc12k();
	cx = 0x40;
	loc_11120;
loc_1100f:
	_sub(ax, 2);
	_shr(ax, 2);
	dx = 0;
	_div(data.word(k_word_245d4));
	_push(ax);
	_dec(al);
	_and(al, 0x3F);
	data.dword(k_chrin) = al;
	di = 0;
	cx = data.word(k_word_245fa);
	ah = data.dword(k_chrin)[3];
loc_1102d:
	_cmp(ah, data.byte(k_byte_27fe8)[di]);
		_jnz(loc_11037);
	data.byte(k_byte_281e8)[di] = al;
loc_11037:
	_inc(di);
	_dec(cx);
		_jnz(loc_1102d);
	dx = 7042;
	cx = ds.word(si);
	_dosfread();
	data.dword(k_chrin)[1] = 0;
	_memalloc12k();
	_pop(cx);
	ch = 0;
	si = 7044;
loc_11051:
	_push(cx);
	cx = data.word(k_word_245d4);
	ch = 0;
loc_11058:
	_push(cx);
	bx = 0;
	cl = 0x0FF;
	al = ds.byte(si);
	_or(al, al);
		_jz(loc_11082);
	_dec(al);
	ah = 0;
	dl = 0x0C;
	_div(dl);
	_inc(al);
	_inc(ah);
	_shl(al, 4);
	_or(al, ah);
	bl = al;
	bh = ds.byte(si+1);
	_inc(bh);
	_cmp(bh, 0x63);
		_jc(loc_11082);
	bh = 0;
loc_11082:
	cl = 0x0FF;
	al = ds.byte(si+2);
	_or(al, al);
		_jz(loc_11094);
	_dec(al);
	_and(al, 0x0F);
	_shl(al, 2);
	cl = al;
loc_11094:
	dl = ds.byte(si+3);
	dh = dl;
	_shr(dl, 4);
	_and(dh, 0x0F);
	_cmp(dl, 3);
		_jz(loc_110cb);
	_cmp(dl, 4);
		_jz(loc_110e4);
	_cmp(dl, 5);
		_jz(loc_110cf);
	_cmp(dl, 6);
		_jz(loc_110d9);
	_cmp(dl, 0x0B);
		_jz(loc_110fa);
	_cmp(dl, 0x0D);
		_jz(loc_110ef);
	_cmp(dl, 0x0E);
		_jz(loc_110f3);
	_cmp(dl, 0x0F);
		_jz(loc_110eb);
	dx = 0;
	loc_110ff;
loc_110cb:
	dl = 0x19;
	loc_110ff;
loc_110cf:
	_shr(dh, 1);
	data.dword(k_chrin)[1] = dh;
	dx = 0;
	loc_110ff;
loc_110d9:
	_shl(dh, 4);
	_or(dh, data.dword(k_chrin)[1]);
	dl = 4;
	loc_110ff;
loc_110e4:
	dl = 0x0E;
	_or(dh, 0x90);
	loc_110ff;
loc_110eb:
	dl = 0x1F;
	loc_110ff;
loc_110ef:
	dl = 0x20;
	loc_110ff;
loc_110f3:
	dl = 0x20;
	_shl(dh, 4);
	loc_110ff;
loc_110fa:
	dl = 0x0E;
	_or(dh, 0x80);
loc_110ff:
	sub_11ba6();
	_add(si, 4);
	_pop(cx);
	_inc(ch);
	_cmp(ch, cl);
		_jc(loc_11058);
	es.byte(di) = 0;
	_inc(di);
	_pop(cx);
	_dec(cx);
		_jnz(loc_11051);
	cx = 0x3F;
	_sub(cl, data.dword(k_chrin));
loc_11120:
	al = 0;
	_write_df(false);
 	_stosb(cx, true);
	_mem_reallocx();
	_pop(si);
	_pop(cx);
	_inc(data.dword(k_chrin)[3]);
	_add(si, 2);
	_dec(cx);
		_jnz(loc_10ffe);
	ax = ds;
	es = ax;
	dx = 6909;
	cx = 8;
	_dosfread();
	si = 6909;
	di = 6885;
	ax = 0;
	data.word(k_word_245d2) = ax;
	ch = 8;
loc_11150:
	cl = 8;
loc_11152:
	_inc(ax);
	_shr(ds.byte(si), 1);
		_jnc(loc_11217);
	_push(ax);
	_push(cx);
	_push(si);
	_push(di);
	data.word(k_word_245d2) = ax;
	_push(di);
	dx = 7042;
	cx = 0x30;
	_dosfread();
	dx = 0;
	cx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4201;
	// _int(0x21);
	_pop(di);
	ds.word(di+0x38) = ax;
	ds.word(di+0x3A) = dx;
	si = 7042;
	edx = ds.dword(si+0x20);
	_cmp(edx, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	ds.dword(di+0x20) = edx;
	_add(data.dword(k_dword_245c4), edx);
	al = ds.byte(si+0x25);
	_ror(al, 4);
	_shr(al, 2);
	ds.byte(di+0x3D) = al;
	ax = data.word(k_freq_245de);
	ds.word(di+0x36) = ax;
	_test(ds.byte(si+0x2F), 8);
		_jnz(loc_111c6);
loc_111b3:
	eax = 0;
	ds.dword(di+0x24) = eax;
	ds.dword(di+0x28) = eax;
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	loc_111e8;
loc_111c6:
	eax = ds.dword(si+0x2A);
	_or(eax, eax);
		_jz(loc_111b3);
	ds.dword(di+0x2C) = eax;
	ebx = ds.dword(si+0x26);
	ds.dword(di+0x24) = ebx;
	_sub(eax, ebx);
	_inc(eax);
	ds.dword(di+0x28) = eax;
	_or(ds.byte(di+0x3C), 8);
loc_111e8:
	cx = 0x20;
	_copy_printable();
	_test(ds.byte(si+0x2E), 1);
		_jz(loc_11204);
	_or(ds.byte(di+0x3C), 4);
	_shr(ds.dword(di+0x24), 1);
	_shr(ds.dword(di+0x2C), 1);
	_shr(ds.dword(di+0x28), 1);
loc_11204:
	dx = ds.word(si+0x20);
	cx = ds.word(si+0x22);
	bx = data.word(k_fhandle_module);
	ax = 0x4201;
	// _int(0x21);
	_pop(di);
	_pop(si);
	_pop(cx);
	_pop(ax);
loc_11217:
	_add(di, 0x40);
	_dec(cl);
		_jnz(loc_11152);
	_inc(si);
	_dec(ch);
		_jnz(loc_11150);
	_cmp(data.word(k_word_245d2), 0);
	_write_cf(true);
 		_jz(loc_10099);
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
loc_10f6a:
}

void InertiaPlayerContext::_ult_module() {
	STACK_CHECK;
	data.dword(k_module_type_text) = 0x20544C55;
	data.word(k_moduleflag_246d0) = 0x200;
	data.byte(k_byte_24673) = 0;
	data.dword(k_chrin) = 0x40;
	ax = data.word(k_word_30515);
	_xchg(al, ah);
	data.word(k_word_30515) = ax;
	_cmp(ax, 0x3034);
		_jc(loc_11265);
	_add(data.dword(k_chrin), 2);
loc_11265:
	data.byte(k_byte_24679) = 6;
	data.byte(k_byte_2467a) = 0x7D;
	ax = ds;
	es = ax;
	si = 6920;
	di = 3151;
	cx = 0x20;
	_copy_printable();
	dx = 6953;
	cx = 1;
	eax = data.byte(k_byte_30537);
	_shl(eax, 5);
	_add(eax, 0x30);
	_dosseek();
	ax = data.byte(k_my_in);
	data.word(k_word_245d2) = ax;
	_mul(data.dword(k_chrin));
	cx = ax;
	dx = 6954;
	_dosfread();
	si = 6954;
	di = 6885;
	cx = data.word(k_word_245d2);
loc_112b4:
	_push(cx);
	_push(si);
	_push(di);
	edx = ds.dword(si+0x38);
	_sub(edx, ds.dword(si+0x34));
		_jnc(loc_112c4);
	edx = 0;
loc_112c4:
	_cmp(edx, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	ds.dword(di+0x20) = edx;
	_add(data.dword(k_dword_245c4), edx);
	al = ds.byte(si+0x3C);
	_shr(al, 2);
	ds.byte(di+0x3D) = al;
	ax = data.word(k_freq_245de);
	_cmp(data.word(k_word_30515), 0x3034);
		_jc(loc_112f1);
	ax = ds.word(si+0x3E);
loc_112f1:
	ds.word(di+0x36) = ax;
	al = ds.byte(si+0x3D);
	_and(al, 0x1C);
	ds.byte(di+0x3C) = al;
	_test(al, 4);
		_jz(loc_11316);
	_add(data.dword(k_dword_245c4), edx);
	_cmp(edx, 0x80000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	_shl(ds.dword(di+0x20), 1);
loc_11316:
	_test(al, 8);
		_jnz(loc_1132d);
loc_1131a:
	eax = 0;
	ds.dword(di+0x24) = eax;
	ds.dword(di+0x28) = eax;
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	loc_11359;
loc_1132d:
	eax = ds.dword(si+0x30);
	_or(eax, eax);
		_jz(loc_1131a);
	_dec(eax);
	ebx = ds.dword(si+0x2C);
	_test(ds.byte(di+0x3C), 4);
		_jz(loc_11348);
	_shr(ebx, 1);
	_shr(eax, 1);
loc_11348:
	ds.dword(di+0x24) = ebx;
	ds.dword(di+0x2C) = eax;
	_sub(eax, ebx);
	_inc(eax);
	ds.dword(di+0x28) = eax;
loc_11359:
	cx = 0x20;
	_copy_printable();
	_pop(di);
	_pop(si);
	_pop(cx);
	_add(di, 0x40);
	_add(si, data.dword(k_chrin));
	_dec(cx);
		_jnz(loc_112b4);
	dx = 6954;
	cx = 0x102;
	_dosfread();
	data.word(k_word_245f8) = 0;
	si = 6954;
	ax = 0;
loc_11382:
	_cmp(ds.byte(si), 0x0FF);
		_jz(loc_1138e);
	_inc(ax);
	_inc(si);
	_cmp(ax, 0x100);
		_jc(loc_11382);
loc_1138e:
	data.word(k_word_245fa) = ax;
	ax = ds;
	es = ax;
	si = 6954;
	di = 6899;
	cx = data.word(k_word_245fa);
	_write_df(false);
 	_movsb(cx, true);
	ax = data.byte(k_byte_30639);
	_inc(ax);
	data.word(k_word_245d4) = ax;
	ax = data.byte(k_byte_3063a);
	_inc(ax);
	data.word(k_word_245f2) = ax;
	data.byte(k_byte_2467e) = 0;
	ax = data.word(k_word_30515);
	_cmp(ax, 0x3031);
		_jz(loc_113c6);
	data.byte(k_byte_2467e) = 2;
loc_113c6:
	_cmp(ax, 0x3033);
		_jc(loc_113f8);
	dx = 7023;
	cx = data.word(k_word_245d4);
	_dosfread();
	_cmp(data.byte(k_sndcard_type), 0);
		_jnz(loc_113f8);
	si = 0;
	cx = data.word(k_word_245d4);
loc_113e2:
	al = data.word(k_word_3063b)[si];
	di = ax;
	_and(di, 0x0F);
	al = data.byte(k_byte_13c54)[di];
	data.dword(k_dword_27bc8)[si] = al;
	_inc(si);
	_dec(cx);
		_jnz(loc_113e2);
loc_113f8:
	si = 6921;
	cx = data.word(k_word_245d4);
loc_113ff:
	_push(cx);
	_push(si);
	dx = 0;
	cx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4201;
	// _int(0x21);
	ds.word(si) = ax;
	ds.word(si+2) = dx;
	cx = data.word(k_word_245f2);
loc_11417:
	_push(cx);
	data.word(k_word_3063b)[1] = 1;
	cx = 0x40;
loc_11420:
	_push(cx);
	_ult_read();
	_pop(cx);
	_dec(cx);
		_jnz(loc_11420);
	_pop(cx);
	_dec(cx);
		_jnz(loc_11417);
	_pop(si);
	_pop(cx);
	_add(si, 4);
	_dec(cx);
		_jnz(loc_113ff);
	cx = data.word(k_word_245f2);
loc_11438:
	_push(cx);
	si = 6921;
	di = 7036;
	cx = data.word(k_word_245d4);
loc_11443:
	_push(cx);
	dx = ds.word(si);
	cx = ds.word(si+2);
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
	data.word(k_word_3063b)[1] = 1;
	cx = 0x40;
loc_1145a:
	_push(cx);
	_ult_read();
	eax = data.dword(k_dword_3063d);
	ds.dword(di) = eax;
	al = data.byte(k_byte_30641);
	ds.byte(di+4) = al;
	_add(di, 5);
	_pop(cx);
	_dec(cx);
		_jnz(loc_1145a);
	dx = 0;
	cx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4201;
	// _int(0x21);
	ds.word(si) = ax;
	ds.word(si+2) = dx;
	_pop(cx);
	_add(si, 4);
	_dec(cx);
		_jnz(loc_11443);
	_memalloc12k();
	si = 7036;
	cx = 0x40;
loc_11494:
	_push(cx);
	_push(si);
	cx = data.word(k_word_245d4);
	ch = 0;
loc_1149c:
	_push(cx);
	bx = 0;
	al = ds.byte(si);
	_or(al, al);
		_jz(loc_114c0);
	_dec(al);
	ah = 0;
	cl = 0x0C;
	_div(cl);
	_shl(al, 4);
	_inc(ah);
	_or(al, ah);
	bl = al;
	bh = ds.byte(si+1);
	_cmp(bh, 0x63);
		_jc(loc_114c0);
	bh = 0;
loc_114c0:
	cl = 0x0FF;
	al = ds.byte(si+2);
	dl = al;
	_shr(al, 4);
	ah = ds.byte(si+4);
	_and(dl, 0x0F);
	dh = ds.byte(si+3);
	_ult_1150b();
	_xchg(ax, dx);
	_ult_1150b();
	_cmp(dl, al);
		_ja(loc_114df);
	_xchg(ax, dx);
loc_114df:
	sub_11ba6();
	_pop(cx);
	_add(si, 0x140);
	_inc(ch);
	_cmp(ch, cl);
		_jc(loc_1149c);
	es.byte(di) = 0;
	_inc(di);
	_pop(si);
	_pop(cx);
	_add(si, 5);
	_dec(cx);
		_jnz(loc_11494);
	_mem_reallocx();
	_pop(cx);
	_dec(cx);
		_jnz(loc_11438);
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
	return;
/*continuing to unbounded code: loc_112b4 from _ult_module:37-289*/
loc_112b4:
	_push(cx);
	_push(si);
	_push(di);
	edx = ds.dword(si+0x38);
	_sub(edx, ds.dword(si+0x34));
		_jnc(loc_112c4);
	edx = 0;
loc_112c4:
	_cmp(edx, 0x100000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	ds.dword(di+0x20) = edx;
	_add(data.dword(k_dword_245c4), edx);
	al = ds.byte(si+0x3C);
	_shr(al, 2);
	ds.byte(di+0x3D) = al;
	ax = data.word(k_freq_245de);
	_cmp(data.word(k_word_30515), 0x3034);
		_jc(loc_112f1);
	ax = ds.word(si+0x3E);
loc_112f1:
	ds.word(di+0x36) = ax;
	al = ds.byte(si+0x3D);
	_and(al, 0x1C);
	ds.byte(di+0x3C) = al;
	_test(al, 4);
		_jz(loc_11316);
	_add(data.dword(k_dword_245c4), edx);
	_cmp(edx, 0x80000);
	_write_df(!_read_df());
 	_adc(data.word(k_word_24662), 0);
	_shl(ds.dword(di+0x20), 1);
loc_11316:
	_test(al, 8);
		_jnz(loc_1132d);
loc_1131a:
	eax = 0;
	ds.dword(di+0x24) = eax;
	ds.dword(di+0x28) = eax;
	_dec(edx);
	ds.dword(di+0x2C) = edx;
	loc_11359;
loc_1132d:
	eax = ds.dword(si+0x30);
	_or(eax, eax);
		_jz(loc_1131a);
	_dec(eax);
	ebx = ds.dword(si+0x2C);
	_test(ds.byte(di+0x3C), 4);
		_jz(loc_11348);
	_shr(ebx, 1);
	_shr(eax, 1);
loc_11348:
	ds.dword(di+0x24) = ebx;
	ds.dword(di+0x2C) = eax;
	_sub(eax, ebx);
	_inc(eax);
	ds.dword(di+0x28) = eax;
loc_11359:
	cx = 0x20;
	_copy_printable();
	_pop(di);
	_pop(si);
	_pop(cx);
	_add(di, 0x40);
	_add(si, data.dword(k_chrin));
	_dec(cx);
		_jnz(loc_112b4);
	dx = 6954;
	cx = 0x102;
	_dosfread();
	data.word(k_word_245f8) = 0;
	si = 6954;
	ax = 0;
loc_11382:
	_cmp(ds.byte(si), 0x0FF);
		_jz(loc_1138e);
	_inc(ax);
	_inc(si);
	_cmp(ax, 0x100);
		_jc(loc_11382);
loc_1138e:
	data.word(k_word_245fa) = ax;
	ax = ds;
	es = ax;
	si = 6954;
	di = 6899;
	cx = data.word(k_word_245fa);
	_write_df(false);
 	_movsb(cx, true);
	ax = data.byte(k_byte_30639);
	_inc(ax);
	data.word(k_word_245d4) = ax;
	ax = data.byte(k_byte_3063a);
	_inc(ax);
	data.word(k_word_245f2) = ax;
	data.byte(k_byte_2467e) = 0;
	ax = data.word(k_word_30515);
	_cmp(ax, 0x3031);
		_jz(loc_113c6);
	data.byte(k_byte_2467e) = 2;
loc_113c6:
	_cmp(ax, 0x3033);
		_jc(loc_113f8);
	dx = 7023;
	cx = data.word(k_word_245d4);
	_dosfread();
	_cmp(data.byte(k_sndcard_type), 0);
		_jnz(loc_113f8);
	si = 0;
	cx = data.word(k_word_245d4);
loc_113e2:
	al = data.word(k_word_3063b)[si];
	di = ax;
	_and(di, 0x0F);
	al = data.byte(k_byte_13c54)[di];
	data.dword(k_dword_27bc8)[si] = al;
	_inc(si);
	_dec(cx);
		_jnz(loc_113e2);
loc_113f8:
	si = 6921;
	cx = data.word(k_word_245d4);
loc_113ff:
	_push(cx);
	_push(si);
	dx = 0;
	cx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4201;
	// _int(0x21);
	ds.word(si) = ax;
	ds.word(si+2) = dx;
	cx = data.word(k_word_245f2);
loc_11417:
	_push(cx);
	data.word(k_word_3063b)[1] = 1;
	cx = 0x40;
loc_11420:
	_push(cx);
	_ult_read();
	_pop(cx);
	_dec(cx);
		_jnz(loc_11420);
	_pop(cx);
	_dec(cx);
		_jnz(loc_11417);
	_pop(si);
	_pop(cx);
	_add(si, 4);
	_dec(cx);
		_jnz(loc_113ff);
	cx = data.word(k_word_245f2);
loc_11438:
	_push(cx);
	si = 6921;
	di = 7036;
	cx = data.word(k_word_245d4);
loc_11443:
	_push(cx);
	dx = ds.word(si);
	cx = ds.word(si+2);
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
	data.word(k_word_3063b)[1] = 1;
	cx = 0x40;
loc_1145a:
	_push(cx);
	_ult_read();
	eax = data.dword(k_dword_3063d);
	ds.dword(di) = eax;
	al = data.byte(k_byte_30641);
	ds.byte(di+4) = al;
	_add(di, 5);
	_pop(cx);
	_dec(cx);
		_jnz(loc_1145a);
	dx = 0;
	cx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4201;
	// _int(0x21);
	ds.word(si) = ax;
	ds.word(si+2) = dx;
	_pop(cx);
	_add(si, 4);
	_dec(cx);
		_jnz(loc_11443);
	_memalloc12k();
	si = 7036;
	cx = 0x40;
loc_11494:
	_push(cx);
	_push(si);
	cx = data.word(k_word_245d4);
	ch = 0;
loc_1149c:
	_push(cx);
	bx = 0;
	al = ds.byte(si);
	_or(al, al);
		_jz(loc_114c0);
	_dec(al);
	ah = 0;
	cl = 0x0C;
	_div(cl);
	_shl(al, 4);
	_inc(ah);
	_or(al, ah);
	bl = al;
	bh = ds.byte(si+1);
	_cmp(bh, 0x63);
		_jc(loc_114c0);
	bh = 0;
loc_114c0:
	cl = 0x0FF;
	al = ds.byte(si+2);
	dl = al;
	_shr(al, 4);
	ah = ds.byte(si+4);
	_and(dl, 0x0F);
	dh = ds.byte(si+3);
	_ult_1150b();
	_xchg(ax, dx);
	_ult_1150b();
	_cmp(dl, al);
		_ja(loc_114df);
	_xchg(ax, dx);
loc_114df:
	sub_11ba6();
	_pop(cx);
	_add(si, 0x140);
	_inc(ch);
	_cmp(ch, cl);
		_jc(loc_1149c);
	es.byte(di) = 0;
	_inc(di);
	_pop(si);
	_pop(cx);
	_add(si, 5);
	_dec(cx);
		_jnz(loc_11494);
	_mem_reallocx();
	_pop(cx);
	_dec(cx);
		_jnz(loc_11438);
	_mod_readfile_11f4e();
		_jc(loc_10099);
	return;
loc_112b4:
}

void InertiaPlayerContext::_ult_1150b() {
	STACK_CHECK;
	_cmp(al, 5);
		_jz(loc_11520);
	_cmp(al, 0x0A);
		_jz(loc_11523);
	_cmp(al, 0x0B);
		_jz(loc_1152a);
	_cmp(al, 0x0C);
		_jz(loc_11531);
	_cmp(al, 0x0E);
		_jz(loc_11539);
	return;
loc_11520:
	ax = 0;
	return;
loc_11523:
	_shr(ah, 2);
	_and(ah, 0x33);
	return;
loc_1152a:
	_and(ax, 0x0F00);
	_or(ax, 0x800E);
	return;
loc_11531:
	cl = ah;
	_shr(cl, 2);
	ax = 0;
	return;
loc_11539:
	_push(dx);
	dx = ax;
	_shr(dx, 4);
	_cmp(dl, 0x0EA);
		_jz(loc_1154b);
	_cmp(dl, 0x0EB);
		_jz(loc_1154b);
	_pop(dx);
	return;
loc_1154b:
	dh = ah;
	_and(dh, 0x0F0);
	_and(ah, 0x0F);
	_shr(ah, 2);
	_or(ah, dh);
	_pop(dx);
	return;
	return;
/*continuing to unbounded code: loc_1152a from _ult_1150b:19-45*/
loc_1152a:
	_and(ax, 0x0F00);
	_or(ax, 0x800E);
	return;
loc_11531:
	cl = ah;
	_shr(cl, 2);
	ax = 0;
	return;
loc_11539:
	_push(dx);
	dx = ax;
	_shr(dx, 4);
	_cmp(dl, 0x0EA);
		_jz(loc_1154b);
	_cmp(dl, 0x0EB);
		_jz(loc_1154b);
	_pop(dx);
	return;
loc_1154b:
	dh = ah;
	_and(dh, 0x0F0);
	_and(ah, 0x0F);
	_shr(ah, 2);
	_or(ah, dh);
	_pop(dx);
	return;
loc_1152a:
}

void InertiaPlayerContext::_ult_read() {
	STACK_CHECK;
	_dec(data.word(k_word_3063b)[1]);
		_jnz(locret_11584);
	dx = 7023;
	cx = 2;
	_dosfread();
	_cmp(data.word(k_word_3063b), 0x0FC);
		_jz(loc_11585);
	ax = data.word(k_word_3063b);
	data.dword(k_dword_3063d) = ax;
	data.word(k_word_3063b)[1] = 1;
	dx = ( data.dword(k_dword_3063d)+2);
	cx = 3;
	_dosfread();
locret_11584:
	return;
loc_11585:
	dx = 7025;
	cx = 5;
	_dosfread();
	return;
}

void InertiaPlayerContext::_inr_read_118b0() {
	STACK_CHECK;
	_push(ds);
	ax = ;
	ds = ax;
	es = ax;
	_shl(dx, 6);
	ax = dx;
	_add(ax, 6885);
	_push(ax);
	cx = 96;
	bx = data.word(k_fhandle_module);
	dx = 6736;
	ah = 0x3F;
	// _int(0x21);
	_pop(bx);
		_jc(loc_119b2);
	di = ds.word(bx);
	si = 6737;
	_write_df(false);
 	cx = 8;
	while(cx--)
		_movsd();
	di = bx;
	ecx = data.dword(k_dword_25892);
	ds.dword(di+0x24) = ecx;
	eax = data.dword(k_dword_25896);
	ds.dword(di+0x2C) = eax;
	_sub(eax, ecx);
	_inc(eax);
	ds.dword(di+0x28) = eax;
	ax = data.word(k_word_2588e);
	ds.word(di+0x36) = ax;
	al = data.byte(k_byte_2588c);
	ds.byte(di+0x3E) = al;
	al = data.byte(k_byte_2588b);
	ds.byte(di+0x3D) = al;
	al = data.byte(k_byte_2588d);
	ds.byte(di+0x3C) = al;
	eax = data.dword(k_dword_25886);
	ds.dword(di+0x20) = eax;
loc_1191c:
	dx = 6905;
	cx = 8;
	bx = data.word(k_fhandle_module);
	ah = 0x3F;
	// _int(0x21);
		_jc(loc_119b2);
	eax = data.dword(k_myin);
	data.dword(k_dword_257a0) = eax;
	cx = 0;
	dx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4201;
	// _int(0x21);
	_shl(edx, 0x10);
	dx = ax;
	_add(data.dword(k_dword_257a0), edx);
	eax = data.dword(k_chrin);
	_cmp(eax, 0x54414453);
		_jnz(loc_11967);
	ds.dword(di+0x38) = edx;
	_test(data.byte(k_sndflags_24622), 4);
		_jnz(loc_11999);
	loc_11999;
loc_11967:
	_cmp(eax, 0x504D4153);
		_jnz(loc_11991);
	cx = 0;
	dx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4201;
	// _int(0x21);
	dx = ax;
	cx = dx;
	_sub(dx, 8);
	_sub(cx, 0);
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
	loc_119af;
loc_11991:
	_cmp(eax, 0x53444E45);
		_jz(loc_119af);
loc_11999:
	dx = data.dword(k_dword_257a0);
	cx = data.dword(k_dword_257a0)[2];
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
		_jc(loc_119b2);
	loc_1191c;
loc_119af:
	_write_cf(false);
 	_pop(ds);
	return;
loc_119b2:
	ax = 0x0FFFE;
	_pop(ds);
	return;
	return;
/*continuing to unbounded code: loc_1191c from _inr_read_118b0:40-98*/
loc_1191c:
	dx = 6905;
	cx = 8;
	bx = data.word(k_fhandle_module);
	ah = 0x3F;
	// _int(0x21);
		_jc(loc_119b2);
	eax = data.dword(k_myin);
	data.dword(k_dword_257a0) = eax;
	cx = 0;
	dx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4201;
	// _int(0x21);
	_shl(edx, 0x10);
	dx = ax;
	_add(data.dword(k_dword_257a0), edx);
	eax = data.dword(k_chrin);
	_cmp(eax, 0x54414453);
		_jnz(loc_11967);
	ds.dword(di+0x38) = edx;
	_test(data.byte(k_sndflags_24622), 4);
		_jnz(loc_11999);
	loc_11999;
loc_11967:
	_cmp(eax, 0x504D4153);
		_jnz(loc_11991);
	cx = 0;
	dx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4201;
	// _int(0x21);
	dx = ax;
	cx = dx;
	_sub(dx, 8);
	_sub(cx, 0);
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
	loc_119af;
loc_11991:
	_cmp(eax, 0x53444E45);
		_jz(loc_119af);
loc_11999:
	dx = data.dword(k_dword_257a0);
	cx = data.dword(k_dword_257a0)[2];
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
		_jc(loc_119b2);
	loc_1191c;
loc_119af:
	_write_cf(false);
 	_pop(ds);
	return;
loc_119b2:
	ax = 0x0FFFE;
	_pop(ds);
	return;
loc_1191c:
}

void InertiaPlayerContext::_inr_read_119b7() {
	STACK_CHECK;
	ecx = data.dword(k_myin);
	bx = data.word(k_fhandle_module);
	dx = di;
	ah = 0x3F;
	// _int(0x21);
	return;
}

void InertiaPlayerContext::_inr_module() {
	STACK_CHECK;
	data.dword(k_module_type_text) = 0x20524E49;
	data.word(k_moduleflag_246d0) = 0x100;
	data.byte(k_byte_24673) = 0;
	data.word(k_word_245f2) = 0;
	data.word(k_word_245d2) = 0;
	ax = ds;
	es = ax;
	_write_df(false);
 	dx = 6636;
	cx = 0x50;
	eax = 0;
	_dosseek();
	si = ( data.byte(k_ainertiamodule)+0x10);
	di = 3151;
	cx = 8;
	_write_df(false);
 	while(cx--)
		_movsd();
	al = data.byte(k_byte_257db);
	data.byte(k_byte_2461a) = al;
	al = data.byte(k_byte_257dc);
	data.byte(k_byte_2467e) = al;
	ax = data.word(k_word_257e6);
	data.word(k_word_245d4) = ax;
	_dec(ax);
	data.byte(k_byte_2461b) = al;
	ax = data.word(k_word_257ec);
	data.word(k_freq_245de) = ax;
	ax = data.word(k_word_257ee);
	data.word(k_word_245fa) = ax;
	ax = data.word(k_word_257f0);
	data.word(k_word_245f8) = ax;
	al = data.byte(k_byte_257f2);
	data.byte(k_byte_2467a) = al;
	al = data.byte(k_byte_257f3);
	data.byte(k_byte_24679) = al;
loc_11a39:
	cx = 8;
	bx = data.word(k_fhandle_module);
	dx = 6905;
	ah = 0x3F;
	// _int(0x21);
		_jc(loc_11b3d);
	eax = data.dword(k_myin);
	data.dword(k_dword_257a0) = eax;
	cx = 0;
	dx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4201;
	// _int(0x21);
	_add(data.dword(k_dword_257a0), ax);
	_adc(data.dword(k_dword_257a0)[2], dx);
	eax = data.dword(k_chrin);
	_cmp(eax, 0x54534C54);
		_jnz(loc_11a81);
	di = 6901;
	_inr_read_119b7();
		_jc(loc_11b3d);
	loc_11b28;
loc_11a81:
	_cmp(eax, 0x54534C42);
		_jnz(loc_11a96);
	di = 6902;
	_inr_read_119b7();
		_jc(loc_11b3d);
	loc_11b28;
loc_11a96:
	_cmp(eax, 0x54534C50);
		_jnz(loc_11aaa);
	di = 6899;
	_inr_read_119b7();
		_jc(loc_11b3d);
	loc_11b28;
loc_11aaa:
	_cmp(eax, 0x54544150);
		_jnz(loc_11b09);
	ebx = data.dword(k_myin);
	_cmp(ebx, 0x40);
		_ja(loc_11ac0);
	bx = 0x40;
loc_11ac0:
	_memalloc();
		_jc(loc_11b3d);
	ecx = data.dword(k_myin);
	di = data.word(k_word_245f2);
	_inc(data.word(k_word_245f2));
	_shl(di, 1);
	data.word(k_segs_table)[di] = ax;
	_cmp(cx, 0x40);
		_jbe(loc_11af3);
	data.word(k_myseg_size)[di] = cx;
	dx = 0;
	bx = data.word(k_fhandle_module);
	_push(ds);
	ds = ax;
	ah = 0x3F;
	// _int(0x21);
	_pop(ds);
		_jc(loc_11b3d);
	loc_11b28;
loc_11af3:
	data.word(k_myseg_size)[di] = 0x40;
	di = 0;
	es = ax;
	cx = 0x10;
	eax = 0;
	_write_df(false);
 	while(cx--)
		_stosd();
	loc_11b28;
loc_11b09:
	_cmp(eax, 0x504D4153);
		_jnz(loc_11b20);
	dx = data.word(k_word_245d2);
	_inc(data.word(k_word_245d2));
	_inr_read_118b0();
		_jc(loc_11b3d);
	loc_11b28;
loc_11b20:
	_cmp(eax, 0x4D444E45);
		_jz(loc_11b41);
loc_11b28:
	dx = data.dword(k_dword_257a0);
	cx = data.dword(k_dword_257a0)[2];
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
		_jnc(loc_11a39);
loc_11b3d:
	ax = 0x0FFFE;
	return;
loc_11b41:
	_mod_readfile_11f4e();
	return;
	return;
/*continuing to unbounded code: loc_11a39 from _inr_module:37-134*/
loc_11a39:
	cx = 8;
	bx = data.word(k_fhandle_module);
	dx = 6905;
	ah = 0x3F;
	// _int(0x21);
		_jc(loc_11b3d);
	eax = data.dword(k_myin);
	data.dword(k_dword_257a0) = eax;
	cx = 0;
	dx = 0;
	bx = data.word(k_fhandle_module);
	ax = 0x4201;
	// _int(0x21);
	_add(data.dword(k_dword_257a0), ax);
	_adc(data.dword(k_dword_257a0)[2], dx);
	eax = data.dword(k_chrin);
	_cmp(eax, 0x54534C54);
		_jnz(loc_11a81);
	di = 6901;
	_inr_read_119b7();
		_jc(loc_11b3d);
	loc_11b28;
loc_11a81:
	_cmp(eax, 0x54534C42);
		_jnz(loc_11a96);
	di = 6902;
	_inr_read_119b7();
		_jc(loc_11b3d);
	loc_11b28;
loc_11a96:
	_cmp(eax, 0x54534C50);
		_jnz(loc_11aaa);
	di = 6899;
	_inr_read_119b7();
		_jc(loc_11b3d);
	loc_11b28;
loc_11aaa:
	_cmp(eax, 0x54544150);
		_jnz(loc_11b09);
	ebx = data.dword(k_myin);
	_cmp(ebx, 0x40);
		_ja(loc_11ac0);
	bx = 0x40;
loc_11ac0:
	_memalloc();
		_jc(loc_11b3d);
	ecx = data.dword(k_myin);
	di = data.word(k_word_245f2);
	_inc(data.word(k_word_245f2));
	_shl(di, 1);
	data.word(k_segs_table)[di] = ax;
	_cmp(cx, 0x40);
		_jbe(loc_11af3);
	data.word(k_myseg_size)[di] = cx;
	dx = 0;
	bx = data.word(k_fhandle_module);
	_push(ds);
	ds = ax;
	ah = 0x3F;
	// _int(0x21);
	_pop(ds);
		_jc(loc_11b3d);
	loc_11b28;
loc_11af3:
	data.word(k_myseg_size)[di] = 0x40;
	di = 0;
	es = ax;
	cx = 0x10;
	eax = 0;
	_write_df(false);
 	while(cx--)
		_stosd();
	loc_11b28;
loc_11b09:
	_cmp(eax, 0x504D4153);
		_jnz(loc_11b20);
	dx = data.word(k_word_245d2);
	_inc(data.word(k_word_245d2));
	_inr_read_118b0();
		_jc(loc_11b3d);
	loc_11b28;
loc_11b20:
	_cmp(eax, 0x4D444E45);
		_jz(loc_11b41);
loc_11b28:
	dx = data.dword(k_dword_257a0);
	cx = data.dword(k_dword_257a0)[2];
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
		_jnc(loc_11a39);
loc_11b3d:
	ax = 0x0FFFE;
	return;
loc_11b41:
	_mod_readfile_11f4e();
	return;
loc_11a39:
}

void InertiaPlayerContext::_dosseek() {
	STACK_CHECK;
	_push(cx);
	_push(dx);
	dx = ax;
	_shr(eax, 0x10);
	cx = ax;
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
	_pop(dx);
	_pop(cx);
	ax = 0x0FFFC;
		_jc(_lfreaderr);
	return;
/*continuing to unbounded code: _lfreaderr from _moduleread:80-96*/
_lfreaderr:
	_push(ax);
	_push(dx);
	bx = data.word(k_fhandle_module);
	ah = 0x3E;
	// _int(0x21);
	_ems_restore_mapctx();
	_push(cs);
	_memfree_125da();
	ax = ds;
	fs = ax;
	_pop(dx);
	_pop(ax);
	sp = data.word(k_savesp_245d0);
	_pop(ds);
	_write_cf(true);
 	return;
}

void InertiaPlayerContext::_dosfread() {
	STACK_CHECK;
	bx = data.word(k_fhandle_module);
	ah = 0x3F;
	// _int(0x21);
	cx = ax;
	ax = 0x0FFFC;
		_jc(_lfreaderr);
	return;
	return;
/*continuing to unbounded code: _lfreaderr from _moduleread:80-96*/
_lfreaderr:
	_push(ax);
	_push(dx);
	bx = data.word(k_fhandle_module);
	ah = 0x3E;
	// _int(0x21);
	_ems_restore_mapctx();
	_push(cs);
	_memfree_125da();
	ax = ds;
	fs = ax;
	_pop(dx);
	_pop(ax);
	sp = data.word(k_savesp_245d0);
	_pop(ds);
	_write_cf(true);
 	return;
}

void InertiaPlayerContext::_memalloc12k() {
	STACK_CHECK;
	ebx = 12352;
	_memalloc();
		_jc(loc_10099);
	es = ax;
	di = 0;
	return;
	return;
/*continuing to unbounded code: loc_10099 from _moduleread:77-96*/
loc_10099:
	dx = 6409;
	ax = 0x0FFFE;
	_push(ax);
	_push(dx);
	bx = data.word(k_fhandle_module);
	ah = 0x3E;
	// _int(0x21);
	_ems_restore_mapctx();
	_push(cs);
	_memfree_125da();
	ax = ds;
	fs = ax;
	_pop(dx);
	_pop(ax);
	sp = data.word(k_savesp_245d0);
	_pop(ds);
	_write_cf(true);
 	return;
}

void InertiaPlayerContext::_mem_reallocx() {
	STACK_CHECK;
	bx = data.word(k_my_seg_index);
	_shl(bx, 1);
	data.word(k_segs_table)[bx] = es;
	data.word(k_myseg_size)[bx] = di;
	ebx = di;
	ax = es;
	_memrealloc();
	_adc(data.word(k_word_24662), 0);
	_inc(data.word(k_my_seg_index));
	return;
}

void InertiaPlayerContext::sub_11ba6() {
	STACK_CHECK;
	_and(ch, 0x1F);
	_or(bl, bl);
		_jz(loc_11bb2);
	_cmp(bl, 0x0FF);
		_jnz(loc_11bbb);
loc_11bb2:
	_or(bh, bh);
		_jz(loc_11bbe);
	_cmp(bh, 0x0FF);
		_jz(loc_11bbe);
loc_11bbb:
	_or(ch, 0x20);
loc_11bbe:
	_cmp(cl, 0x40);
		_ja(loc_11bc6);
	_or(ch, 0x40);
loc_11bc6:
	_or(dx, dx);
		_jz(loc_11bd1);
	_or(dl, dl);
		_jz(loc_11c08);
loc_11bce:
	_or(ch, 0x80);
loc_11bd1:
	_test(ch, 0x0E0);
		_jz(locret_11c03);
	es.byte(di) = ch;
	_inc(di);
	_test(ch, 0x80);
		_jz(loc_11be5);
	es.word(di) = dx;
	_add(di, 2);
loc_11be5:
	_test(ch, 0x40);
		_jz(loc_11bee);
	es.byte(di) = cl;
	_inc(di);
loc_11bee:
	_test(ch, 0x20);
		_jz(loc_11bf9);
	es.word(di) = bx;
	_add(di, 2);
loc_11bf9:
	al = ch;
	_and(al, 0x1F);
	_cmp(al, data.byte(k_byte_2461b));
		_ja(loc_11c04);
locret_11c03:
	return;
loc_11c04:
	data.byte(k_byte_2461b) = al;
	return;
loc_11c08:
	dl = 0x1D;
	loc_11bce;
	return;
/*continuing to unbounded code: loc_11bb2 from sub_11ba6:6-55*/
loc_11bb2:
	_or(bh, bh);
		_jz(loc_11bbe);
	_cmp(bh, 0x0FF);
		_jz(loc_11bbe);
loc_11bbb:
	_or(ch, 0x20);
loc_11bbe:
	_cmp(cl, 0x40);
		_ja(loc_11bc6);
	_or(ch, 0x40);
loc_11bc6:
	_or(dx, dx);
		_jz(loc_11bd1);
	_or(dl, dl);
		_jz(loc_11c08);
loc_11bce:
	_or(ch, 0x80);
loc_11bd1:
	_test(ch, 0x0E0);
		_jz(locret_11c03);
	es.byte(di) = ch;
	_inc(di);
	_test(ch, 0x80);
		_jz(loc_11be5);
	es.word(di) = dx;
	_add(di, 2);
loc_11be5:
	_test(ch, 0x40);
		_jz(loc_11bee);
	es.byte(di) = cl;
	_inc(di);
loc_11bee:
	_test(ch, 0x20);
		_jz(loc_11bf9);
	es.word(di) = bx;
	_add(di, 2);
loc_11bf9:
	al = ch;
	_and(al, 0x1F);
	_cmp(al, data.byte(k_byte_2461b));
		_ja(loc_11c04);
locret_11c03:
	return;
loc_11c04:
	data.byte(k_byte_2461b) = al;
	return;
loc_11c08:
	dl = 0x1D;
	loc_11bce;
loc_11bb2:
}

void InertiaPlayerContext::sub_11c0c() {
	STACK_CHECK;
	si = 0;
	_or(al, al);
		_jz(locret_11c28);
	bx = 0;
loc_11c14:
	bl = data.byte(k_byte_11c29)[bx];
	_add(si, bx);
	bl = es.byte(si);
	_inc(si);
	_shr(bl, 5);
		_jnz(loc_11c14);
	_dec(al);
		_jnz(loc_11c14);
locret_11c28:
	return;
	return;
/*continuing to unbounded code: loc_11c14 from sub_11c0c:5-15*/
loc_11c14:
	bl = data.byte(k_byte_11c29)[bx];
	_add(si, bx);
	bl = es.byte(si);
	_inc(si);
	_shr(bl, 5);
		_jnz(loc_11c14);
	_dec(al);
		_jnz(loc_11c14);
locret_11c28:
	return;
loc_11c14:
}

void InertiaPlayerContext::_copy_printable() {
	STACK_CHECK;
	_push(si);
	_push(di);
loc_11c33:
	al = ds.byte(si);
	_inc(si);
	_cmp(al, 0x20);
		_jc(loc_11c40);
	ds.byte(di) = al;
	_inc(di);
	_dec(cx);
		_jnz(loc_11c33);
loc_11c40:
	_pop(di);
	_pop(si);
	return;
	return;
/*continuing to unbounded code: loc_11c33 from _copy_printable:3-15*/
loc_11c33:
	al = ds.byte(si);
	_inc(si);
	_cmp(al, 0x20);
		_jc(loc_11c40);
	ds.byte(di) = al;
	_inc(di);
	_dec(cx);
		_jnz(loc_11c33);
loc_11c40:
	_pop(di);
	_pop(si);
	return;
loc_11c33:
}

void InertiaPlayerContext::_clean_11c43() {
	STACK_CHECK;
	_push(ds);
	ax = ;
	ds = ax;
	data.byte(k_byte_24679) = 6;
	data.byte(k_byte_2467a) = 125;
	data.byte(k_byte_2467e) = 0;
	data.word(k_moduleflag_246d0) = 1;
	data.word(k_my_seg_index) = 0;
	data.word(k_word_245f0) = 0;
	data.word(k_word_245f6) = 0;
	data.byte(k_byte_24673) = 0;
	data.word(k_word_24630) = 2;
	data.word(k_word_245fa) = 0;
	data.word(k_word_245f8) = 0;
	data.word(k_word_245d4) = 4;
	data.word(k_word_245d6) = 4;
	data.word(k_word_245d8) = 0;
	data.word(k_word_245da) = 0;
	data.word(k_word_245d2) = 0;
	data.word(k_freq_245de) = 8287;
	_test(data.byte(k_flag_playsetttings), 8);
		_jnz(loc_11cb8);
	data.word(k_freq_245de) = 8363;
loc_11cb8:
	data.byte(k_byte_2461a) = 0;
	data.dword(k_dword_245c4) = 0;
	data.word(k_amplification) = 100;
	data.byte(k_byte_24625) = 0;
	ax = ds;
	es = ax;
	_write_df(false);
 	di = 3151;
	cx = 8;
	eax = 0x20202020;
	while(cx--)
		_stosd();
	di = 6884;
	eax = 0;
	cx = 0x280;
	while(cx--)
		_stosd();
	di = 6903;
	cx = 8;
	while(cx--)
		_stosd();
	di = 6886;
	ah = data.byte(k_byte_2461e);
	al = data.byte(k_byte_2461f);
	_shl(eax, 0x10);
	ah = data.byte(k_byte_2461f);
	al = data.byte(k_byte_2461e);
	cx = 8;
	while(cx--)
		_stosd();
	di = 6885;
	eax = 0;
	cx = 0x630;
	while(cx--)
		_stosd();
	dx = 0x63;
	di = 6885;
	eax = 0x20202020;
loc_11d2d:
	cx = 8;
	while(cx--)
		_stosd();
	_sub(di, 0x20);
	ds.word(di+0x32) = 0x0FFFF;
	_add(di, 0x40);
	_dec(dx);
		_jnz(loc_11d2d);
	di = 6895;
	cx = 0x80;
	eax = 0;
	while(cx--)
		_stosd();
	di = 6901;
	cx = 0x40;
	while(cx--)
		_stosd();
	di = 6899;
	cx = 0x40;
	while(cx--)
		_stosd();
	di = 6903;
	cx = 8;
	while(cx--)
		_stosd();
	di = 6902;
	cx = 0x40;
	eax = 0x3F3F3F3F;
	while(cx--)
		_stosd();
	_pop(ds);
	return;
	return;
/*continuing to unbounded code: loc_11cb8 from _clean_11c43:24-95*/
loc_11cb8:
	data.byte(k_byte_2461a) = 0;
	data.dword(k_dword_245c4) = 0;
	data.word(k_amplification) = 100;
	data.byte(k_byte_24625) = 0;
	ax = ds;
	es = ax;
	_write_df(false);
 	di = 3151;
	cx = 8;
	eax = 0x20202020;
	while(cx--)
		_stosd();
	di = 6884;
	eax = 0;
	cx = 0x280;
	while(cx--)
		_stosd();
	di = 6903;
	cx = 8;
	while(cx--)
		_stosd();
	di = 6886;
	ah = data.byte(k_byte_2461e);
	al = data.byte(k_byte_2461f);
	_shl(eax, 0x10);
	ah = data.byte(k_byte_2461f);
	al = data.byte(k_byte_2461e);
	cx = 8;
	while(cx--)
		_stosd();
	di = 6885;
	eax = 0;
	cx = 0x630;
	while(cx--)
		_stosd();
	dx = 0x63;
	di = 6885;
	eax = 0x20202020;
loc_11d2d:
	cx = 8;
	while(cx--)
		_stosd();
	_sub(di, 0x20);
	ds.word(di+0x32) = 0x0FFFF;
	_add(di, 0x40);
	_dec(dx);
		_jnz(loc_11d2d);
	di = 6895;
	cx = 0x80;
	eax = 0;
	while(cx--)
		_stosd();
	di = 6901;
	cx = 0x40;
	while(cx--)
		_stosd();
	di = 6899;
	cx = 0x40;
	while(cx--)
		_stosd();
	di = 6903;
	cx = 8;
	while(cx--)
		_stosd();
	di = 6902;
	cx = 0x40;
	eax = 0x3F3F3F3F;
	while(cx--)
		_stosd();
	_pop(ds);
	return;
loc_11cb8:
}

void InertiaPlayerContext::_ems_init() {
	STACK_CHECK;
	data.byte(k_ems_enabled) = 0;
	ax = 1;
	_test(data.word(k_config_word), 2);
		_jz(loc_11e00);
	ax = 0;
	es = ax;
	ax = 1;
	es = es.word(0x19E);
	_cmp(es.dword(0x0A), 0x584D4D45);
		_jnz(loc_11e00);
	_cmp(es.dword(0x0E), 0x30585858);
		_jnz(loc_11e00);
	ah = 0x40;
	// _int(0x67);
	bx = ax;
	ax = 2;
	_or(bh, bh);
		_jnz(loc_11e00);
	ah = 0x46;
	// _int(0x67);
	bx = ax;
	ax = 2;
	_or(bh, bh);
		_jnz(loc_11e00);
	ax = 3;
	_cmp(bl, 0x40);
		_jc(loc_11e00);
	ah = 0x41;
	// _int(0x67);
	_cmp(ah, 0);
	ax = 2;
		_jnz(loc_11e00);
	data.word(k_ems_pageframe) = bx;
	ah = 0x43;
	bx = 1;
	// _int(0x67);
	_cmp(ah, 0);
	ax = 8;
		_jnz(loc_11e00);
	data.word(k_ems_handle) = dx;
	data.byte(k_ems_enabled) = 1;
	data.word(k_ems_log_pagenum) = 0;
	ax = 0;
	_write_cf(false);
 	return;
loc_11e00:
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_11e00 from _ems_init:46-48*/
loc_11e00:
	_write_cf(true);
 	return;
loc_11e00:
}

void InertiaPlayerContext::_ems_release() {
	STACK_CHECK;
	_cmp(data.byte(k_ems_enabled), 1);
		_jnz(locret_11e1d);
	bx = 0x8000;
	_ems_mapmem();
	dx = data.word(k_ems_handle);
	ah = 0x45;
	// _int(0x67);
	data.word(k_ems_log_pagenum) = 0;
locret_11e1d:
	return;
	return;
/*continuing to unbounded code: locret_11e1d from _ems_release:9-10*/
locret_11e1d:
	return;
locret_11e1d:
}

void InertiaPlayerContext::_ems_realloc() {
	STACK_CHECK;
	_cmp(data.byte(k_ems_enabled), 1);
		_jnz(locret_11e36);
	dx = data.word(k_ems_handle);
	bx = 1;
	ah = 0x51;
	// _int(0x67);
	data.word(k_ems_log_pagenum) = 0;
locret_11e36:
	return;
	return;
/*continuing to unbounded code: locret_11e36 from _ems_realloc:8-9*/
locret_11e36:
	return;
locret_11e36:
}

void InertiaPlayerContext::_ems_deinit() {
	STACK_CHECK;
	_cmp(data.byte(k_ems_enabled), 1);
		_jnz(locret_11e46);
	_ems_release();
	data.byte(k_ems_enabled) = 0;
locret_11e46:
	return;
	return;
/*continuing to unbounded code: locret_11e46 from _ems_deinit:5-6*/
locret_11e46:
	return;
locret_11e46:
}

void InertiaPlayerContext::_ems_save_mapctx() {
	STACK_CHECK;
	_cmp(data.byte(k_ems_enabled), 1);
		_jnz(locret_11e67);
	cx = 0x32;
loc_11e51:
	dx = data.word(k_ems_handle);
	ax = 0x4700;
	// _int(0x67);
	_cmp(ah, 0);
		_jz(locret_11e67);
	_dec(cx);
		_jnz(loc_11e51);
	data.byte(k_byte_246a5) = 1;
locret_11e67:
	return;
	return;
/*continuing to unbounded code: loc_11e51 from _ems_save_mapctx:4-14*/
loc_11e51:
	dx = data.word(k_ems_handle);
	ax = 0x4700;
	// _int(0x67);
	_cmp(ah, 0);
		_jz(locret_11e67);
	_dec(cx);
		_jnz(loc_11e51);
	data.byte(k_byte_246a5) = 1;
locret_11e67:
	return;
loc_11e51:
}

void InertiaPlayerContext::_ems_restore_mapctx() {
	STACK_CHECK;
	_cmp(data.byte(k_ems_enabled), 1);
		_jnz(locret_11e8a);
	_cmp(data.byte(k_byte_246a5), 1);
		_jnz(locret_11e8a);
	cx = 0x32;
loc_11e79:
	dx = data.word(k_ems_handle);
	ax = 0x4800;
	// _int(0x67);
	_cmp(ah, 0);
		_jz(locret_11e8a);
	_dec(cx);
		_jnz(loc_11e79);
locret_11e8a:
	return;
	return;
/*continuing to unbounded code: loc_11e79 from _ems_restore_mapctx:6-15*/
loc_11e79:
	dx = data.word(k_ems_handle);
	ax = 0x4800;
	// _int(0x67);
	_cmp(ah, 0);
		_jz(locret_11e8a);
	_dec(cx);
		_jnz(loc_11e79);
locret_11e8a:
	return;
loc_11e79:
}

void InertiaPlayerContext::_ems_mapmem() {
	STACK_CHECK;
	_cmp(data.byte(k_ems_enabled), 1);
		_jnz(locret_11ec4);
	cx = 0x32;
	_cmp(bx, data.word(k_ems_log_pagenum));
		_jc(loc_11e9e);
	bx = 0x0FFFF;
loc_11e9e:
	_push(bx);
	dx = data.word(k_ems_handle);
	_push(bx);
	ax = 0x4400;
	// _int(0x67);
	_pop(bx);
	_inc(bx);
		_jz(loc_11eb3);
	_cmp(bx, data.word(k_ems_log_pagenum));
		_jc(loc_11eb6);
loc_11eb3:
	bx = 0x0FFFF;
loc_11eb6:
	ax = 0x4401;
	// _int(0x67);
	_cmp(ah, 0);
	_pop(bx);
		_jz(locret_11ec4);
	_dec(cx);
		_jnz(loc_11e9e);
locret_11ec4:
	return;
	return;
/*continuing to unbounded code: loc_11e9e from _ems_mapmem:7-29*/
loc_11e9e:
	_push(bx);
	dx = data.word(k_ems_handle);
	_push(bx);
	ax = 0x4400;
	// _int(0x67);
	_pop(bx);
	_inc(bx);
		_jz(loc_11eb3);
	_cmp(bx, data.word(k_ems_log_pagenum));
		_jc(loc_11eb6);
loc_11eb3:
	bx = 0x0FFFF;
loc_11eb6:
	ax = 0x4401;
	// _int(0x67);
	_cmp(ah, 0);
	_pop(bx);
		_jz(locret_11ec4);
	_dec(cx);
		_jnz(loc_11e9e);
locret_11ec4:
	return;
loc_11e9e:
}

void InertiaPlayerContext::_ems_mapmem2() {
	STACK_CHECK;
	_cmp(data.byte(k_ems_enabled), 1);
		_jnz(locret_11efe);
	cx = 0x32;
	_cmp(bx, data.word(k_ems_log_pagenum));
		_jc(loc_11ed8);
	bx = 0x0FFFF;
loc_11ed8:
	_push(bx);
	dx = data.word(k_ems_handle);
	_push(bx);
	ax = 0x4402;
	// _int(0x67);
	_pop(bx);
	_inc(bx);
		_jz(loc_11eed);
	_cmp(bx, data.word(k_ems_log_pagenum));
		_jc(loc_11ef0);
loc_11eed:
	bx = 0x0FFFF;
loc_11ef0:
	ax = 0x4403;
	// _int(0x67);
	_cmp(ah, 0);
	_pop(bx);
		_jz(locret_11efe);
	_dec(cx);
		_jnz(loc_11ed8);
locret_11efe:
	return;
	return;
/*continuing to unbounded code: loc_11ed8 from _ems_mapmem2:7-29*/
loc_11ed8:
	_push(bx);
	dx = data.word(k_ems_handle);
	_push(bx);
	ax = 0x4402;
	// _int(0x67);
	_pop(bx);
	_inc(bx);
		_jz(loc_11eed);
	_cmp(bx, data.word(k_ems_log_pagenum));
		_jc(loc_11ef0);
loc_11eed:
	bx = 0x0FFFF;
loc_11ef0:
	ax = 0x4403;
	// _int(0x67);
	_cmp(ah, 0);
	_pop(bx);
		_jz(locret_11efe);
	_dec(cx);
		_jnz(loc_11ed8);
locret_11efe:
	return;
loc_11ed8:
}

void InertiaPlayerContext::_ems_realloc2() {
	STACK_CHECK;
	_inc(data.byte(k_byte_24617));
	_cmp(data.byte(k_ems_enabled), 1);
		_jnz(loc_11f3c);
	ebx = ds.dword(di+0x20);
	_shr(ebx, 4);
	_add(bx, 0x102);
	_dec(bx);
	_shr(bx, 0x0A);
	_inc(bx);
	ah = 0x51;
	dx = data.word(k_ems_handle);
	_add(bx, data.word(k_ems_log_pagenum));
	_push(bx);
	// _int(0x67);
	_pop(bx);
	_cmp(ah, 0);
		_jnz(loc_11f3c);
	cx = data.word(k_ems_log_pagenum);
	data.word(k_ems_log_pagenum) = bx;
	bx = cx;
	ax = data.word(k_ems_pageframe);
	return;
loc_11f3c:
	ebx = ds.dword(di+0x20);
	_add(ebx, 0x1020);
	_memalloc();
	cx = 0x0FFFF;
	return;
	return;
/*continuing to unbounded code: loc_11f3c from _ems_realloc2:23-28*/
loc_11f3c:
	ebx = ds.dword(di+0x20);
	_add(ebx, 0x1020);
	_memalloc();
	cx = 0x0FFFF;
	return;
loc_11f3c:
}

void InertiaPlayerContext::_mod_readfile_11f4e() {
	STACK_CHECK;
	data.byte(k_byte_24617) = 0;
	_cmp(data.word(k_word_24662), 0);
	_write_cf(true);
 		_jnz(locret_11fd3);
	_test(data.byte(k_sndflags_24622), 4);
		_jnz(loc_11fd6);
	_test(data.byte(k_sndflags_24622), 0x10);
		_jnz(loc_11fd2);
	cx = data.word(k_word_245d2);
	di = 6885;
loc_11f70:
	_push(cx);
	_cmp(ds.dword(di+0x20), 0);
		_jz(loc_11fcb);
	data.byte(k_byte_24675) = 1;
	al = ds.byte(di+0x3F);
	data.byte(k_byte_24674) = al;
	_push(di);
	_ems_realloc2();
	_pop(di);
		_jc(loc_11fd4);
	ds.word(di+0x30) = ax;
	ds.word(di+0x32) = cx;
	es = ax;
	_test(data.word(k_moduleflag_246d0), 0x5d8);
		_jz(loc_11fa9);
	dx = ds.word(di+0x38);
	cx = ds.word(di+0x3A);
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
loc_11fa9:
	bx = data.word(k_fhandle_module);
	ecx = ds.dword(di+0x20);
	_push(di);
	_push(es);
	dx = ds.word(di+0x32);
	_mod_readfile_12247();
	_adc(data.word(k_word_24662), 0);
	_pop(es);
	_pop(di);
	ax = es;
	_push(di);
	_ems_mapmemx();
	_pop(di);
	_or(ds.byte(di+0x3C), 1);
loc_11fcb:
	_add(di, 0x40);
	_pop(cx);
	_dec(cx);
		_jnz(loc_11f70);
loc_11fd2:
	_write_cf(false);
 locret_11fd3:
	return;
loc_11fd4:
	_pop(cx);
	return;
loc_11fd6:
	eax = 0x10000;
	cl = data.byte(k_dma_channel_0);
	_alloc_dma_buf();
		_jc(locret_1221f);
	data.dword(k_dma_buf_pointer)[2] = ax;
	data.dword(k_dma_buf_pointer) = 0;
	di = 6885;
	cx = data.word(k_word_245d2);
loc_11ff7:
	_push(cx);
	_cmp(ds.dword(di+0x20), 0);
		_jz(loc_12106);
	_inc(data.byte(k_byte_24617));
	data.byte(k_byte_24675) = 1;
	al = ds.byte(di+0x3F);
	data.byte(k_byte_24674) = al;
	_test(data.word(k_moduleflag_246d0), 0x5d8);
		_jz(loc_12027);
	dx = ds.word(di+0x38);
	cx = ds.word(di+0x3A);
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
loc_12027:
	_test(ds.byte(di+0x3C), 4);
		_jz(loc_1206b);
	eax = ds.dword(di+0x20);
	_add(eax, 0x1F);
	_and(al, 0x0E0);
	_shr(eax, 2);
	bx = data.word(k_word_24630);
	_shl(bx, 2);
	_add(ax, bx);
		_jnc(loc_12056);
	_and(data.word(k_word_24630), 0x0C000);
	_add(data.word(k_word_24630), 0x4000);
		_jc(loc_12117);
loc_12056:
	ax = data.word(k_word_24630);
	bx = ax;
	_and(bx, 0x0C000);
	_and(ax, 0x3FFF);
	_shr(ax, 1);
	_or(ax, bx);
	ds.word(di+0x34) = ax;
	loc_12071;
loc_1206b:
	ax = data.word(k_word_24630);
	ds.word(di+0x34) = ax;
loc_12071:
	ecx = ds.dword(di+0x20);
loc_12075:
	_cmp(ecx, 0x8000);
		_jbe(loc_120c4);
	_sub(ecx, 0x8000);
	_push(ecx);
	cx = 0x8000;
	bx = data.word(k_fhandle_module);
	ah = 0x3F;
	_push(di);
	_push(ds);
	dx = data.dword(k_dma_buf_pointer);
	// _int(0x21);
	_pop(ds);
	_pop(di);
	_adc(data.word(k_word_24662), 0);
	si = data.dword(k_dma_buf_pointer);
	cx = 0x8000;
	_mod_sub_12220();
	_push(di);
	cx = 0x8000;
	ax = data.word(k_word_24630);
	_nongravis_182e7();
	_xor(data.dword(k_dma_buf_pointer), 0x8000);
	_add(data.word(k_word_24630), 0x800);
	_pop(di);
	_pop(ecx);
	loc_12075;
loc_120c4:
	if (cx==0)
		loc_120e7;
	bx = data.word(k_fhandle_module);
	ah = 0x3F;
	_push(di);
	_push(cx);
	_push(ds);
	dx = data.dword(k_dma_buf_pointer);
	// _int(0x21);
	_pop(ds);
	_pop(cx);
	_pop(di);
	_push(di);
	_adc(data.word(k_word_24662), 0);
	si = data.dword(k_dma_buf_pointer);
	_push(cx);
	_mod_sub_12220();
	_pop(cx);
loc_120e7:
	_push(cx);
	ax = data.word(k_word_24630);
	_nongravis_182e7();
	_xor(data.dword(k_dma_buf_pointer), 0x8000);
	_pop(ax);
	_add(ax, 0x21);
	_and(al, 0x0E0);
	_shr(ax, 4);
	_add(data.word(k_word_24630), ax);
	_pop(di);
	_or(ds.byte(di+0x3C), 1);
loc_12106:
	_pop(cx);
	dx = data.word(k_word_24630);
	_shr(dx, 1);
	al = data.byte(k_byte_24628);
	_shl(ax, 0x0D);
	_cmp(dx, ax);
		_jbe(loc_12123);
loc_12117:
	_memfree_18a28();
	dx = 6413;
	ax = 0x0FFFD;
	_lfreaderr;
loc_12123:
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_11ff7);
loc_1212b:
	_cmp(data.byte(k_byte_2466e), 1);
		_jz(loc_1212b);
	_memfree_18a28();
	di = 6885;
	cx = data.word(k_word_245d2);
loc_1213c:
	_test(ds.byte(di+0x3C), 1);
		_jz(loc_12216);
	_push(cx);
	ax = 0;
	_test(ds.byte(di+0x3C), 4);
		_jnz(loc_121b9);
	_test(ds.byte(di+0x3C), 8);
		_jz(loc_1219e);
	edx = ds.dword(di+0x24);
	_push(edi);
	edi = ds.word(di+0x34);
	_shl(edi, 4);
	_add(edi, edx);
	_inc(edi);
	_pop(edi);
	edx = ds.dword(di+0x2C);
	_push(edi);
	edi = ds.word(di+0x34);
	_shl(edi, 4);
	_add(edi, edx);
	_add(edi, 2);
	_pop(edi);
	edx = ds.dword(di+0x24);
	_push(edi);
	edi = ds.word(di+0x34);
	_shl(edi, 4);
	_add(edi, edx);
	_pop(edi);
loc_1219e:
	edx = ds.dword(di+0x2C);
	_push(edi);
	edi = ds.word(di+0x34);
	_shl(edi, 4);
	_add(edi, edx);
	_inc(edi);
	_pop(edi);
	loc_12215;
loc_121b9:
	_test(ds.byte(di+0x3C), 8);
		_jz(loc_121ee);
	edx = ds.dword(di+0x24);
	_test(ds.byte(di+0x3C), 0x10);
		_jz(loc_121cd);
	edx = ds.dword(di+0x2C);
loc_121cd:
	_push(edi);
	bx = ds.word(di+0x34);
	edi = bx;
	_and(di, 0x1FFF);
	_and(bx, 0x0C000);
	_shr(bx, 1);
	_or(di, bx);
	_shl(edi, 4);
	_add(edi, edx);
	_pop(edi);
loc_121ee:
	edx = ds.dword(di+0x2C);
	_push(edi);
	bx = ds.word(di+0x34);
	edi = bx;
	_and(di, 0x1FFF);
	_and(bx, 0x0C000);
	_shr(bx, 1);
	_or(di, bx);
	_shl(edi, 4);
	_add(edi, edx);
	_inc(edi);
	_pop(edi);
loc_12215:
	_pop(cx);
loc_12216:
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_1213c);
	_write_cf(false);
 locret_1221f:
	return;
	return;
/*continuing to unbounded code: loc_11f70 from _mod_readfile_11f4e:11-271*/
loc_11f70:
	_push(cx);
	_cmp(ds.dword(di+0x20), 0);
		_jz(loc_11fcb);
	data.byte(k_byte_24675) = 1;
	al = ds.byte(di+0x3F);
	data.byte(k_byte_24674) = al;
	_push(di);
	_ems_realloc2();
	_pop(di);
		_jc(loc_11fd4);
	ds.word(di+0x30) = ax;
	ds.word(di+0x32) = cx;
	es = ax;
	_test(data.word(k_moduleflag_246d0), 0x5d8);
		_jz(loc_11fa9);
	dx = ds.word(di+0x38);
	cx = ds.word(di+0x3A);
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
loc_11fa9:
	bx = data.word(k_fhandle_module);
	ecx = ds.dword(di+0x20);
	_push(di);
	_push(es);
	dx = ds.word(di+0x32);
	_mod_readfile_12247();
	_adc(data.word(k_word_24662), 0);
	_pop(es);
	_pop(di);
	ax = es;
	_push(di);
	_ems_mapmemx();
	_pop(di);
	_or(ds.byte(di+0x3C), 1);
loc_11fcb:
	_add(di, 0x40);
	_pop(cx);
	_dec(cx);
		_jnz(loc_11f70);
loc_11fd2:
	_write_cf(false);
 locret_11fd3:
	return;
loc_11fd4:
	_pop(cx);
	return;
loc_11fd6:
	eax = 0x10000;
	cl = data.byte(k_dma_channel_0);
	_alloc_dma_buf();
		_jc(locret_1221f);
	data.dword(k_dma_buf_pointer)[2] = ax;
	data.dword(k_dma_buf_pointer) = 0;
	di = 6885;
	cx = data.word(k_word_245d2);
loc_11ff7:
	_push(cx);
	_cmp(ds.dword(di+0x20), 0);
		_jz(loc_12106);
	_inc(data.byte(k_byte_24617));
	data.byte(k_byte_24675) = 1;
	al = ds.byte(di+0x3F);
	data.byte(k_byte_24674) = al;
	_test(data.word(k_moduleflag_246d0), 0x5d8);
		_jz(loc_12027);
	dx = ds.word(di+0x38);
	cx = ds.word(di+0x3A);
	bx = data.word(k_fhandle_module);
	ax = 0x4200;
	// _int(0x21);
loc_12027:
	_test(ds.byte(di+0x3C), 4);
		_jz(loc_1206b);
	eax = ds.dword(di+0x20);
	_add(eax, 0x1F);
	_and(al, 0x0E0);
	_shr(eax, 2);
	bx = data.word(k_word_24630);
	_shl(bx, 2);
	_add(ax, bx);
		_jnc(loc_12056);
	_and(data.word(k_word_24630), 0x0C000);
	_add(data.word(k_word_24630), 0x4000);
		_jc(loc_12117);
loc_12056:
	ax = data.word(k_word_24630);
	bx = ax;
	_and(bx, 0x0C000);
	_and(ax, 0x3FFF);
	_shr(ax, 1);
	_or(ax, bx);
	ds.word(di+0x34) = ax;
	loc_12071;
loc_1206b:
	ax = data.word(k_word_24630);
	ds.word(di+0x34) = ax;
loc_12071:
	ecx = ds.dword(di+0x20);
loc_12075:
	_cmp(ecx, 0x8000);
		_jbe(loc_120c4);
	_sub(ecx, 0x8000);
	_push(ecx);
	cx = 0x8000;
	bx = data.word(k_fhandle_module);
	ah = 0x3F;
	_push(di);
	_push(ds);
	dx = data.dword(k_dma_buf_pointer);
	// _int(0x21);
	_pop(ds);
	_pop(di);
	_adc(data.word(k_word_24662), 0);
	si = data.dword(k_dma_buf_pointer);
	cx = 0x8000;
	_mod_sub_12220();
	_push(di);
	cx = 0x8000;
	ax = data.word(k_word_24630);
	_nongravis_182e7();
	_xor(data.dword(k_dma_buf_pointer), 0x8000);
	_add(data.word(k_word_24630), 0x800);
	_pop(di);
	_pop(ecx);
	loc_12075;
loc_120c4:
	if (cx==0)
		loc_120e7;
	bx = data.word(k_fhandle_module);
	ah = 0x3F;
	_push(di);
	_push(cx);
	_push(ds);
	dx = data.dword(k_dma_buf_pointer);
	// _int(0x21);
	_pop(ds);
	_pop(cx);
	_pop(di);
	_push(di);
	_adc(data.word(k_word_24662), 0);
	si = data.dword(k_dma_buf_pointer);
	_push(cx);
	_mod_sub_12220();
	_pop(cx);
loc_120e7:
	_push(cx);
	ax = data.word(k_word_24630);
	_nongravis_182e7();
	_xor(data.dword(k_dma_buf_pointer), 0x8000);
	_pop(ax);
	_add(ax, 0x21);
	_and(al, 0x0E0);
	_shr(ax, 4);
	_add(data.word(k_word_24630), ax);
	_pop(di);
	_or(ds.byte(di+0x3C), 1);
loc_12106:
	_pop(cx);
	dx = data.word(k_word_24630);
	_shr(dx, 1);
	al = data.byte(k_byte_24628);
	_shl(ax, 0x0D);
	_cmp(dx, ax);
		_jbe(loc_12123);
loc_12117:
	_memfree_18a28();
	dx = 6413;
	ax = 0x0FFFD;
	_lfreaderr;
loc_12123:
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_11ff7);
loc_1212b:
	_cmp(data.byte(k_byte_2466e), 1);
		_jz(loc_1212b);
	_memfree_18a28();
	di = 6885;
	cx = data.word(k_word_245d2);
loc_1213c:
	_test(ds.byte(di+0x3C), 1);
		_jz(loc_12216);
	_push(cx);
	ax = 0;
	_test(ds.byte(di+0x3C), 4);
		_jnz(loc_121b9);
	_test(ds.byte(di+0x3C), 8);
		_jz(loc_1219e);
	edx = ds.dword(di+0x24);
	_push(edi);
	edi = ds.word(di+0x34);
	_shl(edi, 4);
	_add(edi, edx);
	_inc(edi);
	_pop(edi);
	edx = ds.dword(di+0x2C);
	_push(edi);
	edi = ds.word(di+0x34);
	_shl(edi, 4);
	_add(edi, edx);
	_add(edi, 2);
	_pop(edi);
	edx = ds.dword(di+0x24);
	_push(edi);
	edi = ds.word(di+0x34);
	_shl(edi, 4);
	_add(edi, edx);
	_pop(edi);
loc_1219e:
	edx = ds.dword(di+0x2C);
	_push(edi);
	edi = ds.word(di+0x34);
	_shl(edi, 4);
	_add(edi, edx);
	_inc(edi);
	_pop(edi);
	loc_12215;
loc_121b9:
	_test(ds.byte(di+0x3C), 8);
		_jz(loc_121ee);
	edx = ds.dword(di+0x24);
	_test(ds.byte(di+0x3C), 0x10);
		_jz(loc_121cd);
	edx = ds.dword(di+0x2C);
loc_121cd:
	_push(edi);
	bx = ds.word(di+0x34);
	edi = bx;
	_and(di, 0x1FFF);
	_and(bx, 0x0C000);
	_shr(bx, 1);
	_or(di, bx);
	_shl(edi, 4);
	_add(edi, edx);
	_pop(edi);
loc_121ee:
	edx = ds.dword(di+0x2C);
	_push(edi);
	bx = ds.word(di+0x34);
	edi = bx;
	_and(di, 0x1FFF);
	_and(bx, 0x0C000);
	_shr(bx, 1);
	_or(di, bx);
	_shl(edi, 4);
	_add(edi, edx);
	_inc(edi);
	_pop(edi);
loc_12215:
	_pop(cx);
loc_12216:
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_1213c);
	_write_cf(false);
 locret_1221f:
	return;
loc_11f70:
}

void InertiaPlayerContext::_mod_sub_12220() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_24674), 1);
		_jz(loc_12228);
	return;
loc_12228:
	al = data.byte(k_byte_24676);
	_cmp(data.byte(k_byte_24675), 0);
		_jz(loc_12239);
	data.byte(k_byte_24675) = 0;
	al = 0;
loc_12239:
	_add(al, es.byte(si));
	es.byte(si) = al;
	_inc(si);
	_dec(cx);
		_jnz(loc_12239);
	data.byte(k_byte_24676) = al;
	return;
}

	_pop(flags);
	_pop(es);
	_pop(bp);
	_pop(edi);
	_pop(esi);
	_pop(bx);
	_pop(dx);
		_jc(locret_122e7);
	_or(ax, ax);
		_jz(loc_122e3);
	eax = ax;
	_add(esi, eax);
	_cmp(dx, 0x0FFFF);
		_jnz(loc_122da);
	_add(bp, 0x800);
	loc_122dc;
loc_122da:
	_inc(dx);
	_inc(dx);
loc_122dc:
	_sub(edi, eax);
		_ja(loc_1224f);
loc_122e3:
	ecx = esi;
	_write_cf(false);
 locret_122e7:
	return;
loc_1224f:
}

void InertiaPlayerContext::_ems_mapmemx() {
	STACK_CHECK;
	_test(ds.byte(di+0x3C), 8);
		_jnz(loc_12386);
	ecx = ds.dword(di+0x2C);
	_inc(ecx);
	ebx = ecx;
	edx = ds.dword(di+0x20);
	_add(edx, 0x800);
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jz(loc_1234e);
	_push(eax);
	_push(ecx);
	_push(edx);
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem();
	_pop(edx);
	_pop(ecx);
	_pop(eax);
	_push(eax);
	_push(ecx);
	_push(edx);
	ebx = edx;
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem2();
	_pop(edx);
	_pop(ecx);
	_pop(eax);
	_and(ecx, 0x3FFF);
	_and(edx, 0x3FFF);
	_add(edx, 0x8000);
loc_1234e:
	si = dx;
	_and(si, 0x0F);
	_shr(edx, 4);
	_add(dx, ax);
	fs = dx;
	di = cx;
	_and(di, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	es = cx;
	cx = 0x200;
	_write_df(false);
 loc_1236c:
	eax = es.dword(di);
	fs.dword(si) = eax;
	es.dword(di) = 0;
	_add(si, 4);
	_add(di, 4);
	_dec(cx);
		_jnz(loc_1236c);
	return;
loc_12386:
	_push(ax);
	_push(di);
	ecx = ds.dword(di+0x2C);
	_inc(ecx);
	ebx = ecx;
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jz(loc_123b0);
	_push(ecx);
	_push(eax);
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem();
	_pop(eax);
	_pop(ecx);
	_and(ecx, 0x3FFF);
loc_123b0:
	si = cx;
	_and(si, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	fs = cx;
	ecx = ds.dword(di+0x20);
	_add(ecx, 0x800);
	ebx = ecx;
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jz(loc_123ee);
	_push(ecx);
	_push(eax);
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem2();
	_pop(eax);
	_pop(ecx);
	_and(ecx, 0x3FFF);
	_add(cx, 0x8000);
loc_123ee:
	bx = cx;
	_and(bx, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	es = cx;
	di = bx;
	cx = 0x200;
	_write_df(false);
 	while(cx--)
		_movs(es.dword(di), fs.dword(si));
	_pop(di);
	_pop(ax);
	ecx = ds.dword(di+0x24);
	ebx = ecx;
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jz(loc_1242d);
	_push(ecx);
	_push(eax);
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem();
	_pop(eax);
	_pop(ecx);
	_and(ecx, 0x3FFF);
loc_1242d:
	si = cx;
	_and(si, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	fs = cx;
	ecx = ds.dword(di+0x2C);
	_inc(ecx);
	ebx = ecx;
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jz(loc_12466);
	_push(ecx);
	_push(eax);
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem2();
	_pop(eax);
	_pop(ecx);
	_and(ecx, 0x3FFF);
	_add(cx, 0x8000);
loc_12466:
	bx = cx;
	_and(bx, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	es = cx;
	_cmp(ds.dword(di+0x28), 0x800);
		_ja(loc_12497);
	edx = ds.dword(di+0x28);
	_add(dx, si);
	di = bx;
	bp = si;
	cx = 0x800;
	_write_df(false);
 loc_1248b:
	_movs(es.byte(di), fs.byte(si));
	_cmp(si, dx);
		_jc(loc_12493);
	si = bp;
loc_12493:
	_dec(cx);
		_jnz(loc_1248b);
	return;
loc_12497:
	di = bx;
	cx = 0x200;
	_write_df(false);
 	while(cx--)
		_movs(es.dword(di), fs.dword(si));
	return;
	return;
/*continuing to unbounded code: loc_1234e from _ems_mapmemx:32-164*/
loc_1234e:
	si = dx;
	_and(si, 0x0F);
	_shr(edx, 4);
	_add(dx, ax);
	fs = dx;
	di = cx;
	_and(di, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	es = cx;
	cx = 0x200;
	_write_df(false);
 loc_1236c:
	eax = es.dword(di);
	fs.dword(si) = eax;
	es.dword(di) = 0;
	_add(si, 4);
	_add(di, 4);
	_dec(cx);
		_jnz(loc_1236c);
	return;
loc_12386:
	_push(ax);
	_push(di);
	ecx = ds.dword(di+0x2C);
	_inc(ecx);
	ebx = ecx;
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jz(loc_123b0);
	_push(ecx);
	_push(eax);
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem();
	_pop(eax);
	_pop(ecx);
	_and(ecx, 0x3FFF);
loc_123b0:
	si = cx;
	_and(si, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	fs = cx;
	ecx = ds.dword(di+0x20);
	_add(ecx, 0x800);
	ebx = ecx;
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jz(loc_123ee);
	_push(ecx);
	_push(eax);
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem2();
	_pop(eax);
	_pop(ecx);
	_and(ecx, 0x3FFF);
	_add(cx, 0x8000);
loc_123ee:
	bx = cx;
	_and(bx, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	es = cx;
	di = bx;
	cx = 0x200;
	_write_df(false);
 	while(cx--)
		_movs(es.dword(di), fs.dword(si));
	_pop(di);
	_pop(ax);
	ecx = ds.dword(di+0x24);
	ebx = ecx;
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jz(loc_1242d);
	_push(ecx);
	_push(eax);
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem();
	_pop(eax);
	_pop(ecx);
	_and(ecx, 0x3FFF);
loc_1242d:
	si = cx;
	_and(si, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	fs = cx;
	ecx = ds.dword(di+0x2C);
	_inc(ecx);
	ebx = ecx;
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jz(loc_12466);
	_push(ecx);
	_push(eax);
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem2();
	_pop(eax);
	_pop(ecx);
	_and(ecx, 0x3FFF);
	_add(cx, 0x8000);
loc_12466:
	bx = cx;
	_and(bx, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	es = cx;
	_cmp(ds.dword(di+0x28), 0x800);
		_ja(loc_12497);
	edx = ds.dword(di+0x28);
	_add(dx, si);
	di = bx;
	bp = si;
	cx = 0x800;
	_write_df(false);
 loc_1248b:
	_movs(es.byte(di), fs.byte(si));
	_cmp(si, dx);
		_jc(loc_12493);
	si = bp;
loc_12493:
	_dec(cx);
		_jnz(loc_1248b);
	return;
loc_12497:
	di = bx;
	cx = 0x200;
	_write_df(false);
 	while(cx--)
		_movs(es.dword(di), fs.dword(si));
	return;
loc_1234e:
}

void InertiaPlayerContext::_ems_mapmemy() {
	STACK_CHECK;
	_test(ds.byte(di+0x3C), 8);
		_jnz(loc_1253b);
	ecx = ds.dword(di+0x2C);
	_inc(ecx);
	ebx = ecx;
	edx = ds.dword(di+0x20);
	_add(edx, 0x800);
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jz(loc_12508);
	_push(eax);
	_push(ecx);
	_push(edx);
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem();
	_pop(edx);
	_pop(ecx);
	_pop(eax);
	_push(eax);
	_push(ecx);
	_push(edx);
	ebx = edx;
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem2();
	_pop(edx);
	_pop(ecx);
	_pop(eax);
	_and(ecx, 0x3FFF);
	_and(edx, 0x3FFF);
	_add(edx, 0x8000);
loc_12508:
	si = dx;
	_and(si, 0x0F);
	_shr(edx, 4);
	_add(dx, ax);
	fs = dx;
	di = cx;
	_and(di, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	es = cx;
	cx = 0x200;
	eax = 0;
	_write_df(false);
 loc_12529:
	eax = fs.dword(si);
	es.dword(di) = eax;
	_add(si, 4);
	_add(di, 4);
	_dec(cx);
		_jnz(loc_12529);
	return;
loc_1253b:
	ecx = ds.dword(di+0x20);
	_add(ecx, 0x800);
	ebx = ecx;
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jz(loc_12568);
	_push(ecx);
	_push(eax);
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem();
	_pop(eax);
	_pop(ecx);
	_and(ecx, 0x3FFF);
loc_12568:
	si = cx;
	_and(si, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	fs = cx;
	ecx = ds.dword(di+0x2C);
	_inc(ecx);
	ebx = ecx;
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jz(loc_125a1);
	_push(ecx);
	_push(eax);
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem2();
	_pop(eax);
	_pop(ecx);
	_and(ecx, 0x3FFF);
	_add(cx, 0x8000);
loc_125a1:
	bx = cx;
	_and(bx, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	es = cx;
	di = bx;
	cx = 0x200;
	_write_df(false);
 	while(cx--)
		_movs(es.dword(di), fs.dword(si));
	return;
	return;
/*continuing to unbounded code: loc_1253b from _ems_mapmemy:54-99*/
loc_1253b:
	ecx = ds.dword(di+0x20);
	_add(ecx, 0x800);
	ebx = ecx;
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jz(loc_12568);
	_push(ecx);
	_push(eax);
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem();
	_pop(eax);
	_pop(ecx);
	_and(ecx, 0x3FFF);
loc_12568:
	si = cx;
	_and(si, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	fs = cx;
	ecx = ds.dword(di+0x2C);
	_inc(ecx);
	ebx = ecx;
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jz(loc_125a1);
	_push(ecx);
	_push(eax);
	_shr(ebx, 0x0E);
	_add(bx, ds.word(di+0x32));
	_ems_mapmem2();
	_pop(eax);
	_pop(ecx);
	_and(ecx, 0x3FFF);
	_add(cx, 0x8000);
loc_125a1:
	bx = cx;
	_and(bx, 0x0F);
	_shr(ecx, 4);
	_add(cx, ax);
	es = cx;
	di = bx;
	cx = 0x200;
	_write_df(false);
 	while(cx--)
		_movs(es.dword(di), fs.dword(si));
	return;
loc_1253b:
}

	_pop(flags);
	return;
}

void InertiaPlayerContext::_memfree_125da() {
	STACK_CHECK;
	_push(ds);
	ax = ;
	ds = ax;
	_ems_realloc();
	_cmp(data.dword(k_dword_24640)[2], 0);
		_jz(loc_125f6);
	_memfree_18a28();
	data.dword(k_dword_24640) = 0;
loc_125f6:
	_cmp(data.byte(k_byte_24665), 1);
		_jnz(loc_1265b);
	_test(data.byte(k_sndflags_24622), 4);
		_jnz(loc_1263d);
	_test(data.byte(k_sndflags_24622), 0x10);
		_jnz(loc_1263d);
	di = 6885;
	cx = data.word(k_word_245d2);
loc_12612:
	_push(cx);
	_test(ds.byte(di+0x3C), 1);
		_jz(loc_12636);
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jnz(loc_12636);
	_cmp(ds.word(di+0x30), 0);
		_jz(loc_12636);
	ax = ds.word(di+0x30);
	_push(di);
	_memfree();
	_pop(di);
	_and(ds.byte(di+0x3C), 0x0FE);
	ds.word(di+0x30) = 0;
loc_12636:
	_pop(cx);
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_12612);
loc_1263d:
	di = 6895;
	cx = data.word(k_word_245f2);
loc_12644:
	ax = ds.word(di);
	_or(ax, ax);
		_jz(loc_12655);
	_push(cx);
	_push(di);
	_memfree();
	_pop(di);
	_pop(cx);
	ds.word(di) = 0;
loc_12655:
	_add(di, 2);
	_dec(cx);
		_jnz(loc_12644);
loc_1265b:
	_pop(ds);
	return;
	return;
/*continuing to unbounded code: loc_125f6 from _memfree_125da:9-56*/
loc_125f6:
	_cmp(data.byte(k_byte_24665), 1);
		_jnz(loc_1265b);
	_test(data.byte(k_sndflags_24622), 4);
		_jnz(loc_1263d);
	_test(data.byte(k_sndflags_24622), 0x10);
		_jnz(loc_1263d);
	di = 6885;
	cx = data.word(k_word_245d2);
loc_12612:
	_push(cx);
	_test(ds.byte(di+0x3C), 1);
		_jz(loc_12636);
	_cmp(ds.word(di+0x32), 0x0FFFF);
		_jnz(loc_12636);
	_cmp(ds.word(di+0x30), 0);
		_jz(loc_12636);
	ax = ds.word(di+0x30);
	_push(di);
	_memfree();
	_pop(di);
	_and(ds.byte(di+0x3C), 0x0FE);
	ds.word(di+0x30) = 0;
loc_12636:
	_pop(cx);
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_12612);
loc_1263d:
	di = 6895;
	cx = data.word(k_word_245f2);
loc_12644:
	ax = ds.word(di);
	_or(ax, ax);
		_jz(loc_12655);
	_push(cx);
	_push(di);
	_memfree();
	_pop(di);
	_pop(cx);
	ds.word(di) = 0;
loc_12655:
	_add(di, 2);
	_dec(cx);
		_jnz(loc_12644);
loc_1265b:
	_pop(ds);
	return;
loc_125f6:
}

void InertiaPlayerContext::sub_1265d() {
	STACK_CHECK;
	ax = ;
	es = ax;
	ax = data.word(k_volume_245fc);
	_dec(ax);
	cl = al;
	si = 6884;
	di = 3151;
	bp = data.byte(k_sndcard_type);
	ch = data.byte(k_byte_24666);
	bh = data.byte(k_byte_24667);
	dl = data.byte(k_sndflags_24622);
	dh = data.byte(k_byte_24628);
	_dec(dh);
	_and(dh, 3);
	_shl(dh, 1);
	_or(dh, data.byte(k_byte_24623));
	_shl(dh, 1);
	_or(dh, data.byte(k_byte_24671));
	_shl(dh, 3);
	al = data.word(k_word_245f6);
	ah = data.word(k_word_245f0);
	return;
}

void InertiaPlayerContext::sub_126a9() {
	STACK_CHECK;
	ax = ;
	es = ax;
	di = 3151;
	si = 6885;
	bl = data.word(k_word_245fa);
	bh = data.word(k_word_245d2);
	cl = data.word(k_word_245d4);
	ch = data.byte(k_byte_24617);
	eax = data.dword(k_module_type_text);
	return;
}

	_pop(flags);
	ds.dword(si+4) = eax;
	_add(si, 0x50);
	_dec(cx);
		_jnz(loc_1272d);
	_pop(es);
	_pop(di);
	si = 6884;
	ax = data.word(k_word_245d4);
loc_1275f:
	_push(ax);
	_push(si);
	_test(ds.byte(si+0x17), 1);
		_jnz(loc_1276c);
	_memclean();
	loc_1278f;
loc_1276c:
	_cmp(data.byte(k_byte_2466e), 1);
		_jz(loc_1276c);
	_push(si);
	_push(di);
	_push(es);
	eax = data.dword(k_dword_24640);
	sub_1279a();
	_pop(es);
	_pop(di);
	_pop(si);
loc_12780:
	_cmp(data.byte(k_byte_2466e), 1);
		_jz(loc_12780);
	ax = data.dword(k_dword_24640);
	sub_1281a();
loc_1278f:
	_pop(si);
	_pop(ax);
	_add(si, 0x50);
	_dec(al);
		_jnz(loc_1275f);
	_pop(ds);
	return;
loc_126f0:
}

void InertiaPlayerContext::sub_1279a() {
	STACK_CHECK;
	data.dword(k_dma_buf_pointer) = eax;
	ax = data.word(k_word_24610);
	ah = 0;
	_mul(ax, [si+0x20]);
	_mul(data.word(k_my_size));
	_shrd(ax, dx, 8);
	_add(ax, 0x30);
	_test(data.word(k_word_24610), 0x8000);
		_jz(loc_127bd);
	_add(ax, 0x100);
loc_127bd:
	_test(ds.byte(si+0x19), 4);
	if (!flags.z()) cl = 1; else cl = 0; //setnz
	_shl(ax, cl);
	_cmp(ax, 0x800);
		_jc(loc_127ce);
	ax = 0x800;
loc_127ce:
	cx = ax;
	eax = ds.dword(si+4);
	_shr(eax, 0x0D);
	_and(al, 0x0FE);
	_test(ds.byte(si+0x19), 4);
		_jz({ sub_182DB(); return; });
	eax = ds.dword(si+4);
	_shr(eax, 0x0D);
	dx = ax;
	_and(dx, 0x0C000);
	_and(ax, 0x1FFF);
	_shl(ax, 1);
	_or(ax, dx);
	_push(cx);
	sub_182db();
	_pop(cx);
loc_127fc:
	_cmp(data.byte(k_byte_2466e), 1);
		_jz(loc_127fc);
	_shr(cx, 1);
	_push(ds);
	di = data.dword(k_dma_buf_pointer);
	bx = ds.word(di+1);
loc_1280d:
	al = ds.byte(bx);
	ds.byte(di) = al;
	_add(bx, 2);
	_inc(di);
	_dec(cx);
		_jnz(loc_1280d);
	_pop(ds);
	return;
	return;
/*continuing to unbounded code: loc_127bd from sub_1279a:11-50*/
loc_127bd:
	_test(ds.byte(si+0x19), 4);
	if (!flags.z()) cl = 1; else cl = 0; //setnz
	_shl(ax, cl);
	_cmp(ax, 0x800);
		_jc(loc_127ce);
	ax = 0x800;
loc_127ce:
	cx = ax;
	eax = ds.dword(si+4);
	_shr(eax, 0x0D);
	_and(al, 0x0FE);
	_test(ds.byte(si+0x19), 4);
		_jz({ sub_182DB(); return; });
	eax = ds.dword(si+4);
	_shr(eax, 0x0D);
	dx = ax;
	_and(dx, 0x0C000);
	_and(ax, 0x1FFF);
	_shl(ax, 1);
	_or(ax, dx);
	_push(cx);
	sub_182db();
	_pop(cx);
loc_127fc:
	_cmp(data.byte(k_byte_2466e), 1);
		_jz(loc_127fc);
	_shr(cx, 1);
	_push(ds);
	di = data.dword(k_dma_buf_pointer);
	bx = ds.word(di+1);
loc_1280d:
	al = ds.byte(bx);
	ds.byte(di) = al;
	_add(bx, 2);
	_inc(di);
	_dec(cx);
		_jnz(loc_1280d);
	_pop(ds);
	return;
loc_127bd:
}

void InertiaPlayerContext::sub_1281a() {
	STACK_CHECK;
	_shl(eax, 0x10);
	ax = data.word(k_word_24610);
	ah = 0;
	_mul(ds.word(si+0x20));
	bp = ax;
	_shr(bp, 8);
	dh = al;
	dl = 0;
	_shr(eax, 0x10);
	loc_12898;
	return;
/*continuing to unbounded code: loc_12898 from _volume_prepare_waves:38-396*/
loc_12898:
	ebx = ds.byte(si+0x23);
	si = ax;
	_test(data.word(k_word_24610), 0x4000);
		_jz(loc_128bb);
	_cmp(data.word(k_amplification), 120);
		_jbe(loc_128bb);
	ax = 100;
	_push(dx);
	_mul(bx);
	_div(data.word(k_amplification));
	_pop(dx);
	bx = ax;
loc_128bb:
	_shl(ebx, 9);
	_add(bx, 6904);
	_inc(bx);
	cx = data.word(k_my_size);
	_test(data.word(k_word_24610), 0x8000);
		_jz(loc_1291e);
	_shl(ecx, 16);
	_shl(esi, 16);
	si = ax;
	cx = 0x100;
loc_128dd:
	eax = fs.dword(si);
	_inc(si);
	_or(al, al);
		_jns(loc_12913);
	_or(ah, ah);
		_js(loc_12913);
	_ror(eax, 8);
	_cmp(al, ah);
		_jg(loc_12913);
	_ror(eax, 8);
	_cmp(al, ah);
		_jg(loc_12913);
	_rol(eax, 16);
	ax = fs.word(si+3);
	_rol(eax, 8);
	_cmp(al, ah);
		_jg(loc_12913);
	_ror(eax, 8);
	_inc(si);
	_cmp(al, ah);
		_jle(loc_1291a);
loc_12913:
	_dec(cx);
		_jnz(loc_128dd);
	_shr(esi, 16);
loc_1291a:
	_shr(ecx, 16);
loc_1291e:
	eax = 0;
loc_12921:
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jnz(loc_12921);
locret_12a55:
	return;
	_shl(ebx, 9);
	_add(bx, 6904);
	_inc(bx);
	cx = data.word(k_my_size);
	_test(data.word(k_word_24610), 0x8000);
		_jz(loc_1291e);
	_shl(ecx, 16);
	_shl(esi, 16);
	si = ax;
	cx = 0x100;
loc_128dd:
	eax = fs.dword(si);
	_inc(si);
	_or(al, al);
		_jns(loc_12913);
	_or(ah, ah);
		_js(loc_12913);
	_ror(eax, 8);
	_cmp(al, ah);
		_jg(loc_12913);
	_ror(eax, 8);
	_cmp(al, ah);
		_jg(loc_12913);
	_rol(eax, 16);
	ax = fs.word(si+3);
	_rol(eax, 8);
	_cmp(al, ah);
		_jg(loc_12913);
	_ror(eax, 8);
	_inc(si);
	_cmp(al, ah);
		_jle(loc_1291a);
loc_12913:
	_dec(cx);
		_jnz(loc_128dd);
	_shr(esi, 16);
loc_1291a:
	_shr(ecx, 16);
loc_1291e:
	eax = 0;
loc_12921:
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jnz(loc_12921);
locret_12a55:
	return;
}

void InertiaPlayerContext::_volume_prepare_waves() {
	STACK_CHECK;
	_test(ds.byte(si+0x17), 1);
		_jz({ _memclean(); return; });
	_test(data.byte(k_sndflags_24622), 1);
		_jz({ _memclean(); return; });
	_push(di);
	_push(es);
	bx = ds.word(si+0x26);
	eax = ds.dword(si+4);
	_shr(eax, 22);
	_add(bx, ax);
	_push(si);
	_ems_mapmem();
	_pop(si);
	eax = ds.dword(si+4);
	bx = ax;
	_shr(eax, 12);
	_cmp(ds.word(si+0x26), 0x0FFFF);
		_jz(loc_12870);
	_and(eax, 0x3FF);
loc_12870:
	_add(ax, ds.word(si+0x24));
	fs = ax;
	ax = data.word(k_word_24610);
	ah = 0;
	_mul(ds.word(si+0x20));
	_mul(data.word(k_freq1));
	bp = 22050;
	_div(bp);
	dx = ax;
	ax = bh;
	_and(al, 0x0F);
	bp = dx;
	_shr(bp, 8);
	dh = dl;
	dl = bl;
	_pop(es);
	_pop(di);
	ebx = ds.byte(si+0x23);
	si = ax;
	_test(data.word(k_word_24610), 0x4000);
		_jz(loc_128bb);
	_cmp(data.word(k_amplification), 120);
		_jbe(loc_128bb);
	ax = 100;
	_push(dx);
	_mul(bx);
	_div(data.word(k_amplification));
	_pop(dx);
	bx = ax;
loc_128bb:
	_shl(ebx, 9);
	_add(bx, 6904);
	_inc(bx);
	cx = data.word(k_my_size);
	_test(data.word(k_word_24610), 0x8000);
		_jz(loc_1291e);
	_shl(ecx, 16);
	_shl(esi, 16);
	si = ax;
	cx = 0x100;
loc_128dd:
	eax = fs.dword(si);
	_inc(si);
	_or(al, al);
		_jns(loc_12913);
	_or(ah, ah);
		_js(loc_12913);
	_ror(eax, 8);
	_cmp(al, ah);
		_jg(loc_12913);
	_ror(eax, 8);
	_cmp(al, ah);
		_jg(loc_12913);
	_rol(eax, 16);
	ax = fs.word(si+3);
	_rol(eax, 8);
	_cmp(al, ah);
		_jg(loc_12913);
	_ror(eax, 8);
	_inc(si);
	_cmp(al, ah);
		_jle(loc_1291a);
loc_12913:
	_dec(cx);
		_jnz(loc_128dd);
	_shr(esi, 16);
loc_1291a:
	_shr(ecx, 16);
loc_1291e:
	eax = 0;
loc_12921:
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jnz(loc_12921);
locret_12a55:
	return;
	return;
/*continuing to unbounded code: loc_128bb from _volume_prepare_waves:51-222*/
loc_128bb:
	_shl(ebx, 9);
	_add(bx, 6904);
	_inc(bx);
	cx = data.word(k_my_size);
	_test(data.word(k_word_24610), 0x8000);
		_jz(loc_1291e);
	_shl(ecx, 16);
	_shl(esi, 16);
	si = ax;
	cx = 0x100;
loc_128dd:
	eax = fs.dword(si);
	_inc(si);
	_or(al, al);
		_jns(loc_12913);
	_or(ah, ah);
		_js(loc_12913);
	_ror(eax, 8);
	_cmp(al, ah);
		_jg(loc_12913);
	_ror(eax, 8);
	_cmp(al, ah);
		_jg(loc_12913);
	_rol(eax, 16);
	ax = fs.word(si+3);
	_rol(eax, 8);
	_cmp(al, ah);
		_jg(loc_12913);
	_ror(eax, 8);
	_inc(si);
	_cmp(al, ah);
		_jle(loc_1291a);
loc_12913:
	_dec(cx);
		_jnz(loc_128dd);
	_shr(esi, 16);
loc_1291a:
	_shr(ecx, 16);
loc_1291e:
	eax = 0;
loc_12921:
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jz(locret_12a55);
	al = fs.byte(si);
	al = ds.byte(ebx+eax*2);
	es.byte(di) = al;
	_add(dl, dh);
	_inc(di);
	_adc(si, bp);
	_dec(cx);
		_jnz(loc_12921);
locret_12a55:
	return;
loc_128bb:
}

void InertiaPlayerContext::_memclean() {
	STACK_CHECK;
	_write_df(false);
 	cx = data.word(k_my_size);
	ax = 0;
	_shr(cx, 1);
	_stosw(cx, true);
	_adc(cx, cx);
	_stosb(cx, true);
	return;
}

void InertiaPlayerContext::_volume_12a66() {
	STACK_CHECK;
	_push(ds);
	ax = ;
	ds = ax;
	cx = data.word(k_word_245d4);
	bx = 6884;
loc_12a73:
	_push(bx);
	cx = cx;
	_pop(bx);
	_add(bx, 0x50);
	_dec(cx);
		_jnz(loc_12a73);
	_pop(ds);
	return;
	return;
/*continuing to unbounded code: loc_12a73 from _volume_12a66:6-14*/
loc_12a73:
	_push(bx);
	cx = cx;
	_pop(bx);
	_add(bx, 0x50);
	_dec(cx);
		_jnz(loc_12a73);
	_pop(ds);
	return;
loc_12a73:
}

void InertiaPlayerContext::_change_volume() {
	STACK_CHECK;
	_push(ds);
	cx = ;
	ds = cx;
	_cmp(ax, -1);
		_jz(loc_12aa9);
	data.word(k_volume_245fc) = ax;
	cx = data.word(k_word_245d4);
	bx = 6884;
loc_12a98:
	_push(bx);
	_push(cx);
	al = ds.byte(bx+8);
	_pop(cx);
	_pop(bx);
	_add(bx, 0x50);
	_dec(cx);
		_jnz(loc_12a98);
loc_12aa9:
	ax = data.word(k_volume_245fc);
	_pop(ds);
	return;
	return;
/*continuing to unbounded code: loc_12a98 from _change_volume:9-21*/
loc_12a98:
	_push(bx);
	_push(cx);
	al = ds.byte(bx+8);
	_pop(cx);
	_pop(bx);
	_add(bx, 0x50);
	_dec(cx);
		_jnz(loc_12a98);
loc_12aa9:
	ax = data.word(k_volume_245fc);
	_pop(ds);
	return;
loc_12a98:
}

void InertiaPlayerContext::_change_amplif() {
	STACK_CHECK;
	_push(ds);
	cx = ;
	ds = cx;
	_cmp(ax, -1);
		_jz(loc_12ace);
	data.word(k_amplification) = ax;
	data.byte(k_byte_24625) = 0;
	_cmp(ax, 100);
		_jbe(loc_12acb);
	data.byte(k_byte_24625) = 1;
loc_12acb:
	sub_13044();
loc_12ace:
	ax = data.word(k_amplification);
	_pop(ds);
	return;
	return;
/*continuing to unbounded code: loc_12acb from _change_amplif:11-16*/
loc_12acb:
	sub_13044();
loc_12ace:
	ax = data.word(k_amplification);
	_pop(ds);
	return;
loc_12acb:
}

void InertiaPlayerContext::_get_playsettings() {
	STACK_CHECK;
	_push(ds);
	ax = ;
	ds = ax;
	al = data.byte(k_flag_playsetttings);
	_pop(ds);
	return;
}

void InertiaPlayerContext::_set_playsettings() {
	STACK_CHECK;
	_push(ds);
	bx = ;
	ds = bx;
	data.byte(k_flag_playsetttings) = al;
	_someplaymode();
	_and(data.word(k_config_word)[1], 0x0FE);
	_test(data.byte(k_flag_playsetttings), 0x10);
		_jz(loc_12afb);
	_or(data.word(k_config_word)[1], 1);
loc_12afb:
	_pop(ds);
	return;
	return;
/*continuing to unbounded code: loc_12afb from _set_playsettings:10-12*/
loc_12afb:
	_pop(ds);
	return;
loc_12afb:
}

void InertiaPlayerContext::sub_12afd() {
	STACK_CHECK;
	_push(ds);
	bx = ;
	ds = bx;
	bx = ch;
	_cmp(bx, data.word(k_word_245d4));
		_jnc(loc_12b16);
	_mul(bx, 80);
	_add(bx, 6884);
	_eff_13a43();
loc_12b16:
	_pop(ds);
	return;
	return;
/*continuing to unbounded code: loc_12b16 from sub_12afd:10-12*/
loc_12b16:
	_pop(ds);
	return;
loc_12b16:
}

void InertiaPlayerContext::sub_12b18() {
	STACK_CHECK;
	_push(ax);
	_push(ds);
	_push(es);
	ax = ;
	es = ax;
	di = 6886;
	cx = 8;
	_write_df(false);
 	while(cx--)
		_movsd();
	ds = ax;
	data.byte(k_byte_2461c) = 0;
	data.byte(k_byte_2461d) = 0;
	si = 6886;
	bx = 6884;
	cx = data.word(k_word_245d4);
	al = 0;
loc_12b42:
	_push(ax);
	ds.byte(bx+0x18) = al;
	al = ds.byte(si);
	ds.byte(bx+0x3A) = al;
	_test(data.byte(k_sndflags_24622), 4);
		_jnz(loc_12b5f);
	_cmp(al, 0x40);
	al = 0;
		_jc(loc_12b5a);
	al = 0x80;
loc_12b5a:
	ds.byte(bx+0x3A) = al;
	loc_12b62;
loc_12b5f:
loc_12b62:
	al = ds.byte(bx+0x3A);
	_cmp(al, 0);
		_jz(loc_12b71);
	_inc(data.byte(k_byte_2461d));
	_cmp(al, 0x80);
		_jz(loc_12b75);
loc_12b71:
	_inc(data.byte(k_byte_2461c));
loc_12b75:
	_pop(ax);
	_add(bx, 80);
	_inc(si);
	_inc(al);
	_dec(cx);
		_jnz(loc_12b42);
	_pop(es);
	_pop(ds);
	_pop(ax);
	return;
	return;
/*continuing to unbounded code: loc_12b42 from sub_12b18:18-52*/
loc_12b42:
	_push(ax);
	ds.byte(bx+0x18) = al;
	al = ds.byte(si);
	ds.byte(bx+0x3A) = al;
	_test(data.byte(k_sndflags_24622), 4);
		_jnz(loc_12b5f);
	_cmp(al, 0x40);
	al = 0;
		_jc(loc_12b5a);
	al = 0x80;
loc_12b5a:
	ds.byte(bx+0x3A) = al;
	loc_12b62;
loc_12b5f:
loc_12b62:
	al = ds.byte(bx+0x3A);
	_cmp(al, 0);
		_jz(loc_12b71);
	_inc(data.byte(k_byte_2461d));
	_cmp(al, 0x80);
		_jz(loc_12b75);
loc_12b71:
	_inc(data.byte(k_byte_2461c));
loc_12b75:
	_pop(ax);
	_add(bx, 80);
	_inc(si);
	_inc(al);
	_dec(cx);
		_jnz(loc_12b42);
	_pop(es);
	_pop(ds);
	_pop(ax);
	return;
loc_12b42:
}

void InertiaPlayerContext::sub_12b83() {
	STACK_CHECK;
	_push(ax);
	_push(ds);
	bx = ;
	ds = bx;
	ah = 0;
	_cmp(al, 0x20);
		_jc(loc_12b92);
	al = 0x20;
loc_12b92:
	_cmp(al, 2);
		_ja(loc_12b98);
	al = 2;
loc_12b98:
	data.word(k_word_245d4) = ax;
	di = 6884;
	cx = data.word(k_word_245d4);
	dx = 0;
	bx = 0;
loc_12ba6:
	_cmp(ds.byte(di+0x1D), 0);
		_jnz(loc_12bb3);
	ds.byte(di+0x18) = dl;
	_inc(dl);
	loc_12bcb;
loc_12bb3:
	_cmp(ds.byte(di+0x1D), 1);
		_jnz(loc_12bc0);
	ds.byte(di+0x18) = dh;
	_inc(dh);
	loc_12bcb;
loc_12bc0:
	_cmp(ds.byte(di+0x1D), 2);
		_jnz(loc_12bcb);
	ds.byte(di+0x18) = bl;
	_inc(bl);
loc_12bcb:
	_add(di, 80);
	_dec(cx);
		_jnz(loc_12ba6);
	ah = 0;
	al = dl;
	data.word(k_word_245d6) = ax;
	al = dh;
	data.word(k_word_245d8) = ax;
	al = bl;
	data.word(k_word_245da) = ax;
	_test(data.byte(k_sndflags_24622), 4);
		_jz(loc_12bef);
	ax = data.word(k_word_245d6);
loc_12bef:
	sub_13044();
	_someplaymode();
	_pop(ds);
	_pop(ax);
	return;
	return;
/*continuing to unbounded code: loc_12b92 from sub_12b83:9-55*/
loc_12b92:
	_cmp(al, 2);
		_ja(loc_12b98);
	al = 2;
loc_12b98:
	data.word(k_word_245d4) = ax;
	di = 6884;
	cx = data.word(k_word_245d4);
	dx = 0;
	bx = 0;
loc_12ba6:
	_cmp(ds.byte(di+0x1D), 0);
		_jnz(loc_12bb3);
	ds.byte(di+0x18) = dl;
	_inc(dl);
	loc_12bcb;
loc_12bb3:
	_cmp(ds.byte(di+0x1D), 1);
		_jnz(loc_12bc0);
	ds.byte(di+0x18) = dh;
	_inc(dh);
	loc_12bcb;
loc_12bc0:
	_cmp(ds.byte(di+0x1D), 2);
		_jnz(loc_12bcb);
	ds.byte(di+0x18) = bl;
	_inc(bl);
loc_12bcb:
	_add(di, 80);
	_dec(cx);
		_jnz(loc_12ba6);
	ah = 0;
	al = dl;
	data.word(k_word_245d6) = ax;
	al = dh;
	data.word(k_word_245d8) = ax;
	al = bl;
	data.word(k_word_245da) = ax;
	_test(data.byte(k_sndflags_24622), 4);
		_jz(loc_12bef);
	ax = data.word(k_word_245d6);
loc_12bef:
	sub_13044();
	_someplaymode();
	_pop(ds);
	_pop(ax);
	return;
loc_12b92:
}

void InertiaPlayerContext::_someplaymode() {
	STACK_CHECK;
	edx = 3;
	eax = 1775763456;
	ecx = 0x369D800;
	_cmp(data.byte(k_byte_2461a), 0);
		_jnz(loc_12c3c);
	edx = 3;
	eax = 1643177984;
	ecx = 0x361F0F0;
	_test(data.byte(k_flag_playsetttings), 8);
		_jnz(loc_12c3c);
	edx = 3;
	eax = 1776914432;
	ecx = 0x369E990;
loc_12c3c:
	data.dword(k_dword_245c0) = ecx;
	edi = data.word(k_freq1);
	cl = data.byte(k_byte_2461a);
	_shl(edi, cl);
	_div(edi);
	data.dword(k_dword_245bc) = eax;
	_test(data.byte(k_sndflags_24622), 4);
		_jz(loc_12c86);
	ecx = data.byte(k_byte_24629);
	eax = 385532977;
	_test(data.byte(k_flag_playsetttings), 8);
		_jnz(loc_12c75);
	eax = 389081954;
loc_12c75:
	_mul(ecx);
	cl = 12;
	_add(cl, data.byte(k_byte_2461a));
	_shrd(eax, edx, cl);
	data.dword(k_dword_2463c) = eax;
loc_12c86:
	di = 6884;
	cx = data.word(k_word_245d4);
	ax = 0;
loc_12c8f:
	ds.word(di+0x3E) = ax;
	_add(di, 0x50);
	_dec(cx);
		_jnz(loc_12c8f);
	return;
	return;
/*continuing to unbounded code: loc_12c3c from _someplaymode:14-43*/
loc_12c3c:
	data.dword(k_dword_245c0) = ecx;
	edi = data.word(k_freq1);
	cl = data.byte(k_byte_2461a);
	_shl(edi, cl);
	_div(edi);
	data.dword(k_dword_245bc) = eax;
	_test(data.byte(k_sndflags_24622), 4);
		_jz(loc_12c86);
	ecx = data.byte(k_byte_24629);
	eax = 385532977;
	_test(data.byte(k_flag_playsetttings), 8);
		_jnz(loc_12c75);
	eax = 389081954;
loc_12c75:
	_mul(ecx);
	cl = 12;
	_add(cl, data.byte(k_byte_2461a));
	_shrd(eax, edx, cl);
	data.dword(k_dword_2463c) = eax;
loc_12c86:
	di = 6884;
	cx = data.word(k_word_245d4);
	ax = 0;
loc_12c8f:
	ds.word(di+0x3E) = ax;
	_add(di, 0x50);
	_dec(cx);
		_jnz(loc_12c8f);
	return;
loc_12c3c:
}

void InertiaPlayerContext::_getset_playstate() {
	STACK_CHECK;
	_push(bx);
	_push(ds);
	bx = ;
	ds = bx;
	_cmp(al, 0x0FF);
		_jz(loc_12ca7);
	data.byte(k_play_state) = al;
loc_12ca7:
	al = data.byte(k_play_state);
	_pop(ds);
	_pop(bx);
	return;
	return;
/*continuing to unbounded code: loc_12ca7 from _getset_playstate:8-12*/
loc_12ca7:
	al = data.byte(k_play_state);
	_pop(ds);
	_pop(bx);
	return;
loc_12ca7:
}

void InertiaPlayerContext::sub_12cad() {
	STACK_CHECK;
	_push(ds);
	_push(es);
	ax = ;
	ds = ax;
	es = ax;
	si = 3142;
	al = ch;
	_or(al, 0x0E0);
	data.word(k_word_246a9) = bx;
	data.byte(k_byte_246a8) = cl;
	data.word(k_word_246a6) = dx;
	sub_13623();
	_pop(es);
	_pop(ds);
	return;
}

void InertiaPlayerContext::_read_sndsettings() {
	STACK_CHECK;
	_push(ds);
	ax = ;
	ds = ax;
	al = data.byte(k_sndcard_type);
	dx = data.word(k_snd_base_port);
	cl = data.byte(k_irq_number);
	ch = data.byte(k_dma_channel);
	ah = data.byte(k_freq_246d7);
	bl = data.byte(k_byte_246d8);
	bh = data.byte(k_byte_246d9);
	bp = data.word(k_freq1);
	_test(data.byte(k_sndflags_24622), 4);
		_jz(loc_12cff);
	bp = data.word(k_freq2);
loc_12cff:
	si = data.word(k_config_word);
	_pop(ds);
	return;
	return;
/*continuing to unbounded code: loc_12cff from _read_sndsettings:15-18*/
loc_12cff:
	si = data.word(k_config_word);
	_pop(ds);
	return;
loc_12cff:
}

void InertiaPlayerContext::sub_12d05() {
	STACK_CHECK;
	_push(ds);
	_push(di);
	_push(es);
	ax = ;
	ds = ax;
	si = 6457;
	_cmp(data.byte(k_snd_init), 1);
		_jnz(loc_12d2e);
	si = data.byte(k_sndcard_type);
	_shl(si, 1);
	si = 6506;
	di = 6905;
	_myasmsprintf();
	ds.byte(di) = 0;
	si = 6905;
loc_12d2e:
	_pop(es);
	_pop(di);
	_strcpy_count_0();
	_pop(ds);
	return;
	return;
/*continuing to unbounded code: loc_12d2e from sub_12d05:16-22*/
loc_12d2e:
	_pop(es);
	_pop(di);
	_strcpy_count_0();
	_pop(ds);
	return;
loc_12d2e:
}

void InertiaPlayerContext::sub_12d35() {
	STACK_CHECK;
	_push(ax);
	_push(bx);
	_push(ds);
	bx = ;
	ds = bx;
	_cmp(al, 1);
		_jz(loc_12d4e);
	data.byte(k_byte_14f71) = 0;
	_setmemalloc1();
	_pop(ds);
	_pop(bx);
	_pop(ax);
	return;
loc_12d4e:
	data.byte(k_byte_14f71) = 1;
	ax = data.word(k_word_2460c);
	_setmemallocstrat();
	_initclockfromrtc();
	_pop(ds);
	_pop(bx);
	_pop(ax);
	return;
	return;
/*continuing to unbounded code: loc_12d4e from sub_12d35:15-23*/
loc_12d4e:
	data.byte(k_byte_14f71) = 1;
	ax = data.word(k_word_2460c);
	_setmemallocstrat();
	_initclockfromrtc();
	_pop(ds);
	_pop(bx);
	_pop(ax);
	return;
loc_12d4e:
}

	_pop(flags);
	_write_cf(true);
 	return;
loc_12e55:
}

	_pop(flags);
	return;
}

	_pop(flags);
	return;
}

	_pop(flags);
	return;
loc_12f78:
}

	_pop(flags);
	return;
}

void InertiaPlayerContext::_set_timer_int() {
	STACK_CHECK;
	ebx = 0x1000;
	_push(dx);
	_memalloc();
	_pop(dx);
		_jc(locret_12fb3);
	data.dword(k_dma_buf_pointer) = 0;
	data.dword(k_dma_buf_pointer)[2] = ax;
	_push(ax);
	_push(dx);
	_memfill8080();
	_pop(bx);
	dx = cs;
	al = 8;
	_setint_vect();
	_pop(ax);
	_write_cf(false);
 locret_12fb3:
	return;
	return;
/*continuing to unbounded code: locret_12fb3 from _set_timer_int:17-18*/
locret_12fb3:
	return;
locret_12fb3:
}

void InertiaPlayerContext::_clean_int8_mem_timr() {
	STACK_CHECK;
	dx = data.dword(k_int8addr)[2];
	bx = data.dword(k_int8addr);
	al = 8;
	_setint_vect();
	_clean_timer();
	ax = data.dword(k_dma_buf_pointer)[2];
	_memfree();
	return;
}

	_pop(flags);
	return;
}

	_pop(flags);
	return;
}

void InertiaPlayerContext::sub_13017() {
	STACK_CHECK;
	di = 6885;
	cx = data.word(k_word_245d2);
loc_1301e:
	_test(ds.byte(di+0x3C), 8);
		_jnz(loc_1302c);
	eax = ds.dword(di+0x2C);
	ds.dword(di+0x24) = eax;
loc_1302c:
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_1301e);
	data.word(k_word_24600) = 0;
loc_13038:
	sub_16c69();
	_cmp(data.word(k_word_24600), 0x800);
		_jbe(loc_13038);
	return;
	return;
/*continuing to unbounded code: loc_1301e from sub_13017:3-17*/
loc_1301e:
	_test(ds.byte(di+0x3C), 8);
		_jnz(loc_1302c);
	eax = ds.dword(di+0x2C);
	ds.dword(di+0x24) = eax;
loc_1302c:
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_1301e);
	data.word(k_word_24600) = 0;
loc_13038:
	sub_16c69();
	_cmp(data.word(k_word_24600), 0x800);
		_jbe(loc_13038);
	return;
loc_1301e:
}

void InertiaPlayerContext::sub_13044() {
	STACK_CHECK;
	al = data.byte(k_byte_2467e);
	_cmp(al, 0);
		_jz(loc_13080);
	_cmp(al, 1);
		_jz(loc_1305a);
	_cmp(al, 2);
		_jz(loc_1306d);
	data.byte(k_byte_2467e) = 0;
	loc_13080;
loc_1305a:
	data.byte(k_byte_2467d) = 0x3F;
	data.word(kOff_2462e) = 3351;
	data.word(kOff_24656) = 6048;
	loc_13091;
loc_1306d:
	data.byte(k_byte_2467d) = 0x3F;
	data.word(kOff_2462e) = 3479;
	data.word(kOff_24656) = 6112;
	loc_13091;
loc_13080:
	data.byte(k_byte_2467d) = 0x40;
	data.word(kOff_2462e) = 3221;
	data.word(kOff_24656) = 5983;
loc_13091:
	di = 6904;
	eax = data.word(k_word_245d6);
	_cmp(ax, 2);
		_ja(loc_130a2);
	ax = 2;
loc_130a2:
	_cmp(data.byte(k_byte_24623), 1);
		_jnz(loc_130ae);
	_shr(ax, 1);
	_adc(ax, 0);
loc_130ae:
	ebp = ax;
	si = data.word(kOff_24656);
	cx = data.byte(k_byte_2467d);
	_inc(cx);
loc_130bc:
	_push(cx);
	_push(ebp);
	eax = ds.byte(si);
	_inc(si);
	edx = data.word(k_amplification);
	_shl(edx, 16);
	_mul(edx);
	ecx = 100;
	_div(ecx);
	edx = 0;
	_div(ebp);
	bp = ax;
	_shr(eax, 16);
	ecx = eax;
	_cmp(data.byte(k_byte_24625), 1);
		_jz(loc_13120);
	ax = 0;
	dx = 0;
	bl = 0x80;
loc_130f6:
	ds.word(di) = ax;
	_add(dx, bp);
	_adc(ax, cx);
	_add(di, 2);
	_dec(bl);
		_jnz(loc_130f6);
	_add(di, 0x100);
	ax = 0;
	dx = 0;
	bl = 0x80;
loc_1310d:
	_sub(di, 2);
	_sub(dx, bp);
	_sbb(ax, cx);
	ds.word(di) = ax;
	_dec(bl);
		_jnz(loc_1310d);
	_add(di, 0x100);
	loc_13162;
loc_13120:
	eax = 0;
	dx = 0;
	bl = 0x80;
loc_13127:
	_cmp(eax, 0x7FFF);
		_jg(loc_1316b);
	ds.word(di) = ax;
loc_13131:
	_add(dx, bp);
	_adc(eax, ecx);
	_add(di, 2);
	_dec(bl);
		_jnz(loc_13127);
	_add(di, 0x100);
	eax = 0;
	dx = 0;
	bl = 0x80;
loc_13148:
	_sub(di, 2);
	_sub(dx, bp);
	_sbb(eax, ecx);
	_cmp(eax, 0x0FFFF8000);
		_jl(loc_13171);
	ds.word(di) = ax;
loc_1315a:
	_dec(bl);
		_jnz(loc_13148);
	_add(di, 0x100);
loc_13162:
	_pop(ebp);
	_pop(cx);
	_dec(cx);
		_jnz(loc_130bc);
	return;
loc_1316b:
	ds.word(di) = 0x7FFF;
	loc_13131;
loc_13171:
	ds.word(di) = 0x8000;
	loc_1315a;
	return;
/*continuing to unbounded code: loc_1305a from sub_13044:10-120*/
loc_1305a:
	data.byte(k_byte_2467d) = 0x3F;
	data.word(kOff_2462e) = 3351;
	data.word(kOff_24656) = 6048;
	loc_13091;
loc_1306d:
	data.byte(k_byte_2467d) = 0x3F;
	data.word(kOff_2462e) = 3479;
	data.word(kOff_24656) = 6112;
	loc_13091;
loc_13080:
	data.byte(k_byte_2467d) = 0x40;
	data.word(kOff_2462e) = 3221;
	data.word(kOff_24656) = 5983;
loc_13091:
	di = 6904;
	eax = data.word(k_word_245d6);
	_cmp(ax, 2);
		_ja(loc_130a2);
	ax = 2;
loc_130a2:
	_cmp(data.byte(k_byte_24623), 1);
		_jnz(loc_130ae);
	_shr(ax, 1);
	_adc(ax, 0);
loc_130ae:
	ebp = ax;
	si = data.word(kOff_24656);
	cx = data.byte(k_byte_2467d);
	_inc(cx);
loc_130bc:
	_push(cx);
	_push(ebp);
	eax = ds.byte(si);
	_inc(si);
	edx = data.word(k_amplification);
	_shl(edx, 16);
	_mul(edx);
	ecx = 100;
	_div(ecx);
	edx = 0;
	_div(ebp);
	bp = ax;
	_shr(eax, 16);
	ecx = eax;
	_cmp(data.byte(k_byte_24625), 1);
		_jz(loc_13120);
	ax = 0;
	dx = 0;
	bl = 0x80;
loc_130f6:
	ds.word(di) = ax;
	_add(dx, bp);
	_adc(ax, cx);
	_add(di, 2);
	_dec(bl);
		_jnz(loc_130f6);
	_add(di, 0x100);
	ax = 0;
	dx = 0;
	bl = 0x80;
loc_1310d:
	_sub(di, 2);
	_sub(dx, bp);
	_sbb(ax, cx);
	ds.word(di) = ax;
	_dec(bl);
		_jnz(loc_1310d);
	_add(di, 0x100);
	loc_13162;
loc_13120:
	eax = 0;
	dx = 0;
	bl = 0x80;
loc_13127:
	_cmp(eax, 0x7FFF);
		_jg(loc_1316b);
	ds.word(di) = ax;
loc_13131:
	_add(dx, bp);
	_adc(eax, ecx);
	_add(di, 2);
	_dec(bl);
		_jnz(loc_13127);
	_add(di, 0x100);
	eax = 0;
	dx = 0;
	bl = 0x80;
loc_13148:
	_sub(di, 2);
	_sub(dx, bp);
	_sbb(eax, ecx);
	_cmp(eax, 0x0FFFF8000);
		_jl(loc_13171);
	ds.word(di) = ax;
loc_1315a:
	_dec(bl);
		_jnz(loc_13148);
	_add(di, 0x100);
loc_13162:
	_pop(ebp);
	_pop(cx);
	_dec(cx);
		_jnz(loc_130bc);
	return;
loc_1316b:
	ds.word(di) = 0x7FFF;
	loc_13131;
loc_13171:
	ds.word(di) = 0x8000;
	loc_1315a;
loc_1305a:
}

void InertiaPlayerContext::sub_13177() {
	STACK_CHECK;
	_or(ax, ax);
		_jz(locret_131b2);
	_or(ds.byte(bx+0x3D), 4);
	_cmp(ds.byte(bx+0x1D), 1);
		_jz(loc_131b3);
	_cmp(ax, ds.word(bx+0x3E));
		_jz(locret_131b2);
	ds.word(bx+0x3E) = ax;
	edi = ax;
	edx = 0;
	eax = data.dword(k_dword_245bc);
	_div(edi);
	ds.word(bx+0x20) = ax;
	cl = data.byte(k_byte_2461a);
	_shl(edi, cl);
	edx = 0;
	eax = data.dword(k_dword_245c0);
	_div(edi);
	ds.word(bx+0x1E) = ax;
locret_131b2:
	return;
loc_131b3:
	edi = ax;
	edx = 0;
	cl = data.byte(k_byte_2461a);
	_shl(edi, cl);
	edx = 0;
	eax = data.dword(k_dword_245c0);
	_div(edi);
	ds.word(bx+0x1E) = ax;
	return;
	return;
/*continuing to unbounded code: locret_131b2 from sub_13177:20-31*/
locret_131b2:
	return;
loc_131b3:
	edi = ax;
	edx = 0;
	cl = data.byte(k_byte_2461a);
	_shl(edi, cl);
	edx = 0;
	eax = data.dword(k_dword_245c0);
	_div(edi);
	ds.word(bx+0x1E) = ax;
	return;
locret_131b2:
}

void InertiaPlayerContext::_nullsub_5() {
	STACK_CHECK;
	return;
}

void InertiaPlayerContext::sub_131da() {
	STACK_CHECK;
	_cmp(ds.byte(bx+0x1D), 1);
		_jz({ _nullsub_5(); return; });
	_test(ds.byte(bx+0x17), 1);
		_jz(locret_131ee);
	_and(ds.byte(bx+0x17), 0x0FE);
	ds.byte(bx+0x35) = 0;
locret_131ee:
	return;
	return;
/*continuing to unbounded code: locret_131ee from sub_131da:7-8*/
locret_131ee:
	return;
locret_131ee:
}

void InertiaPlayerContext::sub_131ef() {
	STACK_CHECK;
	_cmp(ds.byte(bx+0x1D), 1);
		_jz(loc_131d0);
	_and(ds.byte(bx+0x3D), 0x0BF);
	_cmp(al, data.byte(k_byte_2467d));
		_jbe(loc_13202);
	al = data.byte(k_byte_2467d);
loc_13202:
	ah = 0;
	ds.byte(bx+0x22) = al;
	_mul(data.word(k_volume_245fc));
	al = ds.byte(bx+0x23);
	ds.word(bx+0x36) = ax;
	ds.byte(bx+0x23) = ah;
	return;
}

void InertiaPlayerContext::sub_13429() {
	STACK_CHECK;
	_test(ds.byte(bx+0x17), 4);
		_jz(locret_13498);
	al = ds.byte(bx+2);
	_cmp(al, ds.byte(bx+3));
		_jz(loc_13471);
	ds.byte(bx+3) = al;
	_dec(al);
	ah = 0;
	_shl(ax, 6);
	di = ax;
	_add(di, 6885);
	eax = ds.dword(bx+0x28);
	ds.dword(bx+0x40) = eax;
	eax = ds.dword(bx+0x2C);
	ds.dword(bx+0x44) = eax;
	eax = ds.dword(bx+0x30);
	ds.dword(bx+0x48) = eax;
	al = ds.byte(di+0x3C);
	ds.byte(bx+0x19) = al;
	ax = ds.word(di+0x32);
	ds.word(bx+0x26) = ax;
	ax = ds.word(di+0x30);
	ds.word(bx+0x24) = ax;
loc_13471:
	ax = ds.word(bx);
	sub_13177();
	al = 0;
	sub_131ef();
	al = ds.byte(bx+8);
	sub_131ef();
	_test(ds.byte(bx+0x17), 2);
		_jnz(loc_13499);
	_or(ds.byte(bx+0x17), 1);
	eax = ds.word(bx+0x4C);
	_shl(eax, 8);
	ds.dword(bx+4) = eax;
locret_13498:
	return;
loc_13499:
	_test(ds.byte(bx+0x17), 1);
		_jnz({ sub_131DA(); return; });
	return;
}

void InertiaPlayerContext::sub_135ca() {
	STACK_CHECK;
	bx = 6884;
	cx = data.word(k_word_245d4);
	ax = 0;
loc_135d3:
	ds.byte(bx+0x3D) = 0;
	_test(ds.byte(bx+0x17), 0x10);
		_jnz(loc_135e0);
	ds.word(bx+0x0A) = ax;
loc_135e0:
	_add(bx, 0x50);
	_dec(cx);
		_jnz(loc_135d3);
	si = data.dword(k_pointer_245b4);
	al = es.byte(si);
	_inc(si);
	_or(al, al);
		_jz(loc_135fd);
loc_135f2:
	sub_13623();
	al = es.byte(si);
	_inc(si);
	_or(al, al);
		_jnz(loc_135f2);
loc_135fd:
	data.dword(k_pointer_245b4) = si;
	bx = 6884;
	cx = data.word(k_word_245d4);
loc_13608:
	_test(ds.byte(bx+0x17), 1);
		_jz(loc_1361c);
	_test(ds.byte(bx+0x3D), 0x0C);
		_jnz(loc_1361c);
	ax = ds.word(bx);
	cx = cx;
loc_1361c:
	_add(bx, 0x50);
	_dec(cx);
		_jnz(loc_13608);
	return;
	return;
/*continuing to unbounded code: loc_135d3 from sub_135ca:4-39*/
loc_135d3:
	ds.byte(bx+0x3D) = 0;
	_test(ds.byte(bx+0x17), 0x10);
		_jnz(loc_135e0);
	ds.word(bx+0x0A) = ax;
loc_135e0:
	_add(bx, 0x50);
	_dec(cx);
		_jnz(loc_135d3);
	si = data.dword(k_pointer_245b4);
	al = es.byte(si);
	_inc(si);
	_or(al, al);
		_jz(loc_135fd);
loc_135f2:
	sub_13623();
	al = es.byte(si);
	_inc(si);
	_or(al, al);
		_jnz(loc_135f2);
loc_135fd:
	data.dword(k_pointer_245b4) = si;
	bx = 6884;
	cx = data.word(k_word_245d4);
loc_13608:
	_test(ds.byte(bx+0x17), 1);
		_jz(loc_1361c);
	_test(ds.byte(bx+0x3D), 0x0C);
		_jnz(loc_1361c);
	ax = ds.word(bx);
	cx = cx;
loc_1361c:
	_add(bx, 0x50);
	_dec(cx);
		_jnz(loc_13608);
	return;
loc_135d3:
}

void InertiaPlayerContext::sub_13623() {
	STACK_CHECK;
	dh = al;
	_and(dh, 0x0E0);
	_and(ax, 0x1F);
	_cmp(ax, data.word(k_word_245d4));
		_jnc(loc_137be);
	_shl(ax, 4);
	bx = ax;
	_shl(ax, 2);
	_add(bx, ax);
	_add(bx, 6884);
	_test(dh, 0x80);
		_jz(loc_13661);
	_and(dh, 0x7F);
	ax = es.word(si);
	_add(si, 2);
	_or(ax, ax);
		_jz(loc_13661);
	_and(ds.byte(bx+0x17), 0x0EF);
	_cmp(al, 0x20);
		_ja(loc_13661);
	_or(dh, 0x80);
	ds.word(bx+0x0A) = ax;
loc_13661:
	_test(dh, 0x40);
		_jz(loc_13677);
	_and(dh, 0x0BF);
	al = es.byte(si);
	_inc(si);
	_cmp(al, 0x40);
		_ja(loc_13677);
	_or(dh, 0x40);
	ds.byte(bx+8) = al;
loc_13677:
	ds.byte(bx+0x3D) = dh;
	_test(dh, 0x20);
		_jz({ sub_137D5(); return; });
	dx = es.word(si);
	_add(si, 2);
	_or(dh, dh);
		_jz(loc_13718);
	ax = dh;
	_cmp(ax, data.word(k_word_245d2));
		_ja(loc_13718);
	_dec(ax);
	_shl(ax, 6);
	di = ax;
	_add(di, 6885);
	_and(ds.byte(bx+0x17), 0x0FB);
	al = ds.byte(di+0x3C);
	_and(al, 1);
	_shl(al, 2);
	_or(ds.byte(bx+0x17), al);
	_or(ds.byte(bx+0x3D), 0x10);
	ds.byte(bx+2) = dh;
	ds.word(bx+0x4C) = 0;
	_test(ds.byte(bx+0x17), 0x40);
		_jz(loc_136cb);
	_and(ds.byte(bx+0x17), 0x0BF);
	ds.byte(bx+3) = 0;
loc_136cb:
	eax = ds.dword(di+0x24);
	ds.dword(bx+0x28) = eax;
	eax = ds.dword(di+0x28);
	ds.dword(bx+0x2C) = eax;
	eax = ds.dword(di+0x2C);
	ds.dword(bx+0x30) = eax;
	cl = ds.byte(di+0x3E);
	_and(cx, 0x0F);
	_shl(cx, 3);
	ax = cx;
	_neg(ax);
	_shl(cx, 4);
	_add(ax, cx);
	_add(ax, 3863);
	ds.word(bx+0x38) = ax;
	ax = data.word(k_freq_245de);
	cx = ds.word(di+0x36);
	if (cx==0)
		loc_13705;
	ax = cx;
loc_13705:
	ds.word(bx+0x14) = ax;
	_test(ds.byte(bx+0x3D), 0x40);
		_jnz(loc_13718);
	al = ds.byte(di+0x3D);
	ds.byte(bx+8) = al;
	_or(ds.byte(bx+0x3D), 0x40);
loc_13718:
	_or(dl, dl);
		_jz({ sub_137D5(); return; });
	_cmp(dl, 0x0FE);
		_jz(loc_137ce);
	_cmp(dl, 0x0FF);
		_jz({ sub_137D5(); return; });
	ds.byte(bx+0x35) = dl;
	_or(ds.byte(bx+0x3D), 8);
	_test(data.byte(k_sndflags_24622), 0x10);
		_jnz(loc_13742);
	_test(ds.byte(bx+0x17), 4);
		_jz(loc_137ce);
loc_13742:
	al = ds.byte(bx+0x35);
	sub_13826();
	_xchg(ax, ds.word(bx));
	_test(ds.byte(bx+0x3D), 0x80);
		_jz(loc_13791);
	data.word(k_word_245dc) = ax;
	ax = ds.word(bx+0x0A);
	_and(ah, 0x0F0);
	_cmp(al, 3);
		_jz(loc_138bd);
	_cmp(al, 5);
		_jz(loc_138bd);
	_cmp(al, 9);
		_jz(loc_13ace);
	_cmp(al, 0x0C);
		_jz(loc_13b66);
	_cmp(ax, 0x500E);
		_jz(loc_13bf1);
	_cmp(ax, 0x0D00E);
		_jz(loc_13cae);
	_cmp(al, 0x13);
		_jz(loc_13df9);
	_cmp(al, 0x16);
		_jz(loc_13df9);
	_cmp(al, 0x19);
		_jz(loc_13ed3);
loc_13791:
	_test(ds.byte(bx+9), 4);
		_jnz(loc_1379f);
	ds.byte(bx+0x0D) = 0;
loc_1379f:
	_test(ds.byte(bx+9), 0x40);
		_jnz(loc_137a9);
	ds.byte(bx+0x0F) = 0;
loc_137a9:
	di = ds.byte(bx+0x0A);
	_cmp(di, 32);
		_ja({ _eff_nullsub(); return; });
	_shl(di, 1);
	al = ds.byte(bx+0x0B);
	cs:_effoff_18fa2[di];
loc_137be:
	di = dh;
	_shr(di, 5);
	al = data.byte(k_byte_11c29)[di];
	ah = 0;
	_add(si, ax);
	return;
loc_137ce:
	sub_137d5();
	[off_245ce];
	return;
/*continuing to unbounded code: loc_136cb from sub_13623:61-152*/
loc_136cb:
	eax = ds.dword(di+0x24);
	ds.dword(bx+0x28) = eax;
	eax = ds.dword(di+0x28);
	ds.dword(bx+0x2C) = eax;
	eax = ds.dword(di+0x2C);
	ds.dword(bx+0x30) = eax;
	cl = ds.byte(di+0x3E);
	_and(cx, 0x0F);
	_shl(cx, 3);
	ax = cx;
	_neg(ax);
	_shl(cx, 4);
	_add(ax, cx);
	_add(ax, 3863);
	ds.word(bx+0x38) = ax;
	ax = data.word(k_freq_245de);
	cx = ds.word(di+0x36);
	if (cx==0)
		loc_13705;
	ax = cx;
loc_13705:
	ds.word(bx+0x14) = ax;
	_test(ds.byte(bx+0x3D), 0x40);
		_jnz(loc_13718);
	al = ds.byte(di+0x3D);
	ds.byte(bx+8) = al;
	_or(ds.byte(bx+0x3D), 0x40);
loc_13718:
	_or(dl, dl);
		_jz({ sub_137D5(); return; });
	_cmp(dl, 0x0FE);
		_jz(loc_137ce);
	_cmp(dl, 0x0FF);
		_jz({ sub_137D5(); return; });
	ds.byte(bx+0x35) = dl;
	_or(ds.byte(bx+0x3D), 8);
	_test(data.byte(k_sndflags_24622), 0x10);
		_jnz(loc_13742);
	_test(ds.byte(bx+0x17), 4);
		_jz(loc_137ce);
loc_13742:
	al = ds.byte(bx+0x35);
	sub_13826();
	_xchg(ax, ds.word(bx));
	_test(ds.byte(bx+0x3D), 0x80);
		_jz(loc_13791);
	data.word(k_word_245dc) = ax;
	ax = ds.word(bx+0x0A);
	_and(ah, 0x0F0);
	_cmp(al, 3);
		_jz(loc_138bd);
	_cmp(al, 5);
		_jz(loc_138bd);
	_cmp(al, 9);
		_jz(loc_13ace);
	_cmp(al, 0x0C);
		_jz(loc_13b66);
	_cmp(ax, 0x500E);
		_jz(loc_13bf1);
	_cmp(ax, 0x0D00E);
		_jz(loc_13cae);
	_cmp(al, 0x13);
		_jz(loc_13df9);
	_cmp(al, 0x16);
		_jz(loc_13df9);
	_cmp(al, 0x19);
		_jz(loc_13ed3);
loc_13791:
	_test(ds.byte(bx+9), 4);
		_jnz(loc_1379f);
	ds.byte(bx+0x0D) = 0;
loc_1379f:
	_test(ds.byte(bx+9), 0x40);
		_jnz(loc_137a9);
	ds.byte(bx+0x0F) = 0;
loc_137a9:
	di = ds.byte(bx+0x0A);
	_cmp(di, 32);
		_ja({ _eff_nullsub(); return; });
	_shl(di, 1);
	al = ds.byte(bx+0x0B);
	cs:_effoff_18fa2[di];
loc_137be:
	di = dh;
	_shr(di, 5);
	al = data.byte(k_byte_11c29)[di];
	ah = 0;
	_add(si, ax);
	return;
loc_137ce:
	sub_137d5();
	[off_245ce];
loc_136cb:
}

void InertiaPlayerContext::sub_137d5() {
	STACK_CHECK;
	_test(ds.byte(bx+0x3D), 0x40);
		_jnz(loc_137f0);
	di = ds.byte(bx+0x0A);
	_cmp(di, 32);
		_ja({ _eff_nullsub(); return; });
	_shl(di, 1);
	al = ds.byte(bx+0x0B);
	cs:_effoff_18f60[di];
loc_137f0:
	di = ds.byte(bx+0x0A);
	_cmp(di, 32);
		_ja({ _eff_nullsub(); return; });
	_shl(di, 1);
	al = ds.byte(bx+0x0B);
	_test(ds.byte(bx+0x3D), 0x40);
		_jz(locret_13812);
	al = ds.byte(bx+8);
	[off_245cc];
locret_13812:
	return;
	return;
/*continuing to unbounded code: loc_137f0 from sub_137d5:9-20*/
loc_137f0:
	di = ds.byte(bx+0x0A);
	_cmp(di, 32);
		_ja({ _eff_nullsub(); return; });
	_shl(di, 1);
	al = ds.byte(bx+0x0B);
	_test(ds.byte(bx+0x3D), 0x40);
		_jz(locret_13812);
	al = ds.byte(bx+8);
	[off_245cc];
locret_13812:
	return;
loc_137f0:
}

void InertiaPlayerContext::sub_13813() {
	STACK_CHECK;
	di = ds.byte(bx+0x0A);
	_cmp(di, 32);
		_ja({ _eff_nullsub(); return; });
	_shl(di, 1);
	al = ds.byte(bx+0x0B);
	cs:_effoff_18fe4[di];
}

void InertiaPlayerContext::sub_13826() {
	STACK_CHECK;
	cl = al;
	di = cl;
	_dec(di);
	_and(di, 0x0F);
	_shl(di, 1);
	_shr(cl, 4);
	_cmp(data.byte(k_byte_2461a), 0);
		_jnz(loc_1386c);
	ch = cl;
	cl = 0;
	ax = 0;
	_or(ch, ch);
		_jz(loc_13863);
	ax = 24;
	_dec(ch);
		_jz(loc_13863);
	ax = 48;
	_dec(ch);
		_jz(loc_13863);
	ax = 72;
	_dec(ch);
		_jz(loc_13863);
	ax = 96;
	_dec(ch);
		_jz(loc_13863);
	cl = ch;
loc_13863:
	_add(di, ax);
	_add(di, ds.word(bx+0x38));
	_sub(di, 3165);
loc_1386c:
	ax = data.word(k_word_246de)[di];
	_shr(ax, cl);
	cx = ds.word(bx+0x14);
	if (cx==0)
		locret_1387d;
	_mul(data.word(k_freq_245de));
	_div(cx);
locret_1387d:
	return;
	return;
/*continuing to unbounded code: loc_1386c from sub_13826:32-40*/
loc_1386c:
	ax = data.word(k_word_246de)[di];
	_shr(ax, cl);
	cx = ds.word(bx+0x14);
	if (cx==0)
		locret_1387d;
	_mul(data.word(k_freq_245de));
	_div(cx);
locret_1387d:
	return;
loc_1386c:
}

void InertiaPlayerContext::_eff_nullsub() {
	STACK_CHECK;
	return;
}

void InertiaPlayerContext::_eff_1387f() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_24668), 0);
		_jnz({ _eff_nullsub(); return; });
}

void InertiaPlayerContext::_eff_13886() {
	STACK_CHECK;
	ah = 0;
	_shl(ax, 4);
	_sub(ds.word(bx), ax);
	_cmp(ds.word(bx), 0x0A0);
		_jge(loc_13897);
	ds.word(bx) = 0x0A0;
loc_13897:
	ax = ds.word(bx);
	[off_245ca];
}

void InertiaPlayerContext::_eff_1389d() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_24668), 0);
		_jnz({ _eff_nullsub(); return; });
}

void InertiaPlayerContext::_eff_138a4() {
	STACK_CHECK;
	ah = 0;
	_shl(ax, 4);
	_add(ds.word(bx), ax);
		_jc(loc_138b3);
	_cmp(ds.word(bx), 13696);
		_jbe(loc_138b7);
loc_138b3:
	ds.word(bx) = 13696;
loc_138b7:
	ax = ds.word(bx);
	[off_245ca];
	return;
/*continuing to unbounded code: loc_138b3 from _eff_138a4:8-12*/
loc_138b3:
	ds.word(bx) = 13696;
loc_138b7:
	ax = ds.word(bx);
	[off_245ca];
loc_138b3:
}

void InertiaPlayerContext::_eff_138d2() {
	STACK_CHECK;
	_or(al, al);
		_jz(loc_138de);
	ah = 0;
	_shl(ax, 4);
	ds.word(bx+0x12) = ax;
loc_138de:
	ax = ds.word(bx+0x10);
	_or(ax, ax);
		_jz(locret_13cf4);
	dx = ds.word(bx+0x12);
	_cmp(ax, ds.word(bx));
		_jc(loc_138f6);
	_add(ds.word(bx), dx);
	_cmp(ds.word(bx), ax);
		_jc(loc_1390b);
	loc_138fc;
loc_138f6:
	_sub(ds.word(bx), dx);
	_cmp(ax, ds.word(bx));
		_jl(loc_1390b);
loc_138fc:
	ds.word(bx) = ax;
	ds.word(bx+0x10) = 0;
	_and(ds.byte(bx+0x17), 0x0EF);
	[off_245ca];
loc_1390b:
	_test(ds.byte(bx+0x17), 0x20);
		_jnz(loc_13917);
	ax = ds.word(bx);
	[off_245ca];
loc_13917:
	di = ds.word(bx+0x38);
	ax = ds.word(bx);
	cx = 0x3B;
loc_1391f:
	_cmp(ds.word(di), ax);
		_jbe(loc_13929);
	_add(di, 2);
	_dec(cx);
		_jnz(loc_1391f);
loc_13929:
	ax = ds.word(di);
	[off_245ca];
	return;
/*continuing to unbounded code: loc_138de from _eff_138d2:6-43*/
loc_138de:
	ax = ds.word(bx+0x10);
	_or(ax, ax);
		_jz(locret_13cf4);
	dx = ds.word(bx+0x12);
	_cmp(ax, ds.word(bx));
		_jc(loc_138f6);
	_add(ds.word(bx), dx);
	_cmp(ds.word(bx), ax);
		_jc(loc_1390b);
	loc_138fc;
loc_138f6:
	_sub(ds.word(bx), dx);
	_cmp(ax, ds.word(bx));
		_jl(loc_1390b);
loc_138fc:
	ds.word(bx) = ax;
	ds.word(bx+0x10) = 0;
	_and(ds.byte(bx+0x17), 0x0EF);
	[off_245ca];
loc_1390b:
	_test(ds.byte(bx+0x17), 0x20);
		_jnz(loc_13917);
	ax = ds.word(bx);
	[off_245ca];
loc_13917:
	di = ds.word(bx+0x38);
	ax = ds.word(bx);
	cx = 0x3B;
loc_1391f:
	_cmp(ds.word(di), ax);
		_jbe(loc_13929);
	_add(di, 2);
	_dec(cx);
		_jnz(loc_1391f);
loc_13929:
	ax = ds.word(di);
	[off_245ca];
loc_138de:
}

void InertiaPlayerContext::_eff_1392f() {
	STACK_CHECK;
	cl = 3;
	_or(al, al);
		_jz(loc_13950);
	ch = al;
	dl = ds.byte(bx+0x0C);
	_and(al, 0x0F);
		_jz(loc_13943);
	_and(dl, 0x0F0);
	_or(dl, al);
loc_13943:
	_and(ch, 0x0F0);
		_jz(loc_1394d);
	_and(dl, 0x0F);
	_or(dl, ch);
loc_1394d:
	ds.byte(bx+0x0C) = dl;
loc_13950:
	al = ds.byte(bx+0x0D);
	_shr(al, 2);
	_and(ax, 0x1F);
	dl = ds.byte(bx+9);
	_and(dl, 3);
		_jz(loc_1397b);
	_shl(al, 3);
	_cmp(dl, 1);
		_jz(loc_1396d);
	dl = 0x0FF;
	loc_13981;
loc_1396d:
	dl = al;
	_test(ds.byte(bx+0x0D), 0x80);
		_jz(loc_13981);
	dl = 0x0FF;
	_sub(dl, al);
	loc_13981;
loc_1397b:
	di = ax;
	dl = data.byte(k_table_251c0)[di];
loc_13981:
	al = ds.byte(bx+0x0C);
	dh = al;
	_and(al, 0x0F);
	_mul(dl);
	ch = data.byte(k_flag_playsetttings);
	_and(ch, 1);
	_add(cl, ch);
	_shr(ax, cl);
	_test(ds.byte(bx+0x0D), 0x80);
		_jz(loc_1399d);
	_neg(ax);
loc_1399d:
	_add(ax, ds.word(bx));
	_shr(dh, 2);
	_and(dh, 0x3C);
	_add(ds.byte(bx+0x0D), dh);
	[off_245ca];
	return;
/*continuing to unbounded code: loc_1394d from _eff_1392f:16-57*/
loc_1394d:
	ds.byte(bx+0x0C) = dl;
loc_13950:
	al = ds.byte(bx+0x0D);
	_shr(al, 2);
	_and(ax, 0x1F);
	dl = ds.byte(bx+9);
	_and(dl, 3);
		_jz(loc_1397b);
	_shl(al, 3);
	_cmp(dl, 1);
		_jz(loc_1396d);
	dl = 0x0FF;
	loc_13981;
loc_1396d:
	dl = al;
	_test(ds.byte(bx+0x0D), 0x80);
		_jz(loc_13981);
	dl = 0x0FF;
	_sub(dl, al);
	loc_13981;
loc_1397b:
	di = ax;
	dl = data.byte(k_table_251c0)[di];
loc_13981:
	al = ds.byte(bx+0x0C);
	dh = al;
	_and(al, 0x0F);
	_mul(dl);
	ch = data.byte(k_flag_playsetttings);
	_and(ch, 1);
	_add(cl, ch);
	_shr(ax, cl);
	_test(ds.byte(bx+0x0D), 0x80);
		_jz(loc_1399d);
	_neg(ax);
loc_1399d:
	_add(ax, ds.word(bx));
	_shr(dh, 2);
	_and(dh, 0x3C);
	_add(ds.byte(bx+0x0D), dh);
	[off_245ca];
loc_1394d:
}

void InertiaPlayerContext::_eff_139ac() {
	STACK_CHECK;
	_eff_13ad7();
	loc_138de;
	return;
/*continuing to unbounded code: loc_138de from _eff_138d2:6-43*/
loc_138de:
	ax = ds.word(bx+0x10);
	_or(ax, ax);
		_jz(locret_13cf4);
	dx = ds.word(bx+0x12);
	_cmp(ax, ds.word(bx));
		_jc(loc_138f6);
	_add(ds.word(bx), dx);
	_cmp(ds.word(bx), ax);
		_jc(loc_1390b);
	loc_138fc;
loc_138f6:
	_sub(ds.word(bx), dx);
	_cmp(ax, ds.word(bx));
		_jl(loc_1390b);
loc_138fc:
	ds.word(bx) = ax;
	ds.word(bx+0x10) = 0;
	_and(ds.byte(bx+0x17), 0x0EF);
	[off_245ca];
loc_1390b:
	_test(ds.byte(bx+0x17), 0x20);
		_jnz(loc_13917);
	ax = ds.word(bx);
	[off_245ca];
loc_13917:
	di = ds.word(bx+0x38);
	ax = ds.word(bx);
	cx = 0x3B;
loc_1391f:
	_cmp(ds.word(di), ax);
		_jbe(loc_13929);
	_add(di, 2);
	_dec(cx);
		_jnz(loc_1391f);
loc_13929:
	ax = ds.word(di);
	[off_245ca];
}

void InertiaPlayerContext::_eff_139b2() {
	STACK_CHECK;
	_eff_13ad7();
	cl = 3;
	loc_13950;
	return;
/*continuing to unbounded code: loc_13950 from _eff_1392f:18-57*/
loc_13950:
	al = ds.byte(bx+0x0D);
	_shr(al, 2);
	_and(ax, 0x1F);
	dl = ds.byte(bx+9);
	_and(dl, 3);
		_jz(loc_1397b);
	_shl(al, 3);
	_cmp(dl, 1);
		_jz(loc_1396d);
	dl = 0x0FF;
	loc_13981;
loc_1396d:
	dl = al;
	_test(ds.byte(bx+0x0D), 0x80);
		_jz(loc_13981);
	dl = 0x0FF;
	_sub(dl, al);
	loc_13981;
loc_1397b:
	di = ax;
	dl = data.byte(k_table_251c0)[di];
loc_13981:
	al = ds.byte(bx+0x0C);
	dh = al;
	_and(al, 0x0F);
	_mul(dl);
	ch = data.byte(k_flag_playsetttings);
	_and(ch, 1);
	_add(cl, ch);
	_shr(ax, cl);
	_test(ds.byte(bx+0x0D), 0x80);
		_jz(loc_1399d);
	_neg(ax);
loc_1399d:
	_add(ax, ds.word(bx));
	_shr(dh, 2);
	_and(dh, 0x3C);
	_add(ds.byte(bx+0x0D), dh);
	[off_245ca];
}

void InertiaPlayerContext::_eff_139b9() {
	STACK_CHECK;
	_or(al, al);
		_jz(loc_139d8);
	cl = al;
	dl = ds.byte(bx+0x0E);
	_and(al, 0x0F);
		_jz(loc_139cb);
	_and(dl, 0x0F0);
	_or(dl, al);
loc_139cb:
	_and(cl, 0x0F0);
		_jz(loc_139d5);
	_and(dl, 0x0F);
	_or(dl, cl);
loc_139d5:
	ds.byte(bx+0x0E) = dl;
loc_139d8:
	al = ds.byte(bx+0x0F);
	_shr(al, 2);
	_and(ax, 0x1F);
	dl = ds.byte(bx+9);
	_shr(dl, 4);
	_and(dl, 3);
		_jz(loc_13a06);
	_shl(al, 3);
	_cmp(dl, 1);
		_jz(loc_139f8);
	dl = 0x0FF;
	loc_13a0c;
loc_139f8:
	dl = al;
	_test(ds.byte(bx+0x0F), 0x80);
		_jz(loc_13a0c);
	dl = 0x0FF;
	_sub(dl, al);
	loc_13a0c;
loc_13a06:
	di = ax;
	dl = data.byte(k_table_251c0)[di];
loc_13a0c:
	al = ds.byte(bx+0x0E);
	dh = al;
	_and(al, 0x0F);
	_mul(dl);
	_shr(ax, 6);
	ah = al;
	al = ds.byte(bx+8);
	_test(ds.byte(bx+0x0F), 0x80);
		_jnz(loc_13a30);
	_add(al, ah);
	_cmp(al, data.byte(k_byte_2467d));
		_jbe(loc_13a36);
	al = data.byte(k_byte_2467d);
	loc_13a36;
loc_13a30:
	_sub(al, ah);
		_jns(loc_13a36);
	al = 0;
loc_13a36:
	_shr(dh, 2);
	_and(dh, 0x3C);
	_add(ds.byte(bx+0x0F), dh);
	[off_245cc];
	return;
/*continuing to unbounded code: loc_139cb from _eff_139b9:9-62*/
loc_139cb:
	_and(cl, 0x0F0);
		_jz(loc_139d5);
	_and(dl, 0x0F);
	_or(dl, cl);
loc_139d5:
	ds.byte(bx+0x0E) = dl;
loc_139d8:
	al = ds.byte(bx+0x0F);
	_shr(al, 2);
	_and(ax, 0x1F);
	dl = ds.byte(bx+9);
	_shr(dl, 4);
	_and(dl, 3);
		_jz(loc_13a06);
	_shl(al, 3);
	_cmp(dl, 1);
		_jz(loc_139f8);
	dl = 0x0FF;
	loc_13a0c;
loc_139f8:
	dl = al;
	_test(ds.byte(bx+0x0F), 0x80);
		_jz(loc_13a0c);
	dl = 0x0FF;
	_sub(dl, al);
	loc_13a0c;
loc_13a06:
	di = ax;
	dl = data.byte(k_table_251c0)[di];
loc_13a0c:
	al = ds.byte(bx+0x0E);
	dh = al;
	_and(al, 0x0F);
	_mul(dl);
	_shr(ax, 6);
	ah = al;
	al = ds.byte(bx+8);
	_test(ds.byte(bx+0x0F), 0x80);
		_jnz(loc_13a30);
	_add(al, ah);
	_cmp(al, data.byte(k_byte_2467d));
		_jbe(loc_13a36);
	al = data.byte(k_byte_2467d);
	loc_13a36;
loc_13a30:
	_sub(al, ah);
		_jns(loc_13a36);
	al = 0;
loc_13a36:
	_shr(dh, 2);
	_and(dh, 0x3C);
	_add(ds.byte(bx+0x0F), dh);
	[off_245cc];
loc_139cb:
}

void InertiaPlayerContext::_eff_13a43() {
	STACK_CHECK;
	_cmp(al, 0x0A4);
		_jz(loc_13a5b);
	_cmp(al, 0x0A5);
		_jz(loc_13a60);
	_cmp(al, 0x0A6);
		_jz(loc_13a65);
	_cmp(al, 0x80);
		_ja(locret_13a5a);
	_test(data.byte(k_sndflags_24622), 4);
locret_13a5a:
	return;
loc_13a5b:
	_or(ds.byte(bx+0x17), 0x80);
	return;
loc_13a60:
	_and(ds.byte(bx+0x17), 0x7F);
	return;
loc_13a65:
	_xor(ds.byte(bx+0x17), 0x80);
	return;
	return;
/*continuing to unbounded code: locret_13a5a from _eff_13a43:10-20*/
locret_13a5a:
	return;
loc_13a5b:
	_or(ds.byte(bx+0x17), 0x80);
	return;
loc_13a60:
	_and(ds.byte(bx+0x17), 0x7F);
	return;
loc_13a65:
	_xor(ds.byte(bx+0x17), 0x80);
	return;
locret_13a5a:
}

void InertiaPlayerContext::_eff_13a94() {
	STACK_CHECK;
	_or(al, al);
		_jz(loc_13a9b);
	ds.byte(bx+0x16) = al;
loc_13a9b:
	eax = ds.byte(bx+0x16);
	_shl(eax, 8);
	_cmp(eax, ds.dword(bx+0x30));
		_ja(loc_13aae);
	ds.word(bx+0x4C) = ax;
	return;
loc_13aae:
	_cmp(data.byte(k_byte_2461a), 0);
		_jnz(loc_13ac6);
	_and(ds.byte(bx+0x17), 0x0FB);
	_or(ds.byte(bx+0x17), 0x40);
	ds.byte(bx+3) = 0;
	return;
loc_13ac6:
	eax = ds.dword(bx+0x30);
	ds.word(bx+0x4C) = ax;
	return;
	return;
/*continuing to unbounded code: loc_13a9b from _eff_13a94:4-21*/
loc_13a9b:
	eax = ds.byte(bx+0x16);
	_shl(eax, 8);
	_cmp(eax, ds.dword(bx+0x30));
		_ja(loc_13aae);
	ds.word(bx+0x4C) = ax;
	return;
loc_13aae:
	_cmp(data.byte(k_byte_2461a), 0);
		_jnz(loc_13ac6);
	_and(ds.byte(bx+0x17), 0x0FB);
	_or(ds.byte(bx+0x17), 0x40);
	ds.byte(bx+3) = 0;
	return;
loc_13ac6:
	eax = ds.dword(bx+0x30);
	ds.word(bx+0x4C) = ax;
	return;
loc_13a9b:
}

void InertiaPlayerContext::_eff_13ad7() {
	STACK_CHECK;
	dl = ds.byte(bx+8);
	_test(al, 0x0F0);
		_jnz(loc_13aef);
	_and(al, 0x0F);
	_sub(dl, al);
	al = dl;
		_jnc(loc_13ae8);
	al = 0;
loc_13ae8:
	ds.byte(bx+8) = al;
	[off_245cc];
loc_13aef:
	_shr(al, 4);
	_add(dl, al);
	al = dl;
	_cmp(al, data.byte(k_byte_2467d));
		_jbe(loc_13aff);
	al = data.byte(k_byte_2467d);
loc_13aff:
	ds.byte(bx+8) = al;
	[off_245cc];
	return;
/*continuing to unbounded code: loc_13ae8 from _eff_13ad7:11-24*/
loc_13ae8:
	ds.byte(bx+8) = al;
	[off_245cc];
loc_13aef:
	_shr(al, 4);
	_add(dl, al);
	al = dl;
	_cmp(al, data.byte(k_byte_2467d));
		_jbe(loc_13aff);
	al = data.byte(k_byte_2467d);
loc_13aff:
	ds.byte(bx+8) = al;
	[off_245cc];
loc_13ae8:
}

void InertiaPlayerContext::_eff_13b06() {
	STACK_CHECK;
	ah = 0;
	_dec(ax);
	data.word(k_word_245f0) = ax;
	_inc(ax);
	_test(data.byte(k_flag_playsetttings), 4);
		_jnz(loc_13b5b);
	flags.c() = (data.byte(k_byte_282e8) >> ax) & 1;
		_jnc(loc_13b5b);
	cx = data.word(k_word_245fa);
	_add(cx, 7);
	_shr(cx, 3);
		_jz(loc_13b34);
	di = 0;
loc_13b29:
	_cmp(data.byte(k_byte_282e8)[di], 0x0FF);
		_jnz(loc_13b3e);
	_inc(di);
	_dec(cx);
		_jnz(loc_13b29);
loc_13b34:
	_push(bx);
	_push(si);
	_push(es);
	_vlm_141df();
	_pop(es);
	_pop(si);
	_pop(bx);
	return;
loc_13b3e:
	al = data.byte(k_byte_282e8)[di];
	_shl(di, 3);
	cx = 8;
loc_13b48:
	_shr(al, 1);
		_jnc(loc_13b50);
	_inc(di);
	_dec(cx);
		_jnz(loc_13b48);
loc_13b50:
	_cmp(di, data.word(k_word_245fa));
		_jnc(loc_13b34);
	_dec(di);
	data.word(k_word_245f0) = di;
loc_13b5b:
	data.byte(k_byte_24669) = 0;
	data.byte(k_byte_2466a) = 1;
	return;
	return;
/*continuing to unbounded code: loc_13b29 from _eff_13b06:14-47*/
loc_13b29:
	_cmp(data.byte(k_byte_282e8)[di], 0x0FF);
		_jnz(loc_13b3e);
	_inc(di);
	_dec(cx);
		_jnz(loc_13b29);
loc_13b34:
	_push(bx);
	_push(si);
	_push(es);
	_vlm_141df();
	_pop(es);
	_pop(si);
	_pop(bx);
	return;
loc_13b3e:
	al = data.byte(k_byte_282e8)[di];
	_shl(di, 3);
	cx = 8;
loc_13b48:
	_shr(al, 1);
		_jnc(loc_13b50);
	_inc(di);
	_dec(cx);
		_jnz(loc_13b48);
loc_13b50:
	_cmp(di, data.word(k_word_245fa));
		_jnc(loc_13b34);
	_dec(di);
	data.word(k_word_245f0) = di;
loc_13b5b:
	data.byte(k_byte_24669) = 0;
	data.byte(k_byte_2466a) = 1;
	return;
loc_13b29:
}

void InertiaPlayerContext::_eff_13b78() {
	STACK_CHECK;
	_cmp(al, data.byte(k_byte_2467d));
		_jbe(loc_13b81);
	al = data.byte(k_byte_2467d);
loc_13b81:
	ds.byte(bx+8) = al;
	[off_245cc];
	return;
/*continuing to unbounded code: loc_13b81 from _eff_13b78:4-6*/
loc_13b81:
	ds.byte(bx+8) = al;
	[off_245cc];
loc_13b81:
}

void InertiaPlayerContext::_eff_13b88() {
	STACK_CHECK;
	dl = al;
	_and(dl, 0x0F);
	_shr(al, 4);
	ah = 0x0A;
	_mul(ah);
	_add(al, dl);
	_cmp(al, 0x3F);
		_ja(loc_13b5b);
	data.byte(k_byte_24669) = al;
	data.byte(k_byte_2466a) = 1;
	return;
	return;
/*continuing to unbounded code: loc_13b5b from _eff_13b06:44-47*/
loc_13b5b:
	data.byte(k_byte_24669) = 0;
	data.byte(k_byte_2466a) = 1;
	return;
}

void InertiaPlayerContext::_eff_13ba3() {
	STACK_CHECK;
	di = ax;
	_shr(di, 3);
	_and(di, 0x1E);
	_and(al, 0x0F);
	cs:_effoff_19026[di];
}

void InertiaPlayerContext::_eff_13bb2() {
	STACK_CHECK;
	_or(al, al);
		_jz(loc_13bbb);
	_or(ds.byte(bx+0x17), 0x20);
	return;
loc_13bbb:
	_and(ds.byte(bx+0x17), 0x0DF);
	return;
	return;
/*continuing to unbounded code: loc_13bbb from _eff_13bb2:5-7*/
loc_13bbb:
	_and(ds.byte(bx+0x17), 0x0DF);
	return;
loc_13bbb:
}

void InertiaPlayerContext::_eff_13bc0() {
	STACK_CHECK;
	_and(ds.byte(bx+9), 0x0F0);
	_or(ds.byte(bx+9), al);
	return;
}

void InertiaPlayerContext::_eff_13bc8() {
	STACK_CHECK;
	_and(ax, 0x0F);
	di = ax;
	_cmp(data.byte(k_byte_2461a), 0);
		_jnz(loc_13be7);
	_shl(di, 3);
	ax = di;
	_neg(ax);
	_shl(di, 4);
	_add(ax, di);
	_add(ax, 3863);
	ds.word(bx+0x38) = ax;
	return;
loc_13be7:
	_shl(di, 1);
	ax = data.word(k_table_246f6)[di];
	ds.word(bx+0x14) = dx;
	return;
	return;
/*continuing to unbounded code: loc_13be7 from _eff_13bc8:13-17*/
loc_13be7:
	_shl(di, 1);
	ax = data.word(k_table_246f6)[di];
	ds.word(bx+0x14) = dx;
	return;
loc_13be7:
}

void InertiaPlayerContext::_eff_13c02() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_24668), 0);
		_jnz(locret_13cf4);
	_or(al, al);
		_jz(loc_13c2d);
	_cmp(ds.byte(bx+0x3C), 0);
		_jnz(loc_13c1a);
	_inc(al);
	ds.byte(bx+0x3C) = al;
loc_13c1a:
	_dec(ds.byte(bx+0x3C));
		_jz(locret_13cf4);
	al = ds.byte(bx+0x3B);
	data.byte(k_byte_24669) = al;
	data.byte(k_byte_2466b) = 1;
	return;
loc_13c2d:
	ax = data.word(k_word_245f6);
	ds.byte(bx+0x3B) = al;
	return;
	return;
/*continuing to unbounded code: locret_13cf4 from _eff_13ce8:5-12*/
locret_13cf4:
	return;
	return;
	return;
}

void InertiaPlayerContext::_eff_13c34() {
	STACK_CHECK;
	_and(ds.byte(bx+9), 0x0F);
	_shl(al, 4);
	_or(ds.byte(bx+9), al);
	return;
}

void InertiaPlayerContext::_eff_13c3f() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_24668), 0);
		_jz(loc_13c47);
	return;
loc_13c47:
	di = ax;
	_and(di, 0x0F);
	al = data.byte(k_byte_13c54)[di];
	{ _eff_13A43(); return; };
	return;
/*continuing to unbounded code: loc_13c47 from _eff_13c3f:4-8*/
loc_13c47:
	di = ax;
	_and(di, 0x0F);
	al = data.byte(k_byte_13c54)[di];
	{ _eff_13A43(); return; };
loc_13c47:
}

void InertiaPlayerContext::_eff_13c64() {
	STACK_CHECK;
	_or(al, al);
		_jz(locret_13cf4);
	_cmp(data.byte(k_byte_24668), 0);
		_jnz(loc_13c77);
	_test(ds.byte(bx+0x3D), 8);
		_jnz(locret_13cf4);
loc_13c77:
	dl = al;
	ax = data.byte(k_byte_24668);
	_div(dl);
	_or(ah, ah);
		_jnz(locret_13cf4);
	[off_245c8];
	return;
/*continuing to unbounded code: locret_13cf4 from _eff_13ce8:5-12*/
locret_13cf4:
	return;
	return;
	return;
}

void InertiaPlayerContext::_eff_13c88() {
	STACK_CHECK;
	dl = ds.byte(bx+8);
	_cmp(data.byte(k_byte_24668), 0);
		_jz(loc_13af2);
	return;
	return;
/*continuing to unbounded code: loc_13af2 from _eff_13ad7:16-24*/
loc_13af2:
	_add(dl, al);
	al = dl;
	_cmp(al, data.byte(k_byte_2467d));
		_jbe(loc_13aff);
	al = data.byte(k_byte_2467d);
loc_13aff:
	ds.byte(bx+8) = al;
	[off_245cc];
}

void InertiaPlayerContext::_eff_13c95() {
	STACK_CHECK;
	dl = ds.byte(bx+8);
	_cmp(data.byte(k_byte_24668), 0);
		_jz(loc_13ae0);
	return;
	return;
/*continuing to unbounded code: loc_13ae0 from _eff_13ad7:6-24*/
loc_13ae0:
	_sub(dl, al);
	al = dl;
		_jnc(loc_13ae8);
	al = 0;
loc_13ae8:
	ds.byte(bx+8) = al;
	[off_245cc];
	_shr(al, 4);
	_add(dl, al);
	al = dl;
	_cmp(al, data.byte(k_byte_2467d));
		_jbe(loc_13aff);
	al = data.byte(k_byte_2467d);
loc_13aff:
	ds.byte(bx+8) = al;
	[off_245cc];
}

void InertiaPlayerContext::_eff_13ca2() {
	STACK_CHECK;
	_cmp(al, data.byte(k_byte_24668));
		_jnz(locret_13cf4);
	al = 0;
	[off_245cc];
	return;
/*continuing to unbounded code: locret_13cf4 from _eff_13ce8:5-12*/
locret_13cf4:
	return;
	return;
	return;
}

void InertiaPlayerContext::_eff_13cb3() {
	STACK_CHECK;
	_cmp(al, data.byte(k_byte_24668));
		_jnz(locret_13cf4);
	_cmp(ds.word(bx), 0);
		_jz(locret_13cf4);
	ds.byte(bx+0x0A) = 0;
	ds.byte(bx+0x0B) = 0;
	loc_13791;
	return;
/*continuing to unbounded code: locret_13cf4 from _eff_13ce8:5-12*/
locret_13cf4:
	return;
	return;
	return;
}

void InertiaPlayerContext::_eff_13cc9() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_24668), 0);
		_jnz(locret_13cf4);
	_cmp(data.byte(k_byte_2466d), 0);
		_jnz(locret_13cf4);
	_inc(al);
	data.byte(k_byte_2466c) = al;
	return;
	return;
/*continuing to unbounded code: locret_13cf4 from _eff_13ce8:5-12*/
locret_13cf4:
	return;
	return;
	return;
}

void InertiaPlayerContext::_eff_13cdd() {
	STACK_CHECK;
	_test(data.byte(k_flag_playsetttings), 2);
		_jnz({ _eff_13CE8(); return; });
	_cmp(al, 0x20);
		_ja({ sub_13CF6(); return; });
}

void InertiaPlayerContext::_eff_13ce8() {
	STACK_CHECK;
	_or(al, al);
		_jz(locret_13cf5);
	data.byte(k_byte_24667) = al;
	data.byte(k_byte_24668) = 0;
	return;
locret_13cf5:
	return;
	return;
/*continuing to unbounded code: locret_13cf5 from _eff_13ce8:7-8*/
locret_13cf5:
	return;
locret_13cf5:
}

	_pop(flags);
	return;
loc_13d36:
}

void InertiaPlayerContext::sub_13d95() {
	STACK_CHECK;
	data.byte(k_byte_24618) = 1;
	dx = 0;
	ax = 31250;
	_div(cx);
	_neg(al);
	_or(ah, ah);
		_jnz(loc_13d8d);
	ah = data.byte(k_byte_24618);
	data.byte(k_byte_24619) = ah;
	return;
}

	_pop(flags);
	return;
}

	_pop(flags);
	return;
}

void InertiaPlayerContext::_eff_13de5() {
	STACK_CHECK;
	sub_14087();
	_or(ax, ax);
		_jnz(loc_1388b);
	return;
	return;
/*continuing to unbounded code: loc_1388b from _eff_13886:3-10*/
loc_1388b:
	_sub(ds.word(bx), ax);
	_cmp(ds.word(bx), 0x0A0);
		_jge(loc_13897);
	ds.word(bx) = 0x0A0;
loc_13897:
	ax = ds.word(bx);
	[off_245ca];
}

void InertiaPlayerContext::_eff_13def() {
	STACK_CHECK;
	sub_14087();
	_or(ax, ax);
		_jnz(loc_138a9);
	return;
	return;
/*continuing to unbounded code: loc_138a9 from _eff_138a4:3-12*/
loc_138a9:
	_add(ds.word(bx), ax);
		_jc(loc_138b3);
	_cmp(ds.word(bx), 13696);
		_jbe(loc_138b7);
loc_138b3:
	ds.word(bx) = 13696;
loc_138b7:
	ax = ds.word(bx);
	[off_245ca];
}

void InertiaPlayerContext::_eff_13e1e() {
	STACK_CHECK;
	_or(al, al);
		_jz(loc_13e2a);
	ah = 0;
	_shl(ax, 2);
	ds.word(bx+0x12) = ax;
loc_13e2a:
	loc_138de;
	return;
/*continuing to unbounded code: loc_13e2a from _eff_13e1e:6-7*/
loc_13e2a:
	loc_138de;
loc_13e2a:
}

void InertiaPlayerContext::_eff_13e2d() {
	STACK_CHECK;
	cl = 5;
	loc_13931;
	return;
/*continuing to unbounded code: loc_13931 from _eff_1392f:2-57*/
loc_13931:
	_or(al, al);
		_jz(loc_13950);
	ch = al;
	dl = ds.byte(bx+0x0C);
	_and(al, 0x0F);
		_jz(loc_13943);
	_and(dl, 0x0F0);
	_or(dl, al);
loc_13943:
	_and(ch, 0x0F0);
		_jz(loc_1394d);
	_and(dl, 0x0F);
	_or(dl, ch);
loc_1394d:
	ds.byte(bx+0x0C) = dl;
loc_13950:
	al = ds.byte(bx+0x0D);
	_shr(al, 2);
	_and(ax, 0x1F);
	dl = ds.byte(bx+9);
	_and(dl, 3);
		_jz(loc_1397b);
	_shl(al, 3);
	_cmp(dl, 1);
		_jz(loc_1396d);
	dl = 0x0FF;
	loc_13981;
loc_1396d:
	dl = al;
	_test(ds.byte(bx+0x0D), 0x80);
		_jz(loc_13981);
	dl = 0x0FF;
	_sub(dl, al);
	loc_13981;
loc_1397b:
	di = ax;
	dl = data.byte(k_table_251c0)[di];
loc_13981:
	al = ds.byte(bx+0x0C);
	dh = al;
	_and(al, 0x0F);
	_mul(dl);
	ch = data.byte(k_flag_playsetttings);
	_and(ch, 1);
	_add(cl, ch);
	_shr(ax, cl);
	_test(ds.byte(bx+0x0D), 0x80);
		_jz(loc_1399d);
	_neg(ax);
loc_1399d:
	_add(ax, ds.word(bx));
	_shr(dh, 2);
	_and(dh, 0x3C);
	_add(ds.byte(bx+0x0D), dh);
	[off_245ca];
}

void InertiaPlayerContext::_eff_13e32() {
	STACK_CHECK;
	_or(al, al);
		_jz(loc_13e39);
	ds.byte(bx+0x34) = al;
loc_13e39:
	al = ds.byte(bx+0x34);
	dl = ds.byte(bx+8);
	cl = al;
	_and(cl, 0x0F);
	ch = al;
	_shr(ch, 4);
	_cmp(cl, 0x0F);
		_jnz(loc_13e5e);
	_or(ch, ch);
		_jz(loc_13ade);
	_cmp(data.byte(k_byte_24668), 0);
		_jz(loc_13aef);
	return;
loc_13e5e:
	_cmp(ch, 0x0F);
		_jz(loc_13e6f);
	dl = ds.byte(bx+8);
	_test(al, 0x0F);
		_jnz(loc_13ade);
	loc_13aef;
loc_13e6f:
	_or(cl, cl);
		_jz(loc_13aef);
	_cmp(data.byte(k_byte_24668), 0);
		_jz(loc_13ade);
	return;
	return;
/*continuing to unbounded code: loc_13e39 from _eff_13e32:4-30*/
loc_13e39:
	al = ds.byte(bx+0x34);
	dl = ds.byte(bx+8);
	cl = al;
	_and(cl, 0x0F);
	ch = al;
	_shr(ch, 4);
	_cmp(cl, 0x0F);
		_jnz(loc_13e5e);
	_or(ch, ch);
		_jz(loc_13ade);
	_cmp(data.byte(k_byte_24668), 0);
		_jz(loc_13aef);
	return;
loc_13e5e:
	_cmp(ch, 0x0F);
		_jz(loc_13e6f);
	dl = ds.byte(bx+8);
	_test(al, 0x0F);
		_jnz(loc_13ade);
	loc_13aef;
loc_13e6f:
	_or(cl, cl);
		_jz(loc_13aef);
	_cmp(data.byte(k_byte_24668), 0);
		_jz(loc_13ade);
	return;
loc_13e39:
}

void InertiaPlayerContext::_eff_13e7f() {
	STACK_CHECK;
	_eff_13e32();
	loc_13e2a;
	return;
/*continuing to unbounded code: loc_13e2a from _eff_13e1e:6-7*/
loc_13e2a:
	loc_138de;
}

void InertiaPlayerContext::_eff_13e84() {
	STACK_CHECK;
	_eff_13e32();
	cl = 5;
	loc_13950;
	return;
/*continuing to unbounded code: loc_13950 from _eff_1392f:18-57*/
loc_13950:
	al = ds.byte(bx+0x0D);
	_shr(al, 2);
	_and(ax, 0x1F);
	dl = ds.byte(bx+9);
	_and(dl, 3);
		_jz(loc_1397b);
	_shl(al, 3);
	_cmp(dl, 1);
		_jz(loc_1396d);
	dl = 0x0FF;
	loc_13981;
loc_1396d:
	dl = al;
	_test(ds.byte(bx+0x0D), 0x80);
		_jz(loc_13981);
	dl = 0x0FF;
	_sub(dl, al);
	loc_13981;
loc_1397b:
	di = ax;
	dl = data.byte(k_table_251c0)[di];
loc_13981:
	al = ds.byte(bx+0x0C);
	dh = al;
	_and(al, 0x0F);
	_mul(dl);
	ch = data.byte(k_flag_playsetttings);
	_and(ch, 1);
	_add(cl, ch);
	_shr(ax, cl);
	_test(ds.byte(bx+0x0D), 0x80);
		_jz(loc_1399d);
	_neg(ax);
loc_1399d:
	_add(ax, ds.word(bx));
	_shr(dh, 2);
	_and(dh, 0x3C);
	_add(ds.byte(bx+0x0D), dh);
	[off_245ca];
}

void InertiaPlayerContext::_eff_13e8c() {
	STACK_CHECK;
	sub_13e9b();
	data.byte(k_byte_24667) = ah;
	data.byte(k_byte_24668) = 0;
	{ sub_13CF6(); return; };
}

void InertiaPlayerContext::sub_13e9b() {
	STACK_CHECK;
	di = al;
	dx = di;
	_and(dl, 0x0F);
	_shr(di, 4);
	ax = dx;
	_mul(data.byte(k_table_13ec3)[di]);
	_shr(ax, 4);
	_neg(ax);
	_add(ax, 0x31);
	dx = ax;
	_shl(ax, 2);
	_add(ax, dx);
	_shr(ax, 1);
	dx = di;
	ah = dl;
	return;
}

void InertiaPlayerContext::_nullsub_2() {
	STACK_CHECK;
	return;
}

void InertiaPlayerContext::_eff_13f05() {
	STACK_CHECK;
	_or(al, al);
		_jz(loc_13f0c);
	ds.byte(bx+0x34) = al;
loc_13f0c:
	al = ds.byte(bx+0x34);
	dl = al;
	_shr(dl, 4);
	_and(al, 0x0F);
	dh = al;
	_and(ax, 0x0F);
	_add(al, dl);
		_jz(locret_13cf4);
	cl = al;
	ax = data.byte(k_byte_24668);
	_div(cl);
	_cmp(ah, dl);
		_jc(loc_13f34);
	al = 0;
	[off_245cc];
loc_13f34:
	al = ds.byte(bx+8);
	[off_245cc];
	return;
/*continuing to unbounded code: loc_13f0c from _eff_13f05:4-22*/
loc_13f0c:
	al = ds.byte(bx+0x34);
	dl = al;
	_shr(dl, 4);
	_and(al, 0x0F);
	dh = al;
	_and(ax, 0x0F);
	_add(al, dl);
		_jz(locret_13cf4);
	cl = al;
	ax = data.byte(k_byte_24668);
	_div(cl);
	_cmp(ah, dl);
		_jc(loc_13f34);
	al = 0;
	[off_245cc];
loc_13f34:
	al = ds.byte(bx+8);
	[off_245cc];
loc_13f0c:
}

void InertiaPlayerContext::_eff_13f3b() {
	STACK_CHECK;
	_or(al, al);
		_jz(loc_13f42);
	ds.byte(bx+0x34) = al;
loc_13f42:
	al = ds.byte(bx+0x34);
	ch = al;
	_shr(al, 4);
	_test(al, 7);
		_jz(loc_13fb7);
	_test(al, 8);
		_jnz(loc_13f96);
	_cmp(al, 6);
		_jz(loc_13f6d);
	_cmp(al, 7);
		_jz(loc_13f7c);
	_dec(al);
	cl = al;
	al = 1;
	_shl(al, cl);
	_sub(ds.byte(bx+8), al);
		_jnc(loc_13fb7);
	ds.byte(bx+8) = 0;
	loc_13fb7;
loc_13f6d:
	ax = ds.byte(bx+8);
	_shl(ax, 1);
	dl = 3;
	_div(dl);
	ds.byte(bx+8) = al;
	loc_13fb7;
loc_13f7c:
	_shr(ds.byte(bx+8), 1);
	loc_13fb7;
loc_13f81:
	ax = ds.byte(bx+8);
	dx = ax;
	_add(ax, dx);
	_add(ax, dx);
	_shr(ax, 1);
	loc_13fab;
loc_13f8f:
	al = ds.byte(bx+8);
	_add(al, al);
	loc_13fab;
loc_13f96:
	_and(al, 7);
	_cmp(al, 6);
		_jz(loc_13f81);
	_cmp(al, 7);
		_jz(loc_13f8f);
	_dec(al);
	cl = al;
	al = 1;
	_shl(al, cl);
	_add(al, ds.byte(bx+8));
loc_13fab:
	_cmp(al, data.byte(k_byte_2467d));
		_jbe(loc_13fb4);
	al = data.byte(k_byte_2467d);
loc_13fb4:
	ds.byte(bx+8) = al;
loc_13fb7:
	al = ch;
	_and(al, 0x0F);
	{ _eff_13C64(); return; };
	return;
/*continuing to unbounded code: loc_13f42 from _eff_13f3b:4-65*/
loc_13f42:
	al = ds.byte(bx+0x34);
	ch = al;
	_shr(al, 4);
	_test(al, 7);
		_jz(loc_13fb7);
	_test(al, 8);
		_jnz(loc_13f96);
	_cmp(al, 6);
		_jz(loc_13f6d);
	_cmp(al, 7);
		_jz(loc_13f7c);
	_dec(al);
	cl = al;
	al = 1;
	_shl(al, cl);
	_sub(ds.byte(bx+8), al);
		_jnc(loc_13fb7);
	ds.byte(bx+8) = 0;
	loc_13fb7;
loc_13f6d:
	ax = ds.byte(bx+8);
	_shl(ax, 1);
	dl = 3;
	_div(dl);
	ds.byte(bx+8) = al;
	loc_13fb7;
loc_13f7c:
	_shr(ds.byte(bx+8), 1);
	loc_13fb7;
loc_13f81:
	ax = ds.byte(bx+8);
	dx = ax;
	_add(ax, dx);
	_add(ax, dx);
	_shr(ax, 1);
	loc_13fab;
loc_13f8f:
	al = ds.byte(bx+8);
	_add(al, al);
	loc_13fab;
loc_13f96:
	_and(al, 7);
	_cmp(al, 6);
		_jz(loc_13f81);
	_cmp(al, 7);
		_jz(loc_13f8f);
	_dec(al);
	cl = al;
	al = 1;
	_shl(al, cl);
	_add(al, ds.byte(bx+8));
loc_13fab:
	_cmp(al, data.byte(k_byte_2467d));
		_jbe(loc_13fb4);
	al = data.byte(k_byte_2467d);
loc_13fb4:
	ds.byte(bx+8) = al;
loc_13fb7:
	al = ch;
	_and(al, 0x0F);
	{ _eff_13C64(); return; };
loc_13f42:
}

void InertiaPlayerContext::_eff_13fbe() {
	STACK_CHECK;
	_or(al, al);
		_jnz(loc_13fce);
	al = ds.byte(bx+0x34);
	_or(al, al);
		_jz(locret_13cf4);
	ds.byte(bx+0x0B) = al;
loc_13fce:
	ds.byte(bx+0x34) = al;
	al = ds.byte(bx+0x35);
	dl = al;
	_and(dl, 0x0F);
		_jz(locret_13cf4);
	_dec(dl);
	_shr(al, 4);
	ah = 0x0C;
	_mul(ah);
	_add(dl, al);
	ax = data.byte(k_byte_24668);
	dh = 3;
	_div(dh);
	_or(ah, ah);
		_jz(loc_1401a);
	dh = ds.byte(bx+0x0B);
	_cmp(ah, 2);
		_jz(loc_14000);
	_shr(dh, 4);
loc_14000:
	_and(dh, 0x0F);
	_add(dl, dh);
	ax = dl;
	dh = 0x0C;
	_div(dh);
	_inc(ah);
	_shl(al, 4);
	_or(al, ah);
	sub_13826();
	[off_245ca];
loc_1401a:
	ax = ds.word(bx);
	[off_245ca];
	return;
/*continuing to unbounded code: loc_13fce from _eff_13fbe:7-40*/
loc_13fce:
	ds.byte(bx+0x34) = al;
	al = ds.byte(bx+0x35);
	dl = al;
	_and(dl, 0x0F);
		_jz(locret_13cf4);
	_dec(dl);
	_shr(al, 4);
	ah = 0x0C;
	_mul(ah);
	_add(dl, al);
	ax = data.byte(k_byte_24668);
	dh = 3;
	_div(dh);
	_or(ah, ah);
		_jz(loc_1401a);
	dh = ds.byte(bx+0x0B);
	_cmp(ah, 2);
		_jz(loc_14000);
	_shr(dh, 4);
loc_14000:
	_and(dh, 0x0F);
	_add(dl, dh);
	ax = dl;
	dh = 0x0C;
	_div(dh);
	_inc(ah);
	_shl(al, 4);
	_or(al, ah);
	sub_13826();
	[off_245ca];
loc_1401a:
	ax = ds.word(bx);
	[off_245ca];
loc_13fce:
}

void InertiaPlayerContext::_eff_14020() {
	STACK_CHECK;
	ah = 0;
	_shl(ax, 2);
	_push(bx);
	_push(si);
	_push(es);
	_change_amplif();
	_pop(es);
	_pop(si);
	_pop(bx);
	return;
}

void InertiaPlayerContext::_eff_14030() {
	STACK_CHECK;
	_and(ax, 0x0F);
	di = ax;
	al = data.byte(k_table_14057)[di];
	data.byte(k_byte_2467b) = al;
	_calc_14043();
	{ sub_13CF6(); return; };
}

void InertiaPlayerContext::_calc_14043() {
	STACK_CHECK;
	al = data.byte(k_byte_2467b);
	_add(al, data.byte(k_byte_2467c));
	_and(eax, 0x0FF);
	ax = ds.word(eax+eax*4);
	_shr(ax, 1);
	return;
}

void InertiaPlayerContext::_eff_14067() {
	STACK_CHECK;
	_or(al, al);
		_jz(loc_14080);
	_test(al, 0x0F);
		_jz(loc_14077);
	_and(al, 0x0F);
	_sub(data.byte(k_byte_2467c), al);
	loc_1403d;
loc_14077:
	_shr(al, 4);
	_add(data.byte(k_byte_2467c), al);
	loc_1403d;
loc_14080:
	data.byte(k_byte_2467c) = 0;
	loc_1403d;
	return;
/*continuing to unbounded code: loc_1403d from _eff_14030:5-7*/
loc_1403d:
	_calc_14043();
	{ sub_13CF6(); return; };
}

void InertiaPlayerContext::sub_14087() {
	STACK_CHECK;
	ah = 0;
	_or(al, al);
		_jz(loc_14090);
	ds.byte(bx+0x34) = al;
loc_14090:
	al = ds.byte(bx+0x34);
	_cmp(data.byte(k_byte_24668), 0);
		_jz(loc_140a2);
	_cmp(al, 0x0E0);
		_jnc(loc_140b3);
	_shl(ax, 2);
	return;
loc_140a2:
	_cmp(al, 0x0E0);
		_jbe(loc_140b3);
	dl = al;
	_and(al, 0x0F);
	_cmp(dl, 0x0F0);
		_jbe(locret_140b2);
	_shl(ax, 2);
locret_140b2:
	return;
loc_140b3:
	ax = 0;
	return;
	return;
/*continuing to unbounded code: loc_140a2 from sub_14087:13-25*/
loc_140a2:
	_cmp(al, 0x0E0);
		_jbe(loc_140b3);
	dl = al;
	_and(al, 0x0F);
	_cmp(dl, 0x0F0);
		_jbe(locret_140b2);
	_shl(ax, 2);
locret_140b2:
	return;
loc_140b3:
	ax = 0;
	return;
loc_140a2:
}

void InertiaPlayerContext::sub_140b6() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_24671), 1);
		_jz(locret_140e5);
	_cmp(data.byte(k_play_state), 1);
		_jz(locret_140e5);
	_inc(data.byte(k_byte_24668));
	al = data.byte(k_byte_24668);
	_cmp(al, data.byte(k_byte_24667));
		_jnc(loc_140e6);
	bx = 6884;
	cx = data.word(k_word_245d4);
loc_140d8:
	_push(bx);
	_push(cx);
	sub_13813();
	_pop(cx);
	_pop(bx);
	_add(bx, 0x50);
	_dec(cx);
		_jnz(loc_140d8);
locret_140e5:
	return;
loc_140e6:
	data.byte(k_byte_24668) = 0;
	_cmp(data.byte(k_byte_2466d), 0);
		_jnz(loc_140f7);
	sub_135ca();
	loc_14111;
loc_140f7:
	bx = 6884;
	cx = data.word(k_word_245d4);
loc_140fe:
	_push(bx);
	_push(cx);
	sub_13813();
	_pop(cx);
	_pop(bx);
	_add(bx, 0x50);
	_dec(cx);
		_jnz(loc_140fe);
	si = data.dword(k_pointer_245b4);
	$+2;
loc_14111:
	_cmp(data.byte(k_byte_2466b), 1);
		_jz(loc_141ba);
	_cmp(data.byte(k_byte_2466a), 1);
		_jz(loc_14153);
	_cmp(data.byte(k_byte_2466c), 0);
		_jz(loc_14131);
	al = 0;
	_xchg(al, data.byte(k_byte_2466c));
	data.byte(k_byte_2466d) = al;
loc_14131:
	_cmp(data.byte(k_byte_2466d), 0);
		_jz(loc_1413e);
	_dec(data.byte(k_byte_2466d));
		_jnz(loc_14142);
loc_1413e:
	_inc(data.word(k_word_245f6));
loc_14142:
	bx = data.word(k_word_245f0);
	ax = data.byte(k_byte_281e8)[bx];
	_cmp(data.word(k_word_245f6), ax);
		_jbe(loc_141da);
loc_14153:
	_cmp(data.byte(k_play_state), 2);
		_jz(loc_14184);
	_inc(data.word(k_word_245f0));
	return;
/*continuing to unbounded code: loc_140d8 from sub_140b6:11-67*/
loc_140d8:
	_push(bx);
	_push(cx);
	sub_13813();
	_pop(cx);
	_pop(bx);
	_add(bx, 0x50);
	_dec(cx);
		_jnz(loc_140d8);
locret_140e5:
	return;
loc_140e6:
	data.byte(k_byte_24668) = 0;
	_cmp(data.byte(k_byte_2466d), 0);
		_jnz(loc_140f7);
	sub_135ca();
	loc_14111;
loc_140f7:
	bx = 6884;
	cx = data.word(k_word_245d4);
loc_140fe:
	_push(bx);
	_push(cx);
	sub_13813();
	_pop(cx);
	_pop(bx);
	_add(bx, 0x50);
	_dec(cx);
		_jnz(loc_140fe);
	si = data.dword(k_pointer_245b4);
	$+2;
loc_14111:
	_cmp(data.byte(k_byte_2466b), 1);
		_jz(loc_141ba);
	_cmp(data.byte(k_byte_2466a), 1);
		_jz(loc_14153);
	_cmp(data.byte(k_byte_2466c), 0);
		_jz(loc_14131);
	al = 0;
	_xchg(al, data.byte(k_byte_2466c));
	data.byte(k_byte_2466d) = al;
loc_14131:
	_cmp(data.byte(k_byte_2466d), 0);
		_jz(loc_1413e);
	_dec(data.byte(k_byte_2466d));
		_jnz(loc_14142);
loc_1413e:
	_inc(data.word(k_word_245f6));
loc_14142:
	bx = data.word(k_word_245f0);
	ax = data.byte(k_byte_281e8)[bx];
	_cmp(data.word(k_word_245f6), ax);
		_jbe(loc_141da);
loc_14153:
	_cmp(data.byte(k_play_state), 2);
		_jz(loc_14184);
	_inc(data.word(k_word_245f0));
loc_140d8:
}

void InertiaPlayerContext::sub_1415e() {
	STACK_CHECK;
	ax = data.word(k_word_245fa);
	_cmp(data.word(k_word_245f0), ax);
		_jc(loc_14184);
	_test(data.byte(k_flag_playsetttings), 4);
		_jz({ _vlm_141DF(); return; });
	ax = data.word(k_word_245f8);
	data.word(k_word_245f0) = ax;
	_or(ax, ax);
		_jnz(loc_14184);
	al = data.byte(k_byte_2467a);
	sub_13cf6();
	al = data.byte(k_byte_24679);
	_eff_13ce8();
loc_14184:
	bx = data.word(k_word_245f0);
	al = data.byte(k_byte_280e8)[bx];
	_or(al, al);
		_jz(loc_141a2);
	_push(bx);
	_cmp(al, 0x0FF);
		_jnz(loc_1419e);
	al = data.byte(k_byte_2467a);
	sub_13cf6();
	al = data.byte(k_byte_24679);
loc_1419e:
	_eff_13ce8();
	_pop(bx);
loc_141a2:
	flags.c() = (data.byte(k_byte_282e8) >> bx) & 1; data.byte(k_byte_282e8) |= 1 << bx;
	bx = data.byte(k_byte_27fe8)[bx];
	data.word(k_my_seg_index) = bx;
	_shl(bx, 1);
	es = data.word(k_segs_table)[bx];
	data.dword(k_pointer_245b4)[2] = es;
	ax = 0;
	_xchg(al, data.byte(k_byte_24669));
	data.word(k_word_245f6) = ax;
	sub_11c0c();
	data.byte(k_byte_2466a) = 0;
	data.byte(k_byte_2466b) = 0;
	data.byte(k_byte_2466c) = 0;
	data.byte(k_byte_2466d) = 0;
	data.dword(k_pointer_245b4) = si;
	return;
	return;
/*continuing to unbounded code: loc_1419e from sub_1415e:25-46*/
loc_1419e:
	_eff_13ce8();
	_pop(bx);
loc_141a2:
	flags.c() = (data.byte(k_byte_282e8) >> bx) & 1; data.byte(k_byte_282e8) |= 1 << bx;
	bx = data.byte(k_byte_27fe8)[bx];
	data.word(k_my_seg_index) = bx;
	_shl(bx, 1);
	es = data.word(k_segs_table)[bx];
	data.dword(k_pointer_245b4)[2] = es;
	ax = 0;
	_xchg(al, data.byte(k_byte_24669));
	data.word(k_word_245f6) = ax;
	sub_11c0c();
	data.byte(k_byte_2466a) = 0;
	data.byte(k_byte_2466b) = 0;
	data.byte(k_byte_2466c) = 0;
	data.byte(k_byte_2466d) = 0;
	data.dword(k_pointer_245b4) = si;
	return;
loc_1419e:
}

void InertiaPlayerContext::_vlm_141df() {
	STACK_CHECK;
	_volume_12a66();
	data.byte(k_byte_24671) = 1;
	dl = 1;
	bx = 0x5344;
	cx = 0x4D50;
	ax = 0x60FF;
	// _int(0x2F);
	return;
}

void InertiaPlayerContext::_snd_initialze() {
	STACK_CHECK;
	_cmp(data.byte(k_snd_init), 1);
		_jz(loc_1420d);
	data.byte(k_snd_init) = 1;
	bx = data.byte(k_sndcard_type);
	_shl(bx, 1);
	{ _sb16_init(); return; };
loc_1420d:
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_1420d from _snd_initialze:7-9*/
loc_1420d:
	_write_cf(true);
 	return;
loc_1420d:
}

void InertiaPlayerContext::_snd_on() {
	STACK_CHECK;
	_cmp(data.byte(k_snd_init), 1);
		_jnz(loc_1420d);
	_cmp(data.byte(k_snd_set_flag), 1);
		_jz(loc_1420d);
	data.byte(k_snd_set_flag) = 1;
	bx = data.byte(k_sndcard_type);
	_shl(bx, 1);
	{ _sb16_on(); return; };
	return;
/*continuing to unbounded code: loc_1420d from _snd_initialze:7-9*/
loc_1420d:
	_write_cf(true);
 	return;
}

void InertiaPlayerContext::_snd_off() {
	STACK_CHECK;
	_cmp(data.byte(k_snd_init), 1);
		_jnz(loc_1420d);
	_cmp(data.byte(k_snd_set_flag), 0);
		_jz(loc_1420d);
	data.byte(k_snd_set_flag) = 0;
	_volume_12a66();
	bx = data.byte(k_sndcard_type);
	_shl(bx, 1);
	{ _sb16_off(); return; };
	return;
/*continuing to unbounded code: loc_1420d from _snd_initialze:7-9*/
loc_1420d:
	_write_cf(true);
 	return;
}

void InertiaPlayerContext::_snd_deinit() {
	STACK_CHECK;
	_cmp(data.byte(k_snd_init), 1);
		_jnz(loc_1420d);
	data.byte(k_snd_init) = 0;
	_snd_off();
	bx = data.byte(k_sndcard_type);
	_shl(bx, 1);
	{ _sb16_deinit(); return; };
	return;
/*continuing to unbounded code: loc_1420d from _snd_initialze:7-9*/
loc_1420d:
	_write_cf(true);
 	return;
}

void InertiaPlayerContext::_sb16_init() {
	STACK_CHECK;
	data.byte(k_sndflags_24622) = 9;
	data.byte(k_byte_24623) = 1;
	data.byte(k_bit_mode) = 16;
	_sb16_detect_port();
	dx = 6441;
		_jc(loc_14332);
	al = data.byte(k_irq_number);
	data.byte(k_sb_irq_number) = al;
	_cmp(al, 0x0FF);
		_jnz(loc_14abb);
	ah = 0x80;
	_readmixersb();
	_cmp(al, 0x0FF);
		_jz(loc_14abb);
	ah = 2;
	_shr(al, 1);
		_jc(loc_14ab3);
	ah = 5;
	_shr(al, 1);
		_jc(loc_14ab3);
	ah = 7;
	_shr(al, 1);
		_jc(loc_14ab3);
	ah = 0x0A;
loc_14ab3:
	data.byte(k_sb_irq_number) = ah;
	data.byte(k_irq_number) = ah;
loc_14abb:
	al = data.byte(k_dma_channel);
	data.byte(k_dma_chn_mask) = al;
	_cmp(al, 0x0FF);
		_jnz(loc_14afd);
	ah = 0x81;
	_readmixersb();
	_cmp(al, 0x0FF);
		_jz(loc_14afd);
	_cmp(data.byte(k_bit_mode), 8);
		_jz(loc_14ae7);
	ah = 7;
	_test(al, 0x80);
		_jnz(loc_14af5);
	ah = 6;
	_test(al, 0x40);
		_jnz(loc_14af5);
	ah = 5;
	_test(al, 0x20);
		_jnz(loc_14af5);
loc_14ae7:
	ah = 3;
	_test(al, 4);
		_jnz(loc_14af5);
	ah = 1;
	_test(al, 2);
		_jnz(loc_14af5);
	ah = 0;
loc_14af5:
	data.byte(k_dma_chn_mask) = ah;
	data.byte(k_dma_channel) = ah;
loc_14afd:
	_sb16_sound_on();
	eax = 0x1000;
	cl = data.byte(k_dma_chn_mask);
	_alloc_dma_buf();
	data.dword(k_dma_buf_pointer) = 0;
	data.dword(k_dma_buf_pointer)[2] = ax;
	_write_cf(false);
 	return;
	return;
/*continuing to unbounded code: loc_14ab3 from _sb16_init:25-67*/
loc_14ab3:
	data.byte(k_sb_irq_number) = ah;
	data.byte(k_irq_number) = ah;
loc_14abb:
	al = data.byte(k_dma_channel);
	data.byte(k_dma_chn_mask) = al;
	_cmp(al, 0x0FF);
		_jnz(loc_14afd);
	ah = 0x81;
	_readmixersb();
	_cmp(al, 0x0FF);
		_jz(loc_14afd);
	_cmp(data.byte(k_bit_mode), 8);
		_jz(loc_14ae7);
	ah = 7;
	_test(al, 0x80);
		_jnz(loc_14af5);
	ah = 6;
	_test(al, 0x40);
		_jnz(loc_14af5);
	ah = 5;
	_test(al, 0x20);
		_jnz(loc_14af5);
loc_14ae7:
	ah = 3;
	_test(al, 4);
		_jnz(loc_14af5);
	ah = 1;
	_test(al, 2);
		_jnz(loc_14af5);
	ah = 0;
loc_14af5:
	data.byte(k_dma_chn_mask) = ah;
	data.byte(k_dma_channel) = ah;
loc_14afd:
	_sb16_sound_on();
	eax = 0x1000;
	cl = data.byte(k_dma_chn_mask);
	_alloc_dma_buf();
	data.dword(k_dma_buf_pointer) = 0;
	data.dword(k_dma_buf_pointer)[2] = ax;
	_write_cf(false);
 	return;
loc_14ab3:
}

void InertiaPlayerContext::_sb16_on() {
	STACK_CHECK;
	sub_13017();
	data.byte(k_dma_mode) = 0x58;
	data.word(k_word_2460e) = 0x1000;
	si = &;
	al = data.byte(k_sb_irq_number);
	_setsnd_handler();
	dx = data.word(k_sb_base_port);
	_add(dl, 0x0C);
loc_14b36:
	// _in(al, dx);
	_or(al, al);
		_js(loc_14b36);
	al = 0x41;
	// _out(dx, al);
loc_14b3e:
	// _in(al, dx);
	_or(al, al);
		_js(loc_14b3e);
	al = data.word(k_freq1)[1];
	// _out(dx, al);
loc_14b47:
	// _in(al, dx);
	_or(al, al);
		_js(loc_14b47);
	al = data.word(k_freq1);
	// _out(dx, al);
loc_14b50:
	// _in(al, dx);
	_or(al, al);
		_js(loc_14b50);
	_cmp(data.byte(k_bit_mode), 16);
		_jz(loc_14b6a);
	ax = data.word(k_sb_base_port);
	_add(al, 0x0E);
	data.word(k_word_14bbb) = ax;
	ax = 0x0C6;
	loc_14b76;
loc_14b6a:
	ax = data.word(k_sb_base_port);
	_add(al, 0x0F);
	data.word(k_word_14bbb) = ax;
	ax = 0x10B6;
loc_14b76:
	// _out(dx, al);
loc_14b77:
	// _in(al, dx);
	_or(al, al);
		_js(loc_14b77);
	al = data.byte(k_byte_24623);
	_and(al, 1);
	_shl(al, 5);
	_or(al, ah);
	// _out(dx, al);
loc_14b87:
	// _in(al, dx);
	_or(al, al);
		_js(loc_14b87);
	ax = data.word(k_word_2460e);
	_shr(ax, 2);
	cl = data.byte(k_bit_mode);
	_shr(cl, 4);
	_and(cl, 1);
	_shr(ax, cl);
	_dec(ax);
	// _out(dx, al);
loc_14ba0:
	// _in(al, dx);
	_or(al, al);
		_js(loc_14ba0);
	al = ah;
	// _out(dx, al);
	cl = data.byte(k_dma_chn_mask);
	_dma_186e3();
	data.byte(k_byte_2466e) = 1;
	return;
	return;
/*continuing to unbounded code: loc_14b36 from _sb16_on:9-75*/
loc_14b36:
	// _in(al, dx);
	_or(al, al);
		_js(loc_14b36);
	al = 0x41;
	// _out(dx, al);
loc_14b3e:
	// _in(al, dx);
	_or(al, al);
		_js(loc_14b3e);
	al = data.word(k_freq1)[1];
	// _out(dx, al);
loc_14b47:
	// _in(al, dx);
	_or(al, al);
		_js(loc_14b47);
	al = data.word(k_freq1);
	// _out(dx, al);
loc_14b50:
	// _in(al, dx);
	_or(al, al);
		_js(loc_14b50);
	_cmp(data.byte(k_bit_mode), 16);
		_jz(loc_14b6a);
	ax = data.word(k_sb_base_port);
	_add(al, 0x0E);
	data.word(k_word_14bbb) = ax;
	ax = 0x0C6;
	loc_14b76;
loc_14b6a:
	ax = data.word(k_sb_base_port);
	_add(al, 0x0F);
	data.word(k_word_14bbb) = ax;
	ax = 0x10B6;
loc_14b76:
	// _out(dx, al);
loc_14b77:
	// _in(al, dx);
	_or(al, al);
		_js(loc_14b77);
	al = data.byte(k_byte_24623);
	_and(al, 1);
	_shl(al, 5);
	_or(al, ah);
	// _out(dx, al);
loc_14b87:
	// _in(al, dx);
	_or(al, al);
		_js(loc_14b87);
	ax = data.word(k_word_2460e);
	_shr(ax, 2);
	cl = data.byte(k_bit_mode);
	_shr(cl, 4);
	_and(cl, 1);
	_shr(ax, cl);
	_dec(ax);
	// _out(dx, al);
loc_14ba0:
	// _in(al, dx);
	_or(al, al);
		_js(loc_14ba0);
	al = ah;
	// _out(dx, al);
	cl = data.byte(k_dma_chn_mask);
	_dma_186e3();
	data.byte(k_byte_2466e) = 1;
	return;
loc_14b36:
}

	_pop(flags);
	return;
loc_14bd8:
}

void InertiaPlayerContext::_sb16_deinit() {
	STACK_CHECK;
	_memfree_18a28();
	_sb16_sound_off();
	return;
}

	_popad();
	return;
loc_14f3c:
	data.word(k_word_14f6c) = 1;
	cs:_int8addr;
	return;
/*continuing to unbounded code: loc_14f3c from _timer_int_end:20-22*/
loc_14f3c:
	data.word(k_word_14f6c) = 1;
	cs:_int8addr;
loc_14f3c:
}

	_pop(flags);
	_write_cf(false);
 	return;
loc_14f95:
}

void InertiaPlayerContext::_covox_set() {
	STACK_CHECK;
	_configure_timer();
	return;
}

void InertiaPlayerContext::_covox_timer_int() {
	STACK_CHECK;
	_push(ax);
	_push(dx);
	_push(ds);
	ds = dx;
	// _out(dx, al);
	al = 0x20;
	// _out(0x20, al);
	_pop(ds);
	_pop(dx);
	_pop(ax);
	_inc(data.word(k_word_14fc5));
		_jz(loc_14fe3);
	_dec(data.word(k_word_14f6c));
		_jz(near ptr _timer_int_end);
	return;
loc_14fe3:
	_dec(data.word(k_word_14f6c));
		_jz(near ptr _timer_int_end);
	return;
	return;
/*continuing to unbounded code: loc_14fe3 from _covox_timer_int:16-19*/
loc_14fe3:
	_dec(data.word(k_word_14f6c));
		_jz(near ptr _timer_int_end);
	return;
loc_14fe3:
}

void InertiaPlayerContext::_covox_sndoff() {
	STACK_CHECK;
	_memfill8080();
	return;
}

void InertiaPlayerContext::_covox_clean() {
	STACK_CHECK;
	_clean_int8_mem_timr();
	return;
}

	_pop(flags);
	_write_cf(false);
 	return;
loc_1501d:
}

void InertiaPlayerContext::_stereo_set() {
	STACK_CHECK;
	_configure_timer();
	return;
}

void InertiaPlayerContext::_stereo_timer_int() {
	STACK_CHECK;
	_push(ax);
	_push(dx);
	_push(ds);
	dx = ;
	ds = dx;
	al = 2;
	// _out(dx, al);
	_sub(dl, 2);
	// _out(dx, al);
	_add(dl, 2);
	al = 1;
	// _out(dx, al);
	_sub(dl, 2);
	al = ah;
	// _out(dx, al);
	al = 0x20;
	// _out(0x20, al);
	_pop(ds);
	_pop(dx);
	_pop(ax);
	_add(data.word(k_word_15056), 2);
		_jc(loc_1507e);
	_dec(data.word(k_word_14f6c));
		_jz(near ptr _timer_int_end);
	return;
loc_1507e:
	_dec(data.word(k_word_14f6c));
		_jz(near ptr _timer_int_end);
	return;
	return;
/*continuing to unbounded code: loc_1507e from _stereo_timer_int:27-30*/
loc_1507e:
	_dec(data.word(k_word_14f6c));
		_jz(near ptr _timer_int_end);
	return;
loc_1507e:
}

void InertiaPlayerContext::_stereo_sndoff() {
	STACK_CHECK;
	_memfill8080();
	return;
}

void InertiaPlayerContext::_stereo_clean() {
	STACK_CHECK;
	_clean_int8_mem_timr();
	return;
}

	_pop(flags);
	_write_cf(false);
 	return;
loc_150e8:
}

void InertiaPlayerContext::_adlib_set() {
	STACK_CHECK;
	_configure_timer();
	return;
}

void InertiaPlayerContext::_adlib_sndoff() {
	STACK_CHECK;
	_memfill8080();
	return;
}

void InertiaPlayerContext::_adlib_clean() {
	STACK_CHECK;
	_clean_int8_mem_timr();
	_adlib_18389();
	return;
}

	_pop(flags);
	_write_cf(false);
 	return;
}

void InertiaPlayerContext::_pcspeaker_set() {
	STACK_CHECK;
	// _in(al, 0x61);
	_or(al, 3);
	// _out(0x61, al);
	_configure_timer();
	return;
}

void InertiaPlayerContext::_pcspeaker_sndoff() {
	STACK_CHECK;
	_memfill8080();
	// _in(al, 0x61);
	_and(al, 0x0FC);
	// _out(0x61, al);
	return;
}

void InertiaPlayerContext::_pcspeaker_clean() {
	STACK_CHECK;
	_clean_int8_mem_timr();
	return;
}

void InertiaPlayerContext::_midi_set() {
	STACK_CHECK;
	bx = 49828;
	dx = cs;
	al = 8;
	_setint_vect();
	return;
}

void InertiaPlayerContext::loc_14111() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_2466b), 1);
		_jz(loc_141ba);
	_cmp(data.byte(k_byte_2466a), 1);
		_jz(loc_14153);
	_cmp(data.byte(k_byte_2466c), 0);
		_jz(loc_14131);
	al = 0;
	_xchg(al, data.byte(k_byte_2466c));
	data.byte(k_byte_2466d) = al;
loc_14131:
	_cmp(data.byte(k_byte_2466d), 0);
		_jz(loc_1413e);
	_dec(data.byte(k_byte_2466d));
		_jnz(loc_14142);
loc_1413e:
	_inc(data.word(k_word_245f6));
loc_14142:
	bx = data.word(k_word_245f0);
	ax = data.byte(k_byte_281e8)[bx];
	_cmp(data.word(k_word_245f6), ax);
		_jbe(loc_141da);
loc_14153:
	_cmp(data.byte(k_play_state), 2);
		_jz(loc_14184);
	_inc(data.word(k_word_245f0));
	return;
/*continuing to unbounded code: loc_14184 from sub_1415e:14-46*/
loc_14184:
	bx = data.word(k_word_245f0);
	al = data.byte(k_byte_280e8)[bx];
	_or(al, al);
		_jz(loc_141a2);
	_push(bx);
	_cmp(al, 0x0FF);
		_jnz(loc_1419e);
	al = data.byte(k_byte_2467a);
	sub_13cf6();
	al = data.byte(k_byte_24679);
loc_1419e:
	_eff_13ce8();
	_pop(bx);
loc_141a2:
	flags.c() = (data.byte(k_byte_282e8) >> bx) & 1; data.byte(k_byte_282e8) |= 1 << bx;
	bx = data.byte(k_byte_27fe8)[bx];
	data.word(k_my_seg_index) = bx;
	_shl(bx, 1);
	es = data.word(k_segs_table)[bx];
	data.dword(k_pointer_245b4)[2] = es;
loc_141ba:
	ax = 0;
	_xchg(al, data.byte(k_byte_24669));
	data.word(k_word_245f6) = ax;
	sub_11c0c();
	data.byte(k_byte_2466a) = 0;
	data.byte(k_byte_2466b) = 0;
	data.byte(k_byte_2466c) = 0;
	data.byte(k_byte_2466d) = 0;
loc_141da:
	data.dword(k_pointer_245b4) = si;
	return;
}

	_popad();
	return;
loc_1538f:
}

void InertiaPlayerContext::_midi_sndoff() {
	STACK_CHECK;
	dx = data.dword(k_int8addr)[2];
	bx = data.dword(k_int8addr);
	al = 8;
	_setint_vect();
	_clean_timer();
	_midi_153d6();
	return;
}

void InertiaPlayerContext::_midi_clean() {
	STACK_CHECK;
	ah = 0x0FF;
	_midi_153f1();
	return;
}

void InertiaPlayerContext::_midi_153c0() {
	STACK_CHECK;
	ah = 0x0FF;
	_midi_153f1();
	cx = 0x8000;
	_midi_15442();
	ah = 0x3F;
	_midi_153f1();
	cx = 0;
	_midi_15442();
	return;
}

void InertiaPlayerContext::_midi_153d6() {
	STACK_CHECK;
	bl = 0;
loc_153d8:
	ah = 0x0B0;
	_or(ah, bl);
	_midi_15413();
	ah = 0x7B;
	_midi_15413();
	ah = 0;
	_midi_15413();
	_inc(bl);
	_cmp(bl, 0x10);
		_jc(loc_153d8);
	return;
	return;
/*continuing to unbounded code: loc_153d8 from _midi_153d6:2-13*/
loc_153d8:
	ah = 0x0B0;
	_or(ah, bl);
	_midi_15413();
	ah = 0x7B;
	_midi_15413();
	ah = 0;
	_midi_15413();
	_inc(bl);
	_cmp(bl, 0x10);
		_jc(loc_153d8);
	return;
loc_153d8:
}

void InertiaPlayerContext::_midi_153f1() {
	STACK_CHECK;
	dx = data.word(k_word_2465c);
	_inc(dx);
	cx = 0;
loc_153f8:
	// _in(al, dx);
	_test(al, 0x40);
		_jz(loc_15401);
	_dec(cx);
		_jnz(loc_153f8);
	return;
loc_15401:
	al = ah;
	// _out(dx, al);
	cx = 0;
loc_15406:
	// _in(al, dx);
	_shl(al, 1);
		_jnc(loc_1540e);
	_dec(cx);
		_jnz(loc_15406);
loc_1540e:
	_dec(dx);
	// _in(al, dx);
	_cmp(al, 0x0FE);
	return;
	return;
/*continuing to unbounded code: loc_153f8 from _midi_153f1:4-25*/
loc_153f8:
	// _in(al, dx);
	_test(al, 0x40);
		_jz(loc_15401);
	_dec(cx);
		_jnz(loc_153f8);
	return;
loc_15401:
	al = ah;
	// _out(dx, al);
	cx = 0;
loc_15406:
	// _in(al, dx);
	_shl(al, 1);
		_jnc(loc_1540e);
	_dec(cx);
		_jnz(loc_15406);
loc_1540e:
	_dec(dx);
	// _in(al, dx);
	_cmp(al, 0x0FE);
	return;
loc_153f8:
}

void InertiaPlayerContext::_midi_15413() {
	STACK_CHECK;
	_or(ah, ah);
		_jns(loc_15421);
	_cmp(ah, data.byte(k_byte_24677));
		_jz(locret_15441);
	data.byte(k_byte_24677) = ah;
loc_15421:
	dx = data.word(k_word_2465c);
	_inc(dx);
	cl = 0x0FF;
loc_15428:
	// _in(al, dx);
	_test(al, 0x40);
		_jz(loc_15439);
	_shl(al, 1);
		_jc(loc_15434);
	_dec(dx);
	// _in(al, dx);
	_inc(dx);
loc_15434:
	_dec(cl);
		_jnz(loc_15428);
	return;
loc_15439:
	_dec(dx);
	al = ah;
	// _out(dx, al);
	_sub(data.byte(k_byte_24678), al);
locret_15441:
	return;
}

void InertiaPlayerContext::_midi_15442() {
	STACK_CHECK;
	dx = data.word(k_word_2465c);
	_inc(dx);
loc_15447:
	// _in(al, dx);
	_dec(cx);
		_jnz(loc_15447);
	return;
}

void InertiaPlayerContext::_nullsub_4() {
	STACK_CHECK;
	return;
}

void InertiaPlayerContext::_midi_1544d() {
	STACK_CHECK;
	_and(ds.byte(bx+0x17), 0x0FE);
	_midi_154da();
	_or(ah, 0x80);
	_midi_15413();
	_midi_154de();
	_midi_15413();
	ah = 0x7F;
	_midi_15413();
	return;
}

void InertiaPlayerContext::_midi_15466() {
	STACK_CHECK;
	_test(ds.byte(bx+0x17), 0x0FE);
		_jz(loc_1546f);
	_midi_1544d();
loc_1546f:
	_or(ds.byte(bx+0x17), 1);
	al = ds.byte(bx+2);
	_cmp(al, ds.byte(bx+3));
		_jz(loc_1548d);
	ds.byte(bx+3) = al;
	_midi_154da();
	_or(ah, 0x0C0);
	_midi_15413();
	ah = ds.byte(bx+2);
	_midi_15413();
loc_1548d:
	al = ds.byte(bx+8);
	_midi_154ac();
	_midi_154da();
	_or(ah, 0x90);
	_midi_15413();
	_midi_154de();
	_midi_15413();
	ah = 0x7F;
	_midi_15413();
	_or(ds.byte(bx+0x17), 1);
	return;
	return;
/*continuing to unbounded code: loc_1546f from _midi_15466:4-26*/
loc_1546f:
	_or(ds.byte(bx+0x17), 1);
	al = ds.byte(bx+2);
	_cmp(al, ds.byte(bx+3));
		_jz(loc_1548d);
	ds.byte(bx+3) = al;
	_midi_154da();
	_or(ah, 0x0C0);
	_midi_15413();
	ah = ds.byte(bx+2);
	_midi_15413();
loc_1548d:
	al = ds.byte(bx+8);
	_midi_154ac();
	_midi_154da();
	_or(ah, 0x90);
	_midi_15413();
	_midi_154de();
	_midi_15413();
	ah = 0x7F;
	_midi_15413();
	_or(ds.byte(bx+0x17), 1);
	return;
loc_1546f:
}

void InertiaPlayerContext::_midi_154ac() {
	STACK_CHECK;
	_cmp(al, data.byte(k_byte_2467d));
		_jc(loc_154b5);
	al = data.byte(k_byte_2467d);
loc_154b5:
	_cmp(al, ds.byte(bx+0x1B));
		_jz(locret_154d9);
	ds.byte(bx+0x1B) = al;
	di = al;
	_midi_154da();
	_or(ah, 0x0B0);
	_midi_15413();
	ah = 7;
	_midi_15413();
	al = 0x80;
	_add(di, data.word(kOff_24656));
	_mul(ds.byte(di));
	_midi_15413();
locret_154d9:
	return;
	return;
/*continuing to unbounded code: loc_154b5 from _midi_154ac:4-19*/
loc_154b5:
	_cmp(al, ds.byte(bx+0x1B));
		_jz(locret_154d9);
	ds.byte(bx+0x1B) = al;
	di = al;
	_midi_154da();
	_or(ah, 0x0B0);
	_midi_15413();
	ah = 7;
	_midi_15413();
	al = 0x80;
	_add(di, data.word(kOff_24656));
	_mul(ds.byte(di));
	_midi_15413();
locret_154d9:
	return;
loc_154b5:
}

void InertiaPlayerContext::_midi_154da() {
	STACK_CHECK;
	ah = ds.byte(bx+0x18);
	return;
}

void InertiaPlayerContext::_midi_154de() {
	STACK_CHECK;
	al = ds.byte(bx+0x35);
	dl = al;
	_and(dl, 0x0F);
	_dec(dl);
	_shr(al, 4);
	ah = 0x0C;
	_mul(ah);
	_add(al, dl);
	ah = al;
	return;
}

void InertiaPlayerContext::sub_154f4() {
	STACK_CHECK;
	ax = data.word(k_word_245e4);
	_shr(ax, 4);
	data.byte(k_byte_24683) = al;
	_push(bx);
	_push(si);
	bx = ds.word(si+0x26);
	eax = ds.dword(si+4);
	_shr(eax, 0x16);
	_add(bx, ax);
	_ems_mapmem();
	_pop(si);
	_pop(bx);
	eax = ds.dword(si+4);
	_shr(eax, 0x0C);
	_cmp(ds.word(si+0x26), 0x0FFFF);
		_jz(loc_15525);
	_and(eax, 0x3FF);
loc_15525:
	_add(ax, ds.word(si+0x24));
	es = ax;
	ebx = ds.byte(si+0x23);
	ax = ds.word(si+0x36);
	data.word(k_word_24614) = ax;
	data.byte(k_byte_24616) = 0;
	_test(data.byte(k_flag_playsetttings), 0x10);
		_jz(_lc_inerpol_disabld);
	_cmp(al, ah);
	if (!flags.z()) ah = 1; else ah = 0; //setnz
	data.byte(k_byte_24616) = ah;
	ebx = al;
_lc_inerpol_disabld:
	_shl(ebx, 9);
	_add(bx, 6904);
	ebp = ds.word(si+0x20);
	ax = bp;
	ch = al;
	_shr(ebp, 8);
	esi = ds.dword(si+4);
	ax = si;
	cl = al;
	_and(esi, 0x0FFF);
	_shr(esi, 8);
	return;
}

void InertiaPlayerContext::sub_15577() {
	STACK_CHECK;
	_test(ds.byte(si+0x17), 1);
		_jz(locret_157bc);
	_push(si);
	sub_154f4();
	_test(data.byte(k_flag_playsetttings), 0x10);
		_jnz(_lc_perfrm_interpol);
	_cmp(data.byte(k_byte_24625), 1);
		_jz(loc_15e48);
	edx = 0;
	ax = data.word(k_word_245e4);
	_and(eax, 0x0F);
	cs:_offs_noninterp[eax*2];
}

void InertiaPlayerContext::sub_1609f() {
	STACK_CHECK;
	_test(ds.byte(si+0x17), 1);
		_jz(loc_16bb0);
	_push(si);
	sub_154f4();
	_test(data.byte(k_flag_playsetttings), 0x10);
		_jnz(_lc_perfrm_interpol2);
	_cmp(data.byte(k_byte_24625), 1);
		_jz(loc_16959);
	edx = 0;
	ax = data.word(k_word_245e4);
	_and(eax, 0x0F);
	cs:_offs_noninterp2[eax*2];
}

void InertiaPlayerContext::sub_16c69() {
	STACK_CHECK;
	_ems_save_mapctx();
	_write_df(false);
 	ax = data.word(k_word_245e8);
	data.word(k_word_245e4) = ax;
	_dec(data.word(k_word_245ee));
		_jnz(loc_16c88);
	sub_140b6();
	ax = data.word(k_word_245ea);
	data.word(k_word_245e4) = ax;
	ax = data.word(k_word_245ec);
	data.word(k_word_245ee) = ax;
loc_16c88:
	data.byte(k_byte_24682) = 0;
	_cmp(data.byte(k_byte_24623), 1);
		_jz(loc_171d3);
	si = 6884;
	cx = data.word(k_word_245d4);
loc_16c9d:
	_cmp(ds.byte(si+0x1D), 0);
		_jnz(loc_16cbe);
	_push(cx);
	_push(si);
	di = 6905;
	_test(data.byte(k_byte_24682), 1);
		_jnz(loc_16cb9);
	_or(data.byte(k_byte_24682), 1);
	sub_1609f();
	loc_16cbc;
loc_16cb9:
	sub_15577();
loc_16cbc:
	_pop(si);
	_pop(cx);
loc_16cbe:
	_add(si, 0x50);
	_dec(cx);
		_jnz(loc_16c9d);
	di = data.word(k_word_24600);
	cx = data.word(k_word_245e4);
	si = ( data.dword(k_chrin)+1);
	es = data.dword(k_dma_buf_pointer)[2];
	ax = 0x1000;
	_sub(ax, di);
	_cmp(ax, cx);
		_ja(loc_16ceb);
	bx = cx;
	_sub(bx, ax);
	cx = ax;
	_push(bx);
	sub_16cf6();
	_pop(cx);
	di = 0;
	if (cx==0)
		loc_16cee;
loc_16ceb:
	sub_16cf6();
loc_16cee:
	data.word(k_word_24600) = di;
	_ems_restore_mapctx();
	return;
	return;
/*continuing to unbounded code: loc_16c88 from sub_16c69:12-59*/
loc_16c88:
	data.byte(k_byte_24682) = 0;
	_cmp(data.byte(k_byte_24623), 1);
		_jz(loc_171d3);
	si = 6884;
	cx = data.word(k_word_245d4);
loc_16c9d:
	_cmp(ds.byte(si+0x1D), 0);
		_jnz(loc_16cbe);
	_push(cx);
	_push(si);
	di = 6905;
	_test(data.byte(k_byte_24682), 1);
		_jnz(loc_16cb9);
	_or(data.byte(k_byte_24682), 1);
	sub_1609f();
	loc_16cbc;
loc_16cb9:
	sub_15577();
loc_16cbc:
	_pop(si);
	_pop(cx);
loc_16cbe:
	_add(si, 0x50);
	_dec(cx);
		_jnz(loc_16c9d);
	di = data.word(k_word_24600);
	cx = data.word(k_word_245e4);
	si = ( data.dword(k_chrin)+1);
	es = data.dword(k_dma_buf_pointer)[2];
	ax = 0x1000;
	_sub(ax, di);
	_cmp(ax, cx);
		_ja(loc_16ceb);
	bx = cx;
	_sub(bx, ax);
	cx = ax;
	_push(bx);
	sub_16cf6();
	_pop(cx);
	di = 0;
	if (cx==0)
		loc_16cee;
loc_16ceb:
	sub_16cf6();
loc_16cee:
	data.word(k_word_24600) = di;
	_ems_restore_mapctx();
	return;
loc_16c88:
}

void InertiaPlayerContext::sub_16cf6() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_24625), 1);
		_jz(loc_16e24);
	bx = cx;
	_and(bx, 0x0F);
	_shl(bx, 1);
	cs:off_18ea0[bx];
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	al = ds.byte(si);
	_xor(al, 0x80);
	es.byte(di) = al;
	_add(si, 8);
	_inc(di);
	_shr(cx, 4);
		_jz(locret_16e23);
	edx = 0x80808080;
loc_16dbb:
	al = ds.byte(si+0x10);
	ah = ds.byte(si+0x18);
	_shl(eax, 0x10);
	al = ds.byte(si);
	ah = ds.byte(si+8);
	_xor(eax, edx);
	es.dword(di) = eax;
	al = ds.byte(si+0x30);
	ah = ds.byte(si+0x38);
	_shl(eax, 0x10);
	al = ds.byte(si+0x20);
	ah = ds.byte(si+0x28);
	_xor(eax, edx);
	es.dword(di+4) = eax;
	al = ds.byte(si+0x50);
	ah = ds.byte(si+0x58);
	_shl(eax, 0x10);
	al = ds.byte(si+0x40);
	ah = ds.byte(si+0x48);
	_xor(eax, edx);
	es.dword(di+8) = eax;
	al = ds.byte(si+0x70);
	ah = ds.byte(si+0x78);
	_shl(eax, 0x10);
	al = ds.byte(si+0x60);
	ah = ds.byte(si+0x68);
	_xor(eax, edx);
	es.dword(di+0x0C) = eax;
	_add(si, 0x80);
	_add(di, 0x10);
	_dec(cx);
		_jnz(loc_16dbb);
locret_16e23:
	return;
loc_16e24:
	_and(si, 0x0FFFC);
	edx = 0x7FFF;
	ebp = 0x0FFFF8000;
	bx = cx;
	_and(bx, 0x0F);
	_shl(bx, 1);
	cs:off_18ec0[bx];
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16e56;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16e74;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16e92;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16eb0;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16ece;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16eec;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16f0a;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16f28;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16f46;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16f64;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16f82;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16fa0;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16fbe;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16fdc;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16ffa;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	_shr(cx, 4);
		_jz(locret_171d2);
loc_17008:
	eax = ds.dword(si);
	bx = offset_loc_1701c;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	eax = ds.dword(si+8);
	bx = offset_loc_17037;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+1) = ah;
	eax = ds.dword(si+0x10);
	bx = offset_loc_17053;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+2) = ah;
	eax = ds.dword(si+0x18);
	bx = offset_loc_1706f;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+3) = ah;
	eax = ds.dword(si+0x20);
	bx = offset_loc_1708b;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+4) = ah;
	eax = ds.dword(si+0x28);
	bx = offset_loc_170a7;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+5) = ah;
	eax = ds.dword(si+0x30);
	bx = offset_loc_170c3;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+6) = ah;
	eax = ds.dword(si+0x38);
	bx = offset_loc_170df;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+7) = ah;
	eax = ds.dword(si+0x40);
	bx = offset_loc_170fb;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+8) = ah;
	eax = ds.dword(si+0x48);
	bx = offset_loc_17117;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+9) = ah;
	eax = ds.dword(si+0x50);
	bx = offset_loc_17133;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+0x0A) = ah;
	eax = ds.dword(si+0x58);
	bx = offset_loc_1714f;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+0x0B) = ah;
	eax = ds.dword(si+0x60);
	bx = offset_loc_1716b;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+0x0C) = ah;
	eax = ds.dword(si+0x68);
	bx = offset_loc_17187;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+0x0D) = ah;
	eax = ds.dword(si+0x70);
	bx = offset_loc_171a3;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+0x0E) = ah;
	eax = ds.dword(si+0x78);
	bx = offset_loc_171bf;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+0x0F) = ah;
	_add(si, 0x80);
	_add(di, 0x10);
	_dec(cx);
		_jnz(loc_17008);
locret_171d2:
	return;
	return;
/*continuing to unbounded code: loc_16dbb from sub_16cf6:102-479*/
loc_16dbb:
	al = ds.byte(si+0x10);
	ah = ds.byte(si+0x18);
	_shl(eax, 0x10);
	al = ds.byte(si);
	ah = ds.byte(si+8);
	_xor(eax, edx);
	es.dword(di) = eax;
	al = ds.byte(si+0x30);
	ah = ds.byte(si+0x38);
	_shl(eax, 0x10);
	al = ds.byte(si+0x20);
	ah = ds.byte(si+0x28);
	_xor(eax, edx);
	es.dword(di+4) = eax;
	al = ds.byte(si+0x50);
	ah = ds.byte(si+0x58);
	_shl(eax, 0x10);
	al = ds.byte(si+0x40);
	ah = ds.byte(si+0x48);
	_xor(eax, edx);
	es.dword(di+8) = eax;
	al = ds.byte(si+0x70);
	ah = ds.byte(si+0x78);
	_shl(eax, 0x10);
	al = ds.byte(si+0x60);
	ah = ds.byte(si+0x68);
	_xor(eax, edx);
	es.dword(di+0x0C) = eax;
	_add(si, 0x80);
	_add(di, 0x10);
	_dec(cx);
		_jnz(loc_16dbb);
locret_16e23:
	return;
loc_16e24:
	_and(si, 0x0FFFC);
	edx = 0x7FFF;
	ebp = 0x0FFFF8000;
	bx = cx;
	_and(bx, 0x0F);
	_shl(bx, 1);
	cs:off_18ec0[bx];
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16e56;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16e74;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16e92;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16eb0;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16ece;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16eec;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16f0a;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16f28;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16f46;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16f64;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16f82;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16fa0;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16fbe;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16fdc;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	eax = ds.dword(si);
	_add(si, 8);
	bx = offset_loc_16ffa;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	_inc(di);
	_shr(cx, 4);
		_jz(locret_171d2);
loc_17008:
	eax = ds.dword(si);
	bx = offset_loc_1701c;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di) = ah;
	eax = ds.dword(si+8);
	bx = offset_loc_17037;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+1) = ah;
	eax = ds.dword(si+0x10);
	bx = offset_loc_17053;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+2) = ah;
	eax = ds.dword(si+0x18);
	bx = offset_loc_1706f;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+3) = ah;
	eax = ds.dword(si+0x20);
	bx = offset_loc_1708b;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+4) = ah;
	eax = ds.dword(si+0x28);
	bx = offset_loc_170a7;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+5) = ah;
	eax = ds.dword(si+0x30);
	bx = offset_loc_170c3;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+6) = ah;
	eax = ds.dword(si+0x38);
	bx = offset_loc_170df;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+7) = ah;
	eax = ds.dword(si+0x40);
	bx = offset_loc_170fb;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+8) = ah;
	eax = ds.dword(si+0x48);
	bx = offset_loc_17117;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+9) = ah;
	eax = ds.dword(si+0x50);
	bx = offset_loc_17133;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+0x0A) = ah;
	eax = ds.dword(si+0x58);
	bx = offset_loc_1714f;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+0x0B) = ah;
	eax = ds.dword(si+0x60);
	bx = offset_loc_1716b;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+0x0C) = ah;
	eax = ds.dword(si+0x68);
	bx = offset_loc_17187;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+0x0D) = ah;
	eax = ds.dword(si+0x70);
	bx = offset_loc_171a3;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+0x0E) = ah;
	eax = ds.dword(si+0x78);
	bx = offset_loc_171bf;
	_cmp(eax, ebp);
		_jl(loc_18db0);
	_cmp(eax, edx);
		_jg(loc_18db8);
	_xor(ah, 0x80);
	es.byte(di+0x0F) = ah;
	_add(si, 0x80);
	_add(di, 0x10);
	_dec(cx);
		_jnz(loc_17008);
locret_171d2:
	return;
loc_16dbb:
}

void InertiaPlayerContext::sub_1725f() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_24625), 1);
		_jz(loc_17441);
	_or(si, 1);
	edx = 0x80808080;
	_shr(cx, 1);
	bx = cx;
	_and(bx, 0x0F);
	_shl(bx, 1);
	cs:off_18ee0[bx];
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	al = ds.byte(si);
	ah = ds.byte(si+4);
	_add(si, 8);
	_xor(ax, dx);
	es.word(di) = ax;
	_add(di, 2);
	_shr(cx, 4);
		_jz(locret_17440);
loc_17376:
	al = ds.byte(si+8);
	bl = ds.byte(si+0x18);
	ah = ds.byte(si+0x0C);
	bh = ds.byte(si+0x1C);
	_shl(eax, 0x10);
	_shl(ebx, 0x10);
	al = ds.byte(si);
	bl = ds.byte(si+0x10);
	ah = ds.byte(si+4);
	bh = ds.byte(si+0x14);
	_xor(eax, edx);
	_xor(ebx, edx);
	es.dword(di) = eax;
	es.dword(di+4) = ebx;
	al = ds.byte(si+0x28);
	bl = ds.byte(si+0x38);
	ah = ds.byte(si+0x2C);
	bh = ds.byte(si+0x3C);
	_shl(eax, 0x10);
	_shl(ebx, 0x10);
	al = ds.byte(si+0x20);
	bl = ds.byte(si+0x30);
	ah = ds.byte(si+0x24);
	bh = ds.byte(si+0x34);
	_xor(eax, edx);
	_xor(ebx, edx);
	es.dword(di+8) = eax;
	es.dword(di+0x0C) = ebx;
	al = ds.byte(si+0x48);
	bl = ds.byte(si+0x58);
	ah = ds.byte(si+0x4C);
	bh = ds.byte(si+0x5C);
	_shl(eax, 0x10);
	_shl(ebx, 0x10);
	al = ds.byte(si+0x40);
	bl = ds.byte(si+0x50);
	ah = ds.byte(si+0x44);
	bh = ds.byte(si+0x54);
	_xor(eax, edx);
	_xor(ebx, edx);
	es.dword(di+0x10) = eax;
	es.dword(di+0x14) = ebx;
	al = ds.byte(si+0x68);
	bl = ds.byte(si+0x78);
	ah = ds.byte(si+0x6C);
	bh = ds.byte(si+0x7C);
	_shl(eax, 0x10);
	_shl(ebx, 0x10);
	al = ds.byte(si+0x60);
	bl = ds.byte(si+0x70);
	ah = ds.byte(si+0x64);
	bh = ds.byte(si+0x74);
	_xor(eax, edx);
	_xor(ebx, edx);
	es.dword(di+0x18) = eax;
	es.dword(di+0x1C) = ebx;
	_add(si, 0x80);
	_add(di, 0x20);
	_dec(cx);
		_jnz(loc_17376);
locret_17440:
	return;
loc_17441:
	_and(si, 0x0FFFC);
	edx = 0x7FFF;
	ebp = 0x0FFFF8000;
	bx = cx;
	_and(bx, 0x0F);
	_shl(bx, 1);
	cs:off_18f00[bx];
}

void InertiaPlayerContext::sub_17824() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_24625), 1);
		_jz(loc_17a58);
	bx = cx;
	_and(bx, 0x0F);
	_shl(bx, 1);
	cs:off_18f20[bx];
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	_add(si, 8);
	es.dword(di) = eax;
	_add(di, 4);
	_shr(cx, 4);
		_jz(locret_17a57);
loc_1795d:
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	es.dword(di) = eax;
	ax = ds.word(si+0x0C);
	_shl(eax, 0x10);
	ax = ds.word(si+8);
	es.dword(di+4) = eax;
	ax = ds.word(si+0x14);
	_shl(eax, 0x10);
	ax = ds.word(si+0x10);
	es.dword(di+8) = eax;
	ax = ds.word(si+0x1C);
	_shl(eax, 0x10);
	ax = ds.word(si+0x18);
	es.dword(di+0x0C) = eax;
	ax = ds.word(si+0x24);
	_shl(eax, 0x10);
	ax = ds.word(si+0x20);
	es.dword(di+0x10) = eax;
	ax = ds.word(si+0x2C);
	_shl(eax, 0x10);
	ax = ds.word(si+0x28);
	es.dword(di+0x14) = eax;
	ax = ds.word(si+0x34);
	_shl(eax, 0x10);
	ax = ds.word(si+0x30);
	es.dword(di+0x18) = eax;
	ax = ds.word(si+0x3C);
	_shl(eax, 0x10);
	ax = ds.word(si+0x38);
	es.dword(di+0x1C) = eax;
	ax = ds.word(si+0x44);
	_shl(eax, 0x10);
	ax = ds.word(si+0x40);
	es.dword(di+0x20) = eax;
	ax = ds.word(si+0x4C);
	_shl(eax, 0x10);
	ax = ds.word(si+0x48);
	es.dword(di+0x24) = eax;
	ax = ds.word(si+0x54);
	_shl(eax, 0x10);
	ax = ds.word(si+0x50);
	es.dword(di+0x28) = eax;
	ax = ds.word(si+0x5C);
	_shl(eax, 0x10);
	ax = ds.word(si+0x58);
	es.dword(di+0x2C) = eax;
	ax = ds.word(si+0x64);
	_shl(eax, 0x10);
	ax = ds.word(si+0x60);
	es.dword(di+0x30) = eax;
	ax = ds.word(si+0x6C);
	_shl(eax, 0x10);
	ax = ds.word(si+0x68);
	es.dword(di+0x34) = eax;
	ax = ds.word(si+0x74);
	_shl(eax, 0x10);
	ax = ds.word(si+0x70);
	es.dword(di+0x38) = eax;
	ax = ds.word(si+0x7C);
	_shl(eax, 0x10);
	ax = ds.word(si+0x78);
	es.dword(di+0x3C) = eax;
	_add(si, 0x80);
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_1795d);
locret_17a57:
	return;
loc_17a58:
	edx = 0x7FFF;
	ebp = 0x0FFFF8000;
	_shl(cx, 1);
	bx = cx;
	_and(bx, 0x0F);
	_shl(bx, 1);
	cs:off_18f40[bx];
	return;
/*continuing to unbounded code: loc_1795d from sub_17824:115-193*/
loc_1795d:
	ax = ds.word(si+4);
	_shl(eax, 0x10);
	ax = ds.word(si);
	es.dword(di) = eax;
	ax = ds.word(si+0x0C);
	_shl(eax, 0x10);
	ax = ds.word(si+8);
	es.dword(di+4) = eax;
	ax = ds.word(si+0x14);
	_shl(eax, 0x10);
	ax = ds.word(si+0x10);
	es.dword(di+8) = eax;
	ax = ds.word(si+0x1C);
	_shl(eax, 0x10);
	ax = ds.word(si+0x18);
	es.dword(di+0x0C) = eax;
	ax = ds.word(si+0x24);
	_shl(eax, 0x10);
	ax = ds.word(si+0x20);
	es.dword(di+0x10) = eax;
	ax = ds.word(si+0x2C);
	_shl(eax, 0x10);
	ax = ds.word(si+0x28);
	es.dword(di+0x14) = eax;
	ax = ds.word(si+0x34);
	_shl(eax, 0x10);
	ax = ds.word(si+0x30);
	es.dword(di+0x18) = eax;
	ax = ds.word(si+0x3C);
	_shl(eax, 0x10);
	ax = ds.word(si+0x38);
	es.dword(di+0x1C) = eax;
	ax = ds.word(si+0x44);
	_shl(eax, 0x10);
	ax = ds.word(si+0x40);
	es.dword(di+0x20) = eax;
	ax = ds.word(si+0x4C);
	_shl(eax, 0x10);
	ax = ds.word(si+0x48);
	es.dword(di+0x24) = eax;
	ax = ds.word(si+0x54);
	_shl(eax, 0x10);
	ax = ds.word(si+0x50);
	es.dword(di+0x28) = eax;
	ax = ds.word(si+0x5C);
	_shl(eax, 0x10);
	ax = ds.word(si+0x58);
	es.dword(di+0x2C) = eax;
	ax = ds.word(si+0x64);
	_shl(eax, 0x10);
	ax = ds.word(si+0x60);
	es.dword(di+0x30) = eax;
	ax = ds.word(si+0x6C);
	_shl(eax, 0x10);
	ax = ds.word(si+0x68);
	es.dword(di+0x34) = eax;
	ax = ds.word(si+0x74);
	_shl(eax, 0x10);
	ax = ds.word(si+0x70);
	es.dword(di+0x38) = eax;
	ax = ds.word(si+0x7C);
	_shl(eax, 0x10);
	ax = ds.word(si+0x78);
	es.dword(di+0x3C) = eax;
	_add(si, 0x80);
	_add(di, 0x40);
	_dec(cx);
		_jnz(loc_1795d);
locret_17a57:
	return;
loc_17a58:
	edx = 0x7FFF;
	ebp = 0x0FFFF8000;
	_shl(cx, 1);
	bx = cx;
	_and(bx, 0x0F);
	_shl(bx, 1);
	cs:off_18f40[bx];
loc_1795d:
}

void InertiaPlayerContext::_nullsub_3() {
	STACK_CHECK;
	return;
}

	_pop(flags);
	return;
loc_182f7:
}

	_pop(flags);
	return;
loc_182f7:
}

void InertiaPlayerContext::_adlib_18389() {
	STACK_CHECK;
	ax = 0;
loc_1838b:
	_adlib_18395();
	_inc(al);
	_cmp(al, 0x0E8);
		_jbe(loc_1838b);
	return;
	return;
/*continuing to unbounded code: loc_1838b from _adlib_18389:2-7*/
loc_1838b:
	_adlib_18395();
	_inc(al);
	_cmp(al, 0x0E8);
		_jbe(loc_1838b);
	return;
loc_1838b:
}

void InertiaPlayerContext::_adlib_18395() {
	STACK_CHECK;
	_push(ax);
	_push(dx);
	dx = 0x388;
	// _out(dx, al);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	_inc(dx);
	al = ah;
	// _out(dx, al);
	_dec(dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	// _in(al, dx);
	_pop(dx);
	_pop(ax);
	return;
}

void InertiaPlayerContext::_sb16_detect_port() {
	STACK_CHECK;
	_cmp(data.word(k_snd_base_port), 0x0FFFF);
		_jz(loc_183de);
	ax = data.word(k_snd_base_port);
	data.word(k_sb_base_port) = ax;
	_checksb();
		_jnc(loc_1842d);
loc_183de:
	data.word(k_sb_base_port) = 0x220;
	_checksb();
		_jnc(loc_1842d);
	data.word(k_sb_base_port) = 0x240;
	_checksb();
		_jnc(loc_1842d);
	data.word(k_sb_base_port) = 0x210;
	_checksb();
		_jnc(loc_1842d);
	data.word(k_sb_base_port) = 0x230;
	_checksb();
		_jnc(loc_1842d);
	data.word(k_sb_base_port) = 0x250;
	_checksb();
		_jnc(loc_1842d);
	data.word(k_sb_base_port) = 0x260;
	_checksb();
		_jnc(loc_1842d);
	data.word(k_sb_base_port) = 0x280;
	_checksb();
		_jnc(loc_1842d);
	_write_cf(true);
 	return;
loc_1842d:
	al = 0x10;
	_writesb();
	al = 0x80;
	_writesb();
	al = 0x0E1;
	_writesb();
	_readsb();
	ah = al;
	_readsb();
	data.word(k_word_24654) = ax;
	_write_cf(false);
 	return;
	return;
/*continuing to unbounded code: loc_183de from _sb16_detect_port:7-43*/
loc_183de:
	data.word(k_sb_base_port) = 0x220;
	_checksb();
		_jnc(loc_1842d);
	data.word(k_sb_base_port) = 0x240;
	_checksb();
		_jnc(loc_1842d);
	data.word(k_sb_base_port) = 0x210;
	_checksb();
		_jnc(loc_1842d);
	data.word(k_sb_base_port) = 0x230;
	_checksb();
		_jnc(loc_1842d);
	data.word(k_sb_base_port) = 0x250;
	_checksb();
		_jnc(loc_1842d);
	data.word(k_sb_base_port) = 0x260;
	_checksb();
		_jnc(loc_1842d);
	data.word(k_sb_base_port) = 0x280;
	_checksb();
		_jnc(loc_1842d);
	_write_cf(true);
 	return;
loc_1842d:
	al = 0x10;
	_writesb();
	al = 0x80;
	_writesb();
	al = 0x0E1;
	_writesb();
	_readsb();
	ah = al;
	_readsb();
	data.word(k_word_24654) = ax;
	_write_cf(false);
 	return;
loc_183de:
}

void InertiaPlayerContext::_sb16_sound_on() {
	STACK_CHECK;
	_checksb();
	al = 0x0D1;
	_writesb();
	ax = data.word(k_sb_base_port);
	data.word(k_snd_base_port) = ax;
	al = data.byte(k_sb_irq_number);
	data.byte(k_irq_number) = al;
	al = data.byte(k_dma_chn_mask);
	data.byte(k_dma_channel) = al;
	_write_cf(false);
 	return;
}

void InertiaPlayerContext::_sb16_18540() {
	STACK_CHECK;
	data.byte(k_dma_mode) = 0x48;
	// _cli();
	_checksb();
	data.word(k_word_2460e) = 2;
	data.dword(k_dma_buf_pointer) = 0;
	cl = data.byte(k_dma_chn_mask);
	_dma_186e3();
	data.byte(k_sb_int_counter) = 1;
	si = 49944;
	al = data.byte(k_sb_irq_number);
	_setsnd_handler();
	_cmp(data.byte(k_dma_chn_mask), 4);
		_jnc(loc_18591);
	al = 0x40;
	_writesb();
	al = 0x0D3;
	_writesb();
	al = 0x14;
	_writesb();
	ax = data.word(k_word_2460e);
	_dec(ax);
	_writesb();
	al = ah;
	_writesb();
	loc_185b5;
loc_18591:
	al = 0x42;
	_writesb();
	al = 0x0AC;
	_writesb();
	al = 0x44;
	_writesb();
	al = 0x0B6;
	_writesb();
	al = 0x30;
	_writesb();
	ax = data.word(k_word_2460e);
	_writesb();
	al = ah;
	_writesb();
loc_185b5:
	// _sti();
	cx = 0;
loc_185b8:
	_cmp(data.byte(k_sb_int_counter), 1);
		_jnz(loc_185cd);
	if (--cx)
		loc_185b8;
	_restore_intvector();
	cl = data.byte(k_dma_chn_mask);
	_set_dmachn_mask();
	_write_cf(true);
 	return;
loc_185cd:
	_restore_intvector();
	cl = data.byte(k_dma_chn_mask);
	_set_dmachn_mask();
	_write_cf(false);
 	return;
	return;
/*continuing to unbounded code: loc_185b5 from _sb16_18540:41-58*/
loc_185b5:
	// _sti();
	cx = 0;
loc_185b8:
	_cmp(data.byte(k_sb_int_counter), 1);
		_jnz(loc_185cd);
	if (--cx)
		loc_185b8;
	_restore_intvector();
	cl = data.byte(k_dma_chn_mask);
	_set_dmachn_mask();
	_write_cf(true);
 	return;
loc_185cd:
	_restore_intvector();
	cl = data.byte(k_dma_chn_mask);
	_set_dmachn_mask();
	_write_cf(false);
 	return;
loc_185b5:
}

void InertiaPlayerContext::_sb16_handler_int() {
	STACK_CHECK;
	_push(ax);
	_push(dx);
	_push(ds);
	ax = ;
	ds = ax;
	dx = data.word(k_sb_base_port);
	_add(dl, 0x0E);
	// _in(al, dx);
	_inc(data.byte(k_sb_int_counter));
	al = 0x20;
	// _out(0x20, al);
	_pop(ds);
	_pop(dx);
	_pop(ax);
	return;
}

void InertiaPlayerContext::_dma_186e3() {
	STACK_CHECK;
	_test(data.word(k_config_word)[1], 0x10);
		_jz(loc_186ef);
	_and(data.byte(k_dma_mode), 0x0EF);
loc_186ef:
	_cmp(cl, 1);
		_jz(loc_18761);
	_cmp(cl, 2);
		_jz(loc_187a6);
	_cmp(cl, 3);
		_jz(loc_187eb);
	_cmp(cl, 4);
		_jz(loc_18830);
	_cmp(cl, 5);
		_jz(loc_18878);
	_cmp(cl, 6);
		_jz(loc_188c2);
	_cmp(cl, 7);
		_jz(loc_1890c);
	al = 4;
	// _out(0x0A, al);
	al = 0;
	// _out(0x0C, al);
	al = data.byte(k_dma_mode);
	// _out(0x0B, al);
	dx = data.dword(k_dma_buf_pointer)[2];
	_rol(dx, 4);
	ax = dx;
	_and(al, 0x0F0);
	_and(dx, 0x0F);
	_add(ax, data.dword(k_dma_buf_pointer));
	_adc(dx, 0);
	_add(ax, data.dword(k_dword_24694));
	_adc(dx, data.dword(k_dword_24694)[2]);
	// _out(0, al);
	al = ah;
	// _out(0, al);
	al = dl;
	// _out(0x87, al);
	ax = data.word(k_word_2460e);
	_dec(ax);
	// _out(1, al);
	al = ah;
	// _out(1, al);
	al = 0;
	// _out(0x0A, al);
	return;
loc_18761:
	al = 5;
	// _out(0x0A, al);
	al = 0;
	// _out(0x0C, al);
	al = data.byte(k_dma_mode);
	_or(al, 1);
	// _out(0x0B, al);
	dx = data.dword(k_dma_buf_pointer)[2];
	_rol(dx, 4);
	ax = dx;
	_and(al, 0x0F0);
	_and(dx, 0x0F);
	_add(ax, data.dword(k_dma_buf_pointer));
	_adc(dx, 0);
	_add(ax, data.dword(k_dword_24694));
	_adc(dx, data.dword(k_dword_24694)[2]);
	// _out(2, al);
	al = ah;
	// _out(2, al);
	al = dl;
	// _out(0x83, al);
	ax = data.word(k_word_2460e);
	_dec(ax);
	// _out(3, al);
	al = ah;
	// _out(3, al);
	al = 1;
	// _out(0x0A, al);
	return;
loc_187a6:
	al = 6;
	// _out(0x0A, al);
	al = 0;
	// _out(0x0C, al);
	al = data.byte(k_dma_mode);
	_or(al, 2);
	// _out(0x0B, al);
	dx = data.dword(k_dma_buf_pointer)[2];
	_rol(dx, 4);
	ax = dx;
	_and(al, 0x0F0);
	_and(dx, 0x0F);
	_add(ax, data.dword(k_dma_buf_pointer));
	_adc(dx, 0);
	_add(ax, data.dword(k_dword_24694));
	_adc(dx, data.dword(k_dword_24694)[2]);
	// _out(4, al);
	al = ah;
	// _out(4, al);
	al = dl;
	// _out(0x81, al);
	ax = data.word(k_word_2460e);
	_dec(ax);
	// _out(5, al);
	al = ah;
	// _out(5, al);
	al = 2;
	// _out(0x0A, al);
	return;
loc_187eb:
	al = 7;
	// _out(0x0A, al);
	al = 0;
	// _out(0x0C, al);
	al = data.byte(k_dma_mode);
	_or(al, 3);
	// _out(0x0B, al);
	dx = data.dword(k_dma_buf_pointer)[2];
	_rol(dx, 4);
	ax = dx;
	_and(al, 0x0F0);
	_and(dx, 0x0F);
	_add(ax, data.dword(k_dma_buf_pointer));
	_adc(dx, 0);
	_add(ax, data.dword(k_dword_24694));
	_adc(dx, data.dword(k_dword_24694)[2]);
	// _out(6, al);
	al = ah;
	// _out(6, al);
	al = dl;
	// _out(0x82, al);
	ax = data.word(k_word_2460e);
	_dec(ax);
	// _out(7, al);
	al = ah;
	// _out(7, al);
	al = 3;
	// _out(0x0A, al);
	return;
loc_18830:
	al = 4;
	// _out(0x0D4, al);
	al = 0;
	// _out(0x0D8, al);
	al = data.byte(k_dma_mode);
	// _out(0x0D6, al);
	edx = data.dword(k_dma_buf_pointer)[2];
	_shl(edx, 4);
	eax = data.dword(k_dma_buf_pointer);
	_add(eax, edx);
	_add(eax, data.dword(k_dword_24694));
	_shr(eax, 1);
	// _out(0x0C0, al);
	al = ah;
	// _out(0x0C0, al);
	_shr(eax, 0x0F);
	// _out(0x8F, al);
	ax = data.word(k_word_2460e);
	_shr(ax, 1);
	_adc(ax, 0);
	_dec(ax);
	// _out(0x0C2, al);
	al = ah;
	// _out(0x0C2, al);
	al = 0;
	// _out(0x0D4, al);
	return;
loc_18878:
	al = 5;
	// _out(0x0D4, al);
	al = 0;
	// _out(0x0D8, al);
	al = data.byte(k_dma_mode);
	_or(al, 1);
	// _out(0x0D6, al);
	edx = data.dword(k_dma_buf_pointer)[2];
	_shl(edx, 4);
	eax = data.dword(k_dma_buf_pointer);
	_add(eax, edx);
	_add(eax, data.dword(k_dword_24694));
	_shr(eax, 1);
	// _out(0x0C4, al);
	al = ah;
	// _out(0x0C4, al);
	_shr(eax, 0x0F);
	// _out(0x8B, al);
	ax = data.word(k_word_2460e);
	_shr(ax, 1);
	_adc(ax, 0);
	_dec(ax);
	// _out(0x0C6, al);
	al = ah;
	// _out(0x0C6, al);
	al = 1;
	// _out(0x0D4, al);
	return;
loc_188c2:
	al = 6;
	// _out(0x0D4, al);
	al = 0;
	// _out(0x0D8, al);
	al = data.byte(k_dma_mode);
	_or(al, 2);
	// _out(0x0D6, al);
	edx = data.dword(k_dma_buf_pointer)[2];
	_shl(edx, 4);
	eax = data.dword(k_dma_buf_pointer);
	_add(eax, edx);
	_add(eax, data.dword(k_dword_24694));
	_shr(eax, 1);
	// _out(0x0C8, al);
	al = ah;
	// _out(0x0C8, al);
	_shr(eax, 0x0F);
	// _out(0x89, al);
	ax = data.word(k_word_2460e);
	_shr(ax, 1);
	_adc(ax, 0);
	_dec(ax);
	// _out(0x0CA, al);
	al = ah;
	// _out(0x0CA, al);
	al = 2;
	// _out(0x0D4, al);
	return;
loc_1890c:
	al = 7;
	// _out(0x0D4, al);
	al = data.byte(k_dma_mode);
	_or(al, 3);
	// _out(0x0D6, al);
	al = 0;
	// _out(0x0D8, al);
	edx = data.dword(k_dma_buf_pointer)[2];
	_shl(edx, 4);
	eax = data.dword(k_dma_buf_pointer);
	_add(eax, edx);
	_add(eax, data.dword(k_dword_24694));
	_shr(eax, 1);
	// _out(0x0CC, al);
	al = ah;
	// _out(0x0CC, al);
	_shr(eax, 0x0F);
	// _out(0x8A, al);
	ax = data.word(k_word_2460e);
	_shr(ax, 1);
	_adc(ax, 0);
	_dec(ax);
	// _out(0x0CE, al);
	al = ah;
	// _out(0x0CE, al);
	al = 3;
	// _out(0x0D4, al);
	return;
	return;
/*continuing to unbounded code: loc_186ef from _dma_186e3:4-251*/
loc_186ef:
	_cmp(cl, 1);
		_jz(loc_18761);
	_cmp(cl, 2);
		_jz(loc_187a6);
	_cmp(cl, 3);
		_jz(loc_187eb);
	_cmp(cl, 4);
		_jz(loc_18830);
	_cmp(cl, 5);
		_jz(loc_18878);
	_cmp(cl, 6);
		_jz(loc_188c2);
	_cmp(cl, 7);
		_jz(loc_1890c);
	al = 4;
	// _out(0x0A, al);
	al = 0;
	// _out(0x0C, al);
	al = data.byte(k_dma_mode);
	// _out(0x0B, al);
	dx = data.dword(k_dma_buf_pointer)[2];
	_rol(dx, 4);
	ax = dx;
	_and(al, 0x0F0);
	_and(dx, 0x0F);
	_add(ax, data.dword(k_dma_buf_pointer));
	_adc(dx, 0);
	_add(ax, data.dword(k_dword_24694));
	_adc(dx, data.dword(k_dword_24694)[2]);
	// _out(0, al);
	al = ah;
	// _out(0, al);
	al = dl;
	// _out(0x87, al);
	ax = data.word(k_word_2460e);
	_dec(ax);
	// _out(1, al);
	al = ah;
	// _out(1, al);
	al = 0;
	// _out(0x0A, al);
	return;
loc_18761:
	al = 5;
	// _out(0x0A, al);
	al = 0;
	// _out(0x0C, al);
	al = data.byte(k_dma_mode);
	_or(al, 1);
	// _out(0x0B, al);
	dx = data.dword(k_dma_buf_pointer)[2];
	_rol(dx, 4);
	ax = dx;
	_and(al, 0x0F0);
	_and(dx, 0x0F);
	_add(ax, data.dword(k_dma_buf_pointer));
	_adc(dx, 0);
	_add(ax, data.dword(k_dword_24694));
	_adc(dx, data.dword(k_dword_24694)[2]);
	// _out(2, al);
	al = ah;
	// _out(2, al);
	al = dl;
	// _out(0x83, al);
	ax = data.word(k_word_2460e);
	_dec(ax);
	// _out(3, al);
	al = ah;
	// _out(3, al);
	al = 1;
	// _out(0x0A, al);
	return;
loc_187a6:
	al = 6;
	// _out(0x0A, al);
	al = 0;
	// _out(0x0C, al);
	al = data.byte(k_dma_mode);
	_or(al, 2);
	// _out(0x0B, al);
	dx = data.dword(k_dma_buf_pointer)[2];
	_rol(dx, 4);
	ax = dx;
	_and(al, 0x0F0);
	_and(dx, 0x0F);
	_add(ax, data.dword(k_dma_buf_pointer));
	_adc(dx, 0);
	_add(ax, data.dword(k_dword_24694));
	_adc(dx, data.dword(k_dword_24694)[2]);
	// _out(4, al);
	al = ah;
	// _out(4, al);
	al = dl;
	// _out(0x81, al);
	ax = data.word(k_word_2460e);
	_dec(ax);
	// _out(5, al);
	al = ah;
	// _out(5, al);
	al = 2;
	// _out(0x0A, al);
	return;
loc_187eb:
	al = 7;
	// _out(0x0A, al);
	al = 0;
	// _out(0x0C, al);
	al = data.byte(k_dma_mode);
	_or(al, 3);
	// _out(0x0B, al);
	dx = data.dword(k_dma_buf_pointer)[2];
	_rol(dx, 4);
	ax = dx;
	_and(al, 0x0F0);
	_and(dx, 0x0F);
	_add(ax, data.dword(k_dma_buf_pointer));
	_adc(dx, 0);
	_add(ax, data.dword(k_dword_24694));
	_adc(dx, data.dword(k_dword_24694)[2]);
	// _out(6, al);
	al = ah;
	// _out(6, al);
	al = dl;
	// _out(0x82, al);
	ax = data.word(k_word_2460e);
	_dec(ax);
	// _out(7, al);
	al = ah;
	// _out(7, al);
	al = 3;
	// _out(0x0A, al);
	return;
loc_18830:
	al = 4;
	// _out(0x0D4, al);
	al = 0;
	// _out(0x0D8, al);
	al = data.byte(k_dma_mode);
	// _out(0x0D6, al);
	edx = data.dword(k_dma_buf_pointer)[2];
	_shl(edx, 4);
	eax = data.dword(k_dma_buf_pointer);
	_add(eax, edx);
	_add(eax, data.dword(k_dword_24694));
	_shr(eax, 1);
	// _out(0x0C0, al);
	al = ah;
	// _out(0x0C0, al);
	_shr(eax, 0x0F);
	// _out(0x8F, al);
	ax = data.word(k_word_2460e);
	_shr(ax, 1);
	_adc(ax, 0);
	_dec(ax);
	// _out(0x0C2, al);
	al = ah;
	// _out(0x0C2, al);
	al = 0;
	// _out(0x0D4, al);
	return;
loc_18878:
	al = 5;
	// _out(0x0D4, al);
	al = 0;
	// _out(0x0D8, al);
	al = data.byte(k_dma_mode);
	_or(al, 1);
	// _out(0x0D6, al);
	edx = data.dword(k_dma_buf_pointer)[2];
	_shl(edx, 4);
	eax = data.dword(k_dma_buf_pointer);
	_add(eax, edx);
	_add(eax, data.dword(k_dword_24694));
	_shr(eax, 1);
	// _out(0x0C4, al);
	al = ah;
	// _out(0x0C4, al);
	_shr(eax, 0x0F);
	// _out(0x8B, al);
	ax = data.word(k_word_2460e);
	_shr(ax, 1);
	_adc(ax, 0);
	_dec(ax);
	// _out(0x0C6, al);
	al = ah;
	// _out(0x0C6, al);
	al = 1;
	// _out(0x0D4, al);
	return;
loc_188c2:
	al = 6;
	// _out(0x0D4, al);
	al = 0;
	// _out(0x0D8, al);
	al = data.byte(k_dma_mode);
	_or(al, 2);
	// _out(0x0D6, al);
	edx = data.dword(k_dma_buf_pointer)[2];
	_shl(edx, 4);
	eax = data.dword(k_dma_buf_pointer);
	_add(eax, edx);
	_add(eax, data.dword(k_dword_24694));
	_shr(eax, 1);
	// _out(0x0C8, al);
	al = ah;
	// _out(0x0C8, al);
	_shr(eax, 0x0F);
	// _out(0x89, al);
	ax = data.word(k_word_2460e);
	_shr(ax, 1);
	_adc(ax, 0);
	_dec(ax);
	// _out(0x0CA, al);
	al = ah;
	// _out(0x0CA, al);
	al = 2;
	// _out(0x0D4, al);
	return;
loc_1890c:
	al = 7;
	// _out(0x0D4, al);
	al = data.byte(k_dma_mode);
	_or(al, 3);
	// _out(0x0D6, al);
	al = 0;
	// _out(0x0D8, al);
	edx = data.dword(k_dma_buf_pointer)[2];
	_shl(edx, 4);
	eax = data.dword(k_dma_buf_pointer);
	_add(eax, edx);
	_add(eax, data.dword(k_dword_24694));
	_shr(eax, 1);
	// _out(0x0CC, al);
	al = ah;
	// _out(0x0CC, al);
	_shr(eax, 0x0F);
	// _out(0x8A, al);
	ax = data.word(k_word_2460e);
	_shr(ax, 1);
	_adc(ax, 0);
	_dec(ax);
	// _out(0x0CE, al);
	al = ah;
	// _out(0x0CE, al);
	al = 3;
	// _out(0x0D4, al);
	return;
loc_186ef:
}

void InertiaPlayerContext::_set_dmachn_mask() {
	STACK_CHECK;
	al = cl;
	_cmp(al, 4);
		_jnc(loc_18961);
	_or(al, 4);
	// _out(0x0A, al);
	return;
loc_18961:
	_and(al, 3);
	_or(al, 4);
	// _out(0x0D4, al);
	return;
}

void InertiaPlayerContext::_alloc_dma_buf() {
	STACK_CHECK;
	data.dword(k_dword_24684) = eax;
	data.byte(k_byte_2469c) = cl;
	data.byte(k_memflg_2469a) = 0;
	data.byte(k_byte_2469b) = 0;
	data.dword(k_dword_24694) = 0;
	_getmemallocstrat();
	_push(ax);
	_setmemalloc2();
	ebx = data.dword(k_dword_24684);
	_shl(ebx, 1);
	_memalloc();
		_jc(loc_18a22);
	data.word(k_myseg_24698) = ax;
	dx = ax;
	ebx = data.dword(k_dword_24684);
	_cmp(data.byte(k_byte_2469c), 4);
		_jc(loc_189db);
	eax = ax;
	_shl(eax, 4);
	_and(eax, 0x1FFFF);
	_add(eax, ebx);
	_cmp(eax, 0x20000);
		_jbe(loc_18a0a);
	_sub(eax, ebx);
	_neg(eax);
	_add(eax, 0x20000);
	_add(ebx, eax);
	_and(dx, 0x0E000);
	_add(dh, 0x20);
	loc_18a0a;
loc_189db:
	eax = ax;
	_shl(eax, 4);
	_and(eax, 0x0FFFF);
	_add(eax, ebx);
	_cmp(eax, 0x10000);
		_jbe(loc_18a0a);
	_sub(eax, ebx);
	_neg(eax);
	_add(eax, 0x10000);
	_add(ebx, eax);
	_and(dx, 0x0F000);
	_add(dh, 0x10);
loc_18a0a:
	data.word(k_word_2468c) = dx;
	ax = data.word(k_myseg_24698);
	_memrealloc();
	_pop(ax);
	_setmemallocstrat();
	data.byte(k_memflg_2469a) = 1;
	ax = data.word(k_word_2468c);
	_write_cf(false);
 	return;
loc_18a22:
	_pop(ax);
	_setmemallocstrat();
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_189db from _alloc_dma_buf:31-58*/
loc_189db:
	eax = ax;
	_shl(eax, 4);
	_and(eax, 0x0FFFF);
	_add(eax, ebx);
	_cmp(eax, 0x10000);
		_jbe(loc_18a0a);
	_sub(eax, ebx);
	_neg(eax);
	_add(eax, 0x10000);
	_add(ebx, eax);
	_and(dx, 0x0F000);
	_add(dh, 0x10);
loc_18a0a:
	data.word(k_word_2468c) = dx;
	ax = data.word(k_myseg_24698);
	_memrealloc();
	_pop(ax);
	_setmemallocstrat();
	data.byte(k_memflg_2469a) = 1;
	ax = data.word(k_word_2468c);
	_write_cf(false);
 	return;
loc_18a22:
	_pop(ax);
	_setmemallocstrat();
	_write_cf(true);
 	return;
loc_189db:
}

void InertiaPlayerContext::_memfree_18a28() {
	STACK_CHECK;
	_cmp(data.byte(k_memflg_2469a), 1);
		_jnz(loc_18a3b);
	data.byte(k_memflg_2469a) = 0;
	ax = data.word(k_myseg_24698);
	_memfree();
	return;
loc_18a3b:
	_write_cf(false);
 	return;
	return;
/*continuing to unbounded code: loc_18a3b from _memfree_18a28:7-9*/
loc_18a3b:
	_write_cf(false);
 	return;
loc_18a3b:
}

	_pop(flags);
	return;
loc_18a5c:
}

	_pop(flags);
	return;
}

void InertiaPlayerContext::_getint_vect() {
	STACK_CHECK;
	_push(es);
	ah = 0x35;
	// _int(0x21);
	dx = es;
	_pop(es);
	return;
}

void InertiaPlayerContext::_setint_vect() {
	STACK_CHECK;
	_push(ds);
	ds = dx;
	dx = bx;
	ah = 0x25;
	// _int(0x21);
	_pop(ds);
	return;
}

void InertiaPlayerContext::_memalloc() {
	STACK_CHECK;
	_add(ebx, 0x0F);
	_shr(ebx, 4);
	_cmp(ebx, 0x10000);
		_jnc(loc_18ad9);
	ah = 0x48;
	// _int(0x21);
	return;
loc_18ad9:
	ax = 8;
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_18ad9 from _memalloc:8-11*/
loc_18ad9:
	ax = 8;
	_write_cf(true);
 	return;
loc_18ad9:
}

void InertiaPlayerContext::_memfree() {
	STACK_CHECK;
	_push(es);
	es = ax;
	ah = 0x49;
	// _int(0x21);
	_pop(es);
	return;
}

void InertiaPlayerContext::_memrealloc() {
	STACK_CHECK;
	_add(ebx, 0x0F);
	_shr(ebx, 4);
	_cmp(ebx, 0x10000);
		_jnc(loc_18aff);
	es = ax;
	ah = 0x4A;
	// _int(0x21);
	return;
loc_18aff:
	ax = 8;
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_18aff from _memrealloc:9-12*/
loc_18aff:
	ax = 8;
	_write_cf(true);
 	return;
loc_18aff:
}

void InertiaPlayerContext::_setmemallocstrat() {
	STACK_CHECK;
	_push(ax);
	bx = al;
	ax = 0x5801;
	// _int(0x21);
	_pop(bx);
	_shr(bx, 8);
	ax = 0x5803;
	// _int(0x21);
	return;
}

void InertiaPlayerContext::_getmemallocstrat() {
	STACK_CHECK;
	ax = 0x5800;
	// _int(0x21);
	_push(ax);
	ax = 0x5802;
	// _int(0x21);
	_pop(bx);
	ah = al;
	al = bl;
	return;
}

void InertiaPlayerContext::_setmemalloc1() {
	STACK_CHECK;
	_test(data.word(k_config_word), 1);
		_jz({ _setmemalloc2(); return; });
	ax = 0x181;
	{ _setmemallocstrat(); return; };
}

void InertiaPlayerContext::_setmemalloc2() {
	STACK_CHECK;
	ax = 1;
	{ _setmemallocstrat(); return; };
}

void InertiaPlayerContext::_writemixersb() {
	STACK_CHECK;
	_push(ax);
	_push(dx);
	dx = data.word(k_sb_base_port);
	_add(dl, 4);
	_xchg(al, ah);
	// _out(dx, al);
	$+2;
	$+2;
	_inc(dx);
	al = ah;
	// _out(dx, al);
	_pop(dx);
	_pop(ax);
	return;
}

void InertiaPlayerContext::_readmixersb() {
	STACK_CHECK;
	_push(dx);
	dx = data.word(k_sb_base_port);
	_add(dl, 4);
	al = ah;
	// _out(dx, al);
	$+2;
	$+2;
	_inc(dx);
	// _in(al, dx);
	_pop(dx);
	return;
}

void InertiaPlayerContext::_writesb() {
	STACK_CHECK;
	_push(dx);
	_push(cx);
	_push(ax);
	dx = data.word(k_sb_base_port);
	_add(dl, 0x0C);
	cx = 0x1000;
loc_18b70:
	// _in(al, dx);
	_or(al, al);
		_jns(loc_18b7c);
	_dec(cx);
		_jnz(loc_18b70);
	_pop(ax);
	_pop(cx);
	_pop(dx);
	return;
loc_18b7c:
	_pop(ax);
	// _out(dx, al);
	_pop(cx);
	_pop(dx);
	return;
	return;
/*continuing to unbounded code: loc_18b70 from _writesb:7-22*/
loc_18b70:
	// _in(al, dx);
	_or(al, al);
		_jns(loc_18b7c);
	_dec(cx);
		_jnz(loc_18b70);
	_pop(ax);
	_pop(cx);
	_pop(dx);
	return;
loc_18b7c:
	_pop(ax);
	// _out(dx, al);
	_pop(cx);
	_pop(dx);
	return;
loc_18b70:
}

void InertiaPlayerContext::_readsb() {
	STACK_CHECK;
	_push(dx);
	_push(cx);
	_push(ax);
	dx = data.word(k_sb_base_port);
	_add(dl, 0x0E);
	cx = 0x1000;
loc_18b8e:
	// _in(al, dx);
	_or(al, al);
		_js(loc_18b9c);
	_dec(cx);
		_jnz(loc_18b8e);
	_pop(ax);
	_pop(cx);
	_pop(dx);
	al = 0;
	return;
loc_18b9c:
	_pop(ax);
	_sub(dl, 4);
	// _in(al, dx);
	_pop(cx);
	_pop(dx);
	return;
	return;
/*continuing to unbounded code: loc_18b8e from _readsb:7-24*/
loc_18b8e:
	// _in(al, dx);
	_or(al, al);
		_js(loc_18b9c);
	_dec(cx);
		_jnz(loc_18b8e);
	_pop(ax);
	_pop(cx);
	_pop(dx);
	al = 0;
	return;
loc_18b9c:
	_pop(ax);
	_sub(dl, 4);
	// _in(al, dx);
	_pop(cx);
	_pop(dx);
	return;
loc_18b8e:
}

void InertiaPlayerContext::_checksb() {
	STACK_CHECK;
	dx = data.word(k_sb_base_port);
	_add(dl, 6);
	al = 1;
	// _out(dx, al);
	ax = 0x400;
loc_18bb1:
	_dec(ax);
		_jnz(loc_18bb1);
	// _out(dx, al);
	_readsb();
	_cmp(al, 0x0AA);
		_jnz(loc_18bbe);
	_write_cf(false);
 	return;
loc_18bbe:
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_18bb1 from _checksb:6-17*/
loc_18bb1:
	_dec(ax);
		_jnz(loc_18bb1);
	// _out(dx, al);
	_readsb();
	_cmp(al, 0x0AA);
		_jnz(loc_18bbe);
	_write_cf(false);
 	return;
loc_18bbe:
	_write_cf(true);
 	return;
loc_18bb1:
}

void InertiaPlayerContext::_sb16_sound_off() {
	STACK_CHECK;
	_checksb();
	al = 0x0D3;
	_writesb();
	return;
}

	_aad();
	_add(dx, ax);
	_mul(eax, edx, 60);
	_add(eax, ebx);
	edx = 1193180;
	_mul(edx);
	_shrd(eax, edx, 0x10);
	dx = 0;
	es = dx;
	es.dword(0x46C) = eax;
	return;
}

void InertiaPlayerContext::_u32tox() {
	STACK_CHECK;
	_ror(eax, 0x10);
	_u16tox();
	_ror(eax, 0x10);
}

void InertiaPlayerContext::_u16tox() {
	STACK_CHECK;
	_xchg(al, ah);
	_u8tox();
	al = ah;
}

void InertiaPlayerContext::_u8tox() {
	STACK_CHECK;
	_push(ax);
	_shr(al, 4);
	_u4tox();
	_pop(ax);
}

void InertiaPlayerContext::_u4tox() {
	STACK_CHECK;
	_and(al, 0x0F);
	_or(al, '0');
	_cmp(al, '9');
		_jbe(loc_18c3d);
	_add(al, 7);
loc_18c3d:
	ds.byte(si) = al;
	_inc(si);
	return;
	return;
/*continuing to unbounded code: loc_18c3d from _u4tox:6-9*/
loc_18c3d:
	ds.byte(si) = al;
	_inc(si);
	return;
loc_18c3d:
}

void InertiaPlayerContext::_my_i8toa10_0() {
	STACK_CHECK;
	_cbw();
}

void InertiaPlayerContext::_my_i16toa10_0() {
	STACK_CHECK;
	_cwde();
}

void InertiaPlayerContext::_my_i32toa10_0() {
	STACK_CHECK;
	cx = 0;
	_or(eax, eax);
		_jns(_my_i32toa10_1);
	dl = '-';
	_my_putdigit();
	_neg(eax);
	_my_i32toa10_1;
	return;
/*continuing to unbounded code: _my_i32toa10_1 from _my_u32toa10_0:2-3*/
_my_i32toa10_1:
	ebx = 10;
}

void InertiaPlayerContext::_my_u8toa_10() {
	STACK_CHECK;
	ah = 0;
}

void InertiaPlayerContext::_my_u16toa_10() {
	STACK_CHECK;
	eax = ax;
}

void InertiaPlayerContext::_my_u32toa10_0() {
	STACK_CHECK;
	cx = 0;
	ebx = 10;
}

void InertiaPlayerContext::_my_u32toa_0() {
	STACK_CHECK;
	edx = 0;
	_div(ebx);
	_or(eax, eax);
		_jz(loc_18c75);
	_push(edx);
	_my_u32toa_0();
	_pop(edx);
loc_18c75:
	_or(dl, '0');
	return;
/*continuing to unbounded code: loc_18c75 from _my_u32toa_0:8-9*/
loc_18c75:
	_or(dl, '0');
loc_18c75:
}

void InertiaPlayerContext::_my_putdigit() {
	STACK_CHECK;
	ds.byte(si) = dl;
	_inc(si);
	_inc(cx);
	return;
}

void InertiaPlayerContext::_myasmsprintf() {
	STACK_CHECK;
	_push(es);
	ax = ds;
	es = ax;
	loc_18ca2;
loc_18c9f:
	ds.byte(di) = al;
	_inc(di);
loc_18ca2:
	al = ds.byte(si);
	_inc(si);
	_cmp(al, 0x20);
		_jnc(loc_18c9f);
	_cmp(al, 0x0C);
		_ja(_mysprintf_0_nop);
	_inc(si);
	bl = al;
	bh = 0;
	_shl(bx, 1);
	cs:_asmprintf_tbl[bx];
_mysprintf_0_nop:
	_pop(es);
	return;
	_push(si);
	si = ds.word(si);
	_strcpy_count_0();
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	bx = ds.word(si);
	bl = ds.byte(bx);
	bh = 0;
	loc_18cd3;
	bx = ds.word(si);
	bx = ds.word(bx);
loc_18cd3:
	_push(si);
	_shl(bx, 1);
	si = ds.word(si+2);
	si = ds.word(bx+si);
	_strcpy_count_0();
	_pop(si);
	_add(si, 4);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	al = ds.byte(si);
	si = di;
	_my_u8toa_10();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	ax = ds.word(si);
	si = di;
	_my_u16toa_10();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	eax = ds.dword(si);
	si = di;
	_my_u32toa10_0();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	al = ds.byte(si);
	si = di;
	_my_i8toa10_0();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	ax = ds.word(si);
	si = di;
	_my_i16toa10_0();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	eax = ds.dword(si);
	si = di;
	_my_i32toa10_0();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	al = ds.byte(si);
	si = di;
	_u8tox();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	ax = ds.word(si);
	si = di;
	_u16tox();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	eax = ds.dword(si);
	si = di;
	_u32tox();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	return;
/*continuing to unbounded code: loc_18c9f from _myasmsprintf:5-136*/
loc_18c9f:
	ds.byte(di) = al;
	_inc(di);
loc_18ca2:
	al = ds.byte(si);
	_inc(si);
	_cmp(al, 0x20);
		_jnc(loc_18c9f);
	_cmp(al, 0x0C);
		_ja(_mysprintf_0_nop);
	_inc(si);
	bl = al;
	bh = 0;
	_shl(bx, 1);
	cs:_asmprintf_tbl[bx];
_mysprintf_0_nop:
	_pop(es);
	return;
	_push(si);
	si = ds.word(si);
	_strcpy_count_0();
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	bx = ds.word(si);
	bl = ds.byte(bx);
	bh = 0;
	loc_18cd3;
	bx = ds.word(si);
	bx = ds.word(bx);
loc_18cd3:
	_push(si);
	_shl(bx, 1);
	si = ds.word(si+2);
	si = ds.word(bx+si);
	_strcpy_count_0();
	_pop(si);
	_add(si, 4);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	al = ds.byte(si);
	si = di;
	_my_u8toa_10();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	ax = ds.word(si);
	si = di;
	_my_u16toa_10();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	eax = ds.dword(si);
	si = di;
	_my_u32toa10_0();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	al = ds.byte(si);
	si = di;
	_my_i8toa10_0();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	ax = ds.word(si);
	si = di;
	_my_i16toa10_0();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	eax = ds.dword(si);
	si = di;
	_my_i32toa10_0();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	al = ds.byte(si);
	si = di;
	_u8tox();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	ax = ds.word(si);
	si = di;
	_u16tox();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
	_push(si);
	si = ds.word(si);
	eax = ds.dword(si);
	si = di;
	_u32tox();
	di = si;
	_pop(si);
	_add(si, 2);
	loc_18ca2;
loc_18c9f:
}

void InertiaPlayerContext::_mystrlen_0() {
	STACK_CHECK;
	ax = -1;
	_dec(si);
loc_18d93:
	_inc(ax);
	_inc(si);
	_cmp(ds.byte(si), 0);
		_jnz(loc_18d93);
	_sub(si, ax);
	return;
	return;
/*continuing to unbounded code: loc_18d93 from _mystrlen_0:3-9*/
loc_18d93:
	_inc(ax);
	_inc(si);
	_cmp(ds.byte(si), 0);
		_jnz(loc_18d93);
	_sub(si, ax);
	return;
loc_18d93:
}

void InertiaPlayerContext::_strcpy_count_0() {
	STACK_CHECK;
	cx = 0;
	loc_18da6;
loc_18da1:
	es.byte(di) = al;
	_inc(si);
	_inc(di);
loc_18da6:
	al = ds.byte(si);
	_inc(cx);
	_or(al, al);
		_jnz(loc_18da1);
	return;
	return;
/*continuing to unbounded code: loc_18da1 from _strcpy_count_0:3-12*/
loc_18da1:
	es.byte(di) = al;
	_inc(si);
	_inc(di);
loc_18da6:
	al = ds.byte(si);
	_inc(cx);
	_or(al, al);
		_jnz(loc_18da1);
	return;
loc_18da1:
}

void InertiaPlayerContext::_dosgetcurdir() {
	STACK_CHECK;
	_push(si);
	ah = 0x19;
	// _int(0x21);
	_pop(si);
	ds.byte(si) = al;
	ds.byte(si+1) = '\\';
	_add(si, 2);
	dl = 0;
	ah = 0x47;
	// _int(0x21);
	return;
}

void InertiaPlayerContext::_doschdir() {
	STACK_CHECK;
	dl = ds.byte(si);
	_inc(si);
	_push(si);
	ah = 0x0E;
	// _int(0x21);
	_pop(dx);
	ah = 0x3B;
	// _int(0x21);
	return;
}

void InertiaPlayerContext::_filelist_198b8() {
	STACK_CHECK;
	_write_df(false);
 	ax = data.word(k_word_1de5e);
	_cmp(ax, data.word(k_word_1de60));
		_jz(_recolortxtx);
	data.word(k_word_1de60) = ax;
	cx = data.word(k_word_1de54);
	_sub(cx, data.word(k_word_1de5e));
	_cmp(cx, 0x0F);
		_jc(loc_198d5);
	cx = 0x0F;
loc_198d5:
	ax = data.word(k_word_1de5e);
	dx = ax;
	_shl(ax, 1);
	_add(ax, dx);
	_add(ax, data.word(k_word_1de52));
	fs = ax;
	ax = (80*10+10)*2;
loc_198e7:
	_push(ax);
	_push(cx);
	di = data.word(k_videomempointer);
	_add(di, ax);
	bp = di;
	ah = 0x7E;
	_cmp(fs.byte(2), 2);
		_jz(loc_198fd);
	ah = 0x7B;
loc_198fd:
	si = 0x0C;
	cx = 0x0C;
loc_19903:
	al = fs.byte(si);
	_or(al, al);
		_jz(loc_19914);
	es.word(di) = ax;
	_inc(si);
	_add(di, 2);
	_dec(cx);
		_jnz(loc_19903);
loc_19914:
	ax = 0x7E20;
	_write_df(false);
 	_stosw(cx, true);
	_cmp(fs.byte(2), 2);
		_jz(loc_1992a);
	cx = 51;
	_stosw(cx, true);
	loc_199e7;
loc_1992a:
	_push(bp);
	ax = ds;
	es = ax;
	di = 2571;
	bp = 8;
	eax = fs.dword(8);
	_my_u32toa_fill();
	ax = fs.word(6);
	_and(al, 0x1F);
	eax = al;
	bp = 3;
	_my_u32toa_fill();
	ds.byte(di) = '-';
	_inc(di);
	ax = fs.word(6);
	_shr(ax, 5);
	_and(eax, 0x0F);
	si = data.byte(k_ajanfebmaraprmayj)[eax+eax*2];
	_write_df(false);
 	_movsw();
	_movsb();
	ds.byte(di) = '-';
	_inc(di);
	eax = fs.word(6);
	_shr(ax, 9);
	_add(ax, 1980);
	bp = 4;
	_my_u32toa_fill();
	ds.byte(di) = ' ';
	_inc(di);
	ax = fs.word(4);
	_shr(ax, 0x0B);
	dl = 10;
	_div(dl);
	_or(ax, 0x3030);
	ds.word(di) = ax;
	ds.byte(di+2) = ':';
	ax = fs.word(4);
	_shr(ax, 5);
	_and(ax, 0x3F);
	_div(dl);
	_or(ax, 0x3030);
	ds.word(di+3) = ax;
	ds.word(di+5) = ' ';
	_pop(bp);
	si = 2571;
	es = data.word(k_videomempointer)[2];
	di = ds.word(bp+0x18);
	ah = 0x7F;
	_text_1bf69();
	_test(fs.byte(3), 0x40);
		_jz(loc_199cf);
	si = 2266;
	ah = 0x7F;
	_text_1bf69();
	loc_199e7;
loc_199cf:
	ah = 0x7E;
	si = 0x1A;
loc_199d4:
	al = fs.byte(si);
	_or(al, al);
		_jz(loc_199e7);
	es.word(di) = ax;
	_inc(si);
	_add(di, 2);
	_cmp(si, 0x30);
		_jc(loc_199d4);
loc_199e7:
	ax = fs;
	_add(ax, 3);
	fs = ax;
	_pop(cx);
	_pop(ax);
	_add(ax, 0x0A0);
	_dec(cx);
		_jnz(loc_198e7);
	return;
	return;
/*continuing to unbounded code: loc_198d5 from _filelist_198b8:11-134*/
loc_198d5:
	ax = data.word(k_word_1de5e);
	dx = ax;
	_shl(ax, 1);
	_add(ax, dx);
	_add(ax, data.word(k_word_1de52));
	fs = ax;
	ax = (80*10+10)*2;
loc_198e7:
	_push(ax);
	_push(cx);
	di = data.word(k_videomempointer);
	_add(di, ax);
	bp = di;
	ah = 0x7E;
	_cmp(fs.byte(2), 2);
		_jz(loc_198fd);
	ah = 0x7B;
loc_198fd:
	si = 0x0C;
	cx = 0x0C;
loc_19903:
	al = fs.byte(si);
	_or(al, al);
		_jz(loc_19914);
	es.word(di) = ax;
	_inc(si);
	_add(di, 2);
	_dec(cx);
		_jnz(loc_19903);
loc_19914:
	ax = 0x7E20;
	_write_df(false);
 	_stosw(cx, true);
	_cmp(fs.byte(2), 2);
		_jz(loc_1992a);
	cx = 51;
	_stosw(cx, true);
	loc_199e7;
loc_1992a:
	_push(bp);
	ax = ds;
	es = ax;
	di = 2571;
	bp = 8;
	eax = fs.dword(8);
	_my_u32toa_fill();
	ax = fs.word(6);
	_and(al, 0x1F);
	eax = al;
	bp = 3;
	_my_u32toa_fill();
	ds.byte(di) = '-';
	_inc(di);
	ax = fs.word(6);
	_shr(ax, 5);
	_and(eax, 0x0F);
	si = data.byte(k_ajanfebmaraprmayj)[eax+eax*2];
	_write_df(false);
 	_movsw();
	_movsb();
	ds.byte(di) = '-';
	_inc(di);
	eax = fs.word(6);
	_shr(ax, 9);
	_add(ax, 1980);
	bp = 4;
	_my_u32toa_fill();
	ds.byte(di) = ' ';
	_inc(di);
	ax = fs.word(4);
	_shr(ax, 0x0B);
	dl = 10;
	_div(dl);
	_or(ax, 0x3030);
	ds.word(di) = ax;
	ds.byte(di+2) = ':';
	ax = fs.word(4);
	_shr(ax, 5);
	_and(ax, 0x3F);
	_div(dl);
	_or(ax, 0x3030);
	ds.word(di+3) = ax;
	ds.word(di+5) = ' ';
	_pop(bp);
	si = 2571;
	es = data.word(k_videomempointer)[2];
	di = ds.word(bp+0x18);
	ah = 0x7F;
	_text_1bf69();
	_test(fs.byte(3), 0x40);
		_jz(loc_199cf);
	si = 2266;
	ah = 0x7F;
	_text_1bf69();
	loc_199e7;
loc_199cf:
	ah = 0x7E;
	si = 0x1A;
loc_199d4:
	al = fs.byte(si);
	_or(al, al);
		_jz(loc_199e7);
	es.word(di) = ax;
	_inc(si);
	_add(di, 2);
	_cmp(si, 0x30);
		_jc(loc_199d4);
loc_199e7:
	ax = fs;
	_add(ax, 3);
	fs = ax;
	_pop(cx);
	_pop(ax);
	_add(ax, 0x0A0);
	_dec(cx);
		_jnz(loc_198e7);
	return;
loc_198d5:
}

void InertiaPlayerContext::_recolortxt() {
	STACK_CHECK;
	_mul(di, ax, 80*2);
	_add(di, (80*2*10)+(8*2)+1);
	cx = 64;
loc_19a04:
	al = es.byte(di);
	_and(al, 0x0F);
	_or(al, bl);
	es.byte(di) = al;
	_add(di, 2);
	_dec(cx);
		_jnz(loc_19a04);
	return;
	return;
/*continuing to unbounded code: loc_19a04 from _recolortxt:4-12*/
loc_19a04:
	al = es.byte(di);
	_and(al, 0x0F);
	_or(al, bl);
	es.byte(di) = al;
	_add(di, 2);
	_dec(cx);
		_jnz(loc_19a04);
	return;
loc_19a04:
}

void InertiaPlayerContext::_cpy_printable() {
	STACK_CHECK;
	_push(si);
	_push(di);
loc_19a17:
	al = ds.byte(si);
	_inc(si);
	_cmp(al, ' ');
		_jc(loc_19a25);
	es.byte(di) = al;
	_inc(di);
	_dec(cx);
		_jnz(loc_19a17);
loc_19a25:
	_write_df(false);
 	al = ' ';
	_stosb(cx, true);
	_pop(di);
	_pop(si);
	return;
	return;
/*continuing to unbounded code: loc_19a17 from _cpy_printable:3-19*/
loc_19a17:
	al = ds.byte(si);
	_inc(si);
	_cmp(al, ' ');
		_jc(loc_19a25);
	es.byte(di) = al;
	_inc(di);
	_dec(cx);
		_jnz(loc_19a17);
loc_19a25:
	_write_df(false);
 	al = ' ';
	_stosb(cx, true);
	_pop(di);
	_pop(si);
	return;
loc_19a17:
}

	_pop(flags);
		_jc(loc_19c86);
	si = 2348;
	cx = 0x16;
	_cmp(ebp, 0x524E492E);
		_jz(loc_19c80);
	si = 2347;
	cx = 0x16;
	_cmp(ebp, 0x544C552E);
		_jz(loc_19c80);
	si = 2336;
	cx = 0x16;
	_cmp(ebp, 0x4D544D2E);
		_jz(loc_19c80);
	_cmp(ebp, 0x4D53502E);
		_jz(loc_19c80);
	_cmp(ebp, 0x5241462E);
		_jz(loc_19c80);
	_cmp(ebp, 0x3936362E);
		_jz(loc_19c71);
	si = 2348;
	cx = 0x16;
	_cmp(ebp, 0x5353542E);
		_jz(loc_19c80);
	si = 2332;
	cx = 0x16;
	ds.word(si+0x14) = 0x2020;
	loc_19c80;
loc_19c71:
	si = ( data.dword(k_buffer_1dc6c)+1);
	cx = 0x54;
loc_19c77:
	_inc(si);
	_cmp(ds.byte(si), ' ');
	if (--cx && flags.z())
		loc_19c77;
	cx = 0x16;
loc_19c80:
	di = 0x1A;
	_cpy_printable();
loc_19c86:
	ax = es;
	_add(ax, 3);
	es = ax;
	_inc(data.word(k_word_1de54));
	_cmp(data.word(k_word_1de54), 0x52B);
		_jnc(loc_19ca2);
loc_19c99:
	_push(es);
	_dosfindnext();
	_pop(es);
		_jnc(loc_19b3c);
loc_19ca2:
	ah = 0x19;
	// _int(0x21);
	_push(ax);
	dl = 0;
loc_19ca9:
	_push(dx);
	ah = 0x0E;
	// _int(0x21);
	ah = 0x19;
	// _int(0x21);
	_pop(dx);
	_cmp(al, dl);
		_jnz(loc_19cdf);
	eax = 0x5D3A415B;
	_add(ah, dl);
	es.dword(0x0C) = eax;
	es.byte(0x10) = 0;
	es.byte(2) = 1;
	_inc(data.word(k_word_1de5a));
	ax = es;
	_add(ax, 3);
	es = ax;
	_inc(data.word(k_word_1de54));
loc_19cdf:
	_inc(dl);
	_cmp(dl, 0x1A);
		_jc(loc_19ca9);
	_pop(dx);
	ah = 0x0E;
	// _int(0x21);
	es = data.word(k_word_1de52);
	ax = data.word(k_word_1de54);
	bx = ax;
	_shl(ax, 1);
	_add(bx, ax);
	ah = 0x4A;
	// _int(0x21);
	_write_cf(false);
 	return;
loc_19a6e:
}

void InertiaPlayerContext::_parse_cmdline() {
	STACK_CHECK;
	ax = ds;
	es = ax;
	ebp = 0;
	ds = data.word(k_esseg_atstart);
	si = 0x80;
	di = 2300;
	dl = 0;
	_write_df(false);
 	_lodsb();
	cx = al;
	_write_cf(true);
 	if (cx==0)
		loc_19d64;
loc_19d19:
	_lodsb();
	_cmp(al, 0x0D);
		_jz(loc_19d63);
	_or(al, al);
		_jz(loc_19d63);
	_cmp(al, ' ');
		_jnz(loc_19d4e);
	_dec(cx);
		_jnz(loc_19d19);
	_write_cf(true);
 	loc_19d64;
loc_19d2c:
	_lodsb();
	_cmp(al, 0x0D);
		_jz(loc_19d63);
	_or(al, al);
		_jz(loc_19d63);
	_cmp(al, '?');
		_jz(loc_19d47);
	_and(al, 0x0DF);
	_sub(al, 'A');
	eax = al;
	flags.c() = (ebp >> eax) & 1; ebp |= 1 << eax;
	loc_19d19;
loc_19d47:
	flags.c() = (ebp >> 0x1F) & 1; ebp |= 1 << 0x1F;
	loc_19d19;
loc_19d4e:
	_cmp(al, '/');
		_jz(loc_19d2c);
	_stosb();
	_lodsb();
	_cmp(al, 0x0D);
		_jz(loc_19d63);
	_or(al, al);
		_jz(loc_19d63);
	_cmp(al, ' ');
		_jz(loc_19d63);
	if (--cx)
		loc_19d4e;
	_stosb();
loc_19d63:
	_write_cf(false);
 loc_19d64:
	es.byte(di) = 0;
	ax = es;
	ds = ax;
	return;
	return;
/*continuing to unbounded code: loc_19d19 from _parse_cmdline:13-60*/
loc_19d19:
	_lodsb();
	_cmp(al, 0x0D);
		_jz(loc_19d63);
	_or(al, al);
		_jz(loc_19d63);
	_cmp(al, ' ');
		_jnz(loc_19d4e);
	_dec(cx);
		_jnz(loc_19d19);
	_write_cf(true);
 	loc_19d64;
loc_19d2c:
	_lodsb();
	_cmp(al, 0x0D);
		_jz(loc_19d63);
	_or(al, al);
		_jz(loc_19d63);
	_cmp(al, '?');
		_jz(loc_19d47);
	_and(al, 0x0DF);
	_sub(al, 'A');
	eax = al;
	flags.c() = (ebp >> eax) & 1; ebp |= 1 << eax;
	loc_19d19;
loc_19d47:
	flags.c() = (ebp >> 0x1F) & 1; ebp |= 1 << 0x1F;
	loc_19d19;
loc_19d4e:
	_cmp(al, '/');
		_jz(loc_19d2c);
	_stosb();
	_lodsb();
	_cmp(al, 0x0D);
		_jz(loc_19d63);
	_or(al, al);
		_jz(loc_19d63);
	_cmp(al, ' ');
		_jz(loc_19d63);
	if (--cx)
		loc_19d4e;
	_stosb();
loc_19d63:
	_write_cf(false);
 loc_19d64:
	es.byte(di) = 0;
	ax = es;
	ds = ax;
	return;
loc_19d19:
}

void InertiaPlayerContext::_readallmoules() {
	STACK_CHECK;
	dx = 2300;
	_read_module();
		_jc(loc_19d83);
	_cmp(data.word(k_word_1de50), 1);
		_jz(loc_19d81);
	_dosfindnext();
		_jnc({ _readallmoules(); return; });
loc_19d81:
	_write_cf(false);
 	return;
loc_19d83:
	data.byte(k_byte_1de7e) = 3;
	data.word(k_messagepointer) = 2274;
	data.word(k_messagepointer)[2] = ds;
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_19d81 from _readallmoules:9-17*/
loc_19d81:
	_write_cf(false);
 	return;
loc_19d83:
	data.byte(k_byte_1de7e) = 3;
	data.word(k_messagepointer) = 2274;
	data.word(k_messagepointer)[2] = ds;
	_write_cf(true);
 	return;
loc_19d81:
}

void InertiaPlayerContext::_read_module() {
	STACK_CHECK;
	data.byte(k_byte_1de7e) = 3;
	data.word(k_messagepointer) = 2274;
	data.word(k_messagepointer)[2] = ds;
	si = dx;
loc_19e22:
	_inc(si);
	_cmp(ds.byte(si-1), 0);
		_jnz(loc_19e22);
	cx = 0x0C;
loc_19e2c:
	_dec(si);
	_cmp(ds.byte(si-1), ':');
		_jz(loc_19e41);
	_cmp(ds.byte(si-1), '\\');
		_jz(loc_19e41);
	_cmp(si, dx);
		_jbe(loc_19e41);
	_dec(cx);
		_jnz(loc_19e2c);
	_dec(si);
loc_19e41:
	di = 1558;
	cx = 0x0C;
loc_19e47:
	al = ds.byte(si);
	_inc(si);
	_or(al, al);
		_jz(loc_19e5e);
	_cmp(al, 'a');
		_jc(loc_19e58);
	_cmp(al, 'z');
		_ja(loc_19e58);
	_and(al, 0x0DF);
loc_19e58:
	ds.byte(di) = al;
	_inc(di);
	_dec(cx);
		_jnz(loc_19e47);
loc_19e5e:
	ax = ds;
	es = ax;
	al = ' ';
	_write_df(false);
 	_stosb(cx, true);
	_moduleread();
		_jc(loc_1a042);
	data.word(k_current_patterns) = 0;
	data.byte(k_byte_1de84) = 0;
	sub_126a9();
	data.byte(k_module_type_txt) = eax;
	ch = 0;
	data.word(k_amount_of_x) = cx;
	data.byte(k_byte_1de73) = bl;
	_read_sndsettings();
	data.word(k_outp_freq) = bp;
	sub_1265d();
	data.byte(k_byte_1de78) = dl;
	al = dh;
	_and(al, 0x10);
	_shr(al, 4);
	data.byte(k_byte_1de7b) = al;
	data.dword(k_segfsbx_1de28) = si;
	data.dword(k_segfsbx_1de28)[2] = es;
	si = di;
	di = 1549;
	cx = 30;
loc_19eba:
	al = es.byte(si);
	_or(al, al);
		_jz(loc_19ec7);
	ds.byte(di) = al;
	_inc(si);
	_inc(di);
	if (--cx)
		loc_19eba;
loc_19ec7:
	cx = 17;
	si = 0;
loc_19ecc:
	al = es.byte(si);
	data.byte(k_a130295211558)[si] = al;
	_inc(si);
	if (--cx)
		loc_19ecc;
	_video_prp_mtr_positn();
	edx = 0;
	eax = 317;
	ebx = data.word(k_amount_of_x);
	_div(ebx);
	data.dword(k_volume_1de34) = eax;
	data.byte(k_byte_1de7c) = 0;
	sub_12eba();
	return;
/*continuing to unbounded code: loc_19e22 from _read_module:5-91*/
loc_19e22:
	_inc(si);
	_cmp(ds.byte(si-1), 0);
		_jnz(loc_19e22);
	cx = 0x0C;
loc_19e2c:
	_dec(si);
	_cmp(ds.byte(si-1), ':');
		_jz(loc_19e41);
	_cmp(ds.byte(si-1), '\\');
		_jz(loc_19e41);
	_cmp(si, dx);
		_jbe(loc_19e41);
	_dec(cx);
		_jnz(loc_19e2c);
	_dec(si);
loc_19e41:
	di = 1558;
	cx = 0x0C;
loc_19e47:
	al = ds.byte(si);
	_inc(si);
	_or(al, al);
		_jz(loc_19e5e);
	_cmp(al, 'a');
		_jc(loc_19e58);
	_cmp(al, 'z');
		_ja(loc_19e58);
	_and(al, 0x0DF);
loc_19e58:
	ds.byte(di) = al;
	_inc(di);
	_dec(cx);
		_jnz(loc_19e47);
loc_19e5e:
	ax = ds;
	es = ax;
	al = ' ';
	_write_df(false);
 	_stosb(cx, true);
	_moduleread();
		_jc(loc_1a042);
	data.word(k_current_patterns) = 0;
	data.byte(k_byte_1de84) = 0;
	sub_126a9();
	data.byte(k_module_type_txt) = eax;
	ch = 0;
	data.word(k_amount_of_x) = cx;
	data.byte(k_byte_1de73) = bl;
	_read_sndsettings();
	data.word(k_outp_freq) = bp;
	sub_1265d();
	data.byte(k_byte_1de78) = dl;
	al = dh;
	_and(al, 0x10);
	_shr(al, 4);
	data.byte(k_byte_1de7b) = al;
	data.dword(k_segfsbx_1de28) = si;
	data.dword(k_segfsbx_1de28)[2] = es;
	si = di;
	di = 1549;
	cx = 30;
loc_19eba:
	al = es.byte(si);
	_or(al, al);
		_jz(loc_19ec7);
	ds.byte(di) = al;
	_inc(si);
	_inc(di);
	if (--cx)
		loc_19eba;
loc_19ec7:
	cx = 17;
	si = 0;
loc_19ecc:
	al = es.byte(si);
	data.byte(k_a130295211558)[si] = al;
	_inc(si);
	if (--cx)
		loc_19ecc;
	_video_prp_mtr_positn();
	edx = 0;
	eax = 317;
	ebx = data.word(k_amount_of_x);
	_div(ebx);
	data.dword(k_volume_1de34) = eax;
	data.byte(k_byte_1de7c) = 0;
	sub_12eba();
loc_19e22:
}

void InertiaPlayerContext::_keyb_19efd() {
	STACK_CHECK;
	sub_1265d();
	data.byte(k_byte_1de72) = ah;
	data.byte(k_byte_1de74) = al;
	data.byte(k_byte_1de75) = bh;
	data.byte(k_byte_1de76) = ch;
	ax = -1;
	_change_volume();
	data.word(k_word_1de6a) = ax;
	ax = -1;
	_change_amplif();
	data.word(k_word_1de6c) = ax;
	_get_playsettings();
	data.byte(k_flg_play_settings) = al;
	_cmp(data.byte(k_byte_1de7c), 1);
		_jz(loc_1a393);
	_test(data.byte(k_byte_1de90), 2);
		_jnz(loc_1a3c5);
	_test(data.byte(k_byte_1de90), 1);
		_jnz(loc_1a3a7);
	ax = 0;
	_xchg(ax, data.word(k_key_code));
	_or(ax, ax);
		_jz({ _keyb_19EFD(); return; });
	data.word(k_word_1de50) = ax;
	cx = 2;
	_cmp(ax, 0x0E04D);
		_jz(_l_1a044);
	cx = 10;
	_cmp(ax, 0x0E048);
		_jz(_l_1a044);
	cx = 2;
	_cmp(ax, 0x0E04B);
		_jz(loc_1a070);
	ecx = 10;
	_cmp(ax, 0x0E050);
		_jz(loc_1a070);
	_cmp(al, 0x4D);
		_jz(_l_right);
	_cmp(al, 0x48);
		_jz(_l_up);
	_cmp(al, 0x4B);
		_jz(_l_left);
	_cmp(al, 0x50);
		_jz(_l_down);
	_cmp(al, 0x4E);
		_jz(_l_plus);
	_cmp(al, 0x4A);
		_jz(_l_minus);
	_cmp(al, 0x1A);
		_jz(_l_lbracket);
	_cmp(al, 0x1B);
		_jz(_l_rbracket);
	_cmp(al, 0x3B);
		_jz(_l_f1);
	_cmp(al, 0x3C);
		_jz(_l_f2);
	_cmp(al, 0x3D);
		_jz(_l_f3);
	_cmp(al, 0x3E);
		_jz(_l_f4);
	_cmp(al, 0x3F);
		_jz(_l_f5);
	_cmp(al, 0x40);
		_jz(_l_f6);
	_cmp(al, 0x42);
		_jz(_l_f8);
	_cmp(al, 0x43);
		_jz(_l_f9);
	_cmp(al, 0x44);
		_jz(_l_f10);
	_cmp(al, 0x57);
		_jz(_l_f11);
	_cmp(al, 0x58);
		_jz(_l_f12);
	_cmp(al, 0x26);
		_jz(_l_l);
	_cmp(al, 0x32);
		_jz(_l_m);
	_cmp(al, 0x13);
		_jz(_l_r);
	_cmp(al, 0x1F);
		_jz(_l_s);
	_cmp(al, 0x0F);
		_jz(_l_tab);
	_cmp(al, 0x45);
		_jz(_l_numlock);
	_cmp(al, 0x46);
		_jz(_l_scrollock);
	_cmp(al, 0x4F);
		_jz(_l_1_end);
	_cmp(al, 0x1C);
		_jz(_l_enter);
	_cmp(al, 1);
		_jz(_l_esc);
		_jc({ _keyb_19EFD(); return; });
	_cmp(al, 0x0B);
		_jbe(loc_1a33e);
	{ _keyb_19EFD(); return; };
	_write_cf(true);
 	return;
_l_1a044:
	_push(cx);
	_get_12f7c();
	_and(bx, 0x3F);
	eax = ax;
	_shl(eax, 6);
	_or(al, bl);
	_inc(eax);
	bl = al;
	_and(bl, 0x3F);
	_shr(eax, 6);
	bh = 1;
	sub_12f56();
	_pop(cx);
	_dec(cx);
		_jnz(_l_1a044);
	{ _keyb_19EFD(); return; };
loc_1a070:
	_push(cx);
	_get_12f7c();
	_and(bx, 0x3F);
	eax = ax;
	_shl(eax, 6);
	_or(al, bl);
	_sub(eax, 1);
		_jc(loc_1a0a0);
	bl = al;
	_and(bl, 0x3F);
	_shr(eax, 6);
	bh = 1;
	sub_12f56();
	_pop(cx);
	_dec(cx);
		_jnz(loc_1a070);
	{ _keyb_19EFD(); return; };
loc_1a0a0:
	_pop(cx);
	{ _keyb_19EFD(); return; };
_l_up:
	_sub(data.byte(k_byte_1de84), 1);
		_jnc({ _keyb_19EFD(); return; });
	data.byte(k_byte_1de84) = 0;
	{ _keyb_19EFD(); return; };
_l_down:
	_inc(data.byte(k_byte_1de84));
	ax = data.word(k_amount_of_x);
	_cmp(data.byte(k_byte_1de84), al);
		_jc({ _keyb_19EFD(); return; });
	_dec(al);
	data.byte(k_byte_1de84) = al;
	{ _keyb_19EFD(); return; };
_l_right:
	bx = data.dword(k_segfsbx_1de28);
	al = 0x50;
	_mul(data.byte(k_byte_1de84));
	_add(bx, ax);
	cl = 8;
	_test(data.word(k_keyb_switches), 3);
		_jnz(loc_1a0e6);
	cl = 1;
loc_1a0e6:
	al = fs.byte(bx+0x3A);
	_add(al, cl);
	_cmp(al, 0x80);
		_jbe(loc_1a0f2);
	al = 0x80;
loc_1a0f2:
	ch = data.byte(k_byte_1de84);
	sub_12afd();
	{ _keyb_19EFD(); return; };
_l_left:
	bx = data.dword(k_segfsbx_1de28);
	al = 0x50;
	_mul(data.byte(k_byte_1de84));
	_add(bx, ax);
	cl = 8;
	_test(data.word(k_keyb_switches), 3);
		_jnz(loc_1a118);
	cl = 1;
loc_1a118:
	al = fs.byte(bx+0x3A);
	_sub(al, cl);
		_jnc(loc_1a0f2);
	al = 0;
	loc_1a0f2;
_l_l:
	al = 0;
	loc_1a0f2;
_l_m:
	al = 64;
	loc_1a0f2;
_l_r:
	al = 128;
	loc_1a0f2;
_l_s:
	al = 166;
	loc_1a0f2;
_l_plus:
	ax = -1;
	_change_volume();
	cx = 32;
	_test(data.word(k_keyb_switches), 3);
		_jnz(loc_1a14b);
	cx = 2;
loc_1a14b:
	_add(ax, cx);
	_cmp(ax, 256);
		_jc(loc_1a155);
	ax = 256;
loc_1a155:
	_change_volume();
	{ _keyb_19EFD(); return; };
_l_minus:
	ax = -1;
	_change_volume();
	cx = 32;
	_test(data.word(k_keyb_switches), 3);
		_jnz(loc_1a174);
	cx = 2;
loc_1a174:
	_sub(ax, cx);
		_jnc(loc_1a17a);
	ax = 0;
loc_1a17a:
	_change_volume();
	{ _keyb_19EFD(); return; };
_l_rbracket:
	ax = 0x0FFFF;
	_change_amplif();
	cx = 1;
	_test(data.word(k_keyb_switches), 3);
		_jnz(loc_1a199);
	cx = 0x0A;
loc_1a199:
	_add(ax, cx);
	_cmp(ax, 2500);
		_jc(loc_1a1a3);
	ax = 2500;
loc_1a1a3:
	_change_amplif();
	{ _keyb_19EFD(); return; };
_l_lbracket:
	ax = -1;
	_change_amplif();
	cx = 1;
	_test(data.word(k_keyb_switches), 3);
		_jnz(loc_1a1c2);
	cx = 10;
loc_1a1c2:
	_sub(ax, cx);
		_jnc(loc_1a1c9);
	ax = 50;
loc_1a1c9:
	_cmp(ax, 50);
		_ja(loc_1a1d1);
	ax = 50;
loc_1a1d1:
	_change_amplif();
	{ _keyb_19EFD(); return; };
_l_f1:
	_f1_help();
	{ _keyb_19EFD(); return; };
_l_f2:
	_f2_waves();
	{ _keyb_19EFD(); return; };
_l_f3:
	_f3_textmetter();
	data.byte(k_byte_1de85) = 0;
	_test(data.word(k_keyb_switches), 3);
		_jz({ _keyb_19EFD(); return; });
	data.byte(k_byte_1de85) = 1;
	{ _keyb_19EFD(); return; };
_l_f4:
	_cmp(data.word(k_offs_draw), 50200);
		_jnz(loc_1a219);
	ax = data.word(k_word_1de6e);
	_dec(ax);
	_add(data.word(k_current_patterns), ax);
	ax = data.word(k_current_patterns);
	_cmp(ax, data.word(k_word_1de46));
		_jc(loc_1a21f);
loc_1a219:
	data.word(k_current_patterns) = 0;
loc_1a21f:
	_f4_patternnae();
	{ _keyb_19EFD(); return; };
_l_f5:
	_f5_graphspectr();
	{ _keyb_19EFD(); return; };
_l_f6:
	_f6_undoc();
	{ _keyb_19EFD(); return; };
_l_f8:
	_dosexec();
	data.byte(k_byte_1de70) = 0x0FF;
	{ _keyb_19EFD(); return; };
_l_f9:
	_test(data.word(k_keyb_switches), 0x4);
		_jnz(_l_f11);
	_get_playsettings();
	_xor(al, 1);
	_set_playsettings();
	{ _keyb_19EFD(); return; };
_l_f10:
	_test(data.word(k_keyb_switches), 0x4);
		_jnz(_l_f12);
	_get_playsettings();
	_xor(al, 2);
	_set_playsettings();
	{ _keyb_19EFD(); return; };
_l_f11:
	_get_playsettings();
	_xor(al, 4);
	_set_playsettings();
	{ _keyb_19EFD(); return; };
_l_f12:
	_get_playsettings();
	_xor(al, 0x10);
	_set_playsettings();
	_xor(data.word(k_configword)[1], 1);
	{ _keyb_19EFD(); return; };
_l_tab:
	_test(data.word(k_keyb_switches), 0x4);
		_jnz(loc_1a2c1);
	_test(data.word(k_keyb_switches), 0x8);
		_jnz(loc_1a2d1);
	_test(data.word(k_keyb_switches), 0x3);
		_jnz(loc_1a2e1);
	_get_playsettings();
	_xor(al, 8);
	_set_playsettings();
	{ _keyb_19EFD(); return; };
loc_1a2c1:
	cx = 0x0FF;
	bx = 0;
	dx = 0x7D0F;
	sub_12cad();
	{ _keyb_19EFD(); return; };
loc_1a2d1:
	cx = 0x0FF;
	bx = 0;
	dx = 0x910F;
	sub_12cad();
	{ _keyb_19EFD(); return; };
loc_1a2e1:
	cx = 0x0FF;
	bx = 0;
	dx = 0x960F;
	sub_12cad();
	{ _keyb_19EFD(); return; };
_l_numlock:
	_test(data.word(k_keyb_switches), 0x4);
		_jz({ _keyb_19EFD(); return; });
	al = 0x0FF;
	_getset_playstate();
	ah = al;
	al = 1;
	_cmp(ah, al);
		_jnz(loc_1a30d);
	al = 0;
loc_1a30d:
	_getset_playstate();
	{ _keyb_19EFD(); return; };
_l_scrollock:
	al = 0x0FF;
	_getset_playstate();
	ah = al;
	al = 2;
	_cmp(ah, al);
		_jnz(loc_1a326);
	al = 0;
loc_1a326:
	_getset_playstate();
	{ _keyb_19EFD(); return; };
_l_1_end:
	cx = 0x0FF;
	bx = 0;
	dx = 0x0D;
	sub_12cad();
	{ _keyb_19EFD(); return; };
loc_1a33e:
	_sub(al, 2);
	_test(data.word(k_keyb_switches), 0x3);
		_jz(loc_1a34b);
	_add(al, 10);
loc_1a34b:
	_test(data.word(k_keyb_switches), 0x4);
		_jz(loc_1a356);
	_add(al, 20);
loc_1a356:
	_cmp(al, data.word(k_amount_of_x));
		_jnc({ _keyb_19EFD(); return; });
	ch = al;
	bx = data.dword(k_segfsbx_1de28);
	ah = 80;
	_mul(ah);
	_add(bx, ax);
	_xor(fs.byte(bx+0x17), 2);
	bx = 0x0FE;
	cl = 0;
	dx = 0;
	sub_12cad();
	{ _keyb_19EFD(); return; };
_l_enter:
	_write_cf(false);
 	return;
_l_esc:
	data.byte(k_byte_1de7c) = 1;
	_and(data.byte(k_byte_1de90), 0x0FD);
loc_1a393:
	_snd_offx();
	_memfree_125da();
	_write_cf(false);
 	return;
loc_1a3a7:
	_and(data.byte(k_byte_1de90), 0x0FE);
	bx = &;
	ax = data.word(k_mousecolumn);
	bp = data.word(k_mouserow);
	_shr(ax, 3);
	_shr(bp, 3);
	_mouse_1c7cf();
		_jc({ _keyb_19EFD(); return; });
	bx;
loc_1a3c5:
	bx = &;
	ax = data.word(k_mousecolumn);
	bp = data.word(k_mouserow);
	_shr(ax, 3);
	_shr(bp, 3);
	_mouse_1c7cf();
		_jc({ _keyb_19EFD(); return; });
	_push(es);
	dx = 0;
	es = dx;
	edx = es.dword(0x46C);
	_cmp(edx, data.dword(k_dword_1de88));
		_jz(loc_1a3f6);
	data.dword(k_dword_1de88) = edx;
	_pop(es);
	bx;
loc_1a3f6:
	_pop(es);
	loc_193bc;
	return;
/*continuing to unbounded code: _keyb_19efd from _keyb_19efd:0-450*/
_keyb_19efd:
	sub_1265d();
	data.byte(k_byte_1de72) = ah;
	data.byte(k_byte_1de74) = al;
	data.byte(k_byte_1de75) = bh;
	data.byte(k_byte_1de76) = ch;
	ax = -1;
	_change_volume();
	data.word(k_word_1de6a) = ax;
	ax = -1;
	_change_amplif();
	data.word(k_word_1de6c) = ax;
	_get_playsettings();
	data.byte(k_flg_play_settings) = al;
	_cmp(data.byte(k_byte_1de7c), 1);
		_jz(loc_1a393);
	_test(data.byte(k_byte_1de90), 2);
		_jnz(loc_1a3c5);
	_test(data.byte(k_byte_1de90), 1);
		_jnz(loc_1a3a7);
	ax = 0;
	_xchg(ax, data.word(k_key_code));
	_or(ax, ax);
		_jz({ _keyb_19EFD(); return; });
	data.word(k_word_1de50) = ax;
	cx = 2;
	_cmp(ax, 0x0E04D);
		_jz(_l_1a044);
	cx = 10;
	_cmp(ax, 0x0E048);
		_jz(_l_1a044);
	cx = 2;
	_cmp(ax, 0x0E04B);
		_jz(loc_1a070);
	ecx = 10;
	_cmp(ax, 0x0E050);
		_jz(loc_1a070);
	_cmp(al, 0x4D);
		_jz(_l_right);
	_cmp(al, 0x48);
		_jz(_l_up);
	_cmp(al, 0x4B);
		_jz(_l_left);
	_cmp(al, 0x50);
		_jz(_l_down);
	_cmp(al, 0x4E);
		_jz(_l_plus);
	_cmp(al, 0x4A);
		_jz(_l_minus);
	_cmp(al, 0x1A);
		_jz(_l_lbracket);
	_cmp(al, 0x1B);
		_jz(_l_rbracket);
	_cmp(al, 0x3B);
		_jz(_l_f1);
	_cmp(al, 0x3C);
		_jz(_l_f2);
	_cmp(al, 0x3D);
		_jz(_l_f3);
	_cmp(al, 0x3E);
		_jz(_l_f4);
	_cmp(al, 0x3F);
		_jz(_l_f5);
	_cmp(al, 0x40);
		_jz(_l_f6);
	_cmp(al, 0x42);
		_jz(_l_f8);
	_cmp(al, 0x43);
		_jz(_l_f9);
	_cmp(al, 0x44);
		_jz(_l_f10);
	_cmp(al, 0x57);
		_jz(_l_f11);
	_cmp(al, 0x58);
		_jz(_l_f12);
	_cmp(al, 0x26);
		_jz(_l_l);
	_cmp(al, 0x32);
		_jz(_l_m);
	_cmp(al, 0x13);
		_jz(_l_r);
	_cmp(al, 0x1F);
		_jz(_l_s);
	_cmp(al, 0x0F);
		_jz(_l_tab);
	_cmp(al, 0x45);
		_jz(_l_numlock);
	_cmp(al, 0x46);
		_jz(_l_scrollock);
	_cmp(al, 0x4F);
		_jz(_l_1_end);
	_cmp(al, 0x1C);
		_jz(_l_enter);
	_cmp(al, 1);
		_jz(_l_esc);
		_jc({ _keyb_19EFD(); return; });
	_cmp(al, 0x0B);
		_jbe(loc_1a33e);
	{ _keyb_19EFD(); return; };
	_write_cf(true);
 	return;
_l_1a044:
	_push(cx);
	_get_12f7c();
	_and(bx, 0x3F);
	eax = ax;
	_shl(eax, 6);
	_or(al, bl);
	_inc(eax);
	bl = al;
	_and(bl, 0x3F);
	_shr(eax, 6);
	bh = 1;
	sub_12f56();
	_pop(cx);
	_dec(cx);
		_jnz(_l_1a044);
	{ _keyb_19EFD(); return; };
loc_1a070:
	_push(cx);
	_get_12f7c();
	_and(bx, 0x3F);
	eax = ax;
	_shl(eax, 6);
	_or(al, bl);
	_sub(eax, 1);
		_jc(loc_1a0a0);
	bl = al;
	_and(bl, 0x3F);
	_shr(eax, 6);
	bh = 1;
	sub_12f56();
	_pop(cx);
	_dec(cx);
		_jnz(loc_1a070);
	{ _keyb_19EFD(); return; };
loc_1a0a0:
	_pop(cx);
	{ _keyb_19EFD(); return; };
_l_up:
	_sub(data.byte(k_byte_1de84), 1);
		_jnc({ _keyb_19EFD(); return; });
	data.byte(k_byte_1de84) = 0;
	{ _keyb_19EFD(); return; };
_l_down:
	_inc(data.byte(k_byte_1de84));
	ax = data.word(k_amount_of_x);
	_cmp(data.byte(k_byte_1de84), al);
		_jc({ _keyb_19EFD(); return; });
	_dec(al);
	data.byte(k_byte_1de84) = al;
	{ _keyb_19EFD(); return; };
_l_right:
	bx = data.dword(k_segfsbx_1de28);
	al = 0x50;
	_mul(data.byte(k_byte_1de84));
	_add(bx, ax);
	cl = 8;
	_test(data.word(k_keyb_switches), 3);
		_jnz(loc_1a0e6);
	cl = 1;
loc_1a0e6:
	al = fs.byte(bx+0x3A);
	_add(al, cl);
	_cmp(al, 0x80);
		_jbe(loc_1a0f2);
	al = 0x80;
loc_1a0f2:
	ch = data.byte(k_byte_1de84);
	sub_12afd();
	{ _keyb_19EFD(); return; };
_l_left:
	bx = data.dword(k_segfsbx_1de28);
	al = 0x50;
	_mul(data.byte(k_byte_1de84));
	_add(bx, ax);
	cl = 8;
	_test(data.word(k_keyb_switches), 3);
		_jnz(loc_1a118);
	cl = 1;
loc_1a118:
	al = fs.byte(bx+0x3A);
	_sub(al, cl);
		_jnc(loc_1a0f2);
	al = 0;
	loc_1a0f2;
_l_l:
	al = 0;
	loc_1a0f2;
_l_m:
	al = 64;
	loc_1a0f2;
_l_r:
	al = 128;
	loc_1a0f2;
_l_s:
	al = 166;
	loc_1a0f2;
_l_plus:
	ax = -1;
	_change_volume();
	cx = 32;
	_test(data.word(k_keyb_switches), 3);
		_jnz(loc_1a14b);
	cx = 2;
loc_1a14b:
	_add(ax, cx);
	_cmp(ax, 256);
		_jc(loc_1a155);
	ax = 256;
loc_1a155:
	_change_volume();
	{ _keyb_19EFD(); return; };
_l_minus:
	ax = -1;
	_change_volume();
	cx = 32;
	_test(data.word(k_keyb_switches), 3);
		_jnz(loc_1a174);
	cx = 2;
loc_1a174:
	_sub(ax, cx);
		_jnc(loc_1a17a);
	ax = 0;
loc_1a17a:
	_change_volume();
	{ _keyb_19EFD(); return; };
_l_rbracket:
	ax = 0x0FFFF;
	_change_amplif();
	cx = 1;
	_test(data.word(k_keyb_switches), 3);
		_jnz(loc_1a199);
	cx = 0x0A;
loc_1a199:
	_add(ax, cx);
	_cmp(ax, 2500);
		_jc(loc_1a1a3);
	ax = 2500;
loc_1a1a3:
	_change_amplif();
	{ _keyb_19EFD(); return; };
_l_lbracket:
	ax = -1;
	_change_amplif();
	cx = 1;
	_test(data.word(k_keyb_switches), 3);
		_jnz(loc_1a1c2);
	cx = 10;
loc_1a1c2:
	_sub(ax, cx);
		_jnc(loc_1a1c9);
	ax = 50;
loc_1a1c9:
	_cmp(ax, 50);
		_ja(loc_1a1d1);
	ax = 50;
loc_1a1d1:
	_change_amplif();
	{ _keyb_19EFD(); return; };
_l_f1:
	_f1_help();
	{ _keyb_19EFD(); return; };
_l_f2:
	_f2_waves();
	{ _keyb_19EFD(); return; };
_l_f3:
	_f3_textmetter();
	data.byte(k_byte_1de85) = 0;
	_test(data.word(k_keyb_switches), 3);
		_jz({ _keyb_19EFD(); return; });
	data.byte(k_byte_1de85) = 1;
	{ _keyb_19EFD(); return; };
_l_f4:
	_cmp(data.word(k_offs_draw), 50200);
		_jnz(loc_1a219);
	ax = data.word(k_word_1de6e);
	_dec(ax);
	_add(data.word(k_current_patterns), ax);
	ax = data.word(k_current_patterns);
	_cmp(ax, data.word(k_word_1de46));
		_jc(loc_1a21f);
loc_1a219:
	data.word(k_current_patterns) = 0;
loc_1a21f:
	_f4_patternnae();
	{ _keyb_19EFD(); return; };
_l_f5:
	_f5_graphspectr();
	{ _keyb_19EFD(); return; };
_l_f6:
	_f6_undoc();
	{ _keyb_19EFD(); return; };
_l_f8:
	_dosexec();
	data.byte(k_byte_1de70) = 0x0FF;
	{ _keyb_19EFD(); return; };
_l_f9:
	_test(data.word(k_keyb_switches), 0x4);
		_jnz(_l_f11);
	_get_playsettings();
	_xor(al, 1);
	_set_playsettings();
	{ _keyb_19EFD(); return; };
_l_f10:
	_test(data.word(k_keyb_switches), 0x4);
		_jnz(_l_f12);
	_get_playsettings();
	_xor(al, 2);
	_set_playsettings();
	{ _keyb_19EFD(); return; };
_l_f11:
	_get_playsettings();
	_xor(al, 4);
	_set_playsettings();
	{ _keyb_19EFD(); return; };
_l_f12:
	_get_playsettings();
	_xor(al, 0x10);
	_set_playsettings();
	_xor(data.word(k_configword)[1], 1);
	{ _keyb_19EFD(); return; };
_l_tab:
	_test(data.word(k_keyb_switches), 0x4);
		_jnz(loc_1a2c1);
	_test(data.word(k_keyb_switches), 0x8);
		_jnz(loc_1a2d1);
	_test(data.word(k_keyb_switches), 0x3);
		_jnz(loc_1a2e1);
	_get_playsettings();
	_xor(al, 8);
	_set_playsettings();
	{ _keyb_19EFD(); return; };
loc_1a2c1:
	cx = 0x0FF;
	bx = 0;
	dx = 0x7D0F;
	sub_12cad();
	{ _keyb_19EFD(); return; };
loc_1a2d1:
	cx = 0x0FF;
	bx = 0;
	dx = 0x910F;
	sub_12cad();
	{ _keyb_19EFD(); return; };
loc_1a2e1:
	cx = 0x0FF;
	bx = 0;
	dx = 0x960F;
	sub_12cad();
	{ _keyb_19EFD(); return; };
_l_numlock:
	_test(data.word(k_keyb_switches), 0x4);
		_jz({ _keyb_19EFD(); return; });
	al = 0x0FF;
	_getset_playstate();
	ah = al;
	al = 1;
	_cmp(ah, al);
		_jnz(loc_1a30d);
	al = 0;
loc_1a30d:
	_getset_playstate();
	{ _keyb_19EFD(); return; };
_l_scrollock:
	al = 0x0FF;
	_getset_playstate();
	ah = al;
	al = 2;
	_cmp(ah, al);
		_jnz(loc_1a326);
	al = 0;
loc_1a326:
	_getset_playstate();
	{ _keyb_19EFD(); return; };
_l_1_end:
	cx = 0x0FF;
	bx = 0;
	dx = 0x0D;
	sub_12cad();
	{ _keyb_19EFD(); return; };
loc_1a33e:
	_sub(al, 2);
	_test(data.word(k_keyb_switches), 0x3);
		_jz(loc_1a34b);
	_add(al, 10);
loc_1a34b:
	_test(data.word(k_keyb_switches), 0x4);
		_jz(loc_1a356);
	_add(al, 20);
loc_1a356:
	_cmp(al, data.word(k_amount_of_x));
		_jnc({ _keyb_19EFD(); return; });
	ch = al;
	bx = data.dword(k_segfsbx_1de28);
	ah = 80;
	_mul(ah);
	_add(bx, ax);
	_xor(fs.byte(bx+0x17), 2);
	bx = 0x0FE;
	cl = 0;
	dx = 0;
	sub_12cad();
	{ _keyb_19EFD(); return; };
_l_enter:
	_write_cf(false);
 	return;
_l_esc:
	data.byte(k_byte_1de7c) = 1;
	_and(data.byte(k_byte_1de90), 0x0FD);
loc_1a393:
	_snd_offx();
	_memfree_125da();
	_write_cf(false);
 	return;
loc_1a3a7:
	_and(data.byte(k_byte_1de90), 0x0FE);
	bx = &;
	ax = data.word(k_mousecolumn);
	bp = data.word(k_mouserow);
	_shr(ax, 3);
	_shr(bp, 3);
	_mouse_1c7cf();
		_jc({ _keyb_19EFD(); return; });
	bx;
loc_1a3c5:
	bx = &;
	ax = data.word(k_mousecolumn);
	bp = data.word(k_mouserow);
	_shr(ax, 3);
	_shr(bp, 3);
	_mouse_1c7cf();
		_jc({ _keyb_19EFD(); return; });
	_push(es);
	dx = 0;
	es = dx;
	edx = es.dword(0x46C);
	_cmp(edx, data.dword(k_dword_1de88));
		_jz(loc_1a3f6);
	data.dword(k_dword_1de88) = edx;
	_pop(es);
	bx;
loc_1a3f6:
	_pop(es);
	loc_193bc;
_keyb_19efd:
}

void InertiaPlayerContext::_f1_help() {
	STACK_CHECK;
	data.word(kOff_1de3c) = 50164;
	data.word(k_offs_draw) = 50212;
	data.word(k_offs_draw2) = 50168;
	data.word(kOff_1de42) = &;
	_text_init();
	return;
}

void InertiaPlayerContext::_f2_waves() {
	STACK_CHECK;
	data.word(kOff_1de3c) = 50216;
	data.word(k_offs_draw) = 50228;
	data.word(k_offs_draw2) = 50232;
	data.word(kOff_1de42) = 50216;
	_init_vga_waves();
	return;
}

void InertiaPlayerContext::_f3_textmetter() {
	STACK_CHECK;
	data.word(kOff_1de3c) = 50164;
	data.word(k_offs_draw) = 50184;
	data.word(k_offs_draw2) = 50168;
	data.word(kOff_1de42) = &;
	_text_init();
	return;
}

void InertiaPlayerContext::_f4_patternnae() {
	STACK_CHECK;
	data.word(kOff_1de3c) = 50164;
	data.word(k_offs_draw) = 50200;
	data.word(k_offs_draw2) = 50168;
	data.word(kOff_1de42) = &;
	_text_init();
	return;
}

void InertiaPlayerContext::_f5_graphspectr() {
	STACK_CHECK;
	data.word(kOff_1de3c) = 50236;
	data.word(k_offs_draw) = 50248;
	data.word(k_offs_draw2) = 50248;
	data.word(kOff_1de42) = 50236;
	_init_f5_spectr();
	return;
}

void InertiaPlayerContext::_f6_undoc() {
	STACK_CHECK;
	data.word(kOff_1de3c) = 50164;
	data.word(k_offs_draw) = &;
	data.word(k_offs_draw2) = 50168;
	data.word(kOff_1de42) = &;
	_text_init();
	return;
}

void InertiaPlayerContext::_text_init() {
	STACK_CHECK;
	_text_init2();
	return;
}

void InertiaPlayerContext::_text_init2() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_1de86), 1);
		_jz(loc_1a4f2);
	_cmp(data.word(k_amount_of_x), 0x0A);
		_jbe(loc_1a4f2);
	loc_1a5ab;
}

void InertiaPlayerContext::_setvideomode() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_1de70), 0);
		_jz(locret_1a4f1);
	_cmp(data.byte(k_byte_1de70), 1);
		_jz(locret_1a4f1);
	ax = 3;
	_cmp(data.byte(k_byte_1de70), 2);
		_jnz(loc_1a4d5);
	_or(al, 0x80);
loc_1a4d5:
	// _int(0x10);
	_txt_blinkingoff();
	_cmp(data.byte(k_byte_1de86), 1);
		_jz(loc_1a4e8);
	ax = 0x1111;
	bl = 0;
	// _int(0x10);
loc_1a4e8:
	dx = 0x1D00;
	bh = 0;
	ah = 2;
	// _int(0x10);
locret_1a4f1:
	return;
	return;
/*continuing to unbounded code: loc_1a4d5 from _setvideomode:9-23*/
loc_1a4d5:
	// _int(0x10);
	_txt_blinkingoff();
	_cmp(data.byte(k_byte_1de86), 1);
		_jz(loc_1a4e8);
	ax = 0x1111;
	bl = 0;
	// _int(0x10);
loc_1a4e8:
	dx = 0x1D00;
	bh = 0;
	ah = 2;
	// _int(0x10);
locret_1a4f1:
	return;
loc_1a4d5:
}

void InertiaPlayerContext::_txt_draw_top_title() {
	STACK_CHECK;
	cx = 0x102;
	dx = 0x44D;
	bl = 0x78;
	ax = 0x7F03;
	_draw_frame();
	di = data.word(k_videomempointer);
	si = 1522;
	_write_scr();
	return;
}

void InertiaPlayerContext::_txt_draw_bottom() {
	STACK_CHECK;
	si = 2332;
	eax = 0x20202020;
	ds.dword(si) = eax;
	ds.dword(si+4) = eax;
	ds.dword(si+8) = eax;
	ds.byte(si+0x0C) = al;
	ds.byte(si+0x0D) = 0;
	al = data.byte(k_byte_1de75);
	_my_u8toa10();
	ds.dword(si) = 0x20746120;
	_add(si, 4);
	al = data.byte(k_byte_1de76);
	_my_u8toa10();
	ds.word(si) = 0x7062;
	ds.byte(si+2) = 'm';
	si = 2332;
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x48A);
	ah = 0x7F;
	_put_message();
	si = 1981;
	_test(data.byte(k_flg_play_settings), 8);
		_jnz(loc_1a7cc);
	si = 1983;
loc_1a7cc:
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x476);
	ah = 0x7E;
	_put_message();
	si = 2332;
	al = data.byte(k_byte_1de72);
	_inc(al);
	_my_u8toa10();
	ds.byte(si) = '/';
	_inc(si);
	al = data.byte(k_byte_1de73);
	_my_u8toa10();
	ds.dword(si) = 0x202020;
	si = 2332;
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x34A);
	ah = 0x7F;
	_put_message();
	si = 2332;
	al = data.byte(k_byte_1de74);
	_inc(al);
	_my_u8toa10();
	ds.dword(si) = 0x2034362F;
	ds.word(si+4) = ' ';
	_sub(si, cx);
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x3EA);
	ah = 0x7F;
	_put_message();
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x198);
	ah = 0x7C;
	_test(data.byte(k_flg_play_settings), 1);
		_jnz(loc_1a83e);
	ah = 0x78;
loc_1a83e:
	al = 0x0FE;
	es.word(di) = ax;
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x238);
	ah = 0x7C;
	_test(data.byte(k_flg_play_settings), 2);
		_jnz(loc_1a856);
	ah = 0x78;
loc_1a856:
	al = 0x0FE;
	es.word(di) = ax;
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x2D8);
	ah = 0x7C;
	_test(data.byte(k_flg_play_settings), 4);
		_jnz(loc_1a86e);
	ah = 0x78;
loc_1a86e:
	al = 0x0FE;
	es.word(di) = ax;
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x378);
	ah = 0x7C;
	_test(data.byte(k_flg_play_settings), 0x10);
		_jnz(loc_1a886);
	ah = 0x78;
loc_1a886:
	al = 0x0FE;
	es.word(di) = ax;
	si = 2332;
	_mul(ax, data.word(k_word_1de6a), 100);
	al = ah;
	_my_u8toa10();
	ds.dword(si) = 0x202025;
	_sub(si, cx);
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x43A);
	ah = 0x7F;
	_put_message();
	si = 2332;
	ax = data.word(k_word_1de6c);
	_my_u16toa10();
	ds.dword(si) = 0x202025;
	_sub(si, cx);
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x4DA);
	ah = 0x7F;
	_put_message();
	al = 0x0FF;
	_getset_playstate();
	si = al;
	_shl(si, 2);
	_add(si, 2373);
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x0FC);
	ah = 0x7E;
	cx = 4;
loc_1a8eb:
	al = ds.byte(si);
	es.word(di) = ax;
	_inc(si);
	_add(di, 2);
	_dec(cx);
		_jnz(loc_1a8eb);
	return;
	return;
/*continuing to unbounded code: loc_1a7cc from _txt_draw_bottom:25-126*/
loc_1a7cc:
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x476);
	ah = 0x7E;
	_put_message();
	si = 2332;
	al = data.byte(k_byte_1de72);
	_inc(al);
	_my_u8toa10();
	ds.byte(si) = '/';
	_inc(si);
	al = data.byte(k_byte_1de73);
	_my_u8toa10();
	ds.dword(si) = 0x202020;
	si = 2332;
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x34A);
	ah = 0x7F;
	_put_message();
	si = 2332;
	al = data.byte(k_byte_1de74);
	_inc(al);
	_my_u8toa10();
	ds.dword(si) = 0x2034362F;
	ds.word(si+4) = ' ';
	_sub(si, cx);
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x3EA);
	ah = 0x7F;
	_put_message();
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x198);
	ah = 0x7C;
	_test(data.byte(k_flg_play_settings), 1);
		_jnz(loc_1a83e);
	ah = 0x78;
loc_1a83e:
	al = 0x0FE;
	es.word(di) = ax;
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x238);
	ah = 0x7C;
	_test(data.byte(k_flg_play_settings), 2);
		_jnz(loc_1a856);
	ah = 0x78;
loc_1a856:
	al = 0x0FE;
	es.word(di) = ax;
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x2D8);
	ah = 0x7C;
	_test(data.byte(k_flg_play_settings), 4);
		_jnz(loc_1a86e);
	ah = 0x78;
loc_1a86e:
	al = 0x0FE;
	es.word(di) = ax;
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x378);
	ah = 0x7C;
	_test(data.byte(k_flg_play_settings), 0x10);
		_jnz(loc_1a886);
	ah = 0x78;
loc_1a886:
	al = 0x0FE;
	es.word(di) = ax;
	si = 2332;
	_mul(ax, data.word(k_word_1de6a), 100);
	al = ah;
	_my_u8toa10();
	ds.dword(si) = 0x202025;
	_sub(si, cx);
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x43A);
	ah = 0x7F;
	_put_message();
	si = 2332;
	ax = data.word(k_word_1de6c);
	_my_u16toa10();
	ds.dword(si) = 0x202025;
	_sub(si, cx);
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x4DA);
	ah = 0x7F;
	_put_message();
	al = 0x0FF;
	_getset_playstate();
	si = al;
	_shl(si, 2);
	_add(si, 2373);
	di = data.dword(k_videopoint_shiftd);
	_add(di, 0x0FC);
	ah = 0x7E;
	cx = 4;
loc_1a8eb:
	al = ds.byte(si);
	es.word(di) = ax;
	_inc(si);
	_add(di, 2);
	_dec(cx);
		_jnz(loc_1a8eb);
	return;
loc_1a7cc:
}

void InertiaPlayerContext::_f3_draw() {
	STACK_CHECK;
	_txt_draw_bottom();
	_cmp(data.byte(k_byte_1de85), 1);
		_jz(loc_1a913);
	es = data.word(k_buffer_1seg);
	di = 0;
	cx = 0x50;
	ax = 0x4001;
	_volume_prep();
loc_1a913:
	data.word(k_buffer_2seg) = 2571;
	bx = data.dword(k_segfsbx_1de28);
	di = data.word(k_videomempointer);
	_add(di, 0x3C4);
	cx = data.word(k_amount_of_x);
	_cmp(cx, data.word(k_word_1de6e));
		_jbe(loc_1a934);
	cx = data.word(k_word_1de6e);
loc_1a934:
	_inc(data.byte(k_byte_1de71));
	ax = 0;
loc_1a93a:
	_push(ax);
	_push(cx);
	_push(di);
	dl = al;
	_add(al, '1');
	_cmp(al, '9');
		_jbe(loc_1a947);
	_add(al, 7);
loc_1a947:
	ah = 0x1E;
	_cmp(dl, data.byte(k_byte_1de84));
		_jz(loc_1a951);
	ah = 0x7E;
loc_1a951:
	es.word(di+2) = ax;
	al = ' ';
	es.word(di) = ax;
	es.word(di+4) = ax;
	_add(di, 6);
	si = fs.byte(bx+0x35);
	al = ' ';
	_test(si, 0x0F);
		_jz(loc_1a975);
	ax = si;
	_shr(al, 4);
	_add(al, '0');
loc_1a975:
	ah = 0x7F;
	es.word(di+4) = ax;
	_and(si, 0x0F);
	_shl(si, 1);
	al = data.byte(k_notes)[si];
	es.word(di) = ax;
	al = data.byte(k_notes)[si+1];
	es.word(di+2) = ax;
	_add(di, 8);
	_test(fs.byte(bx+0x17), 1);
		_jnz(loc_1a9ad);
	si = 2264;
	ah = 0x7F;
	_test(fs.byte(bx+0x17), 2);
		_jnz(loc_1a9a8);
loc_1a9a5:
	si = 2262;
loc_1a9a8:
	_put_message();
	loc_1a9c2;
loc_1a9ad:
	eax = fs.byte(bx+2);
	_dec(ax);
		_js(loc_1a9a5);
	_shl(ax, 6);
	si = ax;
	_add(si, data.dword(k_dword_1de2c));
	_txt_1abae();
loc_1a9c2:
	_add(di, 2);
	_cmp(data.byte(k_byte_1de85), 1);
		_jnz(loc_1aa1a);
	_push(di);
	_push(es);
	ax = ds;
	es = ax;
	di = 2571;
	_write_df(false);
 	eax = fs.byte(bx+2);
	bp = 2;
	_my_u32toa_fill();
	bp = 4;
	eax = fs.byte(bx+0x22);
	_my_u32toa_fill();
	bp = 7;
	eax = fs.word(bx+0x1E);
	_my_u32toa_fill();
	ax = ds;
	es = ax;
	eax = 0x20202020;
	cx = 4;
	while(cx--)
		_stosd();
	ds.byte(di) = 0;
	_pop(es);
	_pop(di);
	si = 2571;
	ah = 0x7E;
	_put_message();
	loc_1aacb;
loc_1aa1a:
	_cmp(data.byte(k_snd_card_type), 0x0A);
		_jz(loc_1aa62);
	si = data.word(k_buffer_2seg);
	cx = 0x50;
	eax = 0;
	edx = 0;
loc_1aa2e:
	dl = ds.byte(si);
	_or(dl, dl);
		_jns(loc_1aa36);
	_neg(dl);
loc_1aa36:
	_inc(si);
	_add(eax, edx);
	_dec(cx);
		_jnz(loc_1aa2e);
	data.word(k_buffer_2seg) = si;
	edx = 0;
	_div(data.dword(k_volume_1de34));
	_cmp(al, 60);
		_jc(loc_1aa4f);
	al = 60;
loc_1aa4f:
	_cmp(data.byte(k_byte_1de83), 0);
		_jz(loc_1aa5c);
	_cmp(al, fs.byte(bx+0x1A));
		_jc(loc_1aa73);
loc_1aa5c:
	fs.byte(bx+0x1A) = al;
	loc_1aa88;
loc_1aa62:
	_test(fs.byte(bx+0x17), 1);
		_jz(loc_1aa73);
	al = fs.byte(bx+0x22);
	fs.byte(bx+0x1A) = al;
	loc_1aa88;
loc_1aa73:
	_and(data.byte(k_byte_1de71), 0x1F);
		_jnz(loc_1aa88);
	al = data.byte(k_byte_1de83);
	_sub(fs.byte(bx+0x1A), al);
		_jns(loc_1aa88);
	fs.byte(bx+0x1A) = 0;
loc_1aa88:
	cx = fs.byte(bx+0x1A);
	_shr(cx, 1);
	dx = 30;
	_sub(dx, cx);
	if (cx==0)
		_volume_endstr;
	si = cx;
	cx = 0x0D;
	_cmp(si, cx);
		_ja(_volume_medium);
	cx = si;
_volume_medium:
	ax = 0x7A16;
	_write_df(false);
 	_stosw(cx, true);
	_sub(si, 0x0D);
		_jbe(_volume_endstr);
	cx = 0x0C;
	_cmp(si, cx);
		_ja(_volume_higher);
	cx = si;
_volume_higher:
	ah = 0x7E;
	_stosw(cx, true);
	_sub(si, 0x0C);
		_jbe(_volume_endstr);
	cx = si;
	ah = 0x7C;
	_stosw(cx, true);
_volume_endstr:
	cx = dx;
	ax = 0x7816;
	_stosw(cx, true);
loc_1aacb:
	_pop(di);
	_push(di);
	_add(di, 0x7A);
	si = 2162;
	al = fs.byte(bx+0x0A);
	_cmp(al, 0x1D);
		_jz({ loc_1AB0D(); return; });
	_cmp(al, 0x0E);
		_jnz(loc_1aaf0);
	si = 2260;
	al = fs.byte(bx+0x0B);
	_cmp(al, 0x60);
		_jz(loc_1aaf7);
	si = 2228;
	_shr(al, 4);
loc_1aaf0:
	ah = 0;
	_shl(ax, 4);
	_add(si, ax);
loc_1aaf7:
	ah = 0x7E;
	_put_message();
	_pop(di);
	_pop(cx);
	_pop(ax);
	_add(di, 0x0A0);
	_add(bx, 0x50);
	_inc(ax);
	_dec(cx);
		_jnz(loc_1a93a);
	return;
	return;
/*continuing to unbounded code: loc_1a913 from _f3_draw:9-222*/
loc_1a913:
	data.word(k_buffer_2seg) = 2571;
	bx = data.dword(k_segfsbx_1de28);
	di = data.word(k_videomempointer);
	_add(di, 0x3C4);
	cx = data.word(k_amount_of_x);
	_cmp(cx, data.word(k_word_1de6e));
		_jbe(loc_1a934);
	cx = data.word(k_word_1de6e);
loc_1a934:
	_inc(data.byte(k_byte_1de71));
	ax = 0;
loc_1a93a:
	_push(ax);
	_push(cx);
	_push(di);
	dl = al;
	_add(al, '1');
	_cmp(al, '9');
		_jbe(loc_1a947);
	_add(al, 7);
loc_1a947:
	ah = 0x1E;
	_cmp(dl, data.byte(k_byte_1de84));
		_jz(loc_1a951);
	ah = 0x7E;
loc_1a951:
	es.word(di+2) = ax;
	al = ' ';
	es.word(di) = ax;
	es.word(di+4) = ax;
	_add(di, 6);
	si = fs.byte(bx+0x35);
	al = ' ';
	_test(si, 0x0F);
		_jz(loc_1a975);
	ax = si;
	_shr(al, 4);
	_add(al, '0');
loc_1a975:
	ah = 0x7F;
	es.word(di+4) = ax;
	_and(si, 0x0F);
	_shl(si, 1);
	al = data.byte(k_notes)[si];
	es.word(di) = ax;
	al = data.byte(k_notes)[si+1];
	es.word(di+2) = ax;
	_add(di, 8);
	_test(fs.byte(bx+0x17), 1);
		_jnz(loc_1a9ad);
	si = 2264;
	ah = 0x7F;
	_test(fs.byte(bx+0x17), 2);
		_jnz(loc_1a9a8);
loc_1a9a5:
	si = 2262;
loc_1a9a8:
	_put_message();
	loc_1a9c2;
loc_1a9ad:
	eax = fs.byte(bx+2);
	_dec(ax);
		_js(loc_1a9a5);
	_shl(ax, 6);
	si = ax;
	_add(si, data.dword(k_dword_1de2c));
	_txt_1abae();
loc_1a9c2:
	_add(di, 2);
	_cmp(data.byte(k_byte_1de85), 1);
		_jnz(loc_1aa1a);
	_push(di);
	_push(es);
	ax = ds;
	es = ax;
	di = 2571;
	_write_df(false);
 	eax = fs.byte(bx+2);
	bp = 2;
	_my_u32toa_fill();
	bp = 4;
	eax = fs.byte(bx+0x22);
	_my_u32toa_fill();
	bp = 7;
	eax = fs.word(bx+0x1E);
	_my_u32toa_fill();
	ax = ds;
	es = ax;
	eax = 0x20202020;
	cx = 4;
	while(cx--)
		_stosd();
	ds.byte(di) = 0;
	_pop(es);
	_pop(di);
	si = 2571;
	ah = 0x7E;
	_put_message();
	loc_1aacb;
loc_1aa1a:
	_cmp(data.byte(k_snd_card_type), 0x0A);
		_jz(loc_1aa62);
	si = data.word(k_buffer_2seg);
	cx = 0x50;
	eax = 0;
	edx = 0;
loc_1aa2e:
	dl = ds.byte(si);
	_or(dl, dl);
		_jns(loc_1aa36);
	_neg(dl);
loc_1aa36:
	_inc(si);
	_add(eax, edx);
	_dec(cx);
		_jnz(loc_1aa2e);
	data.word(k_buffer_2seg) = si;
	edx = 0;
	_div(data.dword(k_volume_1de34));
	_cmp(al, 60);
		_jc(loc_1aa4f);
	al = 60;
loc_1aa4f:
	_cmp(data.byte(k_byte_1de83), 0);
		_jz(loc_1aa5c);
	_cmp(al, fs.byte(bx+0x1A));
		_jc(loc_1aa73);
loc_1aa5c:
	fs.byte(bx+0x1A) = al;
	loc_1aa88;
loc_1aa62:
	_test(fs.byte(bx+0x17), 1);
		_jz(loc_1aa73);
	al = fs.byte(bx+0x22);
	fs.byte(bx+0x1A) = al;
	loc_1aa88;
loc_1aa73:
	_and(data.byte(k_byte_1de71), 0x1F);
		_jnz(loc_1aa88);
	al = data.byte(k_byte_1de83);
	_sub(fs.byte(bx+0x1A), al);
		_jns(loc_1aa88);
	fs.byte(bx+0x1A) = 0;
loc_1aa88:
	cx = fs.byte(bx+0x1A);
	_shr(cx, 1);
	dx = 30;
	_sub(dx, cx);
	if (cx==0)
		_volume_endstr;
	si = cx;
	cx = 0x0D;
	_cmp(si, cx);
		_ja(_volume_medium);
	cx = si;
_volume_medium:
	ax = 0x7A16;
	_write_df(false);
 	_stosw(cx, true);
	_sub(si, 0x0D);
		_jbe(_volume_endstr);
	cx = 0x0C;
	_cmp(si, cx);
		_ja(_volume_higher);
	cx = si;
_volume_higher:
	ah = 0x7E;
	_stosw(cx, true);
	_sub(si, 0x0C);
		_jbe(_volume_endstr);
	cx = si;
	ah = 0x7C;
	_stosw(cx, true);
_volume_endstr:
	cx = dx;
	ax = 0x7816;
	_stosw(cx, true);
loc_1aacb:
	_pop(di);
	_push(di);
	_add(di, 0x7A);
	si = 2162;
	al = fs.byte(bx+0x0A);
	_cmp(al, 0x1D);
		_jz({ loc_1AB0D(); return; });
	_cmp(al, 0x0E);
		_jnz(loc_1aaf0);
	si = 2260;
	al = fs.byte(bx+0x0B);
	_cmp(al, 0x60);
		_jz(loc_1aaf7);
	si = 2228;
	_shr(al, 4);
loc_1aaf0:
	ah = 0;
	_shl(ax, 4);
	_add(si, ax);
loc_1aaf7:
	ah = 0x7E;
	_put_message();
	_pop(di);
	_pop(cx);
	_pop(ax);
	_add(di, 0x0A0);
	_add(bx, 0x50);
	_inc(ax);
	_dec(cx);
		_jnz(loc_1a93a);
	return;
loc_1a913:
}

void InertiaPlayerContext::loc_1ab0d() {
	STACK_CHECK;
	si = 2220;
	al = fs.byte(bx+0x0B);
	_cmp(al, 0x37);
		_jz(loc_1ab5d);
	_cmp(al, 0x47);
		_jz(loc_1ab67);
	_cmp(al, 0x48);
		_jz(loc_1ab53);
	cl = 0;
	sub_1ab8c();
	ds.word(si+9) = ax;
	cl = fs.byte(bx+0x0B);
	_shr(cl, 4);
	sub_1ab8c();
	ds.word(si+0x0B) = ax;
	cl = fs.byte(bx+0x0B);
	_and(cl, 0x0F);
	sub_1ab8c();
	ds.word(si+0x0D) = ax;
	loc_1aaf7;
loc_1ab44:
	ds.dword(si+9) = 0x20202020;
	ds.word(si+0x0D) = 0x2020;
	loc_1aaf7;
loc_1ab53:
	ds.dword(si+0x0B) = 0x73756C70;
	loc_1ab6f;
loc_1ab5d:
	ds.dword(si+0x0B) = 0x206E696D;
	loc_1ab6f;
loc_1ab67:
	ds.dword(si+0x0B) = 0x206A616D;
loc_1ab6f:
	al = fs.byte(bx+0x35);
	_and(ax, 0x0F);
		_jz(loc_1ab44);
	_cmp(al, 0x0C);
		_ja(loc_1ab44);
	_shl(ax, 1);
	_push(si);
	si = ax;
	ax =  [si];
	_pop(si);
	ds.word(si+9) = ax;
	loc_1aaf7;
	return;
/*continuing to unbounded code: loc_1ab44 from loc_1ab0d:21-45*/
loc_1ab44:
	ds.dword(si+9) = 0x20202020;
	ds.word(si+0x0D) = 0x2020;
	loc_1aaf7;
loc_1ab53:
	ds.dword(si+0x0B) = 0x73756C70;
	loc_1ab6f;
loc_1ab5d:
	ds.dword(si+0x0B) = 0x206E696D;
	loc_1ab6f;
loc_1ab67:
	ds.dword(si+0x0B) = 0x206A616D;
loc_1ab6f:
	al = fs.byte(bx+0x35);
	_and(ax, 0x0F);
		_jz(loc_1ab44);
	_cmp(al, 0x0C);
		_ja(loc_1ab44);
	_shl(ax, 1);
	_push(si);
	si = ax;
	ax =  [si];
	_pop(si);
	ds.word(si+9) = ax;
	loc_1aaf7;
loc_1ab44:
}

void InertiaPlayerContext::sub_1ab8c() {
	STACK_CHECK;
	al = fs.byte(bx+0x35);
	_and(ax, 0x0F);
	_add(al, cl);
	_cmp(al, 0x0C);
		_jbe(loc_1ab9b);
	_sub(al, 0x0C);
loc_1ab9b:
	_shl(ax, 1);
	_push(si);
	si = ax;
	ax = data.byte(k_notes)[si];
	_pop(si);
	_cmp(ah, 0x2D);
		_jz(loc_1abab);
	return;
loc_1abab:
	ah = 0x20;
	return;
	return;
/*continuing to unbounded code: loc_1ab9b from sub_1ab8c:7-18*/
loc_1ab9b:
	_shl(ax, 1);
	_push(si);
	si = ax;
	ax = data.byte(k_notes)[si];
	_pop(si);
	_cmp(ah, 0x2D);
		_jz(loc_1abab);
	return;
loc_1abab:
	ah = 0x20;
	return;
loc_1ab9b:
}

void InertiaPlayerContext::_txt_1abae() {
	STACK_CHECK;
	ah = 0x7B;
	cx = 0x16;
loc_1abb3:
	al = fs.byte(si);
	es.word(di) = ax;
	_inc(si);
	_add(di, 2);
	_dec(cx);
		_jnz(loc_1abb3);
	return;
	return;
/*continuing to unbounded code: loc_1abb3 from _txt_1abae:3-10*/
loc_1abb3:
	al = fs.byte(si);
	es.word(di) = ax;
	_inc(si);
	_add(di, 2);
	_dec(cx);
		_jnz(loc_1abb3);
	return;
loc_1abb3:
}

void InertiaPlayerContext::_f4_draw() {
	STACK_CHECK;
	_txt_draw_bottom();
	di = data.word(k_videomempointer);
	_add(di, 0x3C6);
	si = 2144;
	ah = 0x7E;
	_text_1bf69();
	di = data.word(k_videomempointer);
	_add(di, 0x464);
	bx = data.dword(k_dword_1de2c);
	bp = data.word(k_current_patterns);
	_mul(ax, bp, 0x40);
	_add(bx, ax);
	dl = data.word(k_word_1de6e);
	_dec(dl);
loc_1abf0:
	_cmp(bp, data.word(k_word_1de46));
		_jnc(locret_1acf5);
	_push(bx);
	_push(dx);
	_push(bp);
	_push(di);
	ax = ds;
	es = ax;
	di = 2571;
	_write_df(false);
 	eax = bp;
	_inc(ax);
	bp = 2;
	_my_pnt_u32toa_fill();
	ds.dword(di) = 0x7B0220;
	_add(di, 3);
	si = bx;
	cx = 8;
	_write_df(false);
 	while(cx--)
		_movs(es.dword(di), fs.dword(si));
	_test(fs.byte(bx+0x3C), 1);
		_jnz(loc_1ac35);
	si = 2150;
	cx = 9;
	_movsb(cx, true);
	loc_1acd2;
loc_1ac35:
	eax = fs.dword(bx+0x20);
	bp = 7;
	_my_pnt_u32toa_fill();
	eax = fs.byte(bx+0x3D);
	bp = 3;
	_my_pnt_u32toa_fill();
	eax = 0x363120;
	_test(fs.byte(bx+0x3C), 4);
		_jnz(loc_1ac5f);
	eax = 0x382020;
loc_1ac5f:
	ds.dword(di) = eax;
	al = 0x1D;
	_test(fs.byte(bx+0x3C), 0x10);
		_jnz(loc_1ac6d);
	al = ' ';
loc_1ac6d:
	ds.byte(di+3) = al;
	_add(di, 4);
	eax = fs.word(bx+0x36);
	bp = 6;
	_my_pnt_u32toa_fill();
	ds.dword(di) = 0x7A487E02;
	_add(di, 4);
	ds.dword(di) = 0x7F0220;
	_add(di, 3);
	eax = 0x20202020;
	ah = fs.byte(bx+0x3E);
	_and(ah, 0x0F);
	_test(ah, 8);
		_jz(loc_1acac);
	al = '-';
	_neg(ah);
	_add(ah, 0x10);
loc_1acac:
	_or(ah, '0');
	ds.dword(di) = eax;
	_add(di, 4);
	_test(fs.byte(bx+0x3C), 8);
		_jz(loc_1acd2);
	eax = fs.dword(bx+0x24);
	bp = 7;
	_my_pnt_u32toa_fill();
	eax = fs.dword(bx+0x2C);
	bp = 7;
	_my_pnt_u32toa_fill();
loc_1acd2:
	ds.byte(di) = 0;
	_pop(di);
	_push(di);
	es = data.word(k_videomempointer)[2];
	si = 2571;
	ah = 0x7F;
	_text_1bf69();
	_pop(di);
	_pop(bp);
	_pop(dx);
	_pop(bx);
	_add(bx, 0x40);
	_inc(bp);
	_add(di, 0x0A0);
	_dec(dl);
		_jnz(loc_1abf0);
locret_1acf5:
	return;
	return;
/*continuing to unbounded code: loc_1abf0 from _f4_draw:15-109*/
loc_1abf0:
	_cmp(bp, data.word(k_word_1de46));
		_jnc(locret_1acf5);
	_push(bx);
	_push(dx);
	_push(bp);
	_push(di);
	ax = ds;
	es = ax;
	di = 2571;
	_write_df(false);
 	eax = bp;
	_inc(ax);
	bp = 2;
	_my_pnt_u32toa_fill();
	ds.dword(di) = 0x7B0220;
	_add(di, 3);
	si = bx;
	cx = 8;
	_write_df(false);
 	while(cx--)
		_movs(es.dword(di), fs.dword(si));
	_test(fs.byte(bx+0x3C), 1);
		_jnz(loc_1ac35);
	si = 2150;
	cx = 9;
	_movsb(cx, true);
	loc_1acd2;
loc_1ac35:
	eax = fs.dword(bx+0x20);
	bp = 7;
	_my_pnt_u32toa_fill();
	eax = fs.byte(bx+0x3D);
	bp = 3;
	_my_pnt_u32toa_fill();
	eax = 0x363120;
	_test(fs.byte(bx+0x3C), 4);
		_jnz(loc_1ac5f);
	eax = 0x382020;
loc_1ac5f:
	ds.dword(di) = eax;
	al = 0x1D;
	_test(fs.byte(bx+0x3C), 0x10);
		_jnz(loc_1ac6d);
	al = ' ';
loc_1ac6d:
	ds.byte(di+3) = al;
	_add(di, 4);
	eax = fs.word(bx+0x36);
	bp = 6;
	_my_pnt_u32toa_fill();
	ds.dword(di) = 0x7A487E02;
	_add(di, 4);
	ds.dword(di) = 0x7F0220;
	_add(di, 3);
	eax = 0x20202020;
	ah = fs.byte(bx+0x3E);
	_and(ah, 0x0F);
	_test(ah, 8);
		_jz(loc_1acac);
	al = '-';
	_neg(ah);
	_add(ah, 0x10);
loc_1acac:
	_or(ah, '0');
	ds.dword(di) = eax;
	_add(di, 4);
	_test(fs.byte(bx+0x3C), 8);
		_jz(loc_1acd2);
	eax = fs.dword(bx+0x24);
	bp = 7;
	_my_pnt_u32toa_fill();
	eax = fs.dword(bx+0x2C);
	bp = 7;
	_my_pnt_u32toa_fill();
loc_1acd2:
	ds.byte(di) = 0;
	_pop(di);
	_push(di);
	es = data.word(k_videomempointer)[2];
	si = 2571;
	ah = 0x7F;
	_text_1bf69();
	_pop(di);
	_pop(bp);
	_pop(dx);
	_pop(bx);
	_add(bx, 0x40);
	_inc(bp);
	_add(di, 0x0A0);
	_dec(dl);
		_jnz(loc_1abf0);
locret_1acf5:
	return;
loc_1abf0:
}

void InertiaPlayerContext::_my_pnt_u32toa_fill() {
	STACK_CHECK;
	ds.word(di) = 0x7F02;
	_add(di, 2);
}

void InertiaPlayerContext::_my_u32toa_fill() {
	STACK_CHECK;
	si = 2332;
	_push(bx);
	_push(di);
	_push(bp);
	_my_u32toa10();
	_pop(bp);
	_pop(di);
	_pop(bx);
	_cmp(cx, bp);
		_jc(loc_1ad0f);
	cx = bp;
loc_1ad0f:
	_sub(si, cx);
	dx = cx;
	_neg(cx);
	_add(cx, bp);
	al = ' ';
	_write_df(false);
 	_stosb(cx, true);
	cx = dx;
	_movsb(cx, true);
	return;
	return;
/*continuing to unbounded code: loc_1ad0f from _my_u32toa_fill:12-24*/
loc_1ad0f:
	_sub(si, cx);
	dx = cx;
	_neg(cx);
	_add(cx, bp);
	al = ' ';
	_write_df(false);
 	_stosb(cx, true);
	cx = dx;
	_movsb(cx, true);
	return;
loc_1ad0f:
}

void InertiaPlayerContext::_f1_draw() {
	STACK_CHECK;
	_txt_draw_bottom();
	di = data.word(k_videomempointer);
	si = 1698;
	_write_scr();
	return;
}

	_pop(flags);
	_video_prp_mtr_positn();
loc_1ae7e:
	ax = ds;
	bx = 2571;
	_shr(bx, 4);
	_add(ax, bx);
	data.word(k_buffer_1seg) = ax;
	_add(ax, 0x280);
	data.word(k_buffer_2seg) = ax;
	ax = ds;
	es = ax;
	di = 2571;
	cx = 0x0A00;
	eax = 0;
	_write_df(false);
 	while(cx--)
		_stosd();
	di = 2574;
	cx = 0x0A00;
	eax = 0x1010101;
	while(cx--)
		_stosd();
	return;
	_f2_draw_waves2();
	_video_prp_mtr_positn();
	loc_1ae7e;
	ah = 1;
loc_1ade2:
	al = ah;
	// _out(dx, al);
	di = 0;
loc_1ade7:
	cl = ds.byte(si);
	_inc(si);
	_cmp(si, 2575);
		_jnc(loc_1ae0c);
	_or(cl, cl);
		_js(loc_1ae2d);
	_inc(cl);
loc_1adf6:
	al = es.byte(bx+di);
	al = ds.byte(si);
	es.byte(bx+di) = al;
	_inc(si);
	_cmp(si, 2575);
		_jnc(loc_1ae11);
	_inc(di);
	_dec(cl);
		_jnz(loc_1adf6);
	loc_1ae46;
loc_1ae0c:
	_push();
	_push();
	{ _read2buffer(); return; };
loc_1ae11:
	_push();
	_push();
	{ _read2buffer(); return; };
loc_1ae16:
	_push();
	_push();
}

	_popa();
	si = 2571;
	return;
}

	_pop(flags);
	_video_prp_mtr_positn();
loc_1ae7e:
	ax = ds;
	bx = 2571;
	_shr(bx, 4);
	_add(ax, bx);
	data.word(k_buffer_1seg) = ax;
	_add(ax, 0x280);
	data.word(k_buffer_2seg) = ax;
	ax = ds;
	es = ax;
	di = 2571;
	cx = 0x0A00;
	eax = 0;
	_write_df(false);
 	while(cx--)
		_stosd();
	di = 2574;
	cx = 0x0A00;
	eax = 0x1010101;
	while(cx--)
		_stosd();
	return;
	_f2_draw_waves2();
	_video_prp_mtr_positn();
	loc_1ae7e;
	return;
/*continuing to unbounded code: loc_1ade0 from _init_vga_waves:62-96*/
loc_1ade0:
	ah = 1;
loc_1ade2:
	al = ah;
	// _out(dx, al);
	di = 0;
loc_1ade7:
	cl = ds.byte(si);
	_inc(si);
	_cmp(si, 2575);
		_jnc(loc_1ae0c);
	_or(cl, cl);
		_js(loc_1ae2d);
	_inc(cl);
loc_1adf6:
	al = es.byte(bx+di);
	al = ds.byte(si);
	es.byte(bx+di) = al;
	_inc(si);
	_cmp(si, 2575);
		_jnc(loc_1ae11);
	_inc(di);
	_dec(cl);
		_jnz(loc_1adf6);
	loc_1ae46;
loc_1ae0c:
	_push();
	_push();
	{ _read2buffer(); return; };
loc_1ae11:
	_push();
	_push();
	{ _read2buffer(); return; };
loc_1ae16:
	_push();
	_push();
}

void InertiaPlayerContext::_f2_draw_waves() {
	STACK_CHECK;
	es = data.word(k_buffer_1seg);
	di = 0;
	cx = 0x128;
	ax = 0x0C001;
	_volume_prep();
	ax = 0x0A000;
	es = ax;
	fs = data.word(k_buffer_1seg);
	gs = data.word(k_buffer_2seg);
	di = 2504;
	si = 0;
	cx = data.word(k_amount_of_x);
_lc_next_meter:
	_push(cx);
	_push(si);
	_push(di);
	bp = ds.word(di);
	dx = 0x3CE;
	al = 8;
	// _out(dx, al);
	al = 0x80;
_lc_nextvideobit:
	ah = 37;
	dx = 0x3CF;
	// _out(dx, al);
	bx = bp;
_lc_next_x8:
	di = gs.byte(si);
	dx = fs.byte(si);
	_cmp(di, dx);
		_jz(loc_1af3a);
	_neg(di);
	cx = di;
	_shl(di, 6);
	_shl(cx, 4);
	_add(di, cx);
	cx = ds.word(bx+di);
	_or(cx, cx);
		_js(loc_1af1e);
	_cmp(cx, 280*80);
		_jnc(loc_1af1e);
	_and(es.byte(bx+di), 0x7);
loc_1af1e:
	_neg(dx);
	di = dx;
	_shl(di, 6);
	_shl(dx, 4);
	_add(di, dx);
	cx = ds.word(bx+di);
	_or(cx, cx);
		_js(loc_1af3a);
	_cmp(cx, 280*80);
		_jnc(loc_1af3a);
	_or(es.byte(bx+di), 0x8);
loc_1af3a:
	_add(si, 8);
	_inc(bx);
	_dec(ah);
		_jnz(_lc_next_x8);
	_sub(si, 0x128);
	_inc(si);
	_shr(al, 1);
		_jnc(_lc_nextvideobit);
	_pop(di);
	_pop(si);
	_pop(cx);
	_add(si, 0x128);
	_add(di, 2);
	_dec(cx);
		_jnz(_lc_next_meter);
	ax = data.word(k_buffer_1seg);
	_xchg(ax, data.word(k_buffer_2seg));
	data.word(k_buffer_1seg) = ax;
	return;
	return;
/*continuing to unbounded code: loc_1af1e from _f2_draw_waves:43-74*/
loc_1af1e:
	_neg(dx);
	di = dx;
	_shl(di, 6);
	_shl(dx, 4);
	_add(di, dx);
	cx = ds.word(bx+di);
	_or(cx, cx);
		_js(loc_1af3a);
	_cmp(cx, 280*80);
		_jnc(loc_1af3a);
	_or(es.byte(bx+di), 0x8);
loc_1af3a:
	_add(si, 8);
	_inc(bx);
	_dec(ah);
		_jnz(_lc_next_x8);
	_sub(si, 0x128);
	_inc(si);
	_shr(al, 1);
		_jnc(_lc_nextvideobit);
	_pop(di);
	_pop(si);
	_pop(cx);
	_add(si, 0x128);
	_add(di, 2);
	_dec(cx);
		_jnz(_lc_next_meter);
	ax = data.word(k_buffer_1seg);
	_xchg(ax, data.word(k_buffer_2seg));
	data.word(k_buffer_1seg) = ax;
	return;
loc_1af1e:
}

void InertiaPlayerContext::_f2_draw_waves2() {
	STACK_CHECK;
	ax = 0x0A000;
	es = ax;
	fs = data.word(k_buffer_1seg);
	gs = data.word(k_buffer_2seg);
	di = 2504;
	si = 0;
	cx = data.word(k_amount_of_x);
loc_1af79:
	_push(cx);
	_push(si);
	_push(di);
	bp = ds.word(di);
	dx = 0x3CE;
	al = 8;
	// _out(dx, al);
	al = 0x80;
loc_1af86:
	ah = 37;
	dx = 0x3CF;
	// _out(dx, al);
	bx = bp;
loc_1af8e:
	di = gs.byte(si);
	_neg(di);
	cx = di;
	_shl(di, 6);
	_shl(cx, 4);
	_add(di, cx);
	cx = ds.word(bx+di);
	_or(cx, cx);
		_js(loc_1afae);
	_cmp(cx, 22400);
		_jnc(loc_1afae);
	_and(es.byte(bx+di), 0x7);
loc_1afae:
	_add(si, 8);
	_inc(bx);
	_dec(ah);
		_jnz(loc_1af8e);
	_sub(si, 0x128);
	_inc(si);
	_shr(al, 1);
		_jnc(loc_1af86);
	_pop(di);
	_pop(si);
	_pop(cx);
	_add(si, 0x128);
	_add(di, 2);
	_dec(cx);
		_jnz(loc_1af79);
	loc_1ae7e;
	return;
/*continuing to unbounded code: loc_1af79 from _f2_draw_waves2:8-51*/
loc_1af79:
	_push(cx);
	_push(si);
	_push(di);
	bp = ds.word(di);
	dx = 0x3CE;
	al = 8;
	// _out(dx, al);
	al = 0x80;
loc_1af86:
	ah = 37;
	dx = 0x3CF;
	// _out(dx, al);
	bx = bp;
loc_1af8e:
	di = gs.byte(si);
	_neg(di);
	cx = di;
	_shl(di, 6);
	_shl(cx, 4);
	_add(di, cx);
	cx = ds.word(bx+di);
	_or(cx, cx);
		_js(loc_1afae);
	_cmp(cx, 22400);
		_jnc(loc_1afae);
	_and(es.byte(bx+di), 0x7);
loc_1afae:
	_add(si, 8);
	_inc(bx);
	_dec(ah);
		_jnz(loc_1af8e);
	_sub(si, 0x128);
	_inc(si);
	_shr(al, 1);
		_jnc(loc_1af86);
	_pop(di);
	_pop(si);
	_pop(cx);
	_add(si, 0x128);
	_add(di, 2);
	_dec(cx);
		_jnz(loc_1af79);
	loc_1ae7e;
loc_1af79:
}

void InertiaPlayerContext::_init_f5_spectr() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_1de70), 4);
		_jz(locret_1b083);
	data.byte(k_byte_1de70) = 4;
	ax = 0x13;
	// _int(0x10);
	_set_egasequencer();
	dx = 0x3C8;
	al = 0;
	// _out(dx, al);
	$+2;
	$+2;
	_inc(dx);
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	$+2;
	bp = 0x16C;
	bx = 0;
loc_1affe:
	al = bh;
	// _out(dx, al);
	$+2;
	al = 0x3F;
	// _out(dx, al);
	$+2;
	al = 0;
	// _out(dx, al);
	$+2;
	_add(bx, bp);
	_cmp(bh, 0x40);
		_jc(loc_1affe);
loc_1b014:
	_sub(bx, bp);
	al = 0x3F;
	// _out(dx, al);
	$+2;
	al = bh;
	// _out(dx, al);
	$+2;
	al = 0;
	// _out(dx, al);
	$+2;
	_or(bh, bh);
		_jns(loc_1b014);
	dx = 0x3C8;
	al = 0x0FC;
	// _out(dx, al);
	$+2;
	$+2;
	_inc(dx);
	al = 0;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	$+2;
	al = 0x10;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	$+2;
	al = 0x30;
	// _out(dx, al);
	$+2;
	al = 0x10;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	$+2;
	al = 0x3F;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	_graph_1c070();
	ax = ds;
	es = ax;
	di = 2580;
	cx = 0x0C8;
	eax = 0;
	_write_df(false);
 	while(cx--)
		_stosd();
	ax = 0x200;
	_test(data.word(k_configword), 8);
		_jnz(loc_1b080);
	_shr(ax, 1);
loc_1b080:
	data.word(k_word_24524) = ax;
locret_1b083:
	return;
	return;
/*continuing to unbounded code: loc_1affe from _init_f5_spectr:21-97*/
loc_1affe:
	al = bh;
	// _out(dx, al);
	$+2;
	al = 0x3F;
	// _out(dx, al);
	$+2;
	al = 0;
	// _out(dx, al);
	$+2;
	_add(bx, bp);
	_cmp(bh, 0x40);
		_jc(loc_1affe);
loc_1b014:
	_sub(bx, bp);
	al = 0x3F;
	// _out(dx, al);
	$+2;
	al = bh;
	// _out(dx, al);
	$+2;
	al = 0;
	// _out(dx, al);
	$+2;
	_or(bh, bh);
		_jns(loc_1b014);
	dx = 0x3C8;
	al = 0x0FC;
	// _out(dx, al);
	$+2;
	$+2;
	_inc(dx);
	al = 0;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	$+2;
	al = 0x10;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	$+2;
	al = 0x30;
	// _out(dx, al);
	$+2;
	al = 0x10;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	$+2;
	al = 0x3F;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	$+2;
	// _out(dx, al);
	_graph_1c070();
	ax = ds;
	es = ax;
	di = 2580;
	cx = 0x0C8;
	eax = 0;
	_write_df(false);
 	while(cx--)
		_stosd();
	ax = 0x200;
	_test(data.word(k_configword), 8);
		_jnz(loc_1b080);
	_shr(ax, 1);
loc_1b080:
	data.word(k_word_24524) = ax;
locret_1b083:
	return;
loc_1affe:
}

void InertiaPlayerContext::_spectr_1b084() {
	STACK_CHECK;
	data.word(k_word_2450e) = di;
	al = 1;
	_cmp(al, 1);
		_jnz(loc_1b240);
	_spectr_1b406();
	ax = data.word(k_word_24514);
	si = 0;
loc_1b098:
	_add(si, 4);
	_shr(ax, 1);
	_test(ax, ax);
		_jnz(loc_1b098);
	_sub(si, 4);
	ebx = data.dword(k_tabledword_24526)[si];
	data.dword(k_multip_244d0) = ebx;
	eax = data.dword(k_tabledword_24562)[si];
	data.dword(k_multip_244cc) = eax;
	_add(eax, 0x10000);
	data.dword(k_dword_244c8) = eax;
	data.dword(k_dword_244d4) = ebx;
	cx = data.word(k_word_24514);
	_shr(cx, 1);
	ax = 2;
loc_1b0cf:
	_push(cx);
	_push(ax);
	_shl(ax, 1);
	_dec(ax);
	di = ax;
	_inc(ax);
	_neg(ax);
	_add(ax, 3);
	_add(ax, data.word(k_word_24514));
	_add(ax, data.word(k_word_24514));
	si = ax;
	eax = data.dword(k_dword_244c8);
	data.dword(k_dword_244f4) = eax;
	eax = data.dword(k_dword_244d4);
	data.dword(k_dword_244f8) = eax;
	_dec(si);
	_shl(si, 2);
	_dec(di);
	_shl(di, 2);
	_add(si, data.word(k_word_2450e));
	_add(di, data.word(k_word_2450e));
	eax = ds.dword(di);
	_add(eax, ds.dword(si));
	_sar(eax1);
	data.dword(k_dword_244e4) = eax;
	eax = ds.dword(di+4);
	_sub(eax, ds.dword(si+4));
	_sar(eax1);
	data.dword(k_dword_244e8) = eax;
	eax = ds.dword(di+4);
	_add(eax, ds.dword(si+4));
	_sar(eax1);
	data.dword(k_dword_244ec) = eax;
	eax = ds.dword(si);
	_sub(eax, ds.dword(di));
	_sar(eax1);
	data.dword(k_dword_244f0) = eax;
	ecx = data.dword(k_dword_244f4);
	eax = data.dword(k_dword_244ec);
	_mul(ecx);
	_shrd(eax, edx, 16);
	data.dword(k_dword_244fc) = eax;
	eax = data.dword(k_dword_244f0);
	_mul(ecx);
	_shrd(eax, edx, 16);
	data.dword(k_dword_24500) = eax;
	ecx = data.dword(k_dword_244f8);
	eax = data.dword(k_dword_244ec);
	_mul(ecx);
	_shrd(eax, edx, 16);
	data.dword(k_dword_24508) = eax;
	eax = data.dword(k_dword_244f0);
	_mul(ecx);
	_shrd(eax, edx, 16);
	data.dword(k_dword_24504) = eax;
	eax = data.dword(k_dword_244e4);
	_add(eax, data.dword(k_dword_244fc));
	_sub(eax, data.dword(k_dword_24504));
	ds.dword(di) = eax;
	eax = data.dword(k_dword_244e8);
	_add(eax, data.dword(k_dword_24500));
	_add(eax, data.dword(k_dword_24508));
	ds.dword(di+4) = eax;
	eax = data.dword(k_dword_244e4);
	_sub(eax, data.dword(k_dword_244fc));
	_add(eax, data.dword(k_dword_24504));
	ds.dword(si) = eax;
	eax = data.dword(k_dword_24500);
	_sub(eax, data.dword(k_dword_244e8));
	_add(eax, data.dword(k_dword_24508));
	ds.dword(si+4) = eax;
	eax = data.dword(k_dword_244c8);
	data.dword(kUnk_244c4) = eax;
	eax = data.dword(k_multip_244cc);
	_mul(data.dword(k_dword_244c8));
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244c8), eax);
	eax = data.dword(k_dword_244d4);
	_mul(data.dword(k_multip_244d0));
	_shrd(eax, edx, 0x10);
	_sub(data.dword(k_dword_244c8), eax);
	eax = data.dword(k_dword_244d4);
	_mul(data.dword(k_multip_244cc));
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244d4), eax);
	eax = data.dword(kUnk_244c4);
	_mul(data.dword(k_multip_244d0));
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244d4), eax);
	_pop(ax);
	_pop(cx);
	_inc(ax);
	_dec(cx);
		_jnz(loc_1b0cf);
	si = data.word(k_word_2450e);
	eax = ds.dword(si);
	ebx = ds.dword(si+4);
	_add(ds.dword(si), ebx);
	_sub(eax, ebx);
	ds.dword(si+4) = eax;
	return;
loc_1b240:
	ax = data.word(k_word_24514);
	si = 0;
loc_1b245:
	_add(si, 4);
	_shr(ax, 1);
	_test(ax, ax);
		_jnz(loc_1b245);
	_sub(si, 4);
	ebx = data.dword(k_tabledword_24526)[si];
	_neg(ebx);
	data.dword(k_multip_244d0) = ebx;
	eax = data.dword(k_tabledword_24562)[si];
	_neg(eax);
	data.dword(k_multip_244cc) = eax;
	_add(eax, 0x10000);
	data.dword(k_dword_244c8) = eax;
	data.dword(k_dword_244d4) = ebx;
	cx = data.word(k_word_24514);
	_shr(cx, 1);
	ax = 2;
loc_1b282:
	_push(cx);
	_push(ax);
	_shl(ax, 1);
	_dec(ax);
	di = ax;
	_neg(ax);
	_add(ax, 3);
	_add(ax, data.word(k_word_24514));
	_add(ax, data.word(k_word_24514));
	si = ax;
	eax = data.dword(k_dword_244c8);
	data.dword(k_dword_244f4) = eax;
	eax = data.dword(k_dword_244d4);
	data.dword(k_dword_244f8) = eax;
	_dec(si);
	_shl(si, 2);
	_dec(di);
	_shl(di, 2);
	eax = ds.dword(di);
	_add(eax, ds.dword(si));
	_sar(eax1);
	data.dword(k_dword_244e4) = eax;
	eax = ds.dword(di+4);
	_sub(eax, ds.dword(si+4));
	_sar(eax1);
	data.dword(k_dword_244e8) = eax;
	eax = ds.dword(di+4);
	_add(eax, ds.dword(si+4));
	_neg(eax);
	_sar(eax1);
	data.dword(k_dword_244ec) = eax;
	eax = ds.dword(di);
	_sub(eax, ds.dword(si));
	_sar(eax1);
	data.dword(k_dword_244f0) = eax;
	ecx = data.dword(k_dword_244f4);
	eax = data.dword(k_dword_244ec);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	data.dword(k_dword_244fc) = eax;
	eax = data.dword(k_dword_244f0);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	data.dword(k_dword_24500) = eax;
	ecx = data.dword(k_dword_244f8);
	eax = data.dword(k_dword_244ec);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	data.dword(k_dword_24508) = eax;
	eax = data.dword(k_dword_244f0);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	data.dword(k_dword_24504) = eax;
	eax = data.dword(k_dword_244e4);
	_add(eax, data.dword(k_dword_244fc));
	_sub(eax, data.dword(k_dword_24504));
	ds.dword(di) = eax;
	eax = data.dword(k_dword_244e8);
	_add(eax, data.dword(k_dword_24500));
	_add(eax, data.dword(k_dword_24508));
	ds.dword(di+4) = eax;
	eax = data.dword(k_dword_244e4);
	_sub(eax, data.dword(k_dword_244fc));
	_add(eax, data.dword(k_dword_24504));
	ds.dword(si) = eax;
	eax = data.dword(k_dword_24500);
	_sub(eax, data.dword(k_dword_244e8));
	_add(eax, data.dword(k_dword_24508));
	ds.dword(si+4) = eax;
	eax = data.dword(k_dword_244c8);
	data.dword(kUnk_244c4) = eax;
	eax = data.dword(k_dword_244c8);
	data.dword(kUnk_244c4) = eax;
	eax = data.dword(k_multip_244cc);
	_mul(data.dword(k_dword_244c8));
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244c8), eax);
	eax = data.dword(k_dword_244d4);
	_mul(data.dword(k_multip_244d0));
	_shrd(eax, edx, 0x10);
	_sub(data.dword(k_dword_244c8), eax);
	eax = data.dword(k_dword_244d4);
	_mul(data.dword(k_multip_244cc));
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244d4), eax);
	eax = data.dword(kUnk_244c4);
	_mul(data.dword(k_multip_244d0));
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244d4), eax);
	_pop(ax);
	_pop(cx);
	_inc(ax);
	_dec(cx);
		_jnz(loc_1b282);
	si = data.word(k_word_2450e);
	eax = ds.dword(si);
	ebx = ds.dword(si+4);
	ecx = eax;
	_add(ecx, ebx);
	_sar(ecx1);
	ds.dword(si) = ecx;
	ecx = eax;
	_sub(ecx, ebx);
	_sar(ecx1);
	ds.dword(si) = ecx;
	_spectr_1b406();
	return;
	return;
/*continuing to unbounded code: loc_1b098 from _spectr_1b084:8-256*/
loc_1b098:
	_add(si, 4);
	_shr(ax, 1);
	_test(ax, ax);
		_jnz(loc_1b098);
	_sub(si, 4);
	ebx = data.dword(k_tabledword_24526)[si];
	data.dword(k_multip_244d0) = ebx;
	eax = data.dword(k_tabledword_24562)[si];
	data.dword(k_multip_244cc) = eax;
	_add(eax, 0x10000);
	data.dword(k_dword_244c8) = eax;
	data.dword(k_dword_244d4) = ebx;
	cx = data.word(k_word_24514);
	_shr(cx, 1);
	ax = 2;
loc_1b0cf:
	_push(cx);
	_push(ax);
	_shl(ax, 1);
	_dec(ax);
	di = ax;
	_inc(ax);
	_neg(ax);
	_add(ax, 3);
	_add(ax, data.word(k_word_24514));
	_add(ax, data.word(k_word_24514));
	si = ax;
	eax = data.dword(k_dword_244c8);
	data.dword(k_dword_244f4) = eax;
	eax = data.dword(k_dword_244d4);
	data.dword(k_dword_244f8) = eax;
	_dec(si);
	_shl(si, 2);
	_dec(di);
	_shl(di, 2);
	_add(si, data.word(k_word_2450e));
	_add(di, data.word(k_word_2450e));
	eax = ds.dword(di);
	_add(eax, ds.dword(si));
	_sar(eax1);
	data.dword(k_dword_244e4) = eax;
	eax = ds.dword(di+4);
	_sub(eax, ds.dword(si+4));
	_sar(eax1);
	data.dword(k_dword_244e8) = eax;
	eax = ds.dword(di+4);
	_add(eax, ds.dword(si+4));
	_sar(eax1);
	data.dword(k_dword_244ec) = eax;
	eax = ds.dword(si);
	_sub(eax, ds.dword(di));
	_sar(eax1);
	data.dword(k_dword_244f0) = eax;
	ecx = data.dword(k_dword_244f4);
	eax = data.dword(k_dword_244ec);
	_mul(ecx);
	_shrd(eax, edx, 16);
	data.dword(k_dword_244fc) = eax;
	eax = data.dword(k_dword_244f0);
	_mul(ecx);
	_shrd(eax, edx, 16);
	data.dword(k_dword_24500) = eax;
	ecx = data.dword(k_dword_244f8);
	eax = data.dword(k_dword_244ec);
	_mul(ecx);
	_shrd(eax, edx, 16);
	data.dword(k_dword_24508) = eax;
	eax = data.dword(k_dword_244f0);
	_mul(ecx);
	_shrd(eax, edx, 16);
	data.dword(k_dword_24504) = eax;
	eax = data.dword(k_dword_244e4);
	_add(eax, data.dword(k_dword_244fc));
	_sub(eax, data.dword(k_dword_24504));
	ds.dword(di) = eax;
	eax = data.dword(k_dword_244e8);
	_add(eax, data.dword(k_dword_24500));
	_add(eax, data.dword(k_dword_24508));
	ds.dword(di+4) = eax;
	eax = data.dword(k_dword_244e4);
	_sub(eax, data.dword(k_dword_244fc));
	_add(eax, data.dword(k_dword_24504));
	ds.dword(si) = eax;
	eax = data.dword(k_dword_24500);
	_sub(eax, data.dword(k_dword_244e8));
	_add(eax, data.dword(k_dword_24508));
	ds.dword(si+4) = eax;
	eax = data.dword(k_dword_244c8);
	data.dword(kUnk_244c4) = eax;
	eax = data.dword(k_multip_244cc);
	_mul(data.dword(k_dword_244c8));
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244c8), eax);
	eax = data.dword(k_dword_244d4);
	_mul(data.dword(k_multip_244d0));
	_shrd(eax, edx, 0x10);
	_sub(data.dword(k_dword_244c8), eax);
	eax = data.dword(k_dword_244d4);
	_mul(data.dword(k_multip_244cc));
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244d4), eax);
	eax = data.dword(kUnk_244c4);
	_mul(data.dword(k_multip_244d0));
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244d4), eax);
	_pop(ax);
	_pop(cx);
	_inc(ax);
	_dec(cx);
		_jnz(loc_1b0cf);
	si = data.word(k_word_2450e);
	eax = ds.dword(si);
	ebx = ds.dword(si+4);
	_add(ds.dword(si), ebx);
	_sub(eax, ebx);
	ds.dword(si+4) = eax;
	return;
loc_1b240:
	ax = data.word(k_word_24514);
	si = 0;
loc_1b245:
	_add(si, 4);
	_shr(ax, 1);
	_test(ax, ax);
		_jnz(loc_1b245);
	_sub(si, 4);
	ebx = data.dword(k_tabledword_24526)[si];
	_neg(ebx);
	data.dword(k_multip_244d0) = ebx;
	eax = data.dword(k_tabledword_24562)[si];
	_neg(eax);
	data.dword(k_multip_244cc) = eax;
	_add(eax, 0x10000);
	data.dword(k_dword_244c8) = eax;
	data.dword(k_dword_244d4) = ebx;
	cx = data.word(k_word_24514);
	_shr(cx, 1);
	ax = 2;
loc_1b282:
	_push(cx);
	_push(ax);
	_shl(ax, 1);
	_dec(ax);
	di = ax;
	_neg(ax);
	_add(ax, 3);
	_add(ax, data.word(k_word_24514));
	_add(ax, data.word(k_word_24514));
	si = ax;
	eax = data.dword(k_dword_244c8);
	data.dword(k_dword_244f4) = eax;
	eax = data.dword(k_dword_244d4);
	data.dword(k_dword_244f8) = eax;
	_dec(si);
	_shl(si, 2);
	_dec(di);
	_shl(di, 2);
	eax = ds.dword(di);
	_add(eax, ds.dword(si));
	_sar(eax1);
	data.dword(k_dword_244e4) = eax;
	eax = ds.dword(di+4);
	_sub(eax, ds.dword(si+4));
	_sar(eax1);
	data.dword(k_dword_244e8) = eax;
	eax = ds.dword(di+4);
	_add(eax, ds.dword(si+4));
	_neg(eax);
	_sar(eax1);
	data.dword(k_dword_244ec) = eax;
	eax = ds.dword(di);
	_sub(eax, ds.dword(si));
	_sar(eax1);
	data.dword(k_dword_244f0) = eax;
	ecx = data.dword(k_dword_244f4);
	eax = data.dword(k_dword_244ec);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	data.dword(k_dword_244fc) = eax;
	eax = data.dword(k_dword_244f0);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	data.dword(k_dword_24500) = eax;
	ecx = data.dword(k_dword_244f8);
	eax = data.dword(k_dword_244ec);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	data.dword(k_dword_24508) = eax;
	eax = data.dword(k_dword_244f0);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	data.dword(k_dword_24504) = eax;
	eax = data.dword(k_dword_244e4);
	_add(eax, data.dword(k_dword_244fc));
	_sub(eax, data.dword(k_dword_24504));
	ds.dword(di) = eax;
	eax = data.dword(k_dword_244e8);
	_add(eax, data.dword(k_dword_24500));
	_add(eax, data.dword(k_dword_24508));
	ds.dword(di+4) = eax;
	eax = data.dword(k_dword_244e4);
	_sub(eax, data.dword(k_dword_244fc));
	_add(eax, data.dword(k_dword_24504));
	ds.dword(si) = eax;
	eax = data.dword(k_dword_24500);
	_sub(eax, data.dword(k_dword_244e8));
	_add(eax, data.dword(k_dword_24508));
	ds.dword(si+4) = eax;
	eax = data.dword(k_dword_244c8);
	data.dword(kUnk_244c4) = eax;
	eax = data.dword(k_dword_244c8);
	data.dword(kUnk_244c4) = eax;
	eax = data.dword(k_multip_244cc);
	_mul(data.dword(k_dword_244c8));
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244c8), eax);
	eax = data.dword(k_dword_244d4);
	_mul(data.dword(k_multip_244d0));
	_shrd(eax, edx, 0x10);
	_sub(data.dword(k_dword_244c8), eax);
	eax = data.dword(k_dword_244d4);
	_mul(data.dword(k_multip_244cc));
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244d4), eax);
	eax = data.dword(kUnk_244c4);
	_mul(data.dword(k_multip_244d0));
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244d4), eax);
	_pop(ax);
	_pop(cx);
	_inc(ax);
	_dec(cx);
		_jnz(loc_1b282);
	si = data.word(k_word_2450e);
	eax = ds.dword(si);
	ebx = ds.dword(si+4);
	ecx = eax;
	_add(ecx, ebx);
	_sar(ecx1);
	ds.dword(si) = ecx;
	ecx = eax;
	_sub(ecx, ebx);
	_sar(ecx1);
	ds.dword(si) = ecx;
	_spectr_1b406();
	return;
loc_1b098:
}

void InertiaPlayerContext::_spectr_1b406() {
	STACK_CHECK;
	data.word(k_word_2450e) = di;
	data.word(k_word_2450c) = 0;
	cx = data.word(k_word_24520);
	_shl(cx, 1);
	data.word(k_word_24522) = cx;
	si = data.word(k_word_2450e);
	_shr(cx, 1);
	di = data.word(k_word_2450e);
	bp = di;
loc_1b426:
	_push(cx);
	_cmp(si, di);
		_jle(loc_1b440);
	edx = ds.dword(si);
	ebx = ds.dword(si+4);
	_xchg(edx, ds.dword(di));
	_xchg(ebx, ds.dword(di+4));
	ds.dword(si) = edx;
	ds.dword(si+4) = ebx;
loc_1b440:
	_sub(si, bp);
	_shr(si, 2);
	ax = data.word(k_word_24522);
	_shr(ax, 1);
loc_1b44a:
	_cmp(ax, 2);
		_jl(loc_1b459);
	_cmp(si, ax);
		_jl(loc_1b459);
	_sub(si, ax);
	_shr(ax, 1);
	loc_1b44a;
loc_1b459:
	_add(si, ax);
	_shl(si, 2);
	_add(si, bp);
	_pop(cx);
	_add(di, 8);
	_dec(cx);
		_jnz(loc_1b426);
	data.word(k_word_24516) = 2;
loc_1b46d:
	ax = data.word(k_word_24516);
	_cmp(data.word(k_word_24522), ax);
		_jle(locret_1b5c7);
	_shl(ax, 1);
	data.word(k_word_2451c) = ax;
	si = data.word(k_word_2450c);
	eax = data.dword(k_tabledword_24526)[si];
	data.dword(k_multip_244d0) = eax;
	eax = data.dword(k_tabledword_24562)[si];
	data.dword(k_multip_244cc) = eax;
	_add(data.word(k_word_2450c), 4);
	data.dword(k_dword_244c8) = 0x10000;
	data.dword(k_dword_244d4) = 0;
	cx = data.word(k_word_24516);
	_shr(cx, 1);
	ax = 1;
loc_1b4b3:
	_push(cx);
	_push(ax);
	_shl(ax, 1);
	_dec(ax);
	data.word(k_word_24518) = ax;
	ax = data.word(k_word_24522);
	_sub(ax, data.word(k_word_24518));
	_cwd();
	_div(data.word(k_word_2451c));
	cx = ax;
	_inc(cx);
	ax = 0;
loc_1b4cd:
	_push(cx);
	_push(ax);
	_mul(data.word(k_word_2451c));
	_add(ax, data.word(k_word_24518));
	data.word(k_word_2451e) = ax;
	_add(ax, data.word(k_word_24516));
	data.word(k_word_2451a) = ax;
	si = data.word(k_word_2451a);
	_dec(si);
	_shl(si, 2);
	_add(si, data.word(k_word_2450e));
	di = data.word(k_word_2451e);
	_dec(di);
	_shl(di, 2);
	_add(di, data.word(k_word_2450e));
	ecx = data.dword(k_dword_244c8);
	ebp = data.dword(k_dword_244d4);
	eax = ds.dword(si);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	ebx = eax;
	eax = ds.dword(si+4);
	_mul(ebp);
	_shrd(eax, edx, 0x10);
	_sub(ebx, eax);
	eax = ds.dword(si+4);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	ecx = eax;
	eax = ds.dword(si);
	_mul(ebp);
	_shrd(eax, edx, 0x10);
	_add(ecx, eax);
	eax = ds.dword(di);
	_sub(eax, ebx);
	ds.dword(si) = eax;
	eax = ds.dword(di+4);
	_sub(eax, ecx);
	ds.dword(si+4) = eax;
	_add(ds.dword(di), ebx);
	_add(ds.dword(di+4), ecx);
	_pop(ax);
	_pop(cx);
	_inc(ax);
	_dec(cx);
		_jnz(loc_1b4cd);
	ecx = data.dword(k_multip_244cc);
	ebp = data.dword(k_multip_244d0);
	eax = data.dword(k_dword_244c8);
	data.dword(kUnk_244c4) = eax;
	eax = data.dword(k_dword_244c8);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244c8), eax);
	eax = data.dword(k_dword_244d4);
	_mul(ebp);
	_shrd(eax, edx, 0x10);
	_sub(data.dword(k_dword_244c8), eax);
	eax = data.dword(k_dword_244d4);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244d4), eax);
	eax = data.dword(kUnk_244c4);
	_mul(ebp);
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244d4), eax);
	_pop(ax);
	_pop(cx);
	_inc(ax);
	_dec(cx);
		_jnz(loc_1b4b3);
	ax = data.word(k_word_2451c);
	data.word(k_word_24516) = ax;
	loc_1b46d;
locret_1b5c7:
	return;
	return;
/*continuing to unbounded code: loc_1b426 from _spectr_1b406:10-148*/
loc_1b426:
	_push(cx);
	_cmp(si, di);
		_jle(loc_1b440);
	edx = ds.dword(si);
	ebx = ds.dword(si+4);
	_xchg(edx, ds.dword(di));
	_xchg(ebx, ds.dword(di+4));
	ds.dword(si) = edx;
	ds.dword(si+4) = ebx;
loc_1b440:
	_sub(si, bp);
	_shr(si, 2);
	ax = data.word(k_word_24522);
	_shr(ax, 1);
loc_1b44a:
	_cmp(ax, 2);
		_jl(loc_1b459);
	_cmp(si, ax);
		_jl(loc_1b459);
	_sub(si, ax);
	_shr(ax, 1);
	loc_1b44a;
loc_1b459:
	_add(si, ax);
	_shl(si, 2);
	_add(si, bp);
	_pop(cx);
	_add(di, 8);
	_dec(cx);
		_jnz(loc_1b426);
	data.word(k_word_24516) = 2;
loc_1b46d:
	ax = data.word(k_word_24516);
	_cmp(data.word(k_word_24522), ax);
		_jle(locret_1b5c7);
	_shl(ax, 1);
	data.word(k_word_2451c) = ax;
	si = data.word(k_word_2450c);
	eax = data.dword(k_tabledword_24526)[si];
	data.dword(k_multip_244d0) = eax;
	eax = data.dword(k_tabledword_24562)[si];
	data.dword(k_multip_244cc) = eax;
	_add(data.word(k_word_2450c), 4);
	data.dword(k_dword_244c8) = 0x10000;
	data.dword(k_dword_244d4) = 0;
	cx = data.word(k_word_24516);
	_shr(cx, 1);
	ax = 1;
loc_1b4b3:
	_push(cx);
	_push(ax);
	_shl(ax, 1);
	_dec(ax);
	data.word(k_word_24518) = ax;
	ax = data.word(k_word_24522);
	_sub(ax, data.word(k_word_24518));
	_cwd();
	_div(data.word(k_word_2451c));
	cx = ax;
	_inc(cx);
	ax = 0;
loc_1b4cd:
	_push(cx);
	_push(ax);
	_mul(data.word(k_word_2451c));
	_add(ax, data.word(k_word_24518));
	data.word(k_word_2451e) = ax;
	_add(ax, data.word(k_word_24516));
	data.word(k_word_2451a) = ax;
	si = data.word(k_word_2451a);
	_dec(si);
	_shl(si, 2);
	_add(si, data.word(k_word_2450e));
	di = data.word(k_word_2451e);
	_dec(di);
	_shl(di, 2);
	_add(di, data.word(k_word_2450e));
	ecx = data.dword(k_dword_244c8);
	ebp = data.dword(k_dword_244d4);
	eax = ds.dword(si);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	ebx = eax;
	eax = ds.dword(si+4);
	_mul(ebp);
	_shrd(eax, edx, 0x10);
	_sub(ebx, eax);
	eax = ds.dword(si+4);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	ecx = eax;
	eax = ds.dword(si);
	_mul(ebp);
	_shrd(eax, edx, 0x10);
	_add(ecx, eax);
	eax = ds.dword(di);
	_sub(eax, ebx);
	ds.dword(si) = eax;
	eax = ds.dword(di+4);
	_sub(eax, ecx);
	ds.dword(si+4) = eax;
	_add(ds.dword(di), ebx);
	_add(ds.dword(di+4), ecx);
	_pop(ax);
	_pop(cx);
	_inc(ax);
	_dec(cx);
		_jnz(loc_1b4cd);
	ecx = data.dword(k_multip_244cc);
	ebp = data.dword(k_multip_244d0);
	eax = data.dword(k_dword_244c8);
	data.dword(kUnk_244c4) = eax;
	eax = data.dword(k_dword_244c8);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244c8), eax);
	eax = data.dword(k_dword_244d4);
	_mul(ebp);
	_shrd(eax, edx, 0x10);
	_sub(data.dword(k_dword_244c8), eax);
	eax = data.dword(k_dword_244d4);
	_mul(ecx);
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244d4), eax);
	eax = data.dword(kUnk_244c4);
	_mul(ebp);
	_shrd(eax, edx, 0x10);
	_add(data.dword(k_dword_244d4), eax);
	_pop(ax);
	_pop(cx);
	_inc(ax);
	_dec(cx);
		_jnz(loc_1b4b3);
	ax = data.word(k_word_2451c);
	data.word(k_word_24516) = ax;
	loc_1b46d;
locret_1b5c7:
	return;
loc_1b426:
}

void InertiaPlayerContext::_f5_draw_spectr() {
	STACK_CHECK;
	ax = ds;
	es = ax;
	di = 2571;
	cx = 0x200;
	ax = 0x4001;
	_volume_prep();
	bx = data.dword(k_segfsbx_1de28);
	si = 2571;
	di = 2586;
	bp = data.word(k_amount_of_x);
loc_1b5ec:
	cx = bp;
	dx = 0;
	_cmp(fs.byte(bx+0x3A), 64);
		_ja(loc_1b5fc);
	al = ds.byte(si);
	_cbw();
	_add(dx, ax);
loc_1b5fc:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x8A), 64);
		_ja(loc_1b610);
	al = ds.byte(si+0x200);
	_cbw();
	_add(dx, ax);
loc_1b610:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x0DA), 64);
		_ja(loc_1b624);
	al = ds.byte(si+0x400);
	_cbw();
	_add(dx, ax);
loc_1b624:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x12A), 64);
		_ja(loc_1b638);
	al = ds.byte(si+0x600);
	_cbw();
	_add(dx, ax);
loc_1b638:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x17A), 64);
		_ja(loc_1b64c);
	al = ds.byte(si+0x800);
	_cbw();
	_add(dx, ax);
loc_1b64c:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x1CA), 64);
		_ja(loc_1b660);
	al = ds.byte(si+0x0A00);
	_cbw();
	_add(dx, ax);
loc_1b660:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x21A), 64);
		_ja(loc_1b674);
	al = ds.byte(si+0x0C00);
	_cbw();
	_add(dx, ax);
loc_1b674:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x26A), 64);
		_ja(loc_1b688);
	al = ds.byte(si+0x0E00);
	_cbw();
	_add(dx, ax);
loc_1b688:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x2BA), 64);
		_ja(loc_1b69c);
	al = ds.byte(si+0x1000);
	_cbw();
	_add(dx, ax);
loc_1b69c:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x30A), 64);
		_ja(loc_1b6b0);
	al = ds.byte(si+0x1200);
	_cbw();
	_add(dx, ax);
loc_1b6b0:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x35A), 64);
		_ja(loc_1b6c4);
	al = ds.byte(si+0x1400);
	_cbw();
	_add(dx, ax);
loc_1b6c4:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x3AA), 64);
		_ja(loc_1b6d8);
	al = ds.byte(si+0x1600);
	_cbw();
	_add(dx, ax);
loc_1b6d8:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x3FA), 64);
		_ja(loc_1b6ec);
	al = ds.byte(si+0x1800);
	_cbw();
	_add(dx, ax);
loc_1b6ec:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x44A), 64);
		_ja(loc_1b700);
	al = ds.byte(si+0x1A00);
	_cbw();
	_add(dx, ax);
loc_1b700:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x49A), 64);
		_ja(loc_1b714);
	al = ds.byte(si+0x1C00);
	_cbw();
	_add(dx, ax);
loc_1b714:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x4EA), 0x40);
		_ja(loc_1b728);
	al = ds.byte(si+0x1E00);
	_cbw();
	_add(dx, ax);
loc_1b728:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x53A), 0x40);
		_ja(loc_1b73c);
	al = ds.byte(si+0x2000);
	_cbw();
	_add(dx, ax);
loc_1b73c:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x58A), 0x40);
		_ja(loc_1b750);
	al = ds.byte(si+0x2200);
	_cbw();
	_add(dx, ax);
loc_1b750:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x5DA), 0x40);
		_ja(loc_1b764);
	al = ds.byte(si+0x2400);
	_cbw();
	_add(dx, ax);
loc_1b764:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x62A), 0x40);
		_ja(loc_1b778);
	al = ds.byte(si+0x2600);
	_cbw();
	_add(dx, ax);
loc_1b778:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x67A), 0x40);
		_ja(loc_1b78c);
	al = ds.byte(si+0x2800);
	_cbw();
	_add(dx, ax);
loc_1b78c:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x6CA), 0x40);
		_ja(loc_1b7a0);
	al = ds.byte(si+0x2A00);
	_cbw();
	_add(dx, ax);
loc_1b7a0:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x71A), 0x40);
		_ja(loc_1b7b4);
	al = ds.byte(si+0x2C00);
	_cbw();
	_add(dx, ax);
loc_1b7b4:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x76A), 0x40);
		_ja(loc_1b7c8);
	al = ds.byte(si+0x2E00);
	_cbw();
	_add(dx, ax);
loc_1b7c8:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x7BA), 0x40);
		_ja(loc_1b7dc);
	al = ds.byte(si+0x3000);
	_cbw();
	_add(dx, ax);
loc_1b7dc:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x80A), 0x40);
		_ja(loc_1b7f0);
	al = ds.byte(si+0x3200);
	_cbw();
	_add(dx, ax);
loc_1b7f0:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x85A), 0x40);
		_ja(loc_1b802);
	al = ds.byte(si+0x3400);
	_cbw();
	_add(dx, ax);
loc_1b802:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x8AA), 0x40);
		_ja(loc_1b814);
	al = ds.byte(si+0x3600);
	_cbw();
	_add(dx, ax);
loc_1b814:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x8FA), 0x40);
		_ja(loc_1b826);
	al = ds.byte(si+0x3800);
	_cbw();
	_add(dx, ax);
loc_1b826:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x94A), 0x40);
		_ja(loc_1b838);
	al = ds.byte(si+0x3A00);
	_cbw();
	_add(dx, ax);
loc_1b838:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x99A), 0x40);
		_ja(loc_1b84a);
	al = ds.byte(si+0x3C00);
	_cbw();
	_add(dx, ax);
loc_1b84a:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x9EA), 0x40);
		_ja(loc_1b85c);
	al = ds.byte(si+0x3E00);
	_cbw();
	_add(dx, ax);
loc_1b85c:
	_dec(cx);
		_jz($+2);
loc_1b85f:
	_sar(dx1);
	ds.byte(di) = dl;
	_inc(si);
	_inc(di);
	_cmp(si, 2572);
		_jc(loc_1b5ec);
	si = 2586;
	di = 2579;
	cx = 0x200;
loc_1b876:
	eax = ds.byte(si);
	_shl(eax, 0x10);
	ds.dword(di) = eax;
	ds.dword(di+4) = 0;
	_inc(si);
	_add(di, 8);
	if (--cx)
		loc_1b876;
	ax = data.word(k_word_24524);
	data.word(k_word_24520) = ax;
	data.word(k_word_24514) = ax;
	di = 2579;
	_spectr_1b406();
	si = 2579;
	di = 2580;
	cx = 0x64;
	_spectr_1bbc1();
	bx = data.dword(k_segfsbx_1de28);
	si = 2571;
	di = 2586;
	bp = data.word(k_amount_of_x);
loc_1b8bc:
	cx = bp;
	dx = 0;
	_cmp(fs.byte(bx+0x3A), 0x40);
		_jc(loc_1b8cc);
	al = ds.byte(si);
	_cbw();
	_add(dx, ax);
loc_1b8cc:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x8A), 0x40);
		_jc(loc_1b8e0);
	al = ds.byte(si+0x200);
	_cbw();
	_add(dx, ax);
loc_1b8e0:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x0DA), 0x40);
		_jc(loc_1b8f4);
	al = ds.byte(si+0x400);
	_cbw();
	_add(dx, ax);
loc_1b8f4:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x12A), 0x40);
		_jc(loc_1b908);
	al = ds.byte(si+0x600);
	_cbw();
	_add(dx, ax);
loc_1b908:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x17A), 0x40);
		_jc(loc_1b91c);
	al = ds.byte(si+0x800);
	_cbw();
	_add(dx, ax);
loc_1b91c:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x1CA), 0x40);
		_jc(loc_1b930);
	al = ds.byte(si+0x0A00);
	_cbw();
	_add(dx, ax);
loc_1b930:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x21A), 0x40);
		_jc(loc_1b944);
	al = ds.byte(si+0x0C00);
	_cbw();
	_add(dx, ax);
loc_1b944:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x26A), 0x40);
		_jc(loc_1b958);
	al = ds.byte(si+0x0E00);
	_cbw();
	_add(dx, ax);
loc_1b958:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x2BA), 0x40);
		_jc(loc_1b96c);
	al = ds.byte(si+0x1000);
	_cbw();
	_add(dx, ax);
loc_1b96c:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x30A), 0x40);
		_jc(loc_1b980);
	al = ds.byte(si+0x1200);
	_cbw();
	_add(dx, ax);
loc_1b980:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x35A), 0x40);
		_jc(loc_1b994);
	al = ds.byte(si+0x1400);
	_cbw();
	_add(dx, ax);
loc_1b994:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x3AA), 0x40);
		_jc(loc_1b9a8);
	al = ds.byte(si+0x1600);
	_cbw();
	_add(dx, ax);
loc_1b9a8:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x3FA), 0x40);
		_jc(loc_1b9bc);
	al = ds.byte(si+0x1800);
	_cbw();
	_add(dx, ax);
loc_1b9bc:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x44A), 0x40);
		_jc(loc_1b9d0);
	al = ds.byte(si+0x1A00);
	_cbw();
	_add(dx, ax);
loc_1b9d0:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x49A), 0x40);
		_jc(loc_1b9e4);
	al = ds.byte(si+0x1C00);
	_cbw();
	_add(dx, ax);
loc_1b9e4:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x4EA), 0x40);
		_jc(loc_1b9f8);
	al = ds.byte(si+0x1E00);
	_cbw();
	_add(dx, ax);
loc_1b9f8:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x53A), 0x40);
		_jc(loc_1ba0c);
	al = ds.byte(si+0x2000);
	_cbw();
	_add(dx, ax);
loc_1ba0c:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x58A), 0x40);
		_jc(loc_1ba20);
	al = ds.byte(si+0x2200);
	_cbw();
	_add(dx, ax);
loc_1ba20:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x5DA), 0x40);
		_jc(loc_1ba34);
	al = ds.byte(si+0x2400);
	_cbw();
	_add(dx, ax);
loc_1ba34:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x62A), 0x40);
		_jc(loc_1ba48);
	al = ds.byte(si+0x2600);
	_cbw();
	_add(dx, ax);
loc_1ba48:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x67A), 0x40);
		_jc(loc_1ba5c);
	al = ds.byte(si+0x2800);
	_cbw();
	_add(dx, ax);
loc_1ba5c:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x6CA), 0x40);
		_jc(loc_1ba70);
	al = ds.byte(si+0x2A00);
	_cbw();
	_add(dx, ax);
loc_1ba70:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x71A), 0x40);
		_jc(loc_1ba84);
	al = ds.byte(si+0x2C00);
	_cbw();
	_add(dx, ax);
loc_1ba84:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x76A), 0x40);
		_jc(loc_1ba98);
	al = ds.byte(si+0x2E00);
	_cbw();
	_add(dx, ax);
loc_1ba98:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x7BA), 0x40);
		_jc(loc_1baac);
	al = ds.byte(si+0x3000);
	_cbw();
	_add(dx, ax);
loc_1baac:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x80A), 0x40);
		_jc(loc_1bac0);
	al = ds.byte(si+0x3200);
	_cbw();
	_add(dx, ax);
loc_1bac0:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x85A), 0x40);
		_jc(loc_1bad2);
	al = ds.byte(si+0x3400);
	_cbw();
	_add(dx, ax);
loc_1bad2:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x8AA), 0x40);
		_jc(loc_1bae4);
	al = ds.byte(si+0x3600);
	_cbw();
	_add(dx, ax);
loc_1bae4:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x8FA), 0x40);
		_jc(loc_1baf6);
	al = ds.byte(si+0x3800);
	_cbw();
	_add(dx, ax);
loc_1baf6:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x94A), 0x40);
		_jc(loc_1bb08);
	al = ds.byte(si+0x3A00);
	_cbw();
	_add(dx, ax);
loc_1bb08:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x99A), 0x40);
		_jc(loc_1bb1a);
	al = ds.byte(si+0x3C00);
	_cbw();
	_add(dx, ax);
loc_1bb1a:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x9EA), 0x40);
		_jc(loc_1bb2c);
	al = ds.byte(si+0x3E00);
	_cbw();
	_add(dx, ax);
loc_1bb2c:
	_dec(cx);
		_jz($+2);
loc_1bb2f:
	_sar(dx1);
	ds.byte(di) = dl;
	_inc(si);
	_inc(di);
	_cmp(si, 2572);
		_jc(loc_1b8bc);
	si = 2586;
	di = 2579;
	cx = 0x200;
loc_1bb46:
	eax = ds.byte(si);
	_shl(eax, 0x10);
	ds.dword(di) = eax;
	ds.dword(di+4) = 0;
	_inc(si);
	_add(di, 8);
	if (--cx)
		loc_1bb46;
	ax = data.word(k_word_24524);
	data.word(k_word_24520) = ax;
	data.word(k_word_24514) = ax;
	di = 2579;
	_spectr_1b406();
	si = 2579;
	di = 2583;
	cx = 0x64;
	_spectr_1bbc1();
	ax = 0x0A000;
	es = ax;
	bx = 2580;
	bp = 0x7BC4;
	_spectr_1bce9();
	bx = 2581;
	bp = 0x7BD6;
	_spectr_1bc2d();
	bx = 2583;
	bp = 0x0F8C4;
	_spectr_1bce9();
	bx = 2584;
	bp = 0x0F8D6;
	_spectr_1bc2d();
	ax = ds;
	es = ax;
	si = 2580;
	di = 2582;
	cx = 0x19;
	_write_df(false);
 	while(cx--)
		_movsd();
	si = 2583;
	di = 2585;
	cx = 0x19;
	while(cx--)
		_movsd();
	return;
	return;
/*continuing to unbounded code: loc_1b5ec from _f5_draw_spectr:11-614*/
loc_1b5ec:
	cx = bp;
	dx = 0;
	_cmp(fs.byte(bx+0x3A), 64);
		_ja(loc_1b5fc);
	al = ds.byte(si);
	_cbw();
	_add(dx, ax);
loc_1b5fc:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x8A), 64);
		_ja(loc_1b610);
	al = ds.byte(si+0x200);
	_cbw();
	_add(dx, ax);
loc_1b610:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x0DA), 64);
		_ja(loc_1b624);
	al = ds.byte(si+0x400);
	_cbw();
	_add(dx, ax);
loc_1b624:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x12A), 64);
		_ja(loc_1b638);
	al = ds.byte(si+0x600);
	_cbw();
	_add(dx, ax);
loc_1b638:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x17A), 64);
		_ja(loc_1b64c);
	al = ds.byte(si+0x800);
	_cbw();
	_add(dx, ax);
loc_1b64c:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x1CA), 64);
		_ja(loc_1b660);
	al = ds.byte(si+0x0A00);
	_cbw();
	_add(dx, ax);
loc_1b660:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x21A), 64);
		_ja(loc_1b674);
	al = ds.byte(si+0x0C00);
	_cbw();
	_add(dx, ax);
loc_1b674:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x26A), 64);
		_ja(loc_1b688);
	al = ds.byte(si+0x0E00);
	_cbw();
	_add(dx, ax);
loc_1b688:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x2BA), 64);
		_ja(loc_1b69c);
	al = ds.byte(si+0x1000);
	_cbw();
	_add(dx, ax);
loc_1b69c:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x30A), 64);
		_ja(loc_1b6b0);
	al = ds.byte(si+0x1200);
	_cbw();
	_add(dx, ax);
loc_1b6b0:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x35A), 64);
		_ja(loc_1b6c4);
	al = ds.byte(si+0x1400);
	_cbw();
	_add(dx, ax);
loc_1b6c4:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x3AA), 64);
		_ja(loc_1b6d8);
	al = ds.byte(si+0x1600);
	_cbw();
	_add(dx, ax);
loc_1b6d8:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x3FA), 64);
		_ja(loc_1b6ec);
	al = ds.byte(si+0x1800);
	_cbw();
	_add(dx, ax);
loc_1b6ec:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x44A), 64);
		_ja(loc_1b700);
	al = ds.byte(si+0x1A00);
	_cbw();
	_add(dx, ax);
loc_1b700:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x49A), 64);
		_ja(loc_1b714);
	al = ds.byte(si+0x1C00);
	_cbw();
	_add(dx, ax);
loc_1b714:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x4EA), 0x40);
		_ja(loc_1b728);
	al = ds.byte(si+0x1E00);
	_cbw();
	_add(dx, ax);
loc_1b728:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x53A), 0x40);
		_ja(loc_1b73c);
	al = ds.byte(si+0x2000);
	_cbw();
	_add(dx, ax);
loc_1b73c:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x58A), 0x40);
		_ja(loc_1b750);
	al = ds.byte(si+0x2200);
	_cbw();
	_add(dx, ax);
loc_1b750:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x5DA), 0x40);
		_ja(loc_1b764);
	al = ds.byte(si+0x2400);
	_cbw();
	_add(dx, ax);
loc_1b764:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x62A), 0x40);
		_ja(loc_1b778);
	al = ds.byte(si+0x2600);
	_cbw();
	_add(dx, ax);
loc_1b778:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x67A), 0x40);
		_ja(loc_1b78c);
	al = ds.byte(si+0x2800);
	_cbw();
	_add(dx, ax);
loc_1b78c:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x6CA), 0x40);
		_ja(loc_1b7a0);
	al = ds.byte(si+0x2A00);
	_cbw();
	_add(dx, ax);
loc_1b7a0:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x71A), 0x40);
		_ja(loc_1b7b4);
	al = ds.byte(si+0x2C00);
	_cbw();
	_add(dx, ax);
loc_1b7b4:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x76A), 0x40);
		_ja(loc_1b7c8);
	al = ds.byte(si+0x2E00);
	_cbw();
	_add(dx, ax);
loc_1b7c8:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x7BA), 0x40);
		_ja(loc_1b7dc);
	al = ds.byte(si+0x3000);
	_cbw();
	_add(dx, ax);
loc_1b7dc:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x80A), 0x40);
		_ja(loc_1b7f0);
	al = ds.byte(si+0x3200);
	_cbw();
	_add(dx, ax);
loc_1b7f0:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x85A), 0x40);
		_ja(loc_1b802);
	al = ds.byte(si+0x3400);
	_cbw();
	_add(dx, ax);
loc_1b802:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x8AA), 0x40);
		_ja(loc_1b814);
	al = ds.byte(si+0x3600);
	_cbw();
	_add(dx, ax);
loc_1b814:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x8FA), 0x40);
		_ja(loc_1b826);
	al = ds.byte(si+0x3800);
	_cbw();
	_add(dx, ax);
loc_1b826:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x94A), 0x40);
		_ja(loc_1b838);
	al = ds.byte(si+0x3A00);
	_cbw();
	_add(dx, ax);
loc_1b838:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x99A), 0x40);
		_ja(loc_1b84a);
	al = ds.byte(si+0x3C00);
	_cbw();
	_add(dx, ax);
loc_1b84a:
	_dec(cx);
		_jz(loc_1b85f);
	_cmp(fs.byte(bx+0x9EA), 0x40);
		_ja(loc_1b85c);
	al = ds.byte(si+0x3E00);
	_cbw();
	_add(dx, ax);
loc_1b85c:
	_dec(cx);
		_jz($+2);
loc_1b85f:
	_sar(dx1);
	ds.byte(di) = dl;
	_inc(si);
	_inc(di);
	_cmp(si, 2572);
		_jc(loc_1b5ec);
	si = 2586;
	di = 2579;
	cx = 0x200;
loc_1b876:
	eax = ds.byte(si);
	_shl(eax, 0x10);
	ds.dword(di) = eax;
	ds.dword(di+4) = 0;
	_inc(si);
	_add(di, 8);
	if (--cx)
		loc_1b876;
	ax = data.word(k_word_24524);
	data.word(k_word_24520) = ax;
	data.word(k_word_24514) = ax;
	di = 2579;
	_spectr_1b406();
	si = 2579;
	di = 2580;
	cx = 0x64;
	_spectr_1bbc1();
	bx = data.dword(k_segfsbx_1de28);
	si = 2571;
	di = 2586;
	bp = data.word(k_amount_of_x);
loc_1b8bc:
	cx = bp;
	dx = 0;
	_cmp(fs.byte(bx+0x3A), 0x40);
		_jc(loc_1b8cc);
	al = ds.byte(si);
	_cbw();
	_add(dx, ax);
loc_1b8cc:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x8A), 0x40);
		_jc(loc_1b8e0);
	al = ds.byte(si+0x200);
	_cbw();
	_add(dx, ax);
loc_1b8e0:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x0DA), 0x40);
		_jc(loc_1b8f4);
	al = ds.byte(si+0x400);
	_cbw();
	_add(dx, ax);
loc_1b8f4:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x12A), 0x40);
		_jc(loc_1b908);
	al = ds.byte(si+0x600);
	_cbw();
	_add(dx, ax);
loc_1b908:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x17A), 0x40);
		_jc(loc_1b91c);
	al = ds.byte(si+0x800);
	_cbw();
	_add(dx, ax);
loc_1b91c:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x1CA), 0x40);
		_jc(loc_1b930);
	al = ds.byte(si+0x0A00);
	_cbw();
	_add(dx, ax);
loc_1b930:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x21A), 0x40);
		_jc(loc_1b944);
	al = ds.byte(si+0x0C00);
	_cbw();
	_add(dx, ax);
loc_1b944:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x26A), 0x40);
		_jc(loc_1b958);
	al = ds.byte(si+0x0E00);
	_cbw();
	_add(dx, ax);
loc_1b958:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x2BA), 0x40);
		_jc(loc_1b96c);
	al = ds.byte(si+0x1000);
	_cbw();
	_add(dx, ax);
loc_1b96c:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x30A), 0x40);
		_jc(loc_1b980);
	al = ds.byte(si+0x1200);
	_cbw();
	_add(dx, ax);
loc_1b980:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x35A), 0x40);
		_jc(loc_1b994);
	al = ds.byte(si+0x1400);
	_cbw();
	_add(dx, ax);
loc_1b994:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x3AA), 0x40);
		_jc(loc_1b9a8);
	al = ds.byte(si+0x1600);
	_cbw();
	_add(dx, ax);
loc_1b9a8:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x3FA), 0x40);
		_jc(loc_1b9bc);
	al = ds.byte(si+0x1800);
	_cbw();
	_add(dx, ax);
loc_1b9bc:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x44A), 0x40);
		_jc(loc_1b9d0);
	al = ds.byte(si+0x1A00);
	_cbw();
	_add(dx, ax);
loc_1b9d0:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x49A), 0x40);
		_jc(loc_1b9e4);
	al = ds.byte(si+0x1C00);
	_cbw();
	_add(dx, ax);
loc_1b9e4:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x4EA), 0x40);
		_jc(loc_1b9f8);
	al = ds.byte(si+0x1E00);
	_cbw();
	_add(dx, ax);
loc_1b9f8:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x53A), 0x40);
		_jc(loc_1ba0c);
	al = ds.byte(si+0x2000);
	_cbw();
	_add(dx, ax);
loc_1ba0c:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x58A), 0x40);
		_jc(loc_1ba20);
	al = ds.byte(si+0x2200);
	_cbw();
	_add(dx, ax);
loc_1ba20:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x5DA), 0x40);
		_jc(loc_1ba34);
	al = ds.byte(si+0x2400);
	_cbw();
	_add(dx, ax);
loc_1ba34:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x62A), 0x40);
		_jc(loc_1ba48);
	al = ds.byte(si+0x2600);
	_cbw();
	_add(dx, ax);
loc_1ba48:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x67A), 0x40);
		_jc(loc_1ba5c);
	al = ds.byte(si+0x2800);
	_cbw();
	_add(dx, ax);
loc_1ba5c:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x6CA), 0x40);
		_jc(loc_1ba70);
	al = ds.byte(si+0x2A00);
	_cbw();
	_add(dx, ax);
loc_1ba70:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x71A), 0x40);
		_jc(loc_1ba84);
	al = ds.byte(si+0x2C00);
	_cbw();
	_add(dx, ax);
loc_1ba84:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x76A), 0x40);
		_jc(loc_1ba98);
	al = ds.byte(si+0x2E00);
	_cbw();
	_add(dx, ax);
loc_1ba98:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x7BA), 0x40);
		_jc(loc_1baac);
	al = ds.byte(si+0x3000);
	_cbw();
	_add(dx, ax);
loc_1baac:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x80A), 0x40);
		_jc(loc_1bac0);
	al = ds.byte(si+0x3200);
	_cbw();
	_add(dx, ax);
loc_1bac0:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x85A), 0x40);
		_jc(loc_1bad2);
	al = ds.byte(si+0x3400);
	_cbw();
	_add(dx, ax);
loc_1bad2:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x8AA), 0x40);
		_jc(loc_1bae4);
	al = ds.byte(si+0x3600);
	_cbw();
	_add(dx, ax);
loc_1bae4:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x8FA), 0x40);
		_jc(loc_1baf6);
	al = ds.byte(si+0x3800);
	_cbw();
	_add(dx, ax);
loc_1baf6:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x94A), 0x40);
		_jc(loc_1bb08);
	al = ds.byte(si+0x3A00);
	_cbw();
	_add(dx, ax);
loc_1bb08:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x99A), 0x40);
		_jc(loc_1bb1a);
	al = ds.byte(si+0x3C00);
	_cbw();
	_add(dx, ax);
loc_1bb1a:
	_dec(cx);
		_jz(loc_1bb2f);
	_cmp(fs.byte(bx+0x9EA), 0x40);
		_jc(loc_1bb2c);
	al = ds.byte(si+0x3E00);
	_cbw();
	_add(dx, ax);
loc_1bb2c:
	_dec(cx);
		_jz($+2);
loc_1bb2f:
	_sar(dx1);
	ds.byte(di) = dl;
	_inc(si);
	_inc(di);
	_cmp(si, 2572);
		_jc(loc_1b8bc);
	si = 2586;
	di = 2579;
	cx = 0x200;
loc_1bb46:
	eax = ds.byte(si);
	_shl(eax, 0x10);
	ds.dword(di) = eax;
	ds.dword(di+4) = 0;
	_inc(si);
	_add(di, 8);
	if (--cx)
		loc_1bb46;
	ax = data.word(k_word_24524);
	data.word(k_word_24520) = ax;
	data.word(k_word_24514) = ax;
	di = 2579;
	_spectr_1b406();
	si = 2579;
	di = 2583;
	cx = 0x64;
	_spectr_1bbc1();
	ax = 0x0A000;
	es = ax;
	bx = 2580;
	bp = 0x7BC4;
	_spectr_1bce9();
	bx = 2581;
	bp = 0x7BD6;
	_spectr_1bc2d();
	bx = 2583;
	bp = 0x0F8C4;
	_spectr_1bce9();
	bx = 2584;
	bp = 0x0F8D6;
	_spectr_1bc2d();
	ax = ds;
	es = ax;
	si = 2580;
	di = 2582;
	cx = 0x19;
	_write_df(false);
 	while(cx--)
		_movsd();
	si = 2583;
	di = 2585;
	cx = 0x19;
	while(cx--)
		_movsd();
	return;
loc_1b5ec:
}

void InertiaPlayerContext::_spectr_1bbc1() {
	STACK_CHECK;
	_push(cx);
	eax = ds.dword(si);
	_mul(eax);
	ebx = eax;
	ecx = edx;
	eax = ds.dword(si+4);
	_mul(eax);
	eax = edx;
	_add(eax, ebx);
	_adc(edx, ecx);
	eax = edx;
	cl = data.byte(k_byte_1de81);
	_sar(eaxcl);
	ebx = eax;
	_spectr_1c4f8();
	_or(ah, ah);
		_jz(loc_1bbf4);
	al = 0x0FF;
loc_1bbf4:
	_cmp(data.byte(k_byte_1de82), 0);
		_jz(loc_1bc0c);
	ah = ds.byte(di+0x64);
	_sub(ah, data.byte(k_byte_1de82));
		_jnc(loc_1bc06);
	ah = 0;
loc_1bc06:
	_cmp(ah, al);
		_jc(loc_1bc0c);
	al = ah;
loc_1bc0c:
	ds.byte(di) = al;
	_cmp(ds.byte(di+0x12C), 0);
		_jz(loc_1bc1b);
	_cmp(al, ds.byte(di+0x0C8));
		_jc(loc_1bc24);
loc_1bc1b:
	ds.byte(di+0x0C8) = al;
	ds.byte(di+0x12C) = 0x14;
loc_1bc24:
	_inc(di);
	_add(si, 8);
	_pop(cx);
	_dec(cx);
		_jnz({ _spectr_1BBC1(); return; });
	return;
	return;
/*continuing to unbounded code: _spectr_1bbc1 from _spectr_1bbc1:0-45*/
_spectr_1bbc1:
	_push(cx);
	eax = ds.dword(si);
	_mul(eax);
	ebx = eax;
	ecx = edx;
	eax = ds.dword(si+4);
	_mul(eax);
	eax = edx;
	_add(eax, ebx);
	_adc(edx, ecx);
	eax = edx;
	cl = data.byte(k_byte_1de81);
	_sar(eaxcl);
	ebx = eax;
	_spectr_1c4f8();
	_or(ah, ah);
		_jz(loc_1bbf4);
	al = 0x0FF;
loc_1bbf4:
	_cmp(data.byte(k_byte_1de82), 0);
		_jz(loc_1bc0c);
	ah = ds.byte(di+0x64);
	_sub(ah, data.byte(k_byte_1de82));
		_jnc(loc_1bc06);
	ah = 0;
loc_1bc06:
	_cmp(ah, al);
		_jc(loc_1bc0c);
	al = ah;
loc_1bc0c:
	ds.byte(di) = al;
	_cmp(ds.byte(di+0x12C), 0);
		_jz(loc_1bc1b);
	_cmp(al, ds.byte(di+0x0C8));
		_jc(loc_1bc24);
loc_1bc1b:
	ds.byte(di+0x0C8) = al;
	ds.byte(di+0x12C) = 0x14;
loc_1bc24:
	_inc(di);
	_add(si, 8);
	_pop(cx);
	_dec(cx);
		_jnz({ _spectr_1BBC1(); return; });
	return;
_spectr_1bbc1:
}

void InertiaPlayerContext::_spectr_1bc2d() {
	STACK_CHECK;
	cx = 99;
loc_1bc30:
	al = ds.byte(bx);
	_cmp(al, 90);
		_jc(loc_1bc38);
	al = 90;
loc_1bc38:
	ah = ds.byte(bx+0x64);
	_cmp(ah, 90);
		_jc(loc_1bc42);
	ah = 90;
loc_1bc42:
	_cmp(al, ah);
		_jz(loc_1bc92);
		_jc(loc_1bc70);
	dx = ah;
	_shl(dx, 6);
	di = dx;
	_shl(dx, 2);
	_add(di, dx);
	_neg(di);
	_add(di, bp);
	dl = al;
	_sub(dl, ah);
	al = ah;
loc_1bc5f:
	es.word(di) = ax;
	_inc(al);
	_inc(ah);
	_sub(di, 0x140);
	_dec(dl);
		_jnz(loc_1bc5f);
	loc_1bc92;
loc_1bc70:
	dx = al;
	_shl(dx, 6);
	di = dx;
	_shl(dx, 2);
	_add(di, dx);
	_neg(di);
	_add(di, bp);
	dl = ah;
	_sub(dl, al);
	ax = 0;
loc_1bc87:
	es.word(di) = ax;
	_sub(di, 0x140);
	_dec(dl);
		_jnz(loc_1bc87);
loc_1bc92:
	_cmp(ds.byte(bx+0x12C), 0);
		_jz(loc_1bcdf);
	_dec(ds.byte(bx+0x12C));
		_jnz(loc_1bcc0);
	dx = ds.byte(bx+0x0C8);
	_cmp(dl, 0x5A);
		_jc(loc_1bcab);
	dl = 0x5A;
loc_1bcab:
	_shl(dx, 6);
	di = dx;
	_shl(dx, 2);
	_add(di, dx);
	_neg(di);
	_add(di, bp);
	es.word(di) = 0;
	loc_1bcdf;
loc_1bcc0:
	dx = ds.byte(bx+0x0C8);
	_cmp(dl, 0x5A);
		_jc(loc_1bccc);
	dl = 0x5A;
loc_1bccc:
	_shl(dx, 6);
	di = dx;
	_shl(dx, 2);
	_add(di, dx);
	_neg(di);
	_add(di, bp);
	es.word(di) = 0x0FEFE;
loc_1bcdf:
	_inc(bx);
	_add(bp, 3);
	_dec(cx);
		_jnz(loc_1bc30);
	return;
	return;
/*continuing to unbounded code: loc_1bc30 from _spectr_1bc2d:2-87*/
loc_1bc30:
	al = ds.byte(bx);
	_cmp(al, 90);
		_jc(loc_1bc38);
	al = 90;
loc_1bc38:
	ah = ds.byte(bx+0x64);
	_cmp(ah, 90);
		_jc(loc_1bc42);
	ah = 90;
loc_1bc42:
	_cmp(al, ah);
		_jz(loc_1bc92);
		_jc(loc_1bc70);
	dx = ah;
	_shl(dx, 6);
	di = dx;
	_shl(dx, 2);
	_add(di, dx);
	_neg(di);
	_add(di, bp);
	dl = al;
	_sub(dl, ah);
	al = ah;
loc_1bc5f:
	es.word(di) = ax;
	_inc(al);
	_inc(ah);
	_sub(di, 0x140);
	_dec(dl);
		_jnz(loc_1bc5f);
	loc_1bc92;
loc_1bc70:
	dx = al;
	_shl(dx, 6);
	di = dx;
	_shl(dx, 2);
	_add(di, dx);
	_neg(di);
	_add(di, bp);
	dl = ah;
	_sub(dl, al);
	ax = 0;
loc_1bc87:
	es.word(di) = ax;
	_sub(di, 0x140);
	_dec(dl);
		_jnz(loc_1bc87);
loc_1bc92:
	_cmp(ds.byte(bx+0x12C), 0);
		_jz(loc_1bcdf);
	_dec(ds.byte(bx+0x12C));
		_jnz(loc_1bcc0);
	dx = ds.byte(bx+0x0C8);
	_cmp(dl, 0x5A);
		_jc(loc_1bcab);
	dl = 0x5A;
loc_1bcab:
	_shl(dx, 6);
	di = dx;
	_shl(dx, 2);
	_add(di, dx);
	_neg(di);
	_add(di, bp);
	es.word(di) = 0;
	loc_1bcdf;
loc_1bcc0:
	dx = ds.byte(bx+0x0C8);
	_cmp(dl, 0x5A);
		_jc(loc_1bccc);
	dl = 0x5A;
loc_1bccc:
	_shl(dx, 6);
	di = dx;
	_shl(dx, 2);
	_add(di, dx);
	_neg(di);
	_add(di, bp);
	es.word(di) = 0x0FEFE;
loc_1bcdf:
	_inc(bx);
	_add(bp, 3);
	_dec(cx);
		_jnz(loc_1bc30);
	return;
loc_1bc30:
}

void InertiaPlayerContext::_spectr_1bce9() {
	STACK_CHECK;
	al = ds.byte(bx);
	_cmp(al, 90);
		_jc(loc_1bcf1);
	al = 90;
loc_1bcf1:
	ah = ds.byte(bx+0x64);
	_cmp(ah, 90);
		_jc(loc_1bcfb);
	ah = 90;
loc_1bcfb:
	_cmp(al, ah);
		_jz(locret_1bd67);
		_jc(loc_1bd3e);
	dx = ah;
	_shl(dx, 6);
	di = dx;
	_shl(dx, 2);
	_add(di, dx);
	_neg(di);
	_add(di, bp);
	dl = al;
	_sub(dl, ah);
	_shr(ah, 1);
	eax = 0x0FCFCFCFC;
		_jnc(loc_1bd26);
	_or(eax, 0x1010101);
loc_1bd26:
	es.dword(di) = eax;
	es.dword(di+4) = eax;
	_sub(di, 0x140);
	_xor(eax, 0x1010101);
	_dec(dl);
		_jnz(loc_1bd26);
	return;
loc_1bd3e:
	dx = al;
	_shl(dx, 6);
	di = dx;
	_shl(dx, 2);
	_add(di, dx);
	_neg(di);
	_add(di, bp);
	dl = ah;
	_sub(dl, al);
	eax = 0;
loc_1bd56:
	es.dword(di) = eax;
	es.dword(di+4) = eax;
	_sub(di, 0x140);
	_dec(dl);
		_jnz(loc_1bd56);
locret_1bd67:
	return;
	return;
/*continuing to unbounded code: loc_1bcf1 from _spectr_1bce9:5-53*/
loc_1bcf1:
	ah = ds.byte(bx+0x64);
	_cmp(ah, 90);
		_jc(loc_1bcfb);
	ah = 90;
loc_1bcfb:
	_cmp(al, ah);
		_jz(locret_1bd67);
		_jc(loc_1bd3e);
	dx = ah;
	_shl(dx, 6);
	di = dx;
	_shl(dx, 2);
	_add(di, dx);
	_neg(di);
	_add(di, bp);
	dl = al;
	_sub(dl, ah);
	_shr(ah, 1);
	eax = 0x0FCFCFCFC;
		_jnc(loc_1bd26);
	_or(eax, 0x1010101);
loc_1bd26:
	es.dword(di) = eax;
	es.dword(di+4) = eax;
	_sub(di, 0x140);
	_xor(eax, 0x1010101);
	_dec(dl);
		_jnz(loc_1bd26);
	return;
loc_1bd3e:
	dx = al;
	_shl(dx, 6);
	di = dx;
	_shl(dx, 2);
	_add(di, dx);
	_neg(di);
	_add(di, bp);
	dl = ah;
	_sub(dl, al);
	eax = 0;
loc_1bd56:
	es.dword(di) = eax;
	es.dword(di+4) = eax;
	_sub(di, 0x140);
	_dec(dl);
		_jnz(loc_1bd56);
locret_1bd67:
	return;
loc_1bcf1:
}

void InertiaPlayerContext::_hex_1be39() {
	STACK_CHECK;
	_and(al, 0x0F);
	_or(al, 0x30);
	_cmp(al, 0x39);
		_jbe(loc_1be43);
	_add(al, 7);
loc_1be43:
	es.word(di) = ax;
	_add(di, 2);
	return;
	return;
/*continuing to unbounded code: loc_1be43 from _hex_1be39:6-9*/
loc_1be43:
	es.word(di) = ax;
	_add(di, 2);
	return;
loc_1be43:
}

void InertiaPlayerContext::_message_1be77() {
	STACK_CHECK;
	_push(ax);
	_push(si);
	ch = al;
	_sub(ch, 2);
	dh = al;
	_add(dh, 2);
	ah = 0x0FF;
loc_1be85:
	al = ds.byte(si);
	_inc(ah);
	_inc(si);
	_or(al, al);
		_jnz(loc_1be85);
	cl = 0x4E;
	_sub(cl, ah);
	_shr(ah, 1);
	dl = 0x2A;
	_add(dl, ah);
	al = ch;
	_inc(al);
	ah = 0x0A0;
	_mul(ah);
	di = cl;
	_and(di, 0x0FFFE);
	_add(ax, di);
	_add(ax, 0x0A4);
	_push(ax);
	_shr(cl, 1);
	bl = 0x78;
	ax = 0x7F03;
	_draw_frame();
	_pop(ax);
	_pop(si);
	di = data.word(k_videomempointer);
	_add(di, ax);
	_pop(ax);
	_text_1bf69();
	return;
	return;
/*continuing to unbounded code: loc_1be85 from _message_1be77:8-38*/
loc_1be85:
	al = ds.byte(si);
	_inc(ah);
	_inc(si);
	_or(al, al);
		_jnz(loc_1be85);
	cl = 0x4E;
	_sub(cl, ah);
	_shr(ah, 1);
	dl = 0x2A;
	_add(dl, ah);
	al = ch;
	_inc(al);
	ah = 0x0A0;
	_mul(ah);
	di = cl;
	_and(di, 0x0FFFE);
	_add(ax, di);
	_add(ax, 0x0A4);
	_push(ax);
	_shr(cl, 1);
	bl = 0x78;
	ax = 0x7F03;
	_draw_frame();
	_pop(ax);
	_pop(si);
	di = data.word(k_videomempointer);
	_add(di, ax);
	_pop(ax);
	_text_1bf69();
	return;
loc_1be85:
}

void InertiaPlayerContext::_draw_frame() {
	STACK_CHECK;
	_push(es);
	bp = data.word(k_videomempointer);
	di = cl;
	si = ch;
	_mul(si, 80);
	_add(di, si);
	_shl(di, 1);
	_add(di, bp);
	bp = dl;
	_inc(bp);
	si = cl;
	_sub(bp, si);
		_jbe(loc_1bf57);
	_sub(bp, 2);
		_jc(loc_1bf57);
	dl = dh;
	_inc(dl);
	_sub(dl, ch);
		_jbe(loc_1bf57);
	dh = 0;
	_sub(dx, 2);
		_jc(loc_1bf57);
	_cmp(al, 6);
		_jnc(loc_1bf57);
	si = al;
	_mul(si, 6);
	_add(si, 2375);
	al = ds.byte(si);
	_write_df(false);
 	_stosw();
	cx = bp;
	if (cx==0)
		loc_1bf11;
	al = ds.byte(si+4);
	_stosw(cx, true);
loc_1bf11:
	_xchg(bl, ah);
	al = ds.byte(si+1);
	_stosw();
	_or(dx, dx);
		_jz(loc_1bf3a);
loc_1bf1b:
	_xchg(bl, ah);
	_add(di, 156);
	_sub(di, bp);
	_sub(di, bp);
	al = ds.byte(si+5);
	_stosw();
	cx = bp;
	if (cx==0)
		loc_1bf31;
	al = ' ';
	_stosw(cx, true);
loc_1bf31:
	_xchg(bl, ah);
	al = ds.byte(si+5);
	_stosw();
	_dec(dx);
		_jnz(loc_1bf1b);
loc_1bf3a:
	_xchg(bl, ah);
	_add(di, 156);
	_sub(di, bp);
	_sub(di, bp);
	al = ds.byte(si+2);
	_stosw();
	_xchg(bl, ah);
	cx = bp;
	if (cx==0)
		loc_1bf53;
	al = ds.byte(si+4);
	_stosw(cx, true);
loc_1bf53:
	al = ds.byte(si+3);
	_stosw();
loc_1bf57:
	_pop(es);
	return;
	return;
/*continuing to unbounded code: loc_1bf11 from _draw_frame:36-78*/
loc_1bf11:
	_xchg(bl, ah);
	al = ds.byte(si+1);
	_stosw();
	_or(dx, dx);
		_jz(loc_1bf3a);
loc_1bf1b:
	_xchg(bl, ah);
	_add(di, 156);
	_sub(di, bp);
	_sub(di, bp);
	al = ds.byte(si+5);
	_stosw();
	cx = bp;
	if (cx==0)
		loc_1bf31;
	al = ' ';
	_stosw(cx, true);
loc_1bf31:
	_xchg(bl, ah);
	al = ds.byte(si+5);
	_stosw();
	_dec(dx);
		_jnz(loc_1bf1b);
loc_1bf3a:
	_xchg(bl, ah);
	_add(di, 156);
	_sub(di, bp);
	_sub(di, bp);
	al = ds.byte(si+2);
	_stosw();
	_xchg(bl, ah);
	cx = bp;
	if (cx==0)
		loc_1bf53;
	al = ds.byte(si+4);
	_stosw(cx, true);
loc_1bf53:
	al = ds.byte(si+3);
	_stosw();
loc_1bf57:
	_pop(es);
	return;
loc_1bf11:
}

void InertiaPlayerContext::_write_scr() {
	STACK_CHECK;
	bp = di;
	_add(di, ds.word(si));
	_add(si, 2);
	_n2_setcolor;
	return;
/*continuing to unbounded code: _text_1bf69 from _text_1bf69:0-21*/
_text_1bf69:
	al = ds.byte(si);
	_inc(si);
	_or(al, al);
		_jz(locret_1bf85);
	_cmp(al, 1);
		_jz(_n1_movepos);
	_cmp(al, 2);
		_jz(_n2_setcolor);
	es.word(di) = ax;
	_add(di, 2);
	{ _text_1BF69(); return; };
_n2_setcolor:
	_lodsb();
	ah = al;
	{ _text_1BF69(); return; };
locret_1bf85:
	return;
	return;
}

void InertiaPlayerContext::_text_1bf69() {
	STACK_CHECK;
	al = ds.byte(si);
	_inc(si);
	_or(al, al);
		_jz(locret_1bf85);
	_cmp(al, 1);
		_jz(_n1_movepos);
	_cmp(al, 2);
		_jz(_n2_setcolor);
	es.word(di) = ax;
	_add(di, 2);
	{ _text_1BF69(); return; };
_n2_setcolor:
	_lodsb();
	ah = al;
	{ _text_1BF69(); return; };
locret_1bf85:
	return;
	return;
/*continuing to unbounded code: locret_1bf85 from _text_1bf69:16-17*/
locret_1bf85:
	return;
locret_1bf85:
}

void InertiaPlayerContext::_put_message() {
	STACK_CHECK;
	_write_df(false);
 	_lodsb();
	_or(al, al);
		_jnz(loc_1bf86);
	return;
}

void InertiaPlayerContext::_put_message2() {
	STACK_CHECK;
	_stosw();
	_write_df(false);
 	_lods(fs.byte(si));
	_or(al, al);
		_jnz({ _put_message2(); return; });
	return;
}

	_pop(flags);
		_jc(loc_1bfe3);
	si = 2354;
	cx = 0x0C;
	al = 0;
loc_1bfd9:
	_add(al, ds.byte(si));
	_inc(si);
	if (--cx)
		loc_1bfd9;
	_or(al, al);
		_jnz(loc_1bfe3);
	return;
loc_1bfe3:
	ax = cs;
	ds = ax;
	dx = 1371;
	ah = 9;
	// _int(0x21);
	ax = 0x4C01;
	// _int(0x21);
loc_1bfc9:
}

void InertiaPlayerContext::_getexename() {
	STACK_CHECK;
	es = data.word(k_esseg_atstart);
	es = es.word(0x2C);
	di = 0;
	al = 0;
	_write_df(false);
 	cx = 0x8000;
loc_1c031:
	while(cx-- && !flags.z())
			_jnz(loc_1c050);
	_cmp(es.byte(di), al);
		_jnz(loc_1c031);
	cx = es.word(di+1);
	if (cx==0)
		loc_1c050;
	_add(di, 3);
loc_1c043:
	al = es.byte(di);
	ds.byte(si) = al;
	_inc(di);
	_inc(si);
	_or(al, al);
		_jnz(loc_1c043);
	_write_cf(false);
 	return;
loc_1c050:
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_1c031 from _getexename:7-26*/
loc_1c031:
	while(cx-- && !flags.z())
			_jnz(loc_1c050);
	_cmp(es.byte(di), al);
		_jnz(loc_1c031);
	cx = es.word(di+1);
	if (cx==0)
		loc_1c050;
	_add(di, 3);
loc_1c043:
	al = es.byte(di);
	ds.byte(si) = al;
	_inc(di);
	_inc(si);
	_or(al, al);
		_jnz(loc_1c043);
	_write_cf(false);
 	return;
loc_1c050:
	_write_cf(true);
 	return;
loc_1c031:
}

void InertiaPlayerContext::_set_egasequencer() {
	STACK_CHECK;
	dx = 0x3C4;
	al = 1;
	// _out(dx, al);
	_inc(dl);
	// _in(al, dx);
	_or(al, 0x20);
	// _out(dx, al);
	return;
}

void InertiaPlayerContext::_graph_1c070() {
	STACK_CHECK;
	dx = 0x3C4;
	al = 1;
	// _out(dx, al);
	_inc(dl);
	// _in(al, dx);
	_and(al, 0x0DF);
	// _out(dx, al);
	return;
}

void InertiaPlayerContext::_int9_keyb() {
	STACK_CHECK;
	_cmp(data.byte(k_byte_1c1b8), 1);
		_jz(loc_1c11f);
	_push(ax);
	// _in(al, 0x60);
	_cmp(al, 0x0E0);
		_jz(_l_escaped_scancode);
	_cmp(al, 0x0E1);
		_jz(_l_escaped_scancode);
	ah = data.byte(k_prev_scan_code);
	_or(ah, ah);
		_jz(loc_1c0a5);
	data.byte(k_prev_scan_code) = 0;
loc_1c0a5:
	_cmp(al, 0x36);
		_jz(_l_rshift);
	_cmp(al, 0x0B6);
		_jz(_l_rshiftup);
	_cmp(al, 0x2A);
		_jz(_l_lshift);
	_cmp(al, 0x0AA);
		_jz(_l_lshiftup);
	_cmp(al, 0x1D);
		_jz(_l_ctrl);
	_cmp(al, 0x9D);
		_jz(_l_lctrlup);
	_cmp(al, 0x38);
		_jz(_l_alt);
	_cmp(al, 0x0B8);
		_jz(_l_altup);
	data.word(k_key_code) = ax;
loc_1c0c9:
	// _in(al, 0x61);
	_or(al, 0x80);
	// _out(0x61, al);
	_and(al, 0x7F);
	// _out(0x61, al);
	al = 0x20;
	// _out(0x20, al);
	_pop(ax);
	return;
_l_rshift:
	_or(data.word(k_keyb_switches), 1);
	loc_1c0c9;
_l_rshiftup:
	_and(data.word(k_keyb_switches),  1);
	loc_1c0c9;
_l_lshift:
	_or(data.word(k_keyb_switches), 0x2);
	loc_1c0c9;
_l_lshiftup:
	_and(data.word(k_keyb_switches),  0x2);
	loc_1c0c9;
_l_ctrl:
	_or(data.word(k_keyb_switches), 0x4);
	loc_1c0c9;
_l_lctrlup:
	_and(data.word(k_keyb_switches),  0x4);
	loc_1c0c9;
_l_alt:
	_or(data.word(k_keyb_switches), 0x8);
	loc_1c0c9;
_l_altup:
	_and(data.word(k_keyb_switches),  0x8);
	loc_1c0c9;
_l_escaped_scancode:
	data.byte(k_prev_scan_code) = al;
	loc_1c0c9;
loc_1c11f:
	cs:_oint9_1c1a4;
	return;
/*continuing to unbounded code: loc_1c0a5 from _int9_keyb:13-69*/
loc_1c0a5:
	_cmp(al, 0x36);
		_jz(_l_rshift);
	_cmp(al, 0x0B6);
		_jz(_l_rshiftup);
	_cmp(al, 0x2A);
		_jz(_l_lshift);
	_cmp(al, 0x0AA);
		_jz(_l_lshiftup);
	_cmp(al, 0x1D);
		_jz(_l_ctrl);
	_cmp(al, 0x9D);
		_jz(_l_lctrlup);
	_cmp(al, 0x38);
		_jz(_l_alt);
	_cmp(al, 0x0B8);
		_jz(_l_altup);
	data.word(k_key_code) = ax;
loc_1c0c9:
	// _in(al, 0x61);
	_or(al, 0x80);
	// _out(0x61, al);
	_and(al, 0x7F);
	// _out(0x61, al);
	al = 0x20;
	// _out(0x20, al);
	_pop(ax);
	return;
_l_rshift:
	_or(data.word(k_keyb_switches), 1);
	loc_1c0c9;
_l_rshiftup:
	_and(data.word(k_keyb_switches),  1);
	loc_1c0c9;
_l_lshift:
	_or(data.word(k_keyb_switches), 0x2);
	loc_1c0c9;
_l_lshiftup:
	_and(data.word(k_keyb_switches),  0x2);
	loc_1c0c9;
_l_ctrl:
	_or(data.word(k_keyb_switches), 0x4);
	loc_1c0c9;
_l_lctrlup:
	_and(data.word(k_keyb_switches),  0x4);
	loc_1c0c9;
_l_alt:
	_or(data.word(k_keyb_switches), 0x8);
	loc_1c0c9;
_l_altup:
	_and(data.word(k_keyb_switches),  0x8);
	loc_1c0c9;
_l_escaped_scancode:
	data.byte(k_prev_scan_code) = al;
	loc_1c0c9;
loc_1c11f:
	cs:_oint9_1c1a4;
loc_1c0a5:
}

void InertiaPlayerContext::_get_keybsw() {
	STACK_CHECK;
	_push(es);
	ax = 0;
	es = ax;
	ax = es.word(0x17);
	data.word(k_keyb_switches) = ax;
	_pop(es);
	return;
}

void InertiaPlayerContext::_set_keybsw() {
	STACK_CHECK;
	_push(es);
	ax = 0;
	es = ax;
	ax = data.word(k_keyb_switches);
	es.word(0x17) = ax;
	_pop(es);
	return;
}

void InertiaPlayerContext::_int24() {
	STACK_CHECK;
	al = 3;
	_test(ah, 8);
		_jnz(locret_1c159);
	al = 0;
	_test(ah, 0x20);
		_jnz(locret_1c159);
	al = 1;
locret_1c159:
	return;
	return;
/*continuing to unbounded code: locret_1c159 from _int24:8-9*/
locret_1c159:
	return;
locret_1c159:
}

	_pop(flags);
	_cmp(dl, 1);
		_jz(loc_1c17c);
	ax = 0x4F4B;
	return;
loc_1c17c:
	_push(ax);
	_push(ds);
	ax = ;
	ds = ax;
	data.byte(k_byte_1de7c) = 1;
	_pop(ds);
	_pop(ax);
	return;
loc_1c160:
}

	_pop(flags);
	cs:_int1avect;
loc_1c19c:
}

void InertiaPlayerContext::_dosexec() {
	STACK_CHECK;
	ax = 3;
	// _int(0x10);
	_txt_enableblink();
	cx = 0;
	dx = 0x94F;
	bl = 0x78;
	ax = 0x7F03;
	_draw_frame();
	_txt_draw_top_title();
	si = 1946;
	di = data.word(k_videomempointer);
	_write_scr();
	dx = 0x0A00;
	bh = 0;
	ah = 2;
	// _int(0x10);
	_test(data.byte(k_byte_1de78), 2);
		_jz(loc_1c209);
	ax = 0x351A;
	// _int(0x21);
	data.dword(k_int1avect) = bx;
	data.dword(k_int1avect)[2] = es;
	_push(ds);
	ax = cs;
	ds = ax;
	dx = 50328;
	ax = 0x251A;
	// _int(0x21);
	_pop(ds);
loc_1c209:
	si = 2367;
	_dosgetcurdir();
	al = 1;
	data.byte(k_byte_1c1b8) = al;
	sub_12d35();
	es = data.word(k_esseg_atstart);
	ax = es.word(0x2C);
	data.word(k_word_24445) = ax;
	_get_comspec();
		_jc(loc_1c23e);
	dx = di;
	_push(ds);
	ax = ds;
	es = ax;
	bx = 2652;
	ds = data.word(k_word_24445);
	ax = 0x4B00;
	// _int(0x21);
	_pop(ds);
loc_1c23e:
	al = 0;
	data.byte(k_byte_1c1b8) = al;
	sub_12d35();
	_test(data.byte(k_byte_1de78), 2);
		_jz(loc_1c25c);
	_push(ds);
	dx = data.dword(k_int1avect);
	ax = 0x251A;
	// _int(0x21);
	_pop(ds);
loc_1c25c:
	si = 2367;
	_doschdir();
	data.byte(k_byte_1de70) = 0x0FF;
	return;
	return;
/*continuing to unbounded code: loc_1c209 from _dosexec:30-65*/
loc_1c209:
	si = 2367;
	_dosgetcurdir();
	al = 1;
	data.byte(k_byte_1c1b8) = al;
	sub_12d35();
	es = data.word(k_esseg_atstart);
	ax = es.word(0x2C);
	data.word(k_word_24445) = ax;
	_get_comspec();
		_jc(loc_1c23e);
	dx = di;
	_push(ds);
	ax = ds;
	es = ax;
	bx = 2652;
	ds = data.word(k_word_24445);
	ax = 0x4B00;
	// _int(0x21);
	_pop(ds);
loc_1c23e:
	al = 0;
	data.byte(k_byte_1c1b8) = al;
	sub_12d35();
	_test(data.byte(k_byte_1de78), 2);
		_jz(loc_1c25c);
	_push(ds);
	dx = data.dword(k_int1avect);
	ax = 0x251A;
	// _int(0x21);
	_pop(ds);
loc_1c25c:
	si = 2367;
	_doschdir();
	data.byte(k_byte_1de70) = 0x0FF;
	return;
loc_1c209:
}

void InertiaPlayerContext::_get_comspec() {
	STACK_CHECK;
	es = data.word(k_esseg_atstart);
	es = es.word(0x2C);
	di = 0;
loc_1c273:
	_cmp(es.byte(di), 0);
	_write_cf(true);
 		_jz(locret_1c29d);
	_cmp(es.dword(di), 0x534D4F43);
		_jnz(loc_1c28f);
	_cmp(es.dword(di+4), 0x3D434550);
		_jz(loc_1c299);
loc_1c28f:
	_inc(di);
	_cmp(es.byte(di), 0);
		_jnz(loc_1c28f);
	_inc(di);
	loc_1c273;
loc_1c299:
	_add(di, 8);
	_write_cf(false);
 locret_1c29d:
	return;
	return;
/*continuing to unbounded code: loc_1c273 from _get_comspec:4-22*/
loc_1c273:
	_cmp(es.byte(di), 0);
	_write_cf(true);
 		_jz(locret_1c29d);
	_cmp(es.dword(di), 0x534D4F43);
		_jnz(loc_1c28f);
	_cmp(es.dword(di+4), 0x3D434550);
		_jz(loc_1c299);
loc_1c28f:
	_inc(di);
	_cmp(es.byte(di), 0);
		_jnz(loc_1c28f);
	_inc(di);
	loc_1c273;
loc_1c299:
	_add(di, 8);
	_write_cf(false);
 locret_1c29d:
	return;
loc_1c273:
}

void InertiaPlayerContext::_find_mods() {
	STACK_CHECK;
	ax = ds;
	es = ax;
	di = 2300;
	si = di;
	cx = 120;
	al = 0;
	_write_df(false);
 	while(cx-- && !flags.z())
			_jnz(loc_1c321);
	_dec(di);
	data.word(k_word_1de4a) = di;
loc_1c2b6:
	al = ds.byte(di-1);
	_or(al, al);
		_jz(loc_1c2ca);
	_cmp(al, '\\');
		_jz(loc_1c2ca);
	_cmp(al, ':');
		_jz(loc_1c2ca);
	_dec(di);
	_cmp(si, di);
		_jc(loc_1c2b6);
loc_1c2ca:
	_sub(di, si);
	data.word(k_word_1de4c) = di;
	dx = 2301;
	ah = 0x1A;
	// _int(0x21);
	dx = 2300;
	cx = data.word(k_word_1de4e);
	ah = 0x4E;
	// _int(0x21);
		_jnc(loc_1c309);
	si = 2368;
loc_1c2e7:
	_cmp(ds.byte(si), 0);
		_jz(loc_1c321);
	di = data.word(k_word_1de4a);
	eax = ds.dword(si);
	ds.dword(di) = eax;
	ds.byte(di+4) = 0;
	_add(si, 4);
	dx = 2300;
	cx = 2;
	ah = 0x4E;
	// _int(0x21);
		_jc(loc_1c2e7);
loc_1c309:
	ax = ds;
	es = ax;
	si = 2331;
	di = 2300;
	_add(di, data.word(k_word_1de4c));
	_write_df(false);
 	cx = 3;
	while(cx--)
		_movsd();
	_movsb();
	_write_cf(false);
 	return;
loc_1c321:
	data.byte(k_byte_1de7e) = 2;
	data.word(k_messagepointer) = 2270;
	data.word(k_messagepointer)[2] = ds;
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_1c2b6 from _find_mods:12-66*/
loc_1c2b6:
	al = ds.byte(di-1);
	_or(al, al);
		_jz(loc_1c2ca);
	_cmp(al, '\\');
		_jz(loc_1c2ca);
	_cmp(al, ':');
		_jz(loc_1c2ca);
	_dec(di);
	_cmp(si, di);
		_jc(loc_1c2b6);
loc_1c2ca:
	_sub(di, si);
	data.word(k_word_1de4c) = di;
	dx = 2301;
	ah = 0x1A;
	// _int(0x21);
	dx = 2300;
	cx = data.word(k_word_1de4e);
	ah = 0x4E;
	// _int(0x21);
		_jnc(loc_1c309);
	si = 2368;
loc_1c2e7:
	_cmp(ds.byte(si), 0);
		_jz(loc_1c321);
	di = data.word(k_word_1de4a);
	eax = ds.dword(si);
	ds.dword(di) = eax;
	ds.byte(di+4) = 0;
	_add(si, 4);
	dx = 2300;
	cx = 2;
	ah = 0x4E;
	// _int(0x21);
		_jc(loc_1c2e7);
loc_1c309:
	ax = ds;
	es = ax;
	si = 2331;
	di = 2300;
	_add(di, data.word(k_word_1de4c));
	_write_df(false);
 	cx = 3;
	while(cx--)
		_movsd();
	_movsb();
	_write_cf(false);
 	return;
loc_1c321:
	data.byte(k_byte_1de7e) = 2;
	data.word(k_messagepointer) = 2270;
	data.word(k_messagepointer)[2] = ds;
	_write_cf(true);
 	return;
loc_1c2b6:
}

void InertiaPlayerContext::_dosfindnext() {
	STACK_CHECK;
	dx = 2301;
	ah = 0x1A;
	// _int(0x21);
	ah = 0x4F;
	// _int(0x21);
		_jnc(loc_1c309);
	return;
	return;
/*continuing to unbounded code: loc_1c309 from _find_mods:48-66*/
loc_1c309:
	ax = ds;
	es = ax;
	si = 2331;
	di = 2300;
	_add(di, data.word(k_word_1de4c));
	_write_df(false);
 	cx = 3;
	while(cx--)
		_movsd();
	_movsb();
	_write_cf(false);
 	return;
	data.byte(k_byte_1de7e) = 2;
	data.word(k_messagepointer) = 2270;
	data.word(k_messagepointer)[2] = ds;
	_write_cf(true);
 	return;
}

	_pop(flags);
	return;
loc_1c355:
}

void InertiaPlayerContext::_callsubx() {
	STACK_CHECK;
	al = data.byte(k_snd_card_type);
	dx = data.word(k_snd_base_port_0);
	cl = data.byte(k_irq_number_1);
	ch = data.byte(k_dma_channel_1);
	ah = data.byte(k_freq_1dcf6);
	di = data.byte(k_byte_1dcfb);
	si = data.word(k_configword);
	bl = data.byte(k_byte_1dcf7);
	bh = data.byte(k_byte_1dcf8);
	sub_12da8();
	data.byte(k_byte_1de7e) = 1;
	data.word(k_messagepointer) = dx;
	data.word(k_messagepointer)[2] = fs;
		_jc(locret_1c4a7);
	data.byte(k_byte_1de7e) = 0;
	_read_sndsettings();
	data.byte(k_snd_card_type) = al;
	data.word(k_snd_base_port_0) = dx;
	data.byte(k_irq_number_1) = cl;
	data.byte(k_dma_channel_1) = ch;
	data.byte(k_freq_1dcf6) = ah;
	data.byte(k_byte_1dcf7) = bl;
	data.byte(k_byte_1dcf8) = bh;
	data.word(k_configword) = si;
	data.word(k_outp_freq) = bp;
	data.byte(k_byte_1de7c) = 1;
	_cmp(data.byte(k_snd_card_type), 0);
		_jnz(loc_1c4a6);
	cs.byte(+4) = 0x0F;
loc_1c4a6:
	_write_cf(false);
 locret_1c4a7:
	return;
	return;
/*continuing to unbounded code: loc_1c4a6 from _callsubx:30-33*/
loc_1c4a6:
	_write_cf(false);
 locret_1c4a7:
	return;
loc_1c4a6:
}

	_aad();
	_add(dx, ax);
	_mul(eax, edx, 60);
	_add(eax, ebx);
	edx = 1193180;
	_mul(edx);
	_shrd(eax, edx, 0x10);
	dx = 0;
	es = dx;
	es.dword(0x46C) = eax;
	return;
}

void InertiaPlayerContext::_spectr_1c4f8() {
	STACK_CHECK;
	eax = 0;
	edx = 0x40000000;
loc_1c501:
	ecx = eax;
	_add(ecx, edx);
	_shr(eax, 1);
	_cmp(ecx, ebx);
		_jg(loc_1c515);
	_sub(ebx, ecx);
	_add(eax, edx);
loc_1c515:
	_shr(edx, 2);
		_jnz(loc_1c501);
	_cmp(eax, ebx);
		_jge(locret_1c521);
	_inc(ax);
locret_1c521:
	return;
	return;
/*continuing to unbounded code: loc_1c501 from _spectr_1c4f8:3-18*/
loc_1c501:
	ecx = eax;
	_add(ecx, edx);
	_shr(eax, 1);
	_cmp(ecx, ebx);
		_jg(loc_1c515);
	_sub(ebx, ecx);
	_add(eax, edx);
loc_1c515:
	_shr(edx, 2);
		_jnz(loc_1c501);
	_cmp(eax, ebx);
		_jge(locret_1c521);
	_inc(ax);
locret_1c521:
	return;
loc_1c501:
}

void InertiaPlayerContext::_txt_blinkingoff() {
	STACK_CHECK;
	bl = 0;
	ax = 0x1003;
	// _int(0x10);
	return;
}

void InertiaPlayerContext::_txt_enableblink() {
	STACK_CHECK;
	bl = 1;
	ax = 0x1003;
	// _int(0x10);
	return;
}

void InertiaPlayerContext::_my_u32tox() {
	STACK_CHECK;
	_ror(eax, 0x10);
	_my_u16tox();
	_ror(eax, 0x10);
}

void InertiaPlayerContext::_my_u16tox() {
	STACK_CHECK;
	_xchg(al, ah);
	_my_u8tox();
	al = ah;
}

void InertiaPlayerContext::_my_u8tox() {
	STACK_CHECK;
	_push(ax);
	_shr(al, 4);
	_my_u4tox();
	_pop(ax);
}

void InertiaPlayerContext::_my_u4tox() {
	STACK_CHECK;
	_and(al, 0x0F);
	_or(al, '0');
	_cmp(al, '9');
		_jbe(loc_1c556);
	_add(al, 7);
loc_1c556:
	ds.byte(si) = al;
	_inc(si);
	return;
	return;
/*continuing to unbounded code: loc_1c556 from _my_u4tox:6-9*/
loc_1c556:
	ds.byte(si) = al;
	_inc(si);
	return;
loc_1c556:
}

void InertiaPlayerContext::_my_i8toa10() {
	STACK_CHECK;
	_cbw();
	_cwde();
	cx = 0;
	_or(eax, eax);
		_jns(_my_i32toa10_);
	dl = '-';
	_myputdigit();
	_neg(eax);
	_my_i32toa10_;
	return;
/*continuing to unbounded code: _my_i32toa10_ from _my_u32toa10:2-3*/
_my_i32toa10_:
	ebx = 10;
}

void InertiaPlayerContext::_my_u8toa10() {
	STACK_CHECK;
	ah = 0;
}

void InertiaPlayerContext::_my_u16toa10() {
	STACK_CHECK;
	eax = ax;
}

void InertiaPlayerContext::_my_u32toa10() {
	STACK_CHECK;
	cx = 0;
	ebx = 10;
}

void InertiaPlayerContext::_my_u32toa() {
	STACK_CHECK;
	edx = 0;
	_div(ebx);
	_or(eax, eax);
		_jz(loc_1c58e);
	_push(edx);
	_my_u32toa();
	_pop(edx);
loc_1c58e:
	_or(dl, '0');
	return;
/*continuing to unbounded code: loc_1c58e from _my_u32toa:8-9*/
loc_1c58e:
	_or(dl, '0');
loc_1c58e:
}

void InertiaPlayerContext::_myputdigit() {
	STACK_CHECK;
	ds.byte(si) = dl;
	_inc(si);
	_inc(cx);
	return;
}

void InertiaPlayerContext::_mystrlen() {
	STACK_CHECK;
	ax = -1;
	_dec(si);
loc_1c6ab:
	_inc(ax);
	_inc(si);
	_cmp(ds.byte(si), 0);
		_jnz(loc_1c6ab);
	_sub(si, ax);
	return;
	return;
/*continuing to unbounded code: loc_1c6ab from _mystrlen:3-9*/
loc_1c6ab:
	_inc(ax);
	_inc(si);
	_cmp(ds.byte(si), 0);
		_jnz(loc_1c6ab);
	_sub(si, ax);
	return;
loc_1c6ab:
}

void InertiaPlayerContext::_strcpy_count() {
	STACK_CHECK;
	cx = 0;
	loc_1c6be;
loc_1c6b9:
	es.byte(di) = al;
	_inc(si);
	_inc(di);
loc_1c6be:
	al = ds.byte(si);
	_inc(cx);
	_or(al, al);
		_jnz(loc_1c6b9);
	return;
	return;
/*continuing to unbounded code: loc_1c6b9 from _strcpy_count:3-12*/
loc_1c6b9:
	es.byte(di) = al;
	_inc(si);
	_inc(di);
loc_1c6be:
	al = ds.byte(si);
	_inc(cx);
	_or(al, al);
		_jnz(loc_1c6b9);
	return;
loc_1c6b9:
}

void InertiaPlayerContext::_mouse_init() {
	STACK_CHECK;
	data.byte(k_mouse_visible) = 0;
	ax = 0;
	es = ax;
	_cmp(es.dword(0x0CC), 0);
		_jz(loc_1c708);
	ax = 0x21;
	// _int(0x33);
	_cmp(ax, 0x0FFFF);
		_jz(loc_1c6ef);
	ax = 0;
	// _int(0x33);
	_test(ax, ax);
		_jz(loc_1c708);
	_cmp(ax, 0x0FFFF);
		_jnz(loc_1c708);
loc_1c6ef:
	data.byte(k_mouse_exist_flag) = 1;
	_push(es);
	ax = ;
	es = ax;
	dx = &;
	cx = 0x1F;
	ax = 0x0C;
	// _int(0x33);
	_pop(es);
	_write_cf(false);
 	return;
loc_1c708:
	data.byte(k_mouse_exist_flag) = 0;
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_1c6ef from _mouse_init:16-31*/
loc_1c6ef:
	data.byte(k_mouse_exist_flag) = 1;
	_push(es);
	ax = ;
	es = ax;
	dx = &;
	cx = 0x1F;
	ax = 0x0C;
	// _int(0x33);
	_pop(es);
	_write_cf(false);
 	return;
loc_1c708:
	data.byte(k_mouse_exist_flag) = 0;
	_write_cf(true);
 	return;
loc_1c6ef:
}

void InertiaPlayerContext::_mouse_deinit() {
	STACK_CHECK;
	_cmp(data.byte(k_mouse_exist_flag), 1);
		_jnz(locret_1c72b);
	data.byte(k_mouse_exist_flag) = 0;
	data.byte(k_mouse_visible) = 0;
	dx = 0;
	es = dx;
	cx = dx;
	ax = 0x0C;
	// _int(0x33);
locret_1c72b:
	return;
	return;
/*continuing to unbounded code: locret_1c72b from _mouse_deinit:10-11*/
locret_1c72b:
	return;
locret_1c72b:
}

void InertiaPlayerContext::_mouse_show() {
	STACK_CHECK;
	_cmp(data.byte(k_mouse_exist_flag), 1);
		_jnz(locret_1c755);
	_cmp(data.byte(k_mouse_visible), 1);
		_jz(locret_1c755);
	data.byte(k_mouse_visible) = 1;
	_mouse_showcur();
locret_1c755:
	return;
	return;
/*continuing to unbounded code: locret_1c755 from _mouse_show:7-8*/
locret_1c755:
	return;
locret_1c755:
}

void InertiaPlayerContext::_mouse_hide() {
	STACK_CHECK;
	_cmp(data.byte(k_mouse_exist_flag), 1);
		_jnz(locret_1c76c);
	_cmp(data.byte(k_mouse_visible), 0);
		_jz(locret_1c76c);
	data.byte(k_mouse_visible) = 0;
	_mouse_hide2();
locret_1c76c:
	return;
	return;
/*continuing to unbounded code: locret_1c76c from _mouse_hide:7-8*/
locret_1c76c:
	return;
locret_1c76c:
}

void InertiaPlayerContext::_mouse_getpos() {
	STACK_CHECK;
	_cmp(data.byte(k_mouse_exist_flag), 1);
		_jnz(loc_1c783);
	ax = 3;
	// _int(0x33);
	data.word(k_mousecolumn) = cx;
	data.word(k_mouserow) = dx;
	_write_cf(false);
 	return;
loc_1c783:
	bx = 0;
	cx = 0;
	dx = 0;
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_1c783 from _mouse_getpos:9-14*/
loc_1c783:
	bx = 0;
	cx = 0;
	dx = 0;
	_write_cf(true);
 	return;
loc_1c783:
}

void InertiaPlayerContext::_mouse_showcur() {
	STACK_CHECK;
	_cmp(data.byte(k_mouse_exist_flag), 1);
		_jnz(loc_1c7a7);
	ax = 1;
	// _int(0x33);
	_write_cf(false);
 	return;
	return;
/*continuing to unbounded code: loc_1c7a7 from _mouse_hide2:7-14*/
loc_1c7a7:
	_write_cf(true);
 	return;
loc_1c7a7:
	_write_cf(true);
 	return;
loc_1c7a7:
}

void InertiaPlayerContext::_mouse_hide2() {
	STACK_CHECK;
	_cmp(data.byte(k_mouse_exist_flag), 1);
		_jnz(loc_1c7a7);
	ax = 2;
	// _int(0x33);
	_write_cf(false);
 	return;
loc_1c7a7:
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_1c7a7 from _mouse_hide2:7-9*/
loc_1c7a7:
	_write_cf(true);
 	return;
loc_1c7a7:
}

void InertiaPlayerContext::_mouse_1c7a9() {
	STACK_CHECK;
	_cmp(cx, si);
		_jbe(loc_1c7af);
	_xchg(cx, si);
loc_1c7af:
	_cmp(dx, di);
		_jbe(loc_1c7b5);
	_xchg(dx, di);
loc_1c7b5:
	_cmp(ax, cx);
		_jc(loc_1c7ca);
	_cmp(ax, si);
		_ja(loc_1c7ca);
	_cmp(bp, dx);
		_jc(loc_1c7ca);
	_cmp(bp, di);
		_ja(loc_1c7ca);
	_sub(ax, cx);
	_sub(bp, dx);
	return;
loc_1c7ca:
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_1c7af from _mouse_1c7a9:4-22*/
loc_1c7af:
	_cmp(dx, di);
		_jbe(loc_1c7b5);
	_xchg(dx, di);
loc_1c7b5:
	_cmp(ax, cx);
		_jc(loc_1c7ca);
	_cmp(ax, si);
		_ja(loc_1c7ca);
	_cmp(bp, dx);
		_jc(loc_1c7ca);
	_cmp(bp, di);
		_ja(loc_1c7ca);
	_sub(ax, cx);
	_sub(bp, dx);
	return;
loc_1c7ca:
	_write_cf(true);
 	return;
loc_1c7af:
}

void InertiaPlayerContext::_mouse_1c7cf() {
	STACK_CHECK;
	cx = ds.word(bx);
	_cmp(cx, -1);
		_jz(loc_1c7e9);
	dx = ds.word(bx+2);
	si = ds.word(bx+4);
	di = ds.word(bx+6);
	_mouse_1c7a9();
		_jc(loc_1c7cc);
	bx = ds.word(bx+8);
	_write_cf(false);
 	return;
loc_1c7e9:
	_write_cf(true);
 	return;
	return;
/*continuing to unbounded code: loc_1c7e9 from _mouse_1c7cf:12-14*/
loc_1c7e9:
	_write_cf(true);
 	return;
loc_1c7e9:
}

void InertiaPlayerContext::_start() {
	STACK_CHECK;
	ax = ;
	ds = ax;
	data.word(k_esseg_atstart) = es;
	ax = sp;
	_add(ax, 0x13);
	cl = 4;
	_shr(ax, cl);
	bx = ;
	_add(bx, ax);
	ax = es;
	_sub(bx, ax);
	ah = 0x4A;
	// _int(0x21);
	_write_df(false);
 	dl = 0;
	cx = 0x4D50;
	bx = 0x5344;
	ax = 0x60FF;
	// _int(0x2F);
	_cmp(ax, 0x4F4B);
		_jnz(loc_190d3);
	dx = 2286;
	ah = 9;
	// _int(0x21);
	ah = 0;
	// _int(0x16);
	ax = 0x4C02;
	// _int(0x21);
loc_190d3:
	_loadcfg();
	_parse_cmdline();
	flags.c() = (ebp >> 8) & 1;
		_jc(loc_19050);
	_test(ebp, 0x80000080);
		_jnz(loc_19086);
	flags.c() = (ebp >> 0x0B) & 1;
		_jnc(loc_190f7);
	_or(data.word(k_configword), 4);
loc_190f7:
	flags.c() = (ebp >> 3) & 1;
		_jnc(loc_19103);
	_and(data.word(k_configword), 0x0FB);
loc_19103:
	flags.c() = (ebp >> 6) & 1;
		_jnc(loc_19114);
	_and(data.word(k_configword)[1], 0x0F1);
	_or(data.word(k_configword)[1], 2);
loc_19114:
	flags.c() = (ebp >> 5) & 1;
		_jnc(loc_19125);
	_and(data.word(k_configword)[1], 0x0F1);
	_or(data.word(k_configword)[1], 4);
loc_19125:
	flags.c() = (ebp >> 0x13) & 1;
		_jnc(loc_19131);
	_and(data.word(k_configword)[1], 0x0F1);
loc_19131:
	flags.c() = (ebp >> 4) & 1;
		_jnc(loc_1913d);
	_and(data.word(k_configword), 0x0FD);
loc_1913d:
	flags.c() = (ebp >> 0x14) & 1;
		_jnc(loc_19149);
	_and(data.word(k_configword), 0x0FE);
loc_19149:
	flags.c() = (ebp >> 0x0E) & 1;
		_jnc(loc_19155);
	_and(data.word(k_configword), 0x0BF);
loc_19155:
	flags.c() = (ebp >> 2) & 1;
		_jnc(loc_19161);
	_or(data.word(k_configword), 0x40);
loc_19161:
	flags.c() = (ebp >> 0x15) & 1;
	if (flags.c()) al = 1; else al = 0; //setb
	data.byte(k_byte_1de86) = al;
	al = data.byte(k_byte_1dcf8);
	ah = al;
	_and(al, 0x0F);
	data.byte(k_byte_1de82) = al;
	_shr(ah, 4);
	data.byte(k_byte_1de83) = ah;
	data.word(k_videomempointer) = 0x0B8000000;
	ax = 0x3508;
	// _int(0x21);
	data.word(k_oint8off_1de14) = bx;
	data.word(k_oint8seg_1de16) = es;
	ax = 0x3509;
	// _int(0x21);
	data.dword(k_oint9_1c1a4) = bx;
	data.dword(k_oint9_1c1a4)[2] = es;
	ax = 0x3524;
	// _int(0x21);
	data.dword(k_oint24_1c1ac) = bx;
	data.dword(k_oint24_1c1ac)[2] = es;
	ax = 0x352F;
	// _int(0x21);
	data.dword(k_oint2f_1c1b4) = bx;
	data.dword(k_oint2f_1c1b4)[2] = es;
	_push(ds);
	ax = cs;
	ds = ax;
	dx = 50308;
	ax = 0x2509;
	// _int(0x21);
	dx = 50320;
	ax = 0x2524;
	// _int(0x21);
	dx = 50324;
	ax = 0x252F;
	// _int(0x21);
	_pop(ds);
	ah = 0x34;
	// _int(0x21);
	data.word(k_critsectpoint_off) = bx;
	data.word(k_critsectpoint_seg) = es;
	_push(ds);
	ax = 0x5D06;
	// _int(0x21);
	ax = ds;
	_pop(ds);
	data.word(k_swapdata_off) = si;
	data.word(k_swapdata_seg) = ax;
	data.byte(k_byte_1de70) = 0x0FF;
	_mouse_init();
	bl = data.word(k_configword)[1];
	_shr(bl, 1);
	_and(bx, 7);
	_cmp(bl, 5);
		_jbe(loc_19212);
	bl = 0;
loc_19212:
	_shl(bx, 1);
	ax = data.word(kOff_1ca8e)[bx];
	data.word(kOff_1de3c) = ax;
	_cmp(data.byte(k_buffer_1db6c), 0x40);
		_jz(loc_19d94);
	_cmp(data.byte(k_buffer_1db6c), 0x20);
		_jbe(loc_192ca);
	data.word(k_word_1de4e) = 2;
	_find_mods();
		_jc(loc_19256);
	_callsubx();
		_jc(loc_19256);
	_readallmoules();
		_jc(loc_19250);
	_cmp(data.word(k_word_1de50), 0x1C);
		_jz(loc_192e0);
	data.byte(k_byte_1de7e) = 0;
loc_19250:
	// _cli();
	_deinit_125b9();
loc_19256:
	_mouse_deinit();
	_push(ds);
	dx = data.dword(k_oint2f_1c1b4);
	ax = 0x252F;
	// _int(0x21);
	_pop(ds);
	_push(ds);
	dx = data.dword(k_oint24_1c1ac);
	ax = 0x2524;
	// _int(0x21);
	_pop(ds);
	_push(ds);
	dx = data.dword(k_oint9_1c1a4);
	ax = 0x2509;
	// _int(0x21);
	_pop(ds);
	ax = 3;
	// _int(0x10);
	_txt_enableblink();
	cx = 0;
	dx = 0x124F;
	bl = 0x78;
	ax = 0x7F03;
	_draw_frame();
	_txt_draw_top_title();
	si = 1871;
	di = data.word(k_videomempointer);
	_write_scr();
	dx = 0x1300;
	bh = 0;
	ah = 2;
	// _int(0x10);
	_cmp(data.byte(k_byte_1de7e), 0);
		_jz(loc_192c3);
	dx = 0x1400;
	bh = 0;
	ah = 2;
	// _int(0x10);
	_push(ds);
	dx = data.word(k_messagepointer);
	ah = 9;
	// _int(0x21);
	_pop(ds);
loc_192c3:
	ah = 0x4C;
	al = data.byte(k_byte_1de7e);
	// _int(0x21);
loc_192ca:
	data.byte(k_byte_1de7e) = 5;
	data.word(k_messagepointer) = 2278;
	data.word(k_messagepointer)[2] = ds;
	_callsubx();
		_jc(loc_19256);
loc_192e0:
	si = 2366;
	_dosgetcurdir();
	data.word(k_word_1de62) = 0;
	data.word(k_word_1de5e) = 0;
	data.byte(k_byte_1de7f) = 1;
loc_192f7:
	_setvideomode();
	data.byte(k_byte_1de70) = 1;
loc_192ff:
	cx = 0;
	dx = 0x1B4F;
	bl = 0x78;
	ax = 0x7F03;
	_draw_frame();
	_txt_draw_top_title();
	ax = ds;
	es = ax;
	di = 2571;
	sub_12d05();
	es.byte(di) = 0;
	_sub(di, 0x16EF);
	_and(di, 0x0FFFE);
	ax = 0x50;
	_sub(ax, di);
	_add(ax, 0x320);
	di = data.word(k_videomempointer);
	_add(di, ax);
	si = 2571;
	ah = 0x78;
	_put_message();
	cx = 0x604;
	dx = 0x84B;
	bl = 0x7F;
	ax = 0x7803;
	_draw_frame();
	ah = 0x19;
	// _int(0x21);
	edx = 0x5C3A41;
	_add(dl, al);
	data.dword(k_buffer_1dc6c) = edx;
	si = ( data.dword(k_buffer_1dc6c)+3);
	dl = 0;
	ah = 0x47;
	// _int(0x21);
	si = 2332;
	_mystrlen();
	_shr(ax, 1);
	_neg(ax);
	_add(ax, 0x257);
	_shl(ax, 1);
	di = data.word(k_videomempointer);
	_add(di, ax);
	si = 2332;
	ah = 0x7B;
	_put_message();
	_cmp(data.byte(k_byte_1de7f), 1);
		_jnz(loc_19395);
	si = 1964;
	ax = 0x7E0D;
	_message_1be77();
	_modules_search();
loc_19395:
	data.byte(k_byte_1de7e) = 0;
	data.word(k_word_1de60) = 0x0FFFF;
	cx = 0x906;
	dx = 0x1949;
	bl = 0x7F;
	ax = 0x7803;
	_draw_frame();
loc_193ae:
	_filelist_198b8();
	ax = data.word(k_word_1de62);
	bl = 0x10;
	_recolortxt();
loc_193bc:
	al = data.byte(k_byte_1de7c);
	_xor(al, 1);
	data.byte(k_byte_1de7d) = al;
	_mouse_show();
loc_193c7:
	_test(data.byte(k_byte_1de90), 2);
		_jnz(loc_19848);
	_test(data.byte(k_byte_1de90), 1);
		_jnz(loc_19827);
	al = data.byte(k_byte_1de7c);
	_cmp(al, data.byte(k_byte_1de7d));
		_jz(loc_193ff);
	data.byte(k_byte_1de7d) = al;
	di = data.word(k_videomempointer);
	_add(di, 0x104A);
	ah = 0x78;
	si = 2138;
	_cmp(data.byte(k_byte_1de7c), 0);
		_jz(loc_193fc);
	si = 2132;
loc_193fc:
	_put_message();
loc_193ff:
	ax = data.word(k_key_code);
	_or(ax, ax);
		_jz(loc_193c7);
	_push(ax);
	_mouse_hide();
	_pop(ax);
	data.word(k_key_code) = 0;
	_cmp(al, 1);
		_jz(loc_1964e);
	_cmp(al, 0x48);
		_jz(loc_1957f);
	_cmp(al, 0x50);
		_jz(loc_1953c);
	_cmp(al, 0x47);
		_jz(loc_195a7);
	_cmp(al, 0x4F);
		_jz(loc_195be);
	_cmp(al, 0x49);
		_jz(loc_195ea);
	_cmp(al, 0x51);
		_jz(loc_19610);
	_cmp(al, 0x0E);
		_jz(loc_19762);
	_cmp(al, 0x53);
		_jz(loc_19657);
	_cmp(al, 0x3B);
		_jz(loc_19788);
	_cmp(al, 0x42);
		_jz(loc_197d6);
	_cmp(al, 0x43);
		_jz(loc_197e7);
	_cmp(al, 0x1C);
		_jnz(loc_193bc);
	ax = data.word(k_word_1de62);
	_add(ax, data.word(k_word_1de5e));
	dx = ax;
	_shl(ax, 1);
	_add(ax, dx);
	_add(ax, data.word(k_word_1de52));
	fs = ax;
	si = 0x0C;
	ax = ds;
	es = ax;
	di = 2300;
	dx = di;
	_write_df(false);
 	_movs(es.dword(di), fs.dword(si));
	_movs(es.dword(di), fs.dword(si));
	_movs(es.dword(di), fs.dword(si));
	ds.byte(di) = 0;
	_cmp(fs.byte(2), 0);
		_jz(loc_194eb);
	_cmp(fs.byte(2), 1);
		_jz(loc_19506);
	_push(dx);
	cx = 0x501;
	dx = 0x1A4E;
	bl = 0x7F;
	ax = 0x7800;
	_draw_frame();
	si = 1966;
	ax = 0x7E0D;
	_message_1be77();
	_pop(dx);
	_read_module();
		_jnc(loc_194e3);
	si = 1972;
	_cmp(ax, 0x0FFFE);
		_jz(loc_194ce);
	si = 1970;
	_cmp(ax, 0x0FFFD);
		_jz(loc_194ce);
	si = 1968;
loc_194ce:
	ax = 0x7E0D;
	_message_1be77();
	ax = 0;
	data.word(k_key_code) = ax;
loc_194da:
	_xchg(ax, );
	_or(ax, ax);
		_jz(loc_194da);
loc_194e3:
	data.byte(k_byte_1de7f) = 0;
	loc_192f7;
loc_194eb:
	data.byte(k_byte_1de7f) = 1;
	dx = 2300;
	ah = 0x3B;
	// _int(0x21);
	data.word(k_word_1de62) = 0;
	data.word(k_word_1de5e) = 0;
	loc_192ff;
loc_19506:
	data.byte(k_byte_1de7f) = 1;
	dl = fs.byte(0x0D);
	_sub(dl, 'A');
		_jc(loc_193bc);
	_cmp(dl, 'Z' - 'A' +1);
		_jnc(loc_193bc);
	bl = dl;
	_inc(bl);
	_push(dx);
	ax = 0x440F;
	// _int(0x21);
	_pop(dx);
	ah = 0x0E;
	// _int(0x21);
	data.word(k_word_1de62) = 0;
	data.word(k_word_1de5e) = 0;
	loc_192ff;
loc_1953c:
	_cmp(data.word(k_word_1de62), 0x0E);
		_jnc(loc_1955d);
	bx = data.word(k_word_1de54);
	_dec(bx);
	ax = data.word(k_word_1de62);
	_cmp(ax, bx);
		_jnc(loc_193bc);
	bl = 0x70;
	_recolortxt();
	_inc(data.word(k_word_1de62));
	loc_193ae;
loc_1955d:
	_cmp(data.word(k_word_1de54), 0x0F);
		_jc(loc_193bc);
	ax = data.word(k_word_1de54);
	_sub(ax, data.word(k_word_1de5e));
		_jc(loc_193bc);
	_cmp(ax, 0x10);
		_jc(loc_193bc);
	_inc(data.word(k_word_1de5e));
	loc_193ae;
loc_1957f:
	_cmp(data.word(k_word_1de62), 0);
		_jz(loc_19595);
	ax = data.word(k_word_1de62);
	bl = 0x70;
	_recolortxt();
	_dec(data.word(k_word_1de62));
	loc_193ae;
loc_19595:
	_sub(data.word(k_word_1de5e), 1);
		_jnc(loc_193ae);
	data.word(k_word_1de5e) = 0;
	loc_193ae;
loc_195a7:
	ax = data.word(k_word_1de62);
	bl = 0x70;
	_recolortxt();
	data.word(k_word_1de62) = 0;
	data.word(k_word_1de5e) = 0;
	loc_193ae;
loc_195be:
	ax = data.word(k_word_1de62);
	bl = 0x70;
	_recolortxt();
	ax = data.word(k_word_1de54);
	_dec(ax);
	_cmp(ax, 0x0F);
		_jc(loc_195de);
	_sub(ax, 0x0E);
	data.word(k_word_1de5e) = ax;
	data.word(k_word_1de62) = 0x0E;
	loc_193ae;
loc_195de:
	data.word(k_word_1de5e) = 0;
	data.word(k_word_1de62) = ax;
	loc_193ae;
loc_195ea:
	ax = data.word(k_word_1de62);
	bl = 0x70;
	_recolortxt();
	ax = 0;
	_xchg(ax, data.word(k_word_1de62));
	_or(ax, ax);
		_jnz(loc_193ae);
	_sub(data.word(k_word_1de5e), 0x0F);
		_jnc(loc_193ae);
	data.word(k_word_1de5e) = 0;
	loc_193ae;
loc_19610:
	ax = data.word(k_word_1de62);
	bl = 0x70;
	_recolortxt();
	ax = data.word(k_word_1de54);
	_dec(ax);
	_cmp(ax, 0x0F);
		_jc(loc_19648);
	ax = 0x0E;
	_xchg(ax, data.word(k_word_1de62));
	_cmp(ax, 0x0E);
		_jnz(loc_193ae);
	_add(data.word(k_word_1de5e), 0x0F);
	ax = data.word(k_word_1de54);
	_sub(ax, 0x0F);
	_cmp(data.word(k_word_1de5e), ax);
		_jbe(loc_193ae);
	data.word(k_word_1de5e) = ax;
	loc_193ae;
loc_19648:
	data.word(k_word_1de62) = ax;
	loc_193ae;
loc_1964e:
	si = 2366;
	_doschdir();
	loc_19250;
loc_19657:
	ax = data.word(k_word_1de5e);
	_add(ax, data.word(k_word_1de62));
	dx = ax;
	_shl(ax, 1);
	_add(ax, dx);
	_add(ax, data.word(k_word_1de52));
	fs = ax;
	_test(data.word(k_keyb_switches), 4);
		_jnz(loc_196b0);
	_cmp(fs.byte(2), 2);
		_jnz(loc_193bc);
	data.word(k_word_1de60) = 0x0FFFF;
	_test(fs.byte(3), 0x40);
		_jnz(loc_19698);
	_or(fs.byte(3), 0x40);
	_inc(data.word(k_word_1de5c));
	loc_1953c;
loc_19698:
	_and(fs.byte(3), 0x0BF);
	_sub(data.word(k_word_1de5c), 1);
		_jnc(loc_1953c);
	data.word(k_word_1de5c) = 0;
	loc_1953c;
loc_196b0:
	_cmp(data.word(k_word_1de5c), 0);
		_jz(loc_193bc);
	cx = 0x602;
	dx = 0x1A4E;
	bl = 0x7F;
	ax = 0x7800;
	_draw_frame();
	si = 1974;
	ax = 0x7E0D;
	_message_1be77();
loc_196d0:
	ax = 0;
	_xchg(ax, data.word(k_key_code));
	_or(ax, ax);
		_jz(loc_196d0);
		_js(loc_196d0);
	data.byte(k_byte_1de7f) = 0;
	_cmp(ax, 0x15);
		_jnz(loc_192ff);
	fs = data.word(k_word_1de52);
	cx = data.word(k_word_1de54);
loc_196f1:
	_test(fs.byte(3), 0x40);
		_jz(loc_19744);
	_cmp(fs.byte(2), 2);
		_jnz(loc_19744);
	_push(cx);
	_push(fs);
	cx = 0x602;
	dx = 0x1A4E;
	bl = 0x7F;
	ax = 0x7800;
	_draw_frame();
	_pop(fs);
	_push(fs);
	eax = fs.dword(0x0C);
	data.byte(k_afile) = eax;
	eax = fs.dword(0x10);
	data.byte(k_aname) = eax;
	eax = fs.dword(0x14);
	data.byte(k_a_ext) = eax;
	si = 1976;
	ax = 0x7E0D;
	_message_1be77();
	dx = 1977;
	ah = 0x41;
	// _int(0x21);
	_pop(fs);
	_pop(cx);
loc_19744:
	ax = fs;
	_add(ax, 3);
	fs = ax;
	_dec(cx);
		_jnz(loc_196f1);
	data.word(k_word_1de62) = 0;
	data.word(k_word_1de5e) = 0;
	data.byte(k_byte_1de7f) = 1;
	loc_192ff;
loc_19762:
	_cmp(data.byte(k_byte_1de7c), 1);
		_jz(loc_193bc);
	cx = 0x602;
	dx = 0x1A4E;
	bl = 0x7F;
	ax = 0x7800;
	_draw_frame();
	_keyb_19efd();
	data.byte(k_byte_1de7f) = 0;
	loc_192f7;
loc_19788:
	cx = 0x604;
	dx = 0x84B;
	bl = 0x7F;
	ax = 0x7803;
	_draw_frame();
	cx = 0x906;
	dx = 0x1949;
	bl = 0x7F;
	ax = 0x7803;
	_draw_frame();
	di = data.word(k_videomempointer);
	_add(di, 0x1042);
	cx = 0x4E;
	ax = 0x7820;
	_write_df(false);
 	_stosw(cx, true);
	si = 1985;
	di = data.word(k_videomempointer);
	_write_scr();
loc_197bf:
	_cmp(data.word(k_key_code), 0);
		_jle(loc_197bf);
	data.word(k_key_code) = 0;
	data.byte(k_byte_1de7f) = 0;
	loc_192f7;
loc_197d6:
	_mouse_deinit();
	_dosexec();
	_mouse_init();
	data.byte(k_byte_1de7f) = 0;
	loc_192f7;
loc_197e7:
	_xor(data.word(k_configword), 0x20);
	loc_193bc;
	return;
/*continuing to unbounded code: loc_190d3 from _start:34-661*/
loc_190d3:
	_loadcfg();
	_parse_cmdline();
	flags.c() = (ebp >> 8) & 1;
		_jc(loc_19050);
	_test(ebp, 0x80000080);
		_jnz(loc_19086);
	flags.c() = (ebp >> 0x0B) & 1;
		_jnc(loc_190f7);
	_or(data.word(k_configword), 4);
loc_190f7:
	flags.c() = (ebp >> 3) & 1;
		_jnc(loc_19103);
	_and(data.word(k_configword), 0x0FB);
loc_19103:
	flags.c() = (ebp >> 6) & 1;
		_jnc(loc_19114);
	_and(data.word(k_configword)[1], 0x0F1);
	_or(data.word(k_configword)[1], 2);
loc_19114:
	flags.c() = (ebp >> 5) & 1;
		_jnc(loc_19125);
	_and(data.word(k_configword)[1], 0x0F1);
	_or(data.word(k_configword)[1], 4);
loc_19125:
	flags.c() = (ebp >> 0x13) & 1;
		_jnc(loc_19131);
	_and(data.word(k_configword)[1], 0x0F1);
loc_19131:
	flags.c() = (ebp >> 4) & 1;
		_jnc(loc_1913d);
	_and(data.word(k_configword), 0x0FD);
loc_1913d:
	flags.c() = (ebp >> 0x14) & 1;
		_jnc(loc_19149);
	_and(data.word(k_configword), 0x0FE);
loc_19149:
	flags.c() = (ebp >> 0x0E) & 1;
		_jnc(loc_19155);
	_and(data.word(k_configword), 0x0BF);
loc_19155:
	flags.c() = (ebp >> 2) & 1;
		_jnc(loc_19161);
	_or(data.word(k_configword), 0x40);
loc_19161:
	flags.c() = (ebp >> 0x15) & 1;
	if (flags.c()) al = 1; else al = 0; //setb
	data.byte(k_byte_1de86) = al;
	al = data.byte(k_byte_1dcf8);
	ah = al;
	_and(al, 0x0F);
	data.byte(k_byte_1de82) = al;
	_shr(ah, 4);
	data.byte(k_byte_1de83) = ah;
	data.word(k_videomempointer) = 0x0B8000000;
	ax = 0x3508;
	// _int(0x21);
	data.word(k_oint8off_1de14) = bx;
	data.word(k_oint8seg_1de16) = es;
	ax = 0x3509;
	// _int(0x21);
	data.dword(k_oint9_1c1a4) = bx;
	data.dword(k_oint9_1c1a4)[2] = es;
	ax = 0x3524;
	// _int(0x21);
	data.dword(k_oint24_1c1ac) = bx;
	data.dword(k_oint24_1c1ac)[2] = es;
	ax = 0x352F;
	// _int(0x21);
	data.dword(k_oint2f_1c1b4) = bx;
	data.dword(k_oint2f_1c1b4)[2] = es;
	_push(ds);
	ax = cs;
	ds = ax;
	dx = 50308;
	ax = 0x2509;
	// _int(0x21);
	dx = 50320;
	ax = 0x2524;
	// _int(0x21);
	dx = 50324;
	ax = 0x252F;
	// _int(0x21);
	_pop(ds);
	ah = 0x34;
	// _int(0x21);
	data.word(k_critsectpoint_off) = bx;
	data.word(k_critsectpoint_seg) = es;
	_push(ds);
	ax = 0x5D06;
	// _int(0x21);
	ax = ds;
	_pop(ds);
	data.word(k_swapdata_off) = si;
	data.word(k_swapdata_seg) = ax;
	data.byte(k_byte_1de70) = 0x0FF;
	_mouse_init();
	bl = data.word(k_configword)[1];
	_shr(bl, 1);
	_and(bx, 7);
	_cmp(bl, 5);
		_jbe(loc_19212);
	bl = 0;
loc_19212:
	_shl(bx, 1);
	ax = data.word(kOff_1ca8e)[bx];
	data.word(kOff_1de3c) = ax;
	_cmp(data.byte(k_buffer_1db6c), 0x40);
		_jz(loc_19d94);
	_cmp(data.byte(k_buffer_1db6c), 0x20);
		_jbe(loc_192ca);
	data.word(k_word_1de4e) = 2;
	_find_mods();
		_jc(loc_19256);
	_callsubx();
		_jc(loc_19256);
	_readallmoules();
		_jc(loc_19250);
	_cmp(data.word(k_word_1de50), 0x1C);
		_jz(loc_192e0);
	data.byte(k_byte_1de7e) = 0;
loc_19250:
	// _cli();
	_deinit_125b9();
loc_19256:
	_mouse_deinit();
	_push(ds);
	dx = data.dword(k_oint2f_1c1b4);
	ax = 0x252F;
	// _int(0x21);
	_pop(ds);
	_push(ds);
	dx = data.dword(k_oint24_1c1ac);
	ax = 0x2524;
	// _int(0x21);
	_pop(ds);
	_push(ds);
	dx = data.dword(k_oint9_1c1a4);
	ax = 0x2509;
	// _int(0x21);
	_pop(ds);
	ax = 3;
	// _int(0x10);
	_txt_enableblink();
	cx = 0;
	dx = 0x124F;
	bl = 0x78;
	ax = 0x7F03;
	_draw_frame();
	_txt_draw_top_title();
	si = 1871;
	di = data.word(k_videomempointer);
	_write_scr();
	dx = 0x1300;
	bh = 0;
	ah = 2;
	// _int(0x10);
	_cmp(data.byte(k_byte_1de7e), 0);
		_jz(loc_192c3);
	dx = 0x1400;
	bh = 0;
	ah = 2;
	// _int(0x10);
	_push(ds);
	dx = data.word(k_messagepointer);
	ah = 9;
	// _int(0x21);
	_pop(ds);
loc_192c3:
	ah = 0x4C;
	al = data.byte(k_byte_1de7e);
	// _int(0x21);
loc_192ca:
	data.byte(k_byte_1de7e) = 5;
	data.word(k_messagepointer) = 2278;
	data.word(k_messagepointer)[2] = ds;
	_callsubx();
		_jc(loc_19256);
loc_192e0:
	si = 2366;
	_dosgetcurdir();
	data.word(k_word_1de62) = 0;
	data.word(k_word_1de5e) = 0;
	data.byte(k_byte_1de7f) = 1;
loc_192f7:
	_setvideomode();
	data.byte(k_byte_1de70) = 1;
loc_192ff:
	cx = 0;
	dx = 0x1B4F;
	bl = 0x78;
	ax = 0x7F03;
	_draw_frame();
	_txt_draw_top_title();
	ax = ds;
	es = ax;
	di = 2571;
	sub_12d05();
	es.byte(di) = 0;
	_sub(di, 0x16EF);
	_and(di, 0x0FFFE);
	ax = 0x50;
	_sub(ax, di);
	_add(ax, 0x320);
	di = data.word(k_videomempointer);
	_add(di, ax);
	si = 2571;
	ah = 0x78;
	_put_message();
	cx = 0x604;
	dx = 0x84B;
	bl = 0x7F;
	ax = 0x7803;
	_draw_frame();
	ah = 0x19;
	// _int(0x21);
	edx = 0x5C3A41;
	_add(dl, al);
	data.dword(k_buffer_1dc6c) = edx;
	si = ( data.dword(k_buffer_1dc6c)+3);
	dl = 0;
	ah = 0x47;
	// _int(0x21);
	si = 2332;
	_mystrlen();
	_shr(ax, 1);
	_neg(ax);
	_add(ax, 0x257);
	_shl(ax, 1);
	di = data.word(k_videomempointer);
	_add(di, ax);
	si = 2332;
	ah = 0x7B;
	_put_message();
	_cmp(data.byte(k_byte_1de7f), 1);
		_jnz(loc_19395);
	si = 1964;
	ax = 0x7E0D;
	_message_1be77();
	_modules_search();
loc_19395:
	data.byte(k_byte_1de7e) = 0;
	data.word(k_word_1de60) = 0x0FFFF;
	cx = 0x906;
	dx = 0x1949;
	bl = 0x7F;
	ax = 0x7803;
	_draw_frame();
loc_193ae:
	_filelist_198b8();
	ax = data.word(k_word_1de62);
	bl = 0x10;
	_recolortxt();
loc_193bc:
	al = data.byte(k_byte_1de7c);
	_xor(al, 1);
	data.byte(k_byte_1de7d) = al;
	_mouse_show();
loc_193c7:
	_test(data.byte(k_byte_1de90), 2);
		_jnz(loc_19848);
	_test(data.byte(k_byte_1de90), 1);
		_jnz(loc_19827);
	al = data.byte(k_byte_1de7c);
	_cmp(al, data.byte(k_byte_1de7d));
		_jz(loc_193ff);
	data.byte(k_byte_1de7d) = al;
	di = data.word(k_videomempointer);
	_add(di, 0x104A);
	ah = 0x78;
	si = 2138;
	_cmp(data.byte(k_byte_1de7c), 0);
		_jz(loc_193fc);
	si = 2132;
loc_193fc:
	_put_message();
loc_193ff:
	ax = data.word(k_key_code);
	_or(ax, ax);
		_jz(loc_193c7);
	_push(ax);
	_mouse_hide();
	_pop(ax);
	data.word(k_key_code) = 0;
	_cmp(al, 1);
		_jz(loc_1964e);
	_cmp(al, 0x48);
		_jz(loc_1957f);
	_cmp(al, 0x50);
		_jz(loc_1953c);
	_cmp(al, 0x47);
		_jz(loc_195a7);
	_cmp(al, 0x4F);
		_jz(loc_195be);
	_cmp(al, 0x49);
		_jz(loc_195ea);
	_cmp(al, 0x51);
		_jz(loc_19610);
	_cmp(al, 0x0E);
		_jz(loc_19762);
	_cmp(al, 0x53);
		_jz(loc_19657);
	_cmp(al, 0x3B);
		_jz(loc_19788);
	_cmp(al, 0x42);
		_jz(loc_197d6);
	_cmp(al, 0x43);
		_jz(loc_197e7);
	_cmp(al, 0x1C);
		_jnz(loc_193bc);
	ax = data.word(k_word_1de62);
	_add(ax, data.word(k_word_1de5e));
	dx = ax;
	_shl(ax, 1);
	_add(ax, dx);
	_add(ax, data.word(k_word_1de52));
	fs = ax;
	si = 0x0C;
	ax = ds;
	es = ax;
	di = 2300;
	dx = di;
	_write_df(false);
 	_movs(es.dword(di), fs.dword(si));
	_movs(es.dword(di), fs.dword(si));
	_movs(es.dword(di), fs.dword(si));
	ds.byte(di) = 0;
	_cmp(fs.byte(2), 0);
		_jz(loc_194eb);
	_cmp(fs.byte(2), 1);
		_jz(loc_19506);
	_push(dx);
	cx = 0x501;
	dx = 0x1A4E;
	bl = 0x7F;
	ax = 0x7800;
	_draw_frame();
	si = 1966;
	ax = 0x7E0D;
	_message_1be77();
	_pop(dx);
	_read_module();
		_jnc(loc_194e3);
	si = 1972;
	_cmp(ax, 0x0FFFE);
		_jz(loc_194ce);
	si = 1970;
	_cmp(ax, 0x0FFFD);
		_jz(loc_194ce);
	si = 1968;
loc_194ce:
	ax = 0x7E0D;
	_message_1be77();
	ax = 0;
	data.word(k_key_code) = ax;
loc_194da:
	_xchg(ax, );
	_or(ax, ax);
		_jz(loc_194da);
loc_194e3:
	data.byte(k_byte_1de7f) = 0;
	loc_192f7;
loc_194eb:
	data.byte(k_byte_1de7f) = 1;
	dx = 2300;
	ah = 0x3B;
	// _int(0x21);
	data.word(k_word_1de62) = 0;
	data.word(k_word_1de5e) = 0;
	loc_192ff;
loc_19506:
	data.byte(k_byte_1de7f) = 1;
	dl = fs.byte(0x0D);
	_sub(dl, 'A');
		_jc(loc_193bc);
	_cmp(dl, 'Z' - 'A' +1);
		_jnc(loc_193bc);
	bl = dl;
	_inc(bl);
	_push(dx);
	ax = 0x440F;
	// _int(0x21);
	_pop(dx);
	ah = 0x0E;
	// _int(0x21);
	data.word(k_word_1de62) = 0;
	data.word(k_word_1de5e) = 0;
	loc_192ff;
loc_1953c:
	_cmp(data.word(k_word_1de62), 0x0E);
		_jnc(loc_1955d);
	bx = data.word(k_word_1de54);
	_dec(bx);
	ax = data.word(k_word_1de62);
	_cmp(ax, bx);
		_jnc(loc_193bc);
	bl = 0x70;
	_recolortxt();
	_inc(data.word(k_word_1de62));
	loc_193ae;
loc_1955d:
	_cmp(data.word(k_word_1de54), 0x0F);
		_jc(loc_193bc);
	ax = data.word(k_word_1de54);
	_sub(ax, data.word(k_word_1de5e));
		_jc(loc_193bc);
	_cmp(ax, 0x10);
		_jc(loc_193bc);
	_inc(data.word(k_word_1de5e));
	loc_193ae;
loc_1957f:
	_cmp(data.word(k_word_1de62), 0);
		_jz(loc_19595);
	ax = data.word(k_word_1de62);
	bl = 0x70;
	_recolortxt();
	_dec(data.word(k_word_1de62));
	loc_193ae;
loc_19595:
	_sub(data.word(k_word_1de5e), 1);
		_jnc(loc_193ae);
	data.word(k_word_1de5e) = 0;
	loc_193ae;
loc_195a7:
	ax = data.word(k_word_1de62);
	bl = 0x70;
	_recolortxt();
	data.word(k_word_1de62) = 0;
	data.word(k_word_1de5e) = 0;
	loc_193ae;
loc_195be:
	ax = data.word(k_word_1de62);
	bl = 0x70;
	_recolortxt();
	ax = data.word(k_word_1de54);
	_dec(ax);
	_cmp(ax, 0x0F);
		_jc(loc_195de);
	_sub(ax, 0x0E);
	data.word(k_word_1de5e) = ax;
	data.word(k_word_1de62) = 0x0E;
	loc_193ae;
loc_195de:
	data.word(k_word_1de5e) = 0;
	data.word(k_word_1de62) = ax;
	loc_193ae;
loc_195ea:
	ax = data.word(k_word_1de62);
	bl = 0x70;
	_recolortxt();
	ax = 0;
	_xchg(ax, data.word(k_word_1de62));
	_or(ax, ax);
		_jnz(loc_193ae);
	_sub(data.word(k_word_1de5e), 0x0F);
		_jnc(loc_193ae);
	data.word(k_word_1de5e) = 0;
	loc_193ae;
loc_19610:
	ax = data.word(k_word_1de62);
	bl = 0x70;
	_recolortxt();
	ax = data.word(k_word_1de54);
	_dec(ax);
	_cmp(ax, 0x0F);
		_jc(loc_19648);
	ax = 0x0E;
	_xchg(ax, data.word(k_word_1de62));
	_cmp(ax, 0x0E);
		_jnz(loc_193ae);
	_add(data.word(k_word_1de5e), 0x0F);
	ax = data.word(k_word_1de54);
	_sub(ax, 0x0F);
	_cmp(data.word(k_word_1de5e), ax);
		_jbe(loc_193ae);
	data.word(k_word_1de5e) = ax;
	loc_193ae;
loc_19648:
	data.word(k_word_1de62) = ax;
	loc_193ae;
loc_1964e:
	si = 2366;
	_doschdir();
	loc_19250;
loc_19657:
	ax = data.word(k_word_1de5e);
	_add(ax, data.word(k_word_1de62));
	dx = ax;
	_shl(ax, 1);
	_add(ax, dx);
	_add(ax, data.word(k_word_1de52));
	fs = ax;
	_test(data.word(k_keyb_switches), 4);
		_jnz(loc_196b0);
	_cmp(fs.byte(2), 2);
		_jnz(loc_193bc);
	data.word(k_word_1de60) = 0x0FFFF;
	_test(fs.byte(3), 0x40);
		_jnz(loc_19698);
	_or(fs.byte(3), 0x40);
	_inc(data.word(k_word_1de5c));
	loc_1953c;
loc_19698:
	_and(fs.byte(3), 0x0BF);
	_sub(data.word(k_word_1de5c), 1);
		_jnc(loc_1953c);
	data.word(k_word_1de5c) = 0;
	loc_1953c;
loc_196b0:
	_cmp(data.word(k_word_1de5c), 0);
		_jz(loc_193bc);
	cx = 0x602;
	dx = 0x1A4E;
	bl = 0x7F;
	ax = 0x7800;
	_draw_frame();
	si = 1974;
	ax = 0x7E0D;
	_message_1be77();
loc_196d0:
	ax = 0;
	_xchg(ax, data.word(k_key_code));
	_or(ax, ax);
		_jz(loc_196d0);
		_js(loc_196d0);
	data.byte(k_byte_1de7f) = 0;
	_cmp(ax, 0x15);
		_jnz(loc_192ff);
	fs = data.word(k_word_1de52);
	cx = data.word(k_word_1de54);
loc_196f1:
	_test(fs.byte(3), 0x40);
		_jz(loc_19744);
	_cmp(fs.byte(2), 2);
		_jnz(loc_19744);
	_push(cx);
	_push(fs);
	cx = 0x602;
	dx = 0x1A4E;
	bl = 0x7F;
	ax = 0x7800;
	_draw_frame();
	_pop(fs);
	_push(fs);
	eax = fs.dword(0x0C);
	data.byte(k_afile) = eax;
	eax = fs.dword(0x10);
	data.byte(k_aname) = eax;
	eax = fs.dword(0x14);
	data.byte(k_a_ext) = eax;
	si = 1976;
	ax = 0x7E0D;
	_message_1be77();
	dx = 1977;
	ah = 0x41;
	// _int(0x21);
	_pop(fs);
	_pop(cx);
loc_19744:
	ax = fs;
	_add(ax, 3);
	fs = ax;
	_dec(cx);
		_jnz(loc_196f1);
	data.word(k_word_1de62) = 0;
	data.word(k_word_1de5e) = 0;
	data.byte(k_byte_1de7f) = 1;
	loc_192ff;
loc_19762:
	_cmp(data.byte(k_byte_1de7c), 1);
		_jz(loc_193bc);
	cx = 0x602;
	dx = 0x1A4E;
	bl = 0x7F;
	ax = 0x7800;
	_draw_frame();
	_keyb_19efd();
	data.byte(k_byte_1de7f) = 0;
	loc_192f7;
loc_19788:
	cx = 0x604;
	dx = 0x84B;
	bl = 0x7F;
	ax = 0x7803;
	_draw_frame();
	cx = 0x906;
	dx = 0x1949;
	bl = 0x7F;
	ax = 0x7803;
	_draw_frame();
	di = data.word(k_videomempointer);
	_add(di, 0x1042);
	cx = 0x4E;
	ax = 0x7820;
	_write_df(false);
 	_stosw(cx, true);
	si = 1985;
	di = data.word(k_videomempointer);
	_write_scr();
loc_197bf:
	_cmp(data.word(k_key_code), 0);
		_jle(loc_197bf);
	data.word(k_key_code) = 0;
	data.byte(k_byte_1de7f) = 0;
	loc_192f7;
loc_197d6:
	_mouse_deinit();
	_dosexec();
	_mouse_init();
	data.byte(k_byte_1de7f) = 0;
	loc_192f7;
loc_197e7:
	_xor(data.word(k_configword), 0x20);
	loc_193bc;
loc_190d3:
}

 
 /*;
uint16_t _word_244B7 = 0;
uint16_t anonymous_0 = 0;
uint16_t anonymous_1 = 0;
uint16_t anonymous_2 = 0;
uint16_t anonymous_3 = 0;
uint8_t asc_1058C[] = {0,24,11,13,10,2,1,3,4,7,0};
uint8_t _s3mtable_108D6[] = {255,16,11,13,21,18,17,19,20,27,29,23,22,255,255,9,255,28,7,14,15,255,255,255,8,255};
uint8_t _s3mtable_108F0[] = {0,3,5,4,7,255,255,255,8,255,255,6,12,13,255,255};
uint8_t _byte_11C29 = 0;
2,1,3,2,4,3,5};
uint8_t _byte_13C54[] = {0,9,18,27,36,45,54,64,64,74,83,92,101,110,119,128};
uint8_t _table_13EC3[] = {140,50,25,15,10,7,6,4,3,3,2,2,2,2,1,1};
uint8_t _table_14057[] = {255,128,64,42,32,25,21,18,16,14,12,11,10,9,9,8,135,219};
uint16_t _wss_freq_table = 5513;
uint16_t _wss_freq_table2[] = {1,6615,15,8000,0,9600,14,11025,3,16000,2,18900,5,22050,7,27429,4,32000,6,33075,13,37800,9,44100,11,48000,12};
186;
uint16_t _word_14913 = 1334;
186;
uint16_t _word_14BBB = 559;
186;
uint16_t _word_14CEB = 558;
uint32_t _int8addr = 0;
uint16_t _word_14F6C = 0;
uint16_t _timer_word_14F6E = 0;
uint8_t _byte_14F70 = 0;
uint8_t _byte_14F71 = 0;
uint8_t _byte_14F72 = 0;
uint8_t _byte_14F73 = 0;
186;
uint16_t _word_14FC0 = 4096;
160;
uint16_t _word_14FC5 = 4660;
186;
uint16_t _word_14FC8 = 888;
186;
uint16_t _word_1504D = 890;
161;
uint16_t _word_15056 = 4660;
160;
uint16_t _word_15126 = 4660;
187;
uint16_t _word_1519B = 4096;
138;
30;
uint16_t _word_151A3 = 4660;
uint8_t _pc_timer_tbl[] = {64,64,64,64,64,64,64,64,64,64,63,63,63,63,63,63,63,63,63,63,63,63,62,62,62,62,62,62,62,62,62,62,61,61,61,61,61,61,61,61,61,60,60,60,60,60,60,60,60,60,60,59,59,59,59,59,59,59,59,59,59,58,58,58,58,58,58,58,58,58,58,57,57,57,57,57,57,57,57,57,57,56,56,56,56,56,56,56,56,55,55,55,55,55,54,54,54,54,53,53,53,53,52,52,52,51,51,50,50,49,49,48,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,17,16,16,15,15,14,14,13,13,13,12,12,12,12,11,11,11,11,10,10,10,10,10,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,128,193};
uint8_t _byte_158B4 = 0;
128;
193;
uint8_t _byte_158E3 = 0;
128;
193;
uint8_t _byte_15912 = 0;
128;
193;
uint8_t _byte_15941 = 0;
128;
193;
uint8_t _byte_15970 = 0;
128;
193;
uint8_t _byte_1599F = 0;
128;
193;
uint8_t _byte_159CE = 0;
128;
193;
uint8_t _byte_159FD = 0;
128;
193;
uint8_t _byte_15A2C = 0;
128;
193;
uint8_t _byte_15A5B = 0;
128;
193;
uint8_t _byte_15A8A = 0;
128;
193;
uint8_t _byte_15AB9 = 0;
128;
193;
uint8_t _byte_15AE8 = 0;
128;
193;
uint8_t _byte_15B17 = 0;
128;
193;
uint8_t _byte_15B46 = 0;
128;
193;
uint8_t _byte_15B81 = 0;
128;
193;
uint8_t _byte_15BAD = 0;
128;
193;
uint8_t _byte_15BDA = 0;
128;
193;
uint8_t _byte_15C07 = 0;
128;
193;
uint8_t _byte_15C34 = 0;
128;
193;
uint8_t _byte_15C61 = 0;
128;
193;
uint8_t _byte_15C8E = 0;
128;
193;
uint8_t _byte_15CBB = 0;
128;
193;
uint8_t _byte_15CE8 = 0;
128;
193;
uint8_t _byte_15D15 = 0;
128;
193;
uint8_t _byte_15D42 = 0;
128;
193;
uint8_t _byte_15D6F = 0;
128;
193;
uint8_t _byte_15D9C = 0;
128;
193;
uint8_t _byte_15DC9 = 0;
128;
193;
uint8_t _byte_15DF6 = 0;
128;
193;
uint8_t _byte_15E23 = 0;
128;
193;
uint8_t _byte_16379 = 0;
128;
193;
uint8_t _byte_163A8 = 0;
128;
193;
uint8_t _byte_163D7 = 0;
128;
193;
uint8_t _byte_16406 = 0;
128;
193;
uint8_t _byte_16435 = 0;
128;
193;
uint8_t unk_16464 = 0;
128;
193;
uint8_t _byte_16493 = 0;
128;
193;
uint8_t _byte_164C2 = 0;
128;
193;
uint8_t _byte_164F1 = 0;
128;
193;
uint8_t _byte_16520 = 0;
128;
193;
uint8_t _byte_1654F = 0;
128;
193;
uint8_t _byte_1657E = 0;
128;
193;
uint8_t unk_165AD = 0;
128;
193;
uint8_t _byte_165DC = 0;
128;
193;
uint8_t _byte_1660B = 0;
128;
193;
uint8_t _byte_16646 = 0;
128;
193;
uint8_t _byte_16672 = 0;
128;
193;
uint8_t _byte_1669F = 0;
128;
193;
uint8_t _byte_166CC = 0;
128;
193;
uint8_t _byte_166F9 = 0;
128;
193;
uint8_t _byte_16726 = 0;
128;
193;
uint8_t _byte_16753 = 0;
128;
193;
uint8_t _byte_16780 = 0;
128;
193;
uint8_t _byte_167AD = 0;
128;
193;
uint8_t _byte_167DA = 0;
128;
193;
uint8_t _byte_16807 = 0;
128;
193;
uint8_t _byte_16834 = 0;
128;
193;
uint8_t _byte_16861 = 0;
128;
193;
uint8_t _byte_1688E = 0;
128;
193;
uint8_t _byte_168BB = 0;
128;
193;
uint8_t _byte_168E8 = 0;
uint8_t asc_182C3[] = {0,0,1,3,0,2,0,4,0,0,0,5,6,0,0,7};
uint8_t asc_182D3[] = {0,1,0,2,0,3,4,5};
uint16_t* _asmprintf_tbl = &_mysprintf_0_nop;
&_mysprintf_1_offstr;
&_mysprintf_2_off8str;
&_mysprintf_3_off16str;
&_mysprintf_4_u8toa;
&_mysprintf_5_u16toa;
&_mysprintf_6_u32toa;
&_mysprintf_7_i8toa;
&_mysprintf_8_i16toa;
&_mysprintf_9_i32toa;
&_mysprintf_10_u8tox;
&_mysprintf_11_u16tox;
&_mysprintf_12_u32tox;
uint16_t* _offs_noninterp2 = &loc_161C0;
&loc_161B0;
&loc_161A0;
&loc_16190;
&loc_16180;
&loc_16170;
&loc_16160;
&loc_16150;
&loc_16140;
&loc_16130;
&loc_16120;
&loc_16110;
&loc_16100;
&loc_160F0;
&loc_160E0;
&loc_160D0;
uint16_t* _offs_interpol2 = &loc_16617;
&loc_165E8;
&loc_165B9;
&loc_1658A;
&loc_1655B;
&loc_1652C;
&loc_164FD;
&loc_164CE;
&loc_1649F;
&loc_16470;
&loc_16441;
&loc_16412;
&loc_163E3;
&loc_163B4;
&loc_16385;
&loc_16356;
uint16_t* off_18E00 = &loc_16A89;
&loc_16A76;
&loc_16A63;
&loc_16A50;
&loc_16A3D;
&loc_16A2A;
&loc_16A17;
&loc_16A04;
&loc_169F1;
&loc_169DE;
&loc_169CB;
&loc_169B8;
&loc_169A5;
&loc_16992;
&loc_1697F;
&loc_1696C;
uint16_t* _offs_noninterp = &loc_15698;
&loc_15688;
&loc_15678;
&loc_15668;
&loc_15658;
&loc_15648;
&loc_15638;
&loc_15628;
&loc_15618;
&loc_15608;
&loc_155F8;
&loc_155E8;
&loc_155D8;
&loc_155C8;
&loc_155B8;
&loc_155A8;
uint16_t* _offs_interpol = &loc_15B52;
&loc_15B23;
&loc_15AF4;
&loc_15AC5;
&loc_15A96;
&loc_15A67;
&loc_15A38;
&loc_15A09;
&loc_159DA;
&loc_159AB;
&loc_1597C;
&loc_1594D;
&loc_1591E;
&loc_158EF;
&loc_158C0;
&loc_15891;
uint16_t* off_18E60 = &loc_15F78;
&loc_15F65;
&loc_15F52;
&loc_15F3F;
&loc_15F2C;
&loc_15F19;
&loc_15F06;
&loc_15EF3;
&loc_15EE0;
&loc_15ECD;
&loc_15EBA;
&loc_15EA7;
&loc_15E94;
&loc_15E81;
&loc_15E6E;
&loc_15E5B;
uint16_t* off_18E80 = &loc_16C20;
&loc_16C1A;
&loc_16C14;
&loc_16C0E;
&loc_16C08;
&loc_16C02;
&loc_16BFC;
&loc_16BF6;
&loc_16BF0;
&loc_16BEA;
&loc_16BE4;
&loc_16BDE;
&loc_16BD8;
&loc_16BD2;
&loc_16BCC;
&loc_16BC6;
uint16_t* off_18EA0 = &loc_16DB0;
&loc_16DA5;
&loc_16D9A;
&loc_16D8F;
&loc_16D84;
&loc_16D79;
&loc_16D6E;
&loc_16D63;
&loc_16D58;
&loc_16D4D;
&loc_16D42;
&loc_16D37;
&loc_16D2C;
&loc_16D21;
&loc_16D16;
&loc_16D0B;
uint16_t* off_18EC0 = &loc_17001;
&loc_16FE3;
&loc_16FC5;
&loc_16FA7;
&loc_16F89;
&loc_16F6B;
&loc_16F4D;
&loc_16F2F;
&loc_16F11;
&loc_16EF3;
&loc_16ED5;
&loc_16EB7;
&loc_16E99;
&loc_16E7B;
&loc_16E5D;
&loc_16E3F;
uint16_t* off_18EE0 = &loc_1736F;
&loc_1735F;
&loc_1734F;
&loc_1733F;
&loc_1732F;
&loc_1731F;
&loc_1730F;
&loc_172FF;
&loc_172EF;
&loc_172DF;
&loc_172CF;
&loc_172BF;
&loc_172AF;
&loc_1729F;
&loc_1728F;
&loc_1727F;
uint16_t* off_18F00 = &loc_1761E;
&loc_17600;
&loc_175E2;
&loc_175C4;
&loc_175A6;
&loc_17588;
&loc_1756A;
&loc_1754C;
&loc_1752E;
&loc_17510;
&loc_174F2;
&loc_174D4;
&loc_174B6;
&loc_17498;
&loc_1747A;
&loc_1745C;
uint16_t* off_18F20 = &loc_17956;
&loc_17943;
&loc_17930;
&loc_1791D;
&loc_1790A;
&loc_178F7;
&loc_178E4;
&loc_178D1;
&loc_178BE;
&loc_178AB;
&loc_17898;
&loc_17885;
&loc_17872;
&loc_1785F;
&loc_1784C;
&loc_17839;
uint16_t* off_18F40 = &loc_17C25;
&loc_17C08;
&loc_17BEB;
&loc_17BCE;
&loc_17BB1;
&loc_17B94;
&loc_17B77;
&loc_17B5A;
&loc_17B3D;
&loc_17B20;
&loc_17B03;
&loc_17AE6;
&loc_17AC9;
&loc_17AAC;
&loc_17A8F;
&loc_17A72;
uint16_t* _effoff_18F60 = &_eff_nullsub;
&_eff_nullsub;
&_eff_nullsub;
&_eff_nullsub;
&_eff_nullsub;
&_eff_nullsub;
&_eff_nullsub;
&_eff_nullsub;
&_eff_13A43;
&_eff_13A94;
&_eff_nullsub;
&_eff_13B06;
&_eff_13B78;
&_eff_13B88;
&_eff_13BA3;
&_eff_13CDD;
&_eff_13CE8;
&_eff_13DE5;
&_eff_13DEF;
&_eff_nullsub;
&_eff_13E2D;
&_eff_13E32;
&_eff_13E7F;
&_eff_13E84;
&_eff_13E8C;
&_eff_nullsub;
&_nullsub_2;
&_eff_13F05;
&_eff_13F3B;
&_eff_nullsub;
&_eff_14020;
&_eff_14030;
&_eff_14067;
uint16_t* _effoff_18FA2 = &_eff_nullsub;
&_eff_nullsub;
&_eff_nullsub;
&_eff_nullsub;
&_eff_nullsub;
&_eff_nullsub;
&_eff_nullsub;
&_eff_nullsub;
&_eff_13A43;
&_eff_nullsub;
&_eff_nullsub;
&_eff_13B06;
&_eff_nullsub;
&_eff_13B88;
&_eff_13BA3;
&_eff_13CDD;
&_eff_13CE8;
&_eff_13DE5;
&_eff_13DEF;
&_eff_nullsub;
&_eff_13E2D;
&_eff_13E32;
&_eff_13E7F;
&_eff_13E84;
&_eff_13E8C;
&_eff_nullsub;
&_nullsub_2;
&_eff_13F05;
&_eff_13F3B;
&_eff_nullsub;
&_eff_14020;
&_eff_14030;
&_eff_14067;
uint16_t* _effoff_18FE4 = &_eff_nullsub;
&_eff_13886;
&_eff_138A4;
&_eff_138D2;
&_eff_1392F;
&_eff_139AC;
&_eff_139B2;
&_eff_139B9;
&_eff_nullsub;
&_eff_nullsub;
&_eff_13AD7;
&_eff_nullsub;
&_eff_nullsub;
&_eff_nullsub;
&_eff_13BA3;
&_eff_nullsub;
&_eff_nullsub;
&_eff_13DE5;
&_eff_13DEF;
&_eff_13E1E;
&_eff_13E2D;
&_eff_13E32;
&_eff_13E7F;
&_eff_13E84;
&_eff_nullsub;
&_eff_138D2;
&_nullsub_2;
&_eff_13F05;
&_eff_13F3B;
&_eff_13FBE;
&_eff_nullsub;
&_eff_nullsub;
&_eff_nullsub;
uint16_t* _effoff_19026 = &_eff_nullsub;
&_eff_1387F;
&_eff_1389D;
&_eff_13BB2;
&_eff_13BC0;
&_eff_13BC8;
&_eff_13C02;
&_eff_13C34;
&_eff_13C3F;
&_eff_13C64;
&_eff_13C88;
&_eff_13C95;
&_eff_13CA2;
&_eff_13CB3;
&_eff_13CC9;
&_eff_nullsub;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
const char _aConfigFileNotF[] = { 'C','o','n','f','i','g',' ','f','i','l','e',' ','n','o','t',' ','f','o','u','n','d','.',' ','R','u','n',' ','I','S','E','T','U','P',' ','f','i','r','s','t','\r','\n','$','\r','\n','$'};
uint16_t _key_code = 0;
uint16_t _keyb_switches = 0;
uint8_t _prev_scan_code = 0;
uint32_t _oint9_1C1A4 = 0;
uint32_t _int1Avect = 0;
uint32_t _oint24_1C1AC = 0;
0;
uint32_t _oint2f_1C1B4 = 0;
uint8_t _byte_1C1B8 = 0;
0;
const char _aInertiaPlayerV1_[] = { 'I','n','e','r','t','i','a',' ','P','l','a','y','e','r',' ','V','1','.','2','2',' ','w','r','i','t','t','e','n',' ','b','y',' ','S','t','e','f','a','n',' ','D','a','n','e','s',' ','a','n','d',' ','R','a','m','o','n',' ','v','a','n',' ','G','o','r','k','o','m'};
13,10,10};
'U','s','a','g','e',':',' ','I','P','L','A','Y',' ','[','S','w','i','t','c','h','e','s',']',' ','[','F','i','l','e','N','a','m','e','.','E','x','t','|','@','F','i','l','e','L','i','s','t','.','E','x','t',']','\r','\n'};
10;
'S','w','i','t','c','h','e','s',':','\r','\n',' ','/','?',' ',' ','T','h','i','s',' ','h','e','l','p',' ','s','c','r','e','e','n','\r','\n',' ','/','h',' ',' ','T','h','i','s',' ','h','e','l','p',' ','s','c','r','e','e','n',' ','(','a','g','a','i','n','?','?','?',')','\r','\n',' ','/','i',' ',' ','D','i','s','p','l','a','y',' ','c','u','r','r','e','n','t',' ','s','o','u','n','d','c','a','r','d',' ','s','e','t','t','i','n','g','s','\r','\n',' ','/','l',' ',' ','L','o','o','p',' ','m','o','d','u','l','e',' ','w','h','e','n',' ','i','t','39','s',' ','d','o','n','e','\r','\n',' ','/','d',' ',' ','D','i','s','a','b','l','e',' ','m','o','d','u','l','e',' ','l','o','o','p','i','n','g','\r','\n',' ','/','g',' ',' ','S','t','a','r','t',' ','w','i','t','h',' ','g','r','a','p','h','i','c','a','l',' ','s','c','o','p','e','s',' ','[','F','-','2',']','\r','\n',' ','/','t',' ',' ','S','t','a','r','t',' ','w','i','t','h',' ','t','e','x','t','m','o','d','e',' ','V','U',' ','m','e','t','e','r','s',' ','[','F','-','3',']','\r','\n',' ','/','f',' ',' ','S','t','a','r','t',' ','w','i','t','h',' ','F','a','s','t','F','o','u','r','i','e','r',' ','s','c','r','e','e','n',' ','[','F','-','5',']','\r','\n',' ','/','e',' ',' ','D','i','s','a','b','l','e',' ','E','M','S',' ','u','s','a','g','e','\r','\n',' ','/','u',' ',' ','D','i','s','a','b','l','e',' ','U','M','B',' ','u','s','a','g','e','\r','\n',' ','/','o',' ',' ','E','n','a','b','l','e',' ','G','U','S',' ','C','h','a','n','n','e','l',' ','O','p','t','i','m','i','z','e',' ','[','U','s','e',' ','m','i','n','i','m','u','m',' ','n','u','m','b','e','r',' ','o','f',' ','v','o','i','c','e','s',']','\r'};
10;
' ','/','c',' ',' ','D','i','s','a','b','l','e',' ','G','U','S',' ','C','h','a','n','n','e','l',' ','O','p','t','i','m','i','z','e',' ','[','A','l','w','a','y','s',' ','u','s','e',' ','3','2',' ','v','o','i','c','e','s',']','\r','\n',' ','/','v',' ',' ','D','e','s','q','v','i','e','w',' ','m','o','d','e',':',' ','O','n','l','y',' ','u','s','e',' ','8','0','x','2','5',' ','t','e','x','t','m','o','d','e','\r','\n','$'};
const char _aCurrentSoundcard[] = { '\r','C','u','r','r','e','n','t',' ','S','o','u','n','d','c','a','r','d',' ','s','e','t','t','i','n','g','s',':','\r','\n','\n','$'};
const char _myendl[] = { '\r','\n','$'};
uint16_t* off_1CA8E = &_f3_textmetter;
&_f2_waves;
&_f5_graphspectr;
&_f4_patternnae;
&_f1_help;
&_f6_undoc;
uint16_t* _table_sndcrdname = &_aGravisUltrasou;
&_aProAudioSpectr;
&_aWindowsSoundSy;
&_aSoundBlaster16;
&_aSoundBlasterPr;
&_aSoundBlaster;
&_aCovox;
&_aStereoOn1;
&_aAdlibSoundcard;
&_aPcHonker;
&_aGeneralMidi;
const char * const _aGravisUltrasou = "Gravis UltraSound";
const char * const _aGravisMaxCodec = "Gravis MAX Codec";
const char * const _aProAudioSpectr = "Pro Audio Spectrum 16";
const char * const _aWindowsSoundSy = "Windows Sound System";
const char * const _aSoundBlaster16 = "Sound Blaster 16/16ASP";
const char * const _aSoundBlasterPr = "Sound Blaster Pro";
const char * const _aSoundBlaster = "Sound Blaster";
const char * const _aCovox = "Covox";
const char * const _aStereoOn1 = "Stereo-On-1";
const char * const _aAdlibSoundcard = "Adlib SoundCard";
const char * const _aPcHonker = "PC Honker";
const char * const _aGeneralMidi = "General MIDI";
uint16_t _atop_title = 338;
127;
const char _aInertiaPlayerV1_22A[] = { 'I','n','e','r','t','i','a',' ','P','l','a','y','e','r',' ','V','1','.','2','2',' ','A','s','s','e','m','b','l','y',' ','39','9','4',' ','C','D',' ','E','d','i','t','i','o','n',' ','b','y',' ','S','o','u','n','d',' ','S','o','l','u','t','i','o','n','s'};
1;
244;
1;
const char * const _aCopyrightC1994 = "Copyright (c) 1994,1995 by Stefan Danes and Ramon van Gorkom";
2;
120;
1;
170;
1;
const char _aShell130295211[] = { 'S','h','e','l','l',':',' ','1','3','/','0','2','/','9','5',' ','2','1',':','1','5',':','5','8'};
1;
70;
1;
const char _aPlayer13029521[] = { 'P','l','a','y','e','r',':',' '};
const char * const _a130295211558 = "13/02/95 21:15:58";
uint16_t _bottom_menu = 10;
127;
const char asc_1CC2D[] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
1;
170;
2;
126;
const char _aFilename_0[] = { 'F','i','l','e','n','a','m','e',' ',' ',' ',' ',' ',' ',':',' '};
2;
127;
const char _aFilename_ext[] = { 'F','i','l','e','N','a','m','e','.','E','x','t'};
1;
330;
2;
126;
const char _aModuleType_0[] = { 'M','o','d','u','l','e',' ','T','y','p','e',' ',' ',' ',':',' '};
2;
127;
const char _module_type_txt[] = { ' ',' ',' ',' '};
2;
126;
1;
490;
const char _aChannels[] = { 'C','h','a','n','n','e','l','s',' ',' ',' ',' ',' ',' ',':'};
1;
650;
const char _aSamplesUsed[] = { 'S','a','m','p','l','e','s',' ','U','s','e','d',' ',' ',':'};
1;
810;
const char _aCurrentTrack[] = { 'C','u','r','r','e','n','t',' ','T','r','a','c','k',' ',':'};
1;
970;
const char _aTrackPosition[] = { 'T','r','a','c','k',' ','P','o','s','i','t','i','o','n',':'};
1;
1130;
const char _aSpeed[] = { 'S','p','e','e','d'};
1;
1158;
':'};
2;
120;
1;
1188;
const char _aTab[] = { 'T','a','b'};
1;
248;
2;
uint8_t _byte_1CCEB = 120;
254;
2;
126;
const char _aPlayingInStereoFree[] = { ' ','P','l','a','y','i','n','g',' ','i','n',' ','S','t','e','r','e','o',',',' ','F','r','e','e',':'};
1;
408;
2;
120;
254;
2;
126;
const char _aProtracker1_0_0[] = { ' ','P','r','o','T','r','a','c','k','e','r',' ','1','.','0'};
1;
462;
2;
120;
const char _aF9_4[] = { 'F','-','9'};
1;
568;
2;
120;
254;
2;
126;
const char _aIgnoreBpmChanges[] = { ' ','I','g','n','o','r','e',' ','B','P','M',' ','c','h','a','n','g','e','s'};
1;
622;
2;
120;
const char _aF10_1[] = { 'F','-','1','0'};
2;
126;
1;
728;
2;
120;
254;
2;
126;
const char _aLoopModuleWhenDone[] = { ' ','L','o','o','p',' ','M','o','d','u','l','e',' ','w','h','e','n',' ','d','o','n','e'};
1;
782;
2;
120;
const char _aF11_1[] = { 'F','-','1','1'};
2;
126;
1;
888;
2;
120;
254;
2;
126;
const char _a24bitInterpolation[] = { ' ','2','4','b','i','t',' ','I','n','t','e','r','p','o','l','a','t','i','o','n'};
1;
942;
2;
120;
const char _aF12_1[] = { 'F','-','1','2'};
2;
126;
1;
1048;
const char _aMainVolume[] = { 'M','a','i','n',' ','V','o','l','u','m','e',' ',' ',' ',':'};
1;
1102;
2;
120;
'-',' ','+'};
2;
126;
1;
1208;
const char _aVolumeAmplify[] = { 'V','o','l','u','m','e',' ','A','m','p','l','i','f','y',':'};
1;
1262;
2;
120;
"[ ]";
uint16_t _f1_help_text = 1016;
127;
const char _aSoYouWantedSomeHelp[] = { 'S','o',' ','y','o','u',' ','w','a','n','t','e','d',' ','s','o','m','e',' ','h','e','l','p','?'};
1;
1128;
2;
127;
const char _aF2_0[] = { 'F','-','2'};
2;
126;
const char _aGraphicalScopesOneF[] = { ' ',' ','G','r','a','p','h','i','c','a','l',' ','s','c','o','p','e','s',',',' ','o','n','e',' ','f','o','r',' ','e','a','c','h',' ','c','h','a','n','n','e','l'};
1;
1288;
2;
127;
const char _aF3_0[] = { 'F','-','3'};
2;
126;
const char _aRealtimeVuMeters[] = { ' ',' ','R','e','a','l','t','i','m','e',' ','V','U',' ','m','e','t','e','r','s'};
1;
1448;
2;
127;
const char _aF4_0[] = { 'F','-','4'};
2;
126;
const char _aViewSampleNamesTwic[] = { ' ',' ','V','i','e','w',' ','s','a','m','p','l','e',' ','n','a','m','e','s',' ','(','t','w','i','c','e',' ','f','o','r',' ','m','o','r','e',')'};
1;
1608;
2;
127;
const char _aF5_0[] = { 'F','-','5'};
2;
126;
const char _aFastfourierFrequenc[] = { ' ',' ','F','a','s','t','F','o','u','r','i','e','r',' ','F','r','e','q','u','e','n','c','y',' ','A','n','a','l','y','s','i','s'};
1;
1768;
2;
127;
const char _aF8_0[] = { 'F','-','8'};
2;
uint8_t _aDosShellTypeEx = 126;
const char _aDosShellTypeExitToR[] = { ' ',' ','D','O','S',' ','S','h','e','l','l',' ','(','T','y','p','e',' ','E','X','I','T',' ','t','o',' ','r','e','t','u','r','n',')'};
1;
1928;
2;
uint8_t _aF9_1 = 127;
const char _aF9_2[] = { 'F','-','9'};
2;
uint8_t _aProtracker1_0C = 126;
const char _aProtracker1_0Compat[] = { ' ',' ','P','r','o','T','r','a','c','k','e','r',' ','1','.','0',' ','c','o','m','p','a','t','i','b','i','l','i','t','y',' ','o','n','/','o','f','f'};
1;
2088;
2;
uint8_t _aF10 = 127;
const char _aF10_0[] = { 'F','-','1','0'};
2;
uint8_t _aDisableBpmOnOf = 126;
const char _aDisableBpmOnOff[] = { ' ','D','i','s','a','b','l','e',' ','B','P','M',' ','o','n','/','o','f','f'};
1;
2248;
2;
uint8_t _aF11 = 127;
const char _aF11_0[] = { 'F','-','1','1'};
2;
uint8_t _aLoopModule = 126;
const char _aLoopModule_0[] = { ' ','L','o','o','p',' ','m','o','d','u','l','e'};
1;
2408;
2;
uint8_t _aF12 = 127;
const char _aF12_0[] = { 'F','-','1','2'};
2;
uint8_t _aToggle24bitInt = 126;
const char _aToggle24bitInterpol[] = { ' ','T','o','g','g','l','e',' ','2','4','b','i','t',' ','I','n','t','e','r','p','o','l','a','t','i','o','n'};
1;
1220;
2;
uint8_t _aGray = 127;
const char _aGray_0[] = { 'G','r','a','y',' ','-',' ','+'};
2;
uint8_t _aDecIncVolume = 126;
const char _aDecIncVolume_0[] = { ' ',' ','D','e','c','/','I','n','c',' ','v','o','l','u','m','e'};
1;
1390;
2;
127;
'[',' ',']'};
2;
uint8_t _aDecIncAmplify = 126;
const char _aDecIncAmplify_0[] = { ' ',' ','D','e','c','/','I','n','c',' ','a','m','p','l','i','f','y'};
1;
1536;
2;
uint8_t _aCursor = 127;
const char _aCursor_1[] = { 'C','u','r','s','o','r',' '};
26;
' '};
24;
2;
126;
const char _aFastErForward[] = { ' ',' ','F','a','s','t','(','e','r',')',' ','f','o','r','w','a','r','d'};
1;
1696;
2;
127;
const char _aCursor_0[] = { 'C','u','r','s','o','r',' ','27',' '};
25;
2;
126;
const char _aFastErRewind[] = { ' ',' ','F','a','s','t','(','e','r',')',' ','r','e','w','i','n','d'};
1;
1860;
2;
127;
const char _a1Thru0[] = { '1',' ','T','h','r','u',' ','0'};
2;
126;
const char _aMuteChannel[] = { ' ',' ','M','u','t','e',' ','c','h','a','n','n','e','l'};
1;
2016;
2;
127;
const char _aScrolllock[] = { 'S','c','r','o','l','l','L','o','c','k'};
2;
126;
const char _aLoopPattern[] = { ' ',' ','L','o','o','p',' ','p','a','t','t','e','r','n'};
1;
2186;
2;
127;
const char _aPause[] = { 'P','a','u','s','e'};
2;
126;
const char _aGuess___[] = { ' ',' ','G','u','e','s','s','.','.','.'};
1;
2350;
2;
127;
const char _aEnd[] = { 'E','n','d'};
2;
126;
const char _aEndPattern[] = { ' ',' ','E','n','d',' ','p','a','t','t','e','r','n'};
1;
2510;
2;
127;
const char _aTab_0[] = { 'T','a','b'};
2;
126;
const char * const _aTogglePalNtsc = "  Toggle PAL/NTSC";
uint16_t _hopeyoulike = 966;
126;
const char _aHopeYouLikedUsingTh[] = { 'H','o','p','e',' ','y','o','u',' ','l','i','k','e','d',' ','u','s','i','n','g',' ','t','h','e',' '};
2;
127;
const char _aInertiaPlayer[] = { 'I','n','e','r','t','i','a',' ','P','l','a','y','e','r'};
2;
126;
const char _aWhichIsWrittenIn[] = { ' ','w','h','i','c','h',' ','i','s',' ','w','r','i','t','t','e','n',' ','i','n',' '};
2;
127;
const char _a100Assembler[] = { '1','0','0','%',' ','a','s','s','e','m','b','l','e','r','!'};
2;
126;
1;
1292;
const char _aIfYouHaveBugReports[] = { 'I','f',' ','y','o','u',' ','h','a','v','e',' ','b','u','g','-','r','e','p','o','r','t','s',',',' ','s','u','g','g','e','s','t','i','o','n','s',' ','o','r',' ','c','o','m','m','e','n','t','s',' ','s','e','n','d',' ','a',' ','m','e','s','s','a','g','e',' ','t','o',':'};
1;
1452;
const char _aInternet[] = { 'I','n','t','e','r','n','e','t',' ',':',' '};
2;
127;
const char _aSdanes@marvels_hack[] = { 's','d','a','n','e','s','@','m','a','r','v','e','l','s','.','h','a','c','k','t','i','c','.','n','l'};
2;
126;
1;
1612;
const char _aFidonet[] = { 'F','i','d','o','N','e','t',' ',' ',':',' '};
2;
127;
const char _a2284116_8[] = { '2',':','2','8','4','/','1','1','6','.','8'};
2;
126;
1;
2086;
const char _aSendEmailTo[] = { 'S','e','n','d',' ','e','m','a','i','l',' ','t','o',' '};
2;
127;
const char _aListserver@oliver_s[] = { 'l','i','s','t','s','e','r','v','e','r','@','o','l','i','v','e','r','.','s','u','n','.','a','c','.','z','a'};
2;
126;
const char _aToSubscribeToOneOrB[] = { ' ','t','o',' ','s','u','b','s','c','r','i','b','e',' ','t','o',' ','o','n','e',' ','o','r',' ','b','o','t','h',' ','o','f'};
1;
2246;
const char _aThe[] = { 't','h','e',' '};
2;
127;
const char _aInertiaMailinglists[] = { 'I','n','e','r','t','i','a',' ','M','a','i','l','i','n','g','l','i','s','t','s'};
2;
126;
const char _aAndWriteFollowingTe[] = { ' ','a','n','d',' ','w','r','i','t','e',' ','f','o','l','l','o','w','i','n','g',' ','t','e','x','t',' ','i','n',' ','y','o','u','r',' ','m','e','s','s','a','g','e',':'};
1;
2406;
const char _aToConnectToBinaryIn[] = { 'T','o',' ','c','o','n','n','e','c','t',' ','t','o',' ','B','i','n','a','r','y',' ','I','n','e','r','t','i','a',' ','r','e','l','e','a','s','e','s',':',' '};
2;
127;
const char _aSubscribeInertiaLis[] = { 's','u','b','s','c','r','i','b','e',' ','i','n','e','r','t','i','a','-','l','i','s','t',' ','Y','o','u','r','R','e','a','l','N','a','m','e'};
2;
126;
1;
2566;
const char _aToConnectToDiscussi[] = { 'T','o',' ','c','o','n','n','e','c','t',' ','t','o',' ','D','i','s','c','u','s','s','i','o','n',' ','M','a','i','l','i','n','g',' ','l','i','s','t',':',' '};
2;
127;
const char * const _aSubscribeInertiaTal = "subscribe inertia-talk YourRealName";
uint16_t _word_1D26D = 1010;
126;
const char _aShellingToOperating[] = { 'S','h','e','l','l','i','n','g',' ','t','o',' ','O','p','e','r','a','t','i','n','g',' ','S','y','s','t','e','m','.','.','.'};
1;
1322;
const char _aType[] = { 'T','y','p','e',' '};
2;
127;
const char _aExit[] = { 'E','X','I','T'};
2;
126;
const char _aToReturnTo[] = { ' ','t','o',' ','r','e','t','u','r','n',' ','t','o',' '};
2;
127;
const char * const _aInertiaPlayer_0 = "Inertia Player";
const char * const _msg = "Searching directory for modules  ";
const char * const _aLoadingModule = "Loading module";
const char * const _aModuleIsCorrupt = "Module is corrupt!";
const char * const _aNotEnoughDram_0 = "Not enough DRAM on your UltraSound to load all samples!";
const char * const _aNotEnoughMemo_0 = "Not enough memory available to load all samples!";
const char * const _aDeleteMarkedFil = "Delete marked files? [Y/N]";
const char _aDeletingFile[] = { 'D','e','l','e','t','i','n','g',' ','f','i','l','e',':',' '};
const char _aFile[] = { 'F','i','l','e'};
const char _aName[] = { 'n','a','m','e'};
const char _a_ext[] = { '.','E','x','t'};
0;
const char * const _aPal = "(PAL) ";
const char * const _aNtsc = "(NTSC)";
uint16_t _word_1D3B0 = 1182;
123;
const char _aFileSelectorHelp[] = { 'F','i','l','e',' ','S','e','l','e','c','t','o','r',' ','H','e','l','p'};
1;
1778;
2;
126;
const char _aUse[] = { 'U','s','e',' '};
2;
127;
const char _aHome[] = { 'H','o','m','e'};
2;
126;
','};
2;
127;
const char _aEnd_0[] = { 'E','n','d'};
2;
126;
','};
2;
127;
const char _aPgup[] = { 'P','g','U','p'};
2;
126;
','};
2;
127;
const char _aPgdn[] = { 'P','g','D','n'};
2;
126;
','};
2;
127;
24;
2;
126;
const char _aAnd[] = { ' ','a','n','d',' '};
2;
127;
25;
2;
126;
const char _aToMoveTheHighlighte[] = { ' ','t','o',' ','m','o','v','e',' ','t','h','e',' ','h','i','g','h','l','i','g','h','t','e','d',' ','b','a','r'};
1;
1938;
const char _aPress[] = { 'P','r','e','s','s',' '};
2;
127;
const char _aEnter[] = { 'E','n','t','e','r'};
2;
126;
const char _aToPlayTheModuleOrSe[] = { ' ','t','o',' ','p','l','a','y',' ','t','h','e',' ','m','o','d','u','l','e',' ','o','r',' ','s','e','l','e','c','t',' ','t','h','e',' ','d','r','i','v','e','/','d','i','r','e','c','t','o','r','y'};
1;
2258;
2;
127;
const char _aEsc[] = { 'E','S','C'};
2;
126;
1;
2278;
const char _aQuitIplay[] = { 'Q','u','i','t',' ','I','P','L','A','Y'};
1;
2418;
2;
127;
const char _aF1[] = { 'F','-','1'};
2;
126;
1;
2438;
const char _aThisHelpScreenButIG[] = { 'T','h','i','s',' ','h','e','l','p',' ','s','c','r','e','e','n',',',' ','b','u','t',' ','I',' ','g','u','e','s','s',' ','y','o','u',' ','a','l','r','e','a','d','y',' ','f','o','u','n','d',' ','i','t','.','.','.'};
1;
2578;
2;
127;
const char _aF8_1[] = { 'F','-','8'};
2;
126;
1;
2598;
const char _aDosShellTypeExitT_0[] = { 'D','O','S',' ','S','h','e','l','l',' ','(','T','y','p','e',' ','E','X','I','T',' ','t','o',' ','r','e','t','u','r','n',')'};
1;
2738;
2;
127;
const char _aF9_3[] = { 'F','-','9'};
2;
126;
1;
2758;
const char _aToggleQuickreadingO[] = { 'T','o','g','g','l','e',' ','Q','u','i','c','k','R','e','a','d','i','n','g',' ','o','f',' ','m','o','d','u','l','e',' ','n','a','m','e'};
1;
2898;
uint8_t unk_1D516 = 2;
127;
const char _aDel[] = { 'D','e','l'};
2;
126;
1;
2918;
const char _aMarkFileToDelete[] = { 'M','a','r','k',' ','f','i','l','e',' ','t','o',' ','d','e','l','e','t','e'};
1;
3058;
2;
127;
const char _aCtrlDel[] = { 'C','t','r','l',' ','D','e','l'};
2;
126;
1;
3078;
const char _aDeleteAllFilesWhich[] = { 'D','e','l','e','t','e',' ','a','l','l',' ','f','i','l','e','s',' ','w','h','i','c','h',' ','a','r','e',' ','m','a','r','k','e','d',' ','t','o',' ','d','e','l','e','t','e'};
1;
3218;
2;
127;
const char _aBackspace[] = { 'B','a','c','k','S','p','a','c','e'};
2;
126;
1;
3238;
const char _aReturnToPlaymodeOnl[] = { 'R','e','t','u','r','n',' ','t','o',' ','p','l','a','y','m','o','d','e',' ','[','O','n','l','y',' ','i','f',' ','t','h','e',' ','m','u','s','i','c',' ','i','s',' ','p','l','a','y','i','n','g',']'};
1;
3718;
2;
126;
const char * const _aPressAnyKeyToReturn = "Press any key to return to the fileselector";
const char _aPressF1ForHelpQu[] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','P','r','e','s','s',' ','F','-','1',' ','f','o','r',' ','h','e','l','p',',',' ','Q','u','i','c','k','R','e','a','d','='};
uint16_t _word_1D614 = 8224;
uint8_t _byte_1D616 = 32;
const char * const _aF9 = " [F-9]              ";
const char _aHitBackspaceToRe[] = { 'H','i','t',' ','b','a','c','k','s','p','a','c','e',' ','t','o',' ','r','e','t','u','r','n',' ','t','o',' ','p','l','a','y','m','o','d','e',',',' ','F','-','1',' ','f','o','r',' ','h','e','l','p',',',' ','Q','u','i','c','k','R','e','a','d','='};
uint16_t _word_1D669 = 8224;
uint8_t _byte_1D66B = 32;
const char * const _aF9_0 = " [F-9]";
const char _aSamplename[] = { '#',' ','S','a','m','p','l','e','N','a','m','e',' ',' ',' '};
2;
const char _aXpressF4ForMor[] = { 'x','P','r','e','s','s',' ','F','-','4',' ','f','o','r',' ','m','o','r','e'};
2;
const char * const _aSizeVolModeC2T = "~   Size Vol Mode  C-2 Tune LoopPos LoopEnd";
uint8_t unk_1D6C3 = 2;
const char _aUnused256[] = { '',' ','U','n','u','s','e','d'};
const char * const _a256 = "256";
const char * const _a512 = "512";
const char * const _a768 = "768";
const char * const _a1024 = "1024";
const char * const _aKb = "KB";
const char * const asc_1D6E0 = "               ";
const char * const _aPortamentoUp = "Portamento Up  ";
const char * const _aPortamentoDown = "Portamento Down";
const char * const _aTonePortamento = "Tone Portamento";
const char * const _aVibrato = "Vibrato        ";
const char * const _aPortVolslide = "Port + VolSlide";
const char * const _aVibrVolslide = "Vibr + VolSlide";
const char * const _aTremolo = "Tremolo        ";
const char * const _aFinePanning = "Fine Panning   ";
const char * const _aSetSampleOfs = "Set Sample Ofs ";
const char * const _aVolumeSliding = "Volume Sliding ";
const char * const _aPositionJump = "Position Jump  ";
const char * const _aVolumeChange = "Volume Change  ";
const char * const _aPatternBreak = "Pattern Break  ";
const char * const _aE_command = "E_Command      ";
const char * const _aSetSpeedBpm = "Set Speed/BPM  ";
const char * const _aSetSpeed = "Set Speed      ";
const char * const _aFinePortaUp = "Fine Porta Up  ";
const char * const _aFinePortaDown = "Fine Porta Down";
const char * const _aFineTonePorta = "Fine Tone Porta";
const char * const _aFineVibrato = "Fine Vibrato   ";
const char * const _aFineVolSlide = "Fine Vol Slide ";
const char * const _aFinePortVolsl = "Fine Port+VolSl";
const char * const _aFineVibrVolsl = "Fine Vibr+VolSl";
const char * const _aSetStmSpeed = "Set STM Speed  ";
const char * const _aAutoToneporta = "Auto TonePorta ";
const char * const _aTriller = "Triller        ";
const char * const _aTremor = "Tremor         ";
const char * const _aRetrigVolume = "Retrig+Volume  ";
const char * const _aArpeggio = "Arpeggio       ";
const char * const _aSetAmplify = "Set Amplify    ";
const char * const _aFarTempo = "FAR Tempo      ";
const char * const _aFarFineTempo = "FAR Fine Tempo ";
const char * const _aSetFilter = "Set Filter     ";
const char * const _aFineslideUp = "FineSlide Up   ";
const char * const _aFineslideDown = "FineSlide Down ";
const char * const _aGlissandoCtrl = "Glissando Ctrl ";
const char * const _aVibratoControl = "Vibrato Control";
const char * const _aSetFinetune = "Set FineTune   ";
const char * const _aJumpToLoop = "Jump To Loop   ";
const char * const _aTremoloControl = "Tremolo Control";
const char * const _aSetPanning = "Set Panning    ";
const char * const _aRetriggerNote = "Retrigger Note ";
const char * const _aFinevolumeUp = "FineVolume Up  ";
const char * const _aFinevolumeDown = "FineVolume Down";
const char * const _aNoteCut = "Note Cut       ";
const char * const _aNoteDelay = "Note Delay     ";
const char * const _aPatternDelay = "Pattern Delay  ";
const char * const _aInvertLoop = "Invert Loop    ";
const char * const _aSetLoopPoint = "Set Loop Point ";
const char * const asc_1DA00 = "                      ";
const char * const _aMute = "<Mute>                ";
const char * const _aMarkedToDelete = "<Marked to Delete>    ";
const char _notes[] = { ' ',' ','C','-','C','#','D','-','D','#','E','-','F','-','F','#','G','-','G','#','A','-','A','#','B','-'};
const char _slider[] = { '�','\','\','|','/','�','\','\','|','/'};
const char _aModuleNotFound[] = { 'M','o','d','u','l','e',' ','n','o','t',' ','f','o','u','n','d','.','\r','\n','$'};
const char _aModuleLoadErro[] = { 'M','o','d','u','l','e',' ','l','o','a','d',' ','e','r','r','o','r','.','\r','\n','$'};
const char _aNotEnoughMemor[] = { 'N','o','t',' ','e','n','o','u','g','h',' ','m','e','m','o','r','y','.','\r','\n','$'};
const char _aListFileNotFou[] = { 'L','i','s','t',' ','f','i','l','e',' ','n','o','t',' ','f','o','u','n','d','.','\r','\n','$'};
uint8_t _aCriticalErrorT[] = {13,10,10};
'C','r','i','t','i','c','a','l',' ','e','r','r','o','r',':',' ','T','h','e',' ','p','l','a','y','e','r',' ','j','u','m','p','e','d',' ','t','o',' ','D','O','S',',',' ','a','n','d',' ','s','h','o','u','l','d',' ','n','o','t',' ','b','e',' ','i','n','v','o','k','e','d',' ','a','g','a','i','n','.','\r','\n','C','l','o','s','e',' ','t','h','i','s',' ','D','O','S',' ','s','e','s','s','i','o','n',' ','f','i','r','s','t',' ','w','i','t','h',' ','t','h','e',' ','"','E','X','I','T','"',' ','c','o','m','m','a','n','d','.','\r','\n'};
10;
'(','P','r','e','s','s',' ','a','n','y',' ','k','e','y',' ','t','o',' ','c','o','n','t','i','n','u','e',')','$'};
const char * const _sIplay_cfg = "C:\\IPLAY.CFG";
uint8_t _buffer_1DB6C = 0;
uint8_t _buffer_1DBEC = 0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
uint8_t unk_1DC01 = 0;
0;
0;
0;
0;
0;
0;
0;
0;
uint8_t _byte_1DC0A = 0;
uint32_t _buffer_1DC6C = 0;
uint8_t unk_1DC70 = 0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
uint8_t unk_1DC7B = 0;
uint8_t _byte_1DC7C = 0;
uint32_t _dword_1DCEC = 273829449;
uint8_t _cfg_buffer = 4;
uint8_t _snd_card_type = 3;
uint16_t _snd_base_port_0 = 65535;
uint8_t _irq_number_1 = 255;
uint8_t _dma_channel_1 = 255;
uint8_t _freq_1DCF6 = 44;
uint8_t _byte_1DCF7 = 255;
uint8_t _byte_1DCF8 = 20;
uint16_t _configword = 8587;
uint8_t _byte_1DCFB = 75;
0;
uint8_t _mystr = 0;
uint8_t _byte_1DD3F = 0;
const char * const _a_mod_nst_669_s = ".MOD.NST.669.STM.S3M.MTM.PSM.WOW.INR.FAR.ULT.OKT.OCT   ";
const char _aPlaypausloop[] = { 'P','l','a','y','P','a','u','s','L','o','o','p'};
const char _aJanfebmaraprmayj[] = { ' ',' ',' ','J','a','n','F','e','b','M','a','r','A','p','r','M','a','y','J','u','n','J','u','l','A','u','g','S','e','p','O','c','t','N','o','v','D','e','c'};
const char * const _frameborder = "      ������ɻȼͺڿ��ĳַӽĺոԾͳ";
uint16_t _oint8off_1DE14 = 0;
uint16_t _oint8seg_1DE16 = 0;
uint16_t _critsectpoint_off = 0;
uint16_t _critsectpoint_seg = 0;
uint16_t _swapdata_off = 0;
uint16_t _swapdata_seg = 0;
uint16_t _videomempointer = 0;
0;
uint32_t _videopoint_shiftd = 0;
uint32_t _segfsbx_1DE28 = 0;
uint32_t _dword_1DE2C = 0;
uint16_t _messagepointer = 0;
0;
uint32_t _volume_1DE34 = 0;
uint16_t _outp_freq = 0;
uint16_t _esseg_atstart = 0;
uint16_t* off_1DE3C = &loc_19050;
uint16_t* _offs_draw = &loc_19050;
uint16_t* _offs_draw2 = &loc_19050;
uint16_t* off_1DE42 = &loc_19050;
uint16_t _amount_of_x = 0;
uint16_t _word_1DE46 = 0;
uint16_t _current_patterns = 0;
uint16_t _word_1DE4A = 0;
uint16_t _word_1DE4C = 0;
uint16_t _word_1DE4E = 0;
uint16_t _word_1DE50 = 0;
uint16_t _word_1DE52 = 0;
uint16_t _word_1DE54 = 0;
uint16_t _word_1DE56 = 0;
uint16_t _word_1DE58 = 0;
uint16_t _word_1DE5A = 0;
uint16_t _word_1DE5C = 0;
uint16_t _word_1DE5E = 0;
uint16_t _word_1DE60 = 0;
uint16_t _word_1DE62 = 0;
uint16_t _word_1DE64 = 0;
uint16_t _word_1DE66 = 0;
uint16_t _fhandle_1DE68 = 0;
uint16_t _word_1DE6A = 0;
uint16_t _word_1DE6C = 0;
uint16_t _word_1DE6E = 0;
uint8_t _byte_1DE70 = 0;
uint8_t _byte_1DE71 = 0;
uint8_t _byte_1DE72 = 0;
uint8_t _byte_1DE73 = 0;
uint8_t _byte_1DE74 = 0;
uint8_t _byte_1DE75 = 0;
uint8_t _byte_1DE76 = 0;
uint8_t _flg_play_settings = 0;
uint8_t _byte_1DE78 = 0;
uint8_t _byte_1DE79 = 0;
uint8_t _byte_1DE7A = 0;
uint8_t _byte_1DE7B = 0;
uint8_t _byte_1DE7C = 0;
uint8_t _byte_1DE7D = 0;
uint8_t _byte_1DE7E = 0;
uint8_t _byte_1DE7F = 0;
1;
uint8_t _byte_1DE81 = 0;
uint8_t _byte_1DE82 = 0;
uint8_t _byte_1DE83 = 3;
uint8_t _byte_1DE84 = 0;
uint8_t _byte_1DE85 = 0;
uint8_t _byte_1DE86 = 0;
0;
uint32_t _dword_1DE88 = 0;
uint16_t _mousecolumn = 0;
uint16_t _mouserow = 0;
uint8_t _byte_1DE90 = 0;
uint8_t _mouse_exist_flag = 0;
uint8_t _mouse_visible = 0;
uint16_t _x_storage[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
0;
uint8_t _buffer_1 = 0;
uint8_t _byte_1E0E0 = 0;
uint8_t _byte_1E89B = 0;
uint8_t _buffer_2 = 0;
uint16_t _buffer_1seg = 0;
uint16_t _buffer_2seg = 0;
uint8_t _byte_22EE4 = 0;
uint8_t unk_23EE4 = 0;
uint8_t _byte_23EE5 = 0;
uint8_t _byte_23F48 = 0;
uint8_t unk_24074 = 0;
uint8_t _byte_24075 = 0;
uint8_t _byte_240D8 = 0;
uint8_t _byte_24204 = 0;
uint8_t _palette_24404 = 0;
1;
2;
3;
4;
5;
6;
7;
8;
9;
10;
11;
12;
13;
14;
15;
0;
uint8_t _vga_palette[] = {0,0,0,2,2,6,4,5,13,7,8,21,10,11,27,13,14,33,16,17,42,19,20,49,0,42,42,0,45,45,0,48,48,0,51,51,0,54,54,0,57,57,0,60,60,0,63,63};
uint16_t _word_24445 = 0;
0;
0;
0;
uint8_t unk_24453 = 0;
32;
13;
uint8_t unk_24456 = 32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
65535;
65535;
65535;
65535;
0;
uint32_t unk_244C4 = 0;
uint32_t _dword_244C8 = 0;
uint32_t _multip_244CC = 0;
uint32_t _multip_244D0 = 0;
uint32_t _dword_244D4 = 0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
uint32_t _dword_244E4 = 0;
uint32_t _dword_244E8 = 0;
uint32_t _dword_244EC = 0;
uint32_t _dword_244F0 = 0;
uint32_t _dword_244F4 = 0;
uint32_t _dword_244F8 = 0;
uint32_t _dword_244FC = 0;
uint32_t _dword_24500 = 0;
uint32_t _dword_24504 = 0;
uint32_t _dword_24508 = 0;
uint16_t _word_2450C = 0;
uint16_t _word_2450E = 0;
0;
0;
0;
0;
uint16_t _word_24514 = 0;
uint16_t _word_24516 = 0;
uint16_t _word_24518 = 0;
uint16_t _word_2451A = 0;
uint16_t _word_2451C = 0;
uint16_t _word_2451E = 0;
uint16_t _word_24520 = 0;
uint16_t _word_24522 = 0;
uint16_t _word_24524 = 0;
uint32_t _tabledword_24526[] = {0,65536,46340,25079,12785,6423,3215,1608,804,402,201,100,50,25,12};
uint32_t _tabledword_24562[] = {-65536,0,46340,60547,64276,65220,65457,65516,65531,65534,65535,65535,65535,65535,0};
0;
0;
const char * const _a070295122642 = "07/02/95 12:26:42";
uint32_t _pointer_245B4 = 0;
uint32_t _dma_buf_pointer = 0;
uint32_t _dword_245BC = 0;
uint32_t _dword_245C0 = 0;
uint32_t _dword_245C4 = 0;
uint16_t* off_245C8 = &_moduleread;
uint16_t* off_245CA = &_moduleread;
uint16_t* off_245CC = &_moduleread;
uint16_t* off_245CE = &_moduleread;
uint16_t _savesp_245D0 = 0;
uint16_t _word_245D2 = 0;
uint16_t _word_245D4 = 0;
uint16_t _word_245D6 = 0;
uint16_t _word_245D8 = 0;
uint16_t _word_245DA = 0;
uint16_t _word_245DC = 0;
uint16_t _freq_245DE = 0;
uint16_t* off_245E0 = &_chrin;
uint16_t* off_245E2 = &_myin;
uint16_t _word_245E4 = 0;
uint16_t _word_245E8 = 0;
uint16_t _word_245EA = 0;
uint16_t _word_245EC = 0;
uint16_t _word_245EE = 0;
uint16_t _word_245F0 = 0;
uint16_t _word_245F2 = 0;
uint16_t _my_seg_index = 0;
uint16_t _word_245F6 = 0;
uint16_t _word_245F8 = 0;
uint16_t _word_245FA = 0;
uint16_t _volume_245FC = 256;
uint16_t _amplification = 100;
uint16_t _word_24600 = 0;
uint16_t _word_24602 = 0;
uint16_t _interrupt_mask = 0;
uint16_t _old_intprocoffset = 0;
uint16_t _old_intprocseg = 0;
uint16_t _intvectoffset = 0;
uint16_t _word_2460C = 0;
uint16_t _word_2460E = 0;
uint16_t _word_24610 = 0;
uint16_t _my_size = 0;
uint16_t _word_24614 = 0;
uint8_t _byte_24616 = 0;
uint8_t _byte_24617 = 0;
uint8_t _byte_24618 = 0;
uint8_t _byte_24619 = 0;
uint8_t _byte_2461A = 0;
uint8_t _byte_2461B = 0;
uint8_t _byte_2461C = 0;
uint8_t _byte_2461D = 0;
uint8_t _byte_2461E = 0;
uint8_t _byte_2461F = 0;
uint8_t _byte_24620 = 0;
uint8_t _byte_24621 = 0;
uint8_t _sndflags_24622 = 0;
uint8_t _byte_24623 = 0;
uint8_t _bit_mode = 8;
uint8_t _byte_24625 = 0;
uint16_t _gravis_port = 0;
uint8_t _byte_24628 = 0;
uint8_t _byte_24629 = 32;
uint8_t _irq_number_0 = 0;
uint8_t _byte_2462B = 0;
uint8_t _dma_channel_0 = 0;
uint8_t _byte_2462D = 0;
uint16_t* off_2462E = &_a070295122642;
uint16_t _word_24630 = 0;
uint16_t _word_24632 = 0;
uint16_t _word_24634 = 0;
uint16_t _word_24636 = 0;
uint16_t _freq2 = 0;
0;
uint8_t _byte_2463B = 0;
uint32_t _dword_2463C = 0;
uint32_t _dword_24640 = 0;
0;
uint8_t _byte_24645 = 0;
uint16_t _word_24646 = 0;
uint16_t _sound_port = 0;
uint8_t _byte_2464A = 0;
uint8_t _byte_2464B = 0;
uint16_t _base_port2 = 0;
uint8_t _dma_channel2 = 0;
uint8_t _irq_number2 = 0;
uint8_t _byte_24650 = 0;
uint8_t _byte_24651 = 0;
uint16_t _sb_base_port = 0;
uint16_t _word_24654 = 0;
uint16_t* off_24656 = &_a070295122642;
uint8_t _dma_chn_mask = 0;
uint8_t _sb_irq_number = 0;
uint8_t _sb_timeconst = 0;
uint16_t _word_2465C = 0;
uint16_t _freq1 = 22050;
uint16_t _fhandle_module = 0;
uint16_t _word_24662 = 0;
uint8_t _byte_24664 = 0;
uint8_t _byte_24665 = 0;
uint8_t _byte_24666 = 0;
uint8_t _byte_24667 = 0;
uint8_t _byte_24668 = 0;
uint8_t _byte_24669 = 0;
uint8_t _byte_2466A = 0;
uint8_t _byte_2466B = 0;
uint8_t _byte_2466C = 0;
uint8_t _byte_2466D = 0;
uint8_t _byte_2466E = 0;
uint8_t _dma_mode = 0;
uint8_t _sb_int_counter = 0;
uint8_t _byte_24671 = 0;
uint8_t _flag_playsetttings = 0;
uint8_t _byte_24673 = 0;
uint8_t _byte_24674 = 0;
uint8_t _byte_24675 = 0;
uint8_t _byte_24676 = 0;
uint8_t _byte_24677 = 0;
uint8_t _byte_24678 = 0;
uint8_t _byte_24679 = 0;
uint8_t _byte_2467A = 0;
uint8_t _byte_2467B = 0;
uint8_t _byte_2467C = 0;
uint8_t _byte_2467D = 0;
uint8_t _byte_2467E = 0;
uint8_t _play_state = 0;
uint8_t _snd_init = 0;
uint8_t _snd_set_flag = 0;
uint8_t _byte_24682 = 0;
uint8_t _byte_24683 = 0;
uint32_t _dword_24684 = 0;
0;
uint16_t _word_2468C = 0;
0;
uint32_t _dword_24694 = 0;
uint16_t _myseg_24698 = 0;
uint8_t _memflg_2469A = 0;
uint8_t _byte_2469B = 0;
uint8_t _byte_2469C = 0;
0;
uint16_t _ems_pageframe = 0;
uint16_t _ems_handle = 0;
uint16_t _ems_log_pagenum = 0;
uint8_t _ems_enabled = 0;
uint8_t _byte_246A5 = 0;
uint16_t _word_246A6 = 0;
uint8_t _byte_246A8 = 0;
uint16_t _word_246A9 = 0;
uint32_t _module_type_text = 538976288;
const char asc_246B0[] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
uint16_t _moduleflag_246D0 = 0;
uint8_t _sndcard_type = 0;
uint16_t _snd_base_port = 0;
uint8_t _irq_number = 0;
uint8_t _dma_channel = 0;
uint8_t _freq_246D7 = 0;
uint8_t _byte_246D8 = 0;
uint8_t _byte_246D9 = 0;
uint16_t _config_word = 0;
uint8_t _byte_246DC = 0;
uint16_t _word_246DE[] = {27392,25856,24384,23040,21696,20480,19328,18240,17216,16256,15360,14496};
uint16_t _table_246F6[] = {8363,8422,8482,8543,8604,8667,8730,8794,7901,7954,8007,8062,8116,8191,8231,8305};
uint16_t _table_24716[] = {32768,36864,40960,43346,45056,46369,47442,48350,49152,49845,50465,51026,51538,52009,52446,52852,53248,53604,53941,54259,54561,54848,55122,55384,55634,55874,56105,56327,56542,56748,56948,57141,57344,57525,57700,57871,58037,58198,58355,58508,58657,58802,58944,59083,59218,59350,59480,59606,59730,59852,59970,60087,60201,60313,60423,60531,60638,60742,60844,60945,61044,61141,61237,61331,61424};
uint16_t _table_24798[] = {32768,38912,40960,43008,45056,46080,47104,48128,49152,49664,50176,50688,51200,51712,52224,52736,53248,53504,53760,54016,54272,54528,54784,55040,55296,55552,55808,56064,56320,56576,56832,57088,57472,57600,57728,57856,57984,58112,58240,58368,58496,58624,58752,58880,59008,59136,59264,59392,59520,59648,59776,59904,60032,60160,60288,60416,60544,60672,60800,60928,61056,61184,61312,61424};
uint16_t _table_24818[] = {32768,38912,40960,43008,45056,46080,47104,48128,49152,49664,50176,50688,51200,51712,52224,52736,53248,53504,53760,54016,54272,54528,54784,55040,55296,55552,55808,56064,56320,56576,56832,57088,57472,57600,57728,57856,57984,58112,58240,58368,58496,58624,58752,58880,59008,59136,59264,59392,59520,59648,59776,59904,60032,60160,60288,60416,60544,60672,60800,60928,61056,61184,61312,61424};
uint8_t _table_24898[] = {30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,27,26,26,26,26,26,26,26,26,26,25,25,25,25,25,25,25,24,24,24,24,23,23,23,23,22,22,21,21,20,20,19,19,19,18,18,17,17,16,16,15,15,14,14,13,13,12,12,11,11,10,10,10,9,9,8,8,8,8,7,7,7,7,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
uint16_t _word_24998[] = {27392,25856,24384,23040,21696,20480,19328,18240,17216,16256,15360,14496,13696,12928,12192,11520,10848,10240,9664,9120,8608,8128,7680,7248,6848,6464,6096,5760,5424,5120,4832,4560,4304,4064,3840,3616,3424,3232,3040,2880,2720,2560,2416,2288,2160,2032,1920,1808,1712,1616,1520,1440,1360,1280,1200,1136,1072,1008,960,896,27200,25664,24224,22880,21568,20384,19232,18144,17120,16160,15264,14400,13600,12832,12112,11440,10784,10192,9616,9072,8560,8080,7632,7200,6800,6416,6064,5712,5392,5088,4800,4544,4288,4048,3824,3600,3408,3216,3024,2864,2704,2544,2400,2272,2144,2016,1904,1808,1696,1600,1504,1424,1344,1264,1200,1136,1072,1008,944,896,27008,25472,24064,22688,21440,20224,19104,18016,17024,16064,15168,14304,13504,12736,12032,11344,10720,10112,9552,9008,8512,8032,7584,7152,6752,6368,6016,5680,5360,5056,4768,4512,4256,4016,3792,3584,3376,3184,3008,2832,2672,2528,2384,2256,2128,2000,1888,1792,1680,1584,1504,1408,1328,1264,1184,1120,1056,992,944,896,26816,25312,23872,22528,21280,20096,18944,17888,16896,15936,15040,14208,13408,12656,11936,11264,10640,10048,9472,8944,8448,7968,7520,7104,6704,6320,5968,5632,5312,5024,4736,4480,4224,3984,3760,3552,3344,3168,2992,2816,2656,2512,2368,2240,2112,2000,1888,1776,1664,1584,1488,1408,1328,1248,1184,1120,1056,992,944,880,26624,25120,23712,22368,21120,19936,18816,17760,16768,15840,14944,14112,13312,12560,11856,11184,10560,9968,9408,8880,8384,7920,7472,7056,6656,6272,5920,5600,5280,4992,4704,4448,4192,3952,3728,3520,3328,3136,2960,2800,2640,2496,2352,2224,2096,1984,1872,1760,1664,1568,1472,1392,1312,1248,1168,1104,1040,992,928,880,26432,24928,23552,22208,20960,19808,18688,17632,16640,15712,14816,13984,13216,12464,11776,11104,10480,9904,9344,8816,8320,7856,7408,6992,6608,6240,5888,5552,5248,4944,4672,4416,4160,3920,3712,3504,3296,3120,2944,2784,2624,2480,2336,2208,2080,1968,1856,1744,1648,1552,1472,1392,1312,1232,1168,1104,1040,976,928,864,26240,24768,23360,22048,20832,19648,18560,17504,16512,15584,14720,13888,13120,12384,11680,11024,10416,9824,9280,8752,8256,7792,7360,6944,6560,6192,5840,5520,5200,4912,4640,4384,4128,3904,3680,3472,3280,3088,2928,2752,2608,2464,2320,2192,2064,1952,1840,1744,1632,1536,1456,1376,1296,1232,1152,1088,1024,976,912,864,26048,24576,23200,21888,20672,19520,18400,17376,16416,15488,14624,13792,13024,12288,11600,10944,10336,9760,9200,8688,8208,7744,7312,6896,6512,6144,5808,5472,5168,4880,4608,4352,4096,3872,3648,3456,3264,3072,2896,2736,2576,2432,2304,2176,2048,1936,1824,1728,1632,1536,1440,1360,1280,1216,1152,1088,1024,960,912,864,29024,27392,25856,24384,23040,21696,20480,19328,18240,17216,16256,15360,14512,13696,12928,12192,11520,10848,10240,9664,9120,8608,8128,7680,7248,6848,6464,6096,5760,5424,5120,4832,4560,4304,4064,3840,3616,3424,3232,3040,2880,2720,2560,2416,2288,2160,2032,1920,1808,1712,1616,1520,1440,1360,1280,1200,1136,1072,1008,960,28800,27200,25664,24224,22880,21600,20352,19232,18144,17120,16160,15264,14400,13600,12832,12112,11440,10800,10176,9616,9072,8560,8080,7632,7200,6800,6416,6064,5712,5392,5088,4800,4544,4288,4048,3808,3600,3392,3200,3024,2864,2704,2544,2400,2272,2144,2016,1904,1792,1696,1600,1504,1424,1344,1264,1200,1136,1072,1008,944,28608,27008,25472,24064,22688,21440,20224,19104,18016,17024,16064,15168,14304,13504,12736,12032,11344,10720,10112,9552,9008,8512,8032,7584,7152,6752,6368,6016,5680,5360,5056,4768,4512,4256,4016,3792,3568,3376,3184,3008,2832,2672,2528,2384,2256,2128,2000,1888,1776,1680,1584,1504,1408,1328,1264,1184,1120,1056,992,944,28384,26816,25312,23872,22528,21280,20096,18944,17888,16896,15936,15040,14192,13408,12656,11936,11264,10640,10048,9472,8944,8448,7968,7520,7104,6704,6320,5968,5632,5312,5024,4736,4480,4224,3984,3760,3552,3344,3168,2992,2816,2656,2512,2368,2240,2112,2000,1888,1776,1664,1584,1488,1408,1328,1248,1184,1120,1056,992,944,28192,26624,25120,23712,22368,21120,19936,18816,17760,16768,15808,14944,14096,13312,12560,11856,11184,10560,9968,9408,8880,8384,7904,7472,7056,6656,6272,5920,5600,5280,4992,4704,4448,4192,3952,3728,3520,3328,3136,2960,2800,2640,2496,2352,2224,2096,1968,1872,1760,1664,1568,1472,1392,1312,1248,1168,1104,1040,976,928,28000,26432,24928,23552,22208,20960,19808,18688,17632,16640,15712,14816,14000,13216,12464,11776,11104,10480,9904,9344,8816,8320,7856,7408,6992,6608,6240,5888,5552,5248,4944,4672,4416,4160,3920,3712,3504,3296,3120,2944,2784,2624,2480,2336,2208,2080,1968,1856,1744,1648,1552,1472,1392,1312,1232,1168,1104,1040,976,928,27776,26240,24768,23360,22048,20832,19648,18560,17504,16512,15584,14720,13888,13120,12384,11680,11024,10416,9824,9280,8752,8256,7792,7360,6944,6560,6192,5840,5520,5200,4912,4640,4384,4128,3904,3680,3472,3280,3088,2928,2752,2608,2464,2320,2192,2064,1952,1840,1728,1632,1536,1456,1376,1296,1232,1152,1088,1024,976,912,27584,26048,24576,23200,21888,20672,19520,18400,17376,16416,15488,14624,13792,13024,12288,11600,10944,10336,9760,9200,8688,8208,7744,7312,6896,6512,6144,5808,5472,5168,4880,4608,4352,4096,3872,3648,3456,3248,3072,2896,2736,2576,2432,2304,2176,2048,1936,1824,1728,1616,1536,1440,1360,1280,1216,1152,1088,1024,960,912};
uint16_t _table_25118[] = {1712,1616,1524,1440,1356,1280,1208,1140,1076,1016,960,906,856,808,762,720,678,640,604,570,538,508,480,453,428,404,381,360,339,320,302,285,269,254,240,226,214,202,190,180,170,160,151,143,135,127,120,113,107,101,95,90,85,80,75,71,67,63,60,56,53,50,47,45,42,40,37,35,33,31,30,28,26,25,23,22,21,20,18,17,16,15,15,14};
uint8_t _table_251C0[] = {0,24,49,74,97,120,141,161,180,197,212,224,235,244,250,253,255,253,250,244,235,224,212,197,180,161,141,120,97,74,49,24};
uint8_t _table_251E0[] = {0,21,32,41,48,55,61,68,73,79,84,89,94,98,103,107,111,115,119,124,127,131,134,138,142,145,149,152,155,159,162,165,169,171,175,179,181,184,187,190,193,195,198,201,204,207,209,212,215,218,221,223,226,229,231,234,236,239,241,244,246,249,251,254,255};
uint8_t _table_25221[] = {0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,85,89,93,97,101,105,109,113,117,121,125,129,133,137,141,145,149,153,157,161,165,170,174,178,182,186,190,194,198,202,206,210,214,218,222,226,230,234,238,242,246,250,255};
uint8_t _table_25261[] = {0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164,168,172,176,180,184,188,192,196,200,204,208,212,216,220,224,228,232,236,240,244,248,255,0};
&_sb16_init;
&_covox_init;
&_stereo_init;
&_adlib_init;
&_pcspeaker_init;
&_midi_init;
&_sb16_on;
&_covox_set;
&_stereo_set;
&_adlib_set;
&_pcspeaker_set;
&_midi_set;
&_sb16_off;
&_covox_sndoff;
&_stereo_sndoff;
&_adlib_sndoff;
&_pcspeaker_sndoff;
&_midi_sndoff;
&_sb16_deinit;
&_covox_clean;
&_stereo_clean;
&_adlib_clean;
&_pcspeaker_clean;
&_midi_clean;
uint16_t* _snd_cards_offs = &_aGravisUltrasoun;
&_aProAudioSpectrum;
&_aWindowsSoundSyst;
&_aSoundBlaster1616;
&_aSoundBlasterPro;
&_aSoundBlaster_0;
&_aCovox_0;
&_aStereoOn1_0;
&_aAdlibSoundcard_0;
&_aPcHonker_0;
&_aGeneralMidi_0;
&_sb16_txt;
&_sb16_txt;
&_sb16_txt;
&_sb16_txt;
&_sb16_txt;
&_covox_txt;
&_covox_txt;
&_pcspeaker_text;
&_pcspeaker_text;
&_midi_txt;
uint16_t* off_25326 = &_inr_module;
0;
0;
16;
const char _aInertiaModule_1[] = { 'I','n','e','r','t','i','a',' ','M','o','d','u','l','e',':',' '};
&_mod_mk_module;
56;
4;
4;
const char _aM_k_[] = { 'M','.','K','.'};
&_mod_mk_module;
56;
4;
4;
const char _a_m_k[] = { '.','M','.','K'};
&_mod_mk_module;
56;
4;
4;
const char _aMK[] = { 'M','&','K','!'};
&_mod_mk_module;
56;
4;
4;
const char _aMK_0[] = { 'M','!','K','!'};
&_mod_mk_module;
56;
4;
4;
const char _aGsft[] = { 'G','S','F','T'};
&_mod_mk_module;
56;
4;
4;
const char _aE_g_[] = { 'E','.','G','.'};
&_mod_mk_module;
56;
4;
4;
const char _aFlt4[] = { 'F','L','T','4'};
&_mod_flt8_module;
56;
4;
4;
const char _aFlt8[] = { 'F','L','T','8'};
&_mod_cd81_module;
56;
4;
4;
const char _aCd81[] = { 'C','D','8','1'};
&_mod_cd81_module;
56;
4;
4;
const char _aOcta[] = { 'O','C','T','A'};
&_mod_chn_module;
57;
4;
3;
const char _aChn[] = { 'C','H','N'};
&_mod_ch_module;
58;
4;
2;
const char _aCh[] = { 'C','H'};
&_mod_tdz_module;
56;
4;
3;
const char _aTdz[] = { 'T','D','Z'};
&_stm_module;
20;
0;
8;
const char _aScream[] = { '!','S','c','r','e','a','m','!'};
&__2stm_module;
20;
0;
8;
const char _aBmod2stm[] = { 'B','M','O','D','2','S','T','M'};
&_s3m_module;
44;
0;
4;
const char _aScrm[] = { 'S','C','R','M'};
&_mtm_module;
0;
0;
3;
const char _aMtm[] = { 'M','T','M'};
&_psm_module;
0;
0;
4;
const char _aPsm[] = { 'P','S','M','�'};
&_far_module;
0;
0;
4;
const char _aFar[] = { 'F','A','R','�'};
&_ult_module;
0;
0;
12;
const char _aMas_utrack_v[] = { 'M','A','S','_','U','T','r','a','c','k','_','V'};
&__669_module;
0;
0;
2;
const char _aIf[] = { 'i','f'};
&_e669_module;
0;
0;
2;
const char _aJn[] = { 'J','N'};
const char * const _eModuleNotFound = "Module not found\r\n";
const char * const _aNotEnoughMemory = "Not enough Memory available\r\n";
const char * const _aNotEnoughDramOn = "Not enough DRAM on UltraSound\r\n";
const char _aSomeFunctionsOf[] = { 'S','o','m','e',' ','f','u','n','c','t','i','o','n','s',' ','o','f',' ','t','h','e',' ','U','l','t','r','a','S','o','u','n','d',' ','d','o',' ','n','o','t',' ','w','o','r','k','!','\r','\n'};
10;
'P','r','o','b','a','b','l','y',' ','t','h','e',' ','A','T','-','B','U','S',' ','C','l','o','c','k',' ','S','p','e','e','d',' ','i','s',' ','t','o','o',' ','h','i','g','h','.','\r','\n'};
"Try changing the AT-BUS Clock in the CMOS Setup.\r\n";
const char * const _aCouldNotFindThe = "Could not find the ULTRASND environment string\r\n";
const char _aCouldNotFindT_0[] = { 'C','o','u','l','d',' ','n','o','t',' ','f','i','n','d',' ','t','h','e',' ','G','r','a','v','i','s',' ','U','l','t','r','a','S','o','u','n','d',' ','a','t',' ','t','h','e',' ','s','p','e','c','i','f','i','e','d',' ','p','o','r','t',' ','a','d','d','r','e','s'};
"s\r\n";
const char * const _aThisProgramRequ = "This program requires the soundcards device driver.\r\n";
const char * const _aErrorSoundcardN = "Error: Soundcard not found!\r\n";
const char * const _aErrorCouldNotFi = "Error: Could not find IRQ/DMA!\r\n";
const char * const _aErrorCouldNot_0 = "Error: Could not find IRQ!\r\n";
const char * const _aErrorCouldNot_1 = "Error: Could not find DMA!\r\n";
const char * const _aDeviceNotIniti = "Device not initialised!";
const char * const _aAt = " at";
const char * const _aBasePort = " base port ";
const char * const _aMixedAt = ", mixed at ";
const char * const _aKhz = "kHz";
const char * const _aGravisUltrasoun = "Gravis UltraSound";
uint8_t _gravis_txt = 1;
0;
&_aGravisUltrasoun;
1;
0;
&_aAt;
1;
0;
&_aBasePort;
11;
0;
&_snd_base_port;
const char _aHGf1Irq[] = { 'h',',',' ','G','F','1','-','I','R','Q',' '};
4;
0;
&_irq_number;
const char _aDramDma[] = { ',',' ','D','R','A','M','-','D','M','A',' '};
4;
0;
&_dma_channel;
0;
const char * const _aProAudioSpectrum = "Pro Audio Spectrum 16";
const char * const _aWindowsSoundSyst = "Windows Sound System";
const char * const _aSoundBlaster1616 = "Sound Blaster 16/16ASP";
const char * const _aSoundBlasterPro = "Sound Blaster Pro";
const char * const _aSoundBlaster_0 = "Sound Blaster";
uint8_t _sb16_txt = 2;
0;
&_sndcard_type;
&_snd_cards_offs;
1;
0;
&_aAt;
1;
0;
&_aBasePort;
11;
0;
&_snd_base_port;
const char _aHIrq[] = { 'h',',',' ','I','R','Q',' '};
4;
0;
&_irq_number;
const char _aDma[] = { ',',' ','D','M','A',' '};
4;
0;
&_dma_channel;
1;
0;
&_aMixedAt;
4;
0;
&_freq_246D7;
1;
0;
&_aKhz;
0;
const char * const _aCovox_0 = "Covox";
const char * const _aStereoOn1_0 = "Stereo-On-1";
uint8_t _covox_txt = 2;
0;
&_sndcard_type;
&_snd_cards_offs;
1;
0;
&_aAt;
1;
0;
&_aBasePort;
11;
0;
&_snd_base_port;
'h'};
1;
0;
&_aMixedAt;
4;
0;
&_freq_246D7;
1;
0;
&_aKhz;
0;
const char * const _aAdlibSoundcard_0 = "Adlib SoundCard";
const char * const _aPcHonker_0 = "PC Honker";
uint8_t _pcspeaker_text = 2;
0;
&_sndcard_type;
&_snd_cards_offs;
1;
0;
&_aMixedAt;
4;
0;
&_freq_246D7;
1;
0;
&_aKhz;
0;
const char * const _aGeneralMidi_0 = "General MIDI";
uint8_t _midi_txt = 2;
0;
&_sndcard_type;
&_snd_cards_offs;
1;
0;
&_aAt;
1;
0;
&_aBasePort;
11;
0;
&_snd_base_port;
'h'};
0;
0;
0;
uint32_t _dword_257A0 = 0;
uint16_t _word_257A4 = 0;
const char * const _aInertiaModule = "Inertia Module: ";
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
13;
10;
26;
uint8_t unk_257D9 = 0;
uint8_t _byte_257DA = 16;
uint8_t _byte_257DB = 0;
uint8_t _byte_257DC = 0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
uint16_t _word_257E6 = 4;
uint16_t _word_257E8 = 0;
uint16_t _word_257EA = 0;
uint16_t _word_257EC = 0;
uint16_t _word_257EE = 0;
uint16_t _word_257F0 = 0;
uint8_t _byte_257F2 = 0;
uint8_t _byte_257F3 = 0;
0;
0;
const char * const _aInertiaModule_0 = "Inertia Module: ";
0;
13;
10;
26;
0;
16;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
4;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
const char _aInertiaSample[] = { 'I','n','e','r','t','i','a',' ','S','a','m','p','l','e',':',' '};
const char asc_25856[] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\r','\n','26'};
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
uint32_t _dword_25886 = 0;
16;
uint8_t _byte_2588B = 0;
uint8_t _byte_2588C = 0;
uint8_t _byte_2588D = 0;
uint16_t _word_2588E = 0;
0;
0;
uint32_t _dword_25892 = 0;
uint32_t _dword_25896 = 0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
uint8_t unk_258A6 = 73;
110;
101;
114;
116;
105;
97;
32;
83;
97;
109;
112;
108;
101;
58;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
32;
13;
10;
26;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
16;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
uint8_t _volume_25908 = 0;
uint8_t _myout = 0;
uint32_t _dword_27BC8 = 0;
uint32_t _dword_27BCC = 0;
0;
uint16_t _segs_table = 0;
uint16_t _myseg_size = 0;
uint8_t _byte_27FE8 = 0;
uint8_t _byte_280E7 = 0;
uint8_t _byte_280E8 = 0;
uint8_t _byte_281E8 = 0;
uint8_t _byte_282E8 = 0;
uint8_t _vlm_byte_table = 0;
uint32_t _chrin = 0;
uint32_t _myin = 0;
0;
0;
0;
0;
0;
uint16_t _word_30515 = 0;
uint8_t _myin_0 = 0;
uint32_t _dword_30518 = 0;
0;
0;
0;
0;
uint16_t _word_30520 = 0;
uint8_t _byte_30522 = 0;
uint8_t _byte_30523 = 0;
uint16_t _word_30524 = 0;
uint8_t _byte_30526 = 0;
0;
uint8_t unk_30528 = 0;
uint8_t _byte_30529 = 0;
uint16_t _word_3052A = 0;
uint16_t _word_3052C = 0;
0;
0;
0;
0;
uint16_t _word_30532 = 0;
0;
0;
0;
uint8_t _byte_30537 = 0;
uint8_t _my_in = 0;
uint8_t _byte_30539 = 0;
uint8_t _byte_3053A = 0;
uint8_t _byte_3053B = 0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
uint8_t _byte_30548 = 0;
0;
uint8_t unk_3054A = 0;
uint8_t _byte_3054B = 0;
uint8_t _byte_3054C = 0;
0;
0;
0;
uint8_t _byte_30550 = 0;
0;
uint16_t _word_30552 = 0;
uint16_t _word_30554 = 0;
uint16_t _word_30556 = 0;
0;
0;
uint32_t _dword_3055A = 0;
0;
0;
0;
0;
uint16_t _word_30562 = 0;
uint16_t _word_30564 = 0;
uint32_t _dword_30566 = 0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
0;
uint8_t _byte_30576 = 0;
uint8_t _byte_30577 = 0;
0;
uint8_t _byte_30579 = 0;
uint8_t _byte_3059A = 0;
uint8_t _byte_305F9 = 0;
uint8_t _byte_30639 = 0;
uint8_t _byte_3063A = 0;
uint16_t _word_3063B = 0;
uint32_t _dword_3063D = 0;
uint8_t _byte_30641 = 0;
uint8_t _byte_30669 = 0;
uint8_t _byte_3066A = 0;
uint8_t _byte_3066B = 0;
uint8_t _byte_30679 = 0;
uint8_t _byte_306DE = 0;
uint8_t _byte_308BE = 0;
uint8_t _byte_30908 = 0;
uint8_t _byte_30940 = 0;
uint8_t unk_30941 = 0;
0;
uint8_t _byte_30943 = 0;
0;
uint16_t _word_31508 = 0;
uint8_t _byte_3150A = 0;
0;
uint8_t _byte_3150C = 0;
uint8_t _byte_31D08 = 0;
uint8_t _byte_33508 = 0;
uint8_t _byte_34510 = 0 */

	static const uint8_t src[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x09d0: . .... ....
		0x00, 0x00, 0x18, 0x0b, 0x0d, 0x0a, 0x02, 0x01, 0x03, 0x04, 0x07, 0x00, 0xff, 0x10, 0x0b, 0x0d, 
		//0x09e0: .... .... .... ....
		0x15, 0x12, 0x11, 0x13, 0x14, 0x1b, 0x1d, 0x17, 0x16, 0xff, 0xff, 0x09, 0xff, 0x1c, 0x07, 0x0e, 
		//0x09f0: .... .... .... ....
		0x0f, 0xff, 0xff, 0xff, 0x08, 0xff, 0x00, 0x03, 0x05, 0x04, 0x07, 0xff, 0xff, 0xff, 0x08, 0xff, 
		//0x0a00: .... .... .... ....
		0xff, 0x06, 0x0c, 0x0d, 0xff, 0xff, 0x00, 0x02, 0x01, 0x03, 0x02, 0x04, 0x03, 0x05, 0x00, 0x09, 
		//0x0a10: .... .... .... ....
		0x12, 0x1b, 0x24, 0x2d, 0x36, 0x40, 0x40, 0x4a, 0x53, 0x5c, 0x65, 0x6e, 0x77, 0x80, 0x8c, 0x32, 
		//0x0a20: ..$- 6@@J S.en w..2
		0x19, 0x0f, 0x0a, 0x07, 0x06, 0x04, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0xff, 0x80, 
		//0x0a30: .... .... .... ....
		0x40, 0x2a, 0x20, 0x19, 0x15, 0x12, 0x10, 0x0e, 0x0c, 0x0b, 0x0a, 0x09, 0x09, 0x08, 0x87, 0xdb, 
		//0x0a40: @* . .... .... ....
		0x89, 0x15, 0x01, 0x00, 0xd7, 0x19, 0x0f, 0x00, 0x40, 0x1f, 0x00, 0x00, 0x80, 0x25, 0x0e, 0x00, 
		//0x0a50: .... .... @... .%..
		0x11, 0x2b, 0x03, 0x00, 0x80, 0x3e, 0x02, 0x00, 0xd4, 0x49, 0x05, 0x00, 0x22, 0x56, 0x07, 0x00, 
		//0x0a60: .+.. .>.. .I.. "V..
		0x25, 0x6b, 0x04, 0x00, 0x00, 0x7d, 0x06, 0x00, 0x33, 0x81, 0x0d, 0x00, 0xa8, 0x93, 0x09, 0x00, 
		//0x0a70: %k.. .}.. 3... ....
		0x44, 0xac, 0x0b, 0x00, 0x80, 0xbb, 0x0c, 0x00, 0xba, 0x36, 0x05, 0xba, 0x2f, 0x02, 0xba, 0x2e, 
		//0x0a80: D... .... .6.. /...
		0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xba, 0x00, 0x10, 
		//0x0a90: .... .... .... ....
		0xa0, 0x34, 0x12, 0xba, 0x78, 0x03, 0xba, 0x7a, 0x03, 0xa1, 0x34, 0x12, 0xa0, 0x34, 0x12, 0xbb, 
		//0x0aa0: .4.. x..z ..4. .4..
		0x00, 0x10, 0x8a, 0x1e, 0x34, 0x12, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 
		//0x0ab0: .... 4.@@ @@@@ @@@@
		0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x3e, 0x3e, 0x3e, 
		//0x0ac0: ???? ???? ???? >>>>
		0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3c, 
		//0x0ad0: >>>> >>== ==== ===<
		0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 
		//0x0ae0: <<<< <<<< <;;; ;;;;
		0x3b, 0x3b, 0x3b, 0x3a, 0x3a, 0x3a, 0x3a, 0x3a, 0x3a, 0x3a, 0x3a, 0x3a, 0x3a, 0x39, 0x39, 0x39, 
		//0x0af0: ;;;: :::: :::: :999
		0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x37, 
		//0x0b00: 9999 9998 8888 8887
		0x37, 0x37, 0x37, 0x37, 0x36, 0x36, 0x36, 0x36, 0x35, 0x35, 0x35, 0x35, 0x34, 0x34, 0x34, 0x33, 
		//0x0b10: 7777 6666 5555 4443
		0x33, 0x32, 0x32, 0x31, 0x31, 0x30, 0x30, 0x2f, 0x2e, 0x2d, 0x2c, 0x2b, 0x2a, 0x29, 0x28, 0x27, 
		//0x0b20: 3221 100/ .-,+ *)('
		0x26, 0x25, 0x24, 0x23, 0x22, 0x21, 0x20, 0x1f, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x18, 0x17, 
		//0x0b30: &%$# "! . .... ....
		0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x11, 0x10, 0x10, 0x0f, 0x0f, 0x0e, 0x0e, 0x0d, 0x0d, 0x0d, 
		//0x0b40: .... .... .... ....
		0x0c, 0x0c, 0x0c, 0x0c, 0x0b, 0x0b, 0x0b, 0x0b, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x09, 0x09, 0x09, 
		//0x0b50: .... .... .... ....
		0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 
		//0x0b60: .... .... .... ....
		0x08, 0x08, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
		//0x0b70: .... .... .... ....
		0x06, 0x06, 0x06, 0x06, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x04, 0x04, 
		//0x0b80: .... .... .... ....
		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
		//0x0b90: .... .... .... ....
		0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 
		//0x0ba0: .... .... .... ....
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 
		//0x0bb0: .... .... .... ....
		0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 
		//0x0bc0: .... .... .... ....
		0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 
		//0x0bd0: .... .... .... ....
		0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 
		//0x0be0: .... .... .... ....
		0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 
		//0x0bf0: .... .... .... ....
		0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 
		//0x0c00: .... .... .... ....
		0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 
		//0x0c10: .... .... .... ....
		0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 
		//0x0c20: .... .... .... ....
		0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 
		//0x0c30: .... .... .... ....
		0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 
		//0x0c40: .... .... .... ....
		0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 
		//0x0c50: .... .... .... ....
		0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 0x80, 0xc1, 0x00, 
		//0x0c60: .... .... .... ....
		0x00, 0x00, 0x01, 0x03, 0x00, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 0x06, 0x00, 0x00, 0x07, 
		//0x0c70: .... .... .... ....
		0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x04, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0c80: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0c90: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0ca0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0cb0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0cc0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0cd0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0ce0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0cf0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0d00: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0d10: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0d20: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0d30: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0d40: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0d50: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0d60: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0d70: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0d80: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0d90: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0da0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0db0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0dc0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0dd0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0de0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0df0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0e00: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0e10: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0e20: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0e30: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0e40: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0e50: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0e60: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0e70: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0e80: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0e90: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0ea0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0eb0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0ec0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0ed0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0ee0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0ef0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0f00: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0f10: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0f20: .... .... .... ....
		0x00, 0x00, 0x00, 0x0d, 0x0a, 0x00, 0x0d, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0f30: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0f40: .... .... .... ....
		0x00, 0x00, 0x0d, 0x0a, 0x0a, 0x00, 0x0d, 0x0a, 0x0a, 0x00, 0x0d, 0x0a, 0x00, 0x0d, 0x0a, 0x00, 
		//0x0f50: .... .... .... ....
		0x0d, 0x0a, 0x00, 0x0d, 0x0a, 0x00, 0x27, 0x00, 0x0d, 0x0a, 0x00, 0x0d, 0x0a, 0x00, 0x0d, 0x0a, 
		//0x0f60: .... ..'. .... ....
		0x00, 0x0d, 0x0a, 0x00, 0x0d, 0x0a, 0x00, 0x0d, 0x0a, 0x00, 0x0d, 0x0a, 0x00, 0x0d, 0x0a, 0x00, 
		//0x0f70: .... .... .... ....
		0x0d, 0x0a, 0x00, 0x0d, 0x0a, 0x00, 0x0d, 0x00, 0x0d, 0x0a, 0x0a, 0x00, 0x0d, 0x0a, 0x00, 0x00, 
		//0x0f80: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0f90: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0fa0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x0fb0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x52, 0x01, 0x7f, 0x00, 0x27, 0x00, 0x00, 
		//0x0fc0: .... .... .R.. .'..
		0x01, 0xf4, 0x01, 0x00, 0x00, 0x02, 0x78, 0x01, 0xaa, 0x01, 0x00, 0x01, 0x46, 0x01, 0x00, 0x00, 
		//0x0fd0: .... ..x. .... F...
		0x00, 0x0a, 0x00, 0x7f, 0x00, 0x01, 0xaa, 0x00, 0x02, 0x7e, 0x00, 0x02, 0x7f, 0x00, 0x01, 0x4a, 
		//0x0fe0: .... .... .~.. ...J
		0x01, 0x02, 0x7e, 0x00, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x01, 0xea, 0x01, 0x00, 0x01, 0x8a, 0x02, 
		//0x0ff0: ..~. .... ~... ....
		0x00, 0x01, 0x2a, 0x03, 0x00, 0x01, 0xca, 0x03, 0x00, 0x01, 0x6a, 0x04, 0x00, 0x01, 0x86, 0x04, 
		//0x1000: ..*. .... ..j. ....
		0x00, 0x02, 0x78, 0x01, 0xa4, 0x04, 0x00, 0x01, 0xf8, 0x00, 0x02, 0x78, 0xfe, 0x02, 0x7e, 0x00, 
		//0x1010: ..x. .... ...x ..~.
		0x01, 0x98, 0x01, 0x02, 0x78, 0xfe, 0x02, 0x7e, 0x00, 0x01, 0xce, 0x01, 0x02, 0x78, 0x00, 0x01, 
		//0x1020: .... x..~ .... .x..
		0x38, 0x02, 0x02, 0x78, 0xfe, 0x02, 0x7e, 0x00, 0x01, 0x6e, 0x02, 0x02, 0x78, 0x00, 0x02, 0x7e, 
		//0x1030: 8..x ..~. .n.. x..~
		0x01, 0xd8, 0x02, 0x02, 0x78, 0xfe, 0x02, 0x7e, 0x00, 0x01, 0x0e, 0x03, 0x02, 0x78, 0x00, 0x02, 
		//0x1040: .... x..~ .... .x..
		0x7e, 0x01, 0x78, 0x03, 0x02, 0x78, 0xfe, 0x02, 0x7e, 0x00, 0x01, 0xae, 0x03, 0x02, 0x78, 0x00, 
		//0x1050: ~.x. .x.. ~... ..x.
		0x02, 0x7e, 0x01, 0x18, 0x04, 0x00, 0x01, 0x4e, 0x04, 0x02, 0x78, 0x00, 0x02, 0x7e, 0x01, 0xb8, 
		//0x1060: .~.. ...N ..x. .~..
		0x04, 0x00, 0x01, 0xee, 0x04, 0x02, 0x78, 0x00, 0x00, 0xf8, 0x03, 0x7f, 0x00, 0x01, 0x68, 0x04, 
		//0x1070: .... ..x. .... ..h.
		0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 0x01, 0x08, 0x05, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 0x01, 
		//0x1080: .... ~... .... .~..
		0xa8, 0x05, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 0x01, 0x48, 0x06, 0x02, 0x7f, 0x00, 0x02, 0x7e, 
		//0x1090: .... ..~. .H.. ...~
		0x00, 0x01, 0xe8, 0x06, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 0x01, 0x88, 0x07, 0x02, 0x7f, 0x00, 
		//0x10a0: .... .... ~... ....
		0x02, 0x7e, 0x00, 0x01, 0x28, 0x08, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 0x01, 0xc8, 0x08, 0x02, 
		//0x10b0: .~.. (... ..~. ....
		0x7f, 0x00, 0x02, 0x7e, 0x00, 0x01, 0x68, 0x09, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 0x01, 0xc4, 
		//0x10c0: ...~ ..h. .... ~...
		0x04, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 0x01, 0x6e, 0x05, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 
		//0x10d0: .... .~.. n... ..~.
		0x01, 0x00, 0x06, 0x02, 0x7f, 0x00, 0x1a, 0x00, 0x18, 0x02, 0x7e, 0x00, 0x01, 0xa0, 0x06, 0x02, 
		//0x10e0: .... .... ..~. ....
		0x7f, 0x00, 0x1b, 0x00, 0x19, 0x02, 0x7e, 0x00, 0x01, 0x44, 0x07, 0x02, 0x7f, 0x00, 0x02, 0x7e, 
		//0x10f0: .... ..~. .D.. ...~
		0x00, 0x01, 0xe0, 0x07, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 0x01, 0x8a, 0x08, 0x02, 0x7f, 0x00, 
		//0x1100: .... .... ~... ....
		0x02, 0x7e, 0x00, 0x01, 0x2e, 0x09, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 0x01, 0xce, 0x09, 0x02, 
		//0x1110: .~.. .... ..~. ....
		0x7f, 0x00, 0x02, 0x7e, 0x00, 0x00, 0xc6, 0x03, 0x7e, 0x00, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 
		//0x1120: ...~ .... ~... ..~.
		0x02, 0x7f, 0x00, 0x02, 0x7e, 0x01, 0x0c, 0x05, 0x00, 0x00, 0x01, 0xac, 0x05, 0x00, 0x02, 0x7f, 
		//0x1130: .... ~... .... ....
		0x00, 0x02, 0x7e, 0x01, 0x4c, 0x06, 0x00, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x01, 0x26, 0x08, 0x00, 
		//0x1140: ..~. L... ...~ .&..
		0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 0x01, 0xc6, 0x08, 0x00, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 
		//0x1150: .... ~... .... ..~.
		0x01, 0x66, 0x09, 0x00, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x01, 0x06, 0x0a, 0x00, 0x02, 0x7f, 0x00, 
		//0x1160: .f.. .... ~... ....
		0x00, 0xf2, 0x03, 0x7e, 0x00, 0x01, 0x2a, 0x05, 0x00, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 0x02, 
		//0x1170: ...~ ..*. .... .~..
		0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1180: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9e, 0x04, 0x7b, 0x00, 0x01, 0xf2, 0x06, 0x02, 
		//0x1190: .... .... ..{. ....
		0x7e, 0x00, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 0x02, 0x7f, 
		//0x11a0: ~... ..~. .... ~...
		0x00, 0x02, 0x7e, 0x00, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 0x02, 0x7f, 0x18, 0x02, 0x7e, 0x00, 
		//0x11b0: ..~. .... ~... ..~.
		0x02, 0x7f, 0x19, 0x02, 0x7e, 0x00, 0x01, 0x92, 0x07, 0x00, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x00, 
		//0x11c0: .... ~... .... ..~.
		0x01, 0xd2, 0x08, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x01, 0xe6, 0x08, 0x00, 0x01, 0x72, 0x09, 0x02, 
		//0x11d0: .... ...~ .... .r..
		0x7f, 0x00, 0x02, 0x7e, 0x01, 0x86, 0x09, 0x00, 0x01, 0x12, 0x0a, 0x02, 0x7f, 0x00, 0x02, 0x7e, 
		//0x11e0: ...~ .... .... ...~
		0x01, 0x26, 0x0a, 0x00, 0x01, 0xb2, 0x0a, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x01, 0xc6, 0x0a, 0x00, 
		//0x11f0: .&.. .... ...~ ....
		0x01, 0x52, 0x0b, 0x02, 0x7f, 0x00, 0x02, 0x7e, 0x01, 0x66, 0x0b, 0x00, 0x01, 0xf2, 0x0b, 0x02, 
		//0x1200: .R.. ...~ .f.. ....
		0x7f, 0x00, 0x02, 0x7e, 0x01, 0x06, 0x0c, 0x00, 0x01, 0x92, 0x0c, 0x02, 0x7f, 0x00, 0x02, 0x7e, 
		//0x1210: ...~ .... .... ...~
		0x01, 0xa6, 0x0c, 0x00, 0x01, 0x86, 0x0e, 0x02, 0x7e, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x00, 
		//0x1220: .... .... ~...    .
		0x00, 0x00, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 
		//0x1230: ..    ... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1240: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1250: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1260: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1270: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1280: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1290: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x12a0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x0a, 0x00, 0x00, 0x0d, 0x0a, 0x00, 0x00, 0x0d, 0x0a, 
		//0x12b0: .... .... .... ....
		0x00, 0x00, 0x0d, 0x0a, 0x00, 0x0d, 0x0a, 0x0a, 0x00, 0x00, 0x0d, 0x0a, 0x00, 0x0d, 0x0a, 0x0a, 
		//0x12c0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x12d0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x12e0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x12f0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x49, 0x4e, 0x52, 0x10, 0x04, 0x03, 0xff, 0xff, 0xff, 0xff, 0x2c, 0xff, 
		//0x1300: .... INR. .... ..,.
		0x14, 0x8b, 0x21, 0x4b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1310: ..!K .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1320: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1330: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1340: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1350: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1360: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1370: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x03, 
		//0x1380: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1390: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x13a0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x13b0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x13c0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x13d0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x13e0: .... .... .... ....
		0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 
		//0x13f0: .... .... .... ....
		0x0e, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x06, 0x04, 0x05, 0x0d, 0x07, 0x08, 0x15, 0x0a, 
		//0x1400: .... .... .... ....
		0x0b, 0x1b, 0x0d, 0x0e, 0x21, 0x10, 0x11, 0x2a, 0x13, 0x14, 0x31, 0x00, 0x2a, 0x2a, 0x00, 0x2d, 
		//0x1410: .... !..* ..1. **.-
		0x2d, 0x00, 0x30, 0x30, 0x00, 0x33, 0x33, 0x00, 0x36, 0x36, 0x00, 0x39, 0x39, 0x00, 0x3c, 0x3c, 
		//0x1420: -.00 .33. 66.9 9.<<
		0x00, 0x3f, 0x3f, 0x00, 0x00, 0x6a, 0x0a, 0x00, 0x00, 0x6d, 0x0a, 0x00, 0x00, 0x6d, 0x0a, 0x00, 
		//0x1430: .??. .j.. .m.. .m..
		0x00, 0x6d, 0x0a, 0x0d, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xff, 
		//0x1440: .m..              .
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1450: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1460: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1470: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1480: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1490: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x14a0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x14b0: .... .... .... ....
		0x01, 0x00, 0x04, 0xb5, 0x00, 0x00, 0xf7, 0x61, 0x00, 0x00, 0xf1, 0x31, 0x00, 0x00, 0x17, 0x19, 
		//0x14c0: .... ...a ...1 ....
		0x00, 0x00, 0x8f, 0x0c, 0x00, 0x00, 0x48, 0x06, 0x00, 0x00, 0x24, 0x03, 0x00, 0x00, 0x92, 0x01, 
		//0x14d0: .... ..H. ..$. ....
		0x00, 0x00, 0xc9, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x19, 0x00, 
		//0x14e0: .... ..d. ..2. ....
		0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x04, 0xb5, 
		//0x14f0: .... .... .... ....
		0x00, 0x00, 0x83, 0xec, 0x00, 0x00, 0x14, 0xfb, 0x00, 0x00, 0xc4, 0xfe, 0x00, 0x00, 0xb1, 0xff, 
		//0x1500: .... .... .... ....
		0x00, 0x00, 0xec, 0xff, 0x00, 0x00, 0xfb, 0xff, 0x00, 0x00, 0xfe, 0xff, 0x00, 0x00, 0xff, 0xff, 
		//0x1510: .... .... .... ....
		0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
		//0x1520: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1530: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1540: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1550: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1560: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x64, 0x00, 
		//0x1570: .... .... .... ..d.
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1580: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1590: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x15a0: .... .... . .. ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x15b0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x15c0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x56, 0x00, 
		//0x15d0: .... .... .... ."V.
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x15e0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x15f0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1600: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1610: .... .... .... ....
		0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x1620: ..     .. .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x6b, 0x00, 0x65, 0x40, 0x5f, 0x00, 0x5a, 0xc0, 0x54, 0x00, 0x50, 
		//0x1630: .... .k.e @_.Z .T.P
		0x80, 0x4b, 0x40, 0x47, 0x40, 0x43, 0x80, 0x3f, 0x00, 0x3c, 0xa0, 0x38, 0xab, 0x20, 0xe6, 0x20, 
		//0x1640: .K@G @C.? .<.8 . . 
		0x22, 0x21, 0x5f, 0x21, 0x9c, 0x21, 0xdb, 0x21, 0x1a, 0x22, 0x5a, 0x22, 0xdd, 0x1e, 0x12, 0x1f, 
		//0x1650: "!_! .!.! ."Z" ....
		0x47, 0x1f, 0x7e, 0x1f, 0xb4, 0x1f, 0xff, 0x1f, 0x27, 0x20, 0x71, 0x20, 0x00, 0x80, 0x00, 0x90, 
		//0x1660: G.~. .... ' q  ....
		0x00, 0xa0, 0x52, 0xa9, 0x00, 0xb0, 0x21, 0xb5, 0x52, 0xb9, 0xde, 0xbc, 0x00, 0xc0, 0xb5, 0xc2, 
		//0x1670: ..R. ..!. R... ....
		0x21, 0xc5, 0x52, 0xc7, 0x52, 0xc9, 0x29, 0xcb, 0xde, 0xcc, 0x74, 0xce, 0x00, 0xd0, 0x64, 0xd1, 
		//0x1680: !.R. R.). ..t. ..d.
		0xb5, 0xd2, 0xf3, 0xd3, 0x21, 0xd5, 0x40, 0xd6, 0x52, 0xd7, 0x58, 0xd8, 0x52, 0xd9, 0x42, 0xda, 
		//0x1690: .... !.@. R.X. R.B.
		0x29, 0xdb, 0x07, 0xdc, 0xde, 0xdc, 0xac, 0xdd, 0x74, 0xde, 0x35, 0xdf, 0x00, 0xe0, 0xb5, 0xe0, 
		//0x16a0: )... .... t.5. ....
		0x64, 0xe1, 0x0f, 0xe2, 0xb5, 0xe2, 0x56, 0xe3, 0xf3, 0xe3, 0x8c, 0xe4, 0x21, 0xe5, 0xb2, 0xe5, 
		//0x16b0: d... ..V. .... !...
		0x40, 0xe6, 0xcb, 0xe6, 0x52, 0xe7, 0xd6, 0xe7, 0x58, 0xe8, 0xd6, 0xe8, 0x52, 0xe9, 0xcc, 0xe9, 
		//0x16c0: @... R... X... R...
		0x42, 0xea, 0xb7, 0xea, 0x29, 0xeb, 0x99, 0xeb, 0x07, 0xec, 0x73, 0xec, 0xde, 0xec, 0x46, 0xed, 
		//0x16d0: B... )... ..s. ..F.
		0xac, 0xed, 0x11, 0xee, 0x74, 0xee, 0xd5, 0xee, 0x35, 0xef, 0x93, 0xef, 0xf0, 0xef, 0x00, 0x80, 
		//0x16e0: .... t... 5... ....
		0x00, 0x98, 0x00, 0xa0, 0x00, 0xa8, 0x00, 0xb0, 0x00, 0xb4, 0x00, 0xb8, 0x00, 0xbc, 0x00, 0xc0, 
		//0x16f0: .... .... .... ....
		0x00, 0xc2, 0x00, 0xc4, 0x00, 0xc6, 0x00, 0xc8, 0x00, 0xca, 0x00, 0xcc, 0x00, 0xce, 0x00, 0xd0, 
		//0x1700: .... .... .... ....
		0x00, 0xd1, 0x00, 0xd2, 0x00, 0xd3, 0x00, 0xd4, 0x00, 0xd5, 0x00, 0xd6, 0x00, 0xd7, 0x00, 0xd8, 
		//0x1710: .... .... .... ....
		0x00, 0xd9, 0x00, 0xda, 0x00, 0xdb, 0x00, 0xdc, 0x00, 0xdd, 0x00, 0xde, 0x00, 0xdf, 0x80, 0xe0, 
		//0x1720: .... .... .... ....
		0x00, 0xe1, 0x80, 0xe1, 0x00, 0xe2, 0x80, 0xe2, 0x00, 0xe3, 0x80, 0xe3, 0x00, 0xe4, 0x80, 0xe4, 
		//0x1730: .... .... .... ....
		0x00, 0xe5, 0x80, 0xe5, 0x00, 0xe6, 0x80, 0xe6, 0x00, 0xe7, 0x80, 0xe7, 0x00, 0xe8, 0x80, 0xe8, 
		//0x1740: .... .... .... ....
		0x00, 0xe9, 0x80, 0xe9, 0x00, 0xea, 0x80, 0xea, 0x00, 0xeb, 0x80, 0xeb, 0x00, 0xec, 0x80, 0xec, 
		//0x1750: .... .... .... ....
		0x00, 0xed, 0x80, 0xed, 0x00, 0xee, 0x80, 0xee, 0x00, 0xef, 0x80, 0xef, 0xf0, 0xef, 0x00, 0x80, 
		//0x1760: .... .... .... ....
		0x00, 0x98, 0x00, 0xa0, 0x00, 0xa8, 0x00, 0xb0, 0x00, 0xb4, 0x00, 0xb8, 0x00, 0xbc, 0x00, 0xc0, 
		//0x1770: .... .... .... ....
		0x00, 0xc2, 0x00, 0xc4, 0x00, 0xc6, 0x00, 0xc8, 0x00, 0xca, 0x00, 0xcc, 0x00, 0xce, 0x00, 0xd0, 
		//0x1780: .... .... .... ....
		0x00, 0xd1, 0x00, 0xd2, 0x00, 0xd3, 0x00, 0xd4, 0x00, 0xd5, 0x00, 0xd6, 0x00, 0xd7, 0x00, 0xd8, 
		//0x1790: .... .... .... ....
		0x00, 0xd9, 0x00, 0xda, 0x00, 0xdb, 0x00, 0xdc, 0x00, 0xdd, 0x00, 0xde, 0x00, 0xdf, 0x80, 0xe0, 
		//0x17a0: .... .... .... ....
		0x00, 0xe1, 0x80, 0xe1, 0x00, 0xe2, 0x80, 0xe2, 0x00, 0xe3, 0x80, 0xe3, 0x00, 0xe4, 0x80, 0xe4, 
		//0x17b0: .... .... .... ....
		0x00, 0xe5, 0x80, 0xe5, 0x00, 0xe6, 0x80, 0xe6, 0x00, 0xe7, 0x80, 0xe7, 0x00, 0xe8, 0x80, 0xe8, 
		//0x17c0: .... .... .... ....
		0x00, 0xe9, 0x80, 0xe9, 0x00, 0xea, 0x80, 0xea, 0x00, 0xeb, 0x80, 0xeb, 0x00, 0xec, 0x80, 0xec, 
		//0x17d0: .... .... .... ....
		0x00, 0xed, 0x80, 0xed, 0x00, 0xee, 0x80, 0xee, 0x00, 0xef, 0x80, 0xef, 0xf0, 0xef, 0x1e, 0x1e, 
		//0x17e0: .... .... .... ....
		0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 
		//0x17f0: .... .... .... ....
		0x1e, 0x1e, 0x1e, 0x1e, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 
		//0x1800: .... .... .... ....
		0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 
		//0x1810: .... .... .... ....
		0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 
		//0x1820: .... .... .... ....
		0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 
		//0x1830: .... .... .... ....
		0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 
		//0x1840: .... .... .... ....
		0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x18, 0x18, 0x18, 0x18, 0x17, 0x17, 0x17, 0x17, 0x16, 
		//0x1850: .... .... .... ....
		0x16, 0x15, 0x15, 0x14, 0x14, 0x13, 0x13, 0x13, 0x12, 0x12, 0x11, 0x11, 0x10, 0x10, 0x0f, 0x0f, 
		//0x1860: .... .... .... ....
		0x0e, 0x0e, 0x0d, 0x0d, 0x0c, 0x0c, 0x0b, 0x0b, 0x0a, 0x0a, 0x0a, 0x09, 0x09, 0x08, 0x08, 0x08, 
		//0x1870: .... .... .... ....
		0x08, 0x07, 0x07, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x05, 0x05, 0x05, 0x05, 0x05, 
		//0x1880: .... .... .... ....
		0x05, 0x05, 0x05, 0x05, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 
		//0x1890: .... .... .... ....
		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
		//0x18a0: .... .... .... ....
		0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 
		//0x18b0: .... .... .... ....
		0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 
		//0x18c0: .... .... .... ....
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
		//0x18d0: .... .... .... ....
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x6b, 
		//0x18e0: .... .... .... ...k
		0x00, 0x65, 0x40, 0x5f, 0x00, 0x5a, 0xc0, 0x54, 0x00, 0x50, 0x80, 0x4b, 0x40, 0x47, 0x40, 0x43, 
		//0x18f0: .e@_ .Z.T .P.K @G@C
		0x80, 0x3f, 0x00, 0x3c, 0xa0, 0x38, 0x80, 0x35, 0x80, 0x32, 0xa0, 0x2f, 0x00, 0x2d, 0x60, 0x2a, 
		//0x1900: .?.< .8.5 .2./ .-`*
		0x00, 0x28, 0xc0, 0x25, 0xa0, 0x23, 0xa0, 0x21, 0xc0, 0x1f, 0x00, 0x1e, 0x50, 0x1c, 0xc0, 0x1a, 
		//0x1910: .(.% .#.! .... P...
		0x40, 0x19, 0xd0, 0x17, 0x80, 0x16, 0x30, 0x15, 0x00, 0x14, 0xe0, 0x12, 0xd0, 0x11, 0xd0, 0x10, 
		//0x1920: @... ..0. .... ....
		0xe0, 0x0f, 0x00, 0x0f, 0x20, 0x0e, 0x60, 0x0d, 0xa0, 0x0c, 0xe0, 0x0b, 0x40, 0x0b, 0xa0, 0x0a, 
		//0x1930: ....  .`. .... @...
		0x00, 0x0a, 0x70, 0x09, 0xf0, 0x08, 0x70, 0x08, 0xf0, 0x07, 0x80, 0x07, 0x10, 0x07, 0xb0, 0x06, 
		//0x1940: ..p. ..p. .... ....
		0x50, 0x06, 0xf0, 0x05, 0xa0, 0x05, 0x50, 0x05, 0x00, 0x05, 0xb0, 0x04, 0x70, 0x04, 0x30, 0x04, 
		//0x1950: P... ..P. .... p.0.
		0xf0, 0x03, 0xc0, 0x03, 0x80, 0x03, 0x40, 0x6a, 0x40, 0x64, 0xa0, 0x5e, 0x60, 0x59, 0x40, 0x54, 
		//0x1960: .... ..@j @d.^ `Y@T
		0xa0, 0x4f, 0x20, 0x4b, 0xe0, 0x46, 0xe0, 0x42, 0x20, 0x3f, 0xa0, 0x3b, 0x40, 0x38, 0x20, 0x35, 
		//0x1970: .O K .F.B  ?.; @8 5
		0x20, 0x32, 0x50, 0x2f, 0xb0, 0x2c, 0x20, 0x2a, 0xd0, 0x27, 0x90, 0x25, 0x70, 0x23, 0x70, 0x21, 
		//0x1980:  2P/ ., * .'.% p#p!
		0x90, 0x1f, 0xd0, 0x1d, 0x20, 0x1c, 0x90, 0x1a, 0x10, 0x19, 0xb0, 0x17, 0x50, 0x16, 0x10, 0x15, 
		//0x1990: ....  ... .... P...
		0xe0, 0x13, 0xc0, 0x12, 0xc0, 0x11, 0xc0, 0x10, 0xd0, 0x0f, 0xf0, 0x0e, 0x10, 0x0e, 0x50, 0x0d, 
		//0x19a0: .... .... .... ..P.
		0x90, 0x0c, 0xd0, 0x0b, 0x30, 0x0b, 0x90, 0x0a, 0xf0, 0x09, 0x60, 0x09, 0xe0, 0x08, 0x60, 0x08, 
		//0x19b0: .... 0... ..`. ..`.
		0xe0, 0x07, 0x70, 0x07, 0x10, 0x07, 0xa0, 0x06, 0x40, 0x06, 0xe0, 0x05, 0x90, 0x05, 0x40, 0x05, 
		//0x19c0: ..p. .... @... ..@.
		0xf0, 0x04, 0xb0, 0x04, 0x70, 0x04, 0x30, 0x04, 0xf0, 0x03, 0xb0, 0x03, 0x80, 0x03, 0x80, 0x69, 
		//0x19d0: .... p.0. .... ...i
		0x80, 0x63, 0x00, 0x5e, 0xa0, 0x58, 0xc0, 0x53, 0x00, 0x4f, 0xa0, 0x4a, 0x60, 0x46, 0x80, 0x42, 
		//0x19e0: .c.^ .X.S .O.J `F.B
		0xc0, 0x3e, 0x40, 0x3b, 0xe0, 0x37, 0xc0, 0x34, 0xc0, 0x31, 0x00, 0x2f, 0x50, 0x2c, 0xe0, 0x29, 
		//0x19f0: .>@; .7.4 .1./ P,.)
		0x80, 0x27, 0x50, 0x25, 0x30, 0x23, 0x40, 0x21, 0x60, 0x1f, 0xa0, 0x1d, 0xf0, 0x1b, 0x60, 0x1a, 
		//0x1a00: .'P% 0#@! `... ..`.
		0xe0, 0x18, 0x80, 0x17, 0x30, 0x16, 0xf0, 0x14, 0xc0, 0x13, 0xa0, 0x12, 0xa0, 0x11, 0xa0, 0x10, 
		//0x1a10: .... 0... .... ....
		0xb0, 0x0f, 0xd0, 0x0e, 0x00, 0x0e, 0x30, 0x0d, 0x70, 0x0c, 0xc0, 0x0b, 0x10, 0x0b, 0x70, 0x0a, 
		//0x1a20: .... ..0. p... ..p.
		0xe0, 0x09, 0x50, 0x09, 0xd0, 0x08, 0x50, 0x08, 0xd0, 0x07, 0x60, 0x07, 0x00, 0x07, 0x90, 0x06, 
		//0x1a30: ..P. ..P. ..`. ....
		0x30, 0x06, 0xe0, 0x05, 0x80, 0x05, 0x30, 0x05, 0xf0, 0x04, 0xa0, 0x04, 0x60, 0x04, 0x20, 0x04, 
		//0x1a40: 0... ..0. .... `. .
		0xe0, 0x03, 0xb0, 0x03, 0x80, 0x03, 0xc0, 0x68, 0xe0, 0x62, 0x40, 0x5d, 0x00, 0x58, 0x20, 0x53, 
		//0x1a50: .... ...h .b@] .X S
		0x80, 0x4e, 0x00, 0x4a, 0xe0, 0x45, 0x00, 0x42, 0x40, 0x3e, 0xc0, 0x3a, 0x80, 0x37, 0x60, 0x34, 
		//0x1a60: .N.J .E.B @>.: .7`4
		0x70, 0x31, 0xa0, 0x2e, 0x00, 0x2c, 0x90, 0x29, 0x40, 0x27, 0x00, 0x25, 0xf0, 0x22, 0x00, 0x21, 
		//0x1a70: p1.. .,.) @'.% .".!
		0x20, 0x1f, 0x60, 0x1d, 0xc0, 0x1b, 0x30, 0x1a, 0xb0, 0x18, 0x50, 0x17, 0x00, 0x16, 0xc0, 0x14, 
		//0x1a80:  .`. ..0. ..P. ....
		0xa0, 0x13, 0x80, 0x12, 0x80, 0x11, 0x80, 0x10, 0x90, 0x0f, 0xb0, 0x0e, 0xe0, 0x0d, 0x10, 0x0d, 
		//0x1a90: .... .... .... ....
		0x60, 0x0c, 0xb0, 0x0b, 0x00, 0x0b, 0x60, 0x0a, 0xd0, 0x09, 0x40, 0x09, 0xc0, 0x08, 0x40, 0x08, 
		//0x1aa0: `... ..`. ..@. ..@.
		0xd0, 0x07, 0x60, 0x07, 0xf0, 0x06, 0x80, 0x06, 0x30, 0x06, 0xd0, 0x05, 0x80, 0x05, 0x30, 0x05, 
		//0x1ab0: ..`. .... 0... ..0.
		0xe0, 0x04, 0xa0, 0x04, 0x60, 0x04, 0x20, 0x04, 0xe0, 0x03, 0xb0, 0x03, 0x70, 0x03, 0x00, 0x68, 
		//0x1ac0: .... `. . .... p..h
		0x20, 0x62, 0xa0, 0x5c, 0x60, 0x57, 0x80, 0x52, 0xe0, 0x4d, 0x80, 0x49, 0x60, 0x45, 0x80, 0x41, 
		//0x1ad0:  b.. `W.R .M.I `E.A
		0xe0, 0x3d, 0x60, 0x3a, 0x20, 0x37, 0x00, 0x34, 0x10, 0x31, 0x50, 0x2e, 0xb0, 0x2b, 0x40, 0x29, 
		//0x1ae0: .=`:  7.4 .1P. .+@)
		0xf0, 0x26, 0xc0, 0x24, 0xb0, 0x22, 0xc0, 0x20, 0xf0, 0x1e, 0x30, 0x1d, 0x90, 0x1b, 0x00, 0x1a, 
		//0x1af0: .&.$ .".  ..0. ....
		0x80, 0x18, 0x20, 0x17, 0xe0, 0x15, 0xa0, 0x14, 0x80, 0x13, 0x60, 0x12, 0x60, 0x11, 0x60, 0x10, 
		//0x1b00: .. . .... ..`. `.`.
		0x70, 0x0f, 0x90, 0x0e, 0xc0, 0x0d, 0x00, 0x0d, 0x40, 0x0c, 0x90, 0x0b, 0xf0, 0x0a, 0x50, 0x0a, 
		//0x1b10: p... .... @... ..P.
		0xc0, 0x09, 0x30, 0x09, 0xb0, 0x08, 0x30, 0x08, 0xc0, 0x07, 0x50, 0x07, 0xe0, 0x06, 0x80, 0x06, 
		//0x1b20: ..0. ..0. ..P. ....
		0x20, 0x06, 0xc0, 0x05, 0x70, 0x05, 0x20, 0x05, 0xe0, 0x04, 0x90, 0x04, 0x50, 0x04, 0x10, 0x04, 
		//0x1b30:  ... p. . .... P...
		0xe0, 0x03, 0xa0, 0x03, 0x70, 0x03, 0x40, 0x67, 0x60, 0x61, 0x00, 0x5c, 0xc0, 0x56, 0xe0, 0x51, 
		//0x1b40: .... p.@g `a.. .V.Q
		0x60, 0x4d, 0x00, 0x49, 0xe0, 0x44, 0x00, 0x41, 0x60, 0x3d, 0xe0, 0x39, 0xa0, 0x36, 0xa0, 0x33, 
		//0x1b50: `M.I .D.A `=.9 .6.3
		0xb0, 0x30, 0x00, 0x2e, 0x60, 0x2b, 0xf0, 0x28, 0xb0, 0x26, 0x80, 0x24, 0x70, 0x22, 0x80, 0x20, 
		//0x1b60: .0.. `+.( .&.$ p". 
		0xb0, 0x1e, 0xf0, 0x1c, 0x50, 0x1b, 0xd0, 0x19, 0x60, 0x18, 0x00, 0x17, 0xb0, 0x15, 0x80, 0x14, 
		//0x1b70: .... P... `... ....
		0x50, 0x13, 0x40, 0x12, 0x40, 0x11, 0x40, 0x10, 0x50, 0x0f, 0x80, 0x0e, 0xb0, 0x0d, 0xe0, 0x0c, 
		//0x1b80: P.@. @.@. P... ....
		0x30, 0x0c, 0x80, 0x0b, 0xe0, 0x0a, 0x40, 0x0a, 0xb0, 0x09, 0x20, 0x09, 0xa0, 0x08, 0x20, 0x08, 
		//0x1b90: 0... ..@. .. . .. .
		0xb0, 0x07, 0x40, 0x07, 0xd0, 0x06, 0x70, 0x06, 0x10, 0x06, 0xc0, 0x05, 0x70, 0x05, 0x20, 0x05, 
		//0x1ba0: ..@. ..p. .... p. .
		0xd0, 0x04, 0x90, 0x04, 0x50, 0x04, 0x10, 0x04, 0xd0, 0x03, 0xa0, 0x03, 0x60, 0x03, 0x80, 0x66, 
		//0x1bb0: .... P... .... `..f
		0xc0, 0x60, 0x40, 0x5b, 0x20, 0x56, 0x60, 0x51, 0xc0, 0x4c, 0x80, 0x48, 0x60, 0x44, 0x80, 0x40, 
		//0x1bc0: .`@[  V`Q .L.H `D.@
		0xe0, 0x3c, 0x80, 0x39, 0x40, 0x36, 0x40, 0x33, 0x60, 0x30, 0xa0, 0x2d, 0x10, 0x2b, 0xb0, 0x28, 
		//0x1bd0: .<.9 @6@3 `0.- .+.(
		0x60, 0x26, 0x40, 0x24, 0x30, 0x22, 0x40, 0x20, 0x70, 0x1e, 0xc0, 0x1c, 0x20, 0x1b, 0xa0, 0x19, 
		//0x1be0: `&@$ 0"@  p...  ...
		0x30, 0x18, 0xd0, 0x16, 0x90, 0x15, 0x50, 0x14, 0x30, 0x13, 0x20, 0x12, 0x20, 0x11, 0x20, 0x10, 
		//0x1bf0: 0... ..P. 0. .  . .
		0x40, 0x0f, 0x60, 0x0e, 0x90, 0x0d, 0xd0, 0x0c, 0x10, 0x0c, 0x70, 0x0b, 0xc0, 0x0a, 0x30, 0x0a, 
		//0x1c00: @.`. .... ..p. ..0.
		0xa0, 0x09, 0x10, 0x09, 0x90, 0x08, 0x10, 0x08, 0xa0, 0x07, 0x30, 0x07, 0xd0, 0x06, 0x60, 0x06, 
		//0x1c10: .... .... ..0. ..`.
		0x00, 0x06, 0xb0, 0x05, 0x60, 0x05, 0x10, 0x05, 0xd0, 0x04, 0x80, 0x04, 0x40, 0x04, 0x00, 0x04, 
		//0x1c20: .... `... .... @...
		0xd0, 0x03, 0x90, 0x03, 0x60, 0x03, 0xc0, 0x65, 0x00, 0x60, 0xa0, 0x5a, 0x80, 0x55, 0xc0, 0x50, 
		//0x1c30: .... `..e .`.Z .U.P
		0x40, 0x4c, 0xe0, 0x47, 0xe0, 0x43, 0x20, 0x40, 0x80, 0x3c, 0x20, 0x39, 0xe0, 0x35, 0xe0, 0x32, 
		//0x1c40: @L.G .C @ .< 9 .5.2
		0x00, 0x30, 0x50, 0x2d, 0xc0, 0x2a, 0x60, 0x28, 0x20, 0x26, 0xf0, 0x23, 0xf0, 0x21, 0x10, 0x20, 
		//0x1c50: .0P- .*`(  &.# .!. 
		0x40, 0x1e, 0x90, 0x1c, 0xf0, 0x1a, 0x70, 0x19, 0x00, 0x18, 0xb0, 0x16, 0x60, 0x15, 0x30, 0x14, 
		//0x1c60: @... ..p. .... `.0.
		0x10, 0x13, 0x00, 0x12, 0x00, 0x11, 0x00, 0x10, 0x20, 0x0f, 0x40, 0x0e, 0x80, 0x0d, 0xc0, 0x0c, 
		//0x1c70: .... ....  .@. ....
		0x00, 0x0c, 0x50, 0x0b, 0xb0, 0x0a, 0x10, 0x0a, 0x80, 0x09, 0x00, 0x09, 0x80, 0x08, 0x00, 0x08, 
		//0x1c80: ..P. .... .... ....
		0x90, 0x07, 0x20, 0x07, 0xc0, 0x06, 0x60, 0x06, 0x00, 0x06, 0xa0, 0x05, 0x50, 0x05, 0x00, 0x05, 
		//0x1c90: .. . ..`. .... P...
		0xc0, 0x04, 0x80, 0x04, 0x40, 0x04, 0x00, 0x04, 0xc0, 0x03, 0x90, 0x03, 0x60, 0x03, 0x60, 0x71, 
		//0x1ca0: .... @... .... `.`q
		0x00, 0x6b, 0x00, 0x65, 0x40, 0x5f, 0x00, 0x5a, 0xc0, 0x54, 0x00, 0x50, 0x80, 0x4b, 0x40, 0x47, 
		//0x1cb0: .k.e @_.Z .T.P .K@G
		0x40, 0x43, 0x80, 0x3f, 0x00, 0x3c, 0xb0, 0x38, 0x80, 0x35, 0x80, 0x32, 0xa0, 0x2f, 0x00, 0x2d, 
		//0x1cc0: @C.? .<.8 .5.2 ./.-
		0x60, 0x2a, 0x00, 0x28, 0xc0, 0x25, 0xa0, 0x23, 0xa0, 0x21, 0xc0, 0x1f, 0x00, 0x1e, 0x50, 0x1c, 
		//0x1cd0: `*.( .%.# .!.. ..P.
		0xc0, 0x1a, 0x40, 0x19, 0xd0, 0x17, 0x80, 0x16, 0x30, 0x15, 0x00, 0x14, 0xe0, 0x12, 0xd0, 0x11, 
		//0x1ce0: ..@. .... 0... ....
		0xd0, 0x10, 0xe0, 0x0f, 0x00, 0x0f, 0x20, 0x0e, 0x60, 0x0d, 0xa0, 0x0c, 0xe0, 0x0b, 0x40, 0x0b, 
		//0x1cf0: .... .. . `... ..@.
		0xa0, 0x0a, 0x00, 0x0a, 0x70, 0x09, 0xf0, 0x08, 0x70, 0x08, 0xf0, 0x07, 0x80, 0x07, 0x10, 0x07, 
		//0x1d00: .... p... p... ....
		0xb0, 0x06, 0x50, 0x06, 0xf0, 0x05, 0xa0, 0x05, 0x50, 0x05, 0x00, 0x05, 0xb0, 0x04, 0x70, 0x04, 
		//0x1d10: ..P. .... P... ..p.
		0x30, 0x04, 0xf0, 0x03, 0xc0, 0x03, 0x80, 0x70, 0x40, 0x6a, 0x40, 0x64, 0xa0, 0x5e, 0x60, 0x59, 
		//0x1d20: 0... ...p @j@d .^`Y
		0x60, 0x54, 0x80, 0x4f, 0x20, 0x4b, 0xe0, 0x46, 0xe0, 0x42, 0x20, 0x3f, 0xa0, 0x3b, 0x40, 0x38, 
		//0x1d30: `T.O  K.F .B ? .;@8
		0x20, 0x35, 0x20, 0x32, 0x50, 0x2f, 0xb0, 0x2c, 0x30, 0x2a, 0xc0, 0x27, 0x90, 0x25, 0x70, 0x23, 
		//0x1d40:  5 2 P/., 0*.' .%p#
		0x70, 0x21, 0x90, 0x1f, 0xd0, 0x1d, 0x20, 0x1c, 0x90, 0x1a, 0x10, 0x19, 0xb0, 0x17, 0x50, 0x16, 
		//0x1d50: p!.. .. . .... ..P.
		0x10, 0x15, 0xe0, 0x13, 0xc0, 0x12, 0xc0, 0x11, 0xc0, 0x10, 0xd0, 0x0f, 0xe0, 0x0e, 0x10, 0x0e, 
		//0x1d60: .... .... .... ....
		0x40, 0x0d, 0x80, 0x0c, 0xd0, 0x0b, 0x30, 0x0b, 0x90, 0x0a, 0xf0, 0x09, 0x60, 0x09, 0xe0, 0x08, 
		//0x1d70: @... ..0. .... `...
		0x60, 0x08, 0xe0, 0x07, 0x70, 0x07, 0x00, 0x07, 0xa0, 0x06, 0x40, 0x06, 0xe0, 0x05, 0x90, 0x05, 
		//0x1d80: `... p... ..@. ....
		0x40, 0x05, 0xf0, 0x04, 0xb0, 0x04, 0x70, 0x04, 0x30, 0x04, 0xf0, 0x03, 0xb0, 0x03, 0xc0, 0x6f, 
		//0x1d90: @... ..p. 0... ...o
		0x80, 0x69, 0x80, 0x63, 0x00, 0x5e, 0xa0, 0x58, 0xc0, 0x53, 0x00, 0x4f, 0xa0, 0x4a, 0x60, 0x46, 
		//0x1da0: .i.c .^.X .S.O .J`F
		0x80, 0x42, 0xc0, 0x3e, 0x40, 0x3b, 0xe0, 0x37, 0xc0, 0x34, 0xc0, 0x31, 0x00, 0x2f, 0x50, 0x2c, 
		//0x1db0: .B.> @;.7 .4.1 ./P,
		0xe0, 0x29, 0x80, 0x27, 0x50, 0x25, 0x30, 0x23, 0x40, 0x21, 0x60, 0x1f, 0xa0, 0x1d, 0xf0, 0x1b, 
		//0x1dc0: .).' P%0# @!`. ....
		0x60, 0x1a, 0xe0, 0x18, 0x80, 0x17, 0x30, 0x16, 0xf0, 0x14, 0xc0, 0x13, 0xa0, 0x12, 0xa0, 0x11, 
		//0x1dd0: `... ..0. .... ....
		0xa0, 0x10, 0xb0, 0x0f, 0xd0, 0x0e, 0xf0, 0x0d, 0x30, 0x0d, 0x70, 0x0c, 0xc0, 0x0b, 0x10, 0x0b, 
		//0x1de0: .... .... 0.p. ....
		0x70, 0x0a, 0xe0, 0x09, 0x50, 0x09, 0xd0, 0x08, 0x50, 0x08, 0xd0, 0x07, 0x60, 0x07, 0xf0, 0x06, 
		//0x1df0: p... P... P... `...
		0x90, 0x06, 0x30, 0x06, 0xe0, 0x05, 0x80, 0x05, 0x30, 0x05, 0xf0, 0x04, 0xa0, 0x04, 0x60, 0x04, 
		//0x1e00: ..0. .... 0... ..`.
		0x20, 0x04, 0xe0, 0x03, 0xb0, 0x03, 0xe0, 0x6e, 0xc0, 0x68, 0xe0, 0x62, 0x40, 0x5d, 0x00, 0x58, 
		//0x1e10:  ... ...n .h.b @].X
		0x20, 0x53, 0x80, 0x4e, 0x00, 0x4a, 0xe0, 0x45, 0x00, 0x42, 0x40, 0x3e, 0xc0, 0x3a, 0x70, 0x37, 
		//0x1e20:  S.N .J.E .B@> .:p7
		0x60, 0x34, 0x70, 0x31, 0xa0, 0x2e, 0x00, 0x2c, 0x90, 0x29, 0x40, 0x27, 0x00, 0x25, 0xf0, 0x22, 
		//0x1e30: `4p1 ..., .)@' .%."
		0x00, 0x21, 0x20, 0x1f, 0x60, 0x1d, 0xc0, 0x1b, 0x30, 0x1a, 0xb0, 0x18, 0x50, 0x17, 0x00, 0x16, 
		//0x1e40: .! . `... 0... P...
		0xc0, 0x14, 0xa0, 0x13, 0x80, 0x12, 0x80, 0x11, 0x80, 0x10, 0x90, 0x0f, 0xb0, 0x0e, 0xe0, 0x0d, 
		//0x1e50: .... .... .... ....
		0x10, 0x0d, 0x60, 0x0c, 0xb0, 0x0b, 0x00, 0x0b, 0x60, 0x0a, 0xd0, 0x09, 0x40, 0x09, 0xc0, 0x08, 
		//0x1e60: ..`. .... `... @...
		0x40, 0x08, 0xd0, 0x07, 0x60, 0x07, 0xf0, 0x06, 0x80, 0x06, 0x30, 0x06, 0xd0, 0x05, 0x80, 0x05, 
		//0x1e70: @... `... ..0. ....
		0x30, 0x05, 0xe0, 0x04, 0xa0, 0x04, 0x60, 0x04, 0x20, 0x04, 0xe0, 0x03, 0xb0, 0x03, 0x20, 0x6e, 
		//0x1e80: 0... ..`.  ... .. n
		0x00, 0x68, 0x20, 0x62, 0xa0, 0x5c, 0x60, 0x57, 0x80, 0x52, 0xe0, 0x4d, 0x80, 0x49, 0x60, 0x45, 
		//0x1e90: .h b ..`W .R.M .I`E
		0x80, 0x41, 0xc0, 0x3d, 0x60, 0x3a, 0x10, 0x37, 0x00, 0x34, 0x10, 0x31, 0x50, 0x2e, 0xb0, 0x2b, 
		//0x1ea0: .A.= `:.7 .4.1 P..+
		0x40, 0x29, 0xf0, 0x26, 0xc0, 0x24, 0xb0, 0x22, 0xc0, 0x20, 0xe0, 0x1e, 0x30, 0x1d, 0x90, 0x1b, 
		//0x1eb0: @).& .$." . .. 0...
		0x00, 0x1a, 0x80, 0x18, 0x20, 0x17, 0xe0, 0x15, 0xa0, 0x14, 0x80, 0x13, 0x60, 0x12, 0x60, 0x11, 
		//0x1ec0: ....  ... .... `.`.
		0x60, 0x10, 0x70, 0x0f, 0x90, 0x0e, 0xc0, 0x0d, 0x00, 0x0d, 0x40, 0x0c, 0x90, 0x0b, 0xf0, 0x0a, 
		//0x1ed0: `.p. .... ..@. ....
		0x50, 0x0a, 0xc0, 0x09, 0x30, 0x09, 0xb0, 0x08, 0x30, 0x08, 0xb0, 0x07, 0x50, 0x07, 0xe0, 0x06, 
		//0x1ee0: P... 0... 0... P...
		0x80, 0x06, 0x20, 0x06, 0xc0, 0x05, 0x70, 0x05, 0x20, 0x05, 0xe0, 0x04, 0x90, 0x04, 0x50, 0x04, 
		//0x1ef0: .. . ..p.  ... ..P.
		0x10, 0x04, 0xd0, 0x03, 0xa0, 0x03, 0x60, 0x6d, 0x40, 0x67, 0x60, 0x61, 0x00, 0x5c, 0xc0, 0x56, 
		//0x1f00: .... ..`m @g`a ...V
		0xe0, 0x51, 0x60, 0x4d, 0x00, 0x49, 0xe0, 0x44, 0x00, 0x41, 0x60, 0x3d, 0xe0, 0x39, 0xb0, 0x36, 
		//0x1f10: .Q`M .I.D .A`= .9.6
		0xa0, 0x33, 0xb0, 0x30, 0x00, 0x2e, 0x60, 0x2b, 0xf0, 0x28, 0xb0, 0x26, 0x80, 0x24, 0x70, 0x22, 
		//0x1f20: .3.0 ..`+ .(.& .$p"
		0x80, 0x20, 0xb0, 0x1e, 0xf0, 0x1c, 0x50, 0x1b, 0xd0, 0x19, 0x60, 0x18, 0x00, 0x17, 0xb0, 0x15, 
		//0x1f30: . .. ..P. ..`. ....
		0x80, 0x14, 0x50, 0x13, 0x40, 0x12, 0x40, 0x11, 0x40, 0x10, 0x50, 0x0f, 0x80, 0x0e, 0xb0, 0x0d, 
		//0x1f40: ..P. @.@. @.P. ....
		0xe0, 0x0c, 0x30, 0x0c, 0x80, 0x0b, 0xe0, 0x0a, 0x40, 0x0a, 0xb0, 0x09, 0x20, 0x09, 0xa0, 0x08, 
		//0x1f50: ..0. .... @...  ...
		0x20, 0x08, 0xb0, 0x07, 0x40, 0x07, 0xd0, 0x06, 0x70, 0x06, 0x10, 0x06, 0xc0, 0x05, 0x70, 0x05, 
		//0x1f60:  ... @... p... ..p.
		0x20, 0x05, 0xd0, 0x04, 0x90, 0x04, 0x50, 0x04, 0x10, 0x04, 0xd0, 0x03, 0xa0, 0x03, 0x80, 0x6c, 
		//0x1f70:  ... ..P. .... ...l
		0x80, 0x66, 0xc0, 0x60, 0x40, 0x5b, 0x20, 0x56, 0x60, 0x51, 0xc0, 0x4c, 0x80, 0x48, 0x60, 0x44, 
		//0x1f80: .f.` @[ V `Q.L .H`D
		0x80, 0x40, 0xe0, 0x3c, 0x80, 0x39, 0x40, 0x36, 0x40, 0x33, 0x60, 0x30, 0xa0, 0x2d, 0x10, 0x2b, 
		//0x1f90: .@.< .9@6 @3`0 .-.+
		0xb0, 0x28, 0x60, 0x26, 0x40, 0x24, 0x30, 0x22, 0x40, 0x20, 0x70, 0x1e, 0xc0, 0x1c, 0x20, 0x1b, 
		//0x1fa0: .(`& @$0" @ p. .. .
		0xa0, 0x19, 0x30, 0x18, 0xd0, 0x16, 0x90, 0x15, 0x50, 0x14, 0x30, 0x13, 0x20, 0x12, 0x20, 0x11, 
		//0x1fb0: ..0. .... P.0.  . .
		0x20, 0x10, 0x40, 0x0f, 0x60, 0x0e, 0x90, 0x0d, 0xd0, 0x0c, 0x10, 0x0c, 0x70, 0x0b, 0xc0, 0x0a, 
		//0x1fc0:  .@. `... .... p...
		0x30, 0x0a, 0xa0, 0x09, 0x10, 0x09, 0x90, 0x08, 0x10, 0x08, 0xa0, 0x07, 0x30, 0x07, 0xc0, 0x06, 
		//0x1fd0: 0... .... .... 0...
		0x60, 0x06, 0x00, 0x06, 0xb0, 0x05, 0x60, 0x05, 0x10, 0x05, 0xd0, 0x04, 0x80, 0x04, 0x40, 0x04, 
		//0x1fe0: `... ..`. .... ..@.
		0x00, 0x04, 0xd0, 0x03, 0x90, 0x03, 0xc0, 0x6b, 0xc0, 0x65, 0x00, 0x60, 0xa0, 0x5a, 0x80, 0x55, 
		//0x1ff0: .... ...k .e.` .Z.U
		0xc0, 0x50, 0x40, 0x4c, 0xe0, 0x47, 0xe0, 0x43, 0x20, 0x40, 0x80, 0x3c, 0x20, 0x39, 0xe0, 0x35, 
		//0x2000: .P@L .G.C  @.<  9.5
		0xe0, 0x32, 0x00, 0x30, 0x50, 0x2d, 0xc0, 0x2a, 0x60, 0x28, 0x20, 0x26, 0xf0, 0x23, 0xf0, 0x21, 
		//0x2010: .2.0 P-.* `( & .#.!
		0x10, 0x20, 0x40, 0x1e, 0x90, 0x1c, 0xf0, 0x1a, 0x70, 0x19, 0x00, 0x18, 0xb0, 0x16, 0x60, 0x15, 
		//0x2020: . @. .... p... ..`.
		0x30, 0x14, 0x10, 0x13, 0x00, 0x12, 0x00, 0x11, 0x00, 0x10, 0x20, 0x0f, 0x40, 0x0e, 0x80, 0x0d, 
		//0x2030: 0... .... .. . @...
		0xb0, 0x0c, 0x00, 0x0c, 0x50, 0x0b, 0xb0, 0x0a, 0x10, 0x0a, 0x80, 0x09, 0x00, 0x09, 0x80, 0x08, 
		//0x2040: .... P... .... ....
		0x00, 0x08, 0x90, 0x07, 0x20, 0x07, 0xc0, 0x06, 0x50, 0x06, 0x00, 0x06, 0xa0, 0x05, 0x50, 0x05, 
		//0x2050: ....  ... P... ..P.
		0x00, 0x05, 0xc0, 0x04, 0x80, 0x04, 0x40, 0x04, 0x00, 0x04, 0xc0, 0x03, 0x90, 0x03, 0xb0, 0x06, 
		//0x2060: .... ..@. .... ....
		0x50, 0x06, 0xf4, 0x05, 0xa0, 0x05, 0x4c, 0x05, 0x00, 0x05, 0xb8, 0x04, 0x74, 0x04, 0x34, 0x04, 
		//0x2070: P... ..L. .... t.4.
		0xf8, 0x03, 0xc0, 0x03, 0x8a, 0x03, 0x58, 0x03, 0x28, 0x03, 0xfa, 0x02, 0xd0, 0x02, 0xa6, 0x02, 
		//0x2080: .... ..X. (... ....
		0x80, 0x02, 0x5c, 0x02, 0x3a, 0x02, 0x1a, 0x02, 0xfc, 0x01, 0xe0, 0x01, 0xc5, 0x01, 0xac, 0x01, 
		//0x2090: .... :... .... ....
		0x94, 0x01, 0x7d, 0x01, 0x68, 0x01, 0x53, 0x01, 0x40, 0x01, 0x2e, 0x01, 0x1d, 0x01, 0x0d, 0x01, 
		//0x20a0: ..}. h.S. @... ....
		0xfe, 0x00, 0xf0, 0x00, 0xe2, 0x00, 0xd6, 0x00, 0xca, 0x00, 0xbe, 0x00, 0xb4, 0x00, 0xaa, 0x00, 
		//0x20b0: .... .... .... ....
		0xa0, 0x00, 0x97, 0x00, 0x8f, 0x00, 0x87, 0x00, 0x7f, 0x00, 0x78, 0x00, 0x71, 0x00, 0x6b, 0x00, 
		//0x20c0: .... .... ..x. q.k.
		0x65, 0x00, 0x5f, 0x00, 0x5a, 0x00, 0x55, 0x00, 0x50, 0x00, 0x4b, 0x00, 0x47, 0x00, 0x43, 0x00, 
		//0x20d0: e._. Z.U. P.K. G.C.
		0x3f, 0x00, 0x3c, 0x00, 0x38, 0x00, 0x35, 0x00, 0x32, 0x00, 0x2f, 0x00, 0x2d, 0x00, 0x2a, 0x00, 
		//0x20e0: ?.<. 8.5. 2./. -.*.
		0x28, 0x00, 0x25, 0x00, 0x23, 0x00, 0x21, 0x00, 0x1f, 0x00, 0x1e, 0x00, 0x1c, 0x00, 0x1a, 0x00, 
		//0x20f0: (.%. #.!. .... ....
		0x19, 0x00, 0x17, 0x00, 0x16, 0x00, 0x15, 0x00, 0x14, 0x00, 0x12, 0x00, 0x11, 0x00, 0x10, 0x00, 
		//0x2100: .... .... .... ....
		0x0f, 0x00, 0x0f, 0x00, 0x0e, 0x00, 0x00, 0x18, 0x31, 0x4a, 0x61, 0x78, 0x8d, 0xa1, 0xb4, 0xc5, 
		//0x2110: .... .... 1Jax ....
		0xd4, 0xe0, 0xeb, 0xf4, 0xfa, 0xfd, 0xff, 0xfd, 0xfa, 0xf4, 0xeb, 0xe0, 0xd4, 0xc5, 0xb4, 0xa1, 
		//0x2120: .... .... .... ....
		0x8d, 0x78, 0x61, 0x4a, 0x31, 0x18, 0x00, 0x15, 0x20, 0x29, 0x30, 0x37, 0x3d, 0x44, 0x49, 0x4f, 
		//0x2130: .xaJ 1...  )07 =DIO
		0x54, 0x59, 0x5e, 0x62, 0x67, 0x6b, 0x6f, 0x73, 0x77, 0x7c, 0x7f, 0x83, 0x86, 0x8a, 0x8e, 0x91, 
		//0x2140: TY^b gkos w|.. ....
		0x95, 0x98, 0x9b, 0x9f, 0xa2, 0xa5, 0xa9, 0xab, 0xaf, 0xb3, 0xb5, 0xb8, 0xbb, 0xbe, 0xc1, 0xc3, 
		//0x2150: .... .... .... ....
		0xc6, 0xc9, 0xcc, 0xcf, 0xd1, 0xd4, 0xd7, 0xda, 0xdd, 0xdf, 0xe2, 0xe5, 0xe7, 0xea, 0xec, 0xef, 
		//0x2160: .... .... .... ....
		0xf1, 0xf4, 0xf6, 0xf9, 0xfb, 0xfe, 0xff, 0x00, 0x04, 0x08, 0x0c, 0x10, 0x14, 0x18, 0x1c, 0x20, 
		//0x2170: .... .... .... ... 
		0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44, 0x48, 0x4c, 0x50, 0x55, 0x59, 0x5d, 0x61, 
		//0x2180: $(,0 48<@ DHLP UY]a
		0x65, 0x69, 0x6d, 0x71, 0x75, 0x79, 0x7d, 0x81, 0x85, 0x89, 0x8d, 0x91, 0x95, 0x99, 0x9d, 0xa1, 
		//0x2190: eimq uy}. .... ....
		0xa5, 0xaa, 0xae, 0xb2, 0xb6, 0xba, 0xbe, 0xc2, 0xc6, 0xca, 0xce, 0xd2, 0xd6, 0xda, 0xde, 0xe2, 
		//0x21a0: .... .... .... ....
		0xe6, 0xea, 0xee, 0xf2, 0xf6, 0xfa, 0xff, 0x00, 0x04, 0x08, 0x0c, 0x10, 0x14, 0x18, 0x1c, 0x20, 
		//0x21b0: .... .... .... ... 
		0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44, 0x48, 0x4c, 0x50, 0x54, 0x58, 0x5c, 0x60, 
		//0x21c0: $(,0 48<@ DHLP TX.`
		0x64, 0x68, 0x6c, 0x70, 0x74, 0x78, 0x7c, 0x80, 0x84, 0x88, 0x8c, 0x90, 0x94, 0x98, 0x9c, 0xa0, 
		//0x21d0: dhlp tx|. .... ....
		0xa4, 0xa8, 0xac, 0xb0, 0xb4, 0xb8, 0xbc, 0xc0, 0xc4, 0xc8, 0xcc, 0xd0, 0xd4, 0xd8, 0xdc, 0xe0, 
		//0x21e0: .... .... .... ....
		0xe4, 0xe8, 0xec, 0xf0, 0xf4, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x21f0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2200: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2210: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2220: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2230: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2240: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x38, 0x04, 0x04, 0x00, 0x00, 0x00, 
		//0x2250: .... .... ..8. ....
		0x38, 0x04, 0x04, 0x00, 0x00, 0x00, 0x38, 0x04, 0x04, 0x00, 0x00, 0x00, 0x38, 0x04, 0x04, 0x00, 
		//0x2260: 8... ..8. .... 8...
		0x00, 0x00, 0x38, 0x04, 0x04, 0x00, 0x00, 0x00, 0x38, 0x04, 0x04, 0x00, 0x00, 0x00, 0x38, 0x04, 
		//0x2270: ..8. .... 8... ..8.
		0x04, 0x00, 0x00, 0x00, 0x38, 0x04, 0x04, 0x00, 0x00, 0x00, 0x38, 0x04, 0x04, 0x00, 0x00, 0x00, 
		//0x2280: .... 8... ..8. ....
		0x38, 0x04, 0x04, 0x00, 0x00, 0x00, 0x39, 0x04, 0x03, 0x00, 0x00, 0x00, 0x3a, 0x04, 0x02, 0x00, 
		//0x2290: 8... ..9. .... :...
		0x00, 0x00, 0x38, 0x04, 0x03, 0x00, 0x00, 0x00, 0x14, 0x00, 0x08, 0x00, 0x00, 0x00, 0x14, 0x00, 
		//0x22a0: ..8. .... .... ....
		0x08, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 
		//0x22b0: .... ,... .... ....
		0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 
		//0x22c0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x0d, 0x0a, 0x00, 
		//0x22d0: .... .... .... ....
		0x00, 0x0d, 0x0a, 0x00, 0x00, 0x0d, 0x0a, 0x00, 0x00, 0x0d, 0x0a, 0x0a, 0x00, 0x0d, 0x0a, 0x00, 
		//0x22e0: .... .... .... ....
		0x0d, 0x0a, 0x00, 0x00, 0x0d, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x0a, 0x00, 0x00, 0x0d, 0x0a, 0x00, 
		//0x22f0: .... .... .... ....
		0x00, 0x0d, 0x0a, 0x00, 0x00, 0x0d, 0x0a, 0x00, 0x00, 0x0d, 0x0a, 0x00, 0x00, 0x0d, 0x0a, 0x00, 
		//0x2300: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
		//0x2310: .... .... .... ....
		0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 
		//0x2320: .... .... .... ....
		0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2330: .... .... .... ....
		0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0b, 
		//0x2340: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 
		//0x2350: .... .... .... ....
		0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 
		//0x2360: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 
		//0x2370: .... .... .... ....
		0x00, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2380: .... .... .... ....
		0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 
		//0x2390: .... .... .... ....
		0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 
		//0x23a0: .... .... .... ....
		0x00, 0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x23b0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x23c0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x23d0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x0d, 0x0a, 0x1a, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x23e0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x23f0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x0a, 0x1a, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 
		//0x2400: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2410: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x0a, 0x1a, 0x00, 0x00, 0x00, 0x00, 
		//0x2420: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 
		//0x2430: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2440: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x6e, 0x65, 0x72, 0x74, 0x69, 0x61, 
		//0x2450: .... .... .Ine rtia
		0x20, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x3a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
		//0x2460:  Sam ple:          
		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
		//0x2470:                    
		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0d, 0x0a, 0x1a, 0x00, 0x00, 0x00, 0x00, 
		//0x2480:            ... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 
		//0x2490: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x24a0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x24b0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x24c0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x24d0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x24e0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x24f0: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2500: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2510: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2520: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2530: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2540: .... .... .... ....
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		//0x2550: .... .... .... ....
		0x00, };
	ds.assign(src, src + sizeof(src));


} // End of namespace DreamGen
