// Code of ShenZhou
// ������
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "������");
    set("long", @LONG
��һ��ɽ·�����ޱȣ��ʵô������������ڵ��ο������������
�������е���ľ������������ھͿɵ��������ˡ��������������塣
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"up" : __DIR__"lianhua",
	"eastup" : __DIR__"niubi",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
