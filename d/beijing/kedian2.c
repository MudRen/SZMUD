//Cracked by Roath
// ROOM:  /d/beijing/kedian2.c

inherit ROOM;

void create()
{
        set("short", "��ջ��¥");
        set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����С
ľ�������ٿ��������¶��ԣ������Ӷ��Ǻ����Ĵ���������
���Ŵ��ǿյģ���������ŵ����˹�ȥ��
LONG
        );

        set("sleep_room",1);

        set("exits", ([
                "down" : __DIR__"kedian",
        ]));

        set("cost", 2);
        setup();
}

int valid_leave(object me, string dir)
{

        if (dir == "down" ) me->delete_temp("rent_paid");

        return ::valid_leave(me, dir);
}
