// Room: /d/city/kezhan2.c
//by bravo
inherit ROOM;

void create()
{
        set("short", "�͵��¥");
        set("long", @LONG
�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ����Ĵ�����һ
��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������¥�µ��ƹ񴦸���Ǯ������
˯����
LONG
        );

        set("exits", ([
                "down" : __DIR__"kezhan",
                "enter" : __DIR__"kezhan3",
        ]));

        setup();
        replace_program(ROOM);
}
