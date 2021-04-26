// Code of ShenZhou
// Room: /d/village/square.c

inherit ROOM;

void create()
{
        set("short", "��ȳ�");
        set("long", @LONG
�����Ǵ��ӵ����ģ�һ��ƽ̹�Ĺ㳡��ÿ�����մ�Ⱦ����⡣�㳡�����п�֦
��Ҷï������ƽ�ղ��෹�󣬴������Ů���ٶ�����������̸��˵�ء������м�
����ȶ�(gudui)��
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                "northwest" : __DIR__"nwroad2",
                "northeast" : __DIR__"majiu",
                "south" : __DIR__"sroad4",
                "east"  : __DIR__"eroad3",
        ]));

        set("objects", ([
                __DIR__"npc/kid": 2,
                "/d/shaolin/obj/caoliao": 2,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "village");

        set("cost", 1);
        setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="gudui" )
        {
                if(me->query("rided"))
                return notify_fail("��������������ô�ɣ�\n");
                if( (fam = me->query("family")) && fam["family_name"] == "ؤ��" ) 
                {
                        message("vision",
                                me->name() + "����ؤ�����ǹ���һ�������ȶ������˽�ȥ��\n",
                                environment(me), ({me}) );
                        me->move("/d/gaibang/underxc");
                        message("vision",
                                me->name() + "�ӹȶ������˽�����\n",
                                environment(me), ({me}) );
                        return 1;
                }
                else 
                        return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
        }
}       
