// Code of ShenZhou
// fengdong.c �綯��
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�綯��");
	set("long", @LONG
������ɽ�ı�´����ľïʢ����ʯ���ס�����һ���Ʒ���Բ����Ȼ��ʯ��
ֻҪһ������ҡ����������أȻ�������������������磬��紵�����ƺ�Ҳ��
�ڶ����˳ơ��綯�ҡ��������������򡹣��Ͽ̡���Ȼ�������ʫ�ƣ�����
ʱ��ˮ����ת��Բ����ɽ����������
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 3);
        setup();
	replace_program(ROOM);
}
