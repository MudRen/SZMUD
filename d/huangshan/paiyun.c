// Code of ShenZhou
// ����ͤ
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "����ͤ");
    set("long", @LONG
����������һʯͤ��������ͤ��ͤǰ������ʯ�����οͶ�������
�����������ɽ�Ĺȵ��澰��
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"southeast" : __DIR__"feilai",
	"east" : __DIR__"beihai",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
