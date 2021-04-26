// Code of ShenZhou
// Room: /d/dali/garden4.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIB"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�������ʱʱ��
�۷������䡣��ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : HIB"���ɹ���
���ɹ������ǰ˶�軨����һ�꣬��ɫ������ͬ�����б�
�������Ϻ͵���ĸ�һ�䣬��������������ɹá�û��������
�ر���ɫ�ģ������ǰ˻���ɫҲ�������ǡ����ɹ������ˣ���
�����˱�ױ�����ʹ���һƷ��
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"garden5",
  "southeast" : __DIR__"garden2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
