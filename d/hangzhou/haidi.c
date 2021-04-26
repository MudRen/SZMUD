// Code of ShenZhou
// /d/hangzhou/haidi.c   ����
// by aln 2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{        set("short", "����");
         set("long", @LONG
����ü�ʮ�����˹������ĺ��̡���Ϊ��ˮ���࣬������������ٸ���
����Ա�񹤲����������̣����ڶ����Ȼ������������ﶼ�ǿ��������
����ʱ���˿۹��ò������������췴֮�ġ�
LONG	);

         set("exits", ([ /* sizeof() == 2 */ 
                   "east" : __DIR__"yantian",
                   "southwest" : __DIR__"village", 
         ]));

	 set("objects", ([
                __DIR__"npc/tbbz" : 2,
                
         ]));

	 set("cost", 1);
         set("outdoors", "hangzhou");

         setup();

         replace_program(ROOM);
}
