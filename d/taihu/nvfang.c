// Code of ShenZhou
//Kane

inherit ROOM;

void create()
{
	set("short", "Ů�᷿");
	set("long", @LONG
�����ǹ���ׯŮ���ӵ���Ϣ�ң����ż���ľ�������Զ���һ֧�߽�
���ӣ�����������ݽ�һ�ż��ʣ�����һ��������ɢ�ŵ������㡣
LONG
	);
	set("sleep_room", 1);
	set("no_fight", 1);

	set("exits", ([
		"east" : __DIR__"huating",
	]));
	set("cost", 1);
	set("outdoors", "taihu");

	setup();
	replace_program(ROOM);
}
