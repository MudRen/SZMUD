// Code of ShenZhou
// lyqiao.c ������
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�����������ϵ�һ���������µ���ʽʯ�š��ų�������Ŷ���ʮ������
�����������Է���������ʯ����ͷ�����ξ����ۿ���ʯʨ��������ͤ��������
׺��䣬��ʿʯ�񣬷������ˡ���֮��β����·ֲ���߰��ꡣ�ɴ��Űף�ˮ��
ɽ�࣬ʤ״���˾�̾���ഫ����Ȫ��֪��������һ�����ĵú�ð���º����ţ�
�ú������������������������ϵ�½·��ͨҪ�����󲿷����������Ļ����
�ɴ˾�����
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"lingmu",
		"east" : __DIR__"tudi",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}
