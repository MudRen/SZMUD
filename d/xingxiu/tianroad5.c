// Code of ShenZhou
// room: /d/xingxiu/tianroad5.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "��ɽɽ·");
        set("long", @LONG
��������ɽ��´��ɽ���ɽ�ϴ����������ɪɪ������·����һƬ��Ҷ�֡�
������ȥ������ңң�ɼ����ϱ��и��������ɽ��(cave)��
LONG
        );
        set("exits", ([
            "westup" : __DIR__"tianroad6",
            "eastdown" : __DIR__"tianroad4",
            "enter" : __DIR__"cave",
        ]));
        set("objects", ([
		 __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]));

       set("item_desc", ([
              "cave" : "�������ɽ����Ʈ��һ�����磬�ŵ���ֱ����¡�\n"
       ]) );

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 3);
        setup();
}
/*
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (dir =="enter" ) {
            if (present("zhaixing zi", environment(me)))
            if (!myfam || myfam["family_name"] != "������")
                return notify_fail("ժ����ͻȻ��ס��˵��������������Ҫ�������\n");

        return 1;
    }
        return ::valid_leave(me, dir);
        set("no_clean_up", 0);
}
*/
