//Cracked by Roath
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "���ׯ");
    set("long", @LONG
�����Ǿ����������ļ��ҳ��ׯ֮һ���������һλ���յ��ϰ��ﵱ�ҡ���
����Ȼ���󣬿�����޳�аڵõ������ǣ����㿴���ۻ����ҡ�
LONG
	);

    set("exits", ([
        "southeast" : __DIR__"tianqiao",
    ]));

    set("objects", ([
	__DIR__"npc/zhangshi":1,
    ]));

    setup();
}
