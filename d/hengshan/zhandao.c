// Room: /d/hengshan/zhandao.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ʽջ��");
        set("long", @LONG
ջ�����ڱڣ������������̳ɣ�ÿ������������Žڲ�����һ
��ÿ��������ұڣ�����ľ�壬��Լʮ�ɣ�������Ԩ���˱���̤
�����յ�ľ�壬������������Ϣ����������Ų�������ܹ�ȥ��
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southup"   : __DIR__"yunge",
           "northdown" : __DIR__"cuiping2",
        ]));
        set("outdoors", "hengshan");
		set("cost", 1);
        setup();
        replace_program(ROOM);
}
