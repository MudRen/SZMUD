// Code of ShenZhou
// һ����
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "һ����");
    set("long", @LONG
һ�������ƶ˵Ķ��ڵ�ס��·���ڶ����Աߣ�����������������
һ��Ħ�����ɵ���ʯ��������粢�У�����δ�ϣ�����ͨ����ֻ����
(zuan)��ʯ�졣
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"xiaoxin",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
void init()
{
   add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{
   if ( arg )
      return notify_fail( "ʲô��\n");
   me->move(__DIR__"yixian2");

}
