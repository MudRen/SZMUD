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
��ͣ��СЪ��ʯ·�������ϺͶ������ߡ�
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
	"northeast" : __DIR__"santan3",
	"southeast" : __DIR__"santan1",
                 ])
       );
    setup();
    replace_program(ROOM);
}