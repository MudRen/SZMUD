// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�׳ƴ��ã���������ǧ���ˡ������������л�����Ժ�ܷ�̨�ķ�����
�������๱�����ڿ��͡��˴�ʥ�ߡ��͸�����ľ��ʦ�񡣵�����������ͷ׵�
��ᦣ����ǣ����ܵ�ľ���Ϲ���ɫ��Ѥ����ձ̺��
LONG
        );
        set("exits", ([
                "east" : __DIR__"yanwu",
                "north" : __DIR__"sengshe",
        ]));
	set("objects",([
        "d/qilian/obj/fojing1" : 1,
        ]));

	set("cost", 0);
        setup();
        replace_program(ROOM);
}

