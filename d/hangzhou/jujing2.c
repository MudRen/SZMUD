// Code of ShenZhou
// �۾�԰
// Dong  11/03/1996.
// nta:  Need to as some npc here.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", HIM"�۾�԰"NOR);
    set("long", @LONG
����԰�У�ֻ���������ô������������У����˲��ٱ��ҡ�����
��ů֮ʱ���������ǧ������˿�����̽��벻ʤ������ʫ��������
�ġ��Һ���׽Կ�ã���ô����෢�ӡ����ݵ�ǡ���ô�����������
���ţ����������������š�
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
                   "northeast" : __DIR__"jujing3", 
                   "east" : __DIR__"jujing1", 
                 ])
       );
	set("objects",([
                "/d/taishan/npc/jian-ke" : 1,
        ]));
       set("fjing", 1);
	set("cost", 1);
    setup();
    replace_program(ROOM);
}
