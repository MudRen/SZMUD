// Code of ShenZhou
// chu@xkx 7/27/98

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
����ǰͻȻһ�����˴���������أ����ߴ��׸׵ײ���һ��С��͸�룬����
�������쾮����������һ����ɽ��Ժ�����������һ�ھ�(well)�������ƺ���һ
�������á�
LONG
        );
        set("exits", ([
                "out" : __DIR__"minwu1",
                "north" : __DIR__"ft_datang",
        ]));
        set("item_desc", ([
                "well" : "����д�ţ�������Ȫ����\n"
        ]));
        set("resource/water", 1);
        set("invalid_startroom", 1);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
