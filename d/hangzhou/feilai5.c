// Code of ShenZhou
// ������
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "��΢ͤ");
    set("long", @LONG
��΢ͤ���ڷ�����İ�ɽ�䣬������������Ϊ�������ɶ����ġ�
�����С����곾�������£�����Ѱ���ϴ�΢����ʫ�䣬��ͤ������΢����
��������ɽ��·��
LONG);
    set("exits", ([ /* sizeof() == 1 */ 
        "westdown" : __DIR__"feilai4", 
                 ])
       );
	set("cost", 1);
    setup();
    replace_program(ROOM);
}