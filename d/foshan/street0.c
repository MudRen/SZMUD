// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "��ɽ���");
        set("long", @LONG
��ɽ��ֵ�ƽ���������������ţ�������һ��������������ΰ��
�ô�һ��������
LONG
        );
        set("exits", ([
		"north" : __DIR__"beidi",
		"east" : __DIR__"street1",
		"west" : __DIR__"wgate",
	]));

	set("objects", ([
		"/d/city/npc/jiading" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
