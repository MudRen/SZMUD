// Code of ShenZhou
// ������
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "���ֶ�");
    set("long", @LONG
�ֽ��ϻ�����ֻ�����ҵ������ӣ�����������������С�𡣶���
������ϻ�����һ�顰®���Ƿ�ᡱ�������Ͽ̻�ͷ�裬�м�����
����Ĳ�ᣬ���ҷ������⣬���ͣ���������������������ɽ��·��
С·���������򶫡�
LONG);
    set("exits", ([ /* sizeof() == 2 */ 
       "westdown" : __DIR__"feilai0", 			
       "eastup" : __DIR__"feilai5", 			
                ])
       );
	set("cost", 3);
    setup();
    replace_program(ROOM);
}