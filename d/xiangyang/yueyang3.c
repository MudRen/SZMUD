// Code of ShenZhou
// Room: /d/xiangyang/yueyang3.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIW "��¥" NOR);
	set("long", @LONG
��¥�����ɽȺ�徹�㣬������������ˮ�������ƣ��̲��Ӵ����羰��
�ѣ�Ϊ������¥֮һ�����С���ͥ����ˮ����������¥����ʢ������¥�����С�
³��������������˵��ǡ��������»���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"yueyang2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
