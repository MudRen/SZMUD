// Code of ShenZhou

inherit BULLETIN_BOARD;
#include <ansi.h> 

void create()
{
              set_name(HIW "˵������" NOR, ({ "board" }) );
             set("location", "/u/fanren/workroom");
                 set("board_id", "fanren_b"); 
        set("long", "���ǹ�����ʦר�õ����԰塣\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
