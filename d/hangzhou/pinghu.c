// Code of ShenZhou
// ƽ������
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", HIB"ƽ������"NOR);
    set("long", @LONG
ƽ������������ˮ������ͬ������ƽ�����С������ƽ���ƾ���
��ʱ�º����������������д������ҹʱ��µ��յ�������ɫ����
�����߱��Ƿź�ͤ�����������ǰ׵̡����߾��ǹ�ɽ��
LONG);
    set("exits", ([ /* sizeof() == 3 */ 
                   "northeast" : __DIR__"baiti", 
                   "northwest" : __DIR__"fanghe", 
                   "west": __DIR__"gushan1",
                ])
       );
        set("fjing", 1);
	set("cost", 2);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
