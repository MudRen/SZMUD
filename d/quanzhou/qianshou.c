// Code of ShenZhou
// qianshou.c ǧ����
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ǧ����");
	set("long", @LONG
��ɽ·���ϣ�����ǧ���ҡ�����ÿ���ﶬ��ɽ��Ҷ����������ɷ�Ǻÿ���
����һ�£��ڹ���������һ����ǰ����ͦ�Σ��º��ʯ��ᾣ�����һ�����¡�
���Ծ���������ɮ��һ��ʦ��Ĺͤ��Ĺͤ�ߵ���ʯ�Ͽ���������ʱд�ġ�����
�������ĸ��֡�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northup" : __DIR__"laojun",
		"southeast" : __DIR__"mituo",
	]));

	set("objects", ([
		CLASS_D("gaibang") + "/zhao-gouer" : 1,
	]));
        set("fjing", 1);

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 3);
        setup();
	replace_program(ROOM);
}
