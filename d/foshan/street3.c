// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "��ɽ���");
        set("long", @LONG
����ڷ�ɽ������һָ�Ĵ󻧣���ҵļҶ���ǣ���ǹ�����
���һ��İ���ֻ������͵����·���м��ձ������̣����洫
������������
LONG
        );
        set("exits", ([
		"east" : __DIR__"street4",
		"west" : __DIR__"street2",
		"north" : __DIR__"shaobing",
	]));

	set("objects", ([
		__DIR__"npc/zhong2" : 1,
		"/d/city/npc/wolfdog" : 2,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
