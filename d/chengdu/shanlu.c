//  /d/xueshan/shanlu.c 
inherit ROOM;

void create()
{
        set("short","ɽ·");
        set("long",@LONG 
����һ��ͨ���ѩɽ����������ڵ����ն�����·��ߵͲ�ƽ����������
���Ѿ��в��ٲ����ˣ�ż���㻹�ܿ�����һ���������������߹���
LONG);
        set("exits",([
                "southdown" : __DIR__"shanlu01",
                "northwest": "/d/xueshan/shanlu7"
        ]));
        set("outdoors", "xueshan");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}


