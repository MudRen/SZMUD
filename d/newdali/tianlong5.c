// Code of ShenZhou
//zyz /12/13/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ�����������ӣ�����ǽǰ����һ����ɮ��������ڡ� ����
������Ӧ�˻찵�Ĺ��ߣ����ƺ�����ǽ�ϻ���Щͼ��
LONG
        );

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

