// Code of ShenZhou
// tyroad5.c ���ɽ·
// by Marz 

inherit ROOM;

#include __DIR_"feng.h"

void create()
{
	set("short", "���ɽ·");
	set("long", @LONG
	������һ�����������ɽ·�ϣ�һ�����ͱڣ�һ�������¡��߸ߵ�������(feng)
�����������У���Լ�ɼ����������ԵĽ���ͺ����˶���ϸ������Լ��Ľ��£�����
̧ͷ��һ�ۣ�Ω��һ��С��ˤ��ȥ������ǿ�˳û���٣������޲�����������ֻ���
���·��
LONG
	);
	set("outdoors", "wudang");

	set("exits", ([
		"northtup" : __DIR__"tyroad4",
		"westdown" : __DIR__"tyroad6",
	]));

    set("item_desc", ([
        "feng" : (:look_feng:),
    ]));

	setup();
}

void init()
{
        add_action("look_feng", "look");
}
