// Code of ShenZhou
// chaoan2.c ����
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
������������Ħ��ʯ��������Բ����ü��¡��ɢ�����磬���ſ���ɮ
�£�˫��������������ϥ�ϣ���̬ׯ�ϣ���߷�ɡ���ǰԼ���״�����ʯ������
�п��������Ȱ����徻�����������ǻۣ��������棬Ħ���𡻡�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"out" : __DIR__"caoan1",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);

	set("cost", 0);
        setup();
}
