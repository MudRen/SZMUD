// Code of ShenZhou
// Room: /city/nandajie2.c
// YZC 1995/12/04 
// CLEANSWORD 1996/2/2

inherit ROOM;

void create()
{
        set("short", "�ϴ��");
        set("long", @LONG
����������½��㽭���ᶽ�������ĵ�˰Ǯ�������̵ģ�Ŀ���Ǹ�����տ�
�ŵġ��۽�󡱼ܵ�����ġ���Ϊ��˵������ϰ���ᶽ�Ϲ����ڣ������Ҳ��
�������ӣ��������ſڰѱ�������ʯ�������·��ĳ��˴���ʯ��������������
�������ԡ�ǽ���Ϲ���һ���󲼸棬������һ�д��֣����𻵵����߷�����ʮ��
��������������һ����֣��ϱ���ͷ�������ֵļ��С�
LONG
        );
        set("outdoors", "city");

        set("exits", ([
                "east" : __DIR__"dongnanjie",
                "south" : __DIR__"nandajie3",
                "west" : __DIR__"jujinge",
                "north" : __DIR__"nandajie1",
        ]));

        set("cost", 1);
        setup();
}
