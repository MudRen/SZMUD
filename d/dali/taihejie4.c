// Code of ShenZhou
// Room: /d/newdali/taihejie4.c

inherit ROOM;

void create()
{
	set("short", "̫�ͽֿ�");
	set("long", @LONG
������������ֱͨ�ʹ����ţ��Ǵ�����ڵ���Ҫ�ֵ���ͨ��ȫ��
��Ȼ�Ĵ����ʯ�̳ɡ������������ﲻ����������߱�ֲ�ɰأ���Ŀ
�Դ䡣
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"south" : __DIR__"taihejie2.c",
		"north" : __DIR__"taihejie5.c",
		"east" : __DIR__"road8.c",
		"west" : __DIR__"shegu.c",
		]));
	set("no_clean_up", 0);

	setup();
}
