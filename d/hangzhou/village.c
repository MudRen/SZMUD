// Code of ShenZhou
// /d/hangzhou/village.c   ţ�Ҵ�
// by aln 2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{        set("short", "ţ�Ҵ�");
         set("long", @LONG
Ǯ�����ƺƽ�ˮ������ҹҹ�������ݵĴ��ٰ�ţ�Ҵ���ƹ��������뺣��
����һ����ʮ���ڰ�����Ҷ���ƻ��հ�졣��ǰ����Ұ�ݸ���ʼ��ƣ�����
�˼��������������������Χ��һ�Ѵ�������ŮŮ��ʮ����С�������Ծ۾�
���������һ������������˵�����嶫ͷ����һ���ƾ��������ǾƵ�ģ����
LONG	);

         set("exits", ([ /* sizeof() == 2 */
                   "northeast" : __DIR__"haidi",
                   "east" : __DIR__"jiudian",
                   "west" : __DIR__"road78",  
                 ])
         );

	 set("objects", ([
                __DIR__"npc/yang" : 1,
                __DIR__"npc/guo" : 1,
         ]));

	 set("cost", 1);
         set("outdoors", "hangzhou");

         setup();

         replace_program(ROOM);
}
