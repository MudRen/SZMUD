// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
�����Ƿ�ɽ������š������������ɹ���������������һ����
����Ĵ���Ƿ�ɽ�����Ҫ�ֵ���
LONG
        );
        set("exits", ([
		"east" : __DIR__"street0",
		"west" : __DIR__"dlroad1",
	]));

	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
