// Code of ShenZhou
// �յ�
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "�յ�");
   set("long", @LONG
�յ���ʫ���ն��������ֿ�������ʱ�ú���Ͳ����ɵġ��ն���
����ʫ�������£�������Ǯ���غ��ˣ����ʿŮ�����ᡣ���ź����
���ϣ���ɽʼ������ͨ��������ʮ�����ɣ�����ϯ����̿ա�������
���Ǵ����������ӳ���š�ӳ�������յ������������ϵĵ�һ����
LONG        );

   set("exits", ([ /* sizeof() == 3 */ 
                  "south" : __DIR__"road73", 
                  "north" : __DIR__"suti6", 
                ])
       );
	set("objects",([
                "/d/taishan/npc/shu-sheng" : 1,
        ]));
   set("fjing", 1);
	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
