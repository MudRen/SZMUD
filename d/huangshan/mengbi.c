// Code of ShenZhou
// �α�����
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "�α�����");
    set("long", @LONG
ɽ·����һ��ʯ���������ɺ��һ����ɴ�ʯ��������������
ʯ���ǡ��ʸˡ��������ǡ���ͷ������һ�澰���������α���������
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"eastup" : __DIR__"shixin",
	"southdown" : __DIR__"xianrenz",
	"northeast" : __DIR__"beihai",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
