// jiansu.c  board.c 
// snowlf by 2001.9.30  
      
#include <ansi.h> 
inherit BULLETIN_BOARD; 

void create() 
{ 
	set_name(HIB+"���Բ�"+NOR, ({ "board" }) );  
	set("location", "/u/gateopen/workroom"); 
	set("board_id", "gateopen" ); 
	set("long", "��ľ�塣\n" ); 
	setup(); 
	set("capacity", 300); 
	replace_program(BULLETIN_BOARD); 
}
