// Code of ShenZhou
// �����
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
�ܵ��������Ǿ�ͷ��ǰ���ƺ���һ�߹�����
LONG
        );

	set("exits", ([
		"westup" : __DIR__"jaderoad9",
		"out" : __DIR__"feicui",
	]));

	set("cost", 1);
	setup();
}
