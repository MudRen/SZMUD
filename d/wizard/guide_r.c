// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"大图书馆"+NOR);
        set("long",
 "这里是汇集各种编程资料和向首席开发神仙提问的房间，室内布置着一式红\n"
+"木家具，桌上放着文房四宝，靠壁的柜架满是古玩摆设和书籍，在宫灯映照下，\n"
+"墙的一壁还挂着一副对联：\n\n"
+HIW+"                          五伦之中自有乐趣\n\n"
+"                          六经以外别无文章\n\n\n"+NOR);
        set("exits", ([ 
                  "out" : "/d/wizard/meeting_room",

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        "/clone/board/mudlib_b"->foo();
        call_other("/clone/board/guide_b", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
