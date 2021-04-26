// Code of ShenZhou
// Summer 9/12/96

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�ϰ���");
        set("long", @LONG
�ϰ���������ɽ��������Сɽ�壬���羰���ѡ���ɽСϪ��������ɽ��
�������С���ɽʢ��һ����ɫɽ�����ļ���л���ഫ�����ϵ��������֣���
�Զﴫ������ϰأ���ʵɽ��һ�Ű���Ҳû�С�
LONG
        );

        if( !random(10) ) {
                set("objects", ([
                        "/d/changbai/npc/jiao2" : 1,
	        ]));
        }

        set("exits", ([
                "westup" : __DIR__"qitian",
                "northeast" : __DIR__"ailao",
		"east" : __DIR__"tieshi",
                "northup" : "/d/kunlun/zhenyuanqiao",
        ]));


	set("cost", 3);
        set("tjjob", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
