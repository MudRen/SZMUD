// Code of ShenZhou
// ����
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "����Ȫ");
    set("long", @LONG
ֻ��Ȫˮ��ɳ���������������峺���ס��ഫ��λ�����Կյĺ�
�����ɽ�羰���㣬��ס������������ˮԴ��ȱ��׼��Ǩ�ߡ�һҹ��
���������˵��������ɽͯ��Ȫ����ǲ�������������ڶ��죬��Ȼ��
����ֻ�ϻ��ܵ���Ѩ��ӿ��Ȫˮ�����Զ���Ϊ������Ȫ����
LONG);
    set("resource/water",1);
    set("exits", ([ /* sizeof() == 2 */ 
                  "east" : __DIR__"road77", 
                 ])
       );
	set("cost", 2);
        set("outdoors", "hangzhou");
        set("fjing", 1);
    setup();
    replace_program(ROOM);

}
