// Code of ShenZhou
// Room: /d/dali/garden6.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�������ʱʱ��
�۷������䡣��ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : GRN"������
�����ţ�����ʮ�߶䲻ͬɫ�Ĳ軨����һ�꣬������ɫ��
��ʮ��ѧʿ����һɫ��ƫ���ǲ�����������������ٻ��磬����
�д���С��������ʩЧ򭣬ѧ��ʮ��ѧʿȴ��ѧ�������Ǿͱ�
�����ˡ������š���
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"garden8",
  "south" : __DIR__"garden5",
  "east" : __DIR__"garden7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
