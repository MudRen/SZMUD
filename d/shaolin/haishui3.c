// ROOM: /d/shaolin/hanshui3.c
// Jiuer /8/2001

#include <ansi.h>
#include "d/shaolin/npc/yaoshui.h";inherit ROOM;

void create()
{
        set("short", "��ˮ����");
        set("long", @LONG
�����Ǻ�ˮ���ߣ���Ϊ����ƽ̹������Ե�ʣ������ˮ���Եû���
����࣬��������ĺ�ˮ����ȥ�峺�ɾ��������ǵľ���������
��ˮ�ȣ����߻��м���ũ�帾Ů����ϴ�·���
LONG );

        set("exits", ([ /* sizeof() == 2 */
                "east" : __DIR__"hanshui2",
                "northup" : __DIR__"shanlu1",
                ]));

        set("cost",0);
        set("outdoors", "shaolin");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


