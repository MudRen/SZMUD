// Code of ShenZhou
// Room: /d/dali/garden5.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", MAG"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�������ʱʱ��
�۷������䡣��ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : MAG"�糾����
�糾����������Ʒ�͸�Ʒ֮�֣�������Ʒ�����仨�б�����ɫ
�����������׿ɣ���ɫ�ߴ�֮�����������ɫ����С���
�ޣ����Ǻ��Ů������컨������ϻ��׻����Ǳ��Ǹ�Ʒ�ˣ����
�Ͳ�ö��ˡ�
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"garden3",
  "north" : __DIR__"garden6",
  "southwest" : __DIR__"garden4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
