//Cracked by Roath
// Room: /d/beijing/jiaochang.c

inherit ROOM;
#include "beijing_defs.h"

void create()
{
        set("short", "У��");
        set("long", @LONG
�����������������ĵط����㳡�����в���������������
վ׮��������ͷ���м�Ѳ�ӣ���ʱ��ָ�����ǡ������᷿������
�ǳԷ�˯���ĵط����������ܹܰ칫֮����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "east"  : __DIR__"shiwei_shitang",
        "west"  : __DIR__"shiwei_junying",
        "north"  : __DIR__"shiwei_office",
        "south" : __DIR__"shiweiying",
        ]));

        set("objects", ([
        __DIR__"npc/shiwei4":1,
        __DIR__"npc/shiwei5":1,
        __DIR__"npc/shiwei_jiaotou":1,
        ]));
 
        set("no_clean_up", 0);
        set("cost", 2);
 
        setup();
}

int valid_leave(object me, string dir)
{
    if (dir == "enter") {
	if (!IS_SHIWEI(me) && !wizardp(me)) {
	    if (present("shiwei", environment(me))) {
		return notify_fail("�űߵ��������ְ������ס�ˡ�\n");
	    }
	}
    }
    return ::valid_leave(me, dir);
}
