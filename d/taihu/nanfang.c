// Code of ShenZhou
//Kane

inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @LONG
�����ǹ���ׯ�е��ӵ���Ϣ�ң����ż���ľ�������Զ���һ֧
�߽ż��ӣ��������������һ��С���������ǻ�԰��
LONG
	);
	set("sleep_room", 1);
        set("no_fight", 1);

	set("exits", ([
		"west" : __DIR__"huating",
	]));
	set("cost", 1);
	set("outdoors", "taihu");

	setup();
	replace_program(ROOM);
}
