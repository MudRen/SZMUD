//Room: /d/kaifeng/tingyulou.c
// by bravo
inherit ROOM;
void create()
{
        set("short", "����¥");
        set("long", @LONG
����¥�������Ľǣ�������˽ǣ��������ߣ��̽Ƿ���������
�������������ϣ�������棬�ۻ���ʵΪʤ����¥�����⣬��
��ǧ�����죬ÿ�������뵣��������䣬�����������������ǡ�¥
ǰѦ�ξ�����˵��ΪѦ��Ưϴһ�ֺ�ɫʫ�������ǧ��: �޲��ž�
�����أ���ɫ�ż�����䡣
LONG
        );

        set("exits", ([
                "northwest":__DIR__"eroad2s",
                ]));
         set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
