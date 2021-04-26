// Code of ShenZhou
// room: /d/xingxiu/tianroad1.c
// Jay 3/18/96
// Ryu 5/10/97

inherit ROOM;

void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
����ɿݵĺӴ��У���«έ��������һЩ�Ͱ���С��ľ������һ��
��������ˮ��������Ǹ�ɳ�����ӡ���̲�е�ʯͷ�Ͷ���ܲݵ�֦Ҷ�ϣ�
����һ���˪�����󺮶����²�ľ�Ͻ�����������Ұ������Ȼ���
LONG
        );
        set("exits", ([
            "northdown" : __DIR__"xxh1",
            "southdown" : __DIR__"gangou2",
            "west" : __DIR__"lithouse",
]));
        set("objects", ([
                "/kungfu/class/xingxiu/shihou" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]));
        set("resource/grass", 1);
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("cost", 3);
        setup();
//      replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "������") && dir != "southdown" && me->query("id")!="shu"
                 && (present("shihou zi", environment(me)))) {
                say("ʨ����һ�Բ�������������"+me->name()+"��ǰ��\n");
                return notify_fail("ʨ����һ�Բ�����������������ǰ��\n");
        }
        return ::valid_leave(me, dir);
}
