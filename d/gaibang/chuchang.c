// Code of ShenZhou
// chuchang shi

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ؤ��Ĵ����ң�������ֻ�ܿ���һ�������ŵ����ӡ�
LONG
	);
	set("exits", ([
		"west" : __DIR__"mishi",
		"up" : __DIR__"undertre",
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}
