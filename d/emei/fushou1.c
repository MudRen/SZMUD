// Code of ShenZhou
// /d/emei/fushou1.c ���ĸ�

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "���ĸ�");
	set("long", @LONG
�����Ǹ����ֵ����ĸ������־���ʦ̫���ڷ𷨵ĵط�����������С��
�������ԣ��ƺ�������ʦ̫�Ľ̻ޡ����ڲ��ü�ª����ǽ���ż������Σ�����
���ż������š�������һ������������һ��ի����
LONG
	);
	set("exits", ([
		"out" : __DIR__"fushou",
		"west": __DIR__"fushou3",
		"east": __DIR__"chanfang_fs",
	]));

        set("objects", ([
                CLASS_D("emei") + "/jingzhao" :1,
        ]));

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if ( me->query("gender") != "Ů��" && dir == "west" ) 
                return notify_fail("�����˶���Ů����Ϣ����֮������λ" + 
                        RANK_D->query_respect(me) + "����������\n");

        return ::valid_leave(me, dir);
}

	
