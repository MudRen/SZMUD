// Code of ShenZhou
// Room: /d/shaolin/mishi.c
// Date: kane 98/03/26

#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�����õ���Ϊ�����С���䣬�˴�������صף���
����ȴʮ�����£�����Ҳ�ܳ��㡣�ط���Ȼ�������м�ʲҲ��
�࣬�����ڷŵþ���������˿�������ִ١�
LONG
	);

	set("exits", ([
		"up" : __DIR__"andao2",
	]));

        set("objects", ([
                 "/d/shaolin/npc/chengkun" : 1,
	]));

	set("cost", 1);
	setup();
}
