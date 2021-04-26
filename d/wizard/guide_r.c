// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"��ͼ���"+NOR);
        set("long",
 "�����ǻ㼯���ֱ�����Ϻ�����ϯ�����������ʵķ��䣬���ڲ�����һʽ��\n"
+"ľ�Ҿߣ����Ϸ����ķ��ı������ڵĹ�����ǹ��������鼮���ڹ���ӳ���£�\n"
+"ǽ��һ�ڻ�����һ��������\n\n"
+HIW+"                          ����֮��������Ȥ\n\n"
+"                          ���������������\n\n\n"+NOR);
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
