// Code of ShenZhou
// Room: /d/dali/wangfu8.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long","�������ã�̧ͷӭ���ȿ���һ����������ش��ң�����д�����������֣�
�ǣ��������á������С����巺���֮��������̴��󤰸(desk)��������������
���̹Ŷ���������©�泯ī���󻭣�һ���ǽ�׶�ͣ�һ���ǲ����У���������ʮ
������̴���Σ�����һ������������ľ���ƣ������������ּ�������
������������������"HIW"�������������£���ǰ�������ϼ��\n"NOR
);
	set ("item_desc", ([
		"desk" : "���ϰڷ��˺ü����飬���з�ѧ���ģ�Ҳ�е��ҵ伮������һ���׾���\n"])) ;
	set("objects", ([
		"/kungfu/class/dali/zhengchun" : 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"wangfu9",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
