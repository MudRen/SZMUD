// Code of ShenZhou
// ���㱳
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "���㱳");
    set("long", @LONG
���㱳������Ԩ�����������һ�챡��ʯ�ڣ���ƽ�⻬��ͬ�㼹��
�������治��������Ҫ�ľ���ս��ͷ��Ŀѣ������������Ԩ�����Ʒ�
�ɣ����罭��ŭ�Ρ�
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"down" : __DIR__"tiandu1",
	"up" : __DIR__"tiandu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
