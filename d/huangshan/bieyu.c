// Code of ShenZhou
// �����
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "�����");
    set("long", @LONG
�����������״��һ�������εı����������ɽ�ϻ���һ������
���������󣬻��ǲ�Ҫ��ȥΪ������Ͼ͵��캣�ˣ������ǰٲ���
�ݡ�
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"down" : __DIR__"baibu",
	"northup" : __DIR__"tianhai",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
