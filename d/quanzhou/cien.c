// Code of ShenZhou
// cien.c �Ͷ���
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�Ͷ���");
	set("long", @LONG
�����ʯ���࣬������Ƭ��������ţ��з������á����������ȡ���
ʯȺ�����������ʯ��Ȼ�����ʹ�����γ�һ����Ȼʯ�ң��Ͽ̡���ɽ��ֹ����
�ݳ�������ҶȪ�ݵĽ�ʿ�뺫����½�޵�ͬ�ǡ������񡹵�ŷ��ղ�Ķ������
�ҡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northdown" : __DIR__"shanlu4",
		"southdown" : __DIR__"shanlu5",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

        set("fjing", 1);
        set("cost", 3);
        setup();
	replace_program(ROOM);
}
