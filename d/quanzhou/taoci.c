// Code of ShenZhou
// taoci.c �մ���
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�մ���");
	set("long", @LONG
�������Ƹ�ʽ�������մ���Ʒ����̨�ϰ��Ż�ɫ��������ƿ�ޣ����͸
�����ɶ��칤�����������ϸ��Բ�������������������������λ�������
��ͼ����������Ǵ��Ӳ���Ů��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"xmqiao",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);

	set("cost", 0);
        setup();
	replace_program(ROOM);
}
