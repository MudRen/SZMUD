// By FunBoo@sz

#include <ansi.h> 
inherit BULLETIN_BOARD; 
        
void create() 
{ 
	set_name("�书�������Բ�", ({ "board" }) );  
	set("location", "/d/city/muoukt"); 
	set("board_id", "muoub" ); 
	set("long", "�书�������Բ�\n" ); 
	setup(); 
	set("capacity", 300); 
	replace_program(BULLETIN_BOARD); 
}       
