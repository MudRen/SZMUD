// Code of ShenZhou
// Room: /d/xiangyang/yueyang2.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY "��¥" NOR);
	set("long", @LONG
��¥����������ƴ�ʫ����ס��Ÿ����׾��ס����������ڴ��κ���¥����
��ʫƪ�����������꣬���Ӿ��ذ���ʱ���ޣ�������׫������¥�ǡ������鲢ï
�����С�������֮�Ƕ��ǣ�������֮�ֶ��֡����䣬ǧ�Ŵ��̣�����¥��֮����
��������¥�������Ƕ��һ��������׫������¥�ǡ�(ji)��ľ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"yueyang1",
  "up" : __DIR__"yueyang3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
