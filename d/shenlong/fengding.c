// Code of ShenZhou
// �嶥 /d/shenlong/fengding
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�嶥");
        set("long", @LONG
��������������߷壬����ȴ���ǿ���վ�ڷ嶥����ĿԶ������������
����ε������ա�ãã�Ĵ󺣡���ͻȻ�����Լ��Ƕ�ô����С������׺�֮һ
�ڡ��Ա�һȺ����������Ѳ���ţ�ż����������س����Ƽ��ۡ������ǳ��ȣ�
��������ɽ��ɽ����������һ��ͨ���ɽ��С·��·��С���ƺ��ߵ��˲��ࡣ
LONG
        );
	set("cost", 4);

        set("exits", ([
		"northdown" : __DIR__"houshan",
		"southdown" : __DIR__"shandao",
                "east" : __DIR__"changlang",
        ]));

        set("objects", ([
           //     "/kungfu/class/shenlong/chilong" : 1,
                "/kungfu/class/shenlong/hesheng" : 1,
           //      "/d/shenlong/npc/chi" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

