// Code of ShenZhou
// �����Ժ
// modified by aln  2 / 98

// NTD:  NPC and object. 

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{       set("short", "��Ȫ��Ժ");
        set("long", @LONG
��Ժ������һ�ҡ���Ȫ��Ժ������Ժ��������λ���ߣ���������
��ʫ���ԡ��������Ե�����������ֽ�ͱ�ī��
LONG);

        set("objects", ([
                __DIR__"npc/gu" : 1,
                
        ]));

        set("exits", ([ /* sizeof() == 1 */ 
                   "east" : __DIR__"yuquan", 
        ]));

	set("cost", 1);

        setup();
        replace_program(ROOM);
}
