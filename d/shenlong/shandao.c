// Code of ShenZhou
// ɽ�� /d/shenlong/shandao
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
        set("long", @LONG
ת������ɽ�£�����������һ��ɽ��֮�У�ɽ���ı����Ƿ嶥��������
ɽ�¡�̧ͷң���嶥���ż��������ݣ���������ԼԼ���������ϡ��ĵ���ײ
���������˸���������������������ɽ����Զ�ˡ�ɽ����խ��ֻ����һ��ͨ
����
LONG
        );
	set("cost", 6);
        set("outdoors", "shenlong");

        set("exits", ([
		"northup" : __DIR__"fengding",
		"southdown" : __DIR__"shanpo2",
        ]));

        set("snaketype", ({"snake", "fushe"}));

        setup();
}

#include "/d/shenlong/snakeroom.h";
