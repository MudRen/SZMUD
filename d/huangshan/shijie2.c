// Code of ShenZhou
// ʯ��
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "ʯ��");
    set("long", @LONG
����ʯ���ϣ�������ܿ�����ɽ���е����ɹ�ʯ������ʮ�˵���
�ᣬӭ����һ��������ص�ɽ�塣��̫��һֻ�����ˣ����ӣ��۾���
��Ͷ������һ����
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"up" : __DIR__"shijie1",
	"down" : __DIR__"shijie3",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
