// Code of ShenZhou
// ��������
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "��������");
    set("long", @LONG
������������ֻ�������β���Сʯ�壬��������ͦ�Σ�����
�ӻ���䣬�纣���İ����ʵ��������������ϱ�ʯ������һ��ʯ�죬
����ͨ����ֻ����(zuan)��ʯ�졣
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"jushi",
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
