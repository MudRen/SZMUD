// Code of ShenZhou
// ʯ��
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "ʯ��");
    set("long", @LONG
������һ��������ܹ�ʯ����������߱߿�����һ������ϻ�
���򡱣���һ���ֺ��񡰹ع����ܡ�����һ���ǡ������𡱣�����
ǰ���ǡ�̫����ơ��������޲�ά��άФ��������ܡ�
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"up" : __DIR__"shijie2",
	"down" : __DIR__"shijie4",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
