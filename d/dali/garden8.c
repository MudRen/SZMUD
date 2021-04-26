// Code of ShenZhou
// Room: /d/dali/garden8.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIR"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�������ʱʱ��
�۷������䡣��ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : HIR"�۶���
һ���׻������������������魺˶�״�ڰߵģ��������۶�
�ġ����������ڰߣ���������˶������ۡ�
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"garden9",
  "east" : __DIR__"garden6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
