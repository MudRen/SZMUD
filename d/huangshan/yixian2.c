// Code of ShenZhou
// һ����
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "һ����");
    set("long", @LONG
ʯ���У���ɭɭ�������ӽ������룬������;�������˵�����ʯ
��ͻȻ����һ�𣬰��˼������ࡣ�������Ͽ���һ�����⵽��������
��һ����ɫ�������ޱ���������죬������һ����ϸ�ֳ������ߡ�
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"yixian1",
	"north" : __DIR__"penglai",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
void init()
{
   add_action("do_ji","ji");
   add_action("do_ji","��");
}

int do_ji(string arg)
{
}
