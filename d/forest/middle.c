// Code of ShenZhou
// Jay 7/11/96

#include "tree.h"

void create()
{
    int i;
        set("short", "��ɽ��");
        set("long", @LONG
������Ħ���µ�ɽ����Ħ���¸������ƣ�ʯ���Ϲ�ͺͺ�ģ�û��
��·����������ΧƮ��Ʈȥ��ɽ�ϵ�����֦��β��ɽ�µ�����һ
Ƭ��
LONG
        );

        set("exits", ([
                "down" : __DIR__"foot",
		"up" : __DIR__"mty",
        ]));

	set("climbup",__DIR__"tree_m1");
	set("cost", 8);
	set("outdoors", "city");
        setup();
}


