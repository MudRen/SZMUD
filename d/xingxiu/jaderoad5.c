// Code of ShenZhou
// �����
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����ſ�");
	set("long", @LONG
���ǰ��������ſڣ�ֻ������е������Ǻ��ǣ�����ɢ
����һ�أ��������ձ����й�һ����ս��
LONG
        );

	set("exits", ([
		"north" : __DIR__"jadehall",
		"south" : __DIR__"jaderoad4",
	]));

	set("cost", 1);
	setup();
}
