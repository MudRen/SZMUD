// Code of ShenZhou
// Room: /d/dali/wuhua9.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����ͨ�����Ϸ������������ʱ��ס��������İ��������
������£����ϵ��˼��Ż�Ƥ����Ƥ��ǽ������һ����̴ľ�Ĵ�
���������Ϲ��˼����䵶��ǹ����֮�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"wuhua7.c",
]));
        set("objects", ([
__DIR__"npc/leader1" : 1,
        ]));

set("cost", 1);
	setup();
	replace_program(ROOM);
}
