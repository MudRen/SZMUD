// Code of ShenZhou
// ���˶�
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "���˶�");
    set("long", @LONG
ʯ·�Ա���һ�����ഫ������֮ҹ���������еƣ����������¡���
�ʵ������˶���ǰ��·����һ��ͤ����ʤͤ���ο��Ƿ׷�����СЪ
���������ܾ�ɫ��
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"southdown" : __DIR__"yungu",
	"northup" : __DIR__"xianrenz",	
		 ])
	 );
    setup();
    replace_program(ROOM);
}
