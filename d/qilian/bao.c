// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�ɹŰ�");
        set("long", @LONG
����һ����赻Ի͵��ɹŰ����ɹŹ�ʦ���ַ��������ʡ���������
������ë��̺����������һ�Ŷ̰�������������侭��
LONG
        );
        set("exits", ([
		"out" :__DIR__"caoyuan4",
        ]));

	set("objects", ([
	"/kungfu/class/xueshan/jinlun" : 1,
        ]));
	set("cost", 0);
        setup();
        replace_program(ROOM);
}
