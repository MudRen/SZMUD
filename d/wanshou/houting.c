// Code of ShenZhou
// /d/wanshou/houting.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����������൱���Ƕ�ׯ���ܼ���ʷ������ͽ֮����������
���ǽ���ϻ��Ż���ʨ������ֶ�����Ϸ������ͼ�Σ�����������
����ɽׯ�ĵ������۾�����ؿ���ͼ����ĥ��ʲô��
LONG
        );
        set("exits", ([
                "south" : __DIR__"zhenting",
                "east" : __DIR__"bedroom",
        ]));

	    set("cost", 0);
        setup();
        replace_program(ROOM);

}
