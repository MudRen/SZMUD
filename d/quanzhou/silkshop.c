// Code of ShenZhou
// silkshop.c ������ׯ
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������ׯ");
	set("long", @LONG
���������������˿���������ģ���ɫ����ĵ��棬���ϹҸ�Ʈ��һ����
���Ϻõĳ��棬���ź�ɫ�ġ������С��ĸ����֡���ԭ�����ϵ�˿���ڴ˼�
����ԴԴ���ϵ��������������ׯ�ڸ�ʽ��ɫ���ʵصĳ��Ӧ�о��У�������
Ŀ��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"jiedao1",
	]));

        set("objects", ([ 
		__DIR__"npc/xu" : 1,
		__DIR__"npc/ss_huoji" : 1,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
}
