// Code of ShenZhou
// ������
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "������");
    set("long", @LONG
����嶥�����С��������ء�֮�У�ң���ķ���ǧ�徺�㣬����
����������ʤ�ա�������ɶ�����Ŀ����հ��®�������Ż��ͳ�����
��������ݹ�����˷����ƺ����ޱ�׳�ۡ��������������ʯ(stone)
�͵��˰ٲ����ݡ�
LONG);
    set("item_desc", 
    	([
      	"stone" : 
		"�����ʯһ����ǧ���Ϲ꣬��һ��������˯�ĳ��ߡ�\n"
   	])
	);

    set("exits", ([ /* sizeof() == 2 */
	"down" : __DIR__"yanwang",
	"north" : __DIR__"baibu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
