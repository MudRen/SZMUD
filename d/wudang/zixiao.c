// Code of ShenZhou
// zixiao.c ������
// by Fang
// xQin 11/00

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"����������"NOR);
	set("long", @LONG
�����ߵ���չ����£���ǰչ�ֳ�һ�����������ߴ�������䵱ɽ
��Ϊ���Ĺ�����������������ɽ�������ߵʹ������¡���Χ��ľɭɭ����
����֣���ɫ���ġ��������䵱ʦͽ����Ҫ�������
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"shijie3",
		"southup" : __DIR__"guangchang",
	]));


	set("cost", 1);
	setup();
	replace_program(ROOM);
}

