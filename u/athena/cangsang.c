// Room��/u/athena/renwu.c

#include <room.h> 
inherit ROOM;

void create()
{
        set("short", "������ɣ");
        set("long", @LONG
һ��ʮ�ְ�����չ���ݣ�������һ�������򱡵��顣�е�ֽ���Ѿ����ƣ���
�Ŀ����������¡������Ķ�Թ���Ѫ���ȷ������ﶼ��Ϊ���еĹ��£���Цŭ��
���ɺ�����˵��
LONG
        );
        set("no_fight",1);
        set("exits", ([
                "south" : __DIR__"dating",
        ]));
        setup();
}
