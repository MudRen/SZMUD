// Code of ShenZhou
// ɽ�� /d/shenlong/shanqiu
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һƬɽ��أ�����������Ҷ�ͻ��������ڸ��¹��꣬����ʮ����Ţ��
ͻȻ���㷢�ֵ���������߳����еĺۼ�����ϸ������С��������ӣ����
ȷ�Ƴ��ޣ��㲻�ɵû�������һ�㼦Ƥ��񡣱�����һƬ��԰��
LONG
        );
        set("outdoors", "shenlong");
	set("exits", ([
		"southwest" : __DIR__"shanlu2",
                "north" : __DIR__"guoyuan",
        ]));
        set("snaketype", ({"yinhuan"}));
	set("cost", 5);

        setup();
}

#include "/d/shenlong/snakeroom.h";
