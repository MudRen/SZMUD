// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "�ּ��");
        set("long", @LONG
������һ���ּ�С���������������ѡ����������������ɽ��
����ͨ�򸣽�Ȫ�ݡ�
LONG
        );
        set("exits", ([
		"west" : __DIR__"egate",
		"east" : __DIR__"qzroad2",
	]));

	set("objects", ([
		__DIR__"npc/chaotang" : 1,
		__DIR__"npc/zhangkang" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
