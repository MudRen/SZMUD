// Code of ShenZhou
// Room: /d/dali/garden2.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", RED"�軨԰"NOR);
	set("long", @LONG
�⻨԰��ˮ��һ�Ŵ���֮��һ�ԴԻ���ӳˮ���죬����
��ϼ��һ����ȥ�����Ǻ���ͷ׵Ĳ軨�����ƺ�������������
�޼�Ʒ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"garden3.c",
  "out" : __DIR__"garden1.c",
  "northwest" : __DIR__"garden4.c",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
