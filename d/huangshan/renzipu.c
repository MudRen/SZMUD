// Code of ShenZhou
// ������
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "������");
    set("long", @LONG
һ����ͬ���ֵİ������������ƺ���ɰ����֮�䣬�������ף���
������֮�⡣������ֻ���ٴ��м��������ݰ�ĵŵ���
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"wenquan",
	"west" : __DIR__"minghong",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
