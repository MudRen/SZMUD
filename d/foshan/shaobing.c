// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "�ձ�������");
        set("long", @LONG
����ձ����������¿��ŵġ����治�����������һ����ը
����һ����¯��
LONG
        );
        set("exits", ([
		"south" : __DIR__"street3",
	]));

	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));
	setup();
        replace_program(ROOM);
}
