// Code of ShenZhou
// Room: /d/dali/esqiao.c

inherit ROOM;

void create()
{
	set("short", "��ˮ��");
	set("long", @LONG
һ�������ಽ����ʯ�š����ź���ˮ�������¹سǺʹ���ǣ������峺��
��ˮ������ȥ���ű������¹سǵĳ��ţ�����һ·����ʮ���Ｔ�ɵ�����ǡ�
LONG);
	set("exits", ([
		"southeast" : __DIR__"gaten1",
		"north" : __DIR__"xiaguan",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
