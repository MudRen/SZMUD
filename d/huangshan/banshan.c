// Code of ShenZhou
// ��ɽ��
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "��ɽ��");
    set("long", @LONG
һ��СС�����������˷�����ɰ��֮�䡣������һ���ң�����
ɽ���οʹ���ڴ�����ͣ����һ����Ϣһ�߹�����Χ�羳��
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"southdown" : __DIR__"lima",
	"northeast" : __DIR__"tianmen",
	"northwest" : __DIR__"xiaoxin",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
