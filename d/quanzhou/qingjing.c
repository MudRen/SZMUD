// Code of ShenZhou
// qingjing.c �徻��
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�徻��");
	set("long", @LONG
����һ�����������Ǵ���ʿ����˹������ö����Ľ��ã�ȫ������ɫ�Ͱ�
ɫ�Ļ���ʯ���졣�ߴ����ζ��ļ⹰����ʹ����վ�����ڣ����С������®
����ձ��֮�С����ڻ���һ���������͡�ʯ�̡����ź�������ǡ�����̳����
��������ͽ�ڴ��������ݡ�����ϻ����С�����������
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"alabo",
		"south" : __DIR__"tumen",
	]));

        set("objects", ([ 
		__DIR__"npc/huihui" : 2,
        ]));

        set("no_clean_up", 0);
        set("fanhua", 4);

	set("cost", 1);
        setup();
}
