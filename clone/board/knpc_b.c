inherit BULLETIN_BOARD; 
#include <ansi.h> 
void create() 
    {    
     set_name(HIG"BUG����¼"NOR, ({ "board" }) ); 
     set("location", "/u/knpc/workroom"); 
     set("board_id", "knpc_b"); 
     set("long", "���������һЩ����BUG��δ֤ʵ��BUG��\n" ); 
     setup(); 
     set("capacity", 100); 
     replace_program(BULLETIN_BOARD); 
}
