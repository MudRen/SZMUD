// Code of ShenZhou
// Room: /d/xiangyang/jieting.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIW "��ͤ" NOR);
	set("long", @LONG
����ͥԺ���ƹ��ο����������磬��װ��԰�ֵ¹�ʯȺ���������С�ī԰
�پ������Ʒ���һ���̽Ƿ��ܵ�Сͤ������ͤ��������ǰ��ͤǰ���С��׼�ɽ
ˮ���������Ϲ��Ρ�������ʯ�������ڹ���ʯ�����𣬳��������ϸ�����ƽ��
�顣Ժ���ı�Ƕ���������Ӽ���ͥ�ᡢ���塢���ϸ����˵��ּ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"migongci",
]));

	setup();
	replace_program(ROOM);
}
