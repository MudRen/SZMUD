// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ��СС��ɽ����Ѫ������Ĳ���֮�ء���춴˵�
�Ƚ����أ���Һ���Ѱ��������������һ�Ź��������湩��
ʲ�ᶫ�����㿴���塣
LONG
        );
        set("exits", ([
                "out" : __DIR__"cave1",
        ]));
	set("objects", ([
		"/d/qilian/npc/xlama" : 1,
                "/kungfu/class/xuedao/laozu" : 1,
        ]));

	set("cost", 2);
        setup();
}
/*int valid_leave(object me, string dir)
{
        if (dir =="out" ) {
        if (present("liu chengfeng", environment(me))
        ||present("liu chengfeng", me) ) 		
                return notify_fail("Ѫ��������������ȵ������з粻ɱ�����Ÿ�ʲ�᣿\n");
        return 1;
    }
        return ::valid_leave(me, dir);
        set("no_clean_up", 0);
}
*/
int valid_leave(object me, string dir)
{
        if (dir =="out" && this_player()->query_temp("jidao", 1) > 0)
        return
notify_fail("Ѫ�����淢��һ����Ц���˻�û����ɱ�꣬������ߣ�\n");
return ::valid_leave(me, dir);
set("no_clean_up", 0);

}

