// By FunBoo@sz

#include <ansi.h> 
inherit BULLETIN_BOARD; 
        
void create() 
{ 
	set_name("Œ‰π¶≤‚ ‘¡Ù—‘≤æ", ({ "board" }) );  
	set("location", "/d/city/muoukt"); 
	set("board_id", "muoub" ); 
	set("long", "Œ‰π¶≤‚ ‘¡Ù—‘≤æ\n" ); 
	setup(); 
	set("capacity", 300); 
	replace_program(BULLETIN_BOARD); 
}       
