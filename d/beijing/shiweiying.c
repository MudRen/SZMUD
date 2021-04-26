//Cracked by Roath

// Room: /d/beijing/shiweiying.c

inherit ROOM;
#include "beijing_defs.h"

void create()
{
        set("short", "����Ӫ����");
        set("long", @LONG
�����Ǿ��������ǵĵ��̡�������Ȼ���������󳼸��ڵĺ���
���£���Ҳ�Ǻ��������ġ�������ƽ������������ǰ����ߵ����
�ɶ���С�Ľ��������������Ǿ���Ц����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"jiaochang",
        "south" : __DIR__"dongzhidajie",
        ]));

        set("objects", ([
        __DIR__"npc/shiwei3":2,
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
