#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIW"��ʷ���Ͽⷿ"NOR);
        set("long", @LONG
����һ��ܴ�ܴ�Ĵ���������������ɽ�ƺ�������. �ƺ��ܾ�û������������,
�ܶ൵���϶�����һ�ɺ��Ļ�.
LONG);
        set("exits", ([
"up" : "d/city/wumiao",
]));
    setup();
              set("no_fight", "1"); 
              set("no_steal", "1"); 
              set("no_sleep_room", "1"); 

 call_other("/clone/board/trans_b", "???");  
}
