// Code of ShenZhou
// /d/wanshou/mishi.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"
inherit ROOM;

void create()
{

        set("short", "����");
        set("long", @LONG
����ɽׯ��ׯ�����ʨ��ʷ������˵ĵط������ڲ��ü򵥣�
���࿿���ĵط�����һ�Ŵ�����ʷ��յ�����Ϣ�ĵط�������һ��
��һ��ҩ¯��һ��С������һ������Ϊ���˵���ׯ����ҩ��
LONG
        );

        set("exits", ([
                "west" : __DIR__"zhenting",
        ]));

        set("objects", ([
                __DIR__"npc/shugang" : 1,
        ]));

        set("cost", 0);

        setup();
        replace_program(ROOM);

}

