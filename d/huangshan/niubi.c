// Code of ShenZhou
// ţ�Ƿ�
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "ţ�Ƿ�");
    set("long", @LONG
ţ�Ƿ��µ�ɽ·����һ���ɡ�������ɵ�֦�˼����ڶ�����������
չ������ƽ��������ǡ�����ţ��ʵ��������ɡ�
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"westdown" : __DIR__"yanwang",
	"eastup" : __DIR__"wenshu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
