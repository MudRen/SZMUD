// Code of ShenZhou
// ���ſ�
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "���ſ�");
    set("long", @LONG
���ſ��������춼���������֮�䣬����������ƣ�һ����ɽ֮
·�ʹ������д��ƶ�����
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"banshan",
	"up" : __DIR__"tiandu1",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
