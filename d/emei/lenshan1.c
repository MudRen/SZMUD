// Code of ShenZhou
// Room: /d/emei/lenshan1.c
// Date: xuy /09/19/96

inherit ROOM;

void create()
{
	set("short", "��ɼ��");
	set("long", @LONG
����һƬ������յ���ɼ�֡�����Ҳ�ϱ�����������ɼ������һ�飬�ÿ�
֦��Ҷï����һ�����ɡ��������գ��������ڵ�˿��Ҳ�ޡ������Ϻ��Ŀ�
֦��Ҷ����Ȼ�οͺ���̤��˴���
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"lingyun",
		"west" : __DIR__"leidong",
		"southup" : __DIR__"lenshan2",
	]));

	set("cost", 3);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "southup" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(15));
                me->improve_skill("dodge", random(10));
                write("������ɼ������������һ����Щ���ˡ�\n");
        }

        else if (dir == "southup" && current_jingli <= 10)
        {
                write("���۵��߲����ˣ���Ȼ��ð���ǣ����˹�ȥ��\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

#include "lenshan.h"
