// Code of ShenZhou
// ��̶ӳ��
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "�ص�ʯ·");
    set("long", @LONG
ʯ���Դ����������������沨�����ԣ�ɽɫ�����������οͶ���
��ͣ��СЪ��ʯ·�������������������ߡ�
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
	"northwest" : __DIR__"santan3",
	"southwest" : __DIR__"santan1",
                 ])
       );
    setup();
    replace_program(ROOM);
}