// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����������ɽ����Ե�����������������������ƽԭ���������ţ�����
�����ء������ɽ��������ɽ�ƵͰ����ټ���ͨɽ���̣��ļ����䣬�ʶ���
����
LONG
        );
        set("exits", ([
                "west" : __DIR__"jiayuguan",
                "northdown" : __DIR__"yumen",
                "eastup" : __DIR__"qitian",
        ]));


	set("cost", 4);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
