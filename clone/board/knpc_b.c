inherit BULLETIN_BOARD; 
#include <ansi.h> 
void create() 
    {    
     set_name(HIG"BUG备忘录"NOR, ({ "board" }) ); 
     set("location", "/u/knpc/workroom"); 
     set("board_id", "knpc_b"); 
     set("long", "这里记载着一些著名BUG和未证实的BUG。\n" ); 
     setup(); 
     set("capacity", 100); 
     replace_program(BULLETIN_BOARD); 
}
