// Code of ShenZhou
// /d/hangzhou/yantian.c   ����
// by aln 2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{        set("short", "����");
         set("long", @LONG
�������㶫Ǯ�����뺣�ڣ�������һƬƬ�⻬�羵��ƽ�أ������߰��ɼ�
��������ˮĥ������Ҳ�޴�ƽ������Ǿ������������������ˮ�������
ɹ���Ժ󣬹��º�������������±ˮ������ɹ��������
LONG	);

         set("exits", ([ /* sizeof() == 2 */ 
                   "west" : __DIR__"haidi", 
		   "northeast" : __DIR__"hsmiao",
         ]));

	 set("objects", ([
                __DIR__"npc/hsbz" : 1,
                
         ]));

	 set("cost", 1);
         set("outdoors", "hangzhou");

         setup();

         replace_program(ROOM);
}
