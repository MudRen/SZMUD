// Code of ShenZhou
// ɽ��2 /d/shenlong/shanpo2
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
        set("long", @LONG
����һ��ɽ�£�ͨ�򱱷���һ��ɽ�壬���Ѿ��������������ˣ�����ͣ
������Ϣ��Ϣ��ͻȻ�䣬�㿴�����ϡ����ϡ�·�ϣ���һ������һ��ȫ�Ƕ�
�ߣ����¼��ˣ�... �Ƿ�֮�أ����ɾ��������ǸϿ��뿪�ɡ�������һ����
խ��ɽ����������һ��ɽ�¡�
LONG
        );
	set("cost", 6);
        set("outdoors", "shenlong");

        set("exits", ([
		"northup" : __DIR__"shandao",
		"southdown" : __DIR__"shanpo1",
        ]));

        set("snaketype", ({"jinhuan", "yinhuan"}));

        setup();
}

#include "/d/shenlong/snakeroom.h"
