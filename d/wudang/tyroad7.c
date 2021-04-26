// Code of ShenZhou
// tyroad7.c ���ɽ·
// by Marz 
// xQin 04/01

inherit ROOM;

#include "/d/wudang/feng.h"

void create()
{
	set("short", "���ɽ·");
	set("long", @LONG
������һ�����������ɽ·�ϣ�һ�����ͱڣ�һ�������¡��߸ߵ�����
��(feng)�����������У���Լ�ɼ����������ԵĽ���ͺ����˶���ϸ�����
�Լ��Ľ��£�����̧ͷ��һ�ۣ�Ω��һ��С��ˤ��ȥ������ǿ�˳û���٣�
�����޲�����������ֻ�����·��
LONG
	);
	set("outdoors", "wudang");

	set("exits", ([
		"northup" : __DIR__"tyroad6",
		"eastdown" : __DIR__"tyroad8",
	]));

    set("item_desc", ([
        "feng" : (:look_feng:),
    ]));

	set("cost", 2);
	setup();
}

void init()
{
        add_action("look_feng", "look");
}