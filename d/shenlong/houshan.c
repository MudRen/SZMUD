// Code of ShenZhou
// ��ɽ /d/shenlong/houshan
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ɽ");
        set("long", @LONG
�����Ǻ�ɽ���˼��������Ӳݴ�����ǰ���·Խ��ԽС��·�ϻ���ʲô��
�������ĺۼ�����Խ��Խ���£���ʱ��ͷ��ͻȻ���㿴���ݶ����ƺ���һ������
�����ֿ���̫�����
LONG
        );
	set("cost", 5);
        set("outdoors", "shenlong");
        set("exits", ([
		"southup" : __DIR__"fengding",
                "northdown" : __DIR__"luanshi",
        ]));
        set("snaketype", ({"mangshe"}));
        setup();
}

#include "/d/shenlong/snakeroom.h";
