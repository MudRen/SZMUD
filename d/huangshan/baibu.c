// Code of ShenZhou
// �ٲ�����
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "�ٲ�����");
    set("long", @LONG
����һ�ٶ༶ʯ�㣬��һ�п����ͱ��ϵĳ��ݡ�����������ӿ��
���ݷ·��������֮�С��������͵��˱���塣
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"up" : __DIR__"bieyu",
	"south" : __DIR__"lianhua",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
