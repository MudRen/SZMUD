// Code of ShenZhou
// �����
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����ͨ��");
	set("long", @LONG
һ��������ͨ�������ܰ������ӳ�����Ӱ�ӡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"jaderoad1",
		"north" : __DIR__"jaderoad3",
	]));

	set("cost", 1);
	setup();
}
