// Code of ShenZhou

inherit BULLETIN_BOARD;
#include <ansi.h> 

void create()
{
             set_name(HIG+"��"+HIM+"��"+HIC+"��"+HIR+"��"+NOR, ({ "board" }) );
            set("location", "/u/hap/workroom");
                 set("board_id", "hap_b"); 
        set("long", "���ǹ�����ʦר�õ����԰塣\n" );
        setup();
        set("capacity", 900);
        replace_program(BULLETIN_BOARD);
}
