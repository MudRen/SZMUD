// Code of ShenZhou
// Room: /d/xiangyang/furencheng.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIC "���˳�" NOR);
	set("long", @LONG
�ഫ�����������꣬���ݴ�ʷ������������ʱ��ǰ�ش���ا�����������
ĸ�����˵ǳ�Ѳ�ӣ��������γǻ����ر���������Ů澺ͳ��ڸ�Ů�ڴ�����һ��
Լ��ʮ�׳����³ǡ�����ا������������ǣ������ƾɳǣ������³Ƿ��أ��Ż�
�˹���֮�С�Ϊ�˼��������һ���ͣ����ǽ���γ�ǽ����Ϊ�����˳ǡ���
LONG
	);
        set("coordinates", ([ "x" : -4, "y" : 5 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"beijie3",
]));
	set("no_clean_up", 0);
        set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
