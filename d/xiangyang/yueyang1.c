// Code of ShenZhou
// Room: /d/xiangyang/yueyang1.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIM "һ¥" NOR);
	set("long", @LONG
����¥��¥ƽ��ʳ����Σ���ʮ���ף���ʮ���ף�¥���������ܣ�ͨ�߶�ʮ
�ף����ܿ�������ľ�ṹ�����滷�����ȣ���������ƽ̨������Ϊ��ɫ�����߶�
������Ϊ����״������¥�����ĸ���������������е񻨴�����������տ������
��ΰ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"yueyang",
  "up" : __DIR__"yueyang2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
