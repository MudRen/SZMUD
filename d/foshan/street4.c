// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "��ɽ���");
        set("long", @LONG
��ɽ��ֶ������������������ţ�����һ�¸�ǽ��ǽ�����
�����Ͽ��ġ�Ӣ�۵䵱����
LONG
        );
        set("exits", ([
		"south" : __DIR__"yxpawn",
		"east" : __DIR__"egate",
		"west" : __DIR__"street3",
	]));

	set("objects", ([
		"/d/city/npc/jiading" : 2,
		"/d/city/npc/wolfdog" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
