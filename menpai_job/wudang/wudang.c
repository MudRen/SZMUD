 //CODE BY SCATTER
//Control Center
//wudang.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�䵱���ɹ���������");
        set("long", @LONG
����ʹ�õ�ָ������
��鹤���ȼ� (chklevel)
������ɵ��� (chkmp)
��鹤��ϸ�� (chkinfo)

�趨�����ȼ� (setlevel <�ȼ�>)
�趨���ɵ��� (setmp <����>)
�޸�ϸ�� (setinfo <FUNCTION> <VALUE> <COUNTER>)

LONG
        );


        set("exits", ([
                                        "out" : "/d/wizard/ccenter",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
