// Code of ShenZhou
// gushao.c ��ɩ��
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɩ��");
	set("long", @LONG
��ɩ������������������Ρ��ͦ�Ρ�����Զ��������Ħ����ǧɽ������
�����ٵ�ͨ�����ഫ��ʱ��һ�������ӣ����ޱ��ã�Զ�����󣬲��Ϻ�Ϳ��
�磬���۾�������ɩ����̨Զ�����ո�һ�գ���˼�ɼ���˫˫���������˽���
����������ˡ�ͬʱ����Ҳ��Ȫ�ݸ���Ҫ�ĵ������������ǰ����ۣ���������
�����ۡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"anhai",
		"north" : __DIR__"yongning",
	]));

	set("objects", ([ 
                __DIR__"npc/langren" : 1,
		__DIR__"npc/xunbu" : 1,
	]));	

        set("no_clean_up", 0);
	set("outdoors", "quanzou");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}
