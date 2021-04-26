// Code of ShenZhou
// Jay 7/11/96

#include "tree.h"

void create()
{
    int i;
        set("short", "ɽ��");
        set("long", @LONG
������Ħ���µ�ɽ�š�Ħ���¸������ƣ�ʯ���Ϲ�ͺͺ�ģ�û��
��·��һ������(lian)���ڿ��С�
LONG
        );

        set("exits", ([
                "east" : __DIR__"gate",
		"up" : __DIR__"middle",
        ]));

        set("item_desc", ([
		"lian" : "��ϧ�������Ѿ��������ϣ��������ˡ�\n",
	]));

	set("cost", 1);
	set("outdoors", "city");
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "up" && !wizardp(me))
                return notify_fail("Ħ���·Ǳ�Ѱ������ʹ���Ṧ�ٺã�Ҳ���Ե��ϡ�\n");
        return 1;
}

