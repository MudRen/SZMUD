// Code of ShenZhou
// RYU 1/5/97
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�ͷ���");
        set("long", @LONG
һƷ�ü�������������̰���ܻߣ��������ǣ���Ϸ��Ů֮��Ա����
���������ܵ�Ӧ�е��Ʋá����о޹���һƷ�õģ������������ܵ�����
���ʹͺ���Ρ�����������������ͷ�������
LONG
        );
        set("exits", ([
        ]));


        setup();
        set("outdoors","xixia");
        replace_program(ROOM);
}
