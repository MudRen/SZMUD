// Code of ShenZhou
// dxbaodian.c ���۱���
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���۱���");
	set("long", @LONG
ʯͥ��ͷ�����Ǵ��۱���ഫ����֮�գ�������Ʈ�Ƹǵأ����ֳơ���
�ƴ������϶�������Ŷ�ʮ���������ġ����졹(fairies)�� �������룬
չ�����ɡ����ڰ�������������м��������ڵġ����ͷ����ͼ�Ĳ���
��������Ϊ�Ϸ����������������ӷ𣬶������ڷ𣬱����ɾͷ𡣺�������
̬�����ʮ���޺���
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"yuetai",
		"south" : __DIR__"tianwang",
	]));

	set("item_desc",([
                "fairies" : "�еķ����ֳ�����������е������ķ��ı����������\n"
			    "����֮�䣬���˷·�����һ�����ִ����������Լ���ʡ�\n",
	]));

        set("objects", ([ 
		__DIR__"npc/monk" : 1,
        ]));

        set("no_clean_up", 0);

	set("cost", 0);
        setup();
	replace_program(ROOM);
}
