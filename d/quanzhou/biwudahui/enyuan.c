// Code of ShenZhou
// enyuan ��Թ��
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Թ��");
	set("long", @LONG
�߽����У��͸е�һ����ɱ֮���������ܡ�����һ�����������顸��
Թ�������ĸ����֣���ϸһ��������ָ���̻����ɣ���������������µ�
��̨�ˡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"leitai_gate",
		"south" : __DIR__"citong_e2",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
