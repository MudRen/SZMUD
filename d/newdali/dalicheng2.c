// Code of ShenZhou
// Room: /d/dali/dalicheng2.c

inherit ROOM;

void create()
{
	set("short", "̫�ͽֿ�");
	set("long", @LONG
�������������߾ͱ�ɴ�ʹ������ˣ��Ǵ�����ڵ���Ҫ�ֵ���ͨ��ȫ��
��Ȼ�Ĵ����ʯ�̳ɡ������������ﲻ����������߱�ֲ�ɰأ���Ŀ�Դ䡣
LONG);
	set("exits", ([
		"south" : __DIR__"dalicheng9",
		"north" : __DIR__"dalicheng1",
		"east" : __DIR__"dalicheng5",
		"west" : __DIR__"dalicheng3",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
