// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "�ּ��");
        set("long", @LONG
������һ���ּ�С���������������ѡ������ǹ����ˡ�����ɽ��ï
�ܣ�������棬��λ��·Ҫʮ��С�ġ�
LONG
        );
        set("exits", ([
		"east" : __DIR__"dlroad2",
		"northwest" : __DIR__"dlroad4",
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}