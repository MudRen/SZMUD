// Code of ShenZhou
// chaoan1.c ɽ��
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��");
	set("long", @LONG
������������ɽ����ˬ��ɽ���У�������һ����Ժ����ǰ�Ķ���д�ţ�

������������������������ʤ������ؼž���������

����һ��ʯ���������С�����硣��Χ���ɴ�أ��������־��¡�������Ħ
��̵����ڡ�Ħ����ǲ�˹��Ħ�ᴴ�����ڽ̣��ֳ�Ϊ�����̡���Ħ���ͽ��
Ҫʳ�أ������˴�Ϊ��ʳ����ħ������֮Ϊ��ħ�̡���
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"enter" : __DIR__"caoan2",
		"north" : __DIR__"shisun",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 4);
        setup();
	replace_program(ROOM);
}
