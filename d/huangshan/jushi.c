// Code of ShenZhou
// ����ʯ
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "����ʯ");
    set("long", @LONG
һ���ʯ���������ͷ������ҽ��������㲻�ɵõ���һ��������
��Ҫ�������Ǵ�ʯ�ֲ����ˡ�ԭ���Ǿ�ʯ��һ��Ͽ�ȼ��ţ�û��������
ϸ����ʯ�ϻ����������֡�����ʯ�����Ա�ʯ�����ֿ������֡�����
�ԡ�����ʯ������һ����������Ҫ��(zuan)�ˡ�
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"penglai",
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
   me->move(__DIR__"wenshu");
}
