// Code of ShenZhou
// lingmu.c ��ɽʥĹ
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽʥĹ");
	set("long", @LONG
����Ȫ�ݶ�����ɽ����´�������Ƹ��������䣬��˹���̴�ʼ���º�Ī
������ͽ����ɳ���ʡ������������Ȫ�ݴ��̣������ڴˡ�Ĺ����һ��Բ��ʯ
���ȣ�������һ���ı��ǣ��ˡ�֣�����㱮��(monument)������������������
��̫��֣�͵����������·��Ȫ�ݣ�������Ĺ���㵻�棬�ٸ�Ϊ֮��ʯ���µ�
���̡�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"shuiguan",
		"east" : __DIR__"lyqiao",
		"south" : __DIR__"gangkou3",
	]));
set("fanhua",1);

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("item_desc",([
		"monument" : "���ղ��ܱ�̫��֣�ͣ�ǰ�������³Į˹�ȹ����ɡ�����\n"
			     "ʮ�����������㣬�����鱣�ӡ����ֺ��ռ�����\n",
	]));

	set("cost", 2);
        setup();
	replace_program(ROOM);
}
