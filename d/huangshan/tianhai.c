// Code of ShenZhou
// �캣
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "�캣");
    set("long", @LONG
�캣��ǰ���ᡢ�������ĺ����м䣬���ƱȽ�ƽ̹��ͻȻ�䣬��
��������������һɫ������Ϊ�캣��
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"southdown" : __DIR__"bieyu",
	"northwest" : __DIR__"feilai",
	"northeast" : __DIR__"guangmin",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
