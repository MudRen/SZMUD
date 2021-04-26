// Code of ShenZhou
// /d/hangzhou/hsmiao.c   ������
// by aln 2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{        set("short", "������");
         set("long", @LONG
�����ǿ�����һ��С�𣬶�����һ��ͻ����ɽ��֮����һ�������ǰ��
���Լ�ɼ��ǡ����������֡��������Ǽ�ª�����س���������Ҳ����ף��
LONG	);

         set("exits", ([ /* sizeof() == 2 */
                   "southwest" : __DIR__"yantian",
                   "north" : "/d/jiaxing/field",
                 ])
         );

	 set("objects", ([
                __DIR__"npc/tyjz" : 1,
         ]));

	 set("cost", 1);
         set("outdoors", "hangzhou");

         setup();

         replace_program(ROOM);
}
