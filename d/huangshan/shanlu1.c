// Code of ShenZhou
// ɽ·
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "ɽ·");
    set("long", @LONG
ɽ·������üë����̶����¯�ȷ��ɽ�����·ɽ�Ͽ������
δ������ɽ��������ԼԼ�����������˿�����֮������ͣ����ϸһ
����ԭ������ɽ������ȸ������������
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"baizpu",
	"northeast" : __DIR__"yungu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
